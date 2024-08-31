#include <Engine/Window.h>

#include <iostream>

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (m_window == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return;
	}

	glfwMakeContextCurrent(m_window);
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

bool Window::Update() {
	glfwSwapBuffers(m_window);
	glfwPollEvents();

	return !glfwWindowShouldClose(m_window);
}

void Window::Cleanup() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}