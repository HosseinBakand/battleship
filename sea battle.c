#include<stdio.h>
#include<graphics.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 10
#define WIDTH 900
#define HEIGHT 600
#define BLOCK 37.5
#define SHIP 50
#define SHIP21 51
#define SHIP22 52
#define SHIP23 53
#define SHIP31 54
#define SHIP32 55
#define NEAR 25
#define SHIPBOMB 75
#define SHIPBOMB21 76
#define SHIPBOMB22 77
#define SHIPBOMB23 78
#define SHIPBOMB31 79
#define SHIPBOMB32 80
#define BOMB 100
#define FINISHSHIP 125
#define FINISHSHIP21 126
#define FINISHSHIP22 127
#define FINISHSHIP23 128
#define FINISHSHIP31 129
#define FINISHSHIP32 130

/*kashti = 50
kenar kashti = 25
empty = 0*/
int i,j,i1,j1,nobat=0,hoosh;
char numstring[6][2]={"0","1","2","3","4","5"};
struct Game
{
    int boardplayer[SIZE][SIZE];
    int boardfile[SIZE][SIZE];
    int boardpc[SIZE][SIZE];
    int locat[2];
    int finishnumberpl;
    int finishnumberpc;
    char playername[100];
    int history[2];
}game;
struct Kashti
{
    int kastipc;
    int kasti2pc;
    int kasti3pc;
    int kastipl;
    int kasti2pl;
    int kasti3pl;
}kash;
int check(int x,int y)
{
    if(x<0 || x>=SIZE || y<0 || y>=SIZE)
        return 0;
    return 1;
}

