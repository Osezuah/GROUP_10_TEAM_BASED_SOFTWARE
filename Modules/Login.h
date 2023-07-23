#pragma once
#define USERNAME_SIZE 50
#define NUM_SIZE 10
#define PASSWORD_SIZE 10
#define ORGANIZER_SIZE 150
#define ID_SIZE 40
#define SPORT_SIZE 50
typedef struct Login
{
	int option;
}LOGIN;

void WelcomeMessage();
void DisplayLoginOptions();
int InputStream();

int NextLoginOptions();
void LoginCredentials();




