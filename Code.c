#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

void wait(long);//
void load();//
void loginwindow(void);
void login(void);//
void mainmenu();//
void resetpass();
void setpass(void);
int checkpass();
void signin();
void showinfo(void);
void loanwindow();//
void loan();//
void logout();//
void update();
void deposite();
void viewbalance();
void withdraw();

char pass[20], confpass[20], repass[20], loantype[15], pin[5], repin[5];
int credit;
FILE *dep;
float balance = 0.00, amount;
struct user
{
    char first[10], last[10], address[60], pswd[20], bday[10], mob[11], acctype[10], loantype[15], accno[14], aadhar[12], epin[5];
    float amt;
    int age, loanage, credit, opt;
} u;

int main()
{
    dep = fopen("updatedeposite.txt", "ab+");
    fprintf(dep, "%f", balance);
    fclose(dep);
    fflush(stdin);
    loginwindow();
    mainmenu();
    return 0;
}

void wait(long int n)
{
    for (int i = 0; i < n; i++)
        ;
}
void load()
{
    for (int i = 0; i < 8; i++)
    {
        wait(120000000);
        printf(".");
    }
}
void loginwindow()
{
    char ch;
    int choice;
here:
    system("cls");
    system("color 0F ");
    printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  BVM CO-OPERATIVE BANK LIMITED  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t\t\t\t\t Welcome to Bank Management System\n\n\t\t\t\t\t\t\t\t    User Login \n\n");
    printf("\n\t\t\t\t::::::::::::  If you are new user....Sign in first ::::::::::::\n\n\n");
    printf("\t\t\t\t\t\t1. Sign in (for new user)\n\t\t\t\t\t\t2. login (for existing user)\n");
    printf("\n\t\t\t\t\t\tEnter your choice : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        signin();
        // here:
        printf("\n\n\t\t\t\t*************** Now...login to the application ***************\n");
        printf("\n\t\t\tGoing to login window");
        load();
        printf("\n\n\t\t\tPress any key...........\n");
        fflush(stdin);
        getch();
        login();
    }

    else if (choice == 2)
    {
        FILE *p = fopen("signin_info.txt", "r");
        if (p == NULL)
        {
            printf("\n\n\t\t\t::::::::::::::::::::::::::  You are new user....Sign-in first  ::::::::::::::::::::::::::\n\n");
            printf("\t\t\t\t\t\t\tPress ENTER key for sign-in\n");
            char ch=getche();
            printf("\n\t\t\t\t\t\t\tGoing to sign-in window");
            load();
            signin();
            login();
        }
        else
            login();
    }
    printf("\n\n\t\t\t\t\tWait");
    load();

    if (checkpass() == 1)
    {
        printf("\n\t\t\t******************** login successfull ******************\n");
        printf("\nloading");
        load();
    }
    else if (checkpass() == 0)
    {
        fflush(stdin);
        printf("\n\n\t*********** Wrong Password or user doesn't exist!!! ***********\n\n");
        printf("\t\tForgot password : press 'f'\n\t\tTry again : press 't'\n");
        ch = getche();
        if (ch == 'f' || ch == 'F')
        {
            resetpass();
            printf("\n\t\t\tGoing to login window");
            load();
            goto here;
        }
        if (ch == 't' || ch == 'T')
        {
            printf("\nloading");
            load();
            goto here;
        }
    }
}
void login()
{

    system("cls");
    system("color 8F");
    fflush(stdin);
    printf("\n\n\t\tEnter Your correct application password to go to main menu\n\n");
    printf("\n\t\t\t\t Application Password : ");
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            u.pswd[i] = '\0';
            break;
        }

        u.pswd[i] = ch;
        printf("*");
        i++;
    }
    printf("\n\n");
}
void mainmenu()
{
    char ch;
menu:
    system("cls");
    system("color F");
    char choice;
    FILE *fp = fopen("signin_info.txt", "rb+");
    printf("\n\n\t\t\t\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  BVM CO-OPERATIVE BANK LIMITED  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t\t\t     ::::::::::::::::::  Welcome to the Bank Application  ::::::::::::::::::\n\n\t\t\t\t\t\t\t\t  ::::::::  User Login  :::::::\n\n");
    printf("\n\n\t\t\t\t\t\tHELLO.... ");
    while (fread(&u, sizeof(u), 1, fp) == 1)
    {
        printf("%s", u.first);
        printf(" %s", u.last);
    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t\t[1].\tView Account\n");
    printf("\t\t\t\t\t\t\t[2].\tCurrent Balance\n");
    printf("\t\t\t\t\t\t\t[3].\tUpdate Account Information\n");
    printf("\t\t\t\t\t\t\t[4].\tReset Password\n");
    printf("\t\t\t\t\t\t\t[5].\tDeposite Amount\n");
    printf("\t\t\t\t\t\t\t[6].\tWithdraw Amount\n");
    printf("\t\t\t\t\t\t\t[7].\tLoan\n");
    printf("\t\t\t\t\t\t\t[8].\tLogout\n");

    printf("\n\t\t\t\t\t\t\tEnter your choice : ");
    fflush(stdin);
    scanf("%c", &choice);

    switch (choice)
    {
    case '1':
        fflush(stdin);
        showinfo();
        break;
    case '2':
        viewbalance();
        break;
    case '3':
        fflush(stdin);
        update();
        break;
    case '4':
        fflush(stdin);
        resetpass();
        break;
    case '5':
        fflush(stdin);
        deposite();
        break;
    case '6':
        fflush(stdin);
        withdraw();
        break;
    case '7':
        loanwindow();
        break;
    case '8':
        logout();
        printf("\n\t\t\t\t\t\t\tloging out");
        load();
        exit(0);
        break;

    default:
        printf("\n\n\t\t\t\t\t::::::::::::::::: Please enter valid choice :::::::::::::::::");
        break;
    }
    printf("\n\nPress any key for main menu : ");
    ch = getche();
    printf("\n\n\t\t\t\t\t\t\tLoading");
    load();
    goto menu;
}
void resetpass()
{
    char ch;
    system("cls");
    system("color fc ");
    printf("\n\n\n\t\t\t\t::::::::::::::::::::::::::::::: Reset your password :::::::::::::::::::::::::::::::");
    FILE *fp1, *fp2;
    fp1 = fopen("resetpassword.txt", "w+");
    printf("\n\n\t\t\t\t\t\tEnter new Password : ");
    fflush(stdin);
    gets(repass);
    fputs(repass, fp1);
    fclose(fp1);

    fp1 = fopen("resetpassword.txt", "r");
    fp2 = fopen("projectpassword.txt", "w");
    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("\n\t\t\tLoading");
    load();
    printf("\n\n\t\t\t\t\t*********************** Password Reset successfully ***********************\n");
}
void resetpin()
{
    char ch;
    system("cls");
    system("color fc ");
    printf("\n\n\n\t\t\t\t::::::::::::::::::::::::::::::: Reset your E-pin :::::::::::::::::::::::::::::::");
    FILE *fp1, *fp2;
    fp1 = fopen("resetpin.txt", "w+");
    printf("\n\n\t\t\t\t\t\tEnter new E-pin : ");
    fflush(stdin);
    gets(repin);
    fputs(repin, fp1);
    fclose(fp1);

    fp1 = fopen("resetpin.txt", "r");
    fp2 = fopen("setpin.txt", "w");
    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    printf("\n\t\t\tLoading");
    load();
    printf("\n\n\t\t\t\t\t*********************** E-pin Reset successfully ***********************\n");
}
void setpass()
{
    FILE *fp = fopen("projectpassword.txt", "a");
    printf("\n\n\t\t\tEnter Password : ");
    fflush(stdin);
    gets(pass);
    // strcpy(u.initpswd, pass);
    fputs(pass, fp);
    printf("\n\t\t\tLoading");
    load();
    printf("\n\n\t\t*********************** Password set successfully ***********************\n");

    fclose(fp);
}
void setpin()
{
    FILE *fp = fopen("setpin.txt", "a");
    printf("\n\n\t\t\tEnter E-pin : ");
    fflush(stdin);
    gets(pin);
    // strcpy(u.initpswd, pass);
    fputs(pin, fp);
    printf("\n\t\t\tLoading");
    load();
    printf("\n\n\t\t*********************** E-pin set successfully ***********************\n");

    fclose(fp);
}
int checkpass()
{
    char s[20];
    FILE *fp = fopen("projectpassword.txt", "r");
    fgets(s, sizeof(s), fp);
    if (strcmp(s, u.pswd) == 0)
        return 1;
    else
        return 0;
}
void signin()
{
    system("cls");
    int choice, str, str2, str3;
    FILE *fp;
    fp = fopen("signin_info.txt", "ab+");
    if (strlen(u.loantype) == 0)
    {
        strcpy(u.loantype, "NA!!");
        u.credit = 8;
    }
    
    printf("\n\n\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SIGN IN YOURSELF INTO BVM CO-OPERATIVE BANK LIMITED \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n____________________________________________________________________________________________________________________________________________________________________\n");
    printf("\n\n\n\n\t\t\t\t\t\t\t[-] Enter your First name:-  ");
    scanf("%s", u.first);

    printf("\n\n\t\t\t\t\t\t\t[-] Enter your Last name:-  ");
    scanf("%s", u.last);

    printf("\n\n\t\t\t\t\t\t\t[-] account number :-  ");
    scanf("%s", u.accno);

    printf("\n\n\t\t\t\t\t\t\t[-] Set  your Application Password:-  ");
    setpass();

error:
    printf("\n\n\t\t\t\t\t\t\t[-]Confirm your password:-  ");
    scanf("%s", confpass);
    if (strcmp(confpass, pass) != 0)
    {
        printf("\n\n\t\t\t\t\t\t\tAbove entered password does not match!! Try again");
        goto error;
    }
    else
        printf("\n\n\t\t\t\t\t\t\tPassword match");

    printf("\n\n\t\t\t\t\t\t\t[-] Enter E-Pin:- ");
    setpin();

    printf("\n\n\t\t\t\t\t\t\t[-] Enter your age:- ");
    fflush(stdin);
    scanf("%d", &u.age);

    printf("\n\n\t\t\t\t\t\t\t[-] Enter the Birth date :- ");
    scanf("%s", u.bday);

    printf("\n\n\t\t\t\t\t\t\t[-] Enter your AADHAR Number:- ");
    scanf("%s", u.aadhar);

start:
    printf("\n\n\t\t\t\t\t\t\t[-] Enter a valid mobile number:-  ");
    fflush(stdin);
    scanf("%s", u.mob);
    if (strlen(u.mob) != 10)
    {
        printf("\n\n\t\t\t\t\t\t\t\t[WARNING!] Please enter a valid 10 digit number");
        goto start;
    }

    printf("\n\n\t\t\t\t\t\t\t[-] Enter your permenent Address and proper PINCODE of area:-  ");
    scanf(" %[^\n]%*c", u.address);
    printf("\n\n\t\t\t\t\t\t\t:::::::::::::::: Select account type ::::::::::::::::");
    printf("\n\n\t\t\t\t\t\t\t\t[1] Saving Account");
    printf("\n\t\t\t\t\t\t\t\t[2] Salary Account");
    printf("\n\t\t\t\t\t\t\t\t[3] Fixed Deposit Account");
again:
    printf("\n\n\t\t\t\t\t\t\t[-] Enter your choice:-  ");
    scanf("%d", &choice);
    printf("\nloading");
    load();
    switch (choice)
    {
    case 1:
        printf("\n\n\t\t\t\t\t\t\t-> Saving Account selected");
        printf("\n\n\t\t\t\t\t\t\t\t**INSTRUCTIONS REGARDING SAVING ACCOUNT**");
        printf("\n\n\t\t\t\t\t\t\t[1] Customer's Account must have Rs.2000");
        printf("\n\n\t\t\t\t\t\t\t[2] Customer can make joint Account with 4 person maximun");
        printf("\n\n\t\t\t\t\t\t\t[3] Customer can apply for Debit Card after 2 months of Account Opening");
        strcpy(u.acctype, "Saving");
        break;
    case 2:
        printf("\n\n\t\t\t\t\t\t\t-> Salary Account selected");
        printf("\n\n\t\t\t\t\t\t\t[1] Customer will be given interest rate upto 2 percent");
        printf("\n\n\t\t\t\t\t\t\t[1] NO Deposit money is reuired in Salary Account");
        printf("\n\n\t\t\t\t\t\t\t[2] Customer can't make joint Account in Salary Account");
        printf("\n\n\t\t\t\t\t\t\t[3] Customer is eligible for Debit Card after 15 days after opening Account");
        strcpy(u.acctype, "Salary");
        break;
    case 3:
        printf("\n\n\t\t\t\t\t\t\t-> Fixed Deposit Account selected");
        printf("\n\n\t\t\t\t\t\t\t\t**INSTRUCTIONS REGARDING FIXED DEPOSIT ACCOUNT**");
        printf("\n\n\t\t\t\t\t\t\t\t\t[1] Customer will be given interest rate upto 2 percent");
        printf("\n\n\t\t\t\t\t\t\t\t\t[2] Customer's Account must have Rs.4000");
        printf("\n\n\t\t\t\t\t\t\t\t\t[3] Customer can't make joint Account");
        printf("\n\n\t\t\t\t\t\t\t\t\t[4] Customer is eligible for Debit Card immediately after opening the Account");
        strcpy(u.acctype, "Fixed Deposit");
        break;
    default:
        printf("\n\n\t\t\t\t\t\t\t\t\t[WARNING!]Please Enter the correct Number ");
        goto again;
        break;
    }
    ("\n_______________________________________________________________________________________________________________________\n");
    ("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t\t\t\t\t\t\t[-] Message: Congratulations!! You succesfully created Account in Bank Of BVM");

    fwrite(&u, sizeof(u), 1, fp);
    fclose(fp);
}

void showinfo()
{
    system("cls");
    system("color 06");
    FILE *fp;
    fp = fopen("signin_info.txt", "rb+");
    while (fread(&u, sizeof(u), 1, fp) == 1)
    {
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUSTOMER'S INFORMATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        printf("\n\n\t\t\t\tCustomer's First Name              :-  -%s-", u.first);
        printf("\n\n\t\t\t\tCustomer's Last Name               :-  -%s-", u.last);
        printf("\n\n\t\t\t\tCustomer's Account Number          :-  -%s-", u.accno);
        printf("\n\n\t\t\t\tCustomer's AADHAR number           :-   %s", u.aadhar);
        printf("\n\n\t\t\t\tCustomer's Mobile number           :-   %s", u.mob);
        printf("\n\n\t\t\t\tCustomer's Birth Date              :-   %s", u.bday);
        printf("\n\n\t\t\t\tCustomer's Age                     :-   %d", u.age);
        printf("\n\n\t\t\t\tCustomer's Permenent Address       :-   %s", u.address);
        printf("\n\n\t\t\t\tCustomer's Account Type            :-   %s", u.acctype);
        printf("\n\n\t\t\t\tCustomer's Loan Status             :-   %s", u.loantype);
        printf("\n\n\t\t\t\tCustomer's Credit Score            :-   %d", u.credit);
    }
    fclose(fp);
}
void loanwindow()
{
    system("cls");
    int str1, str2;
    char choice[5];

    printf("\n\n\t\t\t\t**WELCOME TO LOAN INQUIRY**");
    fflush(stdin);
start:
    printf("\n\n\n\tDo you have intrest in taking any Loan? Answer 'YES' or 'NO':-  ");
    scanf("%s", choice);

    str1 = strcmp("yes", choice);
    str2 = strcmp("no", choice);

    if (str1 == 0)
    {
        printf("\n\n\n\n\t\t\t\t\t**HERE YOU WILL GET ALL YOUR ANSWERS REGARDING LOAN**");
        loan();
    }
    else if (str2 == 0)
    {
        printf("\n\n\n\n\t\t\t\t\t\t:::: Thank You! And visit again ::::\n");
        strcpy(u.loantype, "NA");
        printf("\n\n\t\t\t\t\t\t\t\t\t\tLoading");
        load();
        mainmenu();
    }
    else
    {
        printf("\n\n\t\tWARNING!! Please Enter a valid Answer");
        goto start;
    }
}
void loan(void)
{
    int str3;
    char ans[5];

    fflush(stdin);
    printf("\n\n\t\t[1] Car Loan");
    printf("\n\n\t\t[2] Home Loan");
    printf("\n\n\t\t[3] Student Loan");
    printf("\n\n\t\t[4] Gold Loan");
label:
    printf("\n\n\n\tEnter a choice on the basis of above information:- ");
    scanf("%d", &u.opt);

    switch (u.opt)
    {
    case 1:
        printf("\n\n\n\t\t\t\t\t\t***Welcome to Car Loan Department***");
        printf("\n\n\n\t\t\t**Here your all confusion will be cleared**");
        printf("\n\n\t*Eligiblity criteria of Car Loan*: ");
        printf("\n\n\t\t[1] Must have 8 or above CREDIT score");
        printf("\n\n\t\t[2] Must cleared the above Loans");
        printf("\n\n\t\t[3] Must have the original bill of car");

    start2:
        printf("\n\n\n\t\t\t**Give agreement that you read and accept all the things**:\n\n\t\t\t\t\t Ans (yes/no):-  ");
        scanf("%s", ans);
        str3 = strcmp("yes", ans);
        if (str3 != 0)
        {
            printf("\n\n\t\t\tPlease type 'YES' so we can futher proceed");
            goto start2;
        }
        fflush(stdin);
        printf("\n\n\t\tEnter the customer's Age:- ");
        scanf("%d", &u.loanage);

        printf("\n\n\t\tPlease enter your CREDIT score:- ");
        scanf("%d", &u.credit);

        if (u.loanage > 60 && u.loanage < 18 && u.credit < 9)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for this Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(u.loantype, "Car Loan");
        }
        break;
    case 2:
        printf("\n\n\n\t\t\t\t\t\t**Welcome to Home Loan Department**");
        printf("\n\n\n\t\t\t**Here your all confusion will be cleared**");
        printf("\n\n\t*Eligiblity criteria of Home Loan*: ");
        printf("\n\n\t\t[1] Must have 9 or above CREDIT score");
        printf("\n\n\t\t[2] Must cleared the above Loans");
        printf("\n\n\t\t[3] Must have the Agriment letter of House");
        printf("\n\n\t\t[4] House should have minimum 4 or more than rooms");

    start3:
        printf("\n\n\n\t\t\t**Give agreement that you read and accept all the things**:\n\n\t\t\t\t\t Ans:-  ");
        scanf("%s", ans);

        str3 = strcmp("yes", ans);
        if (str3 != 0)
        {
            printf("\n\n\t\t\tPlease type 'YES' so we can futher proceed");
            goto start3;
        }
        fflush(stdin);
        printf("\n\n\t\tEnter the customer's Age:- ");
        scanf("%d", &u.loanage);

        printf("\n\n\t\tPlease enter your CREDIT score:- ");
        scanf("%d", &u.credit);

        if ((u.loanage > 60) && (u.loanage < 18) && (u.credit < 9))
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(u.loantype, "Home Loan");
        }
        break;
    case 3:
        printf("\n\n\n\t\t\t\t\t\t**Welcome to Student Loan Department**");
        printf("\n\n\n\t\t\t**Here your all confusion will be cleared**");
        printf("\n\n\t*Eligiblity criteria of Student Loan*: ");
        printf("\n\n\t\t[1] Must have 10 or above CREDIT score");
        printf("\n\n\t\t[2] Must cleared the above Loans");
        printf("\n\n\t\t[3] Must have the Student's VISA application");
        printf("\n\n\t\t[4] Must have 4 Lakhs Ruppes in your current Account");

    start4:
        printf("\n\n\n\t\t\t**Give agreement that you read and accept all the things**: Ans:-  ");
        scanf("%s", ans);

        str3 = strcmp("yes", ans);
        if (str3 != 0)
        {
            printf("\n\n\t\t\tPlease type 'YES' so we can futher proceed");
            goto start4;
        }
        fflush(stdin);
        printf("\n\n\t\tEnter the customer's Age:- ");
        scanf("%d", &u.loanage);

        printf("\n\n\t\tPlease enter your CREDIT score:- ");
        scanf("%d", &u.credit);

        if (u.loanage > 60 && u.loanage < 18 && u.credit < 10)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(u.loantype, "Student Loan");
        }
        break;
    case 4:
        printf("\n\n\n\t\t\t\t\t\t**Welcome to Gold Loan Department**");
        printf("\n\n\n\t\t\t**Here your all confusion will be cleared**");
        printf("\n\n\t*Eligiblity criteria of Car Loan*: ");
        printf("\n\n\t\t[1] Must have 8 or above CREDIT score");
        printf("\n\n\t\t[2] Must cleared the above Loans");
        printf("\n\n\t\t[3] Must have the original bill of GOLD");

    start5:
        printf("\n\n\n\t\t\t**Give agreement that you read and accept all the things**:\n\n\t\t\t\t\t Ans:-  ");
        scanf("%s", ans);

        str3 = strcmp("yes", ans);
        if (str3 != 0)
        {
            printf("\n\n\t\t\tPlease type 'YES' so we can futher proceed");
            goto start5;
        }
        fflush(stdin);
        printf("\n\n\t\tEnter the customer's Age:- ");
        scanf("%d", &u.loanage);

        printf("\n\n\t\tPlease enter your CREDIT score:- ");
        scanf("%d", &u.credit);

        if (u.loanage > 60 && u.loanage < 18 && u.credit < 9)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(u.loantype, "Gold Loan");
        }
        break;
    default:
        printf("\n\n\t\tWARNING!! Enter a valid number");
        goto label;
    }
    printf("\n\n\n:::::::::::: Loan details stored successfully ::::::::::::\n\n");
}

