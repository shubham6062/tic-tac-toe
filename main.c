#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char player ='x';
const char computer ='o';

void resetboard();
void printboard();
int checkfreespace();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);

int main()
{
    char winner =' ';

    resetboard();
    while(winner ==' ' && checkfreespace() != 0)
    {
        printboard();

        playermove();
        winner = checkwinner();
        if(winner !=' ' || checkfreespace ==0)
        {
            break;
        }

        computermove();
        winner = checkwinner();
        if(winner !=' ' || checkfreespace ==0)
        {
            break;
        }
    }

    printboard();
    printwinner(winner);


}
void resetboard()
{
    // reset the board
   for( int i=0;i<3;i++)
   {
       for( int j=0;j<3;j++)
       {
           board[i][j];
       }
   }
}
void printboard()
{
    // board diagram
    printf(" %c | %c |%c",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c |%c",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c |%c",board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int checkfreespace()
{
    int freespaces= 9;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != ' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}
void playermove()
{
    int x;
    int y;

    do
  {
    printf("Enter row #(1-3):");
    scanf("%d",&x);
    x--;
    printf("Enter column #(1-3):");
    scanf("%d",&y);
    y--;

    if(board[x][y] !=' ')
    {
        printf("\n Invalid move!  ");
    }
    else
    {
        board[x][y] = player;
        break;
    }
  }while (board[x][y] !=' ');
}
void computermove()
{
  // create a seed based on current time
  srand(time(0));
  int x;
  int y;

  if(checkfreespace() >0)
  {
      do
      {
          x =rand() % 3;
          y =rand() % 3;
      }while (board[x][y] != ' ');

      board[x][y] =computer;
  }
  else
  {
      printwinner(' ');
  }
}
char checkwinner()
{
   //check row
   for(int i=0;i<3;i++)
   {
       if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
       {
           return board[1][0];
       }
   }
   // check column
   for(int j=0;j<3;j++)
   {
       if(board[0][j] == board[1][j] && board[1][j] == board[2][j])
       {
           return board[0][j];
       }
   }
   // check diagonals
   if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
       {
           return board[0][0];
       }
   if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
       {
           return board[0][2];
       }
    return ' ';

}
void printwinner(char winner)
{
    if(winner == player)
    {
        printf(" You win!");
    }
    else if(winner == computer)
    {
        printf(" You lose!");
    }
    else
    {
        printf(" Its a tie!");
    }
}
