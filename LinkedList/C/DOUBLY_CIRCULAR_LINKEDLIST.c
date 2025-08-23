//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Doubly Circular Linked-List is a type of linked-list where each node points to the //
//Next And Previous node in the sequence while keeping the ends pointing to each other.This       //
//program demonstrates the implementation of Doubly Circular Linked List .                        //
//================================================================================================//
//Language: C                                                                                     //
//Compiler : GNU GCC                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 25th March 2025                                                                           //
//Day: Tuesday                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<stdio.h>// For printf() and scanf() Functions, etc
#include<stdlib.h>// For malloc() Function
#include<stdbool.h>// For boolean data type

//2===============================================================================================//






//3================================================================================================//

struct sNode//Structure declaration for node in Doubly Circular Linked List
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the linked list
    struct sNode *pPrev;//Pointer to the previous node in the linked list
};//sNODE, *PsNODE, **PPsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node
typedef struct sNode ** PPsNODE;//Pointer to the pointer of the structure node

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Doubly Circular Linked-List                                  //
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
//Display() Function: Displays the entire doubly circular linked list .                           //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to traverse the linked list .                                               //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PsNODE pHead,PsNODE pTail)
{
    PsNODE ptemp = pHead;

    printf("Elements from linked list are : \n\n");

    ///////////////////////Display in serial order//////////////////////

    printf("Elements from linked list in serial order are : \n");

    do
    {
        printf("<- | %d | -> ",ptemp -> iData);
        ptemp = ptemp -> pNext;
    }while(ptemp != pHead);

    ///////////////////////Display in reverse order//////////////////////

    printf("Elements from linked list in reverse order are : \n");

    ptemp = pTail;

    do
    {
        printf("<- | %d | -> ",ptemp -> iData);
        ptemp = ptemp -> pPrev;
    }while(ptemp != pTail);
    printf("\n");

    ptemp = NULL;//Set the pointer to NULL to avoid dangling pointer
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in  the doubly circular linked list .                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PsNODE pHead,PsNODE pTail)
{
    int iSize  = 0;

    do
    {
        iSize++;
        pHead = pHead -> pNext;
    }while(pHead != pTail -> pNext);

    return iSize;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the doubly circular linked list. //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPsNODE pHead,PPsNODE pTail,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        *pHead = PsNewNode;
        *pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = *pHead;
        (*pHead) -> pPrev = PsNewNode;
        *pHead = PsNewNode;
    }

    //Update the previous pointer of the tail to point to the new head
    (*pTail) -> pNext = *pHead;
    (*pHead) -> pPrev = *pTail;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the doubly circular linked list .       //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Data to be inserted in the new node .                                                  //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPsNODE pHead,PPsNODE pTail,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        *pHead = PsNewNode;
        *pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        (*pTail) -> pNext = PsNewNode; // Update the Next pointer of the current tail
        PsNewNode -> pPrev = *pTail; // Set the previous pointer of the new node to the current tail
        *pTail = PsNewNode; // Update the tail pointer to the new node
    }

    (*pHead) -> pPrev = *pTail; // Update the previous pointer of the head to point to the new tail
    (*pTail) -> pNext = *pHead; // Update the Next pointer of the tail to point to the head
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the doubly circular    //
//linked list .                                                                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//2. int : Data to be inserted in the new node .                                                  //
//3. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. int : Counter variable & Size variable in one .                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPosition(PPsNODE pHead,PPsNODE pTail,int iNo,int iPosition)
{
    //Counting number of nodes
    int iCnt = Count(*pHead,*pTail);

    if(iPosition == 1)//If position is 1
    {
        InsertFirst(pHead,pTail,iNo);
        return;
    }
    else if(iPosition == (iCnt + 1))//If position last
    {
        InsertLast(pHead,pTail,iNo);
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
        PsNewNode -> pPrev = NULL;

        PsNODE ptemp = *pHead;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext; // Set the Next pointer of the new node to the Next node
        ptemp -> pNext -> pPrev = PsNewNode; // Update the previous pointer of the Next node to point to the new node
        ptemp -> pNext = PsNewNode; // Set the Next pointer of the current node to the new node
        PsNewNode -> pPrev = ptemp; // Set the previous pointer of the new node to the current node
    }

    (*pHead) -> pPrev = *pTail; // Update the previous pointer of the head to point to the new tail
    (*pTail) -> pNext = *pHead; // Update the Next pointer of the tail to point to the head
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the doubly circular linked list .      //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int : variable to return the deleted data                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteFirst(PPsNODE pHead,PPsNODE pTail)
{
    int iDeleted = 0;

    if(*pHead == *pTail)//If linkedlist contains one node
    {
        iDeleted = (*pHead) -> iData;

        free(*pHead);
        *pHead = NULL;
        *pTail = NULL;
    }
    else//If linkedlist contains multiple nodes
    {
        *pHead = (*pHead) -> pNext;
        iDeleted = (*pTail) -> pNext -> iData;
        free((*pTail) -> pNext);
        (*pHead) -> pPrev = *pTail;
        (*pTail) -> pNext = *pHead;
    }

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the doubly circular linked list .             //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteLast(PPsNODE pHead,PPsNODE pTail)
{
    int iDeleted = 0;

    if(*pHead == *pTail)//If linkedlist contains one node
    {
        iDeleted = (*pHead) -> iData;

        free(*pHead);
        *pHead = NULL;
        *pTail = NULL;
    }
    else//If linkedlist contains multiple two node
    {
        *pTail = (*pTail) -> pPrev;

        iDeleted = (*pHead) -> pPrev -> iData;
        free((*pHead) -> pPrev);

        (*pHead) -> pPrev = *pTail;
        (*pTail) -> pNext = *pHead;
    }

    return iDeleted;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position from the doubly circular  //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Position at which the new node is to be deleted .                                      //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteAtPosition(PPsNODE pHead,PPsNODE pTail,int iPosition)
{
    //Counting number of nodes
    int iSize = Count(*pHead,*pTail);
    int iCnt = 0;

    if(iPosition == 1)//If position is 1
    {
        iCnt = DeleteFirst(pHead,pTail);
        return iCnt;
    }
    else if(iPosition == iSize)//If position last
    {
        iCnt = DeleteLast(pHead,pTail);
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
//Search() Function: Searches for a specific value from doubly circular linked list .             //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : Value to be searched in the linked list .                                              //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Search(PsNODE pHead,PsNODE pTail,int iSearch)
{
    int iSize = Count(pHead,pTail);
    int iPosition = 1;

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
//UpdateNoForNo() Function: Updates the value in exchange of a specific value doubly circular     //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : Value to be searched in the linked list .                                              //
//4. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: bool                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool UpdateNoForNo(PsNODE pHead,PsNODE pTail,int iSearch,int iUpdate)
{
    int iPosition = 1;
    int iSize = Count(pHead,pTail);

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
//UpdateNoForPosition() Function: Updates the value in at a specific position in doubly circular  //
// linked list .                                                                                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : Value to be searched in the linked list .                                              //
//4. int : Value to be updated in the linked list .                                               //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateNoForPosition(PsNODE pHead,PsNODE pTail,int iUpdate,int iPosition)
{
    int iSize = Count(pHead,pTail);
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
//InsertBefore() Function: Adds a new node before a specified node to doubly circular linked list.//
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Data to be inserted in the new node .                                                  //
//4. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : Pointer to store the new node                                                       //
//3. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertBefore(PPsNODE pHead,PPsNODE pTail,int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;

    if(iPosition == 1)
    {
        PsNewNode -> pNext = *pHead;
        (*pHead) -> pPrev = PsNewNode;
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
        PsNewNode -> pPrev = ptemp;
        ptemp -> pNext = PsNewNode;
        PsNewNode -> pNext -> pPrev = PsNewNode;

        ptemp = NULL;//Freeing the temporary pointer
    }

    (*pHead) -> pPrev = *pTail; // Update the previous pointer of the head to point to the tail
    (*pTail) -> pNext = *pHead; // Update the Next pointer of the tail to point to the head
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node to doubly circular linked list.  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Data to be inserted in the new node .                                                  //
//4. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : Pointer to store the new node                                                       //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAfter(PPsNODE pHead,PPsNODE pTail,int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;
    PsNewNode -> pPrev = NULL;


    int iSize = Count(*pHead,*pTail);

    if(iPosition == iSize)
    {
        (*pTail) -> pNext = PsNewNode; // Update the Next pointer of the current tail
        PsNewNode -> pPrev = *pTail; // Set the previous pointer of the new node to the current tail
        *pTail = PsNewNode; // Update the tail pointer to the new node
    }
    else
    {
        PsNODE ptemp = *pHead;

        for(int iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext -> pPrev = PsNewNode;
        PsNewNode -> pPrev = ptemp;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;
    }

    (*pHead) -> pPrev = *pTail; // Update the previous pointer of the head to point to the tail
    (*pTail) -> pNext = *pHead; // Update the Next pointer of the tail to point to the head
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before a specified node to doubly circular linked list. //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: int                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteBefore(PPsNODE pHead,PPsNODE pTail,int iPosition)
{
    PsNODE ptemp = *pHead;
    int iCnt = 0;

    if(iPosition == 2)
    {
        *pHead = (*pHead) -> pNext;
        iCnt = (*pHead) -> pPrev -> iData;

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
        ptempdelete -> pNext -> pPrev = ptemp;

        iCnt = ptempdelete -> iData;
        free(ptempdelete);
        ptempdelete = NULL;
    }

    (*pHead) -> pPrev = *pTail; // Update the previous pointer of the head to point to the tail
    (*pTail) -> pNext = *pHead; // Update the Next pointer of the tail to point to the head

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Removes a node after a specified node from doubly circular linked list. //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
int DeleteAfter(PPsNODE pHead,PPsNODE pTail,int iPosition)
{
    int iSize = Count(*pHead,*pTail);
    int iCnt = 0;

    if(iPosition == (iSize - 1))
    {
        *pTail = (*pTail) -> pPrev; // Update the tail pointer to the second last node
        iCnt = (*pTail) -> pNext -> iData; // Store the data of the node to be deleted

        free((*pTail) -> pNext); // Free the memory of the last node
        (*pTail) -> pNext = NULL;
    }
    else
    {
        PsNODE ptemp = *pHead;
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;
        ptempdelete -> pNext -> pPrev = ptemp;

        iCnt = ptempdelete -> iData;
        free(ptempdelete);
        ptempdelete = NULL;
    }

    (*pHead) -> pPrev = *pTail;
    (*pTail) -> pNext = *pHead;

    return iCnt;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes doubly circular linked list entirely .                           //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteList(PPsNODE pHead,PPsNODE pTail)
{
    while((*pHead != NULL) && (*pTail != NULL))
    {
        if((*pHead != NULL) && (*pHead != *pTail))
        {
            *pHead = (*pHead) -> pNext;

            free((*pHead) -> pPrev);
            (*pHead) -> pPrev = NULL;

            (*pHead) -> pPrev = *pTail;
            (*pTail) -> pNext = *pHead;

            return;
        }

        if(pHead == pTail)
        {
            free(*pHead);
            *pTail = NULL;
            *pHead = NULL;

            return;
        }

        if((*pTail != NULL) && (*pHead != *pTail))
        {
            *pTail = (*pTail) -> pPrev;
            free((*pTail) -> pNext);
            (*pTail) -> pNext = NULL;

            (*pHead) -> pPrev = *pTail;
            (*pTail) -> pNext = *pHead;
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the doubly circular linked list in ascending order .            //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
//3. int : temporary variable to store the data of the node .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SortAscending(PsNODE pHead,PsNODE pTail)
{
    PsNODE ptemp1 = pHead;
    PsNODE ptemp2 = pHead;
    int itransfer = 0;

    do
    {
        do
        {
            if(ptemp1 -> iData < ptemp2 -> iData)
            {
                itransfer = ptemp1 -> iData;
                ptemp1 -> iData = ptemp2 -> iData;
                ptemp2 -> iData = itransfer;
            }

            ptemp2 = ptemp2 -> pNext;
        }while(ptemp2 != pTail);

        ptemp1 = ptemp1 -> pNext;
    }while(ptemp1 != pHead);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse() Function: Reverses the order of data in doubly circular linked list .                 //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to traverse the linked list .                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Reverse(PPsNODE pHead,PPsNODE pTail)
{
    PsNODE pCurrent = *pHead;
    PsNODE ptemp = NULL;

    do
    {
        ptemp = pCurrent -> pPrev;
        pCurrent -> pPrev = pCurrent -> pNext;
        pCurrent -> pNext = ptemp;
        pCurrent = pCurrent -> pPrev;
    }while(pCurrent != *pHead);


    *pHead = ptemp -> pPrev;


    *pTail = (*pHead) -> pPrev;
    *pHead = (*pTail) -> pNext;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the node of the middle node from the doubly circular linked  //
// list .                                                                                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store size of linkedlist .                                                  //
//3. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindMiddleNode(PsNODE pHead,PsNODE pTail)
{
    PsNODE ptemp = pHead;
    int iSize = Count(pHead,pTail);

    for(int iCnt = 1;iCnt < ((iSize + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: returns the kth node from start in doubly circular linkedlist .//
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : integer to store kth position from start .                                             //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromStart(PsNODE pHead,PsNODE pTail,int iKth)
{
    PsNODE ptemp = pHead;

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle in doubly circular linkedlist//
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : integer to store kth position from middle .                                            //
//4. int : integer to store direction of kth position from start or end .                         //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromMiddle(PsNODE pHead,PsNODE pTail,int iKth,int iDirection)
{
    PsNODE ptemp = pHead;
    int iRet = 0;

    if(iDirection == 1)
    {
        iKth = (((iRet = Count(pHead,pTail)) + 1)/2) - iKth;
    }
    else
    {
        iKth = (((iRet = Count(pHead,pTail)) + 1)/2) - iKth;
    }

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromEnd() Function: returns the kth node from end in linkedlist .                    //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : integer to store kth position from end .                                               //
//================================================================================================//
//Return: PsNODE                                                                                  //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. int : integer to store size of linkedlist .                                                  //
//3. int : integer to store counter variable .                                                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromEnd(PsNODE pHead,PsNODE pTail,int iKth)
{
    PsNODE ptemp = pTail;
    int iSize = Count(pHead,pTail);

    for(int iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pPrev;
    }

    return ptemp;
}
//5===============================================================================================//





//6===============================================================================================//


////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of doubly-circular-linked-list .                       //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Manual()
{
    printf("::::MANUAL FOR RAJAS's DOUBLY CIRCULAR LINKED LIST APPLICATION::::\n\n\n");



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
    printf("To Concatenate two linkedlists            : press K\n");
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

    PsNODE pHead1 = NULL;//Pointer to the first node of the linked list
    PsNODE pTail1 = NULL;//Pointer to the last node of the linked list

    PsNODE pRet = NULL;//Pointer to the second node of the linked list

    char siChoiceMode[] = "0";//Variable to store the choice of the user for the mode of operation
    char cChoiceFunction = '\0';//Variable to store the choice of the user for the function to be performed

    int iNo1 = 0;//Variable to store the data of the node
    int iNo2 = 0;//Variable to store the data of the node
    int iRet = 0;//Variable to store the return value of the function

    int iPosition1 = 0;//Variable to store the position of the node
    int iExitMode = 0;//Variable to store the exit mode of the application

    bool bRet = false;

    printf("Welcome to Rajas's Application of Doubly-Circular-LinkedList\n\n");

    while(1)
    {
        iExitMode = 0;//Resetting the exit mode to 0

        printf("====================================================================================================\n");
        printf("Enter the mode of operation : ");
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
                        printf("\n");

                        InsertFirst(&pHead1,&pTail1,iNo1);
                        printf("Node with data %d inserted at the beginning of the doubly circular linked list\n", iNo1);

                        break;
                    case 'B':
                    case 'b':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);
                        printf("\n");

                        InsertLast(&pHead1,&pTail1,iNo1);
                        printf("Node with data %d inserted at the end of the doubly circular linked list\n", iNo1);

                        break;
                    case 'C':
                    case 'c':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position at which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        while((iPosition1 < 1) || (iPosition1 > (iRet = (Count(pHead1,pTail1) + 1))))
                        {
                            printf("Invalid position. Please enter a position between 1 and %d : ",(iRet + 1));
                            scanf("%d",&iPosition1);
                        }

                        InsertAtPosition(&pHead1,&pTail1,iNo1,iPosition1);
                        printf("Node with data %d inserted at the position %d of the doubly circular linked list\n",iNo1,iPosition1);

                        break;
                    case 'D':
                    case 'd':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            iRet = DeleteFirst(&pHead1,&pTail1);
                            printf("deleted data from first position is : %d\n",iRet);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'E':
                    case 'e':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            iRet = DeleteLast(&pHead1,&pTail1);
                            printf("deleted data from last position is : %d\n",iRet);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'F':
                    case 'f':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the position at which the data is to be deleted : ");
                            scanf("%d",&iPosition1);

                            printf("\n");

                            while((iPosition1 < 1) || (iPosition1 > (iRet = Count(pHead1,pTail1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",(iRet + 1));
                                scanf("%d",&iPosition1);
                            }

                            iRet = DeleteAtPosition(&pHead1,&pTail1,iPosition1);
                            printf("Node with data %d deleted from the position %d from the doubly circular linked list\n",iRet,iPosition1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'G':
                    case 'g':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            Display(pHead1,pTail1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'H':
                    case 'h':
                        iRet = Count(pHead1,pTail1);
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
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            Display(pHead1,pTail1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'H':
                    case 'h':
                        iRet = Count(pHead1,pTail1);
                        printf("Number of nodes in the linked list are : %d\n",iRet);

                        break;
                    case 'I':
                    case 'i':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the value to be searched in the linked list : ");
                            scanf("%d",&iNo1);

                            iRet = Search(pHead1,pTail1,iNo1);
                            if(iRet != -1)
                            {
                                printf("The value %d is found at position %d in the linked list\n",iNo1,iRet);
                            }
                            else
                            {
                                printf("The value %d is not found in the linked list\n",iNo1);
                            }
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'J':
                    case 'j':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            Reverse(&pHead1,&pTail1);
                            printf("The doubly circular linked list has been reversed\n");
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'M':
                    case 'm':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            SortAscending(pHead1,pTail1);
                            printf("The doubly circular linked list has been sorted in ascending order\n");
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'N':
                    case 'n':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the value to be updated in the linked list : ");
                            scanf("%d",&iNo1);

                            printf("\n");

                            printf("Enter the value to be updated with : ");
                            scanf("%d",&iNo2);

                            bRet = UpdateNoForNo(pHead1,pTail1,iNo1,iNo2);
                            if(bRet == true)
                            {
                                printf("Element %d has been updated to %d in the doubly circular linked list\n",iNo1,iNo2);
                            }
                            else
                            {
                                printf("Element %d not found in the doubly circular linked list\n",iNo1);
                            }
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'O':
                    case 'o':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the value to be updated in the linked list : ");
                            scanf("%d",&iNo1);

                            printf("\n");

                            printf("Enter the position at which the data is to be updated : ");
                            scanf("%d",&iPosition1);

                            printf("\n");

                            while((iPosition1 < 1) || (iPosition1 > (iRet = Count(pHead1,pTail1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",iRet);
                                scanf("%d",&iPosition1);
                            }

                            UpdateNoForPosition(pHead1,pTail1,iNo1,iPosition1);
                            printf("Element at position %d has been updated to %d in the doubly circular linked list\n",iPosition1,iNo1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'P':
                    case 'p':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the data to be inserted in the linked list : ");
                            scanf("%d",&iNo1);

                            printf("\n");

                            printf("Enter the position before which the data is to be inserted : ");
                            scanf("%d",&iPosition1);

                            printf("\n");

                            while((iPosition1 < 1) || (iPosition1 > (iRet = Count(pHead1,pTail1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",(iRet + 1));
                                scanf("%d",&iPosition1);
                            }

                            InsertBefore(&pHead1,&pTail1,iNo1,iPosition1);
                            printf("Node with data %d has been inserted before position %d in the doubly circular linked list\n",iNo1,iPosition1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'Q':
                    case 'q':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the data to be inserted in the linked list : ");
                            scanf("%d",&iNo1);

                            printf("\n");

                            printf("Enter the position after which the data is to be inserted : ");
                            scanf("%d",&iPosition1);

                            printf("\n");

                            while((iPosition1 < 1) || (iPosition1 > (iRet = Count(pHead1,pTail1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",(iRet + 1));
                                scanf("%d",&iPosition1);
                            }

                            InsertAfter(&pHead1,&pTail1,iNo1,iPosition1);
                            printf("Node with data %d has been inserted after position %d in the doubly circular linked list\n",iNo1,(iPosition1 + 1));
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'R':
                    case 'r':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the data to be deleted in the linked list : ");
                            scanf("%d",&iNo1);

                            printf("\n");

                            printf("Enter the position after which the data is to be deleted : ");
                            scanf("%d",&iPosition1);

                            printf("\n");

                            while((iPosition1 < 1) || (iPosition1 > (iRet = (Count(pHead1,pTail1) - 1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",(iRet + 1));
                                scanf("%d",&iPosition1);
                            }

                            iRet = DeleteAfter(&pHead1,&pTail1,iPosition1);
                            printf("Node with data %d has been deleted after position %d in the doubly circular linked list\n",iRet,iPosition1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'S':
                    case 's':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the data to be deleted in the linked list : ");
                            scanf("%d",&iNo1);

                            printf("\n");

                            printf("Enter the position before which the data is to be deleted : ");
                            scanf("%d",&iPosition1);

                            printf("\n");

                            while((iPosition1 < 1) || (iPosition1 > (iRet = (Count(pHead1,pTail1) - 1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",(iRet + 1));
                                scanf("%d",&iPosition1);
                            }

                            iRet = DeleteBefore(&pHead1,&pTail1,iPosition1);
                            printf("Node with data %d has been deleted before position %d in the doubly circular linked list\n",iRet,iPosition1);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'T':
                    case 't':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            DeleteList(&pHead1,&pTail1);
                            printf("All nodes have been deleted from the doubly circular linked list\n");
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'V':
                    case 'v':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            pRet = FindMiddleNode(pHead1,pTail1);
                            if(pRet != NULL)
                            {
                                printf("The data in middle node from the linked list is : %d\n",pRet -> iData);
                            }
                            else
                            {
                                printf("Invalid position\n");
                            }
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'X':
                    case 'x':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the position of the node to find from the start : ");
                            scanf("%d",&iNo1);

                            while((iNo1 < 1) || (iNo1 > (iRet = Count(pHead1,pTail1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",iRet);
                                scanf("%d",&iNo1);
                            }

                            pRet = FindKthNodeFromStart(pHead1,pTail1,iNo1);
                            printf("The data in %d node from the start of the linked list is : %d\n",iNo1,pRet -> iData);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'Y':
                    case 'y':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the position of the node to find from the middle : ");
                            scanf("%d",&iNo1);

                            while((iNo1 < 1) || (iNo1 > (iRet = (Count(pHead1,pTail1) / 2))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",iRet);
                                scanf("%d",&iNo1);
                            }

                            printf("Kth node from start or end ? >>Press 1: FOR start [OR] >>Press 0: FOR end ::: Your choice : ");
                            scanf("%d",&iNo2);

                            while((iNo2 < 0) || (iNo2 > 1))
                            {
                                printf("Invalid choice. Please enter 0 or 1 : ");
                                scanf("%d",&iNo2);
                            }

                            pRet = FindKthNodeFromMiddle(pHead1,pTail1,iNo1,iNo2);
                            if(iNo2 == 1)
                            {
                                printf("Data in %d node from middle to start is : %d\n",iNo1,pRet -> iData);
                            }
                            else
                            {
                                printf("Data in %d node from middle to end is : %d\n",iNo1,pRet -> iData);
                            }
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

                        break;
                    case 'Z':
                    case 'z':
                        if((iRet = Count(pHead1,pTail1)) != 0)
                        {
                            printf("Enter the position of the node to find from the end : ");
                            scanf("%d",&iNo1);

                            while((iNo1 < 1) || (iNo1 > (iRet = Count(pHead1,pTail1))))
                            {
                                printf("Invalid position. Please enter a position between 1 and %d : ",iRet);
                                scanf("%d",&iNo1);
                            }

                            pRet = FindKthNodeFromStart(pHead1,pTail1,iNo1);
                            printf("The data in %d node from the end of the linked list is : %d\n",iNo1,pRet -> iData);
                        }
                        else
                        {
                            printf("The doubly circular linked list is empty\n");
                        }

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
            printf("Exiting the RAJAS's DOUBLY CIRCULAR LINKEDLIST application\n");
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