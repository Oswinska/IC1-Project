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
    unsigned int price_per_hour;
    short status;
}car;

int menu()
{
    int command = 0;
    printf("Welcome to the Car Service! Write the digit: \n 1 - Rent a car. \n 2 - Change car number.\n ");
    printf("3 - Save changes to the file.\n 4 - Find backup file if lost.\n 5 - Exit the program.\n");
    while (command < 1 || command > 4)
    {
        command = 10;
        scanf("%d", &command);
        if (command >= 1 && command <= 5)
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
	printf("Debt now is: %d\n", cust.debt);
	cust.debt += cars.price_per_hour * val;
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
        scanf("%s", &newnum);

        printf("Step1 succ!\n");
        memcpy(cars.number, &newnum, sizeof(newnum));
        printf("Step2 succ!\n");

        printf("Number is: %s\n", cars.number);
	printf("Price is: %d\n", cars.price_per_hour);
        break;
    }

    case 3:
    {

	getchar();

	char *path = (char*) malloc(255);
	printf("Write the path where you want to save your file:\n");
        scanf("%s[^\n]", path);
        printf("Path achieved! It is: %s\n", path);
	
	char data[255] = { };
        snprintf(data, sizeof(data), "%s %s %s %hu \n%s %hu %hi", cust.name, cust.surname, cust.account_number, cust.debt, cars.number, cars.price_per_hour, cars.status);

	getchar();
	char prefix[255];
        printf("Please, write description about backup.");
	scanf("%[^\n]s", prefix);
        printf("Description achieved! It is: %s\n", prefix);
	char prefix_save[sizeof(path)+sizeof(prefix)+8];
	snprintf(prefix_save, 272, "echo %s > %s", prefix, path);
	system(prefix_save);

        printf ("%s\n\n", data);
        printf("Saving the file...\n\n");
        char to_save[sizeof(path)+sizeof(data)+17];
        snprintf(to_save, 272, "echo \"%s\" >> %s", data, path);
        printf("to_save var created! It looks like: %s\n", to_save);
        system(to_save);
        printf("File saved successfully\n");
       
	break;

    }

    case 4:
    {
    	printf("Input path you are searching file in: \n");
	getchar();
        char path[255];
        scanf("%[^\n]s", path);
        printf("Path achieved! It is: %s\n", path);
	char to_save[sizeof(path)+17];
        snprintf(to_save, sizeof(to_save), "sudo find %s", path);
	system(to_save);
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
