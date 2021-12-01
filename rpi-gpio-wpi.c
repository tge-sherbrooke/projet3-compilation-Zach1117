#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int pin = atoi(argv[1]);

	wiringPiSetupGpio();
	if(pin >= 2 && pin <=27)
	{
		if(strcmp(argv[2],"on") == 0)
		{
			pinMode(pin,OUTPUT);
			digitalWrite(pin,HIGH);
			printf("on\n");
		}
		else if(strcmp(argv[2],"off") == 0)
		{
			pinMode(pin,OUTPUT);
			digitalWrite(pin,LOW);
			printf("off\n");
		}
		else
		{
		printf("argument non valide\n");
		}
	}
	else
	{
		printf("argument non valide\n");
	}

	return 0;
}
