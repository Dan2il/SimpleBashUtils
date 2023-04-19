CFLAG=-std=c11 -c
OFLAG=-std=c11 -o
CFLAGS=-std=c11 -fsanitize=address -c
OFLAGS=-std=c11 -fsanitize=address -o

all: s21_grep

s21_grep: grep.o parsing.o processing_flags.o list.o get_data_file.o out_functions.o
	gcc $(OFLAG) s21_grep grep.o parsing.o processing_flags.o list.o get_data_file.o out_functions.o

grep.o:	grep.c
	gcc $(CFLAG) grep.c grep.h

parsing.o: parsing.c
	gcc $(CFLAG) parsing.c parsing.h

processing_flags.o: processing_flags.c
	gcc $(CFLAG) processing_flags.c processing_flags.h

list.o: list.c
	gcc $(CFLAG) list.c list.h

get_data_file.o: get_data_file.c
	gcc $(CFLAG) get_data_file.c get_data_file.h

out_functions.o: out_functions.c
	gcc $(CFLAG) out_functions.c out_functions.h

clean:	
	rm rf *.o *.gch s21_grep s21_greps

clean_txt:
	rm rf *.txt

clean_all:
	rm rf *.o *.gch *.txt s21_grep s21_greps

reb: 
	$(MAKE) clean 
	$(MAKE) test