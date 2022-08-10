#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char movie_name1[50];
int movie_code1;
char description1[100];
int ticket_price1;
char date1[];
char time1[];

char movie_name2[50];
int movie_code2;
char description2[100];
int ticket_price2;
char date2[];
char time2[];

char cs_movie_name[50];
int cs_movie_code;
int cs_ticket_price;
char cs_description[100];

int movie_enter;
int select_movie;

int sub_choice1;
int sub_choice2;
int sub_choice3;
int sub_choice4;


char customer_name[20];
int customer_mobile_number;
int no_of_tickets;
int ticket_total_price;
int total_tickets1;
int total_tickets2;
int sold_tickets1 = 0;
int sold_tickets2 = 0;

int cancel_booking;
int choose_movie;
int book_movie;

int payment1;
int payment2;
int card_number;
int confirmation;
int mobile_payment;


int main()
{
  loginpanel();

  return 0;
}




void loginpanel()
{
  int choice;

  {
    printf("\n\t------Welcome-------\n");
    printf("\n\tLogin Here\n");
    printf("\t1.Login\n");
    printf("\t2.Booking\n");
    printf("\t3.Exit \n");
    scanf("%d",&choice);


    switch(choice)
    {
       case 1:
        login();
        break;

       case 2:
        customer_menu();
        break;

       case 3:
        printf("\t Exit \n");
        break;

       default:
        printf("Invalid Choice\n");

        return loginpanel();

    }

  }


}

char username[20];
char password[20];

void login()
{
        printf("\t Username : ");
        scanf("%s", &username);

        printf("\t Password : ");
        scanf("%s", &password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0)
            {
                printf("\n\t Login Successful\n\n");

                return admin_panel();
            }

        else
          {
            printf("\t Login Failed! Try again\n");

            return login();
          }

}

void admin_panel()
{
        printf("\n\t---ADMIN PANEL---\n\n");
        printf("\t1. Add Now Showing Movie Records \n");
        printf("\t2. Add Up-coming movie Records \n");
        printf("\t3. View User Details \n");
        printf("\t4. Exit to main menu \n");
        scanf("%d", &sub_choice1);


        switch(sub_choice1)
        {
        case 1:

            printf("\n\t1. Enter Movie No 1 Details : \n");
            printf("\n\t2. Enter Movie No 2 Details : \n");
            scanf("%d", &movie_enter);

            switch (movie_enter)
            {
            case 1:
                movie_no_1();
                return admin_panel();
                break;

            case 2:
                movie_no_2();
                return admin_panel();
                break;
            }

            break;

        case 2:

            printf("\n\t*Movie Name :");
            scanf("%s",&cs_movie_name);

            printf("\n\t*Description :");
            scanf("%s",&cs_description);

            printf("\n\tMovie name : %s \n\tDescription: %s \n",cs_movie_name,cs_description);

            return admin_panel();

            break ;

        case 3:

            return user_details();

            break;

        case 4:

            return loginpanel();

            break;

            default :

                printf("Not valid !");

                return admin_panel();

        }

}

void customer_menu()
{

        printf("\n\t---CUSTOMER MENU---\n\n");
        printf("\t1. Now Showing \n");
        printf("\t2. Coming Soon \n");
        printf("\t3. Buy Tickets \n");
        printf("\t4. Transactions \n");
        printf("\t5. Exit to Main Menu \n");

        scanf("%d", &sub_choice2);


        switch(sub_choice2)
        {
        case 1:
            printf("\n\tMovie name : %s \n\tDescription: %s \n\tShowing Date:%s \n\tTime : %s \n\tTicket Price :%d\n",movie_name1,description1,date1,time1,ticket_price1);

            return customer_menu();

            break;


        case 2:

            printf("\n\tAvengers(2019)");
            printf("\n\tSpiderMan(2019)");
            printf("\n\tIronMan2(2010)");
            printf("\n\t%s \n",cs_movie_name);

            return customer_menu();


            break ;


        case 3:

            printf("\n\t1. %s\n", movie_name1);
            printf("\n\t2. %s\n", movie_name2);

            scanf("%d", &select_movie);

            switch(select_movie)
            {
            case 1:
                book_movie_1();
                break;
            case 2:
                book_movie_2();
                break;

            default:
                printf("\n\tError check details again\n");
            }

            break;

        case 4:
            return transaction();
            break;

        case 5:
            return loginpanel();
            break;

        default :
            printf("Not valid !");
            return customer_menu();
        }

}

