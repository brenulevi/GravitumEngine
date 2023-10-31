#pragma once

#include "Core.h"
#include "../Modules/Window.h"

namespace Gravitum
{
	class GRAVITUMDLL GravitumSimulation
	{
	private:
		Window* window;
	public:
		GravitumSimulation();
		virtual ~GravitumSimulation();

		void Start();
	};
}