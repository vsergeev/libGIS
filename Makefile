CC = gcc
CFLAGS = -Wall -Wextra -O3
LDFLAGS=
OBJECTS = atmel_generic.o ihex.o srecord.o testGIS.o
PROGNAME = testGIS

all: $(PROGNAME)

$(PROGNAME): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -rf $(PROGNAME) $(OBJECTS)

