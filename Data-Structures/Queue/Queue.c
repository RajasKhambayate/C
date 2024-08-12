////////////////////////////////////////////////////////////////////////////////////////////////////
//AUTHOR      : RAJAS SANTOSH KHAMBAYATE                                                          //
//DATE        : 16 MAY 2022                                                                       //
//DAY         : MONDAY                                                                            //
//DESCRIPTION : THIS PROGRAM IS USED TO DEMONSTRATE QUEUE CONCEPTS.(DATA STRUCTURE)               //
//INPUT       : INTEGERS                                                                          //
//OUTPUT      : QUEUE[FIFO]{OF INTEGERS - NON GENERIC}                                            //
//LANGUAGE    : C PROGRAMMING LANGUAGE                                                            //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Enqueue(PPNODE head,int iValue)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));

    newnode -> data = iValue;
    newnode -> next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        PNODE temp = NULL;
        temp = *head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp -> next = newnode;
    }

    printf("Node is inserted in queue successfully.\n\n");
}

void Dequeue(PPNODE head)
{
    if(*head == NULL)
    {
        printf("Queue is already empty.\n");
        return;
    }

    PNODE temp = NULL;
    temp = *head;

    int iDeletedValue = 0;
    iDeletedValue = (*head) -> data;

    (*head) = (*head) -> next;
    free(temp);

    printf("Deleted number is : %d\n\n",iDeletedValue);
}

void Display(PNODE head)
{
    if(head == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Elements from queue are : \n");

    while(head != NULL)
    {
        printf("| %d |-> ",head -> data);
        head = head -> next;
    }

    printf("\n\n");
}

int CountNode(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
        iCnt++;
        head = head -> next;
    }

    return iCnt;
}

int main()
{
    int iNo = 0;
    char Choice = 'A';
    PNODE First = NULL;

    printf("!!WELCOME TO RAJAS QUEUE APPLICATION!!\n\n");

    printf("A : For inserting number Queue\n");
    printf("B : For deleting number from Queue\n");
    printf("C : For reviewing Queue\n");
    printf("D : For counting number of elements in Queue\n");
    printf("E : For terminating the application\n\n");

    while(Choice != 'E')
    {
        printf("Please select a choice : ");
        scanf(" %c", &Choice);

        if((Choice == 'A') || (Choice == 'a'))
        {
            printf("Enter the number to be inserted in queue : ");
            scanf("%d",&iNo);
            Enqueue(&First,iNo);
            Display(First);
        }
        else if((Choice == 'B') || (Choice == 'b'))
        {
            Dequeue(&First);
            Display(First);
        }
        else if((Choice == 'C') || (Choice == 'c'))
        {
            Display(First);
        }
        else if((Choice == 'D') || (Choice == 'd'))
        {
            int iRet = CountNode(First);
            printf("Number of elements in queue are : %d\n\n",iRet); 
        }
        else if((Choice == 'E') || (Choice == 'e'))
        {
            break;
        }
        else
        {
            printf("Invalid command\n\n");
        }
    }

    printf("!!THANKS FOR USING RAJAS QUEUE APPLICATION!!\n\n");
}