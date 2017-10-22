/*
 *show.c
 *在控制台上显示飞机和敌机
 */

#include<stdio.h>
#include<windows.h>

void show(int WIDTH,int HIGH,int canvas[][WIDTH])
{
  int i,j;
  system("clear");

  for(i=0;i<HIGH;i++)
    {
      for(j=0;j<WIDTH;j++)
        {
          if (canvas[i][j]== 0)
            printf(" ");

          if (canvas[i][j] == 1)
            printf("*");

          if(canvas[i][j] ==2)
            printf("|");

          if(canvas[i][j] == 3)
            printf("#");
        }
      printf("\n");
    }
  Sleep(40);
}
