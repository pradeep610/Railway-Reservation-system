#include<stdio.h>
#include<conio.h>
#include"rlyres.h"
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>


int enterchoice()
{

    int choice,i;
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1; i<=40; i++)
    printf("_ ");
    printf("\nSelect an Option:");
    printf("\n\n1.View Trains\n2.Book Ticket\n3.View Ticket\n4.Search Ticket No\n5.View All Bookings\n6.View Train Bookings\n7.Cancel Ticket\n8.Quit");
    printf("\n\nEnter your choice:");
    scanf("%d",&choice);
    return choice;
    getch();

}
void add_trains()
{
    FILE *fp;
    fp=fopen("alltrains.txt","r");
    if(fp==NULL)
    {
        Train alltrains[10]= {{"1001","SHATABDI EXPRESS","BENGALURU","17:30","CHENNAI","22:42",900,235},{"1002","TIPPU EXPRESS","BENGALURU","15:15","MYSURU","17:45",1100,205},{"1003","RAJDHANI EXPRESS","BENGALURU","05:15","DELHI","05:35",2555,995},{"1004","RAICHUR EXPRESS","BENGALURU","09:00","RAICHUR","14:45",1175,190},{"1005","KARWAR EXPRESS","BENGALURU","19:15","KARWAR","14:15",1620,435},{"1006","CHAMUNDI EXPRESS","BENGALURU","18:15","MYSURU","21:05",1440,385},{"1007","MAS VASCO EXPRESS","BENGALURU","10:05","GOA","7:18",1250,325},{"1008","HUBLI EXPRESS","BENGALURU","07:40","HUBLI","13:30",1440,365},{"1009","DURONTO EXPRESS","BENGALURU","11:00","KOLKATA","16:45",3355,955},{"1010","HUMSAFAR EXPRESS","BENGALURU","7:30","AJMER","10:30",2445,335}};
        fp=fopen("alltrains.txt","w");
        fwrite(alltrains,10*sizeof(Train),1,fp);
        printf("File Saved Successfully!\n");
        fclose(fp);
    }
    else
    {
        fclose(fp);
    }
}
void view_trains()
{
    int i;
    printf("\nTRAIN NO\tFROM\t\tTo\t\tFIRST AC FARE\t\tSECOND AC FARE \n");
    for(i=1; i<=40; i++)
    printf("_ ");
    printf("\n");
    FILE  *fp=fopen("alltrains.txt","r");
    Train tr;
   while(fread(&tr,sizeof(tr),1,fp)==1)
{
    printf("%s\t\t%s\t%s\t\t%d\t\t\t%d\n",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
   }
    for(i=1; i<=40; i++)
    printf("_ ");
    printf("\n\n\nPress any key to go back to the main screen");
    fclose(fp);
    getch();
}

int check_train_no(char *trainno)
{

    FILE* fp=fopen("alltrains.txt","r");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

Passenger* get_passenger_datails()
{
    printf("Press 0 to exit\n");
    printf("Enter passenger name:");
    static Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        printf("Reservation Canceled!");
        return NULL;
    }
    int valid;
    printf("Enter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            printf("Reservation Cancelled!");
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            printf("Error! Gender should be M or F (in uppercase)");
            valid=0;
            getch();
        }

    }
    while(valid==0);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
        {
            printf("Reservation Canceled!");
            return NULL;
        }
        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            printf("Error! Invalid Train No,Enter again");
            getch();
        }

    }
    while(valid==0);
    printf("Enter traveling class(First AC-F/Second AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
            printf("Reservation Canceled!");
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            printf("Error! Traveling class should be F or S (in uppercase)");
            valid=0;
            getch();
        }

    }
    while(valid==0);
    printf("Enter address:");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        printf("\t\t\t\t\t\t\t\t");
        printf("Reservation Canceled!");
        return NULL;
    }
    printf("Enter age:");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
            printf("Reservation Canceled!");
            return NULL;
        }
        if(psn.age<0)
        {
            printf("Error! Age should be positive");
            valid=0;
            getch();
        }
    }
    while(valid==0);
    printf("Enter Mobile number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.mob_no);
        if(strcmp(psn.mob_no,"0")==0)
        {
            printf("Reservation Canceled!");
            return NULL;
        }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
        {
            printf("Error! Invalid Mobile No,Enter again");
            getch();
        }
    }
    while(valid==0);
    printf("Please wait!Ticket booking is under process");
    for(int i=0;i<=3;i++)
    {
     printf(".");
     Sleep(4);
    }
    return &psn;
}

