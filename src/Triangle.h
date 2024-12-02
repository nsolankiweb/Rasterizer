#pragma once

#include <stdlib.h>
#include <math.h>
#include <vector> 

#include <glm/glm.hpp>


class Triangle {
	private:
		glm::vec3 v[3];		// Triangle vertices
		glm::vec3 c[3];		// Vertex color
		float barycentric_coordinates[3]; // alpha, beta, gamma

	public:
		float minz = INT64_MAX;
		float maxz = INT64_MIN; 
		// Constructor
		Triangle(glm::vec3 &v0, glm::vec3 &v1, glm::vec3 &v2);

		// Rendering the triangle using OpenGL
		void RenderOpenGL(glm::mat4 &modelViewMatrix, glm::mat4 &projectionMatrix);

		// Rendering the triangle using CPU
		void RenderCPU(glm::mat4 projectionMatrix, glm::mat4 modelViewMatrix, int WINDOW_WIDTH, int WINDOW_HEIGHT, 
							float (&color)[1000][1000][3], float (&depth)[1000][1000]);

		bool insideT(float x, float y, glm::vec3 vv0, glm::vec3 vv1, glm::vec3 vv2); 
		void Mode0(); 
		void Mode1(); 
		void Mode2(float rangez);
		void setRange(std::vector<Triangle> triangleVector); 
};
