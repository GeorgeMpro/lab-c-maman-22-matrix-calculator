CC = gcc # compiler
CFLAGS = -ansi -Wall -pedantic # gcc flags
EXE_O_DEPS = mymat.o mat.o mat_setup_teardown.o input.o command_util.o # dependencies for executable

# final executable
mymat: $(EXE_O_DEPS)
	$(CC) -g $(EXE_O_DEPS) $(CFLAGS) -o $@

mymat.o: mymat.c
	$(CC) -c mymat.c $(CFLAGS) -o $@

#matrix functionality
mat.o: mat.c
	$(CC) -c mat.c $(CFLAGS) -o $@

#matrix initialization and memory freeing
mat_setup_teardown.o: mat_setup_teardown.c
	$(CC) -c mat_setup_teardown.c $(CFLAGS) -o $@

input.o: input.c
	$(CC) -c input.c $(CFLAGS) -o $@

command_util.o: command_util.c
	$(CC) -c command_util.c $(CFAGS) -o $@

clean:
	rm *.o