int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
    {
        return 0;
    }
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
        {
            return 0;
        }
        p_mob++;
    }
   return 1;
}
int get_booked_ticket_count(char*train_no,char c)
{
    Passenger pr;
    int count=0;
    FILE*fp=fopen("allbookings.txt","r");
    if(fp==NULL)
    {
        return 0;
    }

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==c)
        {
            count++;
        }
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    Passenger pr;
    FILE*fp=fopen("allbookings.txt","r");
    if(fp==NULL)
    {
        return 0;
    }
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}

int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==30)
    {
        printf("\nAll Seats full in train no. ");
        printf("%s" ,p.train_no);
        printf(" in ");
        printf("%c",p.p_class);
        printf(" class");
        return -1;

    }
FILE *f1 = fopen("count.txt", "r");
int ticket_no;
fscanf(f1 , "%d", &ticket_no);
ticket_no = ticket_no + 1;
fclose(f1);
f1 = fopen("count.txt", "w");
fprintf(f1,"%d", ticket_no); 
fclose(f1);   

    p.ticketno=ticket_no;

    FILE *fp=fopen("allbookings.txt","a");
    if(fp==NULL)
    {
        printf("\nSorry!File can not be opened");
        return -1;

    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;

}
int accept_ticket_no()
{
    printf("Press 0 to exit\n");
    printf("Enter ticket no:");
    int valid;
    int ticket_no;
    do
    {
        scanf("%d",&ticket_no);
        valid=1;
        if(ticket_no==0)
        {
            printf("Canceling input...");
            return 0;
        }
        if(ticket_no<0)
        {
            printf("Error!Ticket number should be positive");
            valid=0;
            getch();
        }
    }while(valid==0);
    return ticket_no;
}

