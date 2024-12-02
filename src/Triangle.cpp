#include "Triangle.h"
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <algorithm>
#include <vector> 
#include <iostream>

// A function clamping the input values to the lower and higher bounds
#define CLAMP(in, low, high) ((in) < (low) ? (low) : ((in) > (high) ? (high) : in))


Triangle::Triangle(glm::vec3 &v0, glm::vec3 &v1, glm::vec3 &v2)
{
	v[0] = v0;
	v[1] = v1;
	v[2] = v2;

	c[0] = glm::vec3(1.0f, 1.0f, 1.0f);
	c[1] = glm::vec3(1.0f, 1.0f, 1.0f);
	c[2] = glm::vec3(1.0f, 1.0f, 1.0f);
}

// Rendering the triangle using OpenGL
void Triangle::RenderOpenGL(glm::mat4 &modelViewMatrix, glm::mat4 &projectionMatrix) 
{

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(modelViewMatrix));

	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(projectionMatrix));

	glBegin(GL_TRIANGLES);
		glColor3f(c[0].x, c[0].y, c[0].z);
		glVertex3f(v[0].x, v[0].y, v[0].z);

		glColor3f(c[1].x, c[1].y, c[1].z);
		glVertex3f(v[1].x, v[1].y, v[1].z);

		glColor3f(c[2].x, c[2].y, c[2].z);
		glVertex3f(v[2].x, v[2].y, v[2].z);
	glEnd();
}

// Render the triangle on CPU
void Triangle::RenderCPU(glm::mat4 projectionMatrix, glm::mat4 modelViewMatrix, int WINDOW_WIDTH, int WINDOW_HEIGHT, 
							float (&color)[1000][1000][3], float (&depth)[1000][1000]) 
{

	glm::vec4 v0_cp = projectionMatrix * (modelViewMatrix * glm::vec4(v[0], 1.0f));
    glm::vec4 v1_cp = projectionMatrix * (modelViewMatrix * glm::vec4(v[1], 1.0f));
    glm::vec4 v2_cp = projectionMatrix * (modelViewMatrix * glm::vec4(v[2], 1.0f));

	//to NDC
	glm::vec3 v0_ndc = glm::vec3(v0_cp) / v0_cp.w;
    glm::vec3 v1_ndc = glm::vec3(v1_cp) / v1_cp.w;
    glm::vec3 v2_ndc = glm::vec3(v2_cp) / v2_cp.w; 

	//ApplyViewport
	float vM[] = {
        (float)WINDOW_WIDTH / 2, 0.0f, 0.0f, (float)WINDOW_WIDTH / 2,
        0.0f, (float)WINDOW_HEIGHT / 2, 0.0f, (float)WINDOW_HEIGHT / 2,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
	};
	glm::mat4 viewportM = glm::make_mat4(vM); 

	glm::vec3 vv0 = glm::vec3(viewportM * glm::vec4(v0_ndc, 1.0f));
    glm::vec3 vv1 = glm::vec3(viewportM * glm::vec4(v1_ndc, 1.0f));
    glm::vec3 vv2 = glm::vec3(viewportM * glm::vec4(v2_ndc, 1.0f));

	//RasterizeTriangle
	bool inside; 
	int minX = std::min(vv0.x, std::min(vv1.x, vv2.x)) - 1;
	int maxX = std::max(vv0.x, std::max(vv1.x, vv2.x)) + 1;
	int minY = std::min(vv0.y, std::min(vv1.y, vv2.y)) - 1;
	int maxY = std::max(vv0.y, std::max(vv1.y, vv2.y)) + 1;

	for (float y = minY + 0.5; y <= maxY + 0.5; y++) {
		for (float x = minX + 0.5; x <= maxX + 0.5; x++) { 
			inside = insideT(x, y, vv0, vv1, vv2);
			int py = y - 0.5 + 500; 
			int px = x - 0.5 + 500; 
			float d = barycentric_coordinates[0] * vv0.z + barycentric_coordinates[1] * vv1.z + barycentric_coordinates[2] * vv2.z;
			if(inside && py < 1000 && px < 1000 && py >= 0 && px >= 0) {	
				if ( d < depth[py][px]) {
					color[py][px][0] = barycentric_coordinates[0] * c[0].x + barycentric_coordinates[1] * c[1].x + barycentric_coordinates[2] * c[2].x;
					color[py][px][1] = barycentric_coordinates[0] * c[0].y + barycentric_coordinates[1] * c[1].y + barycentric_coordinates[2] * c[2].y;
					color[py][px][2] = barycentric_coordinates[0] * c[0].z + barycentric_coordinates[1] * c[1].z + barycentric_coordinates[2] * c[2].z;
					depth[py][px] = d;
				} 
			}
		}
	}

}

bool Triangle::insideT(float x, float y, glm::vec3 vv0, glm::vec3 vv1, glm::vec3 vv2) {
	float xA = vv0.x; 
	float yA = vv0.y;
	float xB = vv1.x;
	float yB = vv1.y;
	float xC = vv2.x;
	float yC = vv2.y;

	barycentric_coordinates[0] = (-1 * (x - xB)*(yC - yB) + (y - yB)*(xC - xB)) / (-1 * (xA - xB)*(yC - yB) + (yA - yB)*(xC - xB));
	barycentric_coordinates[1] = (-1 * (x - xC)*(yA - yC) + (y - yC)*(xA - xC)) / (-1 * (xB - xC)*(yA - yC) + (yB - yC)*(xA - xC));
	barycentric_coordinates[2] = 1 - barycentric_coordinates[0] - barycentric_coordinates[1];


	if(barycentric_coordinates[0] >= 0 && barycentric_coordinates[1] >= 0 && barycentric_coordinates[2] >= 0 &&
		barycentric_coordinates[0] < 1 && barycentric_coordinates[1] < 1 && barycentric_coordinates[2] < 1) {
		return true;
	}

	return false; 
}

void Triangle::Mode0() {

	glm::vec3 cl = glm::vec3((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX); 

	c[0] = cl; 
	c[1] = cl;
	c[2] = cl; 
}

void Triangle::Mode1() { 

	c[0] = glm::vec3((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX); 
	c[1] = glm::vec3((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX);
	c[2] = glm::vec3((float) rand()/RAND_MAX, (float) rand()/RAND_MAX, (float) rand()/RAND_MAX); 
}

void Triangle::Mode2(float rangez) {
	float zc = 0; 
	glm::vec3 cl = glm::vec3(1.0f, 1.0f, 1.0f); 
	for (int j = 0; j < 3; j++) {
		zc = v[j].z * rangez + 0.5; 
		cl = glm::vec3(zc, 0.0f, zc); 
		c[j] = cl; 
	}
}

void Triangle::setRange(std::vector<Triangle> triangleVector){
	for (int i = 0; i < triangleVector.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (triangleVector[i].v[j].z < minz) {
				minz = triangleVector[i].v[j].z; 
			} else if (triangleVector[i].v[j].z > maxz) {
				maxz = triangleVector[i].v[j].z; 
			}
		}
	}
}