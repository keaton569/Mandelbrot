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
#include "RGB.h"



using namespace std;
using namespace keatonProgram;




int main() {

	

	int height = 600;

	FractalCreator fractalCreator(800,600);

	cout << fractalCreator.getRange(200) << endl;

	fractalCreator.addRange(0.0, RGB(0, 0, 0));
	fractalCreator.addRange(0.33, RGB(255,0,0));
	fractalCreator.addRange(0.66, RGB(255, 255, 0));
	fractalCreator.addRange(1.0, RGB(255, 255, 255));


	cout << fractalCreator.getRange(200) << endl;


	fractalCreator.addZoom(Zoom(176, 44, .07));
	fractalCreator.run("test.bmp");
	

	cout << "finished" << endl;
	return 0;
}
