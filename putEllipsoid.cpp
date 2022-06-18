#include "putEllipsoid.h"
#include <cmath>

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float t){
	
	this -> xcenter = xcenter;
	this -> ycenter = ycenter;
	this -> zcenter = zcenter;
	this -> rx = rx;
	this -> ry = ry;
	this -> rz = rz;
	this -> r = r;
	this -> g = g;
	this -> b = b;
	this -> t = t;
}

putEllipsoid::~putEllipsoid(){
	
}

void putEllipsoid::draw(Sculptor_patch &a){
	int i, j, k;
	a.setColor(r, g, b, t);
	for(i = (xcenter - rx); i<(xcenter + rx); i++){
		for(j = (ycenter - ry); j<(ycenter + ry); j++){
			for(k = (zcenter - ry); k<(zcenter - rz); k++){
				if(((pow(i - xcenter, 2))/pow(rx,2)) + ((pow(j - ycenter, 2))/pow(ry,2)) + ((pow(k - zcenter, 2))/pow(rz,2)) <= 1){
					a.putVoxel(i , j, k);
				}
			}
		}
	}
}
