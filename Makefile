BINS = test

CFLAGS := -Wall -pedantic -std=c99

SRC  = $(wildcard src/*.c) test.c
DEPS  = $(wildcard deps/*/*.c)
OBJS = $(SRC:.c=.o) $(DEPS:.c=.o)

CFLAGS  = -std=c99 -Isrc -Ideps -Wall -Wno-unused-function -U__STRICT_ANSI__

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

$(BINS): $(SRC) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	@./test

clean:
	$(RM) $(OBJS) $(BINS)

.PHONY: test
