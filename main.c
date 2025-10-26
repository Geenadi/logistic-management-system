#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_NAME_LEN 30

int cityCount = 0;

char cities[MAX_CITIES][MAX_NAME_LEN];

void manageCities();
void addCity();
void renameCity();
void displayCities();


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

void addCity(){
    char newCity[MAX_NAME_LEN];
    int cityExists = 0;

    if(cityCount >= MAX_CITIES){
        printf("Unable to add.Maximum city limit has reached.");
        return;
    } 

    getchar();
    printf("Enter a city name: ");
    scanf("%[^\n]", newCity); 

    for(int i = 0; i < cityCount; i++){
        if(strcasecmp(cities[i], newCity) == 0) {
            cityExists = 1;
            break;
        }
    }

    if(cityExists){
        printf("City already exists.\n");
        return;
    } else {
        strcpy(cities[cityCount], newCity);
        cityCount++;
        printf("'%s' successfully added.\n", newCity);
    }
}

void displayCities(){

        if(cityCount == 0){
        printf("No cities available\n");
        return;
    }

    printf("\n-------------------------------");
    printf("\n          City List            ");
    printf("\n-------------------------------\n");

    for(int i = 0; i < cityCount; i++){
        printf("%d. %s\n", i+1, cities[i]);
    }
}

void renameCity(){
    int cityIndex;
    int isDuplicated = 0;

    if(cityCount == 0){
        printf("No cities has enterd to rename.\n");
        return;
    }

    displayCities();

    printf("Enter the number of a city to rename: ");
    scanf("%d", &cityIndex);
    getchar();

    if(cityIndex < 1 || cityIndex > cityCount){
        printf("Invalid Input. Please enter a valid city number!\n");
        return;
    }

    cityIndex--;

    char newName[MAX_NAME_LEN];

    printf("Enter a new name: ");
    scanf("%s", newName);

    for(int i = 0; i < cityCount; i++){
        if(strcasecmp(cities[i], newName) == 0) {
            isDuplicated = 1;
            break;
        }
    }

    if(isDuplicated){
        printf("City name already exists. Please try a different name...\n");
        return;
    }

    strcpy(cities[cityIndex], newName);
    printf("City successfully renamed.\n");

    displayCities();
}



