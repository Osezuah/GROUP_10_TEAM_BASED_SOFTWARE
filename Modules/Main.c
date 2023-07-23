#include "Login.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	WelcomeMessage();
	DisplayLoginOptions();
	printf("Enter an option: ");
	LoginCredentials();
	
	return 0;
}