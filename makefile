parking:parking.o main.o
	gcc parking.o main.o -o parking
parking.o:parking.c
	gcc -c parking.c
main2.o:main.c
	gcc -c main.c