void view_ticket(int ticket_no)
{
    FILE*fp=fopen("allbookings.txt","r");
    FILE *fp1=fopen("alltrains.txt","r");
    if(fp==NULL)
    {
        printf("\nNo bookings done yet");
        return;
    }
    if(fp1==NULL)
    {
        printf("\nNo trains done yet");
        return;
    }
    Passenger pr;
    Train tr;

    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(ticket_no==pr.ticketno)
        {
            printf("DETAILS OF TICKET NO:");
            printf("%d\n",pr.ticketno);
            printf("\nName:");
            printf("%s",pr.p_name);
            printf("\nGENDER:");
	    printf("%c",pr.gender);
            printf("\nTRAIN NO:");
            printf("%s",pr.train_no);
            printf("\nCLASS:");
            printf("%c",pr.p_class);
            printf("\nADDRESS:");
            printf("%s",pr.address);
            printf("\nAGE:");
            printf("%d",pr.age);
            printf("\nMOBILE NO:");
            printf("%s",pr.mob_no);
            printf("\nTICKET NO:");
            printf("%d",pr.ticketno);
            while(fread(&tr,sizeof(tr),1,fp1)==1)
            {
            if(strcmp(pr.train_no,tr.train_no)==0)
            {
                 printf("\nFROM:");
                 printf("%s",tr.from);
                 printf("\nTO:");
                 printf("%s",tr.to);
                 if(pr.p_class=='F')
                 {
                     printf("\nFARE:");
                     printf("%d",tr.fac_fare);
                 }
                 else
                 {
                     printf("\nFARE:");
                     printf("%d",tr.sac_fare);
                 }
             }
             }
             fclose(fp);
             fclose(fp1);
             printf("\n\n");
             return;
             }
    }
    printf("\nNo details of ticket no ");
    printf("%d",ticket_no);
    printf(" found!");
    fclose(fp);
    printf("\n\n");
}
int cancel_ticket(int ticket_no)
{
    FILE*fp1=fopen("allbookings.txt","r");
    if(fp1==NULL)
    {
        printf("\nNo bookings done yet");
        return -1;

     }
     FILE*fp2=fopen("temp.txt","w+");
     Passenger pr;
     int found=0;
     while(fread(&pr,sizeof(pr),1,fp1)==1)
     {
         if(pr.ticketno!=ticket_no)
         {
             fwrite(&pr,sizeof(pr),1,fp2);
         }
         else
         {
             found=1;
         }

     }
     fclose(fp1);
     fclose(fp2);
     if(found==0)
     {
         remove("temp.txt");
     }
     else
     {
        remove("allbookings.txt");
        rename("temp.txt","allbookings.txt");
     }
   return found;
}
char* accept_mob_no()
{
    static char mob_no[11];
    int valid;
    printf("Press 0 to exit\n");
    printf("Enter Mobile number:");
    do
    {
        fflush(stdin);
        scanf("%s",mob_no);
        if(strcmp(mob_no,"0")==0)
        {
            printf("Canceling Input...!");
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            printf("Error! Invalid Mobile No,Enter again");
            getch();
        }
    }while(valid==0);
    return mob_no;
}
int* get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp;
    fp=fopen("allbookings.txt","r");
    if(fp==NULL)
    {
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
         ++count;
        }

    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int*p= (int *)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;

}
void view_all_tickets(char*pmob_no,int*pticket_no)
{
if(pticket_no==NULL)
{
    printf("\nSorry!No Tickets booked against mobile no. ");
    printf("%s",pmob_no);
    printf("\n\n");
    return;
}
printf("\nFollowing tickets are booked for mobile no. ");
printf("%s",pmob_no);
int i;
printf("\n\nTICKET NO:\n");
printf("---------");
for(i=0;*(pticket_no+i)!=-1;i++)
{
    printf("\n%d",*(pticket_no+i));
}
printf("\n\n");
free(pticket_no);
}

char* accept_train_no()
{
    static char train_no[10];
    int valid;
    printf("Press 0 to exit");
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
            printf("Canceling Input...!");
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            printf("Error! Invalid Train No");
            getch();
        }

    }
    while(valid==0);
    return train_no;
}
void view_bookings(char* train_no)
{

    int found=0,i;
    FILE*fp=fopen("allbookings.txt","r");
    Passenger pr;
    printf("TICKET NO\tCLASS\tNAME\t\tGENDER\tAGE\t\tMOBILE NO\n");
    for(i=1;i<=80;i++)
        printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("\n%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            printf("\t%c\t%d\t\t%s",pr.gender,pr.age,pr.mob_no);
            found=1;
        }
    }
    printf("\n");
    for(i=1;i<=80;i++)
      printf("-");
    if(!found)
    {
        printf("\nNo details of train no ");
        printf("%s",train_no);
        printf(" found!");
    }
    printf("\n\n");
    fclose(fp);
}
void view_all_bookings()
{
    int i;
    FILE*fp=fopen("allbookings.txt","r");
    if(fp==NULL)
    {
        printf("\nNo bookings done yet!\n");
        return;
    }
    Passenger pr;
    printf("TRAIN NO\tTICKET NO\tCLASS\tNAME\t\tAGE\tMOBILE NO\n");
    for(i=1;i<=80;i++)
        printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
            printf("\n%s\t\t%d\t\t%c\t%s",pr.train_no,pr.ticketno,pr.p_class,pr.p_name);
            printf("\t\t%d\t%s",pr.age,pr.mob_no);

    }
    printf("\n");
    for(i=1;i<=80;i++)
    printf("-");
    printf("\n");
    fclose(fp);
}









