/*************************************************************
* File: finalRoom.cpp
* Author: Armando Gutiérrez Rojo
* Description: This file contains the implementation of finalRoom
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#include "finalRoom.h"

//Constructor por omisión
finalRoom::finalRoom()
: boss(new Boss){

}

//Constructor  alterno
finalRoom::finalRoom(Boss* b) 
	: boss(b){
}

//Constructor copia
finalRoom::finalRoom(const finalRoom &fr)
	: boss(fr.boss){
}

//Método para que haya pelea
bool finalRoom::passEncounter(Hero *hero, Quest *quest )  {
  //Si la dificultad es fácil el jefe es un  Espartano con 2 puntos de vida
  if(quest->getDifficulty()== 1){
    boss = new Boss("Espartano", 2);
  }

  //Si la dificultad es normal el jefe es un Gladiador con tres puntos de vida
  else if(quest->getDifficulty()==2){
    boss = new Boss("Gladiador", 3);
  }
  //Si la dificultad es normal el jefe es un Dios Griego con cinco puntos de vida
  else if(quest->getDifficulty()== 3){
    boss = new Boss("Zeus", 5);
  }
  
	char option;
	bool cont;

	std::cout << "\nHas respondido todas las preguntas, pero la máquina no quiere ser reconstruida, ¡Ha cobrado vida propia! Y ha tomado la forma de un personaje histórico, es un " << boss <<"\n";

	cont = true;
  //Ciclo que se hará mientras los personajes estén vivos.
	do {
		std::cout << "\n¿Que quieres hacer?\n" << "\nr) Correr\n"  << "\nf) Pelear" << "\n";
		std::cin >> option;
    //Si el jugador elige correr 
		if (option == 'r') {
      std::cout << "\nTu cobardía le ha costado la vida a tu mentor\n";
			cont = false; 
			continue;
		}
    
    //Si el ataque del enemigo es mayor que la defensa del jugador
		if (boss->attack() > hero->defense()) {
			std::cout << "\n" << boss << " te ha atacado\n";
			hero->damage();
		} else {
			std::cout << boss << " ha fallado\n";
		}

    //Si el ataque del enemigo es menor que la defensa del jugador
		if (hero->defense() > boss->attack()) {
			std::cout << "\n" <<  "Has atacado\n";
			boss->damage();
		} else {
			std::cout << "\n" << "Has fallado\n";
		}


	} while (cont == true && (hero->getLife() != 0) && (boss->getLife() != 0));

  //Si el contador es regresa false
	if (cont == false) {
		return false;
	}

  //Si la vida del heroe es 0, el jefe final gana
	if (hero->getLife() == 0) {
		std::cout << "\n" << boss << " wins\n\n";
		return false;
	}

  //Si la vida del jefe es 0 el jugador gana.
	if (boss->getLife() == 0) {
		std::cout << "\n¡Felicitaciones! ¡Has ganado!\n";
		return true;
	} 

	return true;	
}

//Sobrecarga de operador cout <<
std::ostream& operator<< (std::ostream& out, const Boss *boss) {
	out << boss->getDescription();
	return out;
}