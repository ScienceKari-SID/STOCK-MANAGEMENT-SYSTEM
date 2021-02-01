#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
int login(char uname[25], char pass[8])
{
    if (!strcmp(uname, "imManager") && !strcmp(pass, "grow123"))
    {
        return 1;
    }
    else
        return 0;
}
struct item
{
    char name[40];
    int quantity;
    float price;
};
struct item s;
char itemname[40]; 
long int recsize; 
int department() {
    int d;
    printf("\n\nHello Mr.Manager, Welcome to HOMESCREEN\n\nSo,details of which department do you want to access ?\n\n:>Press 1 for ELECTRONICS\n:>Press 2 for STATIONARY\n:>Press 3 for SPORTS_SECTION");
    printf("\n\n Please enter your choice :- ");
    scanf("%d", &d);
    return d;
}
int main()
{
    FILE* fp, * ft;
    int i = 0, r = 0, count = 0;
    char uname[25], pass[8], ch, another, choice;
logout:
    fflush(stdin);
    count = 0;
    printf("\t\t\t\t\t\t\t\t00000000    0000    0000    00000000\n\t\t\t\t\t\t\t\t00          00 00  00 00    00 \n\t\t\t\t\t\t\t\t00          00   00   00    00 \n\t\t\t\t\t\t\t\t00000000    00        00    00000000\n\t\t\t\t\t\t\t\t      00    00        00          00\n\t\t\t\t\t\t\t\t      00    00        00          00\n\t\t\t\t\t\t\t\t00000000(*) 00        00(*) 00000000\n\t\t\t\t\t\t\t\t|__________________________________|\n\t\t\t\t\t\t\t\t|**********************************|\n\n\n");
    printf("\t\t\t\t\t\t\t   **********************************************\n\t\t\t\t\t\t\t   *WELCOME TO STORE'S STOCK MANAGEMENT SYSTEM*\n\t\t\t\t\t\t\t   **********************************************");
    printf("\n\n\n\nTO ACCESS SYSTEM, PLEASE DO LOGIN :)\n\n\n");
    do {
        printf("\t\t\t\t\t\t\t          Enter USERNAME :-\t");
        scanf("%*[\n]");
        fgets(uname, 10, stdin);
        uname[10] = '\0';
        printf("\n\t\t\t\t\t\t\t          Enter PASSWORD :-\t");
        for (i = 0;i < 7;i++)
        {
            pass[i] = _getch();
            printf("*");
        }
        pass[i] = '\0';
        r = login(uname, pass);
        count++;
        if (r) {
            printf("\n\n***************************************************************************| ACCESS GRANTED |*******************************************************************************\n////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n\n\n");
            break;
        }
        else
            printf("\n\n\t\t\t\t\t\tWRONG USERNAME/PASSWORD----------------ACCESS DENIED, TRY AGAIN :<\n\n\n\n");
    } while (count != 3);
    if (count == 3)
    {
        printf("\n\n/////ALL LOGIN ATTEMPTS FAILED.....PLEASE RESTART THE PROGRAM/////");
        _getch();
        return 0;
    }
    /// we have rb+ and wb+ mode in this code, to read/write in binary form.
switch (department()){
    struct item i;
 
        system("cls");
    case 1:
        fp = fopen("Elec.txt", "rb+");/// we have rb+ and wb+ mode in this code, to read/write in binary form.
        if (fp == NULL)
        {
            fp = fopen("Elec.txt", "wb+");
            if (fp == NULL)
            {
                printf("Connot open file");
                exit(1);
            }
        }
        recsize = sizeof(i);  /// sizeo of each record = size of structure variable i
        while (1)
        {
            system("cls"); ///clear the console window
            printf("\t\t\t\t\t\t\t   **********************************************\n\t\t\t\t\t\t\t*WELCOME TO STORE ELECTRONIC DEPARTMENT'S DATABASE*\n\t\t\t\t\t\t\t   **********************************************\n\n");
            printf("1. Add new electronic item to database\n"); /// option for appending new record

            printf("2. Show all electronic items available\n"); /// option for showing existing record

            printf("3. Modify Records\n"); /// option for editing record

            printf("4. Delete Records\n"); /// option for deleting record

            printf("5. Go to main menu :\n"); /// exit from the program

            printf("Your Choice : "); /// enter the choice 1, 2, 3, 4, 5
            fflush(stdin); /// flush the input buffer
            choice = _getch(); 
            switch (choice)
            {

            case '1':
                /// when user press 1
                system("cls");
                fseek(fp, 0, SEEK_END); /// search the file and move cursor to end of the file
                /// here 0 is indicating 0 distance from the EOF
                another = 'y';
                while (another == 'y')  ///user want to add another record
                {
                    printf("____________________________________________________\n");
                    printf("////////////////////////////////////////////////////");
                    printf("\n\n)-> Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n)-> %s is available in quantity :- ", i.name);
                    scanf("%d", &i.quantity);
                    printf("\n\n)-> Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp); /// write new record in the file
                    printf("\n____________________________________________________\n");
                    printf("////////////////////////////////////////////////////");
                    printf("\n\n**Add another record ??---(y/n)** ");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '2':
                system("cls");
                rewind(fp); ///to move file cursor to starting of the file
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\tQUANTITY\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t************************************\n");
                while (fread(&i, recsize, 1, fp) == 1)  /// read the file and fetch the record one record per fetch
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.quantity, i.price);
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t////////////////////////////////////////\n");
                _getch();
                break;

            case '3':  /// edit existing record
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf(")->Enter itemm's name, which is to be modified :- ");
                    scanf("%s", itemname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)  /// fetch all record from file
                    {
                        if (strcmp(i.name, itemname) == 0)  ///if entered name matches with that in file
                        {
                            printf("\n)->Enter new name,quantity and price :-\n");
                            scanf("%s%d%f", i.name, &i.quantity, &i.price);
                            fseek(fp, -recsize, SEEK_CUR); /// to move cursor 1 step back from current position
                            fwrite(&i, recsize, 1, fp); /// override the record
                            break;
                        }
                    }
                    printf("\n**Modify another record??...(y/n)**");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\nEnter name of item to be deleted : ");
                    scanf("%s", itemname);
                    ft = fopen("Temp.txt", "wb");  /// create a intermediate file for temporary storage
                    rewind(fp); /// move record to starting of file
                    while (fread(&i, recsize, 1, fp) == 1)  /// read all records from file
                    {
                        if (strcmp(i.name, itemname) != 0)  /// if the entered record match
                        {
                            fwrite(&i, recsize, 1, ft); /// move all records except the one that is to be deleted to temp file
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Elec.txt"); /// remove the orginal file
                    rename("Temp.txt", "Elec.txt"); /// rename the temp file to original file name
                    fp = fopen("Elec.txt", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '5':
                fclose(fp);  /// close the file
                system("cls");
                goto logout;
            }
        }
        /*
        * 
        * 
        * 
                -----------------------------------------HERE ONWARDS ALL LOGICS ARE REPEATED-------------------------
        *  
        * 
        * 
        *  */
    case 2:
        fp = fopen("BOOK.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("BOOK.txt", "wb+");
            if (fp == NULL)
            {
                printf("Connot open file");
                exit(1);
            }
        }

        /// sizeo of each record = size of structure variable i
        recsize = sizeof(i);
        /// infinite loop continues untile the break statement encounter
        while (1)
        {
            system("cls"); ///clear the console window
            printf("\t\t\t\t\t\t\t   **********************************************\n\t\t\t\t\t\t\t*WELCOME TO STORE'S STATIONARY DEPARTMENT'S DATABASE*\n\t\t\t\t\t\t\t   **********************************************\n\n");
            printf("1. Add new stationary item to Stock\n"); /// option for adding record

            printf("2. Show all available items\n"); /// option for showing existing record

            printf("3. Modify Records\n"); /// option for editing record

            printf("4. Delete items\n"); /// option for deleting record

            printf("5. Exit\n\n"); /// exit from the program

            printf(")>Your Choice : "); /// enter the choice 1, 2, 3, 4, 5
            fflush(stdin); /// flush the input buffer
            choice = _getch(); /// get the input from keyboard
            switch (choice)
            {
            case '1':  /// if user press 1
                system("cls");
                fseek(fp, 0, SEEK_END); /// search the file and move cursor to EOF
                /// here 0 indicates moving 0 distance from the end of the file
                another = 'y';
                while (another == 'y')  /// if user want to add another record
                {
                    printf("\n____________________________________________________\n");
                    printf("////////////////////////////////////////////////////");
                    printf("\n\n)>Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n  %s is available in quantity :- ", i.name);
                    scanf("%d", &i.quantity);
                    printf("\n\n)>Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp); /// write the record in the file
                    printf("\n____________________________________________________\n");
                    printf("////////////////////////////////////////////////////");
                    printf("\n\n**Add another record?....(y/n)**");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '2':
                system("cls");
                rewind(fp); ///this moves file cursor to start of the file
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\t     QUANTITY\t\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t********************************************\n");
                while (fread(&i, recsize, 1, fp) == 1)  /// read the file and fetch the record one record per fetch
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.quantity, i.price); 
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t//////////////////////////////////////////////\n");
                _getch();
                break;
            case '3':  /// if user press 3 then do editing existing record
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf(")->Enter item's name, which is to be modified :- ");
                    scanf("%s", itemname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)  /// fetch all record from file
                    {
                        if (strcmp(i.name, itemname) == 0)  ///if entered name matches with that in file
                        {
                            printf("\n)->Enter new name,quantity and price :- \n");
                            scanf("%s%d%f", i.name, &i.quantity, &i.price);
                            fseek(fp, -recsize, SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&i, recsize, 1, fp); /// overwrite the record
                            break;
                        }
                    }
                    printf("\n**Modify another record?...(y/n)**");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\n)->Enter name of book to be deleted: ");
                    scanf("%s", itemname);
                    ft = fopen("Temp.txt", "wb");  /// create a intermediate file for temporary storage
                    rewind(fp); /// move record to starting of file
                    while (fread(&i, recsize, 1, fp) == 1)  /// read all records from file
                    {
                        if (strcmp(i.name, itemname) != 0)  /// if the entered record match
                        {
                            fwrite(&i, recsize, 1, ft); /// move all records except the one that is to be deleted to temp file
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("BOOK.txt"); /// remove the orginal file
                    rename("Temp.txt", "BOOK.txt"); /// rename the temp file to original file name
                    fp = fopen("BOOK.txt", "rb+");
                    printf("Delete another record?...(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '5':
                fclose(fp);  /// close the file
                system("cls");
                goto logout;    //logout
            }
        }
    case 3:
        fp = fopen("SP.txt", "rb+");
        if (fp == NULL)
        {
            fp = fopen("SP.txt", "wb+");
            if (fp == NULL)
            {
                printf("Connot open file");
                exit(1);
            }
        }
        recsize = sizeof(i);
        while (1)
        {
            system("cls"); ///clear the console window
            printf("\t\t\t\t\t\t\t   **********************************************\n\t\t\t\t\t\t\t*WELCOME TO STORE SPORTS DIVISION'S DATABASE*\n\t\t\t\t\t\t\t   **********************************************\n\n");
            printf("1. Add New item/equipment to Stock\n"); /// option for add record

            printf("2. Show all available items\n"); /// option for showing existing record

            printf("3. Modify Records\n"); /// option for editing record

            printf("4. Delete items\n"); /// option for deleting record

            printf("5. Exit\n"); /// exit from the program

            printf(")>Your Choice : "); /// enter the choice 1, 2, 3, 4, 5
            fflush(stdin); /// flush the input buffer
            choice = _getch(); /// get the input from keyboard
            switch (choice)
            {
            case '1':  /// if user press 1
                system("cls");
                fseek(fp, 0, SEEK_END); /// search the file and move cursor to EOF
                /// here 0 indicates moving 0 distance from the end of the file

                another = 'y';
                while (another == 'y')  /// if user want to add another record
                {
                    printf("\n____________________________________________________\n");
                    printf("////////////////////////////////////////////////////");
                    printf("\n\n)>Enter name of item :- ");
                    scanf("%s", i.name);
                    printf("\n\n)>%s is available in quantity :- ", i.name);
                    scanf("%d", &i.quantity);
                    printf("\n\n)>Enter price :- ");
                    scanf("%f", &i.price);
                    fwrite(&i, recsize, 1, fp); /// write the record in the file
                    printf("\n____________________________________________________\n");
                    printf("////////////////////////////////////////////////////");
                    printf("\n\nAdd another record?...(y/n) ");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '2':
                system("cls");
                rewind(fp); ///this moves file cursor to start of the file
                printf("\t\t\t\t\t\t\t\t\tDESCRIPTION\t     QUANTITY\t\tRATE\n");
                printf("\t\t\t\t\t\t\t\t\t____________________________________________\n");
                printf("\t\t\t\t\t\t\t\t\t********************************************\n");
                while (fread(&i, recsize, 1, fp) == 1)  /// read the file and fetch the record one record per fetch
                {
                    printf("\n\n\t\t\t\t\t\t\t\t\t%s \t\t %d\t\t%.2f", i.name, i.quantity, i.price); /// print the name, age and basic salary
                }
                printf("\n\n\t\t\t\t\t\t\t\t\t//////////////////////////////////////////////\n");
                _getch();
                break;

            case '3':  /// if user press 3 then do editing existing record
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("Enter equipment's name, whose details are to be modified :- ");
                    scanf("%s", itemname);
                    rewind(fp);
                    while (fread(&i, recsize, 1, fp) == 1)  /// fetch all record from file
                    {
                        if (strcmp(i.name, itemname) == 0)  ///if entered name matches with that in file
                        {
                            printf("\nEnter new name,quantity and price :- ");
                            scanf("%s%d%f", i.name, &i.quantity, &i.price);
                            fseek(fp, -recsize, SEEK_CUR); /// move the cursor 1 step back from current position
                            fwrite(&i, recsize, 1, fp); /// override the record
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '4':
                system("cls");
                another = 'y';
                while (another == 'y')
                {
                    printf("\n)>Enter name of item to be deleted: ");
                    scanf("%s", itemname);
                    ft = fopen("Temp.txt", "wb");  /// create a intermediate file for temporary storage
                    rewind(fp); /// move record to starting of file
                    while (fread(&i, recsize, 1, fp) == 1)  /// read all records from file
                    {
                        if (strcmp(i.name, itemname) != 0)  /// if the entered record match
                        {
                            fwrite(&i, recsize, 1, ft); /// move all records except the one that is to be deleted to temp file
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("SP.txt"); /// remove the orginal file
                    rename("Temp.txt", "SP.txt"); /// rename the temp file to original file name
                    fp = fopen("SP.txt", "rb+");
                    printf("Delete another record(y/n)");
                    fflush(stdin);
                    another = _getch();
                }
                break;
            case '5':
                fclose(fp);  /// close the file
                system("cls");
                goto logout; /// exit from the program
            }
        }
    default:
        printf("\n\nUNEXPECTED INPUT DETECTED\nREDIRECTING TO LOGIN PAGE.........................................");
        _getch();
        goto logout;
    }
    _getch();
    return 0;
}





