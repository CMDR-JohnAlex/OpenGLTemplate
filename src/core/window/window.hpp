#ifndef WINDOWH
#define WINDOWH

// Thirdparty
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Standard
#include <iostream>
#include <string>

//#define UNUSED(x) (void)(x)

namespace CE_core {
	class Window {
	public:
		GLFWwindow* window;

		int width = 800;
		int height = 600;

		const char* title;

		bool shouldClose = false;

		int create(int width, int height, std::string title);
		int update();
		int cleanup();
	};
}

void framebufferSizeCallback([[maybe_unused]] GLFWwindow* window, int width, int height);

#endif
