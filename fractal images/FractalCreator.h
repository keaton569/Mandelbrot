#pragma once
#ifndef FRACTALCREATOR_H_
#define FARCTALCREATOR_H_


#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>

#include "Bitmap.h"
#include "bitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "RGB.h"


using namespace std;

namespace keatonProgram {
	class FractalCreator
	{
	private:
		int m_width;
		int m_height;
		Bitmap m_bitmap;
		ZoomList m_zoomList;
		int m_total{ 0 };

		unique_ptr<int[]> m_histogram;
		unique_ptr<int[]> m_fractal;
	
		


	private:
		void calculateIteration();
		void drawFractal();
		void writeBitMap(string filename);		
		void calculateTotalIterations();


	public:
		void run(string name);
		FractalCreator(int width, int height);
		~FractalCreator();
		void addZoom(const Zoom& zoom);
	};
}

#endif // !FRACTALCREATOR_H_