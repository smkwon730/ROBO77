#include <stdio.h>
#include <string.h>
#include "cardGroup.h"
#include "cardType.h"
#include "stdlib.h"
#include "time.h"

int card_flipped[N_TOTAL];
int card_opened[N_TOTAL];
int cnt_flipped;
int cnt_opened;


static void cGroup_shuffleCard(int *Target, int amount)     //(섞을 카드집단 배열, 수)
{
    int i, n;
    int temp;
    srand(time(NULL));
    for (i = amount-1; i>=0; i--)
    {
        n =rand()%amount;
        temp = Target[i];
        Target[i] = Target[n];
        Target[n] = temp;
    }
}

int flippedCardGroup[];
int openedCardGroup[N_TOTAL];       // 오픈된 카드 배열을 모두 Empty로 초기화
memset(openedCardGroup, EMP, N_TOTAL*sizeof(int));


void cGroup_initCard(void)      //flipped/opened card group 초기화
{
    srand((unsigned int)time(NULL));
    cGroup_shuffleCard(card_ALL, N_TOTAL);
}

int cGroup_pullCard(void)       //flipped card group에서 한장 가져옴
{
    
}

int cGroup_holdCards(void)      //처음에 카드 나눠주는 함수

void cGroup_pushCard(int num, int *sum)      //opened card group에 한장을 놓음
{
    /*opened card group에 한 장을 놓는 함수

   내는 카드(cardType)와 합계의 포인터를 인자로 받음
   일반 카드는 0 반환
   x2는 MUL 반환
   */
    if (num >= 0)
        *sum += num;

    else
    {
        switch (num)
        {
            case -10:
                *sum += -10;
                break;

            case x2:
                return x2;
                break;

        }
    }
    return 0;
}