void movie_no_1()
{
        printf("\n\t*Movie Name :");
        scanf("%s",&movie_name1);

        printf("\n\t*Description (Use underscore for space):");
        scanf("%s",&description1);

        printf("\n\t*Showing Date :");
        scanf("%s",&date1);

        printf("\n\t*Showing time :");
        scanf("%s",&time1);

        printf("\n\t*Ticket Price:");
        scanf("%d",&ticket_price1);

        printf("\n\t*Enter Total Ticket Quantity : ");
        scanf("%d", &total_tickets1);

        printf("\n\tMovie name : %s \n\tDescription: %s \n\tShowing Date:%s \n\tShowing Time: %s \n\tTicket Price :%d \n\tTotal Tickets : %d \n",movie_name1,description1,date1,time1,ticket_price1,total_tickets1);

}

void movie_no_2()
{
        printf("\n\t*Movie Name :");
        scanf("%s",&movie_name2);

        printf("\n\t*Description (Use underscore for space):");
        scanf("%s",&description2);

        printf("\n\t*Showing Date :");
        scanf("%s",&date2);

        printf("\n\t*Showing time :");
        scanf("%s",&time2);

        printf("\n\t*Ticket Price:");
        scanf("%d",&ticket_price2);

        printf("\n\t*Enter Total Ticket Quantity : ");
        scanf("%d", &total_tickets2);

        printf("\n\tMovie name : %s \n\tDescription: %s \n\tShowing Date:%s \n\t Showing Time: %s \n\tTicket Price :%d \n\t Total Tickets : %d \n",movie_name2,description2,date2,time2,ticket_price2,total_tickets2);

}


void book_movie_1()
{

		printf("\n\tEnter Customer Name: ");
		scanf("%s",&customer_name);

		printf("\tEnter Customer Phone Number: ");
		scanf("%d",&customer_mobile_number);

		printf("\tEnter No of Tickets: ");
		scanf("%d",&no_of_tickets);

        if (no_of_tickets <= 10)
            {
                ticket_total_price = no_of_tickets*ticket_price1;
                sold_tickets1 = sold_tickets1 + no_of_tickets;

                printf("\n\tName: %s \n\tMobile number: %d \n\tNo of tickets: %d \n\tTotal Price %d",customer_name,customer_mobile_number,no_of_tickets,ticket_total_price);
                printf("\n\tThis is the Sold Tickets : %d \n\tThis is the Total Tickets : %d \n", sold_tickets1, total_tickets1);

                return customer_menu();
            }


        else
            {
                printf("\n\tError! maximum ticket limit is reached( Maximum is 10)...\n");

                return customer_menu();
            }

}

void book_movie_2()
{

		printf("\n\tEnter Customer Name: ");
		scanf("%s",&customer_name);

		printf("\tEnter Customer Phone Number: ");
		scanf("%d",&customer_mobile_number);

		printf("\tEnter No of Tickets: ");
		scanf("%d",&no_of_tickets);

        if (no_of_tickets <= 10)
            {
                ticket_total_price = no_of_tickets*ticket_price2;
                sold_tickets2 = sold_tickets2 + no_of_tickets;

                printf("\n\tName: %s \n\tMobile number: %d \n\tNo of tickets: %d \n\tTotal Price %d",customer_name,customer_mobile_number,no_of_tickets,ticket_total_price);
                printf("\n\tThis is the Sold Tickets : %d \n\tThis is the Total Tickets : %d \n", sold_tickets2, total_tickets2);

                return customer_menu();
            }


        else
            {
                printf("\n\tError! maximum ticket limit is reached( Maximum is 10)...\n");

                return customer_menu();
            }

}

void transaction()
{
        printf("\t1. View Customer Bookings \n");
        printf("\t2. Cancel Customer Bookings  \n");
        printf("\t3. Exit to Main Menu \n");

        scanf("%d", &sub_choice3);


        switch(sub_choice3)
        {
        case 1:
            printf("\n\tName: %s \n\tMobile number: %d \n\tNo of tickets: %d \n\tTotal Price %d",customer_name,customer_mobile_number,no_of_tickets,ticket_total_price);
            payment_method();

            return transaction();

            break;


        case 2:
            printf("\tYour Transactions");
            printf("\n\tName: %s \n\tMobile number: %d \n\tNo of tickets: %d \n\tTotal Price %d",customer_name,customer_mobile_number,no_of_tickets,ticket_total_price);
            printf("\tDo you want to cancel your Booking ?\n");
            printf("\tPress 1-YES \n\t Press 2-NO\n");
            scanf("%d",&cancel_booking);
                      switch(cancel_booking)
                      {
                      case 1:
                        printf("\n\tYour Booking Cancel is successful \n");
                        return transaction();
                        break;

                      case 2:
                        printf("\n\tReturning to Main Menu\n");
                        return customer_menu();
                        break;

                      default :
                        printf("\n\tInvalid Input !\n");
                        return transaction();
                      }

            break ;


        case 3:
            return customer_menu();
            break;

        default :
            printf("Not valid !");
            return transaction();
        }

}

