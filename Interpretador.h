#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class Interpretador{
	private:
		int dimx, dimy, dimz;
		float r, g, b, t;
		
	public:
		Interpretador();
		std::vector <FiguraGeometrica*> analise(std::string filename);
		int getDimx();
		int getDimy();
		int getDimz();
};

#endif
