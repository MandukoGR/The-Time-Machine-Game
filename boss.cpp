/*************************************************************
* File: boss.cpp
* Author: Armando Gutiérrez Rojo
* Description: This file contains the implementation of Boss
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/


#include "boss.h"


//Constructor por omisión
Boss::Boss() 
	: description("noname"), life(3) {
}

//Constructor  alterno
Boss::Boss(std::string d, uint li) 
	: description(d), life(li) {
}

//Constructor copia
Boss::Boss(const Boss &boss)
	: description(boss.description), life(boss.life){
}

//Método para obtener descripción de jefe
std::string Boss::getDescription() const {
	return description;
}

//Método para obtener vida
uint Boss::getLife() const{
  return life;
}
//Método para atacar
uint Boss::attack(){
  srand(time(0));
  uint num = 1 + rand() % 6;
  return num ;

}
//Método por si el jefe recibe daño
void Boss::damage(){
  life = life - 1;
  std::cout << "\nTu enemigo ha recibido daño, le quedan " << life << " puntos de vida\n" << std::endl;
  if(life == 0){
    std::cout << "\nBien hecho, has derrotado al enemigo\n" << std::endl;
  }
}

