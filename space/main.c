/*
 * main.c
 */
#include<stdio.h>
#include "space.h"
/*
 * 1.首先
 */



int main(void)
{
int position_x=0,position_y=0; /*飞机的初始坐标变量*/
int canvas[HIGH][WIDTH] = { 0 };
int enemyNum = 4;
 int enemySpeed = 5; /*敌机速度*/
int enemyX[enemyNum],enemyY[enemyNum];
int con = 1;

startUp(&position_x,&position_y,HIGH,WIDTH,canvas);
enemyStart(enemyNum,enemyX,enemyY,WIDTH,canvas);
while(con)
  {
show(WIDTH,HIGH,canvas);
 updateWithoutInput(HIGH,WIDTH,canvas,enemyNum,enemyX,enemyY);

  enemyHappens(enemyNum,HIGH,WIDTH,enemyX,enemyY,canvas,&position_x,&position_y); 
 updateWithInput(canvas,&position_x,&position_y);
}


return 0;
}

