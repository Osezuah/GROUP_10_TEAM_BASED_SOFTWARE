//Group 10 - Ansh - Adam - Ehinomhen - Team Based Software Development  - s23 
#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include "files.h"

//globally declared event node so that all files can use them.....
eventNode* first_event = NULL; 
eventNode* last_event = NULL;

int main(int argc, char* argv) //command line argument..
{
	printf("Press any key to load\n ");
	getch();
	if (argc != NULL)
	{
		WelcomeMessage();
		DisplayLoginOptions();
		printf("Enter an option: ");
		LoginCredentials();
	}
	else
	{
		return;
	}
	
		
	

	return 0;
}