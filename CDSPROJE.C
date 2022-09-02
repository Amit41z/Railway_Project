#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
char name[50];
int age;
int train_num;
int num_of_seats;
}pd;
void reservation(void); //main reservation function
void viewdetails(void); //view details of all the trains
void cancel(void);
void printticket(char name[],int,int,int,float); //print ticket
void specifictrain(int); //print data related to specific train
float charge(int,int); //charges automatically w.r.t number of seats and train
void login();
int main()
{
int menu_choice,choice_return;
system("cls");
printf("\t\t|===============================================|\n");
printf("\t\t|                                               |\n");
printf("\t\t|         -----------------------------         |\n");
printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
printf("\t\t|         -----------------------------         |\n");
printf("\t\t|                                               |\n");
printf("\t\t|                               	        |\n");
printf("\t\t|                                               |\n");
printf("\t\t|                  PROJECT BY                   |\n");
printf("\t\t|             ||AMIT KUMAR GHOSH||              |\n");
printf("\t\t|===============================================|\n");
getch();
system("cls");
login();
start:
system("cls");
printf("\n=================================\n");
printf(" TRAIN RESERVATION SYSTEM");
printf("\n=================================");
printf("\n1>>Reserve A Ticket");
printf("\n------------------------");
printf("\n2>>View All Available Trains");
printf("\n------------------------");
printf("\n3>>Cancel Reservation");
printf("\n------------------------");
printf("\n4>>Exit");
printf("\n------------------------");
printf("\n\n-->");
scanf("%d",&menu_choice);
switch(menu_choice)
{
case 1:
reservation();
break;
case 2:
viewdetails();
printf("\n\nPress any key to go to Main Menu..");
getch();
break;
case 3:
cancel();
break;
case 4:
return(0);
default:
printf("\nInvalid choice!!!");
}
goto start;
}
void viewdetails(void)
{
system("cls");
printf("-----------------------------------------------------------------------------");
printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
printf("-----------------------------------------------------------------------------");
printf("\n1001\tRAJDHANIEXPRESS\t\tMUMBAIToDELHI\t\tRs.4900\t\t9am");
printf("\n1002\tHOWRAH DURONTO EXPRESS\tPUNE ToJAMSHEDPUR\tRs.3000\t\t3pm");
printf("\n1003\tNETAJIEXPRESS\t\tDELHIToKOLKATA\t\tRs.3500\t\t8am");
printf("\n1004\tGUJARAT EXPRESS\t\tAHMEDDABAD ToMUMBAI\tRs.2500\t\t11am");
printf("\n1005\tG-YSFEXPRESS\t\tLUCNOWToBENGALURU\tRs.4000\t\t7am");
}
void reservation(void)
{
char confirm;
float charges;
pd passdetails;
FILE*fp;
fp=fopen("seats_reserved.txt","a");
system("cls");
printf("\nEnter Your Name:>");
fflush(stdin);
gets(passdetails.name);
//errorherehavetotakeinputofthename
printf("\nEnter Your Age:>");
scanf("%d",&passdetails.age);
printf("\nEnter Number of seats:>");
scanf("%d",&passdetails.num_of_seats);
printf("\n\n>>Press Enter To View Available Trains<<");
getch();
system("cls");
viewdetails();
printf("\n\nEnter train number:>");
start1:
scanf("%d",&passdetails.train_num);
if(passdetails.train_num>=1001&&passdetails.train_num<=1005)
{
charges=charge(passdetails.train_num,passdetails.num_of_seats);
printticket(passdetails.name,passdetails.age,passdetails.num_of_seats,passdetails.train_num,charges);
}
else
{
printf("\nInvalid Train Number!Enter again-->");
goto start1;
}
printf("\n\nConfirm Ticket(y/n):>");
start:
scanf("%c",&confirm);
if(confirm=='y')
{
fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.age,passdetails.num_of_seats,passdetails.train_num,charges);
printf("==================");
printf("\nReservation Done\n");
printf("==================");
printf("\nPress any key to go back to Main menu");
}
else
{
if(confirm=='n'){
printf("\nReservation Not Done!\nPress any key to go back to Main menu!");
}
else
{
printf("\nInvalid choice entered!Enter again----->");
goto start;
}
}
fclose(fp);
getch();
}
float charge(int train_num,int num_of_seats)
{
if(train_num==1001)
{
return(4900.0*num_of_seats);
}
if(train_num==1002)
{
return(3000.0*num_of_seats);
}
 if(train_num==1003)
{
return(3500.0*num_of_seats);
}
if(train_num==1004)
{
return(2500.0*num_of_seats);
}
if(train_num==1005)
{
return(4000.0*num_of_seats);
}
else
{
return 0;
}
}
void printticket(char name[],int age,int num_of_seats,int train_num,float charges)
{
system("cls");
printf("-------------------\n");
printf("\tTICKET\n");
printf("-------------------\n\n");
printf("Name:\t\t\t%s",name);
printf("\nAge:\t\t\t%d",age);
printf("\nNumberOfSeats:\t%d",num_of_seats);
printf("\nTrainNumber:\t\t%d",train_num);
specifictrain(train_num);
printf("\nCharges:\t\t%.2f",charges);
}
void specifictrain(int train_num)
{
if(train_num==1001)
{
printf("\nTrain:\t\t\tRAJDHANIEXPRESS");
printf("\nDestination:\t\tMUMBAIToDELHI");
printf("\nDeparture:\t\t9am");
}
if(train_num==1002)
{
printf("\nTrain:\t\t\tHOWRAHDURONTOEXPRESS");
printf("\nDestination:\t\tJAMSHEDPURTOPUNE");
printf("\nDeparture:\t\t3pm");
}
if(train_num==1003)
{
printf("\nTrain:\t\t\tNETAJIEXPRESS");
printf("\nDestination:\t\tDELHITOKOLKATA");
printf("\nDeparture:\t\t8am");
}
if(train_num==1004)
{
printf("\nTrain:\t\t\tGUJARATEXPRESS");
printf("\nDestination:\t\tAHMEDABADTOMUMBAI");
printf("\nDeparture:\t\t11am");
}
if(train_num==1005)
{
printf("\nTrain:\t\t\tGORAKHPUR-YESVANTPURSFEXPRESS");
printf("\nDestination:\t\tLUCKNOWTOBENGALURU");
printf("\nDeparture:\t\t7am");
}
}
void login()
{
int a=0,i=0;
char uname[10],c=' ';
char pword[10],code[10];
char user[10]="user";
char pass[10]="pass";
do
{
printf("\n ======================= LOGIN FORM=======================\n ");
printf("\n ENTER USER NAME:-");
scanf("%s",&uname);
printf("\n ENTER PASSWORD:-");
while(i<10)
{
pword[i]=getch();
c=pword[i];
if(c==13)break;
else
printf("*");
i++;
}
pword[i]='\0';
//charcode=pword;
 i=0;
//scanf("%s",&pword);
if(strcmp(uname,user)==0&&strcmp(pword,pass)==0)
{
printf(" \n\n\n WELCOME TO OUR SYSTEM !!YOUR LOGIN IS SUCCESSFUL");
printf("\n\n\n\t\t\t\tPress any key to continue...");
getch();//holdsthescreen
break;
}
else
{
printf("\n SORRY!!!! LOGIN IS UNSUCCESSFUL");
a++;
getch();//holdsthescreen
system("cls");
}
}
while(a<=2);
if(a>2)
{
printf("\nSorry you have entered the wrong username and password for four times!!!");
getch();
}
system("cls");
}
void cancel(void)
{
int trainnum;
system("cls");
printf("-----------------------\n");
printf("Enter the train number:\n");
printf("-----------------------\n");
fflush(stdin);
scanf("%i",&trainnum);
printf("\n\nCancelled");
getch();
}