void logout()
{
    printf("\n\n\n\n\t\t\t\t\t\t\tThanks For Using Our Application...!!!");
    printf("\n\n\n\n\t\t\t\t\t\t\t\tHope You Liked It...\n\n\t\t\t\t\t\tPlease Provide Your Feedback on bank123@gmail.com\n\n\n");
}

void update()
{
    system("cls");
    int ch;
    FILE *fp;
    fp = fopen("signin_info.txt", "rb+");

    printf("\n\n\t\t\t--> What do you want to update?\n\n");
    printf("\n\t\t\t\t1] Name \n");
    printf("\t\t\t\t2] mobile number\n");
    printf("\t\t\t\t3] adhaar number\n");
    printf("\t\t\t\t4] address\n");
    printf("\t\t\t\t5] Birth date\n");
    printf("\t\t\t\t6] E-Pin\n");
    printf("\t\t\t\t7] Done\n");

    while (fread(&u, sizeof(u), 1, fp) == 1)
    {
        while (1)
        {
            printf("\n\n\t\t\t\tEnter your choice : ");
            fflush(stdin);
            scanf("%d", &ch);
            printf("\n");

            if (ch == 1)
            {
                printf("\t\t :) Previously stored name : ");
                printf("%s %s", u.first, u.last);
                printf("\n\n\t\t\tEnter new name :-\n");
                printf("\n\t\t\tfirst name : ");
                fflush(stdin);
                gets(u.first);
                printf("\n\t\t\tlast name : ");
                fflush(stdin);
                gets(u.last);
            }
            else if (ch == 2)
            {
                printf("\t\t :) Previously stored mobile number : ");
                printf("%s", u.mob);
                printf("\n\n\t\t\tEnter new mobile number : ");
                fflush(stdin);
                gets(u.mob);
            }
            else if (ch == 3)
            {
                printf("\t\t :) Previously stored adhaar number : ");
                printf("%s", u.aadhar);
                printf("\n\n\t\t\tEnter new adhaar number : ");
                fflush(stdin);
                gets(u.aadhar);
            }
            else if (ch == 4)
            {
                printf("\t\t :) Previously stored address : ");
                printf("%s", u.address);
                printf("\n\n\t\t\tEnter new address : ");
                fflush(stdin);
                gets(u.address);
            }
            else if (ch == 5)
            {
                printf("\t\t :) Previously stored Birth date : ");
                printf("%s", u.bday);
                printf("\n\n\t\t\tEnter new Birth date : ");
                fflush(stdin);
                gets(u.bday);
            }
            else if (ch == 6)
            {
                printf("\t\t :) Previously stored E-pin : ");
                printf("%d", u.epin);
                printf("\n\n\t\t\tEnter new Birth E-pin : ");
                fflush(stdin);
                scanf("%d", &u.epin);
            }
            else if (ch == 7)
            {
                goto end;
            }
        }
    }
end:
    fseek(fp, -(long)sizeof(u), 1);
    fwrite(&u, sizeof(u), 1, fp);
    printf("\n\t\t:::::::::::::: Record Updated Successfully ::::::::::::::\n");
    fclose(fp);
}

