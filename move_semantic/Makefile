C = gcc
CXX = g++

SOURCE_CXX = move_semantic.cpp

TARGET = move_semantic

LDFLAGS = -std=c++17 -pthread


all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS) -o $(TARGET)

clean:
	rm -r *.o $(TARGET)
