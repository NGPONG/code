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

	// 取出光标定位
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	// 随机数种子
	srand(time(NULL));
}

void initSnake(void) {

	snake.size = 0;

	// 蛇头
	snake.head.X = WIDE / 2;
	snake.head.Y = HIGH / 2;

	// 身体
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
	去除蛇尾
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

	// 蛇头
	draw(snake.head.X, snake.head.Y, '@');

	// 蛇身
	for (size_t i = 0; i <= snake.size; i++) {

		draw(snake.body[i].X, snake.body[i].Y, '*');
	}
}

void playGame(void) {

	static char key_last = 0;
	char key = 0;

	while (snake.head.X >= 0 && snake.head.X < WIDE &&	// 判断是否碰撞到墙壁
		   snake.head.Y >= 0 && snake.head.Y < HIGH) {

		/*
		是否碰撞身体
		*/
		for (size_t i = 1; i < snake.size; i++) {

			if (snake.head.X == snake.body[i].X &&
				snake.head.Y == snake.body[i].Y) {

				return;
			}
		}

		/*
		非阻塞接受输入
		*/
		if (_kbhit()) {

			key = _getch();
		}

		/*
		游戏开始的时候，蛇保持不动，直至用户输入了方向键后才开始行动
		*/
		if (key == 0) {

			continue;
		}
		
		/*
		以蛇头作为 "坐标"，当用户输入了方向键 (wasd) 后，先改变蛇头的坐标点，
		蛇身部分则为下一个元素拿下一个元素的位置

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
		食物事件
		*/
		if (snake.head.X == food.X && snake.head.Y == food.Y) {

			initFood();						// 重置食物
			isEat = TRUE;
			snake.size++;					// 身体增长
			score += 10;					// 加分
		}

		Sleep(85);
	}

	return;
}