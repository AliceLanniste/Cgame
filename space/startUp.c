/*
 *startUp.c
 *
 *1.空白地方
 *2.确定飞机位置
 *3.给定敌机坐标
 *4.飞机子弹的位置
 */

#include<stdlib.h>
#include"space.h"

void startUp(Plane* p,Plane s[])
{
  int k;
  p->x = HIGH -1;
  p->y = WIDTH / 2;

  canvas[p->x][p->y] = ONE;

  /* for(k=0;k<5;k++) { */
  /*   s[k].x = rand() % 2; */
    /* s[k].y = rand() % WIDTH; */
    /* canvas[s[k].x][s[k].y]=THREE; */

  /* } */

}




/* void startUp(int *x,int *y,int HIGH,int WIDTH,int canvas[][WIDTH]) */
/* { */

/*   *x = HIGH -1; */
/*   *y = WIDTH / 2; */

/*   canvas[*x][*y] = 1; */
/*   canvas[HIGH-2][WIDTH /2] = 2; */

/* } */

/* void enemyStart(int number,int enemyx[], */
/*                 int enemyY[],int WIDTH, */
/*                 int canvas[][WIDTH]) */

/* { */
/*   int k; */
/*   for(k=0;k<number;k++) */
/*     { */
/*       enemyx[k] = rand() % 2; */
/*       enemyY[k] = rand() % WIDTH; */
/*       canvas[enemyx[k]][enemyY[k]] = 3; */
/*     } */

/* } */