void deposite()
{
    system("cls");
    system("color 03");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   WELCOME TO DEPOSITE WINDOW   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    FILE *old, *bal;
    old = fopen("signin_info.txt", "rb+");
    // bal=fopen("deposite.txt","wb+");
    dep = fopen("updatedeposite.txt", "rb+");
    fscanf(dep, "%f", &balance);
    fclose(dep);
    printf("\n\n\t\t\t\t\t\t\t\tHELLO.....");
    while (fread(&u, sizeof(u), 1, old) > 0)
    {
        printf("%s", u.first);
        printf(" %s", u.last);
    }
    char s[5];
    char ch;
tryagain:
    printf("\n\n\t\t\t\tenter E-pin : ");
    fflush(stdin);
    gets(u.epin);
    FILE *fp = fopen("setpin.txt", "r");
    fgets(s, sizeof(s), fp);

    if (strcmp(s, u.epin) == 0)
    {
        printf("\n\n\t\t\t\t\t\t\t\tLoading");
        load();
        if (strcmp(u.acctype, "Fixed Deposit") == 0)
        {
            printf("\n\n\t\t\t*********************  You can't deposite in Fixed deposite account  *********************\n\n");
        }
        else
        {
            dep = fopen("updatedeposite.txt", "wb+");
            printf("\n\n\t\t\t\t\tEnter deposite amount : ");
            scanf("%f", &amount);
            balance = amount + balance;
            printf("\n\n\t\t\t\t\t ::::::: THANK YOU :::::::\n\n");
        }
        fprintf(dep, "%.2f", balance);
        fclose(dep);
    }
    else
    {
        printf("\n\t\t\t\t\t\t************ Wrong E-pin ************\n\n");
        printf("\t\t1] Forgot E-pin : press 'f'\n");
        printf("\t\t2] try again : press 't'\n");
        printf("\t\t\tyour choice : ");
        scanf("%c", &ch);
        if (ch == 'f')
        {
            resetpin();
        }
        else if (ch == 't')
        {
            goto tryagain;
        }
    }
    fclose(old);
    fclose(fp);
}

void viewbalance()
{
    FILE *dep;
    dep = fopen("updatedeposite.txt", "rb+");
    fscanf(dep, "%f", &balance);
    printf("\n\n\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<   Your Current Balance : %.2f   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>", balance);
    fclose(dep);
}
void withdraw()
{
    system("cls");
    system("color 02");
    printf("\n\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    WITHDRAW YOUR CASH HERE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    FILE *old, *bal;
    old = fopen("signin_info.txt", "rb+");
    // bal=fopen("deposite.txt","wb+");
    dep = fopen("updatedeposite.txt", "rb+");
    fscanf(dep, "%f", &balance);
    fclose(dep);
    printf("\n\n\t\t\t\t\t\t\t\tHELLO.....");
    while (fread(&u, sizeof(u), 1, old) > 0)
    {
        printf("%s", u.first);
        printf(" %s", u.last);
    }
    char s[5];
    char ch;
tryagain:
    printf("\n\n\t\t\t\tenter E-pin : ");
    fflush(stdin);
    gets(u.epin);
    FILE *fp = fopen("setpin.txt", "r");
    fgets(s, sizeof(s), fp);

    if (strcmp(s, u.epin) == 0)
    {
        printf("\n\n\t\t\t\t\t\t\t\tLoading");
        load();
        if (strcmp(u.acctype, "Fixed Deposit") == 0)
        {
            printf("\n\n\t\t\t*********************  You can't deposite in Fixed deposite account  *********************\n\n");
        }
        else
        {
            dep = fopen("updatedeposite.txt", "wb+");
           
            printf("\n\n\t\t\t\t\tEnter Withdraw amount : ");
            scanf("%f", &amount);
            if(balance-amount<1000)
            {
                viewbalance();
                printf("\n\n\t\t\t\tWithdrawal denied....Your account balance must remain greater than '1000 rs.'");
                goto withd;
            }
            balance -= amount;
            withd:
            printf("\n\n\n\n\t\t\t  :::::::::::::::::::::::::::::::::::::::: THANK YOU ::::::::::::::::::::::::::::::::::::\n\n");
        }
        fprintf(dep, "%.2f", balance);
        fclose(dep);
    }
    else
    {
        printf("\n\t\t\t\t\t\t************ Wrong E-pin ************\n\n");
        printf("\t\t1] Forgot E-pin : press 'f'\n");
        printf("\t\t2] try again : press 't'\n");
        printf("\t\t\tyour choice : ");
        scanf("%c", &ch);
        if (ch == 'f')
        {
            resetpin();
        }
        else if (ch == 't')
        {
            goto tryagain;
        }
    }
    fclose(old);
    fclose(fp);
}
