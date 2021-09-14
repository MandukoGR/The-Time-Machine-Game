/*************************************************************
* File: boss.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Boss class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef BOSS_H
#define BOSS_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "types.h"
#include <sstream>
#include <string>

// Clase de héroe
class Boss{
  //Atributos privados, ya que no es necesario que otras clases accedan a ellos
  private:
    std::string description; // variable de tipo string description
    uint life; // variable de tipo unsigned int (porque solo se requieren valores positivos) para la vida
  //Métodos
  public:
    Boss(); //Consrtructor por omisión
    Boss(std::string, uint); //Cronstructor alterno
    Boss(const Boss&); //Constructor de copia
    uint attack(); //Función para atacar
    uint getLife() const; //Función para obtener vida
    std::string getDescription() const; //Función para obtener descripcion
    void damage(); //Función para que el boss reciba daño.
};



#endif
