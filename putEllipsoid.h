#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class putEllipsoid:public FiguraGeometrica{
	private:
		int xcenter, rx, ycenter, ry, zcenter, rz;
		
	public:
		putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float t);
		~putEllipsoid();
		void draw(Sculptor_patch &a);
};

#endif
