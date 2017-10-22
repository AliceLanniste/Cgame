/*
 *startUp.c
 *
 *1.空白地方
 *2.确定飞机位置
 *3.给定敌机坐标
 *4.飞机子弹的位置
 */

#include<stdlib.h>

void startUp(int *x,int *y,int HIGH,int WIDTH,int canvas[][WIDTH])
{

  *x = HIGH -1;
  *y = WIDTH / 2;

  canvas[*x][*y] = 1;
  canvas[HIGH-2][WIDTH /2] = 2;

}

void enemyStart(int number,int enemyx[],
                int enemyY[],int WIDTH,
                int canvas[][WIDTH])

{
  int k;
  for(k=0;k<number;k++)
    {
      enemyx[k] = rand() % 2;
      enemyY[k] = rand() % WIDTH;
      canvas[enemyx[k]][enemyY[k]] = 3;
    }

}
