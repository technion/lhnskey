OBJS=  md5.o lhnskey.o
CC= gcc
CFLAGS= -Wall

all: lhnskey


lhnskey: $(OBJS)
	gcc $(OBJS) -o lhnskey

clean:
	rm -f *.o lhnskey
