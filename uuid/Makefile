CC = g++


all: test_uuid

test_uuid: main.o libuuid.a
	$(CC) -lm -o test_uuid main.o -L . -luuid

main.o: main.cpp
	$(CC) -O -c main.cpp

uuid.o: uuid.h uuid.cpp
	$(CC) -O -c uuid.cpp

libuuid.a: uuid.o
	ar rcs libuuid.a uuid.o 

libs: libuuid.a

clean:
	rm -f test_uuid *.o *.a *.gch