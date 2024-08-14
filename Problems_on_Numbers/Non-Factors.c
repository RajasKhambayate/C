//This code displays non-factors of a positive number.
#include<stdio.h>

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

int main()
{
    int iNo = 0;

    while(iNo <= 0)
    {
        printf("\n\nPlease enter a positive integer value : ");
        scanf("%d",&iNo);

        if(iNo <= 0)
        {
            printf("Please enter a positive number\n");
        }
    }

    Non_Factors(iNo);

    return 0;
}