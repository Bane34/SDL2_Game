OUT := libimgui.a 
AR := ar
ARFLAGS := -crs
RANLIB := ranlib 
SRC := src 
CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -O3

CPPFILES = $(shell find $(SRC) -maxdepth 2 -type f -name *.cpp)
CPPOBJECTS = $(CPPFILES:.cpp=.o)

SOURCES = $(CPPFILES)
OBJECTS = $(CPPOBJECTS)

SUBDIRS := $(shell find $(SRC) -type d)
OBJSUBDIRS := $(patsubst $(SRC)%,$(OBJ),$(SUBDIRS))

all: $(OUT)

$(OUT): $(OBJECTS)
	$(AR) $(ARFLAGS) $(OUT) $(CPPOBJECTS)
	$(RANLIB) $(OUT)

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OUT) $(OBJECTS)