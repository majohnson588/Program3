#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	SEARCH,
	DELE,
	MODIFY,
	SORT,
	PRINT
};

void menu()
{
	printf("_________________CONTACT___________________\n");
	printf("|**********  1.add   2.search  ***********|\n");
	printf("|**********  3.del   4.modify  ***********|\n");
	printf("|**********  5.sort  6.print   ***********|\n");
	printf("|**********  0.exit            ***********|\n");
}

int main()
{
	Contact con;
	int input = 0;
	InitContact(&con);
	do
	{
		int ret = 0;
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DELE:
			DelContact(&con);
			break;
		case SEARCH:
			SearchByName(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
