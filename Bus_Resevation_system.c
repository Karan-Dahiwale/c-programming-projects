#include<stdio.h>
#include <stdlib.h>
#include<string.h>
char bus[10][130] ={"Sanjay Travels","Vijayant Travels","IntrCity SmartBus","VRL Travels"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void login();
void bus_list();
void name_number(int booking,char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();
#define MAX_SEATS 32
#define SEATS_PER_ROW 4
#define TICKET_PRICE 200  
#define DEFAULT_SEATS 40

void login() {
    char u[20];
    char p[20];
    int attempts = 3;  

    while (attempts > 0) {
        printf("================= Enter Username and Password ================= \n");
        printf("1) Username: ");
        scanf("%s", u);
        printf("2) Password: ");
        scanf("%s", p);

        if (strcmp(u, "user") == 0 && strcmp(p, "pass") == 0) {
            printf("\n\n\nWELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\tPress Enter to continue...");
            getchar();  // Consume newline left by scanf
            getchar();  
            return;  // Exit the function if login is successful
        } else {
            attempts--;
            printf("\nSORRY !!!! LOGIN IS UNSUCCESSFUL. You have %d attempts remaining.\n", attempts);
        }
    }

    printf("\nToo many failed attempts. Exiting the program.\n");
    exit(1);  // Terminate the program if login fails after 3 attempts
}


void bus_list(){

   #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
   printf("\n\n\n");
   printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");

   printf("\t\t\t1) %s",bus[0]);
   printf("\n");

   printf("\t\t\t2) %s",bus[1]);
   printf("\n");

   printf("\t\t\t3) %s",bus[2]);
   printf("\n");

   printf("\t\t\t4) %s",bus[3]);
   printf("\n");

}

void booking()
{
    int i = 0;
    char numstr[100];
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering bus number
    bus_list();//for seeing bus list
    printf("Enter the Bus number:--->");
    scanf("%d", &trno);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting seat
    printf("Your Bus Number is %d ********** %s", trno, bus[trno - 1]);
    status_1(trno);

    FILE *f1;
    char str1[10] = "32";  
    int seat1, booking = 0;

    
    char filename[10];
    sprintf(filename, "tr%d.txt", trno);

    
    f1 = fopen(filename, "r");
    if (f1 != NULL) {
        if (fgets(str1, sizeof(str1), f1) == NULL) {
            strcpy(str1, "32");  
        }
        fclose(f1);
    } else {
        
        f1 = fopen(filename, "w");
        if (f1 != NULL) {
            fputs("32", f1);
            fclose(f1);
        }
    }

    seat1 = atoi(str1); 
    if (seat1 <= 0)
    {
        printf("There are no available seats on this bus.\n");
    }
    else
    {
        printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n", seat1);
        printf("\n\t\t\t\tNumber of Tickets:----->");
        scanf("%d", &booking);

        if (booking > seat1 || booking <= 0) {
            printf("Invalid number of tickets. Please try again.\n");
            return;
        }

        seat1 = seat1 - booking;
        itoa(trno, numstr, 10);
        name_number(booking, numstr);
        printf("\n\t\t\t\tThe Total booking amount is %d", TICKET_PRICE * booking);

       
        f1 = fopen(filename, "w");
        if (f1 != NULL) {
            fprintf(f1, "%d", seat1);
            fclose(f1);
        }
    }
}




void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");
   b = fopen(tempstr2,"a");
for(i=0; i<booking; i++)
{
    printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
      printf("\t\t\t\tEnter the seat number:--->");
      scanf("%d",&number);
      printf("\t\t\t\tEnter the name of person:--->");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}


int read_number(int trno) 
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a;
    char numstr[100];
    int i = 0, j = 0, k;
    char ch;

    
    sprintf(numstr, "%d.txt", trno);
    strcat(tempstr2, numstr);

    
    a = fopen(tempstr2, "a+");
    if (a == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    
    while ((ch = fgetc(a)) != EOF) 
    {
        if (ch == ' ')  
        {
            number[i][j] = '\0'; 
            j = 0;
            i++;
        } 
        else 
        {
            number[i][j] = ch;
            j++;
        }
    }

    k = i;

    
    for (i = 0; i < k; i++) 
    {
        num1[i] = atoi(number[i]);
    }

    fclose(a);
    return k;
}
void read_name(int trno)
{
    char tempstr1[20] = "status";
    FILE *b;
    char numstr[10];
    int i = 0, j = 0;
    char ch;

    
    sprintf(numstr, "%d.txt", trno);
    strcat(tempstr1, numstr);

   
    b = fopen(tempstr1, "a+");
    if (b == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    
    while ((ch = fgetc(b)) != EOF)
    {
        if (ch == ' ')  
        {
            name[i][j] = '\0'; 
            i++; 
            j = 0; 
        }
        else
        {
            name[i][j] = ch;
            j++;
        }
    }

   
    if (j > 0) 
        name[i][j] = '\0';

    fclose(b);
}




void status()
{
   
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    bus_list();
    int i, trno, index = 0, j;
    printf("Enter the number of bus:---->");
    scanf("%d", &trno);
    j = read_number(trno);
    read_name(trno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n", trno, bus[trno - 1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[MAX_SEATS + 1][20]; 
    for (i = 0; i <= MAX_SEATS; i++)
        strcpy(tempname[i], "Empty ");
    for (i = 0; i < j; i++)
    {
        if (num1[i] > 0 && num1[i] <= MAX_SEATS)  
        {
            strncpy(tempname[num1[i]], name[i], sizeof(tempname[0]) - 1);
            tempname[num1[i]][sizeof(tempname[0]) - 1] = '\0';  
        }
    }

   
    for (i = 0; i < MAX_SEATS / SEATS_PER_ROW; i++)  
    {
        printf("\t\t\t\t");
        for (j = 0; j < SEATS_PER_ROW; j++)  
        {
            printf("%2d.%-10s\t", index + 1, tempname[index + 1]); 
            index++;
        }
        printf("\n");
    }
}



void status_1(int trno)
{
    printf("Your Bus Number is %d /// %s ///",trno,bus[trno-1]);
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    bus_list();
    int i, index = 0, j;
    j = read_number(trno);
    read_name(trno);
    char tempname[MAX_SEATS + 1][20];  
    for (i = 0; i <= MAX_SEATS; i++)
        strcpy(tempname[i], "Empty ");
    for (i = 0; i < j; i++)
    {
        if (num1[i] > 0 && num1[i] <= MAX_SEATS)  
        {
            strncpy(tempname[num1[i]], name[i], sizeof(tempname[0]) - 1);
            tempname[num1[i]][sizeof(tempname[0]) - 1] = '\0';  
        }
    }
    for (i = 0; i < MAX_SEATS / SEATS_PER_ROW; i++)  
    {
        printf("\t\t\t\t");
        for (j = 0; j < SEATS_PER_ROW; j++)  
        {
            printf("%2d.%-10s\t", index + 1, tempname[index + 1]);  
            index++;
        }
        printf("\n");
    }
}
void cancle() {
    int seat_no, i, found = 0;
    char numstr[10], seatFile[20], statusFile[20];
    
    bus_list();
    
    printf("Enter the bus number: ");
    if (scanf("%d", &trno) != 1 || trno < 1 || trno > 5) {
        printf("Invalid bus number! Please enter a valid number (1-5).\n");
        return;
    }
    
    sprintf(numstr, "%d", trno);
    sprintf(seatFile, "number%s.txt", numstr);
    sprintf(statusFile, "status%s.txt", numstr);

    read_number(trno);
    read_name(trno);
    status_1(trno);

    printf("Enter the seat number: ");
    if (scanf("%d", &seat_no) != 1) {
        printf("Invalid seat number! Please enter a valid number.\n");
        return;
    }

    FILE *a = fopen(statusFile, "w");
    FILE *b = fopen(seatFile, "w");

    if (!a || !b) {
        printf("Error opening files!\n");
        if (a) fclose(a);
        if (b) fclose(b);
        return;
    }

    for (i = 0; i < MAX_SEATS; i++) {
        if (num1[i] == seat_no) {
            found = 1;  
            strcpy(name[i], "Empty");
            num1[i] = 0;  
        }
    }

    for (i = 0; i < MAX_SEATS; i++) {
        if (num1[i] != 0) {
            fprintf(b, "%d ", num1[i]);  
            fprintf(a, "%s ", name[i]);  
        }
    }

    fclose(a);
    fclose(b);

    if (!found) {
        printf("Seat number %d is not booked or does not exist.\n", seat_no);
        return;
    }

    printf("Cancellation successful! Seat number %d is now available.\n", seat_no);
}


int main() {
   int num;

   login();

   do {
         #ifdef _WIN32
            system("cls");
         #else
            system("clear");
         #endif
         printf("\n====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n");
         printf("\t\t\t\t[1] View Bus List\n");
         printf("\t\t\t\t[2] Book Tickets\n");
         printf("\t\t\t\t[3] Cancel Booking\n");
         printf("\t\t\t\t[4] Bus Status Board\n");
         printf("\t\t\t\t[5] Exit\n");
         printf("===============================================================================================================\n");
         printf("\t\t\tEnter Your Choice: ");
         if (scanf("%d", &num) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); 
            continue;
         }
         switch (num) {
            case 1:
               bus_list(); 
               break;
            case 2:
              booking();  
               break;
            case 3:
               cancle();
               break;
            case 4:
               status(); 
               break;
            case 5:
               printf("\nThank you for using the Bus Reservation System. Goodbye!\n");
               exit(0);
            default:
               printf("Invalid choice! Please enter a number between 1 and 5.\n");
         }

         printf("\nPress Enter to continue...");
         getchar(); 
         getchar(); 

   } while (1);
}

