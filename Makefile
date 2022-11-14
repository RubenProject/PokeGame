CC = g++ -g -Wall -Wextra -std=c++2a


CFLAGS = 
LIBS = -ljsoncpp



OBJS = Game.o Type.o Pokemon.o Attack.o Player.o Battle.o

all: PokeGame

PokeGame: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o PokeGame $(LIBS)

Game.o: Game.cpp
	 $(CC) -c $(CFLAGS) Game.cpp $(LIBS)

Pokemon.o: Pokemon.cpp Type.hpp
	 $(CC) -c $(CFLAGS) Pokemon.cpp $(LIBS)

Attack.o: Attack.cpp Type.hpp
	 $(CC) -c $(CFLAGS) Attack.cpp $(LIBS)

Type.o: Type.cpp
	 $(CC) -c $(CFLAGS) Type.cpp $(LIBS)


Player.o: Player.cpp
	 $(CC) -c $(CFLAGS) Player.cpp $(LIBS)

Battle.o: Battle.cpp
	 $(CC) -c $(CFLAGS) Battle.cpp $(LIBS)

clean:
	rm *.o PokeGame

