/*
    Write a program that reads input lines one by one until end of file is reached,
    determines the length of each input line, and then prints out only the longest
    line that was found. To simplify matters, you may assume that no input line
    will be longer than 1000 characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 1001//no input line will be longer than 1000 characters

int main()
{
    char line[MAX_INPUT];
    int len;
    char longest[MAX_INPUT];
    int longest_len;

    longest_len = -1;//If you use 0 here ,then you need to use 1 at last.

    while(gets(line)!=NULL)
    {
        len=strlen(line);
        if(len>longest_len)
        {
            longest_len=len;
            strcpy(longest,line);
        }
    }

    if(longest_len>=0)
    {
        puts(longest);
    }

    return 0;
}
