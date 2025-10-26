#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_NAME_LEN 30
#define INFINITY_VALUE 999999
#define FUEL_PRICE 310.0

int cityCount = 0;
int minDist = 0;
int pathLen = 0;

char cities[MAX_CITIES][MAX_NAME_LEN];
int distances[MAX_CITIES][MAX_CITIES];
int path[MAX_CITIES];


char vehicleNames[3][30] = {"Van", "Truck", "Lorry"};
int vehicleCapacity[3] = {1000, 5000, 10000};
float vehicleRate[3] = {30.0, 40.0, 80.0};
float vehicleSpeed[3] = {60.0, 50.0, 45.0};
float vehicleFuelEfficiency[3] = {12.0, 6.0, 4.0};

void manageCities();
void addCity();
void renameCity();
void removeCity();
void displayCities();
void manageDistance();
void editDistance();
void displayDistanceTable();
void displayVehicles();
void handleDeliveryRequest();
void findShortPath(int souc, int dest);
void calcDeliveryCost(int souc, int dest, int weight, int vehicleType);



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
        scanf("%d", &choice);

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
        printf("\n--------- Distance Management ---------\n");
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

    if (city1 < 1 || city1 > cityCount || city2 < 1 || city2 > cityCount){
        printf("Invalid city numbers.\n");
        return;
    }

    if (city1 == city2){
        printf("Cannot set distance from city to itself.\n");
        return;
    }

    city1--;
    city2--;

    printf("Please enter the distance between the selected cities in km: ");
    scanf("%d", &distance);

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

void displayVehicles(){
    printf("\n--------- Available Vehicles ---------n");

    for (int i = 0; i < 3; i++){
        printf(" %d. %-10s - Capacity: %5d kg, Rate: %.0f LKR/km\n", i + 1, vehicleNames[i], vehicleCapacity[i], vehicleRate[i]);
    }
}

void handleDeliveryRequest(){
    int souc, dest, weight, vehicleType;

    if (cityCount < 2){
        printf("Need at least two cities to deliver.\n");
        return;
    }

    displayCities();

    printf("Enter source city number: ");
    scanf("%d", &souc);
    printf("Enter destination city number: ");
    scanf("%d", &dest);

    if(souc == dest){
        printf("Source and the Destination cities can't be the same.\n");
    }

    souc--;
    dest--;

    printf("Enter weight in kg: ");
    scanf("%d", &weight);

    if(weight < 1 ){
        printf("Invalid Input. Wieight can't be a negative value.\n");
        return;
    }

    void displayVehicle();

    printf("Enter a number to select a vehicle: ");
    scanf("%d", &vehicleType);

     if (vehicleType < 1 || vehicleType > 3){
        printf("Invalid vehicle number. Enter again");
        return;
    }

    vehicleType--;

    if (weight > vehicleCapacity[vehicleType]){
        printf("Weight exceeds vehicle capacity!\n");
        printf("Maximum capacity for %s: %d kg\n", vehicleNames[vehicleType], vehicleCapacity[vehicleType]);
        return;
    }

    calcDeliveryCost(souc, dest, weight, vehicleType);
}    

void findShortPath(int souc, int dest){
    if(distances[souc][dest] > 0){
        minDist = distances[souc][dest];
        path[0] = souc;
        path[1] = dest;
        pathLen = 2;
    }else{
        minDist = INFINITY_VALUE;
        pathLen = 0;
    }

    for(int intermediate = 0; intermediate < cityCount; intermediate++){
        if(intermediate == souc || intermediate == dest){
            continue;
        }

        if(distances[souc][intermediate] > 0 && distances[intermediate][dest] > 0){
            int totalDist = distances[souc][intermediate] + distances[intermediate][dest];
            if (totalDist < minDist){
                minDist = totalDist;
                path[0] = souc;
                path[1] = intermediate;
                path[2] = dest;
                pathLen = 3;
            }
        }
    }

    for (int i = 0; i < cityCount; i++){
        if (i == souc || i == dest){
            continue;
        }
        for (int j = 0; j < cityCount; j++){
            if (j == souc || j == dest || j == i){
                continue;
            }

            if (distances[souc][i] > 0 && distances[i][j] > 0 && distances[j][dest] > 0){
                int totalDist = distances[souc][i] + distances[i][j] + distances[j][dest];
                if (totalDist < minDist){
                    minDist = totalDist;
                    path[0] = souc;
                    path[1] = i;
                    path[2] = j;
                    path[3] = dest;
                    pathLen = 4;
                }
            }
        }
    }
}

void calcDeliveryCost(int souc, int dest, int weight, int vehicleType){

    findShortPath(souc, dest);

    if (minDist == 0 || minDist == INFINITY_VALUE){
        printf("No route available between selected cities!\n");
        return;
    }

    float distance = (float)minDist;
    float rate = vehicleRate[vehicleType];
    float speed = vehicleSpeed[vehicleType];
    float efficiency = vehicleFuelEfficiency[vehicleType];

    float deliveryCost = distance * rate * (1.0 + (weight / 10000.0));
    float fuelUsed = distance / efficiency;
    float fuelCost = fuelUsed * FUEL_PRICE;
    float totalCost = deliveryCost + fuelCost;
    float profit = deliveryCost * 0.25;
    float customerCharge = totalCost + profit;
    float time = distance / speed;

    // displayDeliveryEstimate(souc, dest, weight, vehicleType, distance, deliveryCost, fuelUsed, fuelCost, totalCost, profit, customerCharge, time);

    // saveDeliveryRecord(souc, dest, weight, vehicleType, distance, deliveryCost, time, customerCharge, profit);
}
