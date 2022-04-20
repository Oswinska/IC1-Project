#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* surname;
    char* account_number;
    unsigned int debt;
}customer;

typedef struct {
    char number[8];
    unsigned short price_per_hour;
    short status;
}car;

void rent_car(car* car, customer* client, int time) {
    printf("Debt now is: %d\n", client->debt);
    client->debt += car->price_per_hour * time;
    printf("Debt now is: %d\n", client->debt);
}


void change_number(car* automobile, char *newnum) {
    printf("Step1 succ!\n");
    memcpy(automobile->number, newnum, strlen(newnum));
    printf("Step2 succ!\n");
}

void save_file(car car, customer client) {
    FILE* save_file = fopen("backup.txt", "rw+");
}

int menu()
{
    int command = 0;
    printf("Welcome to the Car Service! Write the digit: \n 1 - Rent a car. \n 2 - Change car number.\n ");
    printf("3 - Save changes to the file.\n 4 - Exit the program.\n");
    while (command < 1 || command > 4)
    {
        command = 10;
        scanf("%d", &command);
        if (command >= 1 && command <= 4)
            return command;
        printf("You have written wrong digit. Please, write another one from the list.\n");
	exit(0);
    }
}

int op_choose()
{
    customer cust;
    cust.name = "John";
    cust.surname = "Wilkins";
    cust.account_number = "1324552342123428534";
    cust.debt = 64000;

    car cars;
    strcpy(cars.number, "AN9728U");
    cars.price_per_hour = 700;
    cars.status = 0;


    int command = menu();

    switch (command)
    {

    case 1:
    {

        printf("For how many hours do you want to rent?\n");
        int val;
        scanf("%d", &val);
        rent_car(&cars, &cust, val);
	printf("Debt is %d\n", cust.debt);
	break;

    }

    case 2:
    {
	printf("Number is: %s\n", cars.number);
	printf("Price is: %d\n", cars.price_per_hour);
	
	printf("Type new number. Only 8 symbols!\n");
        char *newnum;
        printf("Step0 succ!\n");
        scanf("%s", newnum);

        printf("Step1 succ!\n");
        memcpy(cars.number, &newnum, sizeof(newnum));
        printf("Step2 succ!\n");

        printf("Number is: %s\n", cars.number);
	printf("Price is: %d\n", cars.price_per_hour);
        break;
    }

    case 3:
    {

        printf("Saving the file...\n\n");
	FILE* save_file = fopen("backup.txt", "w");
	printf("File opened.");
	fprintf(save_file, "Customer: %s %s %s %d\n", cust.name, cust.surname, cust.account_number, cust.debt);
	printf("Customer written");
	fprintf(save_file, "Car: %s %d %d", cars.number, cars.price_per_hour, cars.status);
	printf("Car written");
	fclose(save_file);
	break;

    }

    case 4:
    {

        printf("Exiting...");
        exit(0);

    }
    }

    return command;

}


int main()
{
    int prog_end = 0;
    while (prog_end == 0)
    {
        op_choose();
    }
}
