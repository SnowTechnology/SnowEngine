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

		m_KeysPressed[GLFW_KEY_LAST + 1];
		m_ButtonsPressed[GLFW_MOUSE_BUTTON_LAST + 1];
		mx = 0.0;
		my = 0.0;
	}

	Window::~Window()
	{
		glfwHideWindow(m_Window);
		// TODO: release callbacks
		glfwSetWindowSizeCallback(m_Window, NULL);
		glfwSetKeyCallback(m_Window, NULL);
		glfwSetMouseButtonCallback(m_Window, NULL);
		glfwSetCursorPosCallback(m_Window, NULL);
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

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, windowSizeCallback);
		glfwSetKeyCallback(m_Window, keyCallback);
		glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
		glfwSetCursorPosCallback(m_Window, cursorPosCallback);

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
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cout << "OpenGL Error (" << error << ")" << std::endl;
		}

		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void windowSizeCallback(GLFWwindow *window, int width, int height)
	{
		Window *win = (Window*) glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height;
		glViewport(0, 0, width, height);
	}

	void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->m_KeysPressed[key] = (action != GLFW_RELEASE);
	}

	void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->m_ButtonsPressed[button] = (action != GLFW_RELEASE);
	}

	void cursorPosCallback(GLFWwindow *window, double xpos, double ypos)
	{
		Window *win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

} }