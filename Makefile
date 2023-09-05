pairsofwords: main.o init.o insert.o getWord.o find.o printTable.o crc64.o grow.o toArray.o comparator.o printArray.o
	gcc -o pairsofwords main.o init.o insert.o getWord.o find.o printTable.o crc64.o grow.o toArray.o comparator.o printArray.o

main.o: main.c main.h
	gcc -c main.c main.h

init.o: init.c main.h
	gcc -c init.c main.h

insert.o: insert.c main.h
	gcc -c insert.c main.h

getWord.o: getWord.c main.h
	gcc -c getWord.c main.h

find.o: find.c main.h
	gcc -c find.c main.h

printTable.o: printTable.c main.h
	gcc -c printTable.c main.h

crc64.o: crc64.c main.h
	gcc -c crc64.c main.h

grow.o: grow.c main.h
	gcc -c grow.c main.h

toArray.o: toArray.c main.h
	gcc -c toArray.c main.h

comparator.o: comparator.c main.h
	gcc -c comparator.c main.h
 
printArray.o: printArray.c main.h
	gcc -c printArray.c main.h

clean:
	rm pairsofwords main.o init.o insert.o getWord.o find.o printTable.o crc64.o grow.o comparator.o toArray.o

