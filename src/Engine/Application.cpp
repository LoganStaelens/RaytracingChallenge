#include <Engine/Application.h>

#include <iostream>
#include <chrono>

#include <GLFW/glfw3.h>

Application::Application()
{
}

void Application::Update()
{
	

}

void Application::Render()
{
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Application::Init()
{
	m_window = std::make_unique<Window>(1600, 800, "Raytracing Challenge");
}

void Application::Cleanup()
{
	m_window->Cleanup();
}


void Application::Start()
{
	if (m_running) return;
	
	m_running = true;
	Run();
}

void Application::Stop()
{
	if (m_running) return;
	
	m_running = false;
	Run();
}

void Application::Run()
{
	Init();

	double fixedDeltaTime = 1.0 / 144.0;
	double startTime = GetTime();
	double unprocessedTime1 = 0;
	double unprocessedTime2 = 0;

	while (m_running) {
		double currentTime = GetTime();
		double timeStep = currentTime - startTime;
		unprocessedTime1 += timeStep;
		unprocessedTime2 += timeStep;

		startTime = currentTime;

		while (unprocessedTime1 >= fixedDeltaTime) {
			Update();
			Render();
			m_running = m_window->Update();
			unprocessedTime1 = 0;
			m_frames++;

			if (unprocessedTime2 >= 1.0) {
				std::cout << "fps : " << m_frames << std::endl;
				unprocessedTime2 = 0;
				m_frames = 0;
			}
		}
	}
	
	Cleanup();
}


static std::chrono::high_resolution_clock::time_point m_epoch = std::chrono::high_resolution_clock::now();
double Application::GetTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_epoch).count() / 1000000000.0;
}