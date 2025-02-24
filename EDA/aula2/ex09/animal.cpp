#include "animal.h"
#include <cstring>

using namespace std;
// início funções classe veterinário

Veterinario::Veterinario(){
	nome = "";
	especialidade = "";
}

Veterinario::Veterinario(string nom, string esp){
	nome = nom;
	especialidade = esp;
}

string Veterinario::getNome() const{
	return nome;
}

string Veterinario::getEspecialidade() const{
	return especialidade;
}

void Veterinario::setNome(string nom){
	nome = nom;
}

void Veterinario::setEspecialidade(string esp){
	especialidade = esp;
}

// Fim funções classe veterinários

// Início funções classe animal

Animal::Animal(string esp, bool sex, string nom, int age){
	especie = esp;

}