/*************************************************************
* File: finalRoom.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of finalRoom class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef FINALROOM_H
#define FINALROOM_H

#include "quest.h"
#include "boss.h"
#include "hero.h"

//clase de cuarto final
class finalRoom {
//Atributos privados
private:
	Boss* boss; //Apuntador a objeto de clase Boss

public:
	finalRoom(); // Constructor por omisión
	finalRoom(Boss*); //Constructor alterno
	finalRoom(const finalRoom&); //Constructor copia

	bool passEncounter(Hero*, Quest*); //Función para realizar encuentro
};

//Sobrecarga de operador cout <<
std::ostream& operator<< (std::ostream&, const Boss*);
#endif
