/*************************************************************
* File: item.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Item class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>
#include "types.h"

//Clase Item
class Item{
  //Atributos protegidos ya que hay subclases que los heredan.
  protected:
    itemType type;
    std::string description;
  
  //Métodos
  public:
    Item(); //Constructor por omisión
    Item(itemType, std::string); //COnstructor alterno
    Item(const Item&); //Constructor copia

    itemType getType(); //Método para obtener tipo del item.
    std::string getDescription(); //Método para obtener descripción del item.

    void setType(itemType); //Método para establecer tipo de item.
    void setDescription(std::string); //Método para establecer descripción del item.
    std::string toString() const; //Método para convertir atributos a string.

    virtual void useItem() ; //Método virtual para utilizar item.
};

#endif