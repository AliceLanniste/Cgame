#ifndef SPACE_H
#define SPACE_H

#define HIGH 30
#define WIDTH 40
extern  void startUp(int* ,int* ,int,int,int[][WIDTH]);
extern void enemyStart(int,int[],int[],int,int[][WIDTH]);

extern void enemyHappens(int,int,int,int[],int[],int[][WIDTH],int*,int*);
extern void updateWithInput(int[][WIDTH],int*,int*);
extern void updateWithoutInput(int,int, int[][WIDTH],int,int[],int[]);
extern void show(int,int,int[][WIDTH]);
#endif
