#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setGpio(char* pin, char* etat) 
{
	int gpio = atoi(pin);
	
	if(gpio >= 1 && gpio <= 27)
	{

		char buf[100];
		  
		  
		 FILE* fd = fopen("/sys/class/gpio/export", "w");
		fprintf(fd, "%d", gpio);
		fclose(fd);

		sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
		fd = fopen(buf, "w");
		fprintf(fd, "out");
		fclose(fd);
		
		sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
	    	fd = fopen(buf, "w");
	    
	    	
	    	if(strcmp(etat, "on") == 0)
	    	{
	    		printf("on\n");
	    		fd = fopen(buf, "w");
			fprintf(fd, "1");
			fclose(fd);
	    	}
	    	else if(strcmp(etat, "off") == 0)
	    	{
	    		printf("off\n");
	    		fd = fopen(buf, "w");
			fprintf(fd, "0");
			fclose(fd);
	    	}
	    	else
	    	{
	    		printf("Etat non valide\n");
	    	}
	    }
	    else
	    {
	    	printf("GPIO non valide");
	    }
}

