CFLAGS = -Wall -Wconversion -Wextra

debug:
	gcc -std=gnu2x -g -o syntax_analyzer ${shell find . -name '*.c'} $(CFLAGS) -DDEBUG -fsanitize=address -fno-optimize-sibling-calls

release:
	gcc -std=gnu2x -O3 -o syntax_analyzer ${shell find . -name '*.c'} $(CFLAGS)

clean:
	rm -rf *.o syntax_analyzer