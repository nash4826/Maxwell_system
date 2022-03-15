#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void ListInit(List* plist) {
	plist->head = NULL;
	plist->personCount = 0;
}

void ListAdd(List* plist, userfunction generator) {
	Node* newNode = malloc(sizeof(Node));
	newNode->user = generator();

	newNode->next = plist->head;
	plist->head = newNode;
	plist->personCount += 1;

}

void ListDelete(List* plist, unsigned int key) {
	
	Node* rpos = plist->head;
	Node* before = rpos;

	while (rpos != NULL) {
		if (rpos->user->key == key && rpos->next == NULL) {
			free(rpos);
			plist->personCount -= 1;
			break;
		}
		else if(rpos->user->key == key){
			before->next = rpos->next;
			free(rpos);
			plist->personCount -= 1;
			break;
		}
		before = rpos;
		rpos = rpos->next;
	}
	

}

int count(List* plist)
{
	return plist->personCount;
}

User* UserSearch(List* plist, unsigned int key){
	Node* cur = plist->head;

	while (cur != NULL) {
		if (cur->user->key == key)
			return cur->user;
		
		cur = cur->next;
	}

	printf("%u ���� ������ ���꿡 �ԷµǾ� ���� �ʽ��ϴ�.\n", key);
	printf("������ ���� �ý����� �̿��Ͻ÷��� ȸ������ ���ּ���.\n");

	return NULL;
}



User* generatorUser() {
	User* user = (User*)malloc(sizeof(User));

	printf("�̸� : ");
	scanf("%s", user->name);

	printf("���� : ");
	scanf("%u", &(user->age));

	printf("�ּ� : ");
	scanf("%s", user->location);

	printf("�޴��� �޹�ȣ : ");
	scanf("%u", &(user->key));

	return user;
}

void printInformation(User* user)
{
	printf("�̸� : %s\n", user->name);
	printf("���� : %u\n", user->age);
	printf("�ּ� : %s\n", user->location);
	printf("������ : %u\n", user->charge);
}