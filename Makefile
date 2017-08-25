AM_CFLAGS := -g -Wall -O2

CC        := gcc
CFLAGS    := $(AM_CFLAGS)

LD        := gcc

APPS      := min
OBJS      := $(APPS).o
SRCS      := $(APPS).c

min: min.o
	$(LD) $(AM_CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -fr $(APPS) *.o *.out
