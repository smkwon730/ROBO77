#include <stdio.h>
#include "cardGroup.h"
#include "cardType.h"

#define N_LIFE          3
#define N_PLAYER        2
#define N_CARDHOLD      5
#define MAX_CUMNUM      77

static int cumNum=0;
static int cardHold[N_PLAYER][N_CARDHOLD];
static int life[N_PLAYER];

int checkGameEnd(void)
{
    if (cumNum >= MAX_CUMNUM)
        return 0;
    return 1;
}


int main(int argc, const char * argv[]) {
    
    int i,j;
    int gameCnt=0;
    
    //initialization
    
    
    //outer loop : multiple games operation
    while (checkPlayerLife())
    {
        //one game initialization
        
        printf("\n\n\t [[[[[ %i'th game start!!! ]]]]]\n\n", gameCnt);
        
        
        //inner loop : one game operation
        while (checkGameEnd())
        {
            printf("\n\nPLAYER %i (life %i) turn :::: (accum count : %i)\n", turn, life[turn], cumNum);
            
            //print card
            
            //select card
            
            //check life
            
            //move to next turn
        }
        
        gameCnt++;
    }
    
    
    
    return 0;
}
