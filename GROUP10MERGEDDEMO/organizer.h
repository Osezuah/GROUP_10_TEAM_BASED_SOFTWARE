#pragma once
#include "files.h"

void disp_menu1(void);
void disp_menu2(void);
void mainMenu();
void AddNewEvent(event* newEvent);
//void loadStadiums(void);
//void loadEvents(void);
void printAllEventsOfThatOrganizer(char* organizerName);
void press_key(void);
int removeEvent(int eventID, char* organizerName);
int Update_an_event(int id, char* organizerName);
//void saveEvents(void);
//void saveStadiums(void);
//void sportselect(char* cat);
//void printAllStadiumsofThatSport(char* cat);