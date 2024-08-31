#pragma once

#include <memory>
#include <Engine/Window.h>

class Application {

public:
	Application();

	void Start();
	void Stop();
	void Run();

	//State functions
	void Update();
	void Render();
	void Init();
	void Cleanup();

private:
	double GetTime();

private:
	bool m_running = false;
	int m_frames = 0;
	std::unique_ptr<Window> m_window;
};