TARGET = program

CC = g++

CFLAGS = -std=c++17 -Wall -lstdc++

SOURCES = main.cpp Algebraic.cpp Trigonometric.cpp

HEADERS = ComplexNumber.h Algebraic.h Trigonometric.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)