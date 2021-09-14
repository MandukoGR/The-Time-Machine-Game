/*************************************************************
* File: level.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Level class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#ifndef LEVEL_H
#define LEVEL_H


#include <iostream>
#include "types.h"
#include <sstream>
#include <string>
#include <vector>




//Clase de nivel
class Level{
  //Atributos privados, ya que no es necesario que otras clases accedan a ellos
  private:
  std::vector<std::string> questions; //Arreglo de preguntas
  std::vector<std::string> answers; //Arreglo de respuestas
  std::vector<std::string> correctanswers; //Arreglo de respuestas correctas

  //Métodos
  public:
  Level(); //Constructor por omisión
  Level(std::vector<std::string>, std::vector<std::string>, std::vector<std::string>); //Constructor alterno
  Level(const Level&); //Constructor copia

  std::vector<std::string> getQuestions();
  void setQuestions(uint); //Función para establecer arreglo de preguntas dependiendo de la dificultad elegida
  void askQuestion(int); //Función para preguntar.
  std::string selectAnswer(); //Función para ingresar respuesta
  uint validateAnswer(int, std::string);//Función para validar respuesta del usuario

};

#endif
