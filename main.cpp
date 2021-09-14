/*************************************************************
* File: main.cpp
* Author: Armando Gutiérrez Rojo
* Description: 
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include <iostream>
#include "level.h"
#include "quest.h"
#include "hero.h"
#include "inventory.h"
#include "book.h"
#include "item.h"
#include "potion.h"
#include "boss.h"
#include "finalRoom.h"
#include "exception.h"
#include <ctime>

//Funciones para lanzar excepciones

//Función para arrojar excepción RangeError
uint readInputBetween(uint d, uint low, uint high) {
	if (d < low || d > high) {
		throw RangeError();
	}
	return d;
}

//Función para arrojar excepción NoSuchElement
std::string readAnswer(std::string answer) {
	if (answer != "1" && answer != "2" && answer != "3" && answer != "e") {
		throw NoSuchElement();
	}
	return answer;
}

int main(){

  
  //Objetos requeridos
  Quest main; //Objeto "main" perteneciente a clase "Quest"
  Hero heroe; //Objeto "heroe" perteneciente a clase "hero"
  Inventory inventory; //Objeto inventory perteneciente a clase "Inventory"
  Level nivel; //Objeto "nivel" perteneciente a clase "Level"
  Potion potion; //Objeto "potion" perteneciente a clase "Potion"
  Book book; //Objeto "book" pertenecientea clase "Book"
  finalRoom room; //Objeto "room" perteneciente a clase "finalRoom"
  
  //Inicialización de variables
  uint d; //Variable d que contendrá la dificultad.
  uint count; //Variable count que será utilizada para contar respuestas correctas.
  uint finalcount; //Variable finalcount que será utilizada para contar respuestas correctas.
  std::string name; //Variable que contendrá nombre del héroe
  std::string answer; //Variable que contendrá respuesta de usuario
  uint validate; //Variable que contendrá validación de respuesta
  itemType select; //Variable que contendrá selección de item.
  int type; //Variable que contendrá un número aleatorio de 0 a 1.
  bool salida = false;

  //Ejecución
  main.menu(); //Se ejecuta el menu
  while(!salida) {
		try {
      std::cin >> d; //Input para ingresar dificultad
			d = readInputBetween(d,1, 3);
			salida = true;
		} catch (Exception e) {
			std::cout << "El número debe de ser entre 1 y 3\n";
			/* x = 1;
			   break; */
		}
	}
  
  main.setDifficulty(d); //Se establece la dificultad
  name = heroe.getName(); //se obtiene nombre del heroe
  heroe.setName(name);//Se establece el nombre del heroe
  std::cout << "\n" << heroe.toString() << main.toString() << "\n";//Se imprimen atributos.
  nivel.setQuestions(d); //Se establecen preguntas dependiendo del nivel

 
  

  //Ciclo para preguntar
  for(int i = 0; i <= 4; i++ ){
    nivel.askQuestion(i); //Mostrar preguntas
    bool salida;

    salida = false;
    while(!salida) {
      try {
         answer = nivel.selectAnswer(); //Permitir seleccionar respuesta
         answer = readAnswer(answer);
         salida = true; 
      } catch (Exception e) {
        std::cout << "\nOpción inválida, favor de introducir una respuesta válida \n";
      
      }
    }
   
    validate = nivel.validateAnswer(i, answer); //Validación de respuesta
    //Si la respuesta es incorrecta el heroe recibe daño y el contador es igual a 0
    if(validate == 0){
      heroe.damage();
      count = 0;
    }
    //Si la respuesta es correcta el contador suma 1.
    else if(validate == 1){
      count++;
      finalcount++;
      //Si el contador es igual a 3 se añade un item aleatorio al inventario.
      if(count == 3){
        std::cout << "\n¡Has recibido un item! Presiona [e] para ver tu inventario\n";
        srand(time(0)); //Semilla 
        type = rand() % 2; //Número aleatorio
        //Si type es igual a 0 se añade pocion
        if(type == 0){
          inventory.addItem(new Potion);
        }
        //Si type es igual a 1 se añade libro
        else if(type == 1){
          inventory.addItem(new Book);
        }
        count = 0; //Se reinicia contador
      }
      
    }
    //Si la respuesta retorna 2 es porque se seleccionó ver inventario.
    else if(validate == 2){
      inventory.seeInventory();
      inventory.selectItem(heroe, main, nivel); //Seleccion de item a utilizar.
      i--; //Se vuelve a la pregunta
      
    }
    
  }

  //Si el jugador tiene todas las respuestas correctas se le otorgará un botín
  if(finalcount == 5){
    std::cout << "\n¡Has recibido un botín! Presiona [e] para ver tu inventario\n";
    inventory.addItem(new Potion);
    inventory.addItem(new Potion);
    inventory.addItem(new Potion);
    inventory.addItem(new Book);
    count = 0;
  }
  std::string opcion;
  std::cout << "\nHas llegado a la última pregunta. Pero te enfrentarás al jefe final preparate antes de pelear\n" << "\n[e] Abrir inventario\n" << "\n[c] Continuar\n";
  std::cin >> opcion;
  if(opcion == "e"){
    inventory.seeInventory();
    inventory.selectItem(heroe, main, nivel); //Seleccion de item a utilizar.
  }
  bool encounter =room.passEncounter(&heroe, &main);
  if( encounter == true){//Pelea final
    std::cout << "\nBien hecho, has salvado a tu mentor y la máquina del tiempo no volverá a fallar ¡Excelente desempeño¡\n"; 
  }
}