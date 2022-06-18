#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class cutSphere:public FiguraGeometrica{
	private:
		int xcenter, ycenter, zcenter, radius;
		
	public:
		cutSphere(int xcenter, int ycenter, int zcenter, int radius);
		~cutSphere();
		void draw(Sculptor_patch &a);
};

#endif
