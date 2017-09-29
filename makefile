CC = gcc
FLAGS = -g
LINK = -lsdl2
INCLUDE = -I/usr/local/include/SDL2
LIB = -L/usr/local/lib

SOURCEDIR = src
BUILDDIR = build

EXECUTABLE = oziak
SOURCES = $(wildcard $(SOURCEDIR)/*.c)
OBJECTS = $(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

all: dir $(BUILDDIR)/$(EXECUTABLE)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LINK) $(INCLUDE) $(LIB) $^ -o $@

$(OBJECTS): $(BUILDDIR)/%.o : $(SOURCEDIR)/%.c
	$(CC) $(FLAGS) $< -c -o $@

clean:
	rm -f $(BUILDDIR)/*o $(BUILDDIR)/$(EXECUTABLE)