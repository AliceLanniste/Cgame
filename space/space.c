#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "space.h"
#include "conico.h"



void updateWithoutInput(int[][WIDTH],Plane[]);
void updateWithInput(Plane*,Bullet*,int[][WIDTH]);
void crash(Plane[],Plane*,int[][WIDTH]);

/*
*初始化玩家、子弹和界面
**/

void startUp(Plane *p,Bullet *b,Plane e[],int can[][WIDTH])
{
  //  int ballet_x,ballet_y;

  /*飞机位置*/
  p-> x = HIGH -1;
  p-> y = WIDTH / 2;
  can[p->x][p->y] = ONE;

  /*子弹坐标*/
  b->x = p->x -1;
  b->y = p-> y ;
  can[b->x][b->y] = TWO;

  /*敌机坐标*/
  for(int i=0;i<5;i++)
    {
      e[i].x = rand() % 2;
      e[i].y = rand() % WIDTH;
      can[e[i].x][e[i].y] = THREE;
    }
}


/*
 *在控制台上显示
**/
void show(int can[][WIDTH])
{

  int i,j;
  system("clear");
  for(i=0;i<HIGH;i++)
    {
      for(j=0;j<WIDTH;j++)
        {
          switch(can[i][j])
            {
            case ONE: printf("*"); break;
            case TWO: printf("|"); break;
            case THREE: printf("#");break;
            default: printf(" ");
            }
        }
      printf("\n");
    }
  Sleep(60);
}



int main(void) {
  static  int canvas[HIGH][WIDTH];
  
  Bullet *bullet = malloc(sizeof(Bullet));

  Plane *player = malloc(sizeof(Plane)), enemy[5];
  int con = 1;

  startUp(player,bullet,enemy,canvas);
  
  while(con)
    {
       show(canvas);
       updateWithoutInput(canvas,enemy);
       updateWithInput(player,bullet,canvas);
       crash(enemy,player,canvas);
    }

  return 0;
}


/*与控制有关的更新*/
void updateWithInput(Plane *p,Bullet *b,int can[][WIDTH])
{
  char input;
  

  
  /*
   *通过键盘来操控飞机和子弹的运动方向
   */
  if(kbhit())
    {
      input = getchar();

      if(input =='a' && p->y > ZERO)
        {
          can[p->x][p->y] =0;
          --(p->y);
          can[p->x][p->y] = 1;

          /*子弹随飞机的移动而移动*/
          --(b->y);
          can[b->x][b->y] = 2;

        }
      if(input=='j' && p->x <WIDTH)
        {
          can[p->x][p->y] = 0;
          ++(p->y);
          can[p->x][p->y] = 1;

          ++(b->y);
          can[b->x][b->y] = 2;
        }
      if(input=='w')
        {
          can[p->x][p->y] =0;
          --(p->x);
          can[p->x][p->y] = 1;
          --(b->x);
          can[b->x][b->y] =2;
        }
      if(input=='b')
        {
          can[p->x][p->y] =0;
          ++(p->x);
          can[p->x][p->y] = 1;

          ++(b->x);
          can[b->x][b->y] =2;
        }
    }


}



/*与控制无关的更新*/
void updateWithoutInput(int can[][WIDTH],Plane enemy[])
{
  int i,j,k;

  for(i=0;i<HIGH;i++)
    {
      for(j=0;j<WIDTH;j++)
        {
          if(can[i][j]==TWO)
            {
              for(k=0;k<5;k++)
                {

                  /*子弹击中敌机*/
                  if(i==enemy[k].x && j==enemy[k].y)
                    {
                      can[enemy[k].x][enemy[k].y] = 0;
                      enemy[k].x = rand() % 2;
                      enemy[k].y = rand() % WIDTH;
                      can[enemy[k].x][enemy[k].y] =THREE;
                      /*子弹消失*/
                      can[i][j]= ZERO;
                    }
                }
              /*子弹向上移动*/
              can[i][j] = 0;
              if(i > 0)
                can[i-1][j] = TWO;

            }
        }
    }

}



void crash(Plane enemy[],Plane *p,int can[][WIDTH])
{
  int k;
  static int speed = 0;
  if(speed < 5)
    speed++;

  if(speed == 5)
    {

      for(k=0;k<5;k++)
        {
      can[enemy[k].x][enemy[k].y] = 0;
      enemy[k].x++;
      speed = 0;
      can[enemy[k].x][enemy[k].y] = 3;
        }
    }
}
