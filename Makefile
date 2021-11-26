OUT = program
CC = g++

CFLAGS = -Wall -Wextra -std=c++11 -O0 `sdl2-config --cflags`
LDFLAGS = -L./lib/imgui -L/usr/local/include/SDL2/ -pthread -lSDL2 -lSDL2main -lSDL2_image -lpng16 -lz -lGL -limgui -ldl `sdl2-config --libs`

INCLUDE = -Isrc -Ilib

CPPFILES = $(shell find src -maxdepth 2 -type f -name *.cpp)
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