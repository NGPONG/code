#pragma warning(disable:6031)
#pragma warning(disable:4996)			

#include "snake.h"

int isEat = FALSE;

int main(void) {

	init_global();
	initSnake();
	drawWall();
	initFood();
	drawSnake();

	playGame();

	system("pause");
	return EXIT_SUCCESS;
}

void init_global(void) {

	// ȡ����궨λ
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	// ���������
	srand(time(NULL));
}

void initSnake(void) {

	snake.size = 0;

	// ��ͷ
	snake.head.X = WIDE / 2;
	snake.head.Y = HIGH / 2;

	// ����
	snake.body[0].X = WIDE / 2 - 1;
	snake.body[0].Y = HIGH / 2;
}

void initFood(void) {

	food.X = rand() % WIDE;
	food.Y = rand() % HIGH;
	draw(food.X, food.Y, '#');
}

void draw(int x, int y, char value) {

	COORD coord = { 0 };
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(value);
}

void drawWall(void) {
	for (size_t i = 0; i <= HIGH; i++)
	{
		for (size_t j = 0; j <= WIDE; j++)
		{
			if (j == WIDE) {
				printf("|");
			}
			else if (i == HIGH) {
				printf("_");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

void drawSnake_Head(void) {

	draw(snake.head.X, snake.head.Y, '@');
}

void drawSnake_Body(void) {

	for (size_t i = 0; i <= snake.size; i++) {

		if (i == 0) {

			draw(snake.head.X, snake.head.Y, '*');
		}
		else {
		
			draw(snake.body[i - 1].X, snake.body[i - 1].Y, '*');
		}
	}

	/* 
	ȥ����β
	*/
	if (isEat) {

		isEat = FALSE;
	}
	else {

		draw(snake.body[snake.size].X, snake.body[snake.size].Y, ' ');
	}

	for (int i = snake.size; i >= 0; i--) {

		if (i == 0) {

			snake.body[0] = snake.head;
		}
		else {

			snake.body[i] = snake.body[i - 1];
		}
	}
}

void drawSnake(void) {

	// ��ͷ
	draw(snake.head.X, snake.head.Y, '@');

	// ����
	for (size_t i = 0; i <= snake.size; i++) {

		draw(snake.body[i].X, snake.body[i].Y, '*');
	}
}

void playGame(void) {

	static char key_last = 0;
	char key = 0;

	while (snake.head.X >= 0 && snake.head.X < WIDE &&	// �ж��Ƿ���ײ��ǽ��
		   snake.head.Y >= 0 && snake.head.Y < HIGH) {

		/*
		�Ƿ���ײ����
		*/
		for (size_t i = 1; i < snake.size; i++) {

			if (snake.head.X == snake.body[i].X &&
				snake.head.Y == snake.body[i].Y) {

				return;
			}
		}

		/*
		��������������
		*/
		if (_kbhit()) {

			key = _getch();
		}

		/*
		��Ϸ��ʼ��ʱ���߱��ֲ�����ֱ���û������˷������ſ�ʼ�ж�
		*/
		if (key == 0) {

			continue;
		}
		
		/*
		����ͷ��Ϊ "����"�����û������˷���� (wasd) ���ȸı���ͷ������㣬
		��������Ϊ��һ��Ԫ������һ��Ԫ�ص�λ��

			0123456789				0123456789
			+---------+				+---------+
		   1|		  |			   1|  	      |
		   2| **@	  |		=> 	   2|  **@	  |		=> (2,2),(2,3),(2,4)	=> (2,3),(2,4),(2,5)
		   3|		  |			   3|		  |
			+---------+				+---------+
		*/

		drawSnake_Body();

		switch (key) {
		case 'w': 
			snake.head.Y--; 
			break;
		case 'a': 
			snake.head.X--;
			break;
		case 's': 
			snake.head.Y++; 
			break;
		case 'd': 
			snake.head.X++;
			break;
		default:
			break;
		}

		drawSnake_Head();

		/*
		ʳ���¼�
		*/
		if (snake.head.X == food.X && snake.head.Y == food.Y) {

			initFood();						// ����ʳ��
			isEat = TRUE;
			snake.size++;					// ��������
			score += 10;					// �ӷ�
		}

		Sleep(85);
	}

	return;
}