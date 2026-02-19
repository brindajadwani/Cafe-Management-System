#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char name[50];
    float price;
    int food_Id_No;
    struct Item *next;
    struct Item *prev;
};

int cust_id = 1;
struct Item *head;
struct Item *last;
int Today_custmer = 0;
float total_income = 0;

struct order_hist
{
    int Customer_ID;
    int items[10][2];
    float amount;
    char date[11];
    struct order_hist *next;
    struct order_hist *prev;
};
struct order_hist *head1;
struct order_hist *last1;

struct Item *getnewNode(char a[], float p, int fin)
{
    struct Item *temp = (struct Item *)malloc(sizeof(struct Item));

    temp->food_Id_No = fin;
    strcpy(temp->name, a);
    temp->price = p;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insert(char n[], float p, int fin)
{
    struct Item *temp1 = getnewNode(n, p, fin);
    if (head == NULL)
    {
        head = temp1;
        last = temp1;
    }
    else
    {
        //to insert node at the end
        temp1->prev = last;
        last->next = temp1;
        last = temp1;
    }
}

struct order_hist *getnewNode_hist()
{
    struct order_hist *temp = (struct order_hist *)malloc(sizeof(struct order_hist));
    temp->next = temp->prev = NULL;
    return (temp);
}

void Display()
{
    printf("                                                -------------                                            \n");
    printf("-----------------------------------------------------MENU-------------------------------------------------\n");
    printf("                                                -------------                                            \n");
    printf("INDEX     ITEM NAME     PRICE\n");

    struct Item *temp = head;
    if (head == NULL)
    {
        printf("Empty");
    }

    while (temp != NULL)
    {
        printf("%d\t%s\t%f\n", temp->food_Id_No, temp->name, temp->price);
        temp = temp->next;
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}

void order()
{
    int a[10][2];
    int n, j = 0, i = 0;

    do
    {
        printf("Please enter the food ID and Quantity : ");
        for (i = 0; i < 2; i++)
        {
            scanf("%d", &a[j][i]);
        }
        j++;
        printf("Do you want to add more items  (1.Yes   2.no)  : ");
        scanf("%d", &n);
    } while (n == 1);

    float total_amount = 0.0;
    char name[25];
    char Date[10];
    printf("\nEnter your Name : ");
    scanf("%s", name);
    printf("\nEnter Today's Date : ");
    scanf("%s", Date);
    int k = 0;
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("                                          Your Order's Summmary                            \n");

    printf("Name:-%s\n", name);
    printf("Date:-%s\n", Date);

    for (k = 0; k < j; k++)
    {
        struct Item *temp = head;
        while (temp->food_Id_No != a[k][0])
        {
            temp = temp->next;
        }

        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%d\t\t%f\n", temp->food_Id_No, temp->name, a[k][1], (a[k][1] * (temp->price)));
        total_amount += (a[k][1] * (temp->price));
    }

    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("\nTotal Payble amount is:-\t\t%f\n", total_amount);
    printf("-------------------------------------------------------------------------------------------------------\n");

    struct order_hist *temp2 = getnewNode_hist();
    temp2->amount = total_amount;
    temp2->Customer_ID = cust_id++;

    int p, s;

    for (p = 0; p < j; p++)
    {
        for (s = 0; s < 2; s++)
        {
            temp2->items[p][s] = a[p][s];
        }
    }

    if (head1 == NULL)
    {
        head1 = last1 = temp2;
    }
    else
    {
        last1->next = temp2;
        temp2->prev = last1;
        last1 = temp2;
    }

    strcpy(temp2->date, Date);

    Today_custmer++;
    total_income += total_amount;
}

void display_rd_hist()
{
    printf("                                                       -------------                                                 \n");
    printf("\n-----------------------------------------------------ORDER HISTORY-------------------------------------------------\n");
    printf("                                                       -------------                                                 \n");
    printf("SR_NO     DATE      TOTAL AMOUNT\n");

    struct order_hist *temp = head1;
    if (head1 == NULL)
    {
        printf("Empty");
    }

    while (temp != NULL)
    {
        printf("%d\t%s\t%f\t\n", temp->Customer_ID, temp->date, temp->amount);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    last = NULL;

    insert("Burger    ", 80, 1);
    insert("Pizza (Large)", 235.67, 2);
    insert("Garlic Bread ", 75.83, 3);
    insert("Momos      ", 70.23, 4);
    insert("Sandwich", 70.23, 5);
    insert("Ice-cream ", 60.23, 6);
    insert("Coffee       ", 52.29, 7);
    insert("Choco Lava", 35.13, 8);
    insert("Cold Drinks", 20.13, 9);

    int choice;

    do
    {
        printf("\n");
        printf("                              WELCOME TO CAFE MANAGEMENT SYSTEM");
        printf("\n-------------------------------------------------------------------------------");
        printf("\n1.  FOOD MENU ");
        printf("\n2.  ADMIN PANEL");
        printf("\n3.  EXIT");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("");
            int ex;

            do
            {
                printf("\n1.SEE MENU  2. ORDER  -->  ");
                int n;
                scanf("%d", &n);

                switch (n)
                {
                case 1:
                    Display();
                    break;
                case 2:
                    order();
                    break;
                }

                printf("1.FOOD MENU & ORDER  2.HOME \n");
                scanf("%d", &ex);
            } while (ex == 1);
            break;

        case 2:
            printf("\n");
            int e;
            {

                do
                {
                    printf("-------------------------------------------------------------------------------------------------------\n");
                    printf("1.     ADD NEW DISH TO MENU\n");
                    printf("2.     TODAY'S  TOTAL INCOME\n");
                    printf("3.     TODAY'S TOTAL NO OF CUSTOMERS\n");
                    printf("4.     ORDER HISTORY\n");
                    printf("5      LIST OF ITEMS IN THE MENU\n");
                    printf("\n------------------------------------------------------------------------------------------------------\n");

                    int ch;
                    scanf("%d", &ch);
                    switch (ch)
                    {
                    case 1:
                        printf(" ");
                        float p;
                        int fin;
                        char n[50];

                        printf("\nEnter the name of FOOD DISH : ");
                        scanf("%s", &n);

                        printf("\nEnter the Price of Dish : ");
                        scanf("%f", &p);

                        printf("\nEnter the food_id_no of Item : ");
                        scanf("%d", &fin);

                        insert(n, p, fin);
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        printf("                 NEW DISH IS ADDED TO THE MENU.......\n");
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        printf("\n");
                        break;

                    case 2:
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        printf("        TODAY'S  TOTAL INCOME IS:- %f\n", total_income);
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        break;

                    case 3:
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        printf("        TODAY TOTAL NO OF CUSTOMER VISITED ID:-%d\n", Today_custmer);
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        break;

                    case 4:
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        printf("	                ORDER SUMMARY");
                        printf("-------------------------------------------------------------------------------------------------------\n");
                        display_rd_hist();
                        printf("\n");
                        break;

                    case 5:
                        printf("\n");
                        Display();
                        break;
                    }

                    printf("1.ADMIN PANEL\n2.MAIN MENU\n");
                    scanf("%d", &e);

                } while (e == 1);
            }
            break;
        }

    } while (choice != 3);

    return 0;
}
