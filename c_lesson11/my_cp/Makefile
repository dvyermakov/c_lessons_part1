APPNAME = my_cp

SRCS += main.c
SRCS += errors.c
SRCS += my_filesys.c

all:
	gcc $(SRCS) -o $(APPNAME)

clean:
	rm -f $(APPNAME)

install:
	cp $(APPNAME) /usr/bin

unistall:
	rm -f /usr/bin/$(APPNAME)