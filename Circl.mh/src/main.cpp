#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <spdlog/spdlog.h>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_ESCAPE) {
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}
}

int main() {
	if (!glfwInit()) {
		glfwTerminate();
		return -1;
	}

	spdlog::info("Hello, World!");
	
	const GLFWvidmode* fullscreen_mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(fullscreen_mode->width, fullscreen_mode->height, "Nigga Window", glfwGetPrimaryMonitor(), nullptr);
	if (!window) {
		std::cerr << "Failed to load GLFW\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	int version = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	if (!version) {
		std::cerr << "Failed to load GladGL\n";
		glfwTerminate();
		return -1;
	}

	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.17f, 0.0f, 0.2f, 1.0f);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}