//1===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: Singly Circular Linked-List is a type of linked-list where each node points to the //
//Next node in the sequence while keeping the end pointing to the head. This program demonstrates //
//the implementation of Singly Circular Linked List .                                             //
//================================================================================================//
//Language: C                                                                                     //
//Compiler : GNU GCC                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 30th March 2025                                                                           //
//Day: Sunday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////

//1===============================================================================================//





//2===============================================================================================//

#include<stdio.h>// For printf() and scanf() Functions, etc
#include<stdlib.h>// For malloc() Function
#include<stdbool.h>// For boolean data type
#include<string.h>// For string functions

//2===============================================================================================//






//3================================================================================================//

struct sNode//Structure declaration for node in Singly Circular Linked List
{
    int iData;//Data of the node
    struct sNode *pNext;//Pointer to the next node in the linked list
};//sNODE, *PsNODE, **PPsNODE;

typedef struct sNode sNODE;//Structure Node
typedef struct sNode * PsNODE;//Pointer to the structure node
typedef struct sNode ** PPsNODE;//Pointer to the pointer of the structure node

//3===============================================================================================//





//4===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
//                                   Singly Circular Linked-List                                  //
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
//Display() Function: Displays the entire singly circular linked list .                           //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Traverse the linked list till the last node and display the data of each node.               //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PsNODE pHead,PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("Linkedlist is empty\n");
        printf("NULL\n");
        return;
    }

    PsNODE ptemp = pHead;
    printf("Elements from linked list are : \n\n");

    printf("-> ");

    do
    {
        printf("| %d | -> ",ptemp -> iData);
        ptemp = ptemp -> pNext;
    }while(ptemp != pHead);
    printf("\n");

}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Count() Function: Counts number of node in  the singly circular linked list .                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the linked list .                                                              //
//2. PsNODE : Pointer to traverse the linked list .                                               //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Initialize a counter variable to 0.                                                          //
//2. Traverse the linked list till the last node and increment the counter variable by 1 for each //
//   node.                                                                                        //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PsNODE pHead,PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("Linkedlist is empty\n");
        return 0;
    }

    PsNODE ptemp = pHead;
    int iSize  = 0;

    do
    {
        iSize++;
        ptemp = ptemp -> pNext;
    }while(ptemp != pHead);

    return iSize;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertFirst() Function: Inserts a new node at the beginning of the singly circular linkedlist . //
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the linked list is empty, update the first pointer with the address of the new node .     //
//4. If the linked list contains at least one node, update the Next pointer of the new node with  //
//   the address of the first node and update the first pointer with the address of the new node. //
//5. Update the Next pointer of the last node to point to the new head node .                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPsNODE pHead,PPsNODE pTail,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        *pHead = PsNewNode;
        *pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        PsNewNode -> pNext = *pHead;
        *pHead = PsNewNode;
    }

    (*pTail) -> pNext = *pHead;

    printf("Node with data %d inserted at the beginning of the singly circular linked list\n",iNo);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertLast() Function: Inserts a new node at the end of the singly circular linked list .       //
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Allocate memory for the new node .                                                           //
//2. Fill the new node with the data .                                                            //
//3. If the linked list is empty, update the first pointer with the address of the new node .     //
//4. If the linked list contains at least one node, update the Next pointer of the                //
//   last node with the address of the new node and update the last pointer with the address of   //
//   the new node.                                                                                //
//5. Update the Next pointer of the new node to point to the head node .                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPsNODE pHead,PPsNODE pTail,int iNo)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        *pHead = PsNewNode;
        *pTail = PsNewNode;
    }
    else//If linkedlist contains atleast one node
    {
        (*pTail) -> pNext = PsNewNode;
        PsNewNode -> pNext = *pHead;
        *pTail = PsNewNode;
    }

    (*pTail) -> pNext = *pHead;

    printf("Node with data %d inserted at the end of the singly circular linked list\n",iNo);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAtPosition() Function: Inserts a new node at the given position of the singly circular    //
