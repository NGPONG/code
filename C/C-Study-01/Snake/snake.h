#ifndef __SNAKE_H__
#define __SNAKE_H__ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define WIDE 60	
#define HIGH 20	

/*
struct
*/
typedef struct postion {

	int X;
	int Y;
} potsion_t;

typedef struct SNAKE {

	potsion_t head;
	potsion_t body[WIDE * HIGH];
	int size;
} snake_t;

typedef struct FOOD {
	
	int X;
	int Y;
} food_t;


/*
field
*/
int score = 0;
snake_t snake;
food_t food;

/*
function
*/
void init_global(void);
void initSnake(void);
void initFood(void);
void drawWall(void);
void drawSnake(void);
void playGame(void);
void draw(int x, int y, char value);
#endif              

