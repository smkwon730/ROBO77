#include "cardType.h"
#include <stdio.h>



void cType_printCard(int cardType) {
	/*
	화면에 카드 내용을 출력하는 함수
	*/
	int card = cType_getCardNum(cardType);
	if (card == CARDNUM_DOUBLE) {
		printf("%s\t", "x2");
	}
	else {
		printf("%d\t", card);
	}
}

int cType_getCardNum(int cardType) {
	/*
	카드를 표현하는 정수값의 숫자를 반환하는 함수
	*/
	if (cardType >= CARDOFFSET_2TO9 && cardType < CARDOFFSET_TEN) {
		return cardType / 3 + 2;
	}
	else if (cardType >= CARDOFFSET_TEN && cardType < CARDOFFSET_11N) {
		return 10;
	}
	else if (cardType >= CARDOFFSET_11N && cardType < CARDOFFSET_76) {
		return 11 * (CARDOFFSET_76 - cardType);
	}
	else if (cardType >= CARDOFFSET_76 && cardType < CARDOFFSET_ZERO) {
		return 76;
	}
	else if (cardType >= CARDOFFSET_ZERO && cardType < CARDOFFSET_MINUS) {
		return 0;
	}
	else if (cardType >= CARDOFFSET_MINUS && cardType < CARDOFFSET_DOUBLE) {
		return CARDNUM_MINUS;
	}
	else {
		return CARDNUM_DOUBLE;
	}
}
