////////////////////////////////////////////////////////////////////////////////////////////////////
//AUTHOR      : RAJAS SANTOSH KHAMBAYATE                                                          //
//DATE        : 16 MAY 2022                                                                       //
//DAY         : MONDAY                                                                            //
//DESCRIPTION : THIS PROGRAM IS USED TO DEMONSTRATE STACK CONCEPTS.(DATA STRUCTURE)               //
//INPUT       : INTEGERS                                                                          //
//OUTPUT      : STACK[FILO]{OF INTEGERS - NON GENERIC}                                            //
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

void Push(PPNODE head,int iValue)
{
    PNODE newnode = NULL;

    newnode = (PNODE)malloc(sizeof(NODE));

    newnode -> data = iValue;
    newnode -> next = NULL;

    newnode -> next = *head;
    *head = newnode;

    printf("Node is pushed in stack successfully.\n\n");
}

void Pop(PPNODE head)
{
    if(*head == NULL)
    {
        printf("Stack is already empty.\n");
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
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements from stack are : \n");

    while(head != NULL)
    {
        printf("|%d|\n",head -> data);
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

    printf("!!WELCOME TO RAJAS STACK APPLICATION!!\n\n");

    printf("A : For inserting number Stack\n");
    printf("B : For deleting number from Stack\n");
    printf("C : For reviewing Stack\n");
    printf("D : For counting number of elements in Stack\n");
    printf("E : For terminating the application\n\n");

    while(Choice != 'E')
    {
        printf("Please select a choice : ");
        scanf(" %c", &Choice);

        if((Choice == 'A') || (Choice == 'a'))
        {
            printf("Enter the number to be inserted in stack : ");
            scanf("%d",&iNo);
            Push(&First,iNo);
            Display(First);
        }
        else if((Choice == 'B') || (Choice == 'b'))
        {
            Pop(&First);
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

    printf("!!THANKS FOR USING RAJAS STACK APPLICATION!!\n\n");
}