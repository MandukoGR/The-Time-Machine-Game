/*************************************************************
* File: inventory.cpp
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the implementation of Inventory class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include "inventory.h"

//Constructor por omisión
Inventory::Inventory()
: items(){

}

//Constructor copia
Inventory::Inventory(const Inventory &inv)
	: items(inv.items){
}

//Destructor
Inventory::~Inventory() {
	for (int i = 0; i < items.size(); i++) {
		delete items[i];
	}
}

//Método para agregar item a inventario
void Inventory::addItem(Item *it) {
		items.push_back(it);
}

//Método para convertir atributos a string
std::string Inventory::toString() const {
	std::stringstream aux;

	aux << &items <<  std::endl;
	return aux.str();
}

//Método para ver inventario
void Inventory::seeInventory(){
  
  if(items.size() == 0){
    std::cout << "Aún no hay nada en tu inventario.\n";
  }
  else{
    std::cout << "Este es tu inventario, si aún no quieres utilizar ningún objeto presion [-1] para volver\n\n"; 

    for(int i = 0; i < items.size()  ; i++){ 
      std::cout << i << " " << items[i]->toString() << "\n";
    
    }
  }
  
}

//Método para seleccionar item a utilizar
void Inventory::selectItem(Hero &hero, Quest &quest, Level &level){
  int opc;
  
  //Mientras opc sea diferente a -1 
  while(opc != -1 && items.size() != 0){
    std::cin >> opc;
    if(opc == -1){
      break;
    }
    itemType type = items[opc]->getType();
    items.erase(items.begin()+opc);
  
  //Si select retorna 1 se utiliza pocion
    if(type == 1){
      Potion potion;
      potion.useItem(hero);
    }
    //Si select retorna 2 se utiliza libro.
    else if(type == 2){
      Book book;
      book.useItem(quest, level);
    }
    
    
    seeInventory();//Ver inventario actualizado
    
  }
  
}