int isfull(int fl[SIZE][SIZE],int x,int y)
{
    if(check(x,y))
        {
            if(fl[x][y]== SHIP)
                return 3;
            else if(fl[x][y]== SHIP31)
                return 4;
            else if(fl[x][y]== SHIP32)
                return 5;
            else if(fl[x][y]== SHIP21)
                return 6;
            else if(fl[x][y]== SHIP22)
                return 7;
            else if(fl[x][y]== SHIP23)
                return 8;
            else if(fl[x][y]== NEAR)
                return 2;

            else
                return 1;
        }
    else
        return 0;
}
void Clearmap()
{
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            game.boardplayer[i][j]=0;
            game.boardpc[i][j]=0;
        }
    }
}
void random3(int map[SIZE][SIZE],int ship)
{
    j=1;
    int randomX,randomY,to;
    while(j)
    {
        randomX=rand()%SIZE;
        randomY=rand()%SIZE;
        to=rand()%4;

        switch(to)
        {
            case 0:
               if(isfull(map,randomX,randomY)==1 && isfull(map,randomX,randomY-1)==1 && isfull(map,randomX,randomY-2)==1)
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX][randomY-1]=ship;
                   map[randomX][randomY-2]=ship;
                   for(i1=randomX-1;i1<=randomX+1;i1++)
                    {
                        for(j1=randomY-3;j1<=randomY+1;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }
            break;
            case 1:
                if(isfull(map,randomX,randomY)==1 && isfull(map,randomX+1,randomY)==1 && isfull(map,randomX+2,randomY)==1)
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX+1][randomY]=ship;
                   map[randomX+2][randomY]=ship;
                   for(i1=randomX-1;i1<randomX+4;i1++)
                    {
                        for(j1=randomY-1;j1<randomY+2;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }
           break;
            case 2:
                if(isfull(map,randomX,randomY) && isfull(map,randomX,randomY+1) && isfull(map,randomX,randomY+2))
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX][randomY+1]=ship;
                   map[randomX][randomY+2]=ship;
                   for(i1=randomX-1;i1<randomX+2;i1++)
                    {
                        for(j1=randomY-1;j1<randomY+4;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }
            break;
            case 3:
                if(isfull(map,randomX,randomY)==1 && isfull(map,randomX-1,randomY)==1 && isfull(map,randomX-2,randomY)==1)
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX-1][randomY]=ship;
                   map[randomX-2][randomY]=ship;
                   for(i1=randomX-3;i1<randomX+2;i1++)
                    {
                        for(j1=randomY-1;j1<randomY+2;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }

        }

    }
}
void random2(int map[SIZE][SIZE],int ship)
{
    j=1;
    int randomX,randomY,to;
    while(j)
    {
        randomX=rand()%SIZE;
        randomY=rand()%SIZE;
        to=rand()%4;

        switch(to)
        {
            case 0:
               if(isfull(map,randomX,randomY)==1 && isfull(map,randomX,randomY-1)==1  )
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX][randomY-1]=ship;

                   for(i1=randomX-1;i1<=randomX+1;i1++)
                    {
                        for(j1=randomY-2;j1<=randomY+1;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }
            break;
            case 1:
                if(isfull(map,randomX,randomY)==1 && isfull(map,randomX+1,randomY)==1)
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX+1][randomY]=ship;

                   for(i1=randomX-1;i1<randomX+3;i1++)
                    {
                        for(j1=randomY-1;j1<randomY+2;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }
           break;
            case 2:
                if(isfull(map,randomX,randomY)==1 && isfull(map,randomX,randomY+1)==1 )
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX][randomY+1]=ship;

                   for(i1=randomX-1;i1<randomX+2;i1++)
                    {
                        for(j1=randomY-1;j1<randomY+3;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }
            break;
            case 3:
                if(isfull(map,randomX,randomY)==1 && isfull(map,randomX-1,randomY)==1 )
               {
                   j=0;
                   map[randomX][randomY]=ship;
                   map[randomX-1][randomY]=ship;

                   for(i1=randomX-2;i1<randomX+2;i1++)
                    {
                        for(j1=randomY-1;j1<randomY+2;j1++)
                        {
                            if(check(i1,j1) && map[i1][j1]!=ship)
                                map[i1][j1]=NEAR;
                        }
                    }
               }

        }

    }
}
void random(int map[SIZE][SIZE])
{

    i=0;
    int randomX,randomY,to;
    //to 0=up 1=right 2=down 3=left

    random3(map,SHIP31);
    random3(map,SHIP32);
    random2(map,SHIP21);
    random2(map,SHIP22);
    random2(map,SHIP23);

    i=0;
    while(i<5)
    {
        randomX=rand()%SIZE;
        randomY=rand()%SIZE;
        if(isfull(map,randomX,randomY)==1)
        {
            i++;
            map[randomX][randomY]=SHIP;
            for(i1=randomX-1;i1<randomX+2;i1++)
            {
                for(j1=randomY-1;j1<randomY+2;j1++)
                {
                    if(check(i1,j1) && map[i1][j1]!=SHIP)
                        map[i1][j1]=NEAR;
                }
            }
        }
    }

}
void drawboardplayer()
{

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            int left,top;
            left=25+j*(BLOCK+1);
            top=25+i*(BLOCK+1);
            int color;
            if(game.boardplayer[i][j]==SHIP || game.boardplayer[i][j]==SHIP31 || game.boardplayer[i][j]==SHIP32 || game.boardplayer[i][j]==SHIP21 || game.boardplayer[i][j]==SHIP22 || game.boardplayer[i][j]==SHIP23 )
                {
                    //color=GREEN;
                    setfillstyle(SOLID_FILL,GREEN);
                    bar(left,top,left+BLOCK,top+BLOCK);
                }
            else if(game.boardplayer[i][j]==SHIPBOMB || game.boardplayer[i][j]==SHIPBOMB31 || game.boardplayer[i][j]==SHIPBOMB32 || game.boardplayer[i][j]==SHIPBOMB21 || game.boardplayer[i][j]==SHIPBOMB22 || game.boardplayer[i][j]==SHIPBOMB23)
                {
                    //color=COLOR(237,28,36);
                    setfillstyle(SOLID_FILL,COLOR(237,28,36));
                    bar(left,top,left+BLOCK,top+BLOCK);
                }
            else if(game.boardplayer[i][j]==BOMB)
                {
                    color=LIGHTGRAY;
                    setfillstyle(SLASH_FILL,LIGHTGRAY);
                    bar(left,top,left+BLOCK,top+BLOCK);
                }
            //else if(game.boardplayer[i][j]==NEAR)
                //color=YELLOW;

            else if(game.boardplayer[i][j]==FINISHSHIP || game.boardplayer[i][j]==FINISHSHIP21 || game.boardplayer[i][j]==FINISHSHIP22 || game.boardplayer[i][j]==FINISHSHIP23 || game.boardplayer[i][j]==FINISHSHIP31 || game.boardplayer[i][j]==FINISHSHIP32)
                {
                    //color=RED;
                    setfillstyle(SOLID_FILL,RED);
                    bar(left,top,left+BLOCK,top+BLOCK);
                }
           /* setbkcolor(COLOR(73,29,11));
           settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
            outtextxy(275,465,numstring[kash.kastipl]);
            outtextxy(275,510,numstring[kash.kasti2pl]);
            outtextxy(275,555,numstring[kash.kasti3pl]);*/
            //else
                    //color=WHITE;

        }
    }

}

