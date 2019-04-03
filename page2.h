#include<graphics.h>
#include<conio.h>
#include<windows.h>


void page2()
{
    cleardevice();
    setfillstyle(HATCH_FILL,6);
    floodfill(0,0,WHITE);

    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,7);
    setcolor(RED);
    setbkcolor(9);
    outtextxy(25,100,"LOADING...");

    for(int i=0;i<400;i++)
    {
        Sleep(1);
        setcolor(YELLOW);
        line(98+i,229,98+i,275);
    }

    setbkcolor(BLACK);
}
