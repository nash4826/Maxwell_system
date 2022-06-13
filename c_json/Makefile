STD = -std=c99
ERRFLAGS = -W -Wall

json.o : json.h parson.h json.c
	clang $(STD) $(ERRFLAGS) -c json.c

parson.o : parson.h parson.c
	clang $(STD) $(ERRFLAGS) -c parson.c

menu.o : menu.h menu.c
	clang $(STD) $(ERRFLAGS) -c menu.c

main.o : main.c menu.h json.h
	clang $(STD) $(ERRFLAGS) -c main.c

status : json.o parson.o menu.o main.o
	clang $(STD) $(ERRFLAGS) json.o parson.o menu.o main.o -o status.exe
	rm -f json.o parson.o menu.o main.o