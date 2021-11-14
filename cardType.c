#include "cardType.h"
#include <stdio.h>
#include <string.h>


int card_TOTAL[N_TOTAL];

int arrayCopy(int *card, int CARDOFFSET, int N)
{
    int i;
    for (i=CARDOFFSET; i<CARDOFFSET+N; i++)
    {
        card_TOTAL[i] = card[i];
    }
}

int cardDeclare()
{
    int card_2[N_2TO9] = {2,2,2};
    int card_3[N_2TO9] = {3,3,3};
    int card_4[N_2TO9] = {4,4,4};
    int card_5[N_2TO9] = {5,5,5};
    int card_6[N_2TO9] = {6,6,6};
    int card_7[N_2TO9] = {7,7,7};
    int card_8[N_2TO9] = {8,8,8};
    int card_9[N_2TO9] = {9,9,9};

    int card_10[N_TEN] = {10,10,10,10,10,10,10,10};

    int card_11[N_11N] = {11};
    int card_22[N_11N] = {22};
    int card_33[N_11N] = {33};
    int card_44[N_11N] = {44};
    int card_55[N_11N] = {55};
    int card_66[N_11N] = {66};

    int card_76[N_76] = {76};

    int card_0[N_ZERO] = {0,0,0,0};

    int card_MINUS[N_MINUS] = {-10,-10,-10,-10};

    int card_x2[N_DOUBLE] = {x2,x2,x2,x2};
    
    arrayCopy(card_2, CARDOFFSET_2TO9+N_2TO9*0, N_2TO9);
    arrayCopy(card_3, CARDOFFSET_2TO9+N_2TO9*1, N_2TO9);
    arrayCopy(card_4, CARDOFFSET_2TO9+N_2TO9*2, N_2TO9);
    arrayCopy(card_5, CARDOFFSET_2TO9+N_2TO9*3, N_2TO9);
    arrayCopy(card_6, CARDOFFSET_2TO9+N_2TO9*4, N_2TO9);
    arrayCopy(card_7, CARDOFFSET_2TO9+N_2TO9*5, N_2TO9);
    arrayCopy(card_8, CARDOFFSET_2TO9+N_2TO9*6, N_2TO9);
    arrayCopy(card_9, CARDOFFSET_2TO9+N_2TO9*7, N_2TO9);
    arrayCopy(card_10, CARDOFFSET_TEN, N_TEN);
    arrayCopy(card_11, CARDOFFSET_11N+N_11N*0, N_11N);
    arrayCopy(card_22, CARDOFFSET_11N+N_11N*1, N_11N);
    arrayCopy(card_33, CARDOFFSET_11N+N_11N*2, N_11N);
    arrayCopy(card_44, CARDOFFSET_11N+N_11N*3, N_11N);
    arrayCopy(card_55, CARDOFFSET_11N+N_11N*4, N_11N);
    arrayCopy(card_66, CARDOFFSET_11N+N_11N*5, N_11N);
    arrayCopy(card_76, CARDOFFSET_76, N_76);
    arrayCopy(card_0, CARDOFFSET_ZERO, N_ZERO);
    arrayCopy(card_MINUS, CARDOFFSET_MINUS, N_MINUS);
    arrayCopy(card_x2, CARDOFFSET_DOUBLE, N_DOUBLE);


    
}

void cType_printCard(int cardType)
{
    
}


int cType_getCardNum(int cardType)
{
    
}
