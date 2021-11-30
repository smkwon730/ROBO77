#include <stdio.h>
#include "cardGroup.h"
#include "cardType.h"
#include <windows.h>

#define N_LIFE          3
#define N_PLAYER        2
#define N_CARDHOLD      5
#define MAX_CUMNUM      77

static int cumNum = 0;
static int cardHold[N_PLAYER][N_CARDHOLD];
static int life[N_PLAYER];

void textColor(int colorNum) {      //출력되는 텍스트의 색을 바꿈
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

int checkPlayerLife(void) {
    /*
    플레이어들의 남은 목숨을 확인하는 함수
    main의 첫번째 while문의 루프 여부 결정
    남은 목숨 수가 0개일 시 while문 탈출
    */
    for (int i = 0; i < N_PLAYER; i++) {
        if (life[i] == 0) return 0;
    }
    return 1;
}

int checkGameEnd(void) {
    /*
    누적합과 플레이어들의 남은 목숨을 확인하는 함수
    main의 첫번째 while문 속 while문의 루프 여부 결정
    누적합이 77 이상이거나 남은 목숨 수가 0개일 시 while문 탈출
    */
    if (cumNum >= MAX_CUMNUM)
        return 0;

    checkPlayerLife();
}

int sendCard(int player, int pick, int doubleCard) {
    /*
    카드를 내는 함수
    */
    int card = cardHold[player][pick];
    if (doubleCard) {
        if (cType_getCardNum(card) == CARDNUM_DOUBLE) {     //x2를 냈을 경우 -1 반환
            return -1;
        }
    }
    cardHold[player][pick] = cGroup_pullCard();     //새 카드를 뽑음
    cGroup_pushCard(card);                          //낸 카드를 opened card group에 놓음
    return cType_getCardNum(card);                  //카드를 표현하는 정수값의 숫자를 반환
}

void checkCum(int turn) {
    /*
    누적합 확인을 통한 목숨 차감 함수
    */
    if (cumNum <= 0) return;        //0을 11로 나누면 0이기 때문에 else if문에 의해 0에서 목숨이 차감되는 것을 방지
    if (cumNum >= MAX_CUMNUM) {             //누적합이 77 이상일 때 목숨 차감
        life[turn]--;
        textColor(12);
        printf("  !! PLAYER %d life lost !! (over 77)\n", turn);
    }
    else if (cumNum % 11 == 0) {    //누적합이 11의 배수일 때 목숨 차감
        life[turn]--;
        textColor(12);
        printf("  !! PLAYER %d life lost !! (multiple of 11)\n", turn);
    }
}



int main(int argc, const char* argv[]) {

    int i, j;
    int gameCnt = 0;        //현재 게임 회차
    int doubleCard = 0;     //x2 카드에 대한 실행을 제어하기 위한 변수
    int turn = 0;           //카드를 낼 차례. 0일 때 첫번째 플레이어, 1일 때 두번째 플레이어
    int card, prvcard, pick;

    //initialization
    for (int i = 0; i < N_PLAYER; i++) {        //플레이어에게 목숨 3개씩 부여
        life[i] = N_LIFE;
    }

    cGroup_initCard();      //카드그룹 초기화

    //outer loop : multiple games operation
    while (checkPlayerLife())
    {
        turn = 0;
        cumNum = 0;
        //one game initialization

        textColor(14);
        printf("\n\n\t [[[[[ %i'th game start!!! ]]]]]\n", gameCnt);

        for (int i = 0; i < N_PLAYER; i++) {        //플레이어 각각에게 카드를 5장씩 분배
            for (int j = 0; j < N_CARDHOLD; j++) {
                cardHold[i][j] = cGroup_pullCard();     //플레이어 i의 j번째 카드를 flipped card group에서 가져옴
            }
        }

        //inner loop : one game operation
        while (checkGameEnd()) {
            textColor(11);
            printf("\n\nPLAYER %i (life %i) turn :::: (accum count : %i)\n", turn, life[turn], cumNum);

            //print card
            textColor(15);
            printf("Current cards--------------------------------------------------------\n");
            for (int i = 0; i < N_CARDHOLD; i++) {
                printf("%d. ", i + 1);                      //플레이어가 카드를 입력할 수 있도록 카드에 번호 부여
                cType_printCard(cardHold[turn][i]);     //가지고 있는 카드(낼 수 있는 카드) 출력
            }
            printf("\n---------------------------------------------------------------------\n\n");

            do {
                /*
                이전 플레이어가 x2를 내지 않았다면 doubleCard=0이므로 공백 출력
                x2를 냈다면 doubleCard=1이므로 1출력
                */
                textColor(15);
                printf(">>>> Select a card %s(1-5): ", doubleCard ? "0 " : "");
                scanf_s("%d", &card);           //낼 카드를 입력받음
                textColor(12);
                if (card < 1 || card > 5) {     //1~5 이외의 숫자를 입력했을 시 경고문 출력
                    printf("input is wrong!! choose from 1 to 5\n");
                    continue;
                }
                //select a card
                pick = sendCard(turn, card - 1, doubleCard);
                /*
                낸 카드가 x2일 경우 pick=-1
                낸 카드가 x2가 아닐 경우 pick는 카드를 표현하는 정수값
                */
                if (pick == -1) {       //이전 플레이어가 x2를 냈는데 card0으로 x2를 냈다면 경고문 출력, 아래 건너뛰고 다시 실행
                    printf("input is wrong!! the first card of the double case should be number!!\n");
                    continue;
                }
                textColor(15);
                prvcard = card;     //낸 카드를 prvcard에 저장 >> card1에 card0과 같은 카드를 내는 것을 방지
                if (pick == CARDNUM_DOUBLE) {       //이전 플레이어가 숫자를 낸 경우, x2를 내면 doubleCard=1
                    printf(">>>> Putting the card x2\n");
                    doubleCard = 1;
                }
                else {
                    printf(">>>> Putting the card %d\n", pick);     //낸 카드 출력
                }
                break;
            } while (1);

            if (pick != CARDNUM_DOUBLE) {       //낸 카드가 x2가 아닌 경우 낸 숫자를 cumNum에 더함
                cumNum += pick;
                if (cumNum < 0) cumNum = 0;     //합 결과가 음수인 경우에는 누적 숫자를 0으로 설정
                if (doubleCard == 0) {          //card1을 내기 전에 게임이 종료되면 안되므로
                    checkCum(turn);
                    if (cumNum >= MAX_CUMNUM) break;    //누적합이 77이상일 경우 while문 바로 탈출
                }
            }

            if (doubleCard && pick != CARDNUM_DOUBLE) {     //이전 플레이어가 x2를 내서 두번째 카드를 내야하는 경우에만 실행됨
                do {
                    textColor(15);
                    printf(">>>> Select a card 1(1-5): ");
                    scanf_s("%d", &card);
                    textColor(12);
                    if (card < 1 || card > 5) {     //1~5 이외의 숫자를 입력했을 시 경고문 출력
                        printf("input is wrong!! choose from 1 to 5!!\n");
                        continue;
                    }
                    if (card == prvcard) {      //card0과 동일한 카드를 내면 경고문 출력
                        printf("input is wrong!! select different cards!!\n");
                        continue;
                    }

                    //select a card
                    pick = sendCard(turn, card - 1, 0);     //pick에 -1이 들어가지 않도록 매개변수 doubleCard에 0을 전달
                    break;
                } while (1);
                doubleCard = 0;

                textColor(15);
                if (pick == CARDNUM_DOUBLE) {
                    printf(">>>> Putting the card x2\n");
                    doubleCard = 1;
                }
                else {
                    printf(">>>> Putting the card %d\n", pick);
                }
                cumNum += pick;                 //낸 카드의 정수값을 누적합에 더함
                if (cumNum < 0) cumNum = 0;     //누적합이 0 미만일 
                checkCum(turn);
            }

            //move to next turn
            turn++;
            if (turn == N_PLAYER) {         //두번째 플레이어의 턴이 끝나면 다시 첫번째 플레이어의 턴이 됨
                turn = 0;
            }
        }

        textColor(14);
        /*
        목숨을 모두 소진한 플레이어가 있을 시 승자 출력, 게임 완전 종료
        */
        if (life[0] == 0) {
            printf("\n\n\t!!! THE WINNER IS PLAYER 1 !!!\n\n");
        }
        else if (life[1] == 0) {
            printf("\n\n\t!!! THE WINNER IS PLAYER 0 !!!\n\n");
        }

        gameCnt++;          //회차 수 증가
        continue;           //위의 if 또는 else if에 걸리지 않았다면 다음 회차로 게임 계속 진행
    }
    textColor(7);
    return 0;
}
