#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "user.h"

/*
	1. ���� ���(���Ḯ��Ʈ�� ����) check!

	2. ���� ����ü ��� �� charge �� random �Լ��� ������ ���差 ���� 

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

