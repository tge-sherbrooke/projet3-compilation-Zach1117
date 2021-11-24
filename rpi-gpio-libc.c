
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
	int gpio = atoi(argv[1]);
	
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
	    
	    	
	    	if(strcmp(argv[2], "on") == 0)
	    	{
	    		printf("on");
	    		fd = fopen(buf, "w");
			fprintf(fd, "1");
			fclose(fd);
	    	}
	    	else if(strcmp(argv[2], "off") == 0)
	    	{
	    		printf("off");
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
    	return 0;
}

