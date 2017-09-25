# General makefile

CC=gcc
CFLAGS=-c
LDFLAGS= 

# These are the directories to be used for the program files
# SOURCEDIR contains the source files - your ".c" files
# INCDIR contains the header files your make - your ".h" files
# BUILDDIR this is where your object files will go - by keeping them all in one directory they are easier to remove

SOURCEDIR = .
INCDIR = .
BUILDDIR = .

# These two lines will make lists of the source files and the object files
# first it finds all the *.c files in the SOURCEDIR directory and puts their
# names in a list called SOURCES. Then it makes a new list with the ".c"s replaced
# by ".o"s

SOURCES=$(wildcard $(SOURCEDIR)/*.c )
OBJECTS=$(patsubst $(SOURCEDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))

# This is the name of the executable you are going to create

TARGET=smoother

# These are the rules which are needed to compile and link.
# Each one basically says that the things on the left of the colon depends on the things to 
# the right of the colon. 
# Below each rule is what needs to be done if the files it depends on are out of date

# The first rule is "all" meaning everything gets compiled when we call "make all"

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) $< -o $@