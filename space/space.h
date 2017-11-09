#ifndef SPACE_H
#define SPACE_H

#define HIGH 15
#define WIDTH 40

enum LEVEL {
  ZERO,
  ONE,
  TWO,
  THREE

};




<<<<<<< HEAD




typedef struct bulletXY
{
  int x;
  int y;
} Bullet;


typedef struct PlaneXY
{
  int x;
  int y;
  Bullet bullet;
} Plane;


void updateWithoutInput(int[][WIDTH],Plane[],Plane*);
void updateWithInput(Plane*,Bullet*,int[][WIDTH]);
void crash(Plane[],Plane*,int[][WIDTH]);
void bulletMove(int[][WIDTH],Plane[]);

=======
typedef struct planeXY
{
  int x;
  int y;
} Plane;

typedef struct bulletXY
{
  int x;
  int y;
} Bullet;
>>>>>>> 4939033cfd6839159755a417173527867ca8f99b

 #endif
