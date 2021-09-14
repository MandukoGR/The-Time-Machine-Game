/*************************************************************
* File: item.cpp
* Author: Armando Gutiérrez Rojo
* Description: This file contains the implementation of Item
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include "item.h"


//Constructor por omisión
Item::Item() 
	: type(NOTHING), description("none") {
}

//Constructor  alterno
Item::Item(itemType t, std::string d) 
	: type(t), description(d) {
}

//Constructor copia
Item::Item(const Item &item)
	: type(item.type), description(item.description){
}

//Método para obtener tipo del item.
itemType Item::getType(){
  return type;
}

//Método para establecer tipo de item.
void Item::setType(itemType t) {
	type = t;
}

//Método para obtener descripción del item.
std::string Item::getDescription(){
  return description;
}

//Método para establecer descripción del item.
void Item::setDescription(std::string d){
  description = d;
}

//Método para utilizar item (vacío ya que es virtual y cambiará dependiendo de subclases)
void Item::useItem(){
  
}

//Método para convertir atributos a string.
std::string Item::toString() const {
	std::stringstream aux;

	aux << description <<  std::endl;
	return aux.str();
}
