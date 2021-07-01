#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
void wait(long);
void load();
void loginwindow(void);
void login(void);
void mainmenu();
void resetpass();
void setpass(void);
int checkpass();
void signin();
void showinfo();
void loanwindow();
void loan();

char pass[20], confpass[20], repass[20], loantype[15];
int credit;
struct user
{
    char first[10], last[10], address[60], pswd[20], initpswd[20], bday[10], mob[11], acctype[10], loantype[15];
    long accno, aadhar;
    int age, loanage, credit, opt;
} u;

void main()
{
    fflush(stdin);
    loginwindow();
    mainmenu();
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
    printf("\n\n\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2  BANK OF BVM  \xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t\t\t Welcome to Bank Management System\n\n\t\t\t\t\t\t    User Login \n\n");
    printf("\n\t\t\t::::::::::::  If you are new user....Sign in first ::::::::::::\n\n\n");
    printf("\t\t\t\t1. Sign in (for new user)\n\t\t\t\t2. login (for existing user)\n");
    printf("\n\t\t\t\tEnter your choice : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        signin();
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
        login();
    }
    printf("\t\t\tWait");
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
     system("cls");
    system("color F");
    int choice;
    FILE *fp=fopen("signin_info.txt","r");
     printf("\n\n\t\t\t\t\t   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  BVM CO-OPERATIVE BANK LIMITED  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    printf("\n\n\t\t\t\t\t     ::::::::::::::::::  Welcome to the Bank Application  ::::::::::::::::::\n\n\t\t\t\t\t\t\t\t  ::::::::  User Login  :::::::\n\n");
    printf("\n\n\t\t\t\t\t\tHELLO.... ");
    while (fread(&u,sizeof(u),1,fp)>0)
    {
        printf("%s",u.first);
        printf(" %s",u.last);
    }
    
    printf("\n\n\t\t\t\t\t\t\t[1].\tView Account\n");
    printf("\t\t\t\t\t\t\t[2].\tCurrent Balance\n");
    printf("\t\t\t\t\t\t\t[3].\tUpdate Account Information\n");
    printf("\t\t\t\t\t\t\t[4].\tReset Password\n");
    printf("\t\t\t\t\t\t\t[5].\tDeposite Amount\n");
    printf("\t\t\t\t\t\t\t[6].\tWithdraw Amount\n");
    printf("\t\t\t\t\t\t\t[7].\tSee Calander\n");
    printf("\t\t\t\t\t\t\t[8].\tLogout\n");

    printf("\n\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d",choice);

        switch (choice)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        
        default:
            break;
        }

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
void setpass()
{
    FILE *fp = fopen("projectpassword.txt", "a");
    printf("\n\n\t\t\tEnter Password : ");
    fflush(stdin);
    gets(pass);
    strcpy(u.initpswd, pass);
    fputs(pass, fp);
    printf("\n\t\t\tLoading");
    load();
    printf("\n\n\t\t*********************** Password set successfully ***********************\n");

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
    strcpy(u.loantype, loantype);
    u.credit = credit;
    printf("\n\n\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SIGN IN YOURSELF INTO BVM CO-OPERATIVE BANK LIMITED \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n____________________________________________________________________________________________________________________________________________________________________\n");
    printf("\n\n\n\n\t[-] Enter your First name:-  ");
    scanf("%s", u.first);

    printf("\n\n\t[-] Enter your Last name:-  ");
    scanf("%s", u.last);

    printf("\n\n\tEnter account number :-  ");
    scanf("%ld", &u.accno);

    printf("\n\n\t[-] Set  your Password:-  ");
    setpass();

error:
    printf("\n\n\t[-]Confirm your password:-  ");
    scanf("%s", confpass);
    if (strcmp(confpass, pass) != 0)
    {
        printf("\n\n\tAbove entered password does not match!! Try again");
        goto error;
    }
    else
        printf("\n\n\tPassword match");

    printf("\n\n\t[-] Enter your age:- ");
    scanf("%d", &u.age);

    printf("\n\n\t[-] Enter the Birth date :- ");
    scanf("%s", &u.bday);

    printf("\n\n\t[-] Enter your AADHAR Number:- ");
    scanf("%d", &u.aadhar);

start:
    printf("\n\n\t[-] Enter a valid mobile number:-  ");
    fflush(stdin);
    scanf("%s", &u.mob);
    if (strlen(u.mob) != 10)
    {
        printf("\n\n\t\t[WARNING!] Please enter a valid 10 digit number");
        goto start;
    }

    printf("\n\n\t[-] Enter your permenent Address and proper PINCODE of area:-  ");
    scanf(" %[^\n]%*c", &u.address);
    printf("\n\n\t:::::::::::::::: Select account type ::::::::::::::::");
    printf("\n\n\t\t[1] Saving Account");
    printf("\n\t\t[2] Salary Account");
    printf("\n\t\t[3] Fixed Deposit Account");
again:
    printf("\n\n\t[-] Enter your choice:-  ");
    scanf("%d", &choice);
    printf("\nloading");
    load();
    switch (choice)
    {
    case 1:
        printf("\n\n\t-> Saving Account selected");
        printf("\n\n\t\t**INSTRUCTIONS REGARDING SAVING ACCOUNT**");
        printf("\n\n\t[1] Customer's Account must have Rs.2000");
        printf("\n\n\t[2] Customer can make joint Account with 4 person maximun");
        printf("\n\n\t[3] Customer can apply for Debit Card after 2 months of Account Opening");
        strcpy(u.acctype, "Saving");
        break;
    case 2:
        printf("\n\n\t-> Salary Account selected");
        printf("\n\n\t[1] Customer will be given interest rate upto 2 percent");
        printf("\n\n\t[1] NO Deposit money is reuired in Salary Account");
        printf("\n\n\t[2] Customer can't make joint Account in Salary Account");
        printf("\n\n\t[3] Customer is eligible for Debit Card after 15 days after opening Account");
        strcpy(u.acctype, "Salary");
        break;
    case 3:
        printf("\n\n\t-> Fixed Deposit Account selected");
        printf("\n\n\t\t**INSTRUCTIONS REGARDING FIXED DEPOSIT ACCOUNT**");
        printf("\n\n\t\t\t[1] Customer will be given interest rate upto 2 percent");
        printf("\n\n\t\t\t[2] Customer's Account must have Rs.4000");
        printf("\n\n\t\t\t[3] Customer can't make joint Account");
        printf("\n\n\t\t\t[4] Customer is eligible for Debit Card immediately after opening the Account");
        strcpy(u.acctype, "Fixed Deposit");
        break;
    default:
        printf("\n\n\t\t\t[WARNING!]Please Enter the correct Number ");
        goto again;
        break;
    }
    ("\n_______________________________________________________________________________________________________________________\n");
    ("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t[-] Message: Congratulations!! You succesfully created Account in Bank Of BVM");

    fwrite(&u, sizeof(u), 1, fp);
    fclose(fp);
}

void showinfo()
{
    FILE *fp;
    fp = fopen("signin_info.txt", "r");
    system("cls");
    system("color 06");
    while (fread(&u, sizeof(u), 1, fp) > 0)
    {
        printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CUSTOMER'S INFORMATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        printf("\n\n\t\t\t\tCustomer's First Name              :-  -%s-", u.first);
        printf("\n\n\t\t\t\tCustomer's Last Name               :-  -%s-", u.last);
        printf("\n\n\t\t\t\tCustomer's Account Number          :-  -%s-", u.accno);
        printf("\n\n\t\t\t\tCustomer's AADHAR number           :-   %d", u.aadhar);
        printf("\n\n\t\t\t\tCustomer's Birth Year              :-   %s", u.bday);
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
    printf("\n\n\n\tHave you intrest to take Loan? Answer 'YES' or 'NO':-  ");
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
        printf("\n\n\n\n\t\t\t\tThank You! And visit again");
        strcpy(loantype, "NO Loans are taken");
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
        scanf("%d", &credit);

        if (u.loanage > 60 || u.loanage < 18 || u.credit < 9)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(loantype, "Car Loan");
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
        scanf("%d", &credit);

        if (u.loanage > 60 || u.loanage < 18 || u.credit < 9)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(loantype, "Home Loan");
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
        scanf("%d", &credit);

        if (u.loanage > 60 || u.loanage < 18 || u.credit < 10)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(loantype, "Student Loan");
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
        scanf("%d", &credit);

        if (u.loanage > 60 || u.loanage < 18 || credit < 9)
        {
            printf("\n\n\t\tOOPS!  You are not eligible for any type of Loan");
        }
        else
        {
            printf("\n\n\t\tCongrats!! You are eligible to take Loan");
            strcpy(loantype, "Gold Loan");
        }
        break;
    default:
        printf("\n\n\t\tWARNING!! Enter a valid number");
        goto label;
    }
}
