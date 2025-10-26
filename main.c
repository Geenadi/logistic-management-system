#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cityCount = 0;


void manageCities();


int main(){
    int choice;

    printf("=============================================\n");
    printf("         LOGISTICS MANAGEMENT SYSTEM         \n");
    printf("=============================================\n");
    
    do{
        printf("\n--------- MAIN MENU ---------n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. Delivery Request\n");
        printf("4. Performance Reports\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", choice);

        switch(choice){
            case 1: 
                manageCities();
                break;
            case 2:
                
                break;
            case 3:

                break;
            case 4: 

                break;
            case 5:
                printf("Exiting System.Thank you!");
                break;
            default:
                printf("Invalid choice! Please try again.\n");                
        }
    }while (choice != 5);
 
    return 0;

}

void manageCities(){
    int choice;
    do{

        printf("\n--------- City Management ---------\n");
        printf("1. Add a new city\n");
        printf("2. Rename a city\n");
        printf("3. Remove a city\n");
        printf("4. Display all cities\n");
        printf("5. Back to main menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
        
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
            return;
                break;
            default:
                printf("Invalid Input! Try again...");
        }
    } while(choice != 5);
}