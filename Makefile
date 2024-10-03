all: compile link run

compile:
	g++ -c main.cpp -IC:\cpp_libraries\SFML-2.6.1\include -DSFML_STATIC

link:
	g++ main.o -o main -LC:\cpp_libraries\SFML-2.6.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

run:
	./main

clear:
	rm -f main.exe *.o
