#include <iomanip>
#include <queue>
#include <fstream>
#include <iostream>
#include "Sculptor_patch.h"

Sculptor_patch::Sculptor_patch(int _nx, int _ny, int _nz){
	int i, j, k;
	nx = _nx;
	ny = _ny;
	nz = _nz;
	r = 0;
	g = 0;
	b = 0;
	t = 0;
	
	v = new Voxel **[nx];
	
	for(i = 0; i < nx; i++){
		v[i] = new Voxel * [ny];
	}
	for(i = 0; i < nx; i++){
		for(j = 0; j < ny; j++){
			v[i][j] = new Voxel [nz];
		}
	}
	for(i=0; i<nx; i++){
		for(j=0; j<ny; j++){
			for(k=0; k<nz; k++){
				this -> v[i][j][k].r = this -> r;
				this -> v[i][j][k].g = this -> g;
				this -> v[i][j][k].b = this -> b;
				this -> v[i][j][k].isON = false;
			}
		}
	}
}

Sculptor_patch::~Sculptor_patch(){
	int i, j;
	for(i = 0; i < nx; i++){
		for(j = 0; j < ny; j++){
			delete [] v[i][j];
		}
	}
	for(i = 0; i < nx; i++){
		delete [] v[i];
	}
}

void Sculptor_patch::setColor(float r, float g, float b, float alpha){
	this -> r = r;
	this -> g = g;
	this -> b = b;
	this -> t = alpha;
}

void Sculptor_patch::putVoxel(int x, int y, int z){
	if((this -> nx > x) && (this -> ny > y) && (this -> nz > z)){
		this -> v[x][y][z].isON = true;
		this -> v[x][y][z].r = this -> r;
		this -> v[x][y][z].g = this -> g;
		this -> v[x][y][z].b = this -> b;
		this -> v[x][y][z].t = this -> t;
	}
}

void Sculptor_patch::cutVoxel(int x, int y, int z){
	if((this -> nx > x) && (this -> ny > y) && (this -> nz > z)){
		this -> v[x][y][z].isON = false;
	}
}

void Sculptor_patch::writeOFF(char* filename){
	int i, j, k, n_voxels, n_vertices;
	n_voxels = 0;
	std::ofstream fout;
	fout.open (filename);
	if(!fout.is_open()){
		std::cout<<"Não foi possivel abrir o arquivo"<<std::endl;
		exit(1);
	}
	
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(v[i][j][k].isON == true){
					n_voxels = n_voxels + 1;
				}
			}
		}
	}
	
	fout << "OFF" << std::endl;
	fout << n_voxels*8 << " " << n_voxels*6 << " " << n_voxels*0 << std::endl;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(v[i][j][k].isON == true){
					fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
					fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
					fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
					fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
					fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
					fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
					fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
					fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
				}
			}
		}
	}
	n_voxels = 0;
	for(i = 0; i<nx; i++){
		for(j = 0; j<ny; j++){
			for(k = 0; k<nz; k++){
				if(v[i][j][k].isON == true){
					n_vertices = n_voxels * 8; 
					fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 1 << " " << n_vertices + 2 << " " << n_vertices + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 3 << " " << n_vertices + 5 << " " << n_vertices + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 4 << " " << n_vertices + 5 << " " << n_vertices + 7 << " " << n_vertices + 6 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 1 << " " << n_vertices + 6 << " " << n_vertices + 7 << " " << n_vertices + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 0 << " " << n_vertices + 4 << " " << n_vertices + 6 << " " << n_vertices + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					fout << "4" << " " << n_vertices + 2 << " " << n_vertices + 7 << " " << n_vertices + 5 << " " << n_vertices + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].t << std::endl;
					n_voxels = n_voxels + 1; 
				}
			}
		}
	}
	fout.close();
}


