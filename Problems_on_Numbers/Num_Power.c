//This code display the number rays to some power.
#include<stdio.h>

int Num_Power(int iValue,int Power)
{
    if(iValue == 0)//(Value == 0) && (Power == +,0)
    {
        return 0;
    }
    else if((iValue != 0) && (Power == 0))//(Value != 0) && (Power == 0)
    {
        return 1;
    }
    else if(iValue == 1)//(Value == 1) && (Power == +,0)
    {
        return 1;
    }
    else if((iValue > 0) && (Power > 0))//(Value == +) && (Power == +)
    {
        int iAns = 1;

        for(int iCnt = 0;iCnt < Power;iCnt++)
        {
            iAns = iAns * iValue;
        }

        return iAns;
    }
}

int main()
{
    int iNo = -1;
    int iPower = -1;

    while((iNo < 0) || (iPower < 0))
    {
        printf("\nEnter the integer value : ");
        scanf("%d",&iNo);


        printf("Enter the positive integer power : ");
        scanf("%d",&iPower);

        if(iNo < 0)
        {
            printf("!!Please enter positive value!!\n");
        }

        if(iPower < 0)
        {
            printf("!!Please enter positive power!!\n");
        }
    }

    int iRet = Num_Power(iNo,iPower);
    printf("\n%d^%d = %d\n",iNo,iPower,iRet);

    return 0;
}