TARGET = program

CC = g++

CFLAGS = -std=c++20 -Wall -lstdc++

SOURCES = main.cpp

HEADERS = value.h measurement.h device.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)