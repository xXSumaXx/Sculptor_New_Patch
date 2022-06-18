#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class cutVoxel:public FiguraGeometrica{
	private:
		int x, y, z;
		
	public:
		cutVoxel(int x, int y, int z);
		~cutVoxel();
		void draw(Sculptor_patch &a);
};

#endif
