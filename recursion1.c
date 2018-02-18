#include<stdio.h>
#include<stdlib.h>

int board[10][10];
int is_attacked(int x,int y);
int find_position(int N);
int size;
int main(int argc,char * argv[])
{
    int x;
    scanf("%d",&x);
    size = x;
    int i,j;
    if(find_position(x))
    {
        printf("YES\n");
        // print here the array
        for(i=0; i<x; i++)
        {
            for(j=0;j<x;j++)
            {
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO\n");
    }

}

int find_position(int N) {
    /* code */
    if (N==0)
    {
        return 0;
    }
    int i,j;
    int x=N;
    int y=N;
    for(i=0; i<x; i++)
    {
        for(j=0; j<y; j++)
        {
            board[i][j] = 1;
            if (is_attacked(i,j))
            {
                printf("debug1 %d %d\n",i,j);
                board[i][j] = 0;
                continue;
            }
            find_position(x-1);
        }
    }
}

int is_attacked(int x,int y)
{
    int i,j;
    for(i=x+1; i<size; i++)
        if (board[i][y] ==1)
        {
            printf("debug %d %d\n",i,y);
            return 1;
        }
    for(j=y+1; j<size; j++)
        if(board[x][j]==1)
        {
            printf("debug2 %d %d\n",x,j);
            return 1;
        }
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if ((i+j) == (x+y))
            {
                printf("i,j == x+y %d %d\n",i,j);
                return 1;
            }
            if(abs(i-j) == abs(x-y))
            {
                printf("i,j == x-y %d %d\n",i,j);
                return 1;
            }
        }
    }
    return 0;
}