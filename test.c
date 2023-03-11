#include "contact.h"
int cmp_peo_by_name1(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->Name, ((PeoInfo*)p2)->Name);
}

int cmp_peo_by_name2(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p2)->Name, ((PeoInfo*)p1 )->Name);
}

void Menu()
{
	printf("__________________INFORMATION_____________________\n");
	printf("|**********  1.Name      2.Age     **************|\n");
	printf("|**********  3.Sex       4.TeleNum **************|\n");
	printf("|**********  5.Address   0.Exit    **************|\n");
}

enum Option1
{
    EXIT,
	NAME,
	AGE,
	SEX,
	TELENUM,
	ADDRESS
};

enum Option2
{
	T,
	ASC,
    DEASC
};

void InitContact(Contact* pc)
{
	assert(pc);

	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加新信息\n");
	}
	printf("请输入名字：>");
	scanf("%s", pc->data[pc->sz].Name);
	printf("请输入年龄：>");
	scanf("%d", &pc->data[pc->sz].Age);
	printf("请输入性别：>");
	scanf("%s", pc->data[pc->sz].Sex);
	printf("请输入电话号码：>");
	scanf("%s", pc->data[pc->sz].TeleNum);
	printf("请输入地址：>");
	scanf("%s", pc->data[pc->sz].Address);
	pc->sz++;
	printf("添加成功\n");
}

void PrintContact(const Contact* pc)
{
	assert(pc);

	int i = 0;
	printf("%-20s %-5s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话号码", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].Name, pc->data[i].Age, pc->data[i].Sex, pc->data[i].TeleNum, pc->data[i].Address);
	}
}

int FindByName(const Contact* pc, char Name[])
{
	assert(pc);

	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(Name, pc->data[i].Name))
		{
			return i;
		}
	}
	return -1;
}

void SearchByName(const Contact* pc)
{
	assert(pc);

	int i = 0;
	char Name[20] = { 0 };
	printf("请输入需要查找的名字\n");
	scanf("%s", &Name);
	for (i = 0; i < pc->sz; i++)
	{
		if (0 == strcmp(Name, pc->data[i].Name))
		{
			printf("%-20s %-5s %-5s %-12s %-30s\n", "姓名", "年龄", "性别", "电话号码", "地址");
			printf("%-20s %-5d %-5s %-12s %-30s\n", pc->data[i].Name, pc->data[i].Age, pc->data[i].Sex, pc->data[i].TeleNum, pc->data[i].Address);
			return;
		}
	}
	printf("找不到目标名字\n");
}

void DelContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("通讯录已空，无法删除、\n");
		return;
	}
	char Name[NAME_MAX] = { 0 };
	printf("请输入要删除人的名字:>");
	scanf("%s", Name);
	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("要调整的人不存在，请重新输入\n");
		return;
	}
	int j = 0;
	for (j = pos; j < pc->sz-1; j++)
	{
		pc->data[j] = pc->data[j + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void ModifyContact(Contact* pc)
{
	assert(pc);

	if (pc->sz == 0)
	{
		printf("通讯录已空，无法查找\n");
		return;
	}
	int input = 0;
	char Name[NAME_MAX] = { 0 };
	printf("请输入你要调整的联系人:>\n");
	scanf("%s", Name);
	int pos = FindByName(pc, Name);
	if (pos == -1)
	{
		printf("要删除的人不存在，请重新输入\n");
		return;
	}
	printf("请输入你需要调整的信息\n");
	getchar();
	Menu();
	do
	{ 
		scanf("%d", &input);
		switch (input)
		{
		case NAME:
			printf("请输入需要修改的姓名\n");
			scanf("%s", pc->data[pos].Name);
			break;
		case AGE:
			printf("请输入需要修改的年龄\n");
			scanf("%d", &pc->data[pos].Age);
			break;
		case SEX:
			printf("请输入需要修改的性别\n");
			scanf("%s", pc->data[pos].Sex);
			break;
		case TELENUM:
			printf("请输入需要修改的电话号码\n");
			scanf("%s", pc->data[pos].TeleNum);
			break;
		case ADDRESS:
			printf("请输入需要修改的地址\n");
			scanf("%s", pc->data[pos].Address);
			break;
		case EXIT:
			printf("退出查找\n");
			return;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input<=0 || input>=5);
	printf("修改成功\n");
}

void SortContact(Contact* pc)
{
	assert(pc);

	int input = 0;
	if (pc->sz == 0)
	{
		printf("通讯录已空，无法排序\n");
		return;
	}
	printf("请选择排升序还是降序\n1.升序 2.降序 0.退出排序\n");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case ASC:
			qsort(&(pc->data[0]), (size_t)pc->sz, (size_t)sizeof(PeoInfo), cmp_peo_by_name1);
			break;
		case DEASC:
			qsort(&(pc->data[0]), (size_t)pc->sz, (size_t)sizeof(PeoInfo), cmp_peo_by_name2);
			break;
		case EXIT:
			return;
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input < 0 || input>2);
	printf("排序成功\n");
}
