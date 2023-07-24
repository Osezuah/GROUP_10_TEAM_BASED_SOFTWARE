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

void loadEvents(void);
void mainMenu();
void printBasketball(void);
void printBaseball(void);
void printFootball(void);
void printHockey(void);
void disp_menu2(void);
int bookforFootball(int ID);
int bookforBasketball(int ID);
int bookforBaseball(int ID);
int bookforHockey(int ID);
void saveEvents(void);