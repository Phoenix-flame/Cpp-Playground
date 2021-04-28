CC = g++


all: test_timer

test_timer: main.o 
	$(CC) -lm -o test_timer main.o -pthread

main.o: main.cpp timer.h
	$(CC) -O -c main.cpp timer.h


clean:
	rm -f test_timer *.o *.a *.gch