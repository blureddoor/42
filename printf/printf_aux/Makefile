# Makefile
CC=gcc
CFLAGS= -I.
ODIR=obj
OBJ=main.o base.o 
DEPS= base.h
all: main
	@echo "Finish."
main: $(OBJ)
	@echo "Building the application core.."
	$(CC) -o x $(OBJ) $(CFLAGS) -g
	
%.o: %.c $(DEPS)
	@echo "Building objects.."
	$(CC) -c -o $@ $< $(CFLAGS) -Wall 
clean: 
	@echo "Cleaning up.."
	rm -f $(OBJ) x
#win: af
#	@echo "Building Windows Executable.."
#	$(CC) -o x.exe $(OBJ) $(CFLAGS)1
