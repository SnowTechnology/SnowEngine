#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace SnowEngine { namespace Graphics {

	struct Window
	{
	private:
		const char *m_Title;
		int m_Width, m_Height;
		GLFWwindow *m_Window;

		bool m_KeysPressed[GLFW_KEY_LAST + 1], m_ButtonsPressed[GLFW_MOUSE_BUTTON_LAST + 1];
		double mx, my;
	public:
		Window(const char* title, int width, int height);
		~Window();

		void requestClose() const;

		void clear() const;
		void update() const;

		inline bool getKey(int key) const { return m_KeysPressed[key]; }
		inline bool getButton(int button) const { return m_ButtonsPressed[button]; }

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline bool shouldClose() const { return glfwWindowShouldClose(m_Window); }
	private:
		bool init();
		friend static void windowSizeCallback(GLFWwindow *window, int width, int height);
		friend static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
		friend static void cursorPosCallback(GLFWwindow *window, double xpos, double ypos);
	};

	static void windowSizeCallback(GLFWwindow *window, int width, int height);
	static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
	static void cursorPosCallback(GLFWwindow *window, double xpos, double ypos);
} }