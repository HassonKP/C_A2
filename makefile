CC=gcc
CFLAGS=-Wall
DFLAGS=-g
PROGS= setBits showBits

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@

clean:
	rm -f $(PROGS) *.log *.txt *.o ~*

