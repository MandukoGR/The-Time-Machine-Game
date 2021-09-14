all: main.o hero.o quest.o level.o inventory.o item.o potion.o book.o boss.o finalRoom.o 
	g++ main.o hero.o quest.o level.o inventory.o item.o potion.o book.o boss.o finalRoom.o -o app

main.o: main.cpp
	g++ -c main.cpp

hero.o: hero.h hero.cpp
	g++ -c hero.cpp

level.o: level.h level.cpp
	g++ -c level.cpp

quest.o: quest.h quest.cpp
	g++ -c quest.cpp

inventory.o: inventory.h inventory.cpp
	g++ -c inventory.cpp

item.o: item.h item.cpp
	g++ -c item.cpp

potion.o: potion.h potion.cpp
	g++ -c potion.cpp

book.o: book.h book.cpp
	g++ -c book.cpp

boss.o: boss.h boss.cpp
	g++ -c boss.cpp

finalRoom.o: finalRoom.h finalRoom.cpp
	g++ -c finalRoom.cpp



clean:
	rm *.o app