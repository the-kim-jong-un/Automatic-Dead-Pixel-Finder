B = bin
O = obj
S = src
FLAGS = -c -Wall

all: $(O) $(B) $(B)/main

$(B)/main: $(O)/colorSFML.o 
	g++ -ggdb $(S)/main.cpp -o $(B)/main $(O)/*.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(O)/colorSFML.o: 
	g++ $(FLAGS) $(S)/colorSFML.cpp -o $(O)/colorSFML.o


$(O):
	mkdir $(O)

$(B):
	mkdir $(B)

clean: $(O) $(B)
	rm -rf $(O)
	rm -rf $(B)
