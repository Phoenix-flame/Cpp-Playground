C = gcc
CXX = g++

SOURCE_CXX = promise.cpp

TARGET = promise

LDFLAGS = -std=c++17 -pthread


all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS) -o $(TARGET)

clean:
	rm -r *.o $(TARGET)
