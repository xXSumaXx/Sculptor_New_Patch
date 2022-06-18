#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "FiguraGeometrica.h"
#include "Sculptor_patch.h"

class putVoxel:public FiguraGeometrica{
	private:
		int x, y, z;
		
	public:
		putVoxel(int x, int y, int z);
		~putVoxel();
		void draw(Sculptor_patch &a);
};

#endif
