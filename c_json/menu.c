#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void init() {
	system("mode con cols=60 lines=20 | title ���� �޴� ");
}

int menu()
{
	init();
	int menu_num;
	printf("--------------------------�޴�----------------------------\n\n");
	printf("                  1. ù ��ġ(json ��ȯ)           \n\n");
	printf("                  2. ���� ���� Ȯ��               \n\n");
	printf("----------------------------------------------------------\n\n");
	printf("Note : ù ��ġ�� �����߾��ٸ� 2������ �������ּ���.\n\n");

	printf("������ �޴��� ��ȣ�� �Է��ϼ��� : ");
	scanf("%d", &menu_num);
	printf("\n");

	while (menu_num != 1 && menu_num != 2)
	{
		printf("�ش� ��ȣ�� �޴��� �����ϴ�. ");
		printf("�ٽ� �Է��ϼ��� : ");
		scanf("%d", &menu_num);
		printf("\n");
	}

	
	return menu_num;
}

