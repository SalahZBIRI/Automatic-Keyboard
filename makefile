main.o: main.c data.h prediction.h gui.h
	gcc -c main.c -lncurses `pkg-config --cflags --libs gtk4` 

data.o: data.c data.h
	gcc -c data.c -lm

prediction.o: prediction.c prediction.h data.h
	gcc -c prediction.c -lm

gui.o: gui.c gui.h
	gcc -c gui.c `pkg-config --cflags --libs gtk4` 

main: main.o data.o prediction.o gui.o
	gcc main.o data.o prediction.o gui.o -o main -lm -lncurses `pkg-config --cflags --libs gtk4` 