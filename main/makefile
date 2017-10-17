#main.out : main.c fun1.c fun2.c
#gcc main.c fun1.c fun2.c -o main.out

CC := gcc
SRCS := $(wildcard *.c)
TRGT :=  $(SRCS:.c=.out)	#../Output/slist.out

LFLAG := -L ../lib/ -lproject
CFLAG := -I ../include
#${TRGT} : ${SRCS}
all:${TRGT}
%.out : %.c
	${CC} $^ ${LFLAG} ${CFLAG} -o  $@

clean :
	rm -f ${TRGT} 
