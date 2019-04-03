#include<stdio.h>
#include"page1.h"
#include"page2.h"
#include"singlePlayer.h"
#include"multiPlayer.h"


int main()
{
    int choice;
    choice=page1();


    switch(choice)
    {
    case 1:
        page2();
        singlePlayer();
        break;
    case 2:
        page2();
        multiPlayer();
        break;
    case 3:
    default:
        printf("please enter options from given below\n");;
    }

}
