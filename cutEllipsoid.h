#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class cutEllipsoid:public FiguraGeometrica{
	private:
		int xcenter, rx, ycenter, ry, zcenter, rz;
		
	public:
		cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
		~cutEllipsoid();
		void draw(Sculptor_patch &a);
};

#endif
