TARGET= bin/final
SRC= $(wildcard src/*.c)
OBJ= $(patsubst src/%.c, obj/%.o, $(SRC))

.PHONY: default clean

default: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(OBJ) | bin
	gcc -o $@ $^

obj/%.o: src/%.c | obj 
	gcc -c $< -o $@ -Iinc

obj:
	mkdir -p obj 

bin:
	mkdir -p bin
