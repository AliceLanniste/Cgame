#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "space.h"
#include "conico.h"



void updateWithoutInput(int[][WIDTH],Plane[]);
void updateWithInput(Plane*,int[][WIDTH]);



void startUp(Plane *p,Plane e[],int can[][WIDTH])
{
  int ballet_x,ballet_y;

  /*飞机位置*/
  p-> x = HIGH -1;
  p-> y = WIDTH / 2;
  can[p->x][p->y] = ONE;

  /*子弹坐标*/
  ballet_x = p->x -1;
   ballet_y = p-> y ;
  can[ballet_x][ballet_y] = TWO;

  /*敌机坐标*/
  for(int i=0;i<5;i++)
    {
      e[i].x = rand() % 2;
      e[i].y = rand() % WIDTH;
      can[e[i].x][e[i].y] = THREE;
    }
}

void show(int can[][WIDTH])
{

  int i,j;
  system("clear");
  for(i=0;i<WIDTH;i++)
    {
      for(j=0;j<HIGH;j++)
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
  Sleep(40);
}



int main(void) {
  static int canvas[HIGH][WIDTH];
  

  Plane *player = malloc(sizeof(Plane)), enemy[5];
  int con = 1;

  startUp(player,enemy,canvas);
  
  while(con)
    {
       show(canvas);
       updateWithoutInput(canvas,enemy);
       updateWithInput(player,canvas);
  }

  return 0;
}


/*与控制有关的更新*/
void updateWithInput(Plane *p,int can[][WIDTH])
{
  char input;
  int k;

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
        }
      if(input=='j' && p->x <WIDTH)
        {
          can[p->x][p->y] = 0;
          ++(p->y);
          can[p->x][p->y] = 1;
        }
      if(input=='w')
        {
          can[p->x][p->y] =0;
          --(p->x);
          can[p->x][p->y] = 1;
        }
      if(input=='b')
        {
          can[p->x][p->y] =0;
          ++(p->x);
          can[p->x][p->y] = 1;
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
                  if(i==enemy[k].x && j==enemy[k].y)
                    {
                      can[enemy[k].x][enemy[k].y] = 0;
                      enemy[k].x = rand() % 2;
                      enemy[k].y = rand() % WIDTH;
                      can[enemy[k].x][enemy[k].y] =THREE;
                      can[i][j] = ZERO;
                    }
                }
              can[i][j] = 0;
              if(i > 0)
                can[i-1][j] = TWO;

            }
        }
    }
}

