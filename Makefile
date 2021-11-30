CC=gcc

wpi: gpio-wpi.c
	$(CC) main.c gpio-wpi.c -o main -lwiringPi 


libc: gpio-libc.c
	$(CC) main.c gpio-libc.c -o main 
