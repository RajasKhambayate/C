////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program checks weather a number is prime or composite .                       //
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
//Check_Prime() Function: This function determines whether number is prime or composite .         //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value to determine prime or composite .                                    //
//================================================================================================//
//Return: boolean                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iFact) : To count the number of factors of 'iValue' .                                    //
//2. int(iCnt) : Loop counter variable .                                                          //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Initialize 'iFact' to 0.                                                                     //
//2. Loop 'iCnt' from 1 to 'iValue/2':                                                            //
//   a. If 'iValue' is divisible by 'iCnt', increment 'iFact'.                                    //
//3. End of loop.                                                                                 //
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Chk_Prime(int iValue)
{
    if((iValue == 0) || (iValue == 1))
    {
        return false;
    }

    int iFact = 0;

    for(int iCnt = 1;iCnt <= iValue/2;iCnt++)
    {
        if((iValue % iCnt) == 0)
        {
            iFact++;
        }
    }

    if(iFact == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Starting point of application
int main()
{
    int iNo = -1;

    while(1)
    {
        while(iNo < 0)
        {
            printf("\nPlease enter a positive integer value : ");
            scanf("%d",&iNo);

            if(iNo < 0)
            {
                continue;
            }
        }

        if(iNo == 0 || iNo == 1)
        {
            printf("0 and 1 are neither prime nor composite numbers .\n");
            printf("====================================================================================================\n");

            iNo = -1;

            continue;
        }

        bool bRet = Chk_Prime(iNo);
        if(bRet == true)
        {
            printf("\n%d : It is prime number\n",iNo);
        }
        else
        {
            printf("\n%d : It is composite number\n",iNo);
        }

        printf("Would you like to try Check_Prime one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ");
        scanf("%d",&iNo);

        if(iNo == 0)
        {
            printf("\n====================================================================================================\n");
            printf("Thank you for using Rajas's Check_Prime program .\n");
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