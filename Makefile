CC=gcc
CFLAGS=-I.
DEPS = move_validation.h menu.h checkmate_engine.h
OBJ = main.o move_validation.o menu.o checkmate_engine.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

chess: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: chess
	./chess