//linked list .                                                                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Data to be inserted in the new node .                                                  //
//4. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : Pointer to the new node .                                                           //
//2. int : Size of the linked list .                                                              //
//3. int : Counter variable .                                                                     //
//4. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. Fill the new node with the data .                                                            //
//5. If the position is 1, update the Next pointer of the new node with the address of the first  //
//   node and update the first pointer with the address of the new node.                          //
//6. If the position is last,update the Next pointer of the last node with the address of the new //
//   node and update the last pointer with the address of the new node.                           //
//7. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the Next       //
//   pointer of the previous node with the address of the new node.                               //
//8. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPosition(PPsNODE pHead,PPsNODE pTail,int iNo,int iPosition)
{
    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    //Counting number of nodes
    int iSize = Count(*pHead,*pTail);
    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iSize + 1)))//If position is invalid
    {

        while(iCnt <= 2)
        {
            printf("Invalid position\n");

            printf("Enter valid position : \n");
            scanf("%d",&iPosition);

            if((iPosition >= 1) && (iPosition <= (iSize + 1)))
            {
                InsertAtPosition(pHead,pTail,iNo,iPosition);
                return;
            }

            iCnt++;
        }

        printf("Wrong input entered 3 times , call function again .\n");

        return;
    }
    else if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        *pHead = PsNewNode;
        *pTail = PsNewNode;
    }
    else if(iPosition == 1)//If position is 1
    {
        PsNewNode -> pNext = *pHead;
        *pHead = PsNewNode;
    }
    else if(iPosition == (iSize + 1))//If position last
    {
        PsNewNode -> pNext = *pHead;
        (*pTail) -> pNext = PsNewNode;
        *pTail = PsNewNode;
    }
    else//Random position
    {
        PsNODE ptemp = *pHead;

        for(iCnt = 1;iCnt < (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;
    }

    (*pTail) -> pNext = *pHead;

    printf("Node with data %d inserted at position %d in the singly circular linked list\n",iNo,iPosition);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteFirst() Function: Deletes a node from beginning of the singly circular linked list .      //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. If the linked list contains one node, free the memory of the first node and update both      //
//   the first and last pointers to NULL .                                                        //
//3. If the linked list contains multiple nodes,update the first pointer with the Next pointer of //
//   the first node, free the memory of the last node,and update the Next pointer of the new head //
//   to point to the tail node .                                                                  //
//4. Update the Next pointer of the tail to point to the new head node .                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPsNODE pHead,PPsNODE pTail)
{
    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        printf("Linkedlist is empty\n");
        return;
    }
    else if(*pHead == *pTail)//If linkedlist contains one node
    {
        *pTail = NULL;

        printf("Node with data %d deleted from the singly circular linked list\n",(*pHead) -> iData);

        free(*pHead);
        *pHead = NULL;

        return;
    }
    else//If linkedlist contains multiple nodes
    {
        *pHead = (*pHead) -> pNext;

        printf("Node with data %d deleted from the beginning of the singly circular linked list\n",(*pTail) -> pNext -> iData);

        free((*pTail) -> pNext);
    }

    (*pTail) -> pNext = *pHead;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteLast() Function: Deletes a node from end of the singly circular linked list .             //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list contains one node, free the memory of the first node and update both the  //
//   first and last pointers to NULL .                                                            //
//3. If linked list contains multiple nodes, traverse till the second last node and delete the    //
//   last node.                                                                                   //
//4. Update the Next pointer of the second last node to point to the head node .                  //
//5. Update the Next pointer of the tail to point to the head node .                              //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPsNODE pHead,PPsNODE pTail)
{
    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        printf("Linkedlist is empty\n");
        return;
    }
    else if(*pHead == *pTail)//If linkedlist contains one node
    {
        *pTail = NULL;
        free(*pHead);
        *pHead = NULL;

        printf("Node with data %d deleted from the singly circular linked list\n",(*pHead) -> iData);

        return;
    }
    else//If linkedlist contains atleast two node
    {
        PsNODE ptemp = *pHead;

        while(ptemp -> pNext != *pTail)
        {
            ptemp = ptemp -> pNext;
        }

        printf("Node with data %d deleted from the end of the singly circular linked list\n",ptemp -> pNext -> iData);

        free(ptemp -> pNext);
        *pTail = ptemp;
        (*pTail) -> pNext = *pHead;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAtPosition() Function: Deletes a new node at the given position of the singly circular    //
//linked list .                                                                                   //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Position at which the new node is to be inserted .                                     //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Size of the linked list .                                                              //
//2. int : Counter variable .                                                                     //
//3. PsNODE : temporary pointer to traverse the linked list .                                     //
//4. PsNODE : temporary pointer to delete the node .                                              //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
////4. If the position is 1, update the first pointer with the Next pointer of the first node and //
//   free the memory of the first node.                                                           //
//5. If the position is last, traverse till the second last node and delete the last node.        //
//6. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the previous node with the Next pointer of the node to be deleted and    //
//   free the memory of the node to be deleted.                                                   //
//7. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAtPosition(PPsNODE pHead,PPsNODE pTail,int iPosition)
{
    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        printf("Linkedlist is empty\n");
        return;
    }

    //Counting number of nodes
    int iSize = Count(*pHead,*pTail);
    int iCnt = 0;

    if((iPosition < 1) || (iPosition > iSize))//If position is invalid
    {
        while(iCnt <= 2)
        {
            printf("Invalid position\n");

            printf("Enter valid position : \n");
            scanf("%d",&iPosition);

            if((iPosition >= 1) && (iPosition <= iSize))
            {
                DeleteAtPosition(pHead,pTail,iPosition);
                return;
            }

            iCnt++;
        }

        printf("Wrong input entered 3 times , call function again .\n");

        return;
    }


    if(*pHead == *pTail)//If linkedlist contains one node
    {
        *pTail = NULL;

        printf("Node with data %d deleted from the singly circular linked list\n",(*pHead) -> iData);

        free(*pHead);
        *pHead = NULL;
    }
    else if(iPosition == 1)//If position is 1
    {
        *pHead = (*pHead) -> pNext;

        printf("Node with data %d deleted from the beginning of the singly circular linked list\n",(*pTail) -> pNext -> iData);

        free((*pTail) -> pNext);
        (*pTail) -> pNext = *pHead;
    }
    else if(iPosition == iSize)//If position last
    {
        PsNODE ptemp = *pHead;

        while(ptemp -> pNext != *pTail)
        {
            ptemp = ptemp -> pNext;
        }

        printf("Node with data %d deleted from the end of the singly circular linked list\n",ptemp -> pNext -> iData);

        free(ptemp -> pNext);
        *pTail = ptemp;
        (*pTail) -> pNext = *pHead;
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
        free(ptempdelete);
    }

    printf("Node deleted from position %d of the singly circular linked list\n",iPosition);
}

//4===============================================================================================//





//6===============================================================================================//

////////////////////////////////////////////////////////////////////////////////////////////////////
//Other Functions:                                                                                //
//================================================================================================//
//1. Search() : Searches for a specific value in the list                                         //
//2. Reverse() : Reverses the order of the list                                                   //
//3. Concat() : Concatenates two lists                                                            //
//4. Merge() : Merges two sorted lists                                                            //
//5. Sort() : Sorts the list in ascending order                                                   //
//6. UpdateNoforNo() : Updates the value of a specific node in exchange to some value             //
//7. UpdateNoForPosition() : Updates the value of a specific node at specific position            //
//8. InsertBefore() : Inserts a new node before a specific node                                   //
//9. InsertAfter() : Inserts a new node after a specific node                                     //
//10. DeleteBefore() : Deletes the node before a specific node                                    //
//11. DeleteAfter() : Deletes the node after a specific node                                      //
//12. DeleteList() : Deletes the entire list                                                      //
//13. RemoveDuplicates() : Removes duplicate nodes from the list                                  //
//14. FindMiddle() : Finds the middle node of the list                                            //
//15. FindDifference() : Finds the difference of two lists                                        //
//16. FindKthNodeFromStart() : Finds the kth node from the start of the list                      //
//17. FindKthNodeFromMiddle() : Finds the kth node from the middle of the list                    //
//18. FindKthNodeFromEnd() : Finds the kth node from the end of the list                          //
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//Search() Function: Searches for a specific value singly circular linked list .                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. PsNODE : Address of the first pointer of the linked list .                                   //
//2. PsNODE : Address of the last pointer of the linked list .                                    //
//3. int : Value to be searched in the linked list .                                              //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int : Counter variable & Position variable in one .                                          //
//2. int : Size of the linked list .                                                              //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. Count the number of nodes in the linked list .                                               //
//3. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, display a message that the value is found and return.//
//4. If the value is not found, return false.                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Search(PsNODE pHead,PsNODE pTail,int iSearch)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("Linkedlist is empty\n");
        return false;
    }

    int iPosition = 1;
    int iSize = Count(pHead,pTail);

    while(iPosition <= iSize)
    {
        if(pHead -> iData == iSearch)
        {
            printf("Element %d is found at position %d in singly circular linked list\n",iSearch,iPosition);
            return true;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    printf("Element %d not found in singly circular linked list\n",iSearch);
    return false;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForNo() Function: Updates the value in exchange of a specific value singly circular     //
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Count the number of nodes in the linked list .                                               //
//2. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, update the data of the node with the specified value.//
//3. If the value is not found, display a message that the value is not found.                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateNoForNo(PsNODE pHead,PsNODE pTail,int iSearch,int iUpdate)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("Linkedlist is empty\n");
        return;
    }

    int iPosition = 1;
    int iSize = Count(pHead,pTail);

    while(iPosition <= iSize)
    {
        if(pHead -> iData == iSearch)
        {
            pHead -> iData = iUpdate;
            printf("Element %d has been updated to %d in singly circular linked list\n",iSearch,iUpdate);

            return;
        }

        pHead = pHead -> pNext;
        iPosition++;
    }

    printf("Element %d not found in singly circular linked list\n",iSearch);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//UpdateNoForPosition() Function: Updates the value in at a specific position singly circular     //
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. Count the number of nodes in the linked list .                                               //
//2. Traverse the linked list till the last node and compare the data of each node with the       //
//   specified value. If the value is found, update the data of the node with the specified value.//
//3. If the value is not found, display a message that the value is not found.                    //
////////////////////////////////////////////////////////////////////////////////////////////////////
void UpdateNoForPosition(PsNODE pHead,PsNODE pTail,int iUpdate,int iPosition)
{
    if(pHead == NULL)
    {
        printf("Linkedlist is empty\n");
        return;
    }

    int iCnt = 0;
    int iSize = Count(pHead,pTail);

    if((iPosition < 1) || (iPosition > (iSize + 1)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            printf("Invalid position\n");
            printf("Enter valid position : \n");
            scanf("%d",&iPosition);

            if((iPosition >= 1) && (iPosition <= (iSize + 1)))
            {
                UpdateNoForPosition(pHead,pTail,iUpdate,iPosition);
                return;
            }
        }

        printf("Wrong input entered 3 times , call function again .\n");

        return;
    }

    iCnt = 1;

    while(iCnt <= iSize)
    {
        if(iCnt == iPosition)
        {
            pHead -> iData = iUpdate;
            printf("Element at position %d has been updated to %d in singly circular linked list\n",iPosition,iUpdate);

            return;
        }

        pHead = pHead -> pNext;
        iCnt++;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Concat() Function: Concats two singly circular linked list .                                    //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list 1 .                                //
//2. PPsNODE : Address of the first pointer of the linked list 2 .                                //
//3. PPsNODE : Address of the last pointer of the linked list 1 .                                 //
//4. PPsNODE : Address of the last pointer of the linked list 2 .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If both linked lists are empty,display a message that both linked lists are empty and return //
//2. If the first linked list is empty, display a message that the first linked list              //
//   is empty and return.                                                                         //
//3. If the second linked list is empty, display a message that the second linked list            //
//   is empty and return.                                                                         //
//4. Update the Next pointer of the last node of the first linked list to point to the first node //
//   of the second linked list and update the Next pointer of the last node of the second linked  //
//   list to point to the first node of the first linked list.                                    //
//5. Update the last pointer of the first linked list to point to the last node of the second     //
//   linked list.                                                                                 //
//6. Set the first and last pointers of the second linked list to NULL to free the memory of the  //
//   second linked list.                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Concat(PPsNODE pHead1,PPsNODE pHead2,PPsNODE pTail1,PPsNODE pTail2)
{
    if((*pHead1 == NULL) && (*pHead2 == NULL) && (*pTail1 == NULL) && (*pTail2 == NULL))
    {
        printf("Both linkedlist are empty\n");
        return;
    }
    else if((*pHead1 == NULL) && (*pTail1 == NULL))
    {
        printf("First linkedlist is empty\n");
        return;
    }
    else if((*pHead2 == NULL) && (*pTail2 == NULL))
    {
        printf("Second linkedlist is empty\n");
        return;
    }

    (*pTail1) -> pNext = *pHead2;
    (*pTail2) -> pNext = *pHead1;

    *pTail1 = *pTail2;

    *pHead2 = NULL; //Freeing the second linked list
    *pTail2 = NULL; //Freeing the second linked list
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertBefore() Function: Adds a new node before a specified node in singly circular linked list.//
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
//2. int : Size of the linked list .                                                              //
//3. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. If the position is 1, update the Next pointer of the new node with the address of the first  //
//   node and update the first pointer with the address of the new node.                          //
//5. If the position is last,update the Next pointer of the last node with the address of the new //
//   node and update the last pointer with the address of the new node.                           //
//6. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the            //
//   Next pointer of the previous node with the address of the new node.                          //
//7. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertBefore(PPsNODE pHead,PPsNODE pTail,int iNo,int iPosition)
{
    if((*pHead == NULL) && (*pTail == NULL))//If linkedlist is empty
    {
        printf("linkedlist are empty\n");
        return;
    }

    int iSize = Count(*pHead,*pTail);

    if((iPosition < 1) || (iPosition > (iSize)))
    {
        printf("Invalid position\n");
        return;
    }

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

    (*pTail) -> pNext = *pHead;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//InsertAfter() Function: Adds a new node after a specified node in singly circular linked list.  //
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
//2. int : Size of the linked list .                                                              //
//3. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. If the position is the last, update the Next pointer of the new node with the address of the //
//   first node and update the Next pointer of the last node with the address of the new          //
//   node and update the last pointer with the address of the new node.                           //
//5. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the new node with the address of the Next node and update the            //
//   Next pointer of the previous node with the address of the new node.                          //
//6. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAfter(PPsNODE pHead,PPsNODE pTail,int iNo,int iPosition)
{
    if((*pHead == NULL) && (*pTail == NULL))
    {
        printf("linkedlist are empty\n");
        return;
    }

    int iSize = Count(*pHead,*pTail);

    if((iPosition < 1) || (iPosition > (iSize)))
    {
        printf("Invalid position\n");
        return;
    }

    //Initialize a new node
    PsNODE PsNewNode = NULL;
    PsNewNode = (PsNODE)malloc(sizeof(sNODE));

    //Filling the node with data
    PsNewNode -> iData = iNo;
    PsNewNode -> pNext = NULL;

    if(iPosition == iSize)
    {
        PsNewNode -> pNext = *pHead;
        (*pTail) -> pNext = PsNewNode;
        *pTail = PsNewNode;
    }
    else
    {
        PsNODE ptemp = *pHead;

        for(int iCnt = 1;iCnt <= (iPosition - 1);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        PsNewNode -> pNext = ptemp -> pNext;
        ptemp -> pNext = PsNewNode;

        ptemp = NULL;
    }

    (*pTail) -> pNext = *pHead;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteBefore() Function: Removes a node before specified node from singly circular linked list. //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Position before which the node is to be deleted .                                      //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. If the position is 2, update the first pointer with the Next pointer of the first node and   //
//   free the memory of the first node.                                                           //
//5. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the previous node with the Next pointer of the node to be deleted        //
//   and free the memory of the node to be deleted.                                               //
//6. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteBefore(PPsNODE pHead,PPsNODE pTail,int iPosition)
{
    if((*pHead == NULL) && (*pTail == NULL))
    {
        printf("linkedlist are empty\n");
        return;
    }

    int iSize = Count(*pHead,*pTail);
    int iCnt = 0;

    if((iPosition < 2) || (iPosition > (iSize)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            printf("Invalid position\n");
            printf("Enter valid position : \n");
            scanf("%d",&iPosition);

            if((iPosition >= 2) && (iPosition <= (iSize)))
            {
                DeleteBefore(pHead,pTail,iPosition);
                return;
            }
        }

        printf("Wrong input entered 3 times , call function again .\n");

        return;
    }

    if(iPosition == 2)
    {
        *pHead = (*pHead) -> pNext;

        printf("Node with data %d deleted from the beginning of the singly circular linked list\n",(*pTail) -> pNext -> iData);

        free((*pTail) -> pNext);
        (*pTail) -> pNext = *pHead;
    }
    else
    {
        PsNODE ptemp = *pHead;
        PsNODE ptempdelete = NULL;

        for(iCnt = 1;iCnt < (iPosition - 2);iCnt++)
        {
            ptemp = ptemp -> pNext;
        }

        ptempdelete = ptemp -> pNext;
        ptemp -> pNext = ptemp -> pNext -> pNext;

        printf("Node with data %d deleted from the singly circular linked list\n",ptempdelete -> iData);

        free(ptempdelete);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteAfter() Function: Removes a node after a specified node from singly circular linked list. //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//3. int : Position before which the new node is to be inserted .                                 //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//2. PsNODE : temporary pointer to delete the node .                                              //
//3. int : Size of the linked list .                                                              //
//4. int : Counter variable .                                                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the position is invalid, display a message that the position is invalid.                  //
//4. If the position is last, traverse till the second last node and delete the last              //
//   node. Update the Next pointer of the last node to point to the head node .                   //
//5. If the position is random, traverse till the node before the specified position and update   //
//   the Next pointer of the previous node with the Next pointer of the node to be deleted and    //
//   free the memory of the node to be deleted.                                                   //
//6. Update the Next pointer of the last node to point to the head node .                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAfter(PPsNODE pHead,PPsNODE pTail,int iPosition)
{
    if((*pHead == NULL) && (*pTail == NULL))
    {
        printf("linkedlist are empty\n");
        return;
    }

    int iSize = Count(*pHead,*pTail);
    int iCnt = 0;

    if((iPosition < 1) || (iPosition > (iSize - 1)))
    {
        for(iCnt = 0;iCnt <= 2;iCnt++)
        {
            printf("Invalid position\n");
            printf("Enter valid position : \n");
            scanf("%d",&iPosition);

            if((iPosition >= 1) && (iPosition <= (iSize - 1)))
            {
                DeleteAfter(pHead,pTail,iPosition);
                return;
            }
        }

        printf("Wrong input entered 3 times , call function again .\n");

        return;
    }

    PsNODE ptemp = *pHead;

    if(iPosition == (iSize - 1))
    {
        while(ptemp -> pNext != *pTail)
        {
            ptemp = ptemp -> pNext;
        }

        printf("Node with data %d deleted from end of the the singly circular linked list\n",ptemp -> pNext -> iData);

        free(ptemp -> pNext);
        ptemp -> pNext = *pHead;
        *pTail = ptemp;
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

        printf("Node with data %d deleted from the singly circular linked list\n",ptempdelete -> iData);

        free(ptempdelete);
    }

    (*pTail) -> pNext = *pHead;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//DeleteList() Function: Deletes singly circular linked list entirely .                           //
//================================================================================================//
//Parameters:                                                                                     //
//1. PPsNODE : Address of the first pointer of the linked list .                                  //
//2. PPsNODE : Address of the last pointer of the linked list .                                   //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables:                                                                                //
//1. PsNODE : temporary pointer to traverse the linked list .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list is not empty, traverse the linked list and free the memory of each node   //
//   one by one.                                                                                  //
//3. Finally, free the first pointer and display a message that the linked list has been deleted. //
//4. Set the first pointer and last pointer to NULL to avoid dangling pointers.                   //
//5. Display a message that the linked list has been deleted.                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteList(PPsNODE pHead,PPsNODE pTail)
{
    if((*pHead == NULL) && (*pTail == NULL))
    {
        printf("linkedlist is already empty\n");
        return;
    }

    PsNODE ptempdelete = *pHead;

    do
    {
        *pHead = (*pHead) -> pNext;
        free((*pTail) -> pNext);
        (*pTail) -> pNext = *pHead;
    }while(*pHead != *pTail);

    free(*pHead);
    free(*pTail);

    *pHead = NULL;
    *pTail = NULL;

    printf("Singly Circular Linked List has been deleted\n");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//SortAscending() Function: Sorts the singly circular linked list in ascending order .            //
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
//3. int : temporary variable to store the data of the node .                                     //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list is not empty, traverse the linked list and compare the data               //
//   of each node with the data of the next node. If the data of the first node is greater than   //
//   the data of the next node, swap the data of the two nodes. Repeat this process till the last //
//   node.                                                                                        //
//3. Finally, display a message that the linked list has been sorted in ascending order.          //
////////////////////////////////////////////////////////////////////////////////////////////////////
void SortAscending(PsNODE pHead,PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("linkedlist is empty\n");
        return;
    }

    int itransfer = 0;
    PsNODE ptemp1 = pHead;
    PsNODE ptemp2 = pHead;

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

    printf("Singly Circular Linked List has been sorted as in ascending order\n");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//Reverse() Function: Reverses the order of data in singly circular linked list .                 //
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
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty and return .    //
//2. If the linked list is not empty, traverse the linked list and reverse the order of data in   //
//   each node.                                                                                   //
//3. Finally,update the first pointer with the address of the last node and the last pointer with //
//   the address of the first node. Update the Next pointer of the last node to point to the head //
//   node.                                                                                        //
//4. Display a message that the linked list's data has been reversed.                             //
//5. Set the first pointer and last pointer to NULL to avoid dangling pointers.                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Reverse(PPsNODE pHead,PPsNODE pTail)
{
    if((*pHead == NULL) && (*pTail == NULL))
    {
        printf("linkedlist is empty\n");
        return;
    }

    PsNODE pCurrent = *pHead;
    PsNODE ptempprev = *pTail;
    PsNODE ptempNext = NULL;

    do
    {
        ptempNext = pCurrent -> pNext;
        pCurrent -> pNext = ptempprev;
        ptempprev = pCurrent;
        pCurrent = ptempNext;
    }while(pCurrent != *pHead);

    pCurrent = *pHead;
    *pHead = *pTail;
    *pTail = pCurrent;

    (*pTail) -> pNext = *pHead;

    printf("Linkedlist's data has been reversed\n");
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindMiddleNode() Function: returns the middle node from the singly circular linkedlist .        //
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
//4. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. Traverse the linked list till the middle node and return the address of the middle node.     //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindMiddleNode(PsNODE pHead, PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("linkedlist is empty\n");
        return 0;
    }

    PsNODE ptemp = pHead;

    int iCnt = 0;
    int iSize = Count(pHead,pTail);

    for(iCnt = 1;iCnt < ((iSize + 1)/2);iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromStart() Function: returns the kth node from start in singly circular linkedlist .//
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
//3. int : integer to store kth position from start .                                             //
//4. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the kth position is invalid, display a message that the kth position is invalid.          //
//4. Travel the linked list till the kth node from start and return the address of the kth node.  //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromStart(PsNODE pHead, PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("linkedlist is empty\n");
        return 0;
    }

    PsNODE ptemp = pHead;

    int iKth = 0;
    printf("Enter the kth position from start : ");
    scanf("%d",&iKth);
    printf("\n");
    int iCnt = 0;
    int iSize = Count(pHead,pTail);


    if((iKth < 1) || (iKth > iSize))
    {
        printf("Invalid position\n");

        printf("Wrong input, call function again .\n");

        return NULL;
    }


    for(iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    if(ptemp == NULL)
    {
        printf("Invalid position\n");
        return NULL;
    }
    else
    {
        printf("Data in %d node from start is : %d\n",iKth,ptemp -> iData);
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromMiddle() Function: returns the kth node from middle in linkedlist .              //
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
//3. int : integer to store kth position from start .                                             //
//4. int : integer to store counter variable .                                                    //
//5. int : integer to store direction of kth position from start or end .                         //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the kth position is invalid, display a message that the kth position is invalid.          //
//4. If the kth position is random, traverse the linked list till the kth node from middle and    //
//   return the address of the kth node.                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromMiddle(PsNODE pHead, PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("linkedlist is empty\n");
        return 0;
    }

    PsNODE ptemp = pHead;

    int iKth = 0;
    printf("Enter the kth position from middle : ");
    scanf("%d",&iKth);
    printf("\n");
    int iDirection = 0;
    printf("Kth node from start or end ? >>Press 1 : FOR start [OR] >>Press 2 : FOR end ::: Your choice : ");
    scanf("%d",&iDirection);
    printf("\n");
    int iSize = Count(pHead,pTail);
    int iCnt = 0; 


    if((iKth < 1) || (iKth >= ((iSize + 1)/2)))
    {
        printf("Invalid position\n");

        printf("Wrong input, call function again .\n");

        return NULL;
    }

    if(iDirection == 1)
    {
        iKth = ((iSize + 1)/2) - iKth;
    }
    else
    {
        iKth = ((iSize + 1)/2) + iKth;
    }

    for(iCnt = 1;iCnt < iKth;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    if(ptemp == NULL)
    {
        printf("Invalid position\n");
        return NULL;
    }
    else
    {
        if(iDirection == 1)
        {
            printf("Data in %d node from middle to start is : %d\n",iKth,ptemp -> iData);
        }
        else
        {
            printf("Data in %d node from middle to end is : %d\n",iKth,ptemp -> iData);
        }
    }

    return ptemp;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
//FindKthNodeFromEnd() Function: returns the kth node from end in linkedlist .                    //
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
//3. int : integer to store kth position from start .                                             //
//4. int : integer to store counter variable .                                                    //
//================================================================================================//
//Algorithm:                                                                                      //
//1. If the linked list is empty, display a message that the linked list is empty.                //
//2. Count the number of nodes in the linked list .                                               //
//3. If the kth position is invalid, display a message that the kth position is invalid.          //
//4. If the kth position is random, traverse the linked list till the kth node from end and       //
//   return the address of the kth node.                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
PsNODE FindKthNodeFromEnd(PsNODE pHead,PsNODE pTail)
{
    if((pHead == NULL) && (pTail == NULL))
    {
        printf("linkedlist is empty\n");
        return 0;
    }

    PsNODE ptemp = pHead;

    int iKth = 0;
    printf("Enter the kth position from end : ");
    scanf("%d",&iKth);
    printf("\n");
    int iCnt = 0;
    int iSize = Count(pHead,pTail);


    if((iKth < 1) || (iKth > iSize))
    {
        printf("Invalid position\n");

        printf("Wrong input, call function again .\n");

        return NULL;
    }

    int iIndex = iSize - iKth + 1;

    for(iCnt = 1;iCnt < iIndex;iCnt++)
    {
        ptemp = ptemp -> pNext;
    }

    if(ptemp == NULL)
    {
        printf("Invalid position\n");
        return NULL;
    }
    else
    {
        printf("Data in %d node from end is : %d\n",iKth,ptemp -> iData);
    }

    return ptemp;
}


//6===============================================================================================//





//5===============================================================================================//


////////////////////////////////////////////////////////////////////////////////////////////////////
//Manual() Function: A guide for the usage of singly-circular-linked-list .                       //
//================================================================================================//
//Parameters: None                                                                                //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm: None                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Manual()
{
    printf("::::MANUAL FOR RAJAS's SINGLY CIRCULAR LINKED LIST APPLICATION::::\n\n\n");



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

    PsNODE pHead2 = NULL;//Pointer to the first node of the second linked list
    PsNODE pTail2 = NULL;//Pointer to the last node of the second linked list

    PsNODE pRet = NULL;//Pointer to the second node of the linked list

    char siChoiceMode[] = "0";//Variable to store the choice of the user for the mode of operation
    char cChoiceFunction = '\0';//Variable to store the choice of the user for the function to be performed

    int iNo1 = 0;//Variable to store the data of the node
    int iNo2 = 0;//Variable to store the data of the node
    int iRet = 0;//Variable to store the return value of the function

    int iPosition1 = 0;//Variable to store the position of the node
    int iExitMode = 0;//Variable to store the exit mode of the application

    printf("Welcome to Rajas's Application of Singly-Circular-LinkedList\n\n");

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
                        break;
                    case 'B':
                    case 'b':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);
                        printf("\n");

                        InsertLast(&pHead1,&pTail1,iNo1);
                        break;
                    case 'C':
                    case 'c':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position at which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        InsertAtPosition(&pHead1,&pTail1,iNo1,iPosition1);

                        break;
                    case 'D':
                    case 'd':
                        DeleteFirst(&pHead1,&pTail1);

                        break;
                    case 'E':
                    case 'e':
                        DeleteLast(&pHead1,&pTail1);

                        break;
                    case 'F':
                    case 'f':
                        printf("Enter the position at which the data is to be deleted : ");
                        scanf("%d",&iPosition1);

                        DeleteAtPosition(&pHead1,&pTail1,iPosition1);

                        break;
                    case 'G':
                    case 'g':
                        Display(pHead1,pTail1);

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
                        Display(pHead1,pTail1);

                        break;
                    case 'H':
                    case 'h':
                        iRet = Count(pHead1,pTail1);
                        printf("Number of nodes in the linked list are : %d\n",iRet);

                        break;
                    case 'I':
                    case 'i':
                        printf("Enter the value to be searched in the linked list : ");
                        scanf("%d",&iNo1);

                        Search(pHead1,pTail1,iNo1);

                        break;
                    case 'J':
                    case 'j':
                        Reverse(&pHead1,&pTail1);

                        break;
                    case 'K':
                    case 'k':
                        Concat(&pHead1,&pHead2,&pTail1,&pTail2);

                        break;
                    case 'L':
                    case 'l':
                        //Merge(&pHead1,&pHead1);

                        break;
                    case 'M':
                    case 'm':
                        SortAscending(pHead1,pTail1);

                        break;
                    case 'N':
                    case 'n':
                        printf("Enter the value to be updated in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the value to be updated with : ");
                        scanf("%d",&iNo2);

                        UpdateNoForNo(pHead1,pTail1,iNo1,iNo2);

                        break;
                    case 'O':
                    case 'o':
                        printf("Enter the value to be updated at a specific position in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position at which the data is to be updated : ");
                        scanf("%d",&iPosition1);

                        UpdateNoForPosition(pHead1,pTail1,iNo1,iPosition1);

                        break;
                    case 'P':
                    case 'p':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position before which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        InsertBefore(&pHead1,&pTail1,iNo1,iPosition1);

                        break;
                    case 'Q':
                    case 'q':
                        printf("Enter the data to be inserted in the linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the position after which the data is to be inserted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        InsertAfter(&pHead1,&pTail1,iNo1,iPosition1);

                        break;
                    case 'R':
                    case 'r':
                        printf("Enter the position before which the data is to be deleted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        DeleteBefore(&pHead1,&pTail1,iPosition1);

                        break;
                    case 'S':
                    case 's':
                        printf("Enter the position after which the data is to be deleted : ");
                        scanf("%d",&iPosition1);

                        printf("\n");

                        DeleteAfter(&pHead1,&pTail1,iPosition1);

                        break;
                    case 'T':
                    case 't':
                        DeleteList(&pHead1,&pTail1);
                        break;
                        //Fixme
                    case 'U':
                    case 'u':
                        //RemoveDuplicates(&pHead1);

                        break;
                    case 'V':
                    case 'v':
                        pRet = FindMiddleNode(pHead1,pTail1);

                        if(pRet != NULL)
                        {
                            printf("The data in middle node from the linked list is : %d\n",pRet -> iData);
                        }
                        else
                        {
                            printf("Invalid position\n");
                        }

                        break;
                    case 'W':
                    case 'w':
                        printf("Enter the first linked list : ");
                        scanf("%d",&iNo1);

                        printf("\n");

                        printf("Enter the second linked list : ");
                        scanf("%d",&iNo2);

                        //iReturn = FindDifference(&pHead1,&pHead1);

                        break;
                    case 'X':
                    case 'x':
                        pRet = FindKthNodeFromStart(pHead1,pTail1);

                        break;
                    case 'Y':
                    case 'y':
                        pRet = FindKthNodeFromMiddle(pHead1,pTail1);

                        break;
                    case 'Z':
                    case 'z':
                        pRet = FindKthNodeFromEnd(pHead1,pTail1);

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
            printf("Exiting the RAJAS's SINGLY CIRCULAR LINKEDLIST application\n");
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


//5===============================================================================================//