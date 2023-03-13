#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 6
#define TELENUM_MAX 12
#define ADDRESS_MAX 30

#define DEFAULT_SZ 3
typedef struct PeoInfo
{
	char Name[NAME_MAX];
	char Sex[SEX_MAX];
	int Age;
	char TeleNum[TELENUM_MAX];
	char Address[ADDRESS_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

void InitContact(Contact* pc);

void AddContact(Contact* pc);

int FindByName(const Contact* pc, char Name[]);

void DelContact(Contact* pc);

void PrintContact(const Contact* pc);

void SearchByName(const Contact* pc);

void ModifyContact(Contact* pc);

void SortContact(Contact* pc);

void Menu();

int cmp_peo_by_name1(const void* p1, const void* p2);

int cmp_peo_by_name2(const void* p1, const void* p2);

void DestoryContact(Contact* pc);

void CheckContact(Contact* pc);
