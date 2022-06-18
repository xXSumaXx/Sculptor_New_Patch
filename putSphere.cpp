#include "putSphere.h"
#include <cmath>

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float t){
	
	this -> xcenter = xcenter;
	this -> ycenter = ycenter;
	this -> zcenter = zcenter;
	this -> radius = radius;
	this -> r = r;
	this -> g = g;
	this -> b = b;
	this -> t = t;
}

putSphere::~putSphere(){
	
}

void putSphere::draw(Sculptor_patch &a){
	int i, j, k;
	a.setColor(r, g, b, t);
	for(i = (xcenter - radius); i<(xcenter + radius); i++){
		for(j = (ycenter - radius); j<(ycenter + radius); j++){
			for(k = (zcenter - radius); k<(zcenter + radius); k++){
				if((pow(i - xcenter, 2)) + (pow(j - ycenter, 2)) + (pow(k - zcenter, 2)) <= (pow(r,2))){
					a.putVoxel(i,j,k);
				}
			}
		}
	}
}
