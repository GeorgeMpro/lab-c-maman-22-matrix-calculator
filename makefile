CC = gcc # compiler
CFLAGS = -ansi -Wall -pedantic # gcc flags
#EXE_O_DEPS = complex.o mycomp.o input.o # dependencies for executable
EXE_O_DEPS = mymat.o mat.o mat_setup_teardown.o #todo input.o # dependencies for executable
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

#todo remove notes
#input.o: input.c
	#$(CC) -c input.c $(CFLAGS) -o $@

# main - depend on all headers as well (for typedefs & constants)
#mycomp.o: mycomp.c complex.h input.h mycomp.h
#	$(CC) -c mycomp.c $(CFLAGS) -o $@
# input processing
#input.o: input.c input.h
#	$(CC) -c input.c $(CFLAGS) -o $@
