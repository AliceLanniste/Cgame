/*
 * updateWithInput 和updateWithoutInput
 *
 */

#include "conico.h"
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>

/*
 *与控制有关的操作
 *除了飞机的上下控制还有子弹的位置
 */

void updateWithInput(int canvas[][40],int *x,int *y)
{
  char input;
  int k;


  if(kbhit())
    {
      input = getchar();
      static int bullet_x = 28;
      static int bullet_y = 20;

      if(input =='a' && *y> 0)
        {
          canvas[*x][*y] = 0;
          *y=*y-1;
          canvas[*x][*y] = 1;

           bullet_y = bullet_y -1;

          canvas[bullet_x][bullet_y] = 2;

        }

      if(input =='j' && *y< 40)
        {
          canvas[*x][*y] = 0;
          *y = *y + 1;
          canvas[*x][*y] = 1;

          bullet_y++;
          canvas[bullet_x][bullet_y] = 2;
        }
      if(input == 'w')
        {
          canvas[*x][*y] = 0;
          *x=*x-1;
          canvas[*x][*y]= 1;

          bullet_x--;
          canvas[bullet_x][bullet_y] = 2;
        }
      if(input=='b')
        {
          canvas[*x][*y] = 0;
          *x =*x+1;
          canvas[*x][*y] = 1;

          bullet_x++;
          canvas[bullet_x][bullet_y] = 2;
         }
      /*  printf("%d %d\n",*x,*y); */
    }
}


/*
 *与控制无关的操作，包括子弹的向上发射
 *以及敌机的降落
 */

void updateWithoutInput(int high,int width,int canvas[][40],int num,int ex[],int ey[])
{
  int i,j,k;

  for(i=0;i<high;i++)
    {
      for(j=0;j<width;j++)
        {
          /*子弹向上发射
           *如果不限定 i> 0 会引发段错误
           */
          if(canvas[i][j] == 2)
            {
              /*子弹射中敌机*/
              for(k=0;k<num;k++)
                {
                  if(i==ex[k] && j == ey[k])
                    {
                      canvas[ex[k]][ey[k]] =0;
                      ex[k] = rand() % 2;
                      ey[k] = rand() % width;
                      canvas[ex[k]][ey[k]] = 3;
                      canvas[i][j] =0;
                     } 
                 }
              canvas[i][j] = 0;
              if(i > 0)
                canvas[i-1][j] =2;


            }
 
        }
     }

}

void enemyHappens(int num,int high,int width,int ex[],int ey[],int canvas[][40],int *x,int *y)
{
  int k;
  static int speed =0;

  if(speed < 20)
    speed++;

  /*敌机降落*/

  if (speed == 20)
{
  for(k=0;k<num;k++)
    {
      canvas[ex[k]][ey[k]] = 0;
      ex[k]++;
      speed = 0;
      canvas[ex[k]][ey[k]] = 3;

  /*敌机离开边界以及产生新的敌机*/
      if(ex[k] > high)
        {
              canvas[ex[k]][ey[k]] = 0;
          ex[k] = rand() % 2 ;
          ey[k] = rand() % width;
          canvas[ex[k]][ey[k]] = 3;
        }

  /*敌机20和飞机碰撞判断*/
      if(*x==ex[k] && *y==ey[k])
      {
        printf("failed\n");
        Sleep(200);
        exit(0);
      }

    }
 }
} 



