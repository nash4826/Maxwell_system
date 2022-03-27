#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "menu.h"
#include "json.h"

int main()
{	
	int select_num = menu();
	char name[20];
	if (select_num == 1) {
		printf("이름을 입력하세요 : ");
		scanf("%s", name);
		init_Information_json(name);
		printf("JSON 파일 작성 완료!\n");
	}
	else {
		system("cls");
		reset_status_json();
		printStatus();
		printf("reset 완료");
	}
	return 0;
}