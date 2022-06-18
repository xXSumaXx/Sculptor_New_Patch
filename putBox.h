#ifndef PUTBOX_H
#define PUTBOX_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class putBox:public FiguraGeometrica{
	private:
		int x0, x1, y0, y1, z0, z1;
		
	public:
		putBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float t);
		~putBox();
		void draw(Sculptor_patch &a);
};

#endif