void user_details()
{

   printf("\n\t1.User Details\n");
   printf("\n\t2.User Transactions\n");
   printf("\n\t3.Exit to Admin Panel\n");

   scanf("%d",&sub_choice4);

        switch(sub_choice4)
        {
        case 1:
            printf("\n\tUser name: %s \n\tUser mobile number : %d",customer_name,customer_mobile_number);
            return user_details();

            break;

        case 2:
            printf("\n\tName: %s \n\tMobile number: %d \n\tNo of tickets: %d \n\tTotal Price %d",customer_name,customer_mobile_number,no_of_tickets,ticket_total_price);
            return user_details();

            break;

        case 3:
            return admin_panel();

        default:
            printf("\n\tInvalid Input");

            return user_details();

        }
}

void nowshowing()

{
    printf("\n\tChoose The Movie\n");

    printf("\n\t1.%s\n",movie_name1);
    printf("\n\t2.%s\n",movie_name2);
    printf("\n\t3. Exit\n");

    scanf("%d",&choose_movie);

       switch(choose_movie)
       {
       case 1:
           printf("\n\tMovie Name : %s", movie_name1);
           printf("\n\tPress 1 to book the movie\n");
           printf("\n\tPress 2 to goback\n");
           scanf("%d",&book_movie);
             switch(book_movie)
             {
             case 1:
                return book_movie_1();
                break;

             case 2:
                return nowshowing();
                break;

             case 3:
                return customer_menu();
                break;

             default :
                printf("\n\t Invalid Input");
                return nowshowing();
             }
            break;

       case 2:
        printf("\n\tMovie Name : %s", movie_name2);
        printf("\n\tPress 1 to book the movie\n");
        printf("\n\tPress 2 to goback\n");
        scanf("%d",&book_movie);
            switch(book_movie)
             {
             case 1:
                return book_movie_2();

                break;

             case 2:
                return nowshowing();
                break;

             case 3:
                return customer_menu();
                break;

             default :
                printf("\n\t Invalid Input");
                return nowshowing();
             }
            break;

       case 3 :
           return customer_menu();
           break;

       default :
           printf("\t\n Invalid Input !\n");
           return nowshowing();
       }
}

void payment_method()
{
    printf("\n\tChoose Your payment method \n");
    printf("\n\t1.Visa/Master Card\n");
    printf("\n\t2.From Mobile Bill\n");
    printf("\n\t3.Exit to the Transactions\n ");

    scanf("%d",&payment1);

    switch(payment1)
    {
    case 1:
        printf("\n\tEnter your card number :");
        scanf("%d",&card_number);

        printf("\n\tConfirm Your Number :");
        printf("\n\tPress 1 to Confirm \n\tPress 2 to Decline\n");
        printf("\n\t3.Exit to the Transactions\n ");

        scanf("%d",&confirmation);

           switch(confirmation)

           {
            case 1:
                printf("\n\tYour Payment Successful \n");
                return customer_menu();

                break;

            case 2:
                printf("\n\tYour payment Declined \n");
                return payment_method();

                break;

            case 3:
                return transaction();
                break;

            default :
                printf("\n\t Invalid Input \n");

           }

    case 2:
         printf("\n\t Enter Your Mobile Number : ");
         scanf("%d",&mobile_payment);

         printf("\n\tConfirm Your Number : ");
         printf("\n\tPress 1 to Confirm : \n\tPress 2 to Decline : \n");
         printf("\n\t3.Exit to the Transactions\n ");

         scanf("%d",&confirmation);

           switch(confirmation)

           {
           case 1:
                printf("\n\tYour Payment Successful \n");
                return customer_menu();
                break;

           case 2:
                printf("\n\tYour payment Declined \n");
                return payment_method();
                break;

            case 3:
                return transaction();
                break;

            default :
                printf("\n\t Invalid Input");


         }

        case 3:
            return transaction();
            break;


        default:
            printf("\n\tInvalid Login");

    }

}

