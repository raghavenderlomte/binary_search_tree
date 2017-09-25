CC=gcc  #type of compiler i am using gcc

FLAGS = -I include/ -g   #to include the header file which is present in include folder
OBJPATH1= source/	#objpath1 and 2 contains the path of .c files
OBJPATH2= test/

default:executable clean

executable:main.o src.o
	$(CC) -o executable main.o src.o

main.o:$(OBJPATH2)main.c
	$(CC) $(FLAGS) -c $(OBJPATH2)main.c

src.o:$(OBJPATH1)src.c
	$(CC) $(FLAGS) -c $(OBJPATH1)src.c

clean:
	rm -rf main.o src.o
