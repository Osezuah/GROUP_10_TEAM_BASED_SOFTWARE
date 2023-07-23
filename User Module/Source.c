#include <stdio.h>
#include "basketball.h"
#include "football.h"
#include "baseball.h"
#include "hockey.h"

int main()
{
    printf("WELCOME! USER MODULE\n");

    //Inventory for each sport...All this would be done by Ehi in her module.
    writeBasketballInventory();
    writeFootballInventory();
    writeBaseballInventory();
    writeHockeyInventory();

    //sport selection options..
    printf("Sport Selection\n");
    printf("1 - Basketball\n");
    printf("2 - Football\n");
    printf("3 - Baseball\n");
    printf("4 - Hockey\n");
    printf("0 - Exit\n");  //clean exit

    //choice of sport selection..
    int choice;
    printf("Enter your choice: ");
    scanf_s("%d", &choice);

    //switch case..
    switch (choice)
    {
    case 0:
        printf("Exiting program...\n");
        return 0;
    case 1:
       basketball();
        break;
    case 2:
       football();
        break;
    case 3:
       baseball();
        break;
    case 4:
      hockey();
        break;
    default:
        printf("Invalid selection!\n");
        break;
    }
   
}
