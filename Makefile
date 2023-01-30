CC = g++
CFLAGS = -Wall -Werror -pedantic
OBJECTS = FibLFSR.o PhotoMagic.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic ps1a

ps1a:test.o FibLFSR.o 
	$(CC) $(CFLAGS) -o test test.o FibLFSR.o -lboost_unit_test_framework
test.o:test.cpp
	$(CC) $(CFLAGS) -o test.o -c test.cpp
PhotoMagic: $(OBJECTS) 
	$(CC) $(CFLAGS) -o PhotoMagic FibLFSR.o PhotoMagic.o $(SFML)
PhotoMagic.o: PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o
FibLFSR.o: FibLFSR.cpp FibLFSR.hpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o
clean: 
	rm PhotoMagic ps1a *.o
	
