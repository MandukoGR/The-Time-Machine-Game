/*************************************************************
* File: book.h
* Author: Armando Gutiérrez Rojo 
* Description: This file contains the definition of Book class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "item.h"
#include "level.h"
#include "quest.h"

//Clase Book
class Book : public Item {
  //Métodos
  public:
    Book(); //Constructor por omisión.
    Book(itemType, std::string); //Constructor alterno
    Book(const Book&); //Constructor copia.

    void useItem(Quest&, Level&); //Método para utilizar item "Book".
};

#endif