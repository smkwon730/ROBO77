#include <stdio.h>
#include "cardGroup.h"
#include "cardType.h"
#include "stdlib.h"
#include "time.h"

#define CARD_NONE       -1

int card_flipped[N_TOTAL];
int card_opened[N_TOTAL];
int cnt_flipped;
int cnt_opened;


static void cGroup_shuffleCard(int Ncard, int clearOption)
{
    
}


void cGroup_initCard(void)
{
    srand((unsigned int)time(NULL));
    cGroup_shuffleCard(N_TOTAL, 1);
}

int cGroup_pullCard(void)
{
    
}

void cGroup_pushCard(int cardType)
{
   
}
