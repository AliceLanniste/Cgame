#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "space.h"
#include "conico.h"



<<<<<<< HEAD


void gotoxy(int x,int y)  //光标移动到(x,y)位置
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

=======
void updateWithoutInput(int[][WIDTH],Plane[]);
void updateWithInput(Plane*,Bullet*,int[][WIDTH]);
void crash(Plane[],Plane*,int[][WIDTH]);
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b

/*
*初始化玩家、子弹和界面
**/

<<<<<<< HEAD
void startUp(Plane *p,Plane e[],int can[][WIDTH])
{
  //  int ballet_x,ballet_y;

  int bx,by;
=======
void startUp(Plane *p,Bullet *b,Plane e[],int can[][WIDTH])
{
  //  int ballet_x,ballet_y;

>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
  /*飞机位置*/
  p-> x = HIGH -1;
  p-> y = WIDTH / 2;
  can[p->x][p->y] = ONE;

  /*子弹坐标*/
<<<<<<< HEAD
  (p->bullet).x = p->x -1;
  (p->bullet).y = p->y;
  bx = (p->bullet).x;
  by= (p->bullet).y;
  can[bx][by] = TWO;

  /* b->x = p->x -1; */
  /* b->y = p-> y ; */
  /* can[b->x][b->y] = TWO; */
=======
  b->x = p->x -1;
  b->y = p-> y ;
  can[b->x][b->y] = TWO;
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b

  /*敌机坐标*/
  for(int i=0;i<5;i++)
    {
<<<<<<< HEAD
      int ebx,eby;
      e[i].x = rand() % 2;
      e[i].y = rand() % WIDTH;
      can[e[i].x][e[i].y] = THREE;
      /*敌机子弹*/
      (e[i].bullet).x = e[i].x +1;
      (e[i].bullet).y =e[i].y;
      ebx = (e[i].bullet).x;
      eby=(e[i].bullet).y;
      can[ebx][eby] = TWO;

=======
      e[i].x = rand() % 2;
      e[i].y = rand() % WIDTH;
      can[e[i].x][e[i].y] = THREE;
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
    }
}


/*
 *在控制台上显示
**/
void show(int can[][WIDTH])
{

  int i,j;
<<<<<<< HEAD
  gotoxy(0,0);
=======
  system("clear");
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
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
<<<<<<< HEAD
  Sleep(100);
=======
  Sleep(60);
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
}



int main(void) {
  static  int canvas[HIGH][WIDTH];
  
<<<<<<< HEAD
  //Bullet *bullet = malloc(sizeof(Bullet));
=======
  Bullet *bullet = malloc(sizeof(Bullet));
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b

  Plane *player = malloc(sizeof(Plane)), enemy[5];
  int con = 1;

<<<<<<< HEAD
  startUp(player,enemy,canvas);

  while(con)
    {
      show(canvas);
      //updateWithoutInput(canvas,enemy,player);
      //    crash(enemy,player,canvas);
      //updateWithInput(player,bullet,canvas);
=======
  startUp(player,bullet,enemy,canvas);
  
  while(con)
    {
       show(canvas);
       updateWithoutInput(canvas,enemy);
       updateWithInput(player,bullet,canvas);
       crash(enemy,player,canvas);
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
    }

  return 0;
}


<<<<<<< HEAD
/* 与控制有关的更新 */
 void updateWithInput(Plane *p,Bullet *b,int can[][WIDTH]) 
=======
/*与控制有关的更新*/
void updateWithInput(Plane *p,Bullet *b,int can[][WIDTH])
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
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
<<<<<<< HEAD
}

/* 与控制无关的更新  */

void updateWithoutInput(int can[][WIDTH],Plane enemy[],Plane *p)
{
  bulletMove(can,enemy);
  enemyBullet(can,enemy,p);
  crash(enemy,p,can);
}

/*
*TODO 敌机子弹击中玩家
* 
*玩家的子弹击中敌机
**/
void bulletMove(int can[][WIDTH],Plane e[])
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
                if(i==e[k].x && j==e[k].y)
                  {
                    can[e[k].x][e[k].y] = 0;
                    e[k].x = rand() % 2;
                    e[k].y = rand() % WIDTH;
                    can[e[k].x][e[k].y] =THREE;
                    /*子弹消失*/
                    can[i][j]= ZERO;
                  }
              }
            /*子弹向上移动*/
            can[i][j] = 0;
            if(i > 0)
              can[i-2][j] = TWO;

          }
      }
  }
}
/*上面的bulletMove太多嵌套行动会比较慢*/
void bullet2Move(int can[][WIDTH],Plane *p,Plane e[])
{
  int pbullet_x = (p->bullet).x;
  int pbullet_y = (p->bullet).y;

 

  for(k=0;k<5;k++)
  {

    if((pbullet_x==e[k].x) && (pbullet_y==e[k].y))
    {
      can[e[k].x][e[k].y] = 0;
      e[k].x = rand() % 2;
      e[k].y = rand() % WIDTH;
      can[e[k].x][e[k].y] = 3;
      can[pbullet_x][pbullet_y] = 2;
    }

     /*玩家子弹向上移动*/
  can[pbullet_x][pbullet_y] = 0;
  if(pbullet_x > 0)
    can[pbullet_x-2][pbullet_y] = 2;
  }  

   
=======


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

>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
}



<<<<<<< HEAD

void crash(Plane e[],Plane *p,int can[][WIDTH])
{
  int k;

  static int speed = 0;
  if(speed < 20)
    speed++;

  for(k=0;k<5;k++)
    {
      /*敌机降落*/
      if(e[k].x > HIGH)
        {
          can[e[k].x][e[k].y] =0;
          e[k].x = rand() % 2;
          e[k].y = rand() % WIDTH;
          can[e[k].x][e[k].y] = 3;
          e[k].bullet.x = e[k].x+1;
          e[k].bullet.y = e[k].y; 
          can[e[k].bullet.x][e[k].bullet.y] = 2;
          
        }

      if(p->x==e[k].x && p->y==e[k].y)
        {
          printf("失败\n");
          Sleep(3000);
          exit(0);
        }

      if(speed== 20)
        {
          for(k=0;k<5;k++)
            {
              can[e[k].x][e[k].y] = 0;
              ++e[k].x;
              speed =0;
              can[e[k].x][e[k].y] = 3;
            }
        }
    }
  Sleep(100);

}

/*敌机子弹需要一直往下射击
*如果子弹大于HIGH则消失
*敌机子弹射中玩家
**/
void enemyBullet(int can[][WIDTH],Plane e[],Plane *p)
{
  int k;
  for(k=0;k<5;k++)
  {
    int x=e[k].bullet.x,y=e[k].bullet.y;
    /*子弹超过边界*/
   if(x > HIGH)
     can[x][y] = 0;
 
     /*敌机子弹向下飞*/
  can[x][y] = 0;
  can[x+1][y] = 2;   

/*敌机子弹射中玩家*/
  if((x==p->x) && (y==p->y))
  {
    can[p->x][p->y] = 0;
    printf("结束\n");
    Sleep(200);
    exit(0);
  }
  }
=======
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
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b
}
