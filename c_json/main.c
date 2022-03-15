#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "user.h"

/*
	1. 유저 등록(연결리스트로 구현) check!

	2. 유저 구조체 요소 중 charge 를 random 함수로 에너지 저장량 구현 

*/

int main() 
{
	unsigned int num;
	List list;
	ListInit(&list);
	ListAdd(&list, generatorUser);
	ListAdd(&list, generatorUser);
	ListAdd(&list, generatorUser);
	ListAdd(&list, generatorUser);

	ListDelete(&list, 56);

	User* temp = UserSearch(&list, 34);
	printInformation(temp);
	
	return 0;
}

