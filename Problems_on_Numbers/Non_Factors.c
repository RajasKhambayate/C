////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program displays non-factors of a number .                                    //
//================================================================================================//
//Language: C                                                                                     //
//Compiler : GNU GCC                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 16th May 2025                                                                             //
//Day: Friday                                                                                     //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>//for printf and scanf functions .


////////////////////////////////////////////////////////////////////////////////////////////////////
//Non_Factors() Function: This function displays non-factors of a number.                         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value for calculating factors .                                            //
//================================================================================================//
//Return: void                                                                                    //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Loop 'iCnt' from 1 to 'iValue':                                                              //
//   a. If 'iValue' is not divisible by 'iCnt', print 'iCnt'.                                     //
//2. End of loop.                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
void Non_Factors(int iValue)
{
    for(int iCnt = 1;iCnt <= iValue;iCnt++)
    {
        if((iValue % iCnt) != 0)
        {
            printf("%d\n",iCnt);
        }
    }
}

//Starting point of application
int main()
{
    int iNo = 0;

    while(1)
    {
        iNo = 0;

        while(iNo <= 0)
        {
            printf("Please enter a positive integer value : ");
            scanf("%d",&iNo);
        }

        printf("Would you like to try Non_Factors one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ");
        scanf("%d",&iNo);

        if(iNo == 0)
        {
            printf("\n====================================================================================================\n");
            printf("Thank you for using Rajas's Non_Factors program .\n");
            break;
        }
        else
        {
            printf("====================================================================================================\n");
            continue;
        }
    }

    return 0;
}