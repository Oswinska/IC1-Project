#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* surname;
    char* account_number;
    unsigned short debt;
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


void change_number(car* automobile) {
    printf("Type new number. Only 8 symbols!\n");
    char *newNumber;
    printf("Step0 succ!\n");
    scanf("%s", newNumber);
    printf("Step1 succ\n");
    strcpy(automobile->number, newNumber);
    printf("Step2 succ\n");
}

void save_file(car car, customer client) {
    FILE* save_file = fopen("backup.txt", "rw+");
}

void open_file() {
    FILE* file;
    char* line;

    if ((file = fopen("backup.txt", "r+")) == NULL) {
        printf("cannot open file.\\n");
        exit(1);
    };
    for (int i = 0; i < 3; i++) {
        fscanf(file, "%s", line);

    };
}

int menu()
{
    int command = 0;
    printf("Welcome to the Car Service! Write the digit: \n 1 - Rent a car. \n 2 - Change name.\n ");
    printf("3 - Change surname.\n 4 - Save changes.\n 5 - Exit the program.\n");
    while (command < 1 || command > 4)
    {
        command = 10;
        scanf("%d", &command);
        if (command >= 1 && command <= 4)
            return command;
        printf("You have written wrong digit. Please, write another one from the list.\n");
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
    char *newName = "AN9728U";
    memcpy(cars.number, newName, strlen(newName));
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
        change_number(&cars);
        printf("Number is: %s\n", cars.number);
        break;
    }

    case 3:
    {

        printf("Saving the file...\n\n");
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
