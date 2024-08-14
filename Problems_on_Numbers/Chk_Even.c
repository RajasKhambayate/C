//This code checks weather a number is even or odd.
#include<stdio.h>
#include<stdbool.h>

bool Chk_Even(int iValue)
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

int main()
{
    int iNo = 0;
    printf("Please enter a integer value : ");
    scanf("%d",&iNo);

    if(iNo == 0)
    {
        printf("zero is neither even nor odd\n");
        return 0;
    }

    bool bRet = Chk_Even(iNo);
    if(bRet == true)
    {
        printf("%d is a even number\n",iNo);
    }
    else
    {
        printf("%d is a odd number\n",iNo);
    }

    return 0;
}