CFLAG=-std=c11 -c
OFLAG=-std=c11 -o
CFLAGS=-std=c11 -Wall -Werror -Wextra -fsanitize=address -c
OFLAGS=-std=c11 -Wall -Werror -Wextra -fsanitize=address -o

s21_cat: s21_cat.o
	gcc $(OFLAG) s21_cat s21_cat.o

san: sanit_cat.o
	gcc $(OFLAGS) s21_cats cat.o

s21_cat.o:	s21_cat.c
	gcc $(CFLAG) s21_cat.c s21_cat.h

sanit_cat.o: cat.c
	gcc $(CFLAGS) cat.c

reb: 
	$(MAKE) clean
	$(MAKE) test

clean:	
	rm rf *.o *.gch s21_cat s21_cats

clean_txt:
	rm rf *.o *.gch *.txt