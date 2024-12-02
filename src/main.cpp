#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
#include "Triangle.h"
#include <string>
#include <cmath>


#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

GLFWwindow *window;

float color[WINDOW_HEIGHT][WINDOW_WIDTH][3];
float depth[WINDOW_HEIGHT][WINDOW_WIDTH];


std::vector<Triangle> triangleVector;
bool isOpenGL = true;
float eyeDistance = 5.0f;



void ClearFrameBuffer()
{
	memset(&color[0][0][0], 0.0f, sizeof(float) * WINDOW_WIDTH * WINDOW_HEIGHT * 3);
}

void Display()
{	
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.0f), float(WINDOW_WIDTH) / float(WINDOW_HEIGHT), 0.1f, 100.0f);
	glm::mat4 modelViewMatrix = glm::lookAt(eyeDistance * glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	if (isOpenGL)
	{
		for (int i = 0; i < triangleVector.size(); i++)
			triangleVector[i].RenderOpenGL(modelViewMatrix, projectionMatrix);
	}
	else
	{
		for (int j = 0; j < WINDOW_HEIGHT; j++) {
			for(int k = 0; k < WINDOW_WIDTH; k++) {
				depth[j][k] = INFINITY; 
			}
		}
		for (int j = 0; j < WINDOW_HEIGHT; j++) {
			for(int k = 0; k < WINDOW_WIDTH; k++) {
				color[j][k][0] = 0.0f; 
				color[j][k][1] = 0.0f; 
				color[j][k][2] = 0.0f; 
			}
		}
		for (int i = 0; i < triangleVector.size(); i++) {
			triangleVector[i].RenderCPU(projectionMatrix, modelViewMatrix, WINDOW_WIDTH, WINDOW_HEIGHT, color, depth);
		}

		glDrawPixels(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGB, GL_FLOAT, &color[0][0][0]);
	}
}

void Mode0T() {
	for (int i = 0; i < triangleVector.size(); i++)
			triangleVector[i].Mode0(); 
}

void Mode1T() {
	for (int i = 0; i < triangleVector.size(); i++)
			triangleVector[i].Mode1(); 
}

void Mode2T() {
	triangleVector[0].setRange(triangleVector); 
	float min = triangleVector[0].minz; 
	float max = triangleVector[0].maxz; 
	float range = 1 / (max - min); 
	for (int i = 0; i < triangleVector.size(); i++) {
		triangleVector[i].Mode2(range); 
	}

}

// Keyboard character callback function
void CharacterCallback(GLFWwindow* lWindow, unsigned int key)
{
	switch (key)
	{
	case 'w':
		eyeDistance *= (1 - 0.05);
		break;
	case 's':
		eyeDistance *= (1 + 0.05);
		break;
	case ' ':
		isOpenGL = !isOpenGL;
		break;
	case 'q':
		glfwSetWindowShouldClose(window, GLFW_TRUE);
		break;
	case '0':
		Mode0T();  
		break; 
	case '1':
		Mode1T(); 
		break; 
	case '2':
		Mode2T(); 
		break; 
	default:
		break;
	}
}

void CreateTriangleVector(std::vector<glm::vec3> &vertices)
{
	for (int i = 0; i < vertices.size() / 3; i++)
	{
		Triangle myTriangle(vertices[i * 3 + 0], vertices[i * 3 + 1], vertices[i * 3 + 2]);
		triangleVector.push_back(myTriangle);
	}
}

void LoadModel(char* name, std::vector<glm::vec3> &vertices)
{
	// Taken from Shinjiro Sueda with slight modification
	std::string meshName(name);
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string errStr;
	bool rc = tinyobj::LoadObj(&attrib, &shapes, &materials, &errStr, meshName.c_str());
	if (!rc) {
		std::cerr << errStr << std::endl;
	}
	else {
		// Some OBJ files have different indices for vertex positions, normals,
		// and texture coordinates. For example, a cube corner vertex may have
		// three different normals. Here, we are going to duplicate all such
		// vertices.
		// Loop over shapes
		for (size_t s = 0; s < shapes.size(); s++) {
			// Loop over faces (polygons)
			size_t index_offset = 0;
			for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
				size_t fv = shapes[s].mesh.num_face_vertices[f];
				// Loop over vertices in the face.
				for (size_t v = 0; v < fv; v++) {
					// access to vertex
					tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
					vertices.push_back(glm::vec3(attrib.vertices[3 * idx.vertex_index + 0],
												 attrib.vertices[3 * idx.vertex_index + 1],
												 attrib.vertices[3 * idx.vertex_index + 2]));
				}
				index_offset += fv;
			}
		}
	}
}

void Init()
{
	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Assignment3 - <Nandni Solanki>", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSetCharCallback(window, CharacterCallback);
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);

	ClearFrameBuffer();

	std::vector<glm::vec3> vertices;
	std::string filename; 
	std::cout << "Please enter the name of the model you wish to view (it is case sensitive).\nYour options are bunny.obj, duck.obj, sphere.obj." << std::endl;
	std::cin >> filename; 
	filename = "../obj/" + filename;
	LoadModel(filename.data(), vertices);
	CreateTriangleVector(vertices);
	
}

int main()
{
	Init();
	while ( glfwWindowShouldClose(window) == 0) 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Display();
		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}