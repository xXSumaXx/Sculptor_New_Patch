#include "cutVoxel.h"
#include "Sculptor_patch.h"

cutVoxel::cutVoxel(int x0, int y0, int z0){
	
	this -> x = x0;
	this -> y = y0;
	this -> z = z0;

}

cutVoxel::~cutVoxel(){
	
}

void cutVoxel::draw(Sculptor_patch &a){
	if((this -> nx > x) && (this -> ny > y) && (this -> nz > z)){
		this -> v[x][y][z].isON = false;
	}
}
