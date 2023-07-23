#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "baseball.h"

#define LIMIT 40
#define MAX_SEATS 100


struct baseballGame
{
    char stadium[LIMIT];
    char tournament[LIMIT];
    char date[LIMIT];
    char time[LIMIT];
    int availableTickets;
    float ticketPrice;
};

//The software shall incorporate a random number generator..we included this..this function would randomly generate seat number to the user.
int randomseat_baseball(int availableSeats)
{
    srand(time(NULL));
    return rand() % availableSeats + 1;
}

//this functionality is to check as of now in the individual part. Mainly this inventory would be by the organizer..
void writeBaseballInventory()
{
    struct baseballGame games[] = {
        {"Stadium X", "Championship Z", "July 30, 2023", "18:30", 120, 25.0},
        {"Stadium Y", "Cup W", "August 15, 2023", "19:00", 100, 20.0},
        {"Stadium Z", "Tournament Q", "September 1, 2023", "20:30", 150, 30.0}
    };

    FILE* fptr;
    fptr = fopen("INVENTORYbaseball.txt", "a");

    if (fptr == NULL)
    {
        printf("Failed to open file for writing!\n");
        return;
    }

    for (int i = 0; i < sizeof(games) / sizeof(struct baseballGame); i++)
    {
        fwrite(&games[i], sizeof(struct baseballGame), 1, fptr);
    }

    fclose(fptr);

    printf("Baseball inventory data written to the file successfully!\n");
}

void displayBaseballInventory()
{
    FILE* fptr;
    fptr = fopen("INVENTORYbaseball.txt", "r");

    if (fptr == NULL)
    {
        printf("Failed to open file!\n");
        return;
    }

    struct baseballGame game;
    int gameCount = 0;

    printf("Baseball Inventory:\n");
    printf("-------------------\n");

    while (fread(&game, sizeof(struct baseballGame), 1, fptr))
    {
        printf("Game %d:\n", gameCount + 1);
        printf("Stadium: %s\n", game.stadium);
        printf("Tournament: %s\n", game.tournament);
        printf("Date: %s\n", game.date);
        printf("Time: %s\n", game.time);
        printf("Available Tickets: %d\n", game.availableTickets);
        printf("Ticket Price: %.2f\n", game.ticketPrice);
        printf("\n");
        gameCount++;
    }

    fclose(fptr);
}

void bookBaseballGame()
{
    FILE* fptr;
    fptr = fopen("INVENTORYbaseball.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    struct baseballGame game;
    int gameCount = 0;

    printf("Select a game to book tickets:\n");

    while (fread(&game, sizeof(struct baseballGame), 1, fptr))
    {
        printf("Game %d:\n", gameCount + 1);
        printf("Stadium: %s\n", game.stadium);
        printf("Tournament: %s\n", game.tournament);
        printf("Date: %s\n", game.date);
        printf("Time: %s\n", game.time);
        printf("Available Tickets: %d\n", game.availableTickets);
        printf("Ticket Price: %.2f\n", game.ticketPrice);
        printf("\n");
        gameCount++;
    }

    fclose(fptr);

    // Prompting the user to choose a game tournament
    int gameChoice;
    printf("Enter the game number to book tickets (1-%d): ", gameCount);
    scanf_s("%d", &gameChoice);

    // Input validation to check if any such game exists or not
    if (gameChoice < 1 || gameChoice > gameCount)
    {
        printf("Invalid game selection!\n");
        return;
    }

    // Open the inventory file in read-write mode
    fptr = fopen("INVENTORYbaseball.txt", "r+");

    if (fptr == NULL)
    {
        printf("Failed to open file for booking!\n");
        return;
    }

    // Move the file pointer to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct baseballGame), SEEK_SET);

    // Read the selected game
    fread(&game, sizeof(struct baseballGame), 1, fptr);

    // Check if there are available tickets for the selected game
    if (game.availableTickets <= 0)
    {
        printf("No available tickets for the selected game!\n");
        fclose(fptr);
        return;
    }

    // Decrement the available tickets count by 1
    game.availableTickets--;

    // Move the file pointer back to the selected game
    fseek(fptr, (gameChoice - 1) * sizeof(struct baseballGame), SEEK_SET);

    // Write the updated game back to the file
    fwrite(&game, sizeof(struct baseballGame), 1, fptr);

    fclose(fptr);

    // Assign a random seat to the user
    int seatNumber = randomseat_baseball(MAX_SEATS);
    printf("Seat number %d booked for the game!\n", seatNumber);
}

void baseball()
{
    printf("Baseball selected!\n");
    displayBaseballInventory();
    bookBaseballGame();
}
