/*************************************************************
* File: quest.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Quest class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef QUEST_H
#define QUEST_H

#include <iostream>
#include "types.h"
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>



//Clase de misión 
class Quest{
  private:
  //Atributos privados, ya que no es necesario que otras clases accedan a ellos
    levelDifficulty difficulty; //Dificultad
  public:
    Quest();
    Quest(levelDifficulty);
    Quest(const Quest&);
    void menu(); //Función para mostrar menú.
    levelDifficulty getDifficulty() const; //Obtener dificultad
    void setDifficulty(uint); //Función para establecer dificultad
    std::string toString() const; //Función para convertir valores de atributos a string

};

//Sirve para que texto se imprima lento 
struct slowly_printing_string { std::string data; long int delay; };

#endif

