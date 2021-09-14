/*************************************************************
* File: potion.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Potion class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef POTION_H
#define POTION_H

#include <iostream>
#include "item.h"
#include "hero.h"

//Clase Potion, subclase de clase Item.
class Potion : public Item {
  //Los atributos los hereda de clase Item.

  //Métodos
  public:
    Potion(); //Constructor por omisión
    Potion(itemType, std::string); //Constructor alterno
    Potion(const Potion&); //Constructor copia

    void useItem(Hero&); //Método para utilizar poción.
};

#endif