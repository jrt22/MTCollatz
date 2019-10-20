CFLAGS = -lpthread -g 
CC = g++

objects = mt-collatz.cpp 

mt-collatz.o: $(objects)
	$(CC) $(objects) -o mt-collatz $(CFLAGS)


.PHONY : clean
clean: 
	rm myshell $(objects)
