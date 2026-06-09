# ─────────────────────────────────────────────
#  Ignis Vael — Simple Makefile (Arch / Linux)
# ─────────────────────────────────────────────
CC      = gcc
TARGET  = ignis_vael
SRC     = testing.c
CFLAGS  = -O2 -std=c11 -Wall -Wextra \
          $(shell pkg-config --cflags sdl3 2>/dev/null || sdl3-config --cflags 2>/dev/null)
LDFLAGS = $(shell pkg-config --libs   sdl3 2>/dev/null || sdl3-config --libs   2>/dev/null) -lm

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
