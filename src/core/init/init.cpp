// User-Defined Headers
// --------------------
#include "init.hpp"

// 3rd Party Library Headers
// -------------------------
// GLAD
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>

// Standard Library Headers
// ------------------------
#include <iostream>

namespace CE_core {
	namespace CE_init {
		int graphicsInit() {
			glfwInit();

			// Set the OpenGL version
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

			// Use only modern OpenGL functions
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

			return 0;
		}

		int graphicsInit(int versionMajor, int versionMinor) {
			if (!glfwInit()) {
				std::cerr << "Failed to initialize GLFW" << std::endl;
				return -1;
			}

			// Set the OpenGL version
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);

			// Use only modern OpenGL functions
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

			return 0;
		}
	}
}

