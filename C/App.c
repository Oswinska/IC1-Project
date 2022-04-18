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
    customer person_taking;
}car;

void rent_car(car car, customer client, int time) {
    client.debt += car.price_per_hour * time;
    car.person_taking = client;
}

void change_name(customer client) {
    printf("What's your new name?\n");
    char* newName;
    scanf("%s", &newName);

    memset(client.surname, 0, 15);
    memcpy(client.surname, newName, strlen(newName));
}

void change_surname(customer client) {
    printf("What's your new surname?\n");
    char* newSurname;
    scanf("%s", &newSurname);

    memset(client.surname, 0, 15);
    memcpy(client.surname, newSurname, strlen(newSurname));
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
        fscanf(file, "%s", &line);

    };
}

int menu()
{
    int command = 0;
    printf("Welcome to the Car Service! Write the digit: \n 1 - Rent a car. \n 2 - Change name.\n ");
    printf("3 - Change surname.\n 4 - Save changes.\n 5 - Exit the program.\n");
    while (command < 1 || command > 5)
    {
        command = 10;
        scanf("%d", &command);
        if (command >= 1 && command <= 5)
            return command;
        printf("You have written wrong digit. Please, write another one from the list.\n");
    }
}

int op_choose()
{

    customer* customers;

    customer cust1;
    char name = "John";
    cust1.name = "John";
    cust1.surname = "Wilkins";
    cust1.account_number = "1324552342123428534";
    unsigned short debt1 = 0;

    customers[0] = cust1;
    customers[1] = cust1;

    int command = menu();
    switch (command)
    {

    case 1:
    {

        printf("What car do you want to rent?\n");
        int val;
        scanf("%d", &val);
        break;

    }

    case 2:
    {

        printf("What value do you want to delete?\n");
        int val;
        scanf("%d", &val);
        break;

    }

    case 3:
    {

        printf("Printing the tree...\n\n");
        printf("\nTree was printed.\n\n");
        break;

    }

    case 4:
    {

        printf("Saving the tree...\n\n");
        FILE* output;
        output = fopen("out.txt", "w+");
        fclose(output);
        printf("\nTree successfully saved in file out.txt\n\n");
        break;

    }

    case 5:
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

