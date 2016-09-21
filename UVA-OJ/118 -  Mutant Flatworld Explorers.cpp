#include <bits/stdc++.h>
using namespace std;
bool danger[50][50];
int main()
{
    int row, col;

    while(scanf("%d%d", &row, &col) != EOF)
    {
        int x,y;
        char direction,instruction[100];



        while(scanf("%d%d", &x,&y) != EOF)
        {
            getchar();
            scanf("%c", &direction);
            scanf("%s", instruction);

            int i;

            for(i=0; i<strlen(instruction); i++)
            {
                if(instruction[i] == 'F')
                {
                    if(direction == 'W')
                    {
                        if(x-1 < 0)
                        {
                            if(!danger[x][y])
                            {
                                printf("%d %d %c LOST\n", x,y,direction);
                                danger[x][y] = 1;
                                break;
                            }
                        }
                        else x--;
                    }
                    else if(direction == 'E')
                    {
                        if(x+1 > row)
                        {
                            if(!danger[x][y])
                            {
                                printf("%d %d %c LOST\n", x,y,direction);
                                danger[x][y] = 1;
                                break;
                            }
                        }

                        else x++;
                    }
                    else if(direction == 'N')
                    {
                        if(y+1 > col)
                        {
                            if(!danger[x][y])
                            {
                                printf("%d %d %c LOST\n", x,y,direction);
                                danger[x][y] = 1;
                                break;
                            }

                        }
                        else y++;
                    }
                    else if(direction == 'S')
                    {
                        if(y-1 < 0)
                        {
                            if(!danger[x][y])
                            {
                                printf("%d %d %c LOST\n", x,y,direction);
                                danger[x][y] = 1;
                                break;
                            }

                        }
                        else y--;
                    }
                }

                else if(instruction[i] == 'L')
                {
                    if(direction == 'N') direction = 'W';
                    else if(direction == 'S') direction = 'E';
                    else if(direction == 'E') direction = 'N';
                    else direction = 'S';
                }

                else if(instruction[i] == 'R')
                {
                    if(direction == 'N') direction = 'E';
                    else if(direction == 'S') direction = 'W';
                    else if(direction == 'E') direction = 'S';
                    else direction = 'N';
                }
            }

            if(i == strlen(instruction)) printf("%d %d %c\n", x,y,direction);

        }
    }

    return 0;
}
