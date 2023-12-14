src = $(wildcard *.c)
bin = $(patsubst %.c,%,$(src))

all : $(bin)

% : %.c
	$(CC) -o $@ $<

clean :
	rm -f $(bin)
