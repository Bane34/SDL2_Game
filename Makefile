OUT = program

CC = g++

CFLAGS = -Wall -Wextra -std=c++11 -O0
LDFLAGS = -Llib -pthread -lSDL2 -lSDL2main -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lpng16 -lz -lGL

INCLUDE = -Iinclude

CPPFILES = $(shell find src -maxdepth 1 -type f -name *.cpp)
CPPOBJECTS = $(CPPFILES:.cpp=.o)

SOURCES = $(CPPFILES)
OBJECTS = $(CPPOBJECTS)

all: $(OUT)

$(OUT): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUT) $(LDFLAGS)

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $< -c -o $@

clean:
	rm -f $(OUT) $(OBJECTS)