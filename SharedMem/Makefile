C = gcc
CXX = g++

SOURCE_CXX1 = publisher.cpp
SOURCE_CXX2 = subscriber.cpp

TARGET1 = publisher
TARGET2 = subscriber

LDFLAGS = -std=c++17 -pthread



all:
	$(CXX) $(SOURCE_CXX1) $(LDFLAGS) -o $(TARGET1) 
	$(CXX) $(SOURCE_CXX2) $(LDFLAGS) -o $(TARGET2) 

clean:
	rm -r *.o $(TARGET)
