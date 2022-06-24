// Copyright (c) 2022 Constellation-Engine Developers (see [AUTHORS.md](AUTHORS.md))

// User-Defined Headers
// --------------------
#include "main.hpp"
#include "core/init/init.hpp"
#include "core/window/window.hpp"

// 3rd Party Library Headers
// -------------------------
// GLAD
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>
// stb
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Standard Library Headers
// ------------------------
#include <iostream>

int main() {
	CE_core::CE_init::graphicsInit();
	CE_core::Window window;

	window.create(800, 600, "Constellation Engine Game");

	while (!window.shouldClose) {
		window.update();
	}

	window.cleanup();

	return 0;
}