#include "GravitumSimulation.h"

#include <stdio.h>

namespace Gravitum
{
	GravitumSimulation::GravitumSimulation()
	{
		window = new Window();
	}

	GravitumSimulation::~GravitumSimulation()
	{
		delete window;
	}

	void GravitumSimulation::Start()
	{
		window->Create();

		MSG msg = { 0 };
		do {

			if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{

			}

		} while (msg.message != WM_QUIT);
	}
}