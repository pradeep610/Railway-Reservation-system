#include <stdio.h>
#include<ctype.h>
#include<io.h>
#include <stdlib.h>
#include<conio.h>
#include"rlyres.h"
#include<string.h>
#include<windows.h>

int main()

{
    Passenger *ptr;
    int ch;
    int ticket_no;
    int result;
    add_trains();
    char*pmob_no;
    int *pticket_no;
    char *ptrain_no;
    char username[20];
    char pwd[15];
    int i;
    new:
    for(i=1;i<=30;i++)
    printf("-");
    printf("RAILWAY RESERVATION SYSTEM");
    for(i=1;i<=30;i++)
    printf("-");
    printf("\n\t\t\t\t:::::LOGIN:::::\n");
    printf("\nENTER USERNAME: ");
    scanf("%s",username);
    printf("\nENTER PASSWORD: ");
    scanf("%s",pwd);

    printf("\n\n\n\n\tPassword Verification Under process.Please wait!........");
    Sleep(4);
    if((strcmp(username,"Railway")==0)&&(strcmp(pwd,"1234")==0))
    {

    }
    else
    {
        system("cls");
        printf("\n\nIncorrect! User-name or Password. ");
        printf("\n\nPress any key to re-login");
        getch();
        system("cls");
        goto new;
    }
    system("cls");
    while(1)
     {
     system("cls");
     ch=enterchoice();
     if(ch==8)
     {
         exit(0);
     }
     else
     {
         switch(ch)
         {
         case 1:
             view_trains();
             system("cls");
            break;
         case 2:
             ptr=get_passenger_datails();
             if(ptr!=NULL)
             {
               ticket_no=book_ticket(* ptr);
               if(ticket_no==-1)
               {
                printf("\n\nBooking Failed!");
               }
               else
               {
                printf("\nCongratulations! You have Successfully Booked a Ticket.\n");
                printf("\nYour ticket no is ");
                printf("%d\n\n",ticket_no);
               }
            }
            printf("\nPress any key to go back to the main screen");
            getch();
           system("cls");
             break;
         case 3:
            system("cls");
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            view_ticket(ticket_no);
            printf("\nPress any key to go back to the main screen");
            getch();
            system("cls");
            break;
         case 4:
            system("cls");
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            printf("\nPress any key to go back to the main screen");
            getch();
            system("cls");
           break;
         case 5:
            system("cls");
            view_all_bookings();
            printf("\nPress any key to go back to the main screen");
            getch();
            system("cls");
            break;
         case 6:
               system("cls");
             ptrain_no=accept_train_no();
             if(ptrain_no!=NULL)
             {
                 view_bookings(ptrain_no);
             }
             printf("\nPress any key to go back to the main screen");
             getch();
             system("cls");
            break;
         case 7:
             system("cls");
             ticket_no=accept_ticket_no();
             if(ticket_no!=0)
             {
                result=cancel_ticket(ticket_no);
                if(result==0)
                {
                         printf("\nSorry! No tickets booked against ticket no ");
                         printf("%d\n\n",ticket_no);
                }
                else if(result==1)
                {
                        printf("\nTicket no ");
                        printf("%d",ticket_no);
                        printf(" successfully canceled!\n\n");
                }

             }
            printf("\nPress any key to go back to the main screen");
            getch();
            system("cls");
            break;
         default:
            printf("\nWrong Choice! Try Again.");
            getch();
            system("cls");

         }
     }
 }
     getch();
     return 0;
}
