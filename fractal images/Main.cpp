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



using namespace std;
using namespace keatonProgram;


const int WIDTH = 800;
const int HEIGHT = 600;

int main() {

	


	Bitmap bitmap(WIDTH, HEIGHT);

	double min = 9999999;
	double max = -9999999;


	ZoomList zoomList(WIDTH, HEIGHT);
	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 2.0/WIDTH));
	zoomList.add(Zoom(176, HEIGHT - 44, .07));


	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERTAIONS]{});
	unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT] {});

	//bitmap.setPixel(WIDTH / 2, HEIGHT / 2, 255,0,0);

	for (int x=0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT ; y++)
		{

			pair<double, double> coords = zoomList.doZoom(x, y);	

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			fractal[y * WIDTH + x] = iterations;
			
			if (iterations != Mandelbrot::MAX_ITERTAIONS)
			{
				histogram[iterations]++;
			}
						

			
		}
	}


	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERTAIONS; i++)
	{
		total += histogram[i];

	}

	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;


			int iterations = fractal[y * WIDTH + x];



			if (iterations != Mandelbrot::MAX_ITERTAIONS)
			{


				uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERTAIONS);
				double hue = 0.0;

				for (int i = 0; i <= iterations; i++)
				{
					hue += ((double)histogram[i]) / total;
				}

				green = pow(255, hue);

			}
			bitmap.setPixel(x, y, red, green, blue);			
		}
	}
	

	bitmap.write("test.bmp");

	cout << "finished" << endl;
	return 0;
}


//keaotnnnnnnn