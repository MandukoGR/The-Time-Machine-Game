/*************************************************************
* File: hero.cpp
* Author: Armando Gutiérrez Rojo
* Description: This file contains the implementation of Hero
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/


#include "hero.h"


//Constructor por omisión
Hero::Hero() 
	: name("noname"), life(3) {
}

//Constructor  alterno
Hero::Hero(std::string n, uint li) 
	: name(n), life(li) {
}

//Constructor copia
Hero::Hero(const Hero &hero)
	: name(hero.name), life(hero.life){
}

//Método para obtener nombre del héroe
std::string Hero::getName() const {
  std::string name;
  std::cout << "¡Hola científico! ¿Cuál es tu nombre?" << std::endl;
  std::cin >> name;
	return name;
}
uint Hero::getLife() const{
  return life;
}
//Método para establecer nombre del héroe
void Hero::setName(std::string n) {
	name = n;
}
//Método para defender
uint Hero::defense(){
  uint num = 1 + rand() % 6;
  return num ;


}
//Método por si el héroe recibe daño
void Hero::damage(){
  life = life - 1;
  std::cout << "Has recibido daño te quedan " << life << " puntos de vida" << std::endl;
  if(life == 0){
    std::cout << "Ya no tienes vida, has perdido :( " << std::endl;
    exit(-1);
  }
}
//Método por si el héroe recibe cura
void Hero::heal(){
  life = life + 1;
  std::cout << "Te has curado, te quedan " << life << " puntos de vida" << std::endl;
}


//Método para convertir valores de atributos a string
std::string Hero::toString() const {
	std::stringstream aux;

	aux << "Hola " << name << "," << "empezarás con " << life << " puntos de vida"<<  std::endl;
	return aux.str();
}