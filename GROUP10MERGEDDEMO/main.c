#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include "files.h"

eventNode* first_event = NULL;
eventNode* last_event = NULL;

int main(void)
{
	WelcomeMessage();
	DisplayLoginOptions();
	printf("Enter an option: ");
	LoginCredentials();

	return 0;
}