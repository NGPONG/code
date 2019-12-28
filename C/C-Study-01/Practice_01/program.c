#include <stdio.h>
#include <Windows.h>

int main_MultiplicationTable_Asc(void) {

	int num = 1;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			printf("%d x %d = %d", j, i, i * j);
			if (num != j) {
			
				putchar('\t');
			}
		}
		putchar('\n');
		num++;
	}

	system("pause");
	return 0;
}

int main_MultiplicationTable_Desc(void) {

	int num = 9;

	for (int i = 9; i >= 1; i--)
	{
		for (int j = 1; j <= num; j++)
		{
			printf("%d x %d = %d", j, i, i * j);
			if (num != j) {

				putchar('\t');
			}
		}
		putchar('\n');
		num--;
	}

	system("pause");
	return 0;
}