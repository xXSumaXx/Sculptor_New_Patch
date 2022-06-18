#include <iostream>
#include <vector>
#include "Sculptor_patch.h"
#include "Interpretador.h"
#include "FiguraGeometrica.h"
#include "putBox.h"
#include "putSphere.h"

int main() {
	
	Sculptor_patch *Modelo;
	Interpretador Analisador;
	std::vector <FiguraGeometrica*> figs;
	figs = Analisador.analise("Teste.txt");
	Modelo = new Sculptor_patch(Analisador.getDimx(), Analisador.getDimy(), Analisador.getDimz());
	
	for(size_t i = 0; i < figs.size(); i++){
		std::cout<<"draw\n";
		figs[i]->draw(*Modelo);
	}
	
	Modelo -> writeOFF((char*)"Dino.off");
	for(size_t i = 0; i < figs.size(); i++){
		delete figs[i];
	}
	
	delete Modelo;
	
	return 0;
}
