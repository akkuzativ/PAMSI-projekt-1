OUTPUT_NAME = projekt1

FLAGS = -Wall -pedantic
CC = g++

OBJ_PATH = obj/
SRC_PATH = src/
INC_PATH = inc/



all: o
	$(CC) $(FLAGS) -o $(OUTPUT_NAME) $(OBJ_PATH)*

o:
	$(CC) $(FLAGS) -c $(SRC_PATH)*
	mkdir -p $(OBJ_PATH)
	mv *.o $(OBJ_PATH)

clean:
	rm -r $(OBJ_PATH)
	rm $(OUTPUT_NAME)