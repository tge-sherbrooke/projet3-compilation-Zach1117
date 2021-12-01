CC=gcc

wpi: gpio-wpi.c
	$(CC) main.c gpio-wpi.c -o rpi-gpio -lwiringPi 


libc: gpio-libc.c
	$(CC) main.c gpio-libc.c -o rpi-gpio 
