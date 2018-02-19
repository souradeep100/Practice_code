#include<stdio.h>
#include<stdlib.h>

int board[10][10];
int is_attacked(int x,int y);
int find_position(int N);
int number_of_queens;
int main(int argc,char * argv[])
{
    int x;
    scanf("%d",&x);
    number_of_queens = x;
    int i,j;
    if(find_position(number_of_queens))
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
        return 1;
    }

    int i,j;
    for(i=(number_of_queens-N); i < number_of_queens; i++)
    {
        for(j=(number_of_queens-N); j < number_of_queens; j++)
        {
            board[i][j] = 1;
            if (is_attacked(i,j))
            {
                board[i][j] = 0;
                continue;
            }
            if(find_position(N-1))
                return 1;
        }
    }
    return 0;
}

int is_attacked(int x,int y)
{
    int i,j;
    for(i=0; i<x; i++)
        if (board[i][y] ==1)
        {
            //printf("debug %d %d\n",i,y);
            return 1;
        }
    for(j=0; j<y; j++)
        if(board[x][j]==1)
        {
            //printf("//debug2 %d %d\n",x,j);
            return 1;
        }
    if (x&&y)
    {
        for(i=0; i<number_of_queens;i++)
        {
           for (j=0; j<number_of_queens; j++)
            {
                if((((i+j)==(x+y)) && board[i][j]==1 && i!=x)
                  || (((i-j)==(x-y)) && board[i][j]==1 && i!=x))
                {
                    printf("debug board%d :%d %d\n",board[i][j],i,j);
                    printf("debug 1%d %d\n",x,y);
                    return 1;
                }
            } 
        } 
    }
    return 0;
}
