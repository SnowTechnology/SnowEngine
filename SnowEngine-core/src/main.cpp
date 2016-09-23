#include "graphics/window.h"

using namespace SnowEngine;
using namespace SnowEngine::Graphics;

int main()
{
	Window window("SnowEngine!", 1280, 720);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!window.shouldClose())
	{
		window.clear();
		window.update();
	}

	return 0;
}