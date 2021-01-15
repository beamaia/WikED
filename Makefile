CC		:= gcc
CFLAGS	:= -w

BIN		:= bin
SRC		:= .
INCLUDE	:= .

PROGARGS	:= entrada_teste.txt

PROGARGS2	:= entradaCores.txt

PROGARGS3	:= 

EXECUTABLE	:= main
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

VALGRIND	:= 

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
OBJECTS		:= $(SOURCES:.c=.o)

all: clean $(EXECUTABLE)

.PHONY: clean
clean:
	-$(RM) $(OBJECTS)

run: 
	./$(EXECUTABLE) $(PROGARGS)

run2: all
	./$(EXECUTABLE) $(PROGARGS2)
	
run3: all
	./$(EXECUTABLE) $(PROGARGS3)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBRARIES) -lm

val: all
	valgrind ./$(EXECUTABLE) $(PROGARGS)

val2: all
	valgrind ./$(EXECUTABLE) $(PROGARGS2)

val3: all
	valgrind ./$(EXECUTABLE) $(PROGARGS3)

full: all
	- valgrind -v --leak-check=full ./$(EXECUTABLE) $(PROGARGS)

full2: all
	- valgrind -v --leak-check=full ./$(EXECUTABLE) $(PROGARGS2)