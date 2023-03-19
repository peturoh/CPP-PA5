all: compile link

compile: g++ -c snakes.cpp

linking: g++ snakes.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
