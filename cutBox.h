#ifndef CUTBOX_H
#define CUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class cutBox:public FiguraGeometrica{
	private:
		int x0, x1, y0, y1, z0, z1;
		
	public:
		cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
		~cutBox();
		void draw(Sculptor_patch &a);
};

#endif
