#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void init() {
	system("mode con cols=60 lines=20 | title 전력 메뉴 ");
}

int menu()
{
	init();
	int menu_num;
	printf("--------------------------메뉴----------------------------\n\n");
	printf("                  1. 첫 설치(json 변환)           \n\n");
	printf("                  2. 전력 상태 확인               \n\n");
	printf("----------------------------------------------------------\n\n");
	printf("Note : 첫 설치를 진행했었다면 2번으로 선택해주세요.\n\n");

	printf("선택할 메뉴의 번호를 입력하세요 : ");
	scanf("%d", &menu_num);
	printf("\n");

	while (menu_num != 1 && menu_num != 2)
	{
		printf("해당 번호는 메뉴에 없습니다. ");
		printf("다시 입력하세요 : ");
		scanf("%d", &menu_num);
		printf("\n");
	}

	
	return menu_num;
}

