//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Singly Linear Linked-List is a type of linked-list where each node points to the   //
//Next node in the sequence while keeping the ends pointing to NULL. This program demonstrates    //
//the implementation of Singly Linear Linked List .                                               //
//================================================================================================//
//Language: C                                                                                     //
//Compiler : GNU GCC                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 16th March 2025                                                                           //
//Day: Sunday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<stdio.h>// For printf() and scanf() Functions, etc
#include<stdlib.h>// For malloc() Function
#include<stdbool.h>// For boolean data type

//2===============================================================================================//






//3================================================================================================//

struct sNode//Structure declaration for node in Singly Linear Linked List
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the linked list
};//sNODE, *PsNODE, **PPsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node
typedef struct sNode ** PPsNODE;//Pointer to the pointer to the structure node

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Singly Linear Linked-List                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//Functions:                                                                                      //
//================================================================================================//
//Insertion:                                                                                      //
//1. InsertFirst() : Inserts a new node at the beginning of the linked list .                     //
//2. InsertLast() : Inserts a new node at the end of the list .                                   //
//3. InsertAtPosition() : Inserts a new node at a specified position in the linked .              //
//================================================================================================//
//Deletion:                                                                                       //
//4. DeleteFirst() : Deletes the first node of the linked list .                                  //
//5. DeleteLast() : Deletes the last node of the linked list .                                    //
//6. DeleteAtPosition() : Deletes the node at a specified position in the linked list .           //
//================================================================================================//
//Traversal:                                                                                      //
//7. Display() : Displays the contents of the linked list .                                       //
//8. Count() : Counts the number of nodes in the linked list .                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//Display() Function: Displays the entire singly linear linked list .                             //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PsNODE pHead)
{
    printf("Elements from linked list are : \n");

    while(pHead != NULL)
    {
        printf("| %d | -> ",pHead -> iData);
        pHead = pHead -> pNext;
    }
    printf("NULL\n");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in the singly linear linked list .                      //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PsNODE pHead)
{
    int iSize  = 0;

    while(pHead != NULL)
    {
        iSize++;
        pHead = pHead -> pNext;
    }

    return iSize;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the singly linear linked list .  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPsNODE pHead,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(*pHead == NULL)//If linkedlist is empty
    {
        *pHead = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = *pHead;
        *pHead = PsNewNode;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the singly linear linked list .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : Temporary pointer for traversal                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPsNODE pHead,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(*pHead == NULL)//If linkedlist is empty
    {
        *pHead = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNODE ptemp = *pHead;

        while(ptemp -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        ptemp -> pNext = PsNewNode;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the singly linear      //
//linked list .                                                                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Data to be inserted in the new node .                                                  //
//3. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPosition(PPsNODE pHead,int iNo,int iPosition)
{
    //Counting number of nodes
    int iSize = Count(*pHead);

    if(iPosition == 1)//If position is 1
    {
        InsertFirst(pHead,iNo);
        return;
    }
    else if(iPosition == (iSize + 1))//If position last
    {
        InsertLast(pHead,iNo);
        return;
    }
    else//Random position
    {
        //Initialize a new node
        PsNODE PsNewNode = NULL;
        PsNewNode = (PsNODE)malloc(sizeof(sNODE));

        //Filling the node with data
        PsNewNode -> iData = iNo;
        PsNewNode -> pNext = NULL;

        PsNODE ptemp = *pHead;

        for(int iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the singly linear linked list .        //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int    : variable to return the deleted data                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteFirst(PPsNODE pHead)
{
    int iDeleted = 0;

    if((*pHead) -> pNext == NULL)//If linkedlist contains one node
    {
        iDeleted = (*pHead) -> iData;
        free(*pHead);
        *pHead = NULL;
    }
    else//If linkedlist more than one node
    {
        PsNODE ptemp = *pHead;
        *pHead = ptemp -> pNext;

        iDeleted = ptemp -> iData;

        free(ptemp);
        ptemp = NULL;
    }

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the singly linear linked list .               //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int    : variable to return the deleted data                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteLast(PPsNODE pHead)
{
    int iDeleted = 0;

    if((*pHead) -> pNext == NULL)//If linkedlist contains one node
    {
        iDeleted = (*pHead) -> iData;
        free(*pHead);
        *pHead = NULL;
    }
    else//If linkedlist contains atleast two node
    {
        PsNODE ptemp = *pHead;

        while(ptemp -> pNext -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        iDeleted = ptemp -> pNext -> iData;
        free(ptemp -> pNext);
        ptemp -> pNext = NULL;
    }

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the singly linear    //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteAtPosition(PPsNODE pHead,int iPosition)
{
    //Counting number of nodes
    int iSize = Count(*pHead);
    int iCnt = 0;

    if(iPosition == 1)//If position is 1
    {
        iCnt = DeleteFirst(pHead);
        return iCnt;
    }
    else if(iPosition == iSize)//If position last
    {
        iCnt = DeleteLast(pHead);
        return iCnt;
    }
    else//Random position
    {
        PsNODE ptemp = *pHead;
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        iCnt = ptempdelete -> iData;
        free(ptempdelete);
        ptempdelete = NULL;

        return iCnt;
    }
}

//4===============================================================================================//





//5===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Other Functions:                                                                                //
//================================================================================================//
//1. Search() : Searches for a specific value in the list                                         //
//2. Reverse() : Reverses the order of the list                                                   //
//3. Sort() : Sorts the list in ascending order                                                   //
//4. UpdateNoforNo() : Updates the value of a specific node in exchange to some value             //
//5. UpdateNoForPosition() : Updates the value of a specific node at specific position            //
//6. InsertBefore() : Inserts a new node before a specific node                                   //
//7. InsertAfter() : Inserts a new node after a specific node                                     //
//8. DeleteBefore() : Deletes the node before a specific node                                     //
//9. DeleteAfter() : Deletes the node after a specific node                                       //
//10. DeleteList() : Deletes the entire list                                                      //
//11. FindMiddle() : Finds the middle node of the list                                            //
//12. FindKthNodeFromStart() : Finds the kth node from the start of the list                      //
//13. FindKthNodeFromMiddle() : Finds the kth node from the middle of the list                    //
//14. FindKthNodeFromEnd() : Finds the kth node from the end of the list                          //
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//Search() Function: Searches for a specific value from the singly linear linked list .           //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. int : Value to be searched in the linked list .                                              //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Search(PsNODE pHead,int iSearch)
{
    int iPosition = 1;
    int iSize = Count(pHead);

    while(iPosition <= iSize)
    {
        if(pHead -> iData == iSearch)
        {
            return iPosition;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }


    return -1;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForNo() Function: Updates the value in exchange of a specific value in the singly linear//
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. int : Value to be searched in the linked list .                                              //
//3. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: bool                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool UpdateNoForNo(PsNODE pHead,int iSearch,int iUpdate)
{
    int iSize = Count(pHead);
    int iPosition = 1;

    while(iPosition <= iSize)
    {
        if(pHead -> iData == iSearch)
        {
            pHead -> iData = iUpdate;
            return true;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForPosition() Function: Updates the value at a specific position in singly linear linked//
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. int : Value to be searched in the linked list .                                              //
//3. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateNoForPosition(PsNODE pHead,int iUpdate,int iPosition)
{
    int iSize = Count(pHead);
    int iCnt = 1;

    while(iCnt <= iSize)
    {
        if(iCnt == iPosition)
        {
            pHead -> iData = iUpdate;
            return;
        }

        pHead = pHead -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertBefore() Function: Adds a new node before a specified node in singly linear linked list . //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Data to be inserted in the new node .                                                  //
//3. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : Pointer to store the new node                                                       //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertBefore(PPsNODE pHead,int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = *pHead;
        *pHead = PsNewNode;
    }
    else
    {
        PsNODE ptemp = *pHead;

        for(int iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;//Freeing the temporary pointer
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node in singly linear linked list .   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Data to be inserted in the new node .                                                  //
//3. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : Pointer to store the new node                                                       //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAfter(PPsNODE pHead,int iNo,int iPosition)
{
    int iSize = Count(*pHead);

    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    PsNODE ptemp = *pHead;

    if(iPosition == iSize)
    {
        //InsertLast(pHead,iNo); ---> Can be used

        while(ptemp ->pNext != NULL)
        {
            ptemp = ptemp ->pNext;
        }

        ptemp ->pNext = PsNewNode;

        ptemp = NULL;//Freeing the temporary pointer
    }
    else
    {
        for(int iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before a specified node from singly linear linked list .//
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteBefore(PPsNODE pHead,int iPosition)
{
    int iCnt = 0;

    PsNODE ptemp = *pHead;

    if(iPosition == 2)
    {
        *pHead = ptemp -> pNext;

        iCnt = ptemp -> iData;
        free(ptemp);
        ptemp = NULL;
    }
    else
    {
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition - 2);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        iCnt = ptempdelete -> iData;

        free(ptempdelete);
        ptempdelete = NULL;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Remove a node after a specified node from singly linear linked list .   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteAfter(PPsNODE pHead,int iPosition)
{
    PsNODE ptemp = *pHead;
    int iSize = Count(*pHead);
    int iCnt = 0;


    if(iPosition == (iSize - 1))
    {
        while(ptemp -> pNext -> pNext != NULL)
        {
            ptemp = ptemp -> pNext;
        }

        iCnt = ptemp -> pNext -> iData;

        free(ptemp -> pNext);
        ptemp -> pNext = NULL;
    }
    else
    {
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        iCnt = ptempdelete -> iData;
        free(ptempdelete);
        ptempdelete = NULL;
    }

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes the entire singly linear linked list .                           //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteList(PPsNODE pHead)
{
    PsNODE ptempdelete = *pHead;

    while(*pHead != NULL)
    {
        ptempdelete = *pHead;
        *pHead = (*pHead) -> pNext;

        free(ptempdelete);
        ptempdelete = NULL;
    }

    free(*pHead);
    *pHead = NULL;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the singly linear linked list in ascending order .              //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. int : temporary variable to store the data of the node .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SortAscending(PsNODE pHead)
{
    PsNODE ptemp1 = pHead;
    PsNODE ptemp2 = pHead;
    int itransfer = 0;

    for(ptemp1 = pHead;ptemp1 -> pNext != NULL;ptemp1 = ptemp1 -> pNext)
    {
        for(ptemp2 = ptemp1 -> pNext;ptemp2 != NULL;ptemp2 = ptemp2 -> pNext)
        {
            if(ptemp1 -> iData > ptemp2 -> iData)
            {
                itransfer = ptemp1 -> iData;
                ptemp1 -> iData = ptemp2 -> iData;
                ptemp2 -> iData = itransfer;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse() Function: Reverses the order of data in singly linear linked list .                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Reverse(PPsNODE pHead)
{
    PsNODE ptempNext = NULL;
    PsNODE ptempPrev = NULL;

    while(*pHead != NULL)
    {
        ptempNext = (*pHead) -> pNext;
        (*pHead) -> pNext = ptempPrev;
        ptempPrev = *pHead;
        *pHead = ptempNext;
    }

    *pHead = ptempPrev;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the singly linear linked list .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store size of linkedlist .                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindMiddleNode(PsNODE pHead)
{
    PsNODE ptemp = pHead;
    int iSize = Count(pHead);

    for(int iCnt = 1;iCnt < ((iSize + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: returns the kth node from start from singly linear linkedlist .//
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. int : variable as offset from start of list to find                                          //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromStart(PsNODE pHead,int iKth)
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle from singly linear linked    //
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. int : integer to store kth position from middle .                                            //
//3. int : integer to store direction of kth position from start or end .                         //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromMiddle(PsNODE pHead,int iKth,int iDirection)
{
    PsNODE ptemp = pHead;
    int iSize = Count(pHead);

    if(iDirection == 1)
    {
        iKth = ((iSize + 1)/2) - iKth;
    }
    else
    {
        iKth = ((iSize + 1)/2) + iKth;
    }

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromEnd() Function: returns the kth node from end from singly linear linkedlist .    //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. int : variable as offset from end of list to find .                                          //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store size of linkedlist .                                                  //
//3. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromEnd(PsNODE pHead,int iKth)
{
    PsNODE ptemp = pHead;
    int iSize = Count(pHead);

    for(int iCnt = 1;iCnt < (iSize - iKth + 1);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


//5===============================================================================================//





//6===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of singly-linear-linked-list .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Manual()
{
    printf("::::MANUAL FOR RAJAS's SINGLY LINEAR LINKED LIST APPLICATION::::\n\n\n");



    printf("-----Below are functionalities provided for simple access of linked list(After entering 2 in ModeSelection stage)-----\n\n");

    printf("INSERTION\n");
    printf("For Inserting data at FIRST      position : press A\n");
    printf("For Inserting data at LAST       position : press B\n");
    printf("For Inserting data at SPECIFIC   position : press C\n\n");

    printf("DELETION\n");
    printf("For Deleting  data at  First     position : press D\n");
    printf("For Deleting  data at  LAST      position : press E\n");
    printf("For Deleting  data at  SPECIFIC  position : press F\n\n");

    printf("COUNT\n");
    printf("To Count no. of nodes in linked list      : press G\n");

    printf("DISPLAY\n");
    printf("To View data in linked list               : press H\n\n\n");


    printf("-----Below are functionalities provided for added features of linked list(After entering 3 in ModeSelection stage)-----\n\n");

    printf("SEARCHING AND MERGING\n");
    printf("To Search a Specific Value in linkedlist  : press I\n");
    printf("To Reverse the linkedList                 : press J\n");
    printf("To Sort the linkedlist                    : press M\n\n");

    printf("UPDATING\n");
    printf("To Update value with a unique value in LL : press N\n");
    printf("To Update value at a position in LL       : press O\n\n");

    printf("INSERTION 2\n");
    printf("To Insert a node before a specific node   : press P\n");
    printf("To Insert a node after a specific node    : press Q\n\n");

    printf("DELETION 2\n");
    printf("To Delete a node before a specific node   : press R\n");
    printf("To Delete a node after a specific node    : press S\n");
    printf("To Delete the entire linkedlist           : press T\n\n");

    printf("FINDING\n");
    printf("To Find middle node of LL                 : press V\n");
    printf("To Find kth node from start of LL         : press X\n");
    printf("To Find kth node from middle of LL        : press Y\n");
    printf("To Find kth node from end of LL           : press Z\n\n");

    printf("COUNT\n");
    printf("To Count no. of nodes in linked list      : press G\n\n");

    printf("DISPLAY\n");
    printf("To View data in linked list               : press H\n\n\n");


    printf("Below are the modes in which you can operate\n\n");

    printf("For Manual                      : press 1\n");
    printf("For Simple Access of linkedlist : press 2\n");
    printf("For use of Added features       : press 3\n");
    printf("To exit the LinkedList App      : press 4\n\n");
}


int main()
{
    //Manual();//Display the manual for the application

    PsNODE pHead1 = NULL;//Pointer to the first node of the first linked list

    PsNODE pRet = NULL;//Pointer to the second node of the linked list

    char siChoiceMode[] = "0";//Variable to store the choice of the user for the mode of operation
    char cChoiceFunction = '\0';//Variable to store the choice of the user for the function to be performed

    int iNo1 = 0;//Variable to store the data of the node
    int iNo2 = 0;//Variable to store the data of the node
    int iRet = 0;//Variable to store the return value of the function

    int iPosition1 = 0;//Variable to store the position of the node
    int iExitMode = 0;//Variable to store the exit mode of the application

    bool bRet = false;

    printf("Welcome to Rajas's Application of Singly-Linear-LinkedList\n\n");

    while(1)
    {
        iExitMode = 0;//Resetting the exit mode to 0

        printf("====================================================================================================\n");
        printf("Enter the mode of operation : \n");
        scanf("%s",siChoiceMode);

        if(atoi(siChoiceMode) == 1)
        {
            Manual();//Display the manual for the application
        }
        else if(atoi(siChoiceMode) == 2)
        {
            printf("Active Mode : SIMPLE ACCESS\n");

            iExitMode = 0;//Resetting the exit mode to 0

            while(iExitMode != 1)
            {
                printf("====================================================================================================\n");
                printf("To exit SIMPLE ACCESS mode : press Z\n");
                printf("To view the manual : press Y\n");
                printf("Enter the function to be performed : ");
                scanf(" %c", &cChoiceFunction);

                switch(cChoiceFunction)
                {
                    case 'A':
                    case 'a':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        InsertFirst(&pHead1,iNo1);
                        printf("Node with data %d inserted at the beginning of the singly linear linked list\n",iNo1);
                        break;
                    case 'B':
                    case 'b':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);
                        printf("\n");

                        InsertLast(&pHead1,iNo1);
                        break;
                    case 'C':
                    case 'c':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position at which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        InsertAtPosition(&pHead1,iNo1,iPosition1);

                        break;
                    case 'D':
                    case 'd':
                        iRet = DeleteFirst(&pHead1);

                        break;
                    case 'E':
                    case 'e':
                        iRet = DeleteLast(&pHead1);

                        break;
                    case 'F':
                    case 'f':
                        printf("Enter the position at which the data is to be deleted : ");
                        scanf("%d",&iPosition1);

                        iRet = DeleteAtPosition(&pHead1,iPosition1);

                        break;
                    case 'G':
                    case 'g':
                        Display(pHead1);

                        break;
                    case 'H':
                    case 'h':
                        iRet = Count(pHead1);
                        printf("Number of nodes in the linked list are : %d\n",iRet);

                        break;
                    case 'Y':
                    case 'y':
                        Manual();//Display the manual for the application

                        break;
                    case 'Z':
                    case 'z':
                        printf("Exiting SIMPLE ACCESS mode\n");
                        iExitMode = 1;

                        break;
                    default:
                        printf("Invalid choice\n");
                }
            }
        }
        else if(atoi(siChoiceMode) == 3)
        {
            printf("Active Mode : ADDED FEATURES\n");

            iExitMode = 0;//Resetting the exit mode to 0

            while(iExitMode != 1)
            {
                printf("====================================================================================================\n");
                printf("To exit ADDED FEATURES mode : press A\n");
                printf("To view the manual : press B\n");
                printf("Enter the function to be performed : ");
                scanf(" %c", &cChoiceFunction);

                switch(cChoiceFunction)
                {
                    case 'B':
                    case 'b':
                        Manual();//Display the manual for the application

                        break;
                    case 'G':
                    case 'g':
                        Display(pHead1);

                        break;
                    case 'H':
                    case 'h':
                        iRet = Count(pHead1);
                        printf("Number of nodes in the linked list are : %d\n",iRet);

                        break;
                    case 'I':
                    case 'i':
                        printf("Enter the value to be searched in the linked list : ");
                        scanf("%d",&iNo1);

                        iRet = Search(pHead1,iNo1);

                        break;
                    case 'J':
                    case 'j':
                        Reverse(&pHead1);

                        break;
                    case 'L':
                    case 'l':
                        //Merge(&pHead1,&pHead1);

                        break;
                    case 'M':
                    case 'm':
                        SortAscending(pHead1);

                        break;
                    case 'N':
                    case 'n':
                        printf("Enter the value to be updated in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the value to be updated with : ");
                        scanf("%d",&iNo2);

                        bRet = UpdateNoForNo(pHead1,iNo1,iNo2);

                        break;
                    case 'O':
                    case 'o':
                        printf("Enter the value to be updated at a specific position in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position at which the data is to be updated : ");
                        scanf("%d",&iPosition1);

                        UpdateNoForPosition(pHead1,iNo1,iPosition1);

                        break;
                    case 'P':
                    case 'p':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position before which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        InsertBefore(&pHead1,iNo1,iPosition1);

                        break;
                    case 'Q':
                    case 'q':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position after which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        InsertAfter(&pHead1,iNo1,iPosition1);

                        break;
                    case 'R':
                    case 'r':
                        printf("Enter the position before which the data is to be deleted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        iRet = DeleteBefore(&pHead1,iPosition1);

                        break;
                    case 'S':
                    case 's':
                        printf("Enter the position after which the data is to be deleted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        iRet = DeleteAfter(&pHead1,iPosition1);

                        break;
                    case 'T':
                    case 't':
                        DeleteList(&pHead1);
                        break;
                        //Fixme
                    case 'U':
                    case 'u':
                        //RemoveDuplicates(&pHead1);

                        break;
                    case 'V':
                    case 'v':
                        pRet = FindMiddleNode(pHead1);

                        if(pRet != NULL)
                        {
                            printf("The data in middle node from the linked list is : %d\n",pRet -> iData);
                        }
                        else
                        {
                            printf("Invalid position\n");
                        }

                        break;
                    case 'X':
                    case 'x':
                        pRet = FindKthNodeFromStart(pHead1,iNo1);

                        break;
                    case 'Y':
                    case 'y':
                        pRet = FindKthNodeFromMiddle(pHead1,iNo1,iNo2);

                        break;
                    case 'Z':
                    case 'z':
                        pRet = FindKthNodeFromEnd(pHead1,iNo1);

                        break;
                    case 'A':
                    case 'a':
                        printf("Exiting ADDED FEATURES mode\n");
                        iExitMode = 1;

                        break;
                    default:
                        printf("Invalid choice\n");
                }
            }

            continue;
        }
        else if(atoi(siChoiceMode) == 4)
        {
            printf("Exiting the RAJAS's SINGLY LINEAR LINKEDLIST application\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
            continue;
        }
    }

    return 0;//End of program
}

//6===============================================================================================//