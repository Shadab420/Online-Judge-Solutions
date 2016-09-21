#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)

int t,r,c,rx,ry;
char grid[61][61], cmd, direction;

void updateDirection()
{
    if(cmd == 'R')
    {
        if(direction == 'N') direction = 'E';
        else if(direction == 'S') direction = 'W';
        else if(direction == 'E') direction = 'S';
        else if(direction == 'W') direction = 'N';
    }
    else
    {
        if(direction == 'N') direction = 'W';
        else if(direction == 'S') direction = 'E';
        else if(direction == 'E') direction = 'N';
        else if(direction == 'W') direction = 'S';
    }
}

void updatePosition()
{
    if(direction == 'N')
    {
        if(rx-1 >=0 && grid[rx-1][ry] != '*') rx--;
    }
    else if(direction == 'S')
    {
        if(rx+1 < r && grid[rx+1][ry] != '*') rx++;
    }
    else if(direction == 'E')
    {
        if(ry+1 < c && grid[rx][ry+1] != '*') ry++;
    }
    else if(direction == 'W')
    {
        if(ry-1 >= 0  && grid[rx][ry-1] != '*') ry--;
    }
}

int main()
{
    freopen("input/in.txt","r",stdin);
    freopen("input/out.txt","w",stdout);

    read(t);

    for(int cs=1; cs<=t; cs++)
    {
        if(cs>1) printf("\n");
        read(r); read(c);
        cin.ignore();

        memset(grid,'\0',sizeof(grid));

        for(int i=0; i<r; i++) gets(grid[i]);

        read(rx); read(ry); rx--; ry--; direction = 'N';
        bool quit = false, invalid = false;

        while(scanf("%c", &cmd))
        {
            if(cmd == ' ' || cmd == '\n');
            else if(cmd == 'Q')
            {
                quit = true; break;
            }
            else if(cmd != 'F') updateDirection();
            else if(cmd == 'F')
            {
                if(rx>=0 && rx<r && ry>=0 && ry<c) updatePosition();
                else invalid = true;
            }
        }

        if(quit)
        {
            printf("%d %d %c\n", rx+1,ry+1,direction);
        }
    }

    return 0;
}
