#include <fstream>
#include <cmath>
#include <sstream>
#include <iostream>
#include "Interpretador.h"
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"


Interpretador::Interpretador(){
	
}

std::vector<FiguraGeometrica*> Interpretador::analise(std::string filename){
	
	std::vector<FiguraGeometrica*> figs;
	std::ifstream fin;
	std::stringstream ss;
	std::string s;
	std::string token;
	
	fin.open(filename.c_str());
	if(!fin.is_open()){
		std::cout<<"Falha ao abrir!";
		exit(0);
	}
	while(fin.good()){
		getline(fin,s);
		if(fin.good()){
			ss.clear();
			ss.str(s);
			ss>>token;
			if(ss.good()){
				if(token.compare("Dim")==0){
					ss >> dimx >> dimy >> dimz;
				}else if(token.compare("putVoxel")==0){
					int x, y, z;
					ss >> x >> y >> z;
					figs.push_back(new putVoxel(x, y, z));
				}else if(token.compare("cutVoxel")==0){
					int x, y, z;
					ss >> x >> y >> z;
					figs.push_back(new cutVoxel(x, y, z));
				}else if(token.compare("putBox")==0){
					int x0, x1, y0, y1, z0, z1;
					ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> t; 
					figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, t));
				}else if(token.compare("cutBox")==0){
					int x0, x1, y0, y1, z0, z1;
					ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1; 
					figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
				}else if(token.compare("putSphere")==0){
					int xcenter, ycenter, zcenter, radius;
					ss >> xcenter >> ycenter >> zcenter >> radius;
					figs.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, t));
				}else if(token.compare("cutSphere")==0){
					int xcenter, ycenter, zcenter, radius;
					ss >> xcenter >> ycenter >> zcenter >> radius;
					figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
				}else if(token.compare("putEllipsoid")==0){
					int xcenter, ycenter, zcenter, rx, ry, rz;
					ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b>> t;
					figs.push_back(new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, t));
				}else if(token.compare("cutEllipsoid")==0){
					int xcenter, ycenter, zcenter, rx, ry, rz;
					ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b>> t;
					figs.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
				}
			}
		}
	}
	return (figs);
}

int Interpretador::getDimx(){
	return dimx;
}

int Interpretador::getDimy(){
	return dimy;
}

int Interpretador::getDimz(){
	return dimz;
}
