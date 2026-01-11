CXX = g++
FLAGS = -Wall -std=c++17
TARGET = program.exe
SRC = src/lab1.cpp 

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(FLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean