// header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define enter 10

//----------------------------function declarartion for menus's and bla bla bla ---------------------
// main menu for any user
void menu();

// for info on the application
void info();
//----------------------------up to here for menu's--------------------------------------------------

// structure for storing data of farmer
struct user_farmer
{
    char phone[50];
    char name[50];
    char password[50];
} user;

//------------------------------functions for used in the section of farmers----------------------------------
// for login
void login_farmer();

// for registration
void signup();

// menu for farmer
void menu_farmer();

// for choices
void choice_farmer();

// for entering production details
void production_details();

// for details of fruit
void fruit_detail();

// for details of fruit
void vegetable_detail();

// for details of fruit
void dry_detail();

// check demands
void check_demands();

//------------------------------------upto here for farmer-------------------------------------------------

//-----------------------------------------main function----------------------------------------------------

int main()
{
    system("clear");
    printf("\n\n\n\n\t\t\t\t\t\tWELCOME TO OUR APPLICATION BY SAUGAT BHATTA\n");
    printf("\n\n\t\t\t\t\t\tFARM DATA MANAGEMENT\n");
    printf("\n\n\t\t\t\t\t\t\tBY\n");

    printf("\n\n\n\n\t\t\t\t\t\tPRESS ENTER TO CONTINUE ");

    char a;
    printf("\n\t\t");
    a = getchar();
    if (a == enter)
        system("clear");
    menu();
}

//---------------------------------------up to here---------------------------------------

//------------------Functions used in the section of merchant's portion-------------------

struct user_merchant
{
    char phone[50];
    char name[50];
    char password[50];
} user_merc;

// include DMA somewhere
// work of file at last
// function for login page for merchant
void login();

// function for creating new login id
void create();
// this function shows the details of certain user
//  void details();
// for choice of options to buy
void choice();
// function for item list
void item_list();
// for info on items
void item_info();
// menu
void menu_merchant();
// for requesting items
void item_request();
// structure for importing files from (file of farmer)

//----------------------------------------upto here for merchant-------------------------------------------

//------------------------------------Function defenition of menu's and bla bla ---------------------------
void menu()
{
    printf("\n\n\t\t\t\t\t-----------------WELCOME TO THE MAIN MENU---------------------\n\n\n");
    printf("\n\n\t\t\t\t\t1.Farmer\n\n");
    printf("\t\t\t\t\t2.Merchant\n\n");
    printf("\t\t\t\t\t3.About this application\n\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu_farmer();
        break;
    case 2:
        menu_merchant();
        break;
    case 3:
        system("clear");
        info();
        break;
    default:
        system("clear");
        printf("\n\nenter valid number\n\n\n");

        menu();
        break;
    }
}

void info()
{
    printf("\t\t\t\t\tABOUT THIS APPLICATION\n");
    printf("\n\n\t\t This was the application developed by students of electronics department of thapathali cmapus for\n\n");
    printf("\t\t completion of out mini-project of 1st semester.This is a baisc application build by using C.\n");
    printf("\n\n\n");

    char b;
    printf("\nDo you want to return to previous menu?\n");
    printf("\nplease enter your choice[y/n]\n\n");
    scanf(" %c", &b);
    if (b == 'y')
    {
        system("clear");
        menu();
    }
    else
        exit(1);
}

//-----------------------------------menu's definition up to here---------------------------------------------------

// -----------------------------------definition of portion of farmer-----------------------------------------------

void menu_farmer()
{
    system("clear");
    printf("\n\n\t\t\t\t\t-----------WELCOME TO MENU-------------\n\n");
    // first choices
    printf("\n\t\t\t\t\t PLEASE SELECT AN ACTION \n");
    printf("\n\t\t\t\t\t 1.LOGIN TO YOUR FARMER ACCOUNT\n");
    printf("\n\t\t\t\t\t 2.GET A FARMER CREDENTIALS\n");
    printf("\n\t\t\t\t\t 3.Exit\n");
    int answer;
    scanf("%d", &answer);
    // asnwer must be either 1 or 2 for now
    if (answer == 1)
    {
        system("clear");
        login_farmer();
    }
    else if (answer == 2)
    {
        system("clear");
        signup();
    }
    else if (answer == 3)
    {
        printf("----------EXITING------------\n");
        exit(1);
    }
    else
    {
        // printf("enter valid number\n");
        menu_farmer();
    }
}
void login_farmer()
{
    FILE *fp;
    char filename[50], phone[50], password[50], phone2[50];
    system("clear");
    printf("\nPhone No:\t");
    scanf("%s", phone);
    printf("Password:\t");
    scanf("%s", password);
    fp = fopen(strcat(phone, ".dat"), "r");
    if (fp == NULL)
    {
        printf("Account  not registered");
        char ans = 'y';
        printf("\n\nDo you want to register?\n\n");
        printf("please enter your choice[y/n]...\n");
        scanf(" %c", &ans);
        if (ans == 'y')
        {
            system("clear");
            create();
        }
        else
            exit(1);
    }
    else
    {
        fread(&user, sizeof(struct user_farmer), 1, fp);
        fclose(fp);
        if (strcmp(password, user.password) == 0)
        {
            system("clear");
            printf("\n\nsuccessful login ");
            printf("%s \n", user.name);
            // system("clear");
            choice_farmer();
        }
        // else
        // {
        //     printf("not here\n");
        // }
    }
}

void signup()
{

    system("clear");
    struct user_farmer user;
    char filename[50], phone[50], password[50], phone2[50];
    FILE *fp;
    printf("\nEnter your name:\t");
    scanf(" %s", user.name);
    printf("Enter your phone number of 10 digits:\t");
    scanf("%s", user.phone);
    if (strlen(user.phone) < 10)
    {
        printf("please enter number of 10 digit\n");
        scanf("%s", user.phone);
    }
    // else
    // {
    //     continue;
    // }

    printf("Enter your new password of atleast 6 digits:\t");
    scanf("%s", user.password);
    if (strlen(user.password) < 6)
    {
        printf("please enter password of atleast 6 digit\n");
        scanf(" %s", user.password);
    }
    // else
    // {
    //     continue;
    // }
    stpcpy(filename, user.phone);
    fp = fopen(strcat(filename, ".dat"), "w");
    fwrite(&user, sizeof(user), 1, fp);
    if (fwrite != 0)
    {
        printf("Succesfully registered");
        printf("\n\nPlease re-run the program after registrating to see changes\n\n");
        exit(1);
    }
}

void choice_farmer()
{
    printf("\n\n\t\tPLEASE SELECT AN ACTION\n\n");
    printf("\n\n\t\t1.Enter production details\n");
    printf("\n\t\t2.Check demands\n");
    printf("\n\t\t3.Return to previous menu\n");

    int choose;
    printf("\n");
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("clear");
        production_details();
    }

    // else if (choose == 2)
    // {
    //     system("clear");
    //     item_info();
    // }
    else if (choose == 2)
    {
        system("clear");
        // item_request();
        check_demands();
    }
    else if (choose == 3)
    {
        system("clear");
        menu_farmer();
    }
    else
        printf("enter valid number\n");
}

void production_details()
{
    printf("\n\n\t1.Fruits\n");
    printf("\n\n\t2.Vegetable\n");
    printf("\n\n\t3.Dry Fruits\n");
    printf("\n\n\t4.Return to previous menu\n");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        fruit_detail();
        break;
    case 2:
        vegetable_detail();
        break;
    case 3:
        dry_detail();
        break;
    case 4:
        choice_farmer();
        break;
    default:
        break;
    }
}
struct product_details
{
    char name_product[20];
    int quantity;
    int price;
    char produced_by[20];
    int contact;

} intake;

void fruit_detail()
{
    FILE *fruits = fopen("fruits.csv", "a");
    printf("\nEnter the name of fruit\n");
    scanf("%s",intake.name_product);
    printf("Enter the quantity of same fruit (kg)\n");
    scanf("%d", &intake.quantity);
    printf("Enter the price of same fruit per kg\n");
    scanf("%d", &intake.price);
    printf("Enter who has the product?\n");
    scanf("%s",intake.produced_by);
    printf("Enter the contact of same person?\n");
    scanf("%d",&intake.contact);

    // fwrite(&intake,sizeof(intake),1,fruits);
    fprintf(fruits, "\n%s\t%d\t\t%d\t\t%s\t\t%d\n", intake.name_product, intake.quantity, intake.price, intake.produced_by, intake.contact );
    fclose(fruits);

    char answer = 'y';
    printf("\n\nDo you want to return to previous menu\n");
    printf("enter your choice[y/n]");
    char a;
    scanf(" %c", &a);
    if (a == answer)
    {
        system("clear");
        production_details();
    }
    else
        exit(1);
}

void vegetable_detail()
{
    FILE *vegetable = fopen("vegetable.csv", "a");
    printf("\nEnter the name of vegetable\n");
    scanf("%s", intake.name_product);
    printf("Enter the quantity of same vegetable (kg)\n");
    scanf("%d", &intake.quantity);
    printf("Enter the price of same vegetable per kg\n");
    scanf("%d", &intake.price);
    printf("Enter who has the product?\n");
    scanf(" %s", intake.produced_by);
    printf("Enter the contact of same person?\n");
    scanf(" %d",&intake.contact);

    fprintf(vegetable, "\n%s\t%d\t\t%d\t\t%s\t\t%d\n", intake.name_product, intake.quantity, intake.price, intake.produced_by, intake.contact);
    fclose(vegetable);

    char answer = 'y';
    printf("\n\nDo you want to return to previous menu\n");
    printf("enter your choice[y/n]");
    char a;
    scanf(" %c", &a);
    if (a == answer)
        production_details();
    else
        exit(1);
}

void dry_detail()
{
    // FILE *dry = fopen("dry.csv", "a");
    // printf("\nEnter the name of dry fruit\n");
    // scanf("%s", intake.name_product);
    // printf("Enter the quantity of same dry fruit (kg)\n");
    // scanf("%d", &intake.quantity);
    // printf("Enter the price of same dry fruit per kg\n");
    // scanf("%d", &intake.price);
    // printf("Enter who has the product?\n");
    // scanf(" %[^\n]s", intake.produced_by);
    // printf("Enter the contact of same person?\n");
    // scanf(" %s", intake.contact);

    // fprintf(dry, "%s\t%d\t\t%d\t\t%s\t\t%s", intake.name_product, intake.quantity, intake.price, intake.produced_by, intake.contact);
    // fclose(dry);

    // char answer = 'y';
    // printf("\n\nDo you want to return to previous menu\n");
    // printf("enter your choice[y/n]");
    // char a;
    // scanf(" %c", &a);
    // if (a == answer)
    // {
    //     system("clear");
    //     production_details();
    // }
    // else
    //     exit(1);
    FILE *dry= fopen("dry.csv", "a");
    printf("\nEnter the name of dry fruits\n");
    scanf("%s", intake.name_product);
    printf("Enter the quantity of same dry fruits (kg)\n");
    scanf("%d", &intake.quantity);
    printf("Enter the price of same dry fruits per kg\n");
    scanf("%d", &intake.price);
    printf("Enter who has the product?\n");
    scanf(" %s", intake.produced_by);
    printf("Enter the contact of same person?\n");
    scanf(" %d",&intake.contact);

    fprintf(dry, "\n%s\t%d\t\t%d\t\t%s\t\t%d\n", intake.name_product, intake.quantity, intake.price, intake.produced_by, intake.contact);
    fclose(dry);

    char answer = 'y';
    printf("\n\nDo you want to return to previous menu\n");
    printf("enter your choice[y/n]");
    char a;
    scanf(" %c", &a);
    if (a == answer)
        production_details();
    else
        exit(1);
}

struct requests
{
    char item_name[20];
    int item_quantity;
    char requested_by[20];
    int contact;
} requested_by;
void check_demands()
{
    FILE *demands = fopen("request.csv", "r");
    if (demands == NULL)
    {
        printf("No item requested for now\n");
        char a;
        printf("\n\n\nDo you want to return to previous menu\n");
        printf("please enter your choice[y/n]\n");
        scanf(" %c", &a);
        if (a == 'y')
        {
            system("clear");
            choice_farmer();
        }
        else
            exit(1);
    }
    else
    {
        fread(&requested_by, sizeof(requested_by), 1, demands);
        fclose(demands);
        printf("\n\n\t\tName\tQuantity(kg)\tMerchant\tContact\n");
        printf("\t-----------------------------------------------------------------\n\n\n");
        // printf("\t\t%s\t%d\t%s\t%s\n",requested_by.item_name,requested_by.item_quantity,requested_by.requested_by,requested_by.contact);
        printf("\n\t\t%s", requested_by.item_name);
        printf("\t%d", requested_by.item_quantity);
        printf("\t\t%s", requested_by.requested_by);
        printf("\t%d", requested_by.contact);

        printf("\n\n\n\n");
        char choice = 'y';
        printf("Do you want to return to previous menu\n\n");
        printf("enter your choice[y/n]\n");
        scanf(" %c", &choice);
        if (choice == 'y')
        {
            system("clear");
            choice_farmer();
        }

        else if (choice == 'n')
            exit(1);

        else
            printf("enter valide character\n");
    }
}

//--------------------------------------upto here for farmer------------------------------------------------------------------

//-------------------------------function defition of merchant portion--------------------------------------------------------------------

// information about fruits
struct product_detail
{
    char name_product[20];
    int quantity;
    int price;
    char produced_by[20];
    int contact;

} extract;

void fruits()
{
    FILE *fruits_details = fopen("fruits.csv", "r");

    if (fruits_details == NULL){
        printf("No production at a time\n");
    }
    else
    {
        // fseek(fruit_detail, 0, SEEK_END);
        // long fsize = ftell(fruit_detail);
        // fseek(fruit_detail, 0, SEEK_SET);
        fread(&extract, sizeof(extract), 1, fruits_details);
        printf("\nFruit Quantity \t     Price \t\t Farmer \t  Contact\n ");
        printf("---------------------------------------------------------------------------------\n");
        printf("\t\t%s \t %d \t %d\t\t %s\t%d\n\n\n", extract.name_product, extract.quantity, extract.price, extract.produced_by, extract.contact);
        fclose(fruits_details);
        printf("\n\n\n\n");
        char answer = 'y';
        printf("Do you want to return to Previous menu(y/n)\n");
        scanf(" %c", &answer);
        if (answer == 'y')
        {
            system("clear");
            item_list();
        }
        else if (answer == 'n')
        {
            printf("----------EXITING------------\n");
            exit(1);
        }
        // more from file generated by farmer's}
    }
}
// veggies
void veggies()
{

    // printf("\t\tFor 'this vegetables' contact 'this person' \n");
    // printf("\t\tFor 'this vegetables' contact 'this person' \n");
    // printf("\t\tFor 'this vegetables' contact 'this person' \n");
    FILE *vege_details = fopen("vegetable.csv", "r");
    fread(&extract, sizeof(extract), 1, vege_details);
    if (vege_details == NULL)
        printf("No production at a time\n");
    else

    {
        printf("\nVege Quantity \t Price \t\t Farmer \t  Contact\n ");
        printf("------------------------------------------------------------------------------------\n");
        printf("\n\t\t%s\t%d \t %d\t\t %s\t%d\n", extract.name_product, extract.quantity, extract.price, extract.produced_by, extract.contact);
          fclose(vege_details);

        printf("\n\n\n\n\n\n");
        char answer = 'y';
        printf("Do you want to return to Previous menu(y/n)\n");
        scanf(" %c", &answer);
        if (answer == 'y')
        {
            system("clear");

            item_list();
        }
        else if (answer == 'n')
        {
            printf("----------EXITING------------\n");
            exit(1);
        }
    }
    // more from file generated by farmer's
}
// dryfruits
void dry()
{
    // FILE *dry_details = fopen("dry.csv", "r");
    // fread(&extract, sizeof(extract), 1, dry_details);
    // fclose(dry_details);
    // if (dry_details == NULL)
    //     printf("No production at a time\n");
    // else
    // { // printf("\t\tFor 'this dry fruit' contact 'this person' \n");
    //     // printf("\t\tFor 'this dry fruit' contact 'this person' \n");
    //     // printf("\t\tFor 'this dry fruit' contact 'this person' \n");
    //     fread(&extract, sizeof(extract), 1, dry_details);
    //     printf("\n\t\tDry Fruit \t Quantity \t Price \t Farmer \t Contact\n ");
    //     printf("\t------------------------------------------------------------------------------------\n");
    //     printf("\n\t\t%s \t\t %d \t\t %d\t\t %s\t\t%s\n", extract.name_product, extract.quantity, extract.price, extract.produced_by, extract.contact);

    //     printf("\n\n\n\n\n\n");
    //     char answer = 'y';
    //     printf("Do you want to return to Previous menu(y/n)\n");
    //     scanf(" %c", &answer);
    //     if (answer == 'y')
    //     {
    //         system("clear");
    //         item_list();
    //     }
    //     else if (answer == 'n')
    //     {
    //         printf("----------EXITING------------\n");
    //         exit(1);
    //     }
    // }
    // // more from file generated by farmer's
     FILE *dry_details = fopen("dry.csv", "r");
    fread(&extract, sizeof(extract), 1, dry_details);
    if (dry_details == NULL){
        printf("No production at a time\n");
    }
    else
    {
        printf("\nDryFruit Quantity \t Price \t\t Farmer \t  Contact\n ");
        printf("------------------------------------------------------------------------------------\n");
        printf("\n\t\t%s \t %d \t %d\t\t %s\t%d\n", extract.name_product, extract.quantity, extract.price, extract.produced_by, extract.contact);
        fclose(dry_details);
        printf("\n\n\n\n\n\n");
        char answer = 'y';
        printf("Do you want to return to Previous menu(y/n)\n");
        scanf(" %c", &answer);
        if (answer == 'y')
        {
            system("clear");
            item_list();
        }
        else if (answer == 'n')
        {
            printf("----------EXITING------------\n");
            exit(1);
        }
    }
    // more from file generated by farmer'
}
// main function
//  int main()
//  {
//      system("clear");
//      printf("\n\n\n\n\t\t\t\t\t---------WELCOME TO OUR APPLICATION-----------\n");
//      // printf("\t\t\t-----------------APPLICATION------------------\n");
//      printf("\n\n\n\n\t\t\t\t\t\tPRESS ENTER TO CONTINUE ");

//     char a;
//     printf("\n\t\t");
//     a = getchar();
//     if (a == enter)
//         system("clear");
//     menu();
//     return 0;
// }
void menu_merchant()
{
    system("clear");
    printf("\n\n\t\t\t\t\t-----------WELCOME TO MENU-------------\n\n");
    // first choices
    printf("\n\t\t\t\t\t PLEASE SELECT AN ACTION \n");
    printf("\n\t\t\t\t\t 1.LOGIN TO YOUR MERCHANT ACCOUNT\n");
    printf("\n\t\t\t\t\t 2.GET A MERCHANT CREDENTIALS\n");
    printf("\n\t\t\t\t\t 3.Exit\n");
    int answer;
    scanf("%d", &answer);
    // asnwer must be either 1 or 2 for now
    if (answer == 1)
    {
        system("clear");
        login();
    }
    else if (answer == 2)
    {
        system("clear");
        create();
    }
    else if (answer == 3)
    {
        printf("----------EXITING------------\n");
        exit(1);
    }
    else
    {
        // printf("enter valid number\n");
        menu_merchant();
    }
}

// void login()
// {
//     system("clear");
//     printf("\n\t\t-----------WELCOME TO LOGIN PAGE FOR MERCHANT'S-------------\n\n");
//     printf("\n\t\t-----------PLEASE ENTER THE VALID CODE PROVIDED AFTER REGISTRATION-------\n");
//     char user_name[12];
//     char password[10];
//     printf("\n\t\tEnter your user name ");
//     scanf("\t\t %s", user_name);
//     printf("\n\t\tEnter your password ");
//     scanf("\t\t %s", password);

//     //values for user_name and password must be checked from file
//     if ((strcmp(user_name, "one") == 0) && (strcmp(password, "two") == 0))
//     {
//         system("clear");
//         printf("\nYou have successfully logged in\n");
//         //details();
//         choice();
//     }
// }
void login()
{
    FILE *fp;
    char filename[50], phone[50], password[50], phone2[50];
    system("clear");
    printf("\nPhone No:\t");
    scanf("%s", phone);
    printf("Password:\t");
    scanf("%s", password);
    fp = fopen(strcat(phone, ".dat"), "r");
    if (fp == NULL)
    {
        printf("Account  not registered\n\n");
        char ans = 'y';
        printf("\n\nDo you want to register?\n\n");
        printf("please enter your choice[y/n]...\n");
        scanf(" %c", &ans);
        if (ans == 'y')
            create();
        else
            exit(1);
    }
    else
    {
        fread(&user_merc, sizeof(struct user_merchant), 1, fp);
        fclose(fp);
        if (strcmp(password, user_merc.password) == 0)
        {
            system("clear");
            printf("\n\nsuccessful login ");
            printf("%s \n", user_merc.name);
            // system("clear");
            choice();
        }
        else
        {
            printf("Invalid password \n");
            printf("\n\n\t\t--------------Exiting----------\n");
            exit(1);
            // printf("not here\n");
        }
    }
}
// database missing
//  void create()
//  {
//      printf("\t\t-----------WELCOME TO SIGNUP PAGE-------------\n\n");

//     FILE *details, *read;
//     details = fopen("details.csv", "a+");
//     printf("\t\t Please Enter your first name  ");
//     char first_name[20];
//     scanf("%s", first_name);
//     fprintf(details, "%s\n", first_name);
//     printf("\n\t\t Please Enter your last name   ");
//     char last_name[20];
//     scanf("%s", last_name);
//     fprintf(details, "%s\n", last_name);
//     printf("\n\t\t Please Enter your contact number   ");
//     char conatct[11];
//     scanf("%s", conatct);
//     fprintf(details, "%s\n", conatct);
//     // printf("\n\t\t Please Enter your new user name   ");
//     // char user_name[11];
//     // scanf("%s", user_name);
//     // fprintf(details, "%s\n", user_name);
//     // printf("\n\t\t Please Enter your new password  ");
//     // char password[11];
//     // scanf("%s", password);
//     // fprintf(details, "%s\n", password);
//     fprintf(details, "\n");

//     fclose(details);
//     login();
//     printf("\n");

//     //reading a file must be done

//     // read = fopen("details.csv", "r+");
//     // char a;
//     // while ((a = fgetc(read) != EOF))
//     // {
//     //     printf("%c", a);
//     // }
//     // fclose(read);
// }
void create()
{
    system("clear");
    struct user_merchant user;
    char filename[50], phone[50], password[50], phone2[50];
    FILE *fp;
    int opt, choice;
    int amount;
    printf("\nEnter your name:\t");
    scanf(" %s", user_merc.name);
    printf("Enter your phone number of atleast 10 digit:\t");
    scanf("%s", user_merc.phone);
    if (strlen(user_merc.phone) < 10)
    {
        printf("please enter number of 10 digit\n");
        scanf("%s", user_merc.phone);
    }
    // else
    // {
    //     continue;
    // }

    printf("Enter your new password of atleast 6 digit:\t");
    scanf("%s", user_merc.password);
    if (strlen(user_merc.password) < 6)
    {
        printf("please enter password of atleast 6 digit\n");
        scanf(" %s", user_merc.password);
    }
    // else
    // {
    //     continue;
    // }
    stpcpy(filename, user_merc.phone);
    fp = fopen(strcat(filename, ".dat"), "w");
    // fp = fopen(/home/kingdom/Desktop/Project/merchant/strcat(filename, ".dat"), "w");
    fwrite(&user_merc, sizeof(user_merc), 1, fp);
    if (fwrite != 0)
    {
        printf("Succesfully registered");
        printf("\n\nPlease re-run the program after registrating to see changes\n");
        exit(1);
    }
    // printf("\n");
    // char answer = 'y';

    // printf("\n Do you want to login to your account?\n");
    // scanf(" %c", &answer);
    // if (answer == 'y')
    // {
    //     login();
    // }
    // else
    // {
    //     menu();
    // }
}

// void details()
// {
//     printf("\t\t Name\n");
//     printf("\t\t ID\n");
//     printf("\t\t Location\n");
//     printf("\t\t Contact\n");
//     printf("\n");
// }

void choice()
{
    printf("\n\n\t\t\t---------------PLEASE SELECT AN ACTION------------\n");
    printf("\n\t\t1.Do you want to buy a item?\n");
    // printf("\n\t\t2.Do you want to have info on items?\n");
    printf("\n\t\t2.Do you want to request an item?\n");
    // printf("\n\t\t4.Item Info\n");
    printf("\n\t\t3.Log Out\n");
    int choose;
    printf("\n");
    scanf("%d", &choose);

    if (choose == 1)
    {
        system("clear");
        item_list();
    }

    // else if (choose == 4)
    // {
    //     system("clear");
    //     item_info();
    // }
    else if (choose == 2)
    {
        system("clear");
        item_request();
    }
    else if (choose == 3)
    {
        system("clear");
        menu_merchant();
    }
    else
        printf("enter valid number\n");
}
void item_list()
{
    printf("\n\n\t\t\t---------------WELCOME TO THE ITEM LISTING PAGE------------\n");
    printf("\n\n\t\t\tWhat do you want to buy?\n");
    printf("\n\t\t\t\t1.Fruits\n");
    printf("\n\t\t\t\t2.Vegetables\n");
    printf("\n\t\t\t\t3.Dry fruits\n");
    printf("\n\t\t\t\t4.Return to Previous menu\n");
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        system("clear");
        fruits();
        break;
    case 2:
        system("clear");
        veggies();
        break;
    case 3:
        system("clear");
        dry();
        break;
    case 4:
        system("clear");
        choice();
        break;
    default:
        printf("Enter valid number\n");
    }
}
// this function is for info on production by farmers
//  void item_info()
//  {
//      // printf("\n\n\t\t\t---------------WELCOME TO THE INFO PAGE------------\n");
//      // printf("\t\t 1.Item goood for 10 days\n");
//      // printf("\t\t 2.Items produced in large amount\n");
//      // printf("\n\t\t------for furthur detail on item please register your account -------\n");

//     fruits();
// }

void item_request()
{
    struct requests
    {
        char item_name[20];
        int item_quantity;
        char requested_by[20];
        int contact;
    } request;

    printf("\n\n\t\t\t---------------WELCOME TO THE REQUEST PAGE------------\n");
    printf("\n\nPlease enter the name of item you want to request\n");
    scanf(" %s", request.item_name);
    printf("\nPlease enter the quantity of item you want to request(in kg)\n");
    scanf("%d", &request.item_quantity);
    printf("\nPlease enter the name of person who is requesting it\n");
    scanf("%s", request.requested_by);
    printf("\nPlease enter the contact of person who is requesting\n");
    scanf("%d", &request.contact);

    // fread(&user, sizeof(struct user_merchant), 1, fp);
    // fclose(fp);
    FILE *item_request = fopen("request.csv", "a");
    // fwrite(&request,sizeof(struct requests), 1, item_request);
    fprintf(item_request, "%s\t%d\t%s\t%d\n", request.item_name, request.item_quantity, request.requested_by, request.contact);
    fclose(item_request);

    printf("\n\n\n");
    char answer = 'y';
    printf("Do you want to return to Previous menu(y/n)\n");
    scanf(" %c", &answer);
    if (answer == 'y')
    {
        system("clear");
        choice();
    }
    else if (answer == 'n')
    {
        printf("\n\n\n\n----------EXITING------------\n\n");
        exit(1);
    }
}

//--------------------------------up to here for merchant------------------------------------------------------------------
 