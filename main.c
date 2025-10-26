#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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