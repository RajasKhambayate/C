////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program checks weather a number is even or odd .                                 //
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
#include<stdbool.h>//for boolean data type .


////////////////////////////////////////////////////////////////////////////////////////////////////
//Check_Prime() Function: This function checks weather a number is even or odd .                  //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value to determine even or odd .                                           //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables: None                                                                           //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Check if 'iValue' is even or odd using modulo operator .                                     //
//2. If 'iValue' is even, return true.                                                            //
//3. Else, return false.                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Check_Even(int iValue)
{
    if((iValue % 2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Starting point of the program
int main()
{
    int iNo = 0;

    while(1)
    {
        printf("Please enter a integer value : ");
        scanf("%d",&iNo);

        if(iNo == 0)
        {
            printf("Zero(0) is neither even nor odd\n");
            continue;
        }

        bool bRet = Check_Even(iNo);
        if(bRet == true)
        {
            printf("%d : It is even number\n",iNo);
        }
        else
        {
            printf("%d : It is odd number\n",iNo);
        }


        printf("Would you like to try Check_Even one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ");
        scanf("%d",&iNo);

        if(iNo == 0)
        {
            printf("\n====================================================================================================\n");
            printf("Thank you for using Rajas's Check_Even program .\n");
            break;
        }
        else
        {
            printf("====================================================================================================\n");
            iNo = -1;
            continue;
        }
    }

    return 0;
}