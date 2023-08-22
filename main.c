#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL)) ;
    int m,n,hamle=0,yemek,i,j,sayac=1,kontrol=0,snakesize=1,x,y,k,l,snakecontrol=0;         //oyun icin gerekli hazirliklar
    char hamleyonu,sayi=48;
    printf("Please enter your number of lines : ");
    scanf("%d",&m);
    printf("Please enter your number of columns : ");
    scanf("%d",&n);
    printf("please enter your number of food : ");
    scanf("%d",&yemek);
    while(!(yemek>0 && yemek<m*n-1))                                                                // yanlis yemek alma durumunda tekrardan veri isteme
    {
        printf("please enter a value greater than 0 and less than %d : ",m*n-1);
        scanf("%d",&yemek);
    }
    char gamearea[m+2][n+2];
    int snake[yemek][2], newsnake[yemek][2];
    for(i=0;i<yemek;i++)                                                                            //yilan baslangic koordinatlari
    {
        for(j=0;j<2;j++)
        {
            snake[i][j] = 0;
        }
    }
    for(i=0;i<=m+1;i++)                                                                           //oyun alani olusturma
    {
        for(j=0;j<=n+1;j++)
        {
            if(i==0 || i==m+1 || j==0 ||j==n+1)
            {
                gamearea[i][j] = '*';
            }
            else
            {
                gamearea[i][j] = NULL;
            }
        }
    }
    while(sayac<=yemek+1)                                                                     //rastgele yemek ve yilan baslangic noktasi ayarlama
    {
        i = rand() % m+2 ;
        j = rand() % n+2 ;
        if(gamearea[i][j] == NULL)
        {
            if(sayac==yemek+1)
            {
                snake[0][0] = i;
                snake[0][1] = j;
                gamearea[i][j]='1';
            }
            else
            {
               gamearea[i][j] = '0';
            }
             sayac++;
        }
    }
    do                                                                                           //oyun alani ekrana gelir ve oyun baslar
    {
        for(i=0;i<=m+1;i++)
        {
            for(j=0;j<=n+1;j++)
            {
                printf("%c ",gamearea[i][j]);
            }
            printf("\n");
        }
        printf("Hamle Sayisi : %d\n",hamle);
        printf("Hamlenizi seciniz : ");
        kontrol=0;
        sayi = 48;
        while(kontrol == 0)                                                                      //kontrol dogru tusa basıldımı ona bakıyor
        {
            if(hamleyonu == 'u' || hamleyonu == 'U')
            {
                if(gamearea[((snake[0][0])-1)][(snake[0][1])] == '0')                                           //yemek yerse
                {
                    snakesize++;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0] = snake[i][0]-1;
                            newsnake[i][1] = snake[i][1];
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1] = snake[i-1][1];
                        }
                    }
                     for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1] = newsnake[i][1];
                    }
                }
                else                                                                                             //yemek yemezse
                {
                     if(gamearea[((snake[0][0])-1)][(snake[0][1])] != NULL && gamearea[((snake[0][0])-1)][(snake[0][1])] != '0' )  //kendine carpiyormu
                    {
                        snakecontrol=1;
                    }
                    k=snake[snakesize-1][0];
                    l=snake[snakesize-1][1];
                    gamearea[k][l]=NULL;
                    for(i=0;i<snakesize;i++)                                                //hareket mekanizması
                    {
                        if(i==0)
                        {
                            newsnake[i][0]=snake[i][0]-1;
                            newsnake[i][1]=snake[i][1];
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1]=snake[i-1][1];
                        }
                    }
                    for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1]= newsnake[i][1];
                    }
                }
                kontrol=1;                                                                //doğru hamle yapıldı
                hamle++;                                                                  //hamle++
            }
            else if(hamleyonu == 'l'|| hamleyonu == 'L')
            {
                if(gamearea[(snake[0][0])][(snake[0][1]-1)] == '0')
                {
                    snakesize++;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0] = snake[i][0];
                            newsnake[i][1] = snake[i][1]-1;
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1] = snake[i-1][1];
                        }
                    }
                     for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1] = newsnake[i][1];
                    }
                }
                else
                {
                     if(gamearea[(snake[0][0])][(snake[0][1]-1)] != NULL && gamearea[(snake[0][0])][(snake[0][1]-1)] !='0')
                    {
                        snakecontrol = 1;
                    }
                    k=snake[snakesize-1][0];
                    l=snake[snakesize-1][1];
                    gamearea[k][l]=NULL;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0] = snake[i][0];
                            newsnake[i][1]= snake[i][1]-1;
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1] = snake[i-1][1];
                        }
                    }
                    for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1] = newsnake[i][1];
                    }
                }
                kontrol=1;
                hamle++;
            }

             else if(hamleyonu == 'd'|| hamleyonu == 'D')
            {
                if(gamearea[((snake[0][0])+1)][(snake[0][1])] == '0')
                {
                    snakesize++;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0] = snake[i][0]+1;
                            newsnake[i][1] = snake[i][1];
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1] = snake[i-1][1];
                        }
                    }
                     for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1] = newsnake[i][1];
                    }
                }
                else
                {
                    if(gamearea[((snake[0][0])+1)][(snake[0][1])] != NULL && gamearea[((snake[0][0])+1)][(snake[0][1])] != '0')
                    {
                        snakecontrol=1;
                    }
                    k=snake[snakesize-1][0];
                    l=snake[snakesize-1][1];
                    gamearea[k][l]=NULL;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0]=snake[i][0]+1;
                            newsnake[i][1]=snake[i][1];
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1]=snake[i-1][1];
                        }
                    }
                    for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1]= newsnake[i][1];
                    }
                }
                kontrol=1;
                hamle++;
            }
             else if(hamleyonu == 'r'|| hamleyonu == 'R')
            {
                if(gamearea[(snake[0][0])][(snake[0][1])+1] == '0')
                {
                    snakesize++;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0] = snake[i][0];
                            newsnake[i][1] = snake[i][1]+1;
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1] = snake[i-1][1];
                        }
                    }
                     for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1] = newsnake[i][1];
                    }
                }
                else
                {
                    if(gamearea[(snake[0][0])][(snake[0][1]+1)] != NULL && gamearea[(snake[0][0])][(snake[0][1]+1)] != '0')
                    {
                        snakecontrol=1;
                    }
                    k=snake[snakesize-1][0];
                    l=snake[snakesize-1][1];
                    gamearea[k][l]=NULL;
                    for(i=0;i<snakesize;i++)
                    {
                        if(i==0)
                        {
                            newsnake[i][0] = snake[i][0];
                            newsnake[i][1]= snake[i][1]+1;
                        }
                        else
                        {
                            newsnake[i][0] = snake[i-1][0];
                            newsnake[i][1] = snake[i-1][1];
                        }
                    }
                    for(i=0;i<snakesize;i++)
                    {
                        snake[i][0] = newsnake[i][0];
                        snake[i][1] = newsnake[i][1];
                    }
                }
                kontrol=1;
                hamle++;
            }
            else                                                          //yanlis hamle yapildiginda calisir
            {
                printf("Lutfen gecerli bir hamle seciniz : ");
                scanf(" %c",&hamleyonu);
                kontrol=0;
            }
            if(kontrol==1)
            {
                    for(i=0;i<snakesize;i++)
                    {
                    sayi = sayi + 1;
                    x = snake[i][0];
                    y = snake[i][1];
                    gamearea[x][y] = sayi;
                    }
            }
        }
    }while(snakesize!=yemek+1 && snakecontrol==0);                           //yemekler bittimi ve yilan bir yere carptimi kontrolu
    for(i=0;i<=m+1;i++)                                                      //son oyun alani yazdirilir
        {
            for(j=0;j<=n+1;j++)
            {
                printf("%c ",gamearea[i][j]);
            }
            printf("\n");
        }
        if(snakesize==yemek+1)                                                //yemekler bitti ise
        {
        printf("CONGRATULATIONS YOU WIN\n");
        printf("SNAKE SIZE : %d \n",snakesize);
        printf("NUMBER OF MOVES : %d\n",hamle);
        }
        else                                                                  //bir yere carpildi ise
        {
            printf("GAME OVER\n");
            printf("SNAKE SIZE : %d \n",snakesize);
            printf("number of remaining foods : %d\n",(yemek-snakesize)+1);
            printf("NUMBER OF MOVES : %d\n",hamle);
        }
    return 0;
}
