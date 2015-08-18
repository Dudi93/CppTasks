CFLAGS = -Wall -g -std=c++11
LFLAGS = -pthread
SOURCES = ./src/main.cpp
EXECUTABLE = prog

OBJECTS = $(SOURCES:.cpp=.o)


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ $(OBJECTS) -o $(EXECUTABLE) $(LFLAGS) 

%.o: %.cpp
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)