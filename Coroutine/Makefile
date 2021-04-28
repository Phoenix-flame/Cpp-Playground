C = gcc
CXX = g++-10

SOURCE_CXX = coroutine.cpp

TARGET = coroutine

LDFLAGS = -std=c++20 -pthread -fcoroutines


all:
	$(CXX) $(SOURCE_CXX) $(LDFLAGS) -o $(TARGET)

clean:
	rm -r *.o $(TARGET)
