


OBJS= ui_main.o token_functions.o


CFLAGS=-g -O3

all: ui_main

ui_main:$(OBJS)
	cc -o ui_main $(CFLAGS) $(OBJS)



$(OBJS): tokenizer.h

clean:
	rm -f *.o ui_main

run:ui_main
	./ui_main
