C = gcc
CXX = g++

SOURCE_CXX = main.cpp

TARGET = SharedLibrary

LDFLAGS = -std=c++17 -pthread

hello.so:
	$(CXX) -fPIC -shared hello.cpp -o hello.so

all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS) -o $(TARGET) -ldl

clean:
	rm -r *.o $(TARGET)
