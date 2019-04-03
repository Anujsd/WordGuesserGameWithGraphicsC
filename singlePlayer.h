#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>

char* vowelsRemover2(char *str);
void showInterface2(int lives,char *formattedWord2);
void check2();
void inputFromFile();

char originalWord2[30],formattedWord2[30];
char words[100][20],input[20];
int wordsReadIn=0;

void singlePlayer()
{

    srand(time(NULL));
    char ch;
    int length,lives=3,correct=0;

    cleardevice();
    line(0,0,0,0);

    setfillstyle(WIDE_DOT_FILL,3);
    floodfill(0,0,WHITE);


    setcolor(RED);
    setbkcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(200,10,"LET\'S");
    setcolor(RED);
    setbkcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(200,70,"PLAY");
    setcolor(RED);
    setbkcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,6);
    outtextxy(85,130,"THE GAME");


    inputFromFile();
    int randomIndex=rand()%wordsReadIn;
    strcpy(originalWord2,words[randomIndex]);

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(20,250,"We have selected random word from database");

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(20,280,"you have to find that word");

    length=strlen(originalWord2);

    strcpy(formattedWord2,originalWord2);
    strcpy(formattedWord2,vowelsRemover2(formattedWord2));

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(20,350,"Formatted word is");

    setcolor(YELLOW);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(400,350,formattedWord2);

    setcolor(WHITE);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(20,400,"press Enter");
    getch();

    while(lives!=0)
    {
        setbkcolor(BLACK);
        cleardevice();
        showInterface2(lives,formattedWord2);
        ch=getch();
        for(int i=0;i<length;i++)
            {
                if(originalWord2[i]==ch&&(!(formattedWord2[i]==ch)))
                {
                    formattedWord2[i]=ch;
                    correct=1;
                }
            }

        check2();

        if(correct==0)
            {
                lives--;
                outtextxy(29,296,"You guessed wrong alphabet");
            }
        else
             outtextxy(29,296,"You have guessed correct alphabet");

        outtextxy(21,348,"Word after guessing alphabet is");
        outtextxy(474,350,formattedWord2);

        setcolor(WHITE);
        setbkcolor(GREEN);
        settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
        outtextxy(20,400,"press Enter");

        correct=0;
        setbkcolor(BLACK);
        getch();

    }
    cleardevice();

    setfillstyle(HATCH_FILL,YELLOW);
    floodfill(0,0,WHITE);
    setcolor(RED);
    setbkcolor(BLUE);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,5);
    outtextxy(40,200,"You lose the game");

    setcolor(RED);
    setbkcolor(GREEN);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,3);
    outtextxy(150,100,"Word was");
    outtextxy(350,100,originalWord2);

    getch();

}

char* vowelsRemover2(char *str)
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

void check2()
{
    if(strcmp(originalWord2,formattedWord2)==0)
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
            outtextxy(350,100,originalWord2);
            getch();
            exit(0);
        }
}

void showInterface2(int lives,char *formattedWord2)
{
    char livesch[1];
    sprintf(livesch,"%d",lives);


    setfillstyle(HATCH_FILL,RED);
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
    outtextxy(19,178,"Formatted word For You Is");

    setcolor(BLUE);
    setbkcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(420,177,formattedWord2);

    setcolor(BLUE);
    setbkcolor(YELLOW);
    settextstyle(DEFAULT_CHARSET,HORIZ_DIR,1);
    outtextxy(22,234,"Enter any character from a to z in smaller");
    outtextxy(22,255,"case for guessing hidden alphabet in word");



}

void inputFromFile()
{
    FILE *fp;
    fp=fopen("words.txt","r");
    if(fp==NULL)
    {
        outtextxy(100,100,"File not found\n");
        exit(0);
    }
    while(fgets(input,19,fp))
    {
        sscanf(input,"%s",words[wordsReadIn]);
        wordsReadIn++;
    }
    fclose(fp);

}

