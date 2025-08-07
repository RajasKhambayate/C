////////////////////////////////////////////////////////////////////////////////////////////////////
//Description: This program opens file using open system call .                                   //
//================================================================================================//
//Language: C                                                                                     //
//Compiler : GNU GCC                                                                              //
//IDE: Visual Studio code                                                                         //
//================================================================================================//
//Author/Coder: Rajas Khambayate                                                                  //
//Date: 07th August 2025                                                                          //
//Day: Thursday                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<fcntl.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//Open_File() Function: This function opens file using open system call and returns FD .          //
//================================================================================================//
//Parameters:                                                                                     //
//1. char *(argv) : The string as input for File_Name .                                           //
//================================================================================================//
//Return: int                                                                                     //
//================================================================================================//
//Local variables:                                                                                //
//1. int(iFile_Descriptor)   : variable to store File_Descriptor of opened file .                 //
//================================================================================================//
//Algorithm:                                                                                      //
//1. Open File using open() system call .                                                         //
////////////////////////////////////////////////////////////////////////////////////////////////////
int Open_File(char *argv)
{
    int File_Descriptor = 0;

    File_Descriptor = open(argv,O_RDWR);//Opens file in read & write mode .

    return File_Descriptor;
}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"!!Invalid number of Arguments , seems like you forgot to mention File_Name as argument!!\n");
        printf("Create Application  : g++ Open_File.cpp -o open\n");
        printf("Usage               : ./open File_Name\n");
        return -1;
    }

    int iRet = Open_File(argv[1]);

    if(iRet == -1)
    {
        perror("Unable to Open File ");
        return -1;
    }
    else
    {
        printf("File is successfully opened with File_Descriptor : %d\n",iRet);
        close(iRet);
    }

    return 0;
}