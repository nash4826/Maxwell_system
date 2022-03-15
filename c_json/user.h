#pragma once
#ifndef __USER_H__
#define __USER_H__

#define TRUE	1
#define FALSE	0


typedef struct _user {
	char name[30];
	char location[100];
	unsigned int age;
	unsigned int key;

	unsigned char charge;
}User;

typedef struct _node {
	User* user;
	struct _node* next;
}Node;

typedef struct _linkedList {
	Node* head;
	int personCount;
}List;

typedef User* (*userfunction)();

void ListInit(List* plist);
void ListAdd(List* plist, userfunction generator);
void ListDelete(List* plist, unsigned int key);
int count(List* plist);

User* UserSearch(List* plist, unsigned int key);
User* generatorUser();

void printInformation(User* user);

#endif // !__USER_H__