void drawboardpc()
{

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {


            int left,top;
            left=500+j*(BLOCK+1);
            top=25+i*(BLOCK+1);
            int color;

            //else if(game.boardpc[i][j]==SHIP || game.boardpc[i][j]==SHIP31 || game.boardpc[i][j]==SHIP32 || game.boardpc[i][j]==SHIP21 || game.boardpc[i][j]==SHIP22 || game.boardpc[i][j]==SHIP23)
               // color=GREEN;
            if(game.boardpc[i][j]==SHIPBOMB || game.boardpc[i][j]==SHIPBOMB31 || game.boardpc[i][j]==SHIPBOMB32 || game.boardpc[i][j]==SHIPBOMB21 || game.boardpc[i][j]==SHIPBOMB22 || game.boardpc[i][j]==SHIPBOMB23 )
            {
                //color=COLOR(237,28,36);
                //readimagefile("F:/proje payan term/proje/payanterm/pak.gif",left,top,left+BLOCK,top+BLOCK);
                setfillstyle(SOLID_FILL,COLOR(237,28,36));
                bar(left,top,left+BLOCK,top+BLOCK);
            }
            else if(game.boardpc[i][j]==BOMB)
            {
                //color=LIGHTGRAY;
                setfillstyle(SLASH_FILL,LIGHTGRAY);
                bar(left,top,left+BLOCK,top+BLOCK);
            }

            //else if(game.boardpc[i][j]==NEAR)
                //color=YELLOW;
            else if(game.boardpc[i][j]==FINISHSHIP || game.boardpc[i][j]==FINISHSHIP21 || game.boardpc[i][j]==FINISHSHIP22 || game.boardpc[i][j]==FINISHSHIP23 || game.boardpc[i][j]==FINISHSHIP31 || game.boardpc[i][j]==FINISHSHIP32)
            {
                //color=RED;
                setfillstyle(SOLID_FILL,RED);
                bar(left,top,left+BLOCK,top+BLOCK);
            }
            if(game.locat[0]==i && game.locat[1]==j)
            {
                //color=LIGHTBLUE;
                setfillstyle(INTERLEAVE_FILL,LIGHTBLUE);
                bar(left,top,left+BLOCK,top+BLOCK);
            }
           /* setbkcolor(COLOR(73,29,11));
           settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
            outtextxy(620,465,numstring[kash.kastipc]);
            outtextxy(620,510,numstring[kash.kasti2pc]);
            outtextxy(620,555,numstring[kash.kasti3pc]);*/
            //else
                    //color=WHITE;

        }

    }

}
void setlocat(int x,int y)
{
    if(!check(x,y))
        return ;
    else
    {
        game.locat[0]=x;
        game.locat[1]=y;
    }
}
void locatdown()
     {
         setlocat(game.locat[0]+1,game.locat[1]);
     }
void locatup()
     {
         setlocat(game.locat[0]-1,game.locat[1]);
     }
void locatleft()
     {
         setlocat(game.locat[0],game.locat[1]-1);
     }
void locatright()
     {
         setlocat(game.locat[0],game.locat[1]+1);
     }

