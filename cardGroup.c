#include <stdio.h>
#include "cardGroup.h"
#include "cardType.h"
#include "stdlib.h"
#include "time.h"

#define CARD_NONE       -1

int card_flipped[N_TOTAL];      //플레이어에게 뽑힌 카드
int card_opened[N_TOTAL];       //플레이어가 낸 카드
int cnt_flipped;                //덱에 있는 카드 수 (뽑을 카드 수)
int cnt_opened;                 //플레이어가 낸 카드 수


static void cGroup_shuffleCard(int Ncard, int clearOption) {        //카드를 섞는 함수
    if (clearOption) {                                              //cGroup_initCard에서 실행
        for (int i = 0; i < Ncard - 1; i++) {                       //전체 카드를 섞음
            int j = i + rand() / (RAND_MAX / (Ncard - i) + 1);
            int t = card_flipped[j];
            card_flipped[j] = card_flipped[i];
            card_flipped[i] = t;
        }
    }
    else {                                          //cGroup_pullCard에서 실행
        for (int i = 0; i < cnt_opened; i++) {      //opened card group에 있는 카드를 랜덤으로 하나씩 골라 위치를 바꿔 섞음
            int j = i + rand() / (RAND_MAX / (Ncard - i) + 1);
            int t = card_opened[j];
            card_opened[j] = card_opened[i];
            card_opened[i] = t;
        }

        for (int i = 0; i < cnt_opened; i++) {      //오픈된 카드를 다시 뽑을 수 있도록 덱에 넣음
            card_flipped[i] = card_opened[i];
            cnt_flipped--;
        }
        cnt_opened = 0;
    }

}


void cGroup_initCard(void) {                //flipped/opened card group 초기화
    for (int i = 0; i < N_TOTAL; i++) {
        card_flipped[i] = i;
    }

    srand((unsigned int)time(NULL));
    cGroup_shuffleCard(N_TOTAL, 1);
}

int cGroup_pullCard(void) {                 //flipped card group에서 한 장 가져옴
    if (cnt_flipped == N_TOTAL) {           //카드를 모두 뽑았을 때 실행
        cGroup_shuffleCard(N_TOTAL, 0);
    }
    return card_flipped[cnt_flipped++];     //뽑은 카드 증가
}

void cGroup_pushCard(int cardType) {        //opened card group에 한 장을 놓음
    card_opened[cnt_opened++] = cardType;   //오픈한 카드 증가
}
