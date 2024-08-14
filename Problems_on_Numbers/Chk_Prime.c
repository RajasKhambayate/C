//This code checks weather a number is prime or composite.
#include<stdio.h>
#include<stdbool.h>

bool Chk_Prime(int iValue)
{
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

int main()
{
    int iNo = -1;

    while(iNo < 0)
    {
        printf("\n\nPlease enter a positive integer value : ");
        scanf("%d",&iNo);

        if(iNo < 0)
        {
            printf("Please enter a positive number\n");
        }
    }


    if((iNo == 0) || (iNo == 1))
    {
        printf("%d is neither prime nor composite\n",iNo);
        return 0;
    }

    bool bRet = Chk_Prime(iNo);
    if(bRet == true)
    {
        printf("%d is a prime number\n",iNo);
    }
    else
    {
        printf("%d is a composite number\n",iNo);
    }

    return 0;
}