#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class putSphere:public FiguraGeometrica{
	private:
		int xcenter, ycenter, zcenter, radius;
		
	public:
		putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float t);
		~putSphere();
		void draw(Sculptor_patch &a);
};

#endif
