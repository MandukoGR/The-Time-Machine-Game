/*************************************************************
* File: level.cpp
* Author: Armando Gutiérrez Rojo
* Description: This file contains the implementation of Level
*							 class.
*
* Copyright (c) 2021 by Tecnologico de Monterrey.
* All Rights Reserved. May be reproduced for any non-commercial
* purpose.
*************************************************************/


#include "level.h"

//Implementación clase Level

//Constructor por omisión
Level::Level() 
	:  questions(), answers(), correctanswers() {
}

//Constructor alterno
Level::Level(std::vector<std::string> q, std::vector<std::string> ans, std::vector<std::string> cans) 
	:  questions(q), answers(ans), correctanswers(cans) {
}

//Constructor copia
Level::Level(const Level &level)
  :  questions(level.questions), answers(level.answers){
  }

//Método para establecer arreglo de preguntas dependiendo de la dificultad elegida
//Se estableceran, dependiendo del nivel, preguntas, opciones de respuesta y respuestas correctas,
//para posteriormente realizar una comparación de las respuestas del usuario con las correctas.
void Level::setQuestions(uint d){
  if (d == 1){
    questions = {"1. ¿Qué beneficio trajo al hombre la caza del mamut?", 
                 "2. Durante la Edad Media una civilización asiática se destacó por su avance científico. ¿Cuál de las siguientes civilizaciones inventó el papel, la imprenta y la pólvora?", 
                 "3. ¿Qué cultura practicaba la momificación como forma de conservar los cadáveres pensando que después de la muerte aún había vida?", 
                 "4. Para que los pueblos nómadas se transformaran en sedentarios, ¿qué actividad fundamental fue necesaria para este cambio?", 
                 "5. ¿Qué pueblo andino habló el quechua como idioma oficial?"};
    answers = {"[1] Con los huesos construyó herramientas e instrumentos musicales\n[2] La piel de   este animal sirvió como fertilizante.\n[3] Utilizó la grasa para cocinar sus alimentos\n", 
               "[1] India.\n[2] China.\n[3] Japón\n",
               "[1] Egipto.\n[2] Mesopotamia.\n[3] China.\n",
               "[1] Metalurga.\n[2] Ganadería.\n[3] Agricultura.\n",
               "[1] Inca.\n[2] Chavín.\n[3] Nazca.\n",};
    correctanswers = {"1","2","1","3","1"};
  }

  else if ( d == 2){
    questions = {"1. ¿Cuál fue la principal actividad económica de las sociedades feudales?",
                 "2. ¿Qué características culturales compartían los pueblos del periodo Clásico en Mesoamérica?", 
                 "3. ¿Cuál fue la principal causa que impulsó los viajes de exploración a partir del siglo XV? ", 
                 "4. ¿Qué era necesario ser para poder participar en la democracia ateniense?", 
                 "5. ¿Cuál fue una de las características físicas que permitió el desarrollo de las culturas mesoamericanas?"};
    answers = {"[1] El comercio marítimo de oro y plata.\n[2] La industria cerámica y de textiles.\n [3] La producción agrícola y ganadera.\n", 
               "[1] Inventaron el juego de pelota\n[2] Practicaron el comercio.\n[3] Dominaron la talla de piedra y la escultura monumental. Su principal dios fue el jaguar\n",
               "[1] Organizar un ejército cristiano para derrotar a los árabes.\n[2] Buscar nuevas vías de comunicación para facilitar el comercio de los reinos europeos.\n[3] Extender la religión católica en África y Asia.\n",
               "[1] Ciudadano. \n[2] Senador. \n[3] Comerciante.\n",
               "[1] Contar con un territorio propicio para la agricultura y ganadería.\n[2] Vivir en regiones que les permitieron ser pescadores y cazadores.\n[3] Dominar una gran extensión territorial donde construir ciudades.\n",};
    correctanswers = {"3","3","2","1","1"};
  }

  else if ( d == 3){
    questions = {"1. ¿Cómo se llama el primer homínido que fabricó armas y herramientas con madera, hueso y piedra para cazar grandes animales, además de ser el primero en enterrar a sus muertos?", 
                 "2. ¿Cuál de las siguientes opciones menciona datos importantes de la civilización islámica?", 
                 "3. ¿Cuál es la principal razón por la que la cultura helenística se extendió en el mundo?", 
                 "4. ¿Cuál fue la principal consecuencia de la caída de Constantinopla en poder de los turcos otomanos?", 
                 "5. ¿Cuál fue la principal causa de que en España, Portugal, Inglaterra y Francia durante los siglos XV y XVI, se fundaran monarquías de tipo absolutista?"};
    answers = {"[1] Homo sapiens\n[2] Homo erectus\n[3] Homo habilis\n",
               "[1] Se desarrolló en Líbano, su libro sagrado era el Talmud.\n[2] Fue una civilización agrícola.\n[3] Su líder religioso fue Mahoma y su libro sagrado era el Corán.\n",
               "[1] La imposición que hicieron los romanos de sus costumbres y cultura en los sitios conquistados.\n[2] Las conquistas que logró Alejandro Magno para consolidar el más grande imperio de su tiempo.\n[3] El buen gusto de los extranjeros que apreciaban las artes y ciencias, por lo que las difundieron.\n",
               "[1] El expansionismo político y cultural musulmán en toda Europa.\n[2] El fin de las monarquías europeas y el inicio de las repúblicas.\n[3] El fin del régimen imperial y el desarrollo del feudalismo.\n",
               "[1] El descubrimiento y control de las nuevas rutas comerciales.\n[2] La alianza de gobernantes con banqueros y comerciantes ricos.\n[3] Las constantes invasiones externas que debilitaban su poderío.\n", };
    correctanswers = {"1","3","2","1","2"};
  }

}  
std::vector<std::string> Level::getQuestions(){
  return questions;
}
//Método para preguntar.
void Level::askQuestion(int i){
  std::cout << questions[i] << std::endl;
  std::cout << answers[i] << std::endl;

}

//Método para ingresar respuesta
std::string Level::selectAnswer(){
  std::string answer;
  std::cin >> answer;
  return answer;
}

//Método para evaluar respuesta del usuario
uint Level::validateAnswer(int i, std::string answer){
  if(answer == correctanswers[i]){
    std::cout << "Correcto" << std::endl;
    return 1;
  }
  else if (answer == "e"){
    return 2;

  }
  else{
    return 0;
  }

}


