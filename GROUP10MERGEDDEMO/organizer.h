//Group 10 - Ansh - Adam - Ehinomhen - Team Based Software Development  - s23 
#pragma once
#include "files.h"

void disp_menu1(void);
void disp_menu2(void);
void mainMenu(const unsigned char*);
void AddNewEvent(event* newEvent, const unsigned char* organizerName);
void printAllEventsOfThatOrganizer(const unsigned char*);
void press_key(void);
int removeEvent(int, const unsigned char*);
void Update_an_event(int, const unsigned char*);
