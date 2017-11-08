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

 #endif
