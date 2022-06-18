#include "putVoxel.h"
#include "Sculptor_patch.h"

putVoxel::putVoxel(int x0, int y0, int z0){
	
	this -> x = x0;
	this -> y = y0;
	this -> z = z0;

}

putVoxel::~putVoxel(){
	
}

void putVoxel::draw(Sculptor_patch &a){
	if((this -> nx > x) && (this -> ny > y) && (this -> nz > z)){
		this -> v[x][y][z].isON = true;
		this -> v[x][y][z].r = this -> r;
		this -> v[x][y][z].g = this -> g;
		this -> v[x][y][z].b = this -> b;
		this -> v[x][y][z].t = this -> t;
	}
}
