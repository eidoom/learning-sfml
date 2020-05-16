sfml-app: main.o
	g++ $< -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c $< -o $@
