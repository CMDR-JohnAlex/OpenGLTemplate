#include "window.hpp"

namespace CE_core {
	int Window::create(int userWidth, int userHeight, std::string userTitle) {
		width = userWidth;
		height = userHeight;
		title = userTitle.c_str();

		// Create the GLFWwindow object
		window = glfwCreateWindow(width, height, title, NULL, NULL);

		// Error handling
		if (!window) {
			std::cout << "Failed to create GLFW window. If you have an Intel GPU, they are not 3.3 compatible." << std::endl;

			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initialize GLAD" << std::endl;

			return -1;
		}

		// Use the entire window
		glViewport(0, 0, width, height);

		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

		return 0;
	}

	int Window::update() {
		if (glfwWindowShouldClose(window)) {
			shouldClose = true;
		}

		glfwSwapBuffers(window);
		glfwPollEvents();

		return 0;
	}

	int Window::cleanup() {
		glfwTerminate();

		return 0;
	}
}

void framebufferSizeCallback([[maybe_unused]] GLFWwindow* window, int width, int height) {
	//UNUSED(window);
	glViewport(0, 0, width, height);
}