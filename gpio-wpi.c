#include <stdio.h>
#include <wiringPi.h>
#include <string.h>
#include <stdlib.h>

void setGpio(char* pin, char* etat)
{
	int gpio = atoi(pin);

	wiringPiSetupGpio();
	if(gpio >= 2 && gpio <=27)
	{
		if(strcmp(etat,"on") == 0)
		{
			pinMode(gpio,OUTPUT);
			digitalWrite(gpio,HIGH);
			printf("on\n");
		}
		else if(strcmp(etat,"off") == 0)
		{
			pinMode(gpio,OUTPUT);
			digitalWrite(gpio,LOW);
			printf("off\n");
		}
		else
		{
		printf("Etat non valide\n");
		}
	}
	else
	{
		printf("GPIO non valide\n");
	}
}
