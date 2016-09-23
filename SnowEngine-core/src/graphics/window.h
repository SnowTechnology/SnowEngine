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
	public:
		Window(const char* title, int width, int height);
		~Window();

		void requestClose() const;

		void clear() const;
		void update() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		inline bool shouldClose() const { return glfwWindowShouldClose(m_Window); }
	private:
		bool init();
	};

} }