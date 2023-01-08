CC = g++
EXEC = main.exe

build: compileSource compileObject
Sbuild: ScompileSource ScompileObject
start: compileSource compileObject run clearObject

compileSource: src/Main.cpp
	$(CC) -c src/*.cpp -I"libs\SFML-2.5.1\include"

compileObject: Main.o
	$(CC) *.o -o bin/$(EXEC) -L"libs\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system


ScompileSource: src/Main.cpp
	$(CC) -c src/*.cpp -I"libs\SFML-2.5.1\include" -DSFML_STATIC

ScompileObject: Main.o
	$(CC) *.o -o bin/$(EXEC) -L"libs\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

run: bin/$(EXEC)
	./bin/$(EXEC)

clearObject:
	rm *.o 