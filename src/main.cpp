// JOHN ALEXANDER LE ROUX

// User-Defined Headers
// --------------------
#include "config/config.hpp"

// 3rd Party Library Headers
// -------------------------
// GLAD
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;
// stb
#define STB_IMAGE_IMPLEMENTATION
#include "../contrib/stb/stb_image.h"
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Standard Library Headers
// ------------------------
#include <iostream>



// Settings
// --------
// Screen
const unsigned int SCR_WIDTH = 800; // Default 800 or 1024
const unsigned int SCR_HEIGHT = 600; // Default 600 or 768

// Timing
float deltaTime = 0.0f;	// deltaTime is the time between current frame and last frame
float lastFrame = 0.0f;



// Callback functions
// ------------------
// Whenever the window size changes (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// Make sure the viewport matches the new window dimensions
	glViewport(0, 0, width, height);
}

// Process all input
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Check if the ESC key was pressed
		glfwSetWindowShouldClose(window, true);            // If so, close the window

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) // Check if the Q key was pressed
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    // If so, change draw mode to GL_LINE / wireframe

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) // Check if the E key was pressed
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);    // If so, change draw mode to GL_FILL

	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) // Check if the C key was pressed
		glfwSetClipboardString(NULL, "Hello this is a clipboard test");


	if ((glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) && (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) && (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS))
		glfwSetWindowShouldClose(window, true); // If so, close the window          

	if ((glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) && (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if ((glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS) && (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char* argv[])
{
	// Initialize GLFW
	// ---------------
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	// Configure GLFW
	glfwWindowHint(GLFW_SAMPLES, 4);                               // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
#endif

	// Create a window with glfw
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Template!", NULL, NULL);
	if (!window)
	{
		std::cerr << "Failed to create GLFW window. If you have an Intel GPU, they are not 3.3 compatible." << std::endl;
		glfwTerminate();
		return -1;
	}

	// Set the context to be the window and setup any callback functions
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	
	
	// Initialize GLAD; Load all OpenGL pointers
	// -----------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Configure global OpenGL state
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FRAMEBUFFER_SRGB); // Use sRGB
	glfwSwapInterval(1); // Turn on vsync for smoother rendering and so OpenGL doesn't draw faster than the monitor refresh rate so the program uses 100% CPU and GPU
	// Render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// Per-frame time logic
		// --------------------
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;



		// Input
		// -----
		processInput(window);



		// Render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // a=x/255 where x is the RGB value and a is your desired result from 0 to 1
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffer



		// Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}

#ifdef _WIN32 // _WIN32 = Windows32,  _WIN64 = Windows64,  __APPLE__ = MacOS,  __linux__ = Linux,  __ANDROID__ = Android. https://blog.kowalczyk.info/article/j/guide-to-predefined-macros-in-c-compilers-gcc-clang-msvc-etc..html
#ifndef _DEBUG // Project properties > Linker > System > Subsystem to "Windows" (only for all Release builds) will use WinMain as the start of program and hide the console
#define nominmax
#include <Windows.h>
int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PSTR szCmdLine, _In_ int iCmdShow)
{
	main(__argc, __argv); // __argc, __argv, __wargv: https://docs.microsoft.com/en-us/cpp/c-runtime-library/argc-argv-wargv?view=msvc-170
	//MessageBox(NULL, TEXT("Body Text"), TEXT("Title"), 0);
	return 0;
}
#endif
#endif // Another option to hide window without WinMain: https://stackoverflow.com/questions/18260508/c-how-do-i-hide-a-console-window-on-startup