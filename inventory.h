/*************************************************************
* File: inventory.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Inventory class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "types.h"
#include "item.h"
#include "hero.h"
#include "quest.h"
#include "potion.h"
#include "book.h"
#include "level.h"

//Clase Inventory
class Inventory{
//Atributos privados, ya que no es necesario que otras clases accedan a ellos
private:
	std::vector<Item*> items;

//Métodos
public:
	Inventory(); //Constructor por omisión
	Inventory(const Inventory&); //Constructor copia
	~Inventory(); //Destructor

  std::string toString() const; //Método para convertir atributos a string.
	void addItem(Item*); //Método para añadir itema al inventario
  void seeInventory(); //Método para ver el inventario.
  void selectItem(Hero&, Quest&, Level&); //Método para seleccionar item a utilizar.
};
#endif