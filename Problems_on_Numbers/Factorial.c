////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program performs factorial of a number .                                      //
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
//Factorial() Function: This function returns factorial of a number .                             //
//================================================================================================//
//Parameters:                                                                                     //
//1. int(iValue) : The value for calculating factorial .                                          //
//================================================================================================//
//Return: integer                                                                                 //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iCnt) : Loop counter variable .                                                          //
//2. int(iFactorial) : Variable to store factorial of a number .                                  //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Initialize iFactorial to 1 .                                                                 //
//2. Loop from 1 to iValue .                                                                      //
//3. Multiply iFactorial with iCnt in each iteration .                                            //
//4. Return iFactorial .                                                                          //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Factorial(int iValue)
{
    int iFactorial = 1;

    for(int iCnt = 1;iCnt <= iValue;iCnt++)
    {
        iFactorial = iFactorial * iCnt;
    }

    return iFactorial;
}

//Starting point of application
int main()
{
    int iNo = 0;
    int iRet = 0;

    while(1)
    {
        iNo = 0;

        while(iNo <= 0)
        {
            printf("Please enter a positive integer value : ");
            scanf("%d",&iNo);
        }

        iRet = Factorial(iNo);
        printf("Factorial of %d is : %d\n",iNo,iRet);

        printf("Would you like to try Factorial one more time? >Press for->YES:ANY_NUM OR NO:0 <=>Your Choice : ");
        scanf("%d",&iNo);

        if(iNo == 0)
        {
            printf("\n====================================================================================================\n");
            printf("Thank you for using Rajas's Factorial program .\n");
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