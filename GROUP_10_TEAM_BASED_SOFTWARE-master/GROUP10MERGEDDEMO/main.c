#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include "files.h"

eventNode* first_event = NULL;
eventNode* last_event = NULL;

int main(int argc, char* argv)
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