#include "window.h"

#include <iostream>

namespace SnowEngine { namespace Graphics {

	Window::Window(const char* title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;

		if (!init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwHideWindow(m_Window);
		// TODO: release callbacks
		// TODO: clear memory
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW!" << std::endl;
			return false;
		}

		glfwDefaultWindowHints();
		glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create the window!" << std::endl;
			return false;
		}

		const GLFWvidmode *vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_Window, (vidmode->width - m_Width) / 2, (vidmode->height - m_Height) / 2);

		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1);
		
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Failed to initialize GLEW!" << std::endl;
			return false;
		}

		std::cout << "GLFW " << glfwGetVersionString() << std::endl;
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
		glfwShowWindow(m_Window);
		return true;
	}

	void Window::requestClose() const
	{
		glfwSetWindowShouldClose(m_Window, true);
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() const
	{
		GLint error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL Error (" << error << ")" << std::endl;
		}

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

} }