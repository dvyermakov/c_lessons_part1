APPNAME = main

SRCS += main.c
SRCS += date.c
SRCS += errors.c

all:
	gcc $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

debug:
	gcc $(SRCS) -o $(APPNAME) -DDEBUG