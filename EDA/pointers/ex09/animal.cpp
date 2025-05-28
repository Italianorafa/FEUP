#include "animal.h"
#include <cstring>

using namespace std;
// início funções classe veterinário

Veterinario::Veterinario(){
	nome = "";
	especialidade = "";
}

Veterinario::Veterinario(string nom, string esp):nome(nom), especialidade(esp){}

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

Animal::Animal(string esp, bool sex, string nom, int age): especie(esp), sexo(sex), nome(nom), idade(age){}

Animal::Animal(string esp, bool sex, string nom, int age, Veterinario vet): especie(esp), sexo(sex), nome(nom), idade(age),veterinario(vet){}

string Animal::getEspecie() const{
	return especie;
}
bool Animal::getSexo() const{
	return sexo;
}
string Animal::getNome() const{
	return nome;
}
Veterinario Animal::getVeterinario() const{
	return veterinario;
}

int Animal::getIdade(void) const{
	return idade;
}

void Animal::setIdade(int id){
	idade = id;
}

void Animal::setVeterinario(Veterinario vet){
	veterinario=vet;
}

Animal::Animal(Animal &a): especie(a.especie), sexo(a.sexo), nome(a.nome), idade(a.idade), veterinario(a.veterinario){}