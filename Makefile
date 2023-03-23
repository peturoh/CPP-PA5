CC=g++
SFML_LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: sfml-app

sfml-app: snakes.o
	$(CC) snakes.o -o sfml-app $(SFML_LIBS)

snakes.o: snakes.cpp
	$(CC) -c snakes.cpp

clean:
	rm -f sfml-app *.o
