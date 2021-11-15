#ifndef cardType_h
#define cardType_h

#define N_2TO9          3
#define N_TEN           8
#define N_11N           1
#define N_76            1
#define N_ZERO          4
#define N_MINUS         4
#define N_DOUBLE        4

#define x2 -20

#define CARDOFFSET_2TO9     0
#define CARDOFFSET_TEN      (N_2TO9*8)                          // 3*8 =24
#define CARDOFFSET_11N      (CARDOFFSET_TEN+N_TEN)              // =32
#define CARDOFFSET_76       (CARDOFFSET_11N+N_11N*6)            // =38
#define CARDOFFSET_ZERO     (CARDOFFSET_76+N_76)                // =39
#define CARDOFFSET_MINUS    (CARDOFFSET_ZERO+N_ZERO)            // =43
#define CARDOFFSET_DOUBLE   (CARDOFFSET_MINUS+N_MINUS)          // =47

#define N_TOTAL             (CARDOFFSET_DOUBLE+N_DOUBLE)        // =51


#define CARDNUM_DOUBLE      100
#define CARDNUM_MINUS       -10

int cType_getCardNum(int cardType);
void cType_printCard(int cardType);


/* -------------- 카드만들기 시작 --------------*/
int card_ALL[N_TOTAL];

int fillArray(int array, int amount, int num) //(배열 종류, 배열수)
{
    for (int *i=0; i<amount; i++)
    {
        array[i] = num;
    }
}

int arrayCopy(int *card, int CARDOFFSET, int N) // 전체 카드 덱 생성을 위한 도구 함수
{
    int i;
    for (i=CARDOFFSET; i<CARDOFFSET+N; i++)
    {
        card_ALL[i] = card[i];
    }
}

    //헤더를 조정해도 코드 수정이 용이하도록 구성
    int card_2[N_2TO9];
    fillArray(card_2, N_2TO9, 2);
    int card_3[N_2TO9];
    fillArray(card_3, N_2TO9, 3);
    int card_4[N_2TO9];
    fillArray(card_4, N_2TO9, 4);
    int card_5[N_2TO9];
    fillArray(card_5, N_2TO9, 5);
    int card_6[N_2TO9];
    fillArray(card_6, N_2TO9, 6);
    int card_7[N_2TO9];
    fillArray(card_7, N_2TO9, 7);
    int card_8[N_2TO9] = {8,8,8};
    fillArray(card_8, N_2TO9, 8);
    int card_9[N_2TO9] = {9,9,9};
    fillArray(card_9, N_2TO9, 9);

    int card_10[N_TEN];
    fillArray(card_10, N_TEN, 10);

    int card_11[N_11N];
    fillArray(card_11, N_11N, 11);
    int card_22[N_11N];
    fillArray(card_22, N_11N, 22);
    int card_33[N_11N];
    fillArray(card_33, N_11N, 33);
    int card_44[N_11N];
    fillArray(card_44, N_11N, 44);
    int card_55[N_11N];
    fillArray(card_55, N_11N, 55);
    int card_66[N_11N];
    fillArray(card_66, N_11N, 66);

    int card_76[N_76];
    fillArray(card_76, N_76, 76);

    int card_0[N_ZERO];
    fillArray(card_0, N_ZERO, 0);

    int card_MINUS[N_MINUS];
    fillArray(card_MINUS, N_MINUS, -10);

    int card_x2[N_DOUBLE] = {x2,x2,x2,x2};
    fillArray(card_x2, N_DOUBLE, x2);
    
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
/*-------------- 카드만들기 완료 --------------*/


#endif /* cardType_h */
