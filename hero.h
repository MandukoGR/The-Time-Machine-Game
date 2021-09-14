/*************************************************************
* File: hero.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Hero class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef HERO_H
#define HERO_H


#include <iostream>
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include "types.h"
#include <sstream>
#include <string>
#include <vector>

// Clase de héroe
class Hero{
  //Atributos privados, ya que no es necesario que otras clases accedan a ellos
  private:
    std::string name; // variable de tipo string nombre
    uint life; // variable de tipo unsigned int (porque solo se requieren valores positivos) para la vida
  //Métodos
  public:
    Hero(); //Consrtructor por omisión
    Hero(std::string, uint); //Cronstructor alterno
    Hero(const Hero&); //Constructor de copia
    
    std::string getName() const; //Función para obtener nombre
    uint getLife() const; //Función para obtener vida
    void setName(std::string); //Función para establecer nombre
    uint defense(); //Funcion para defender
    void damage(); //Función para que el heroe reciba daño.
    void heal(); //Función para que el heroe se cure
    std::string toString() const; //Función para convertir valores de atributos a string
};

#endif
