#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include "user.h"


int main()
{
	loadEvents();
	mainMenu();
	return 0;
}