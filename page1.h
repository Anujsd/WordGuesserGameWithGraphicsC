#include<graphics.h>
#include<stdio.h>

int page1()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int x=getmaxx();
    int y=getmaxy();

    setfillstyle(LINE_FILL,8);
    floodfill(0,0,WHITE);

    setcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,8);
    setbkcolor(1);
    outtextxy(110,10,"WORD");

    setcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,8);
    setbkcolor(7);
    outtextxy(10,90,"GUESSER");

    setcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,8);
     setbkcolor(3);
    outtextxy(110,178,"GAME");



    setcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
     setbkcolor(7);
    outtextxy(270,363,"S FOR SINGLE PLAYER");


    setcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
     setbkcolor(3);
    outtextxy(270,395,"M FOR MULTI-PLAYER");

    setcolor(WHITE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    setbkcolor(3);
    outtextxy(270,430,"ANY KEY TO EXIT");

    char input;
    input=getch();
    if(input=='S'||input=='s')
        return 1;
    else if(input=='M'||input=='m')
        return 2;
    else
        return 3;


    cleardevice();
    closegraph();

}
