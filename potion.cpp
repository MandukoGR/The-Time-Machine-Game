/*************************************************************
* File: potion.cpp
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the implementation of Potion class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include "potion.h"

//Constructor por omisión
Potion::Potion()
	: Item(POTION,"Poción: Brinda 1 punto de salud"){
}

//Constructor alterno
Potion::Potion(itemType t, std::string d)
	: Item(t, d) {
}

//Constructor copia
Potion::Potion(const Potion &p)
  : Item(p.type, p.description){
}

//Método para utilizar poción.
void Potion::useItem(Hero &hero){
  hero.heal();
}

