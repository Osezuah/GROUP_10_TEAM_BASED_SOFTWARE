#pragma once

#define SPORT 11
#define MAX_ORG_NAME 30
#define MAX_EVENT_NAME 100
#define MAX_PLACE 50

typedef struct Date {
    int day;
    int month;
    int year;
}date;

typedef struct Time {
    int hour;
    int minute;
}TIME;

typedef struct Stadium
{
    int stadiumID;
    char category[SPORT];
    char place[MAX_PLACE];
    int capacity;
} stadium;

typedef struct Event {
    int eventID;
    char category[SPORT];
    char eventName[MAX_EVENT_NAME];
    char place[MAX_PLACE];
    TIME times;
    date dates;
    int tickets;
    double price;
    char organizer[MAX_ORG_NAME];
} event;

typedef struct EventNode {
    event data;
    struct EventNode* prev;
    struct EventNode* next;
} eventNode;

/*typedef struct StadiumNode {
    stadium data;
    struct StadiumNode* prev;
    struct StadiumNode* next;
} stadiumNode;
*/

void loadEvents(void);
void saveEvents(void);
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
