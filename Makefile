EXEC = 8080.out
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)
flags = -g

$(EXEC): $(OBJECTS)
	gcc $(OBJECTS) $(flags) -o $(EXEC)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm *.out
	-rm *.o