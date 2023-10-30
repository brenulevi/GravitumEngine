#include <iostream>

#include "GravitumEngine/GravitumSimulation.h"

class Simulation : public Gravitum::GravitumSimulation
{
private:

public:
	Simulation()
	{

	}

	~Simulation()
	{

	}
};

int main()
{
	Simulation* sim = new Simulation();
	sim->Start();
	delete sim;
}