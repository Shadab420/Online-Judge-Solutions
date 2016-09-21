#include <bits/stdc++.h>
using namespace std;

struct Marker
{
    char ch;
    int x, y;
};

int row, col;
char grid[35][85], boundaryChar;
int dx[4] = {-1,0,0,1};
int dy[8] = {0,-1,1,0};
vector<Marker>mark;

void floodFill(char ch, int x, int y)
{
    grid[x][y] = ch;

    for(int i=0; i<4; i++)
    {
        int newX = x+dx[i];
        int newY = y+dy[i];

        if(newX >= 0 && newX < row && newY >= 0 && newY < strlen(grid[newX]))
        {

            if(grid[newX][newY] != boundaryChar && grid[newX][newY] != ch && grid[newX][newY] == ' ' )
            {
                bool boundaryFound = false;
                for(int j=0; j<newY; j++)
                {
                    if(grid[newX][j] == boundaryChar)
                    {
                        boundaryFound = true;
                        break;
                    }
                }

                if(boundaryFound)
                {
                    floodFill(ch, newX, newY);
                }

            }
        }
    }
}

int main()
{
//    freopen("input/in.txt","r",stdin);
//    freopen("input/out.txt","w",stdout);
    row = 0;
    int cs = 0;

    while(gets(grid[row]))
    {
        if(grid[row][0] != '_')
        {
            if(cs==1) { printf("\n"); cs=0; }
            col = strlen(grid[row]);

            for(int i=0; i<col; i++)
            {
                if(grid[row][i] != ' ')
                {
                    boundaryChar = grid[row][i];
                    break;
                }
            }

            for(int i=0; i<col; i++)
            {
                if(grid[row][i] != ' ' && grid[row][i] != boundaryChar)
                {
                    Marker temp;
                    temp.ch = grid[row][i];
                    temp.x = row;
                    temp.y = i;
                    mark.push_back(temp);
                }
            }
            row++;
        }

        else if(grid[row][0] == '_')
        {
            for(int i=0; i<mark.size(); i++)
            {
                floodFill(mark[i].ch, mark[i].x, mark[i].y);
            }

            for(int i=0; i<=row; i++)
            {
                printf("%s\n", grid[i]);
            }

            cs=1;

            row = 0;
            memset(grid,'\0', sizeof grid);
            mark.clear();
            getchar();
        }
    }

    return 0;
}

