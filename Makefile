CC=gcc -Wall

all::	argadder inputadder inputadder2 cp cat head wc

argadder:	argadder.c
	$(CC) -o argadder argadder.c

inputadder:	inputadder.c
	$(CC) -o inputadder inputadder.c

inputadder2:	inputadder2.c
	$(CC) -o inputadder2 inputadder2.c

cp:	cp.c
	$(CC) -o cp cp.c

cat:	cat.c
	$(CC) -o cat cat.c

head:	head.c
	$(CC) -o head head.c

wc:	wc.c
	$(CC) -o wc wc.c

clean::
	/bin/rm argadder inputadder inputadder2 cp cat head wc
