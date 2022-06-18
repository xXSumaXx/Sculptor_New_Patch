#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor_patch.h"

class FiguraGeometrica{
	protected:
		float r, g, b, t;
	public:
		FiguraGeometrica();
		virtual ~FiguraGeometrica(){};
		virtual void draw(Sculptor_patch &a)=0;
};

#endif
