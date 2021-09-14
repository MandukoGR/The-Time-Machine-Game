/*************************************************************
* File: quest.cpp
* Author: Armando Gutiérrez Rojo
* Description: This file contains the implementation of Quest
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include "quest.h"

//Sirve para que texto se imprima lento 
std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
    for (const auto& c : s.data) {
        out << c << std::flush;        
        std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
    }
    return out;
}
//Consturctor por omision
Quest::Quest()
: difficulty(NONE){
}
//Consturctor alterno
Quest::Quest(levelDifficulty d)
: difficulty(d){
}
//Consturctor copia
Quest::Quest(const Quest &quest)
: difficulty(quest.difficulty){

}
//Método que despliega bienvenida y menú
void Quest::menu(){
  std::cout << slowly_printing_string{"Has estado ayudando al cientifico Isaac Albert Brown a construir una maquina del tiempo. Sin embargo, en una de las practicas de prueba la maquina se ha averiado. Tu mentor tambien ha desaparecido. Sin embargo, logra comunicarse contigo a traves del monitor averiado de la maquina del tiempo. Te informa que para que el pueda regresar al tiempo actual debes de ayudarlo respondiendo preguntas de historia. La maquina esta a punto de destruirse por completo, solo puedes equivocarte 3 veces si no la maquina explotara y nunca mas veras a tu mentor. El doctor Brown tambien te menciona que si tienes una racha de 3 respuestas correctas la maquina expulsara objetos con los cuales la puedes reparar, dandote ventajas como cambiar dificultad de las preguntas u obtener una vida extra.",20} << std::endl << "Selecciona dificultad: " << std::endl;
  std::cout << "[1] Fácil" << std::endl << "[2] Normal" << std::endl <<  "[3] Dificil" << std::endl;
}

//Método para establecer dificultad
void Quest::setDifficulty(uint d){
    if( d == 1){
      difficulty = EASY;
    }
    else if (d == 2){
      difficulty = NORMAL;
     
    }

    else if (d == 3){
      difficulty = HARD;
      
    } 
}
levelDifficulty Quest::getDifficulty() const{
  return difficulty;
}
//Método que convierte atributos a string
std::string Quest::toString() const {
	std::stringstream aux;

	aux << "en dificultad " << difficulty << std::endl;
	return aux.str();
}