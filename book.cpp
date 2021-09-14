/*************************************************************
* File: book.cpp
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the implementation of Book class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/

#include "book.h"

//Constructor por omisión
Book::Book()
	: Item(BOOK,"Libro mágico: Puedes cambiar dificultad de nivel "){
}

//Constructor alterno
Book::Book(itemType t, std::string d)
	: Item(t, d) {
}

//Constructor copia
Book::Book(const Book &s)
  : Item(s.type, s.description){
}

//Método para utilizar item "Book".
void Book::useItem(Quest &q, Level &l){
  uint d;
  std::cout<< "\nHas utilizado un libro mágico, puedes cambiar de dificultad \n";
  std::cout << "\n[1] Fácil\n" << "\n[2] Normal\n" <<"\n[3] Dificil\n";
  std::cin>> d;
  q.setDifficulty(d); //Se cambia la dificultad
  l.setQuestions(d); //Se cambian las preguntas
}
