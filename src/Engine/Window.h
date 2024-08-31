#pragma once
#pragma once 

struct GLFWwindow;

class Window {

public:
	Window(int width, int height, const char* title);
	void Cleanup();
	bool Update();

private:
	GLFWwindow* m_window;
};