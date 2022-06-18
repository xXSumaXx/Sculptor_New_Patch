#ifndef SCULPTOR_PATCH_H
#define SCULPTOR_PATCH_H
#include "Voxel.h"


class Sculptor_patch{
	protected:
		Voxel *** v;
		int nx, ny, nz;
		float r, g, b, t;
	public:
		Sculptor_patch(int _nx, int _ny, int _nz);
		~Sculptor_patch();
		void setColor(float r, float g, float b, float alpha);
		void putVoxel(int x, int y, int z);
		void cutVoxel(int x, int y, int z);
		void writeOFF(char *filename);
};

#endif
