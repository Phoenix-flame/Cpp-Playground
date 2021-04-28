CC = g++
SOURCE = main.cpp
TARGET = test_db
LDFLAGS = -std=c++14 -I /usr/include/mysql -I /usr/include/mysql++  -lmysqlpp -lmysqlclient 
all:
	$(CC) $(SOURCE) $(LDFLAGS) -o $(TARGET) 
clean:
	rm $(TARGET)
run:
	./$(TARGET)