#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

char* vowelsRemover(char *str);
void check();
void showInterface(int lives,char *formattedWord);

char originalWord[30],formattedWord[30];
char ch;
int length,lives=3,correct=0;

void multiPlayer()
{

/**first interface**/
    setfillstyle(HATCH_FILL,CYAN);
    floodfill(0,0,WHITE);

    setcolor(RED);
    setbkcolor(MAGENTA);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(200,10,"LET\'S");
    setcolor(RED);
    setbkcolor(MAGENTA);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(200,70,"PLAY");
    setcolor(RED);
    setbkcolor(MAGENTA);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(85,130,"THE GAME");


    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(24,250,"Enter a length of word");

    length=getch();
    length=length-48;
    char ch2[1];
    sprintf(ch2,"%d",length);

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(400,250,ch2);

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(24,300,"Enter a word");


    for(int i=0;i<length;i++)
        originalWord[i]=getch();
    originalWord[length]='\0';



    strcpy(formattedWord,originalWord);
    strcpy(formattedWord,vowelsRemover(formattedWord));

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(400,300,formattedWord);

    if(strcmp(originalWord,formattedWord)==0){

        setcolor(YELLOW);
        setbkcolor(GREEN);
        settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
        outtextxy(24,350,"There are no vowels in given");
        outtextxy(24,380,"word please enter another word");
        getch();
        exit(0);
    }

    setcolor(WHITE);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(20,400,"press Enter");

    getch();


    while(lives!=0)
    {
        cleardevice();

        setbkcolor(BLACK);

        showInterface(lives,formattedWord);
        ch=getch();
        for(int i=0;i<length;i++)
            {
                if(originalWord[i]==ch&&(!(formattedWord[i]==ch)))
                {
                    formattedWord[i]=ch;
                    correct=1;
                }
            }

        check();

        if(correct==0)
            {
                lives--;
                outtextxy(29,296,"you guessed wrong alphabet");
            }
        else
             outtextxy(29,296,"you have guessed correct alphabet");

        outtextxy(21,348,"word after guessing alphabet is");
        outtextxy(474,350,formattedWord);

        setcolor(BLACK);
        setbkcolor(GREEN);
        settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
        outtextxy(20,400,"press Enter");

        correct=0;

        getch();

    }
    cleardevice();

    setfillstyle(HATCH_FILL,CYAN);
    floodfill(0,0,WHITE);
    setcolor(RED);
    setbkcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,5);
    outtextxy(40,200,"You lose the game");

    setcolor(RED);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(150,100,"Word was");
    outtextxy(350,100,originalWord);


    getch();

}

char* vowelsRemover(char *str)
{
   char ch;
   for(int i=0;i<strlen(str);i++)
     {
        ch=str[i];
        if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='O'||ch=='o'||ch=='u'||ch=='U')
        str[i]='-';
     }
   return str;
}

void check()
{
    if(strcmp(originalWord,formattedWord)==0)
        {
            cleardevice();
            setfillstyle(HATCH_FILL,BLACK);
            floodfill(0,0,WHITE);
            setcolor(RED);
            setbkcolor(BLUE);
            settextstyle(DEFAULT_CHARSET,HORIZ_DIR,5);
            outtextxy(40,200,"You win the game");

            setcolor(RED);
            setbkcolor(GREEN);
            settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
            outtextxy(150,100,"Word was");
            outtextxy(350,100,originalWord);
            getch();
            exit(0);
        }
}

void showInterface(int lives,char *formattedWord)
{
    char livesch[1];
    sprintf(livesch,"%d",lives);


    setfillstyle(WIDE_DOT_FILL,MAGENTA);
    floodfill(0,0,WHITE);

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(450,15,"LIVES");

    setcolor(BLUE);
    setbkcolor(RED);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(565,15,livesch);

    setcolor(BLUE);
    setbkcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(15,95,"YOU NEED TO GUESS HIDDEN PART");
    outtextxy(15,116,"OF WORD TO WIN THE GAME");


    setcolor(BLUE);
    setbkcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(19,178,"Word For You Is");

    setcolor(BLUE);
    setbkcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(385,177,formattedWord);

    setcolor(BLUE);
    setbkcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(22,234,"Enter any character from a to z in smaller");
    outtextxy(22,255,"case for guessing hidden alphabet in word");



}
