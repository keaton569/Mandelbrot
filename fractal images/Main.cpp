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
using namespace keatonProgram;




int main() {
	int height = 600;

	FractalCreator fractalCreator(800,600);

	fractalCreator.addZoom(Zoom(176, height - 44, .07));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitMap("test.bmp");
	   	 
	

	cout << "finished" << endl;
	return 0;
}
