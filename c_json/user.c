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

	printf("%u 님의 정보가 전산에 입력되어 있지 않습니다.\n", key);
	printf("에너지 관리 시스템을 이용하시려면 회원가입 해주세요.\n");

	return NULL;
}



User* generatorUser() {
	User* user = (User*)malloc(sizeof(User));

	printf("이름 : ");
	scanf("%s", user->name);

	printf("나이 : ");
	scanf("%u", &(user->age));

	printf("주소 : ");
	scanf("%s", user->location);

	printf("휴대폰 뒷번호 : ");
	scanf("%u", &(user->key));

	return user;
}

void printInformation(User* user)
{
	printf("이름 : %s\n", user->name);
	printf("나이 : %u\n", user->age);
	printf("주소 : %s\n", user->location);
	printf("충전량 : %u\n", user->charge);
}