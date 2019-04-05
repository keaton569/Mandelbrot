#pragma once
#include <string>
#include "Zoom.h"



using namespace std;

namespace keatonProgram {
	class FractalCreator
	{
	public:
		FractalCreator();
		~FractalCreator();

		void calculateIteration();
		void drawFractal();
		void writeBitMap(string filename);
		void addZoon(const Zoom& zoom);
	};
}

