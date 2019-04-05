#pragma once

#ifndef MANDELBROT_H_
#define MANDELBROT_H_


namespace keatonProgram {
	class Mandelbrot
	{
	public:
		static const int MAX_ITERTAIONS = 1000;



	public:
		Mandelbrot();
		virtual ~Mandelbrot();


		static int getIterations(double x, double y);
	};

}

#endif // !MANDELBROT_H_

