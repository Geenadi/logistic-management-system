#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_NAME_LEN 30

int cityCount = 0;

char cities[MAX_CITIES][MAX_NAME_LEN];
int distances[MAX_CITIES][MAX_CITIES];

void manageCities();
void addCity();
void renameCity();
void removeCity();
void displayCities();
void manageDistance();
void editDistance();
void displayDistanceTable();


int main(){
    int choice;

    printf("=============================================\n");
    printf("         LOGISTICS MANAGEMENT SYSTEM         \n");
    printf("=============================================\n");
    
    do{
        printf("\n--------- MAIN MENU ---------\n");
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
                manageDistance();
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

        printf("\n--------- City Management --------\n");
        printf("1. Add a new city\n");
        printf("2. Rename a city\n");
        printf("3. Remove a city\n");
        printf("4. Display all cities\n");
        printf("5. Back to main menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
                addCity();
                break;
            case 2:
                renameCity();
                break;
            case 3:
                removeCity();
                break;
            case 4:
                displayCities();
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

void removeCity(){

int cityIndex;

    if(cityCount == 0){
        printf("No cities have entered to remove.\n");
        return;
    }

    displayCities();

    printf("Enter a city number to remove: ");
    scanf("%d", &cityIndex);

    if(cityIndex < 1 || cityIndex > cityCount){
        printf("Invalid city number. Enter a valid city number to remove.\n");
        return;
    }

    cityIndex--;

        for (int i = cityIndex; i < cityCount - 1; i++) {
        strcpy(cities[i], cities[i + 1]);
    }

    for (int i = cityIndex; i < cityCount - 1; i++) {
        for (int j = 0; j < cityCount; j++) {
            distances[i][j] = distances[i + 1][j];
        }
    }

    for (int i = 0; i < cityCount - 1; i++) {
        for (int j = cityIndex; j < cityCount - 1; j++) {
            distances[i][j] = distances[i][j + 1];
        }
    }

    cityCount--;

    printf("City successfully deleted.\n");
}

void manageDistance(){
    int choice;
    do{
        printf("\n--------- Distance Management ---------n");
        printf("1. Input/Edit distance\n");
        printf("2. Display Distance table\n");
        printf("3. Back to main menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);  

        switch(choice){
            case 1:
                editDistance();
                break;
            case 2:

                break;
            case 3:
                return;
            default:
                printf("Invalid choice.Try again!\n");            
        }
    } while(choice != 3);
}

void editDistance(){
    int city1, city2, distance;

    if(cityCount < 2){
        printf("Need at least two citis to add or edit the distance.");
        return;
    }

    displayCities();

    printf("Enter first city number: ");
    scanf("%d", &city1);
    printf("Enter second city number: ");
    scanf("%d", &city2);

    if (city1 < 1 || city1 > cityCount || city2 < 1 || city2 > cityCount)
    {
        printf("Invalid city numbers.\n");
        return;
    }

    if (city1 == city2)
    {
        printf("Cannot set distance from city to itself.\n");
        return;
    }

    city1--;
    city2--;

    printf("Please enter the distance between the selected cities in km: ");
    scanf("%d", distance);

    if (distance < 0)
    {
        printf("Invalid distance.\n");
        return;
    }

    distances[city1][city2] = distance;
    distances[city2][city1] = distance;

    printf("Distance set successfully.\n");


}

void displayDistanceTable(){
    if (cityCount == 0){
        printf("No cities available to display distances.\n");
        return;
    }

    printf("\n---------------------------------------\n");
    printf("          Distances between two cities     \n");
    printf("\n---------------------------------------\n");

    printf("\n%-15s", " ");

    for (int i = 0; i < cityCount; i++){
        printf("%-15s", cities[i]);
    }

    printf("\n");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < cityCount; i++) {
        printf("%-15s", cities[i]);
        for (int j = 0; j < cityCount; j++) {
            printf("%-15s", (i != j && distances[i][j] == 0) ? "-" : (char[16]){0});
            if (!(i != j && distances[i][j] == 0))
                printf("%-15d", distances[i][j]);
        }
        printf("\n");
    }

}