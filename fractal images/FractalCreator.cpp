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
#include "FractalCreator.h"

using namespace std;

namespace keatonProgram {


	void FractalCreator::run(string name) {
		
		calculateIteration();
		calculateTotalIterations();
		drawFractal();
		writeBitMap("test.bmp");
	
	}

	FractalCreator::FractalCreator(int width, int height):
		m_width(width),
		m_height(height),
		m_histogram(new int[Mandelbrot::MAX_ITERTAIONS]{0}),
		m_fractal(new int[m_width * m_height]{0}),
		m_bitmap(m_width, m_height),
		m_zoomList(m_width, m_height)
	{
			
		m_zoomList.add(Zoom(m_width / 2, m_height / 2, 2.0 / m_width));


	}


	FractalCreator::~FractalCreator()
	{

	}

	void FractalCreator::calculateIteration() {

		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{

				pair<double, double> coords = m_zoomList.doZoom(x, y);

				int iterations = Mandelbrot::getIterations(coords.first, coords.second);

				m_fractal[y * m_width + x] = iterations;

				if (iterations != Mandelbrot::MAX_ITERTAIONS)
				{
					m_histogram[iterations]++;
				}



			}
		}
	}		
	

	void FractalCreator::drawFractal() {
		
		RGB startColor(0, 0, 0);
		RGB endColor(255, 128, 128);
		RGB colorDiff(endColor - startColor);

		for (int x = 0; x < m_width; x++)
		{
			for (int y = 0; y < m_height; y++)
			{
				uint8_t red = 0;
				uint8_t green = 0;
				uint8_t blue = 0;


				int iterations = m_fractal[y * m_width + x];



				if (iterations != Mandelbrot::MAX_ITERTAIONS)
				{


					uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERTAIONS);
					double hue = 0.0;

					for (int i = 0; i <= iterations; i++)
					{
						hue += ((double)m_histogram[i]) / m_total;
					}

					red = startColor.r + colorDiff.r * hue;
					green = startColor.g + colorDiff.g * hue;
					blue = startColor.b + colorDiff.b * hue;

				}
				m_bitmap.setPixel(x, y, red, green, blue);
			}
		}

	}

	void FractalCreator::writeBitMap(string name) {
		m_bitmap.write(name);
	}

	void FractalCreator::addZoom(const Zoom& zoom) {
		m_zoomList.add(zoom);

	}
		

	void FractalCreator::calculateTotalIterations() {
		for (int i = 0; i < Mandelbrot::MAX_ITERTAIONS; i++)
		{
			m_total += m_histogram[i];

		}
		
		}

	}
		
