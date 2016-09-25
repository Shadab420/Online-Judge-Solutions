#include <bits/stdc++.h>
using namespace std;

#define read(num1, num2) scanf("%d %d", &num1, &num2)

char grid[21][21];
int r,c,entx,enty;

void goUp(int x, int y);
void goDown(int x, int y);
void goLeft(int x, int y);
void goRight(int x, int y);


int main()
{
    freopen("input/in.txt", "r", stdin);
    freopen("input/out.txt", "w", stdout);

    int houseId=0;

    while(read(c,r)!=EOF)
    {
        if(c==0 && r==0) break;
        houseId++;

        for(int i=0; i<r; i++)
        {
            scanf("%s", grid[i]);

            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == '*')
                {
                    entx = i; enty= j;
                }
            }
        }

        if(entx == 0)
        {
            goDown(entx,enty);
        }
        else if(enty == 0)
        {
            goRight(entx,enty);
        }
        else if(entx == r-1)
        {
            goUp(entx,enty);
        }
        else if(enty == c-1)
        {
            goLeft(entx,enty);
        }

        cout << "HOUSE " << houseId << endl;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++) cout << grid[i][j];
            cout << endl;
        }
    }

    return 0;
}

void goUp(int x, int y)
{
    if(x<0 || x>=r || y<0 || y>=c) return;
    if(grid[x][y] == '*' || grid[x][y] == '.') goUp(x-1,y);
    else if(grid[x][y] == '/') goRight(x,y+1);
    else if(grid[x][y] == '\\') goLeft(x,y-1);
    else if(grid[x][y] == 'x')
    {
        if((x == entx && y == enty) || ((x==0 || x==r-1) && (y==0 || y==c-1))) return;
        else grid[x][y] = '&';
    }
    return;
}

void goDown(int x, int y)
{
    if(x<0 || x>=r || y<0 || y>=c) return;
    if(grid[x][y] == '*' || grid[x][y] == '.') goDown(x+1,y);
    else if(grid[x][y] == '/') goLeft(x,y-1);
    else if(grid[x][y] == '\\') goRight(x,y+1);
    else if(grid[x][y] == 'x')
    {
        if((x == entx && y == enty) || ((x==0 || x==r-1) && (y==0 || y==c-1))) return;
        else grid[x][y] = '&';
    }
    return;
}

void goLeft(int x, int y)
{
    if(x<0 || x>=r || y<0 || y>=c) return;
    if(grid[x][y] == '*' || grid[x][y] == '.') goLeft(x,y-1);
    else if(grid[x][y] == '/') goDown(x+1,y);
    else if(grid[x][y] == '\\') goUp(x-1,y);
    else if(grid[x][y] == 'x')
    {
        if((x == entx && y == enty) || ((x==0 || x==r-1) && (y==0 || y==c-1))) return;
        else grid[x][y] = '&';
    }
    return;
}

void goRight(int x, int y)
{
    if(x<0 || x>=r || y<0 || y>=c) return;
    if(grid[x][y] == '*' || grid[x][y] == '.') goRight(x,y+1);
    else if(grid[x][y] == '/') goUp(x-1,y);
    else if(grid[x][y] == '\\') goDown(x+1,y);
    else if(grid[x][y] == 'x')
    {
        if((x == entx && y == enty) || ((x==0 || x==r-1) && (y==0 || y==c-1))) return;
        else grid[x][y] = '&';
    }
    return;
}