int finish(int map[SIZE][SIZE],int ship,int x,int y)
{
    i1=0;
    for(i=x-2;i<x+3;i++)
    {
        for(j=y-2;j<y+3;j++)
        {
            if((map[i][j]==ship )&& check(x,y))
                i1++;
        }
    }
    if(i1==0)
        return 1;
    else
        return 0;
}
int deletenear(int map[SIZE][SIZE],int x,int y)
{

    if(y==0)
    {
        for(i=x-1;i<x+2;i++)
        {
            for(j=y;j<y+2;j++)
            {
                if(map[i][j]==NEAR && check(x,y))
                    map[i][j]=BOMB;
            }
        }
    }
    else if(y==9)
    {
        for(i=x-1;i<x+2;i++)
        {
            for(j=y-1;j<y+1;j++)
            {
                if(map[i][j]==NEAR && check(x,y))
                    map[i][j]=BOMB;
            }
        }
    }
    else
    {
        for(i=x-1;i<x+2;i++)
        {
            for(j=y-1;j<y+2;j++)
            {
                if(map[i][j]==NEAR && check(x,y))
                    map[i][j]=BOMB;
            }
        }
    }
}
void deletenear2(int map[SIZE][SIZE],int finship,int x,int y)
{

    for(i=x-2;i<x+3;i++)
    {
        for(j=y-2;j<y+3;j++)
        {
            if(map[i][j]==finship)
               deletenear(map,i,j);

        }
    }

}
void deletenear3(int map[SIZE][SIZE],int finship,int x,int y)
{
    int m,n;
     for(i=x-2;i<x+3;i++)
    {
        for(j=y-2;j<y+3;j++)
        {
            if(map[i][j]==finship)
              {
                  n=i;
                  m=j;

              }

        }
    }

    deletenear(map,n,m);
}
void shipbomb(int map[SIZE][SIZE],int shipbomb,int finship,int x,int y)
{
    for(i=x-2;i<x+3;i++)
    {
        for(j=y-2;j<y+3;j++)
        {
            if(map[i][j]==shipbomb && check(i,j))
                map[i][j]=finship;
        }
    }
}
void putbombplayer()
{

    if (isfull(game.boardpc,game.locat[0],game.locat[1])==3)//ship
    {
        nobat=0;
        game.boardpc[game.locat[0]][game.locat[1]]=FINISHSHIP;
        game.finishnumberpc++;
        deletenear(game.boardpc,game.locat[0],game.locat[1]);
        kash.kastipc--;

    }
    else if(isfull(game.boardpc,game.locat[0],game.locat[1])==4)//ship31
    {
        nobat=0;
        game.boardpc[game.locat[0]][game.locat[1]]=SHIPBOMB31;
        if(finish(game.boardpc ,SHIP31,game.locat[0],game.locat[1]))
            {
                game.boardpc[game.locat[0]][game.locat[1]]=FINISHSHIP31;
                shipbomb(game.boardpc,SHIPBOMB31,FINISHSHIP31,game.locat[0],game.locat[1]);
                deletenear2(game.boardpc,FINISHSHIP31,game.locat[0],game.locat[1]);
                deletenear3(game.boardpc,FINISHSHIP31,game.locat[0],game.locat[1]);
                deletenear(game.boardpc,game.locat[0],game.locat[1]);
                game.finishnumberpc++;
                kash.kasti3pc--;

            }
    }
     else if(isfull(game.boardpc,game.locat[0],game.locat[1])==5)//32
    {
        nobat=0;
        game.boardpc[game.locat[0]][game.locat[1]]=SHIPBOMB32;
        if(finish(game.boardpc,SHIP32 ,game.locat[0],game.locat[1]))
            {
                game.boardpc[game.locat[0]][game.locat[1]]=FINISHSHIP32;
                shipbomb(game.boardpc,SHIPBOMB32,FINISHSHIP32,game.locat[0],game.locat[1]);
                deletenear2(game.boardpc,FINISHSHIP32,game.locat[0],game.locat[1]);
                deletenear3(game.boardpc,FINISHSHIP32,game.locat[0],game.locat[1]);
                deletenear(game.boardpc,game.locat[0],game.locat[1]);
                game.finishnumberpc++;
                kash.kasti3pc--;

            }
    }
     else if(isfull(game.boardpc,game.locat[0],game.locat[1])==6)//21
    {
        nobat=0;
        game.boardpc[game.locat[0]][game.locat[1]]=SHIPBOMB21;
        if(finish(game.boardpc,SHIP21 ,game.locat[0],game.locat[1]))
            {
                game.boardpc[game.locat[0]][game.locat[1]]=FINISHSHIP21;
                shipbomb(game.boardpc,SHIPBOMB21,FINISHSHIP21,game.locat[0],game.locat[1]);
                deletenear2(game.boardpc,FINISHSHIP21,game.locat[0],game.locat[1]);
                deletenear3(game.boardpc,FINISHSHIP21,game.locat[0],game.locat[1]);
                deletenear(game.boardpc,game.locat[0],game.locat[1]);
                game.finishnumberpc++;
                kash.kasti2pc--;
            }
    }
     else if(isfull(game.boardpc,game.locat[0],game.locat[1])==7)//22
    {
        nobat=0;
        game.boardpc[game.locat[0]][game.locat[1]]=SHIPBOMB22;
        if(finish(game.boardpc,SHIP22 ,game.locat[0],game.locat[1]))
            {
                game.boardpc[game.locat[0]][game.locat[1]]=FINISHSHIP22;
                shipbomb(game.boardpc,SHIPBOMB22,FINISHSHIP22,game.locat[0],game.locat[1]);
                deletenear2(game.boardpc,FINISHSHIP22,game.locat[0],game.locat[1]);
                deletenear3(game.boardpc,FINISHSHIP22,game.locat[0],game.locat[1]);
                deletenear(game.boardpc,game.locat[0],game.locat[1]);
                game.finishnumberpc++;
                kash.kasti2pc--;
            }
    }
     else if(isfull(game.boardpc,game.locat[0],game.locat[1])==8)//23
    {
        nobat=0;
        game.boardpc[game.locat[0]][game.locat[1]]=SHIPBOMB23;
        if(finish(game.boardpc,SHIP23 ,game.locat[0],game.locat[1]))
            {
                game.boardpc[game.locat[0]][game.locat[1]]=FINISHSHIP23;
                shipbomb(game.boardpc,SHIPBOMB23,FINISHSHIP23,game.locat[0],game.locat[1]);
                deletenear2(game.boardpc,FINISHSHIP23,game.locat[0],game.locat[1]);
                deletenear3(game.boardpc,FINISHSHIP23,game.locat[0],game.locat[1]);
                deletenear(game.boardpc,game.locat[0],game.locat[1]);
                game.finishnumberpc++;
                kash.kasti2pc--;
            }
    }
    else if(game.boardpc[game.locat[0]][game.locat[1]]==BOMB || game.boardpc[game.locat[0]][game.locat[1]]==FINISHSHIP || game.boardpc[game.locat[0]][game.locat[1]]==FINISHSHIP21 || game.boardpc[game.locat[0]][game.locat[1]]==FINISHSHIP22 || game.boardpc[game.locat[0]][game.locat[1]]==FINISHSHIP23 || game.boardpc[game.locat[0]][game.locat[1]]==FINISHSHIP31 || game.boardpc[game.locat[0]][game.locat[1]]==FINISHSHIP32  || game.boardpc[game.locat[0]][game.locat[1]]==SHIPBOMB || game.boardpc[game.locat[0]][game.locat[1]]==SHIPBOMB21 || game.boardpc[game.locat[0]][game.locat[1]]==SHIPBOMB22 || game.boardpc[game.locat[0]][game.locat[1]]==SHIPBOMB23 || game.boardpc[game.locat[0]][game.locat[1]]==SHIPBOMB31 || game.boardpc[game.locat[0]][game.locat[1]]==SHIPBOMB32)
        nobat=0;
    else
    {
        game.boardpc[game.locat[0]][game.locat[1]]=BOMB;
         nobat=1;
    }

}
void putbombpc(int x,int y)
{
    if (isfull(game.boardplayer,x,y)==3)
        {
            nobat=1;
            deletenear(game.boardplayer,x,y);
            game.boardplayer[x][y]=FINISHSHIP;
            game.history[0]=FINISHSHIP;
            game.finishnumberpl++;
            kash.kastipl--;
        }
    else if (isfull(game.boardplayer,x,y)==4)//31
        {
            nobat=1;
            game.history[0]=x;
            game.history[1]=y;
            game.boardplayer[x][y]=SHIPBOMB31;
            if(finish(game.boardplayer,SHIP31 ,x,y))
            {
                game.boardplayer[x][y]=FINISHSHIP31;
                shipbomb(game.boardplayer,SHIPBOMB31,FINISHSHIP31,x,y);
                deletenear2(game.boardplayer,FINISHSHIP31,x,y);
                deletenear3(game.boardplayer,FINISHSHIP31,x,y);
                game.history[0]=FINISHSHIP;
                deletenear(game.boardplayer,x,y);
                game.finishnumberpl++;
                kash.kasti3pl--;
            }
        }
        else if (isfull(game.boardplayer,x,y)==5)//32
        {
            nobat=1;
            game.history[0]=x;
            game.history[1]=y;
            game.boardplayer[x][y]=SHIPBOMB32;
            if(finish(game.boardplayer,SHIP32 ,x,y))
            {
                game.boardplayer[x][y]=FINISHSHIP32;
                shipbomb(game.boardplayer,SHIPBOMB32,FINISHSHIP32,x,y);
                deletenear2(game.boardplayer,FINISHSHIP32,x,y);
                deletenear3(game.boardplayer,FINISHSHIP32,x,y);
                game.history[0]=FINISHSHIP;
                deletenear(game.boardplayer,x,y);
                game.finishnumberpl++;
                kash.kasti3pl--;
            }
        }
        else if (isfull(game.boardplayer,x,y)==6)//21
        {
            nobat=1;
            game.history[0]=x;
            game.history[1]=y;
            game.boardplayer[x][y]=SHIPBOMB21;
            if(finish(game.boardplayer,SHIP21 ,x,y))
            {

                game.boardplayer[x][y]=FINISHSHIP21;
                shipbomb(game.boardplayer,SHIPBOMB21,FINISHSHIP21,x,y);
                deletenear2(game.boardplayer,FINISHSHIP21,x,y);
                deletenear3(game.boardplayer,FINISHSHIP21,x,y);
                game.history[0]=FINISHSHIP;
                deletenear(game.boardplayer,x,y);
                game.finishnumberpl++;
                kash.kasti2pl--;
            }
        }
        else if (isfull(game.boardplayer,x,y)==7)//22
        {
            nobat=1;
            game.history[0]=x;
            game.history[1]=y;
            game.boardplayer[x][y]=SHIPBOMB22;
            if(finish(game.boardplayer,SHIP22 ,x,y))
            {

                game.boardplayer[x][y]=FINISHSHIP22;
                shipbomb(game.boardplayer,SHIPBOMB22,FINISHSHIP22,x,y);
                deletenear2(game.boardplayer,FINISHSHIP22,x,y);
                deletenear3(game.boardplayer,FINISHSHIP22,x,y);
                game.history[0]=FINISHSHIP;
                deletenear(game.boardplayer,x,y);
                game.finishnumberpl++;
                kash.kasti2pl--;
            }
        }
        else if (isfull(game.boardplayer,x,y)==8)//23
        {
            nobat=1;
            game.history[0]=x;
            game.history[1]=y;
            game.boardplayer[x][y]=SHIPBOMB23;
            if(finish(game.boardplayer,SHIP23 ,x,y))
            {

                game.boardplayer[x][y]=FINISHSHIP23;
                shipbomb(game.boardplayer,SHIPBOMB23,FINISHSHIP23,x,y);
                deletenear2(game.boardplayer,FINISHSHIP23,x,y);
                deletenear3(game.boardplayer,FINISHSHIP23,x,y);
                game.history[0]=FINISHSHIP;
                deletenear(game.boardplayer,x,y);
                game.finishnumberpl++;
                kash.kasti2pl--;
            }
        }
    else if(game.boardplayer[x][y]==BOMB || game.boardplayer[x][y]==FINISHSHIP || game.boardplayer[x][y]==FINISHSHIP21 || game.boardplayer[x][y]==FINISHSHIP22 || game.boardplayer[x][y]==FINISHSHIP23 || game.boardplayer[x][y]==FINISHSHIP31 || game.boardplayer[x][y]==FINISHSHIP32 || game.boardplayer[x][y]==SHIPBOMB || game.boardplayer[x][y]==SHIPBOMB31 || game.boardplayer[x][y]==SHIPBOMB32 || game.boardplayer[x][y]==SHIPBOMB21 || game.boardplayer[x][y]==SHIPBOMB22 || game.boardplayer[x][y]==SHIPBOMB23)
        nobat=1;
    else
    {
        game.boardplayer[x][y]=BOMB;
        nobat=0;
        game.history[0]=BOMB;
    }
}
int search()
{
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(game.boardplayer[i][j]==SHIPBOMB21 || game.boardplayer[i][j]==SHIPBOMB22 || game.boardplayer[i][j]==SHIPBOMB23 || game.boardplayer[i][j]==SHIPBOMB31 || game.boardplayer[i][j]==SHIPBOMB32)
            {
                game.history[0]=i;
                game.history[1]=j;
                return 1;

            }
        }
    }
    return 0;
}
void mind()
{
    int to;
        to=rand()%4;
        switch(to)
        {
            printf("%d",to);
            case 0://up
                if(game.boardplayer[game.history[0]-1][game.history[1]]!=BOMB && game.boardplayer[game.history[0]-1][game.history[1]]!=SHIPBOMB && game.boardplayer[game.history[0]-1][game.history[1]]!=SHIPBOMB31 && game.boardplayer[game.history[0]-1][game.history[1]]!=SHIPBOMB32 && game.boardplayer[game.history[0]-1][game.history[1]]!=SHIPBOMB21 && game.boardplayer[game.history[0]-1][game.history[1]]!=SHIPBOMB22 && game.boardplayer[game.history[0]-1][game.history[1]]!=SHIPBOMB23 )
                {
                    putbombpc(game.history[0]-1,game.history[1]);
                    return;
                }
                else  if(game.boardplayer[game.history[0]][game.history[1]-2]!=BOMB && game.boardplayer[game.history[0]][game.history[1]-2]!=SHIPBOMB && game.boardplayer[game.history[0]][game.history[1]-2]!=SHIPBOMB31 && game.boardplayer[game.history[0]][game.history[1]-2]!=SHIPBOMB32 && game.boardplayer[game.history[0]][game.history[1]-2]!=SHIPBOMB21 && game.boardplayer[game.history[0]][game.history[1]-2]!=SHIPBOMB22 && game.boardplayer[game.history[0]][game.history[1]-2]!=SHIPBOMB23 )
                    {
                        putbombpc(game.history[0],game.history[1]-2);
                        return;
                    }
             case 1://right
                if(game.boardplayer[game.history[0]][game.history[1]+1]!=BOMB && game.boardplayer[game.history[0]][game.history[1]+1]!=SHIPBOMB && game.boardplayer[game.history[0]][game.history[1]+1]!=SHIPBOMB31 && game.boardplayer[game.history[0]][game.history[1]+1]!=SHIPBOMB32 && game.boardplayer[game.history[0]][game.history[1]+1]!=SHIPBOMB21 && game.boardplayer[game.history[0]][game.history[1]+1]!=SHIPBOMB22 && game.boardplayer[game.history[0]][game.history[1]+1]!=SHIPBOMB23 )
                {
                    putbombpc(game.history[0],game.history[1]+1);
                    return;
                }
                else if(game.boardplayer[game.history[0]][game.history[1]+2]!=BOMB && game.boardplayer[game.history[0]][game.history[1]+2]!=SHIPBOMB && game.boardplayer[game.history[0]][game.history[1]+2]!=SHIPBOMB31 && game.boardplayer[game.history[0]][game.history[1]+2]!=SHIPBOMB32 && game.boardplayer[game.history[0]][game.history[1]+2]!=SHIPBOMB21 && game.boardplayer[game.history[0]][game.history[1]+2]!=SHIPBOMB22 && game.boardplayer[game.history[0]][game.history[1]+2]!=SHIPBOMB23 )
                    {
                        putbombpc(game.history[0],game.history[1]+2);
                        return;
                    }
            case 2://down
                if(game.boardplayer[game.history[0]+1][game.history[1]]!=BOMB && game.boardplayer[game.history[0]+1][game.history[1]]!=SHIPBOMB && game.boardplayer[game.history[0]+1][game.history[1]]!=SHIPBOMB31 && game.boardplayer[game.history[0]+1][game.history[1]]!=SHIPBOMB32 && game.boardplayer[game.history[0]+1][game.history[1]]!=SHIPBOMB21 && game.boardplayer[game.history[0]+1][game.history[1]]!=SHIPBOMB22 && game.boardplayer[game.history[0]+1][game.history[1]]!=SHIPBOMB23)
                {
                    putbombpc(game.history[0]+1,game.history[1]);
                    return;
                }
                else if(game.boardplayer[game.history[0]+2][game.history[1]]!=BOMB && game.boardplayer[game.history[0]+2][game.history[1]]!=SHIPBOMB && game.boardplayer[game.history[0]+2][game.history[1]]!=SHIPBOMB31 && game.boardplayer[game.history[0]+2][game.history[1]]!=SHIPBOMB32 && game.boardplayer[game.history[0]+2][game.history[1]]!=SHIPBOMB21 && game.boardplayer[game.history[0]+2][game.history[1]]!=SHIPBOMB22 && game.boardplayer[game.history[0]+2][game.history[1]]!=SHIPBOMB23)
                {
                    putbombpc(game.history[0]+2,game.history[1]);
                    return;
                }
            case 3://left
                if(game.boardplayer[game.history[0]-1][game.history[1]-1]!=BOMB && game.boardplayer[game.history[0]][game.history[1]-1]!=SHIPBOMB && game.boardplayer[game.history[0]][game.history[1]-1]!=SHIPBOMB31 && game.boardplayer[game.history[0]][game.history[1]-1]!=SHIPBOMB32 && game.boardplayer[game.history[0]][game.history[1]-1]!=SHIPBOMB21 && game.boardplayer[game.history[0]][game.history[1]-1]!=SHIPBOMB22 && game.boardplayer[game.history[0]][game.history[1]-1]!=SHIPBOMB23 )
                {
                    putbombpc(game.history[0],game.history[1]-1);
                    return;
                }


            else if(game.boardplayer[game.history[0]-2][game.history[1]]!=BOMB && game.boardplayer[game.history[0]-2][game.history[1]]!=SHIPBOMB && game.boardplayer[game.history[0]-2][game.history[1]]!=SHIPBOMB31 && game.boardplayer[game.history[0]-2][game.history[1]]!=SHIPBOMB32 && game.boardplayer[game.history[0]-2][game.history[1]]!=SHIPBOMB21 && game.boardplayer[game.history[0]-2][game.history[1]]!=SHIPBOMB22 && game.boardplayer[game.history[0]-2][game.history[1]]!=SHIPBOMB23)
                {
                    putbombpc(game.history[0]-2,game.history[1]);
                    return;
                }

            mind();
            return;

        }

}
void randompcbomb()
{

    if(game.history[0]!=FINISHSHIP && game.history[0]!=BOMB)
    {
        mind();
    }
    else if(search())
    {
        mind();
    }
    else
    {
        int randomX,randomY;
        randomX=rand()%SIZE;
        randomY=rand()%SIZE;
        putbombpc(randomX,randomY);
    }
}
void findship3(int ship)
{
    int n=0,find=1;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {

            if(game.boardfile[i][j]==SHIP)
               {
                   n++;
                   if(n==3)
                   {
                       game.boardfile[i][j]=ship;
                       game.boardfile[i][j-2]=ship;
                       game.boardfile[i][j-1]=ship;
                       game.boardplayer[i][j]=ship;
                       game.boardplayer[i][j-2]=ship;
                       game.boardplayer[i][j-1]=ship;
                       return;
                   }
               }
            else if(game.boardfile[i][j]==0)
                n=0;
        }
        n=0;

    }
     for(j=0;j<SIZE;j++)
        {
            for(i=0;i<SIZE;i++)
            {
                if(game.boardfile[i][j]==SHIP)
                {
                   n++;
                   if(n==3)
                   {
                       game.boardfile[i][j]=ship;
                       game.boardfile[i-2][j]=ship;
                       game.boardfile[i-1][j]=ship;
                        game.boardplayer[i][j]=ship;
                       game.boardplayer[i-1][j]=ship;
                       game.boardplayer[i-2][j]=ship;
                       return;
                   }
               }
                else if(game.boardfile[i][j]==0)
                    n=0;
            }
        n=0;
        }

}
void findship2(int ship)
{
    int n=0,find=1;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(game.boardfile[i][j]==SHIP)
               {
                   n++;
                   if(n==2)
                   {
                       game.boardfile[i][j]=ship;
                       game.boardfile[i][j-1]=ship;
                       game.boardplayer[i][j]=ship;
                       game.boardplayer[i][j-1]=ship;
                       return;
                   }
               }
            else if(game.boardfile[i][j]==0)
                n=0;
        }
        n=0;
    }
     for(j=0;j<SIZE;j++)
        {
            for(i=0;i<SIZE;i++)
            {
                if(game.boardfile[i][j]==SHIP)
                {
                   n++;
                   if(n==2)
                   {
                       game.boardfile[i][j]=ship;
                       game.boardfile[i-1][j]=ship;
                       game.boardplayer[i][j]=ship;
                       game.boardplayer[i-1][j]=ship;
                       return;
                   }
               }
                else if(game.boardfile[i][j]==0)
                    n=0;
            }
        n=0;
        }

}
void findship()
{
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(game.boardfile[i][j]==SHIP)
               {
                   game.boardplayer[i][j]=SHIP;
               }
        }
    }
}
int yek(int x,int y)
{
    for(i1=x-1;i1<x+2;i1++)
    {
        for(j1=y-1;j1<y+2;j1++)
        {
            if(game.boardplayer[i1][j1]==SHIP || game.boardplayer[i1][j1]==SHIP31 || game.boardplayer[i1][j1]==SHIP32 || game.boardplayer[i1][j1]==SHIP21 || game.boardplayer[i1][j1]==SHIP22 || game.boardplayer[i1][j1]==SHIP23 )
                return 1;
        }
    }
    return 0;
}
void putnear()
{
     for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(game.boardplayer[i][j]==0)
            {
                if(yek(i,j))
                    game.boardplayer[i][j]=NEAR;

            }
        }
    }
}
void okmap()
{
   findship3(SHIP31);
   findship3(SHIP32);
   findship2(SHIP21);
   findship2(SHIP22);
   findship2(SHIP23);
   findship();
   putnear();

}
void openfile()
{
    char m;
    FILE *input;
    input=fopen("map.txt","r");
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            fscanf(input,"%c",&m);

            if(m=='*')
                {

                    game.boardfile[i][j]=SHIP;
                }
        }
        fscanf(input,"%c",&m);
    }
    okmap();
}
void number()
{
    kash.kastipc=5;
    kash.kasti2pc=3;
    kash.kasti3pc=2;
    kash.kastipl=5;
    kash.kasti2pl=3;
    kash.kasti3pl=2;
}
void printnumber()
{
    setbkcolor(COLOR(73,29,11));
    settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
    outtextxy(620,465,numstring[kash.kastipc]);
    outtextxy(620,510,numstring[kash.kasti2pc]);
    outtextxy(620,555,numstring[kash.kasti3pc]);
    outtextxy(275,465,numstring[kash.kastipl]);
    outtextxy(275,510,numstring[kash.kasti2pl]);
    outtextxy(275,555,numstring[kash.kasti3pl]);
}
int main()
{
    int halat;
    printf("please enter your name:\n");
    gets(game.playername);
    printf("to play with random map enter 0 \n");
    printf("if you want raed your map from file enter 1 \n");
    scanf("%d",&halat);
    srand(time(NULL));
    initwindow(WIDTH,HEIGHT,"Sea Battle:)"
               ,(getmaxwidth()-WIDTH)/2
               ,(getmaxheight()-HEIGHT)/2);
    game.history[0]=BOMB;
    Clearmap();

    number();
    game.finishnumberpl=0;                        //bporse random ya file
    game.finishnumberpc=0;
    game.locat[0]=0;
    game.locat[1]=0;
    random(game.boardpc);
    if(halat==1)
        openfile();
    else
        random(game.boardplayer);

   while(1)
  {

       //draw();
        readimagefile("bk.jpg",0,0,WIDTH,HEIGHT);
       drawboardpc();
       //writeimagefile("F:/proje payan term/proje/payanterm/bk.jpg",0,0,WIDTH,HEIGHT);
       drawboardplayer();
        setbkcolor(BLACK);
       settextstyle(COMPLEX_FONT,HORIZ_DIR,3);
       outtextxy(150,430,game.playername);
       if(!nobat)

       {
           setfillstyle(SOLID_FILL,BLUE);
           bar (425,25,435,50);
           if(kbhit())
            {
                char key=getch();
                switch(key)
                {

                    case 80:
                        locatdown();
                        break;
                    case 72:
                        locatup();
                        break;
                    case 75:
                        locatleft();
                        break;
                    case 77:
                        locatright();
                        break;
                    case 32:
                        putbombplayer();

                        break;
                    case 13:
                        putbombplayer();
                        break;
                }
            }


       }
       if(nobat)
       {
           setfillstyle(SOLID_FILL,BLUE);
           bar (475, 25,485,50);
            randompcbomb();
       }

       delay(50);
        //cleardevice();
       printnumber();
       if(game.finishnumberpc==10)
       {
           readimagefile("win.gif",176,136,690,331);
           puts(game.playername);
           printf(" win");
           getch();
           getch();
           return 0;
       }
       if(game.finishnumberpl==10)
       {
           readimagefile("lost.gif",176,136,690,331);
           printf("cumputer win");
           getch();
           getch();
           return 0;
       }


   }


    return 0;
}
