#ifndef _AMJMEMORY_H
#define _AMJMEMORY_H

#include <stdlib.h>
#include <stdio.h>

#define uint8 unsigned char
#define uint32  unsigned int
#define int32 int

/****************************************************************************
 *                                                                          *
 *         In this section are general memory allocation routines           *
 *                                                                          *
 ****************************************************************************/

void *amjSafeMalloc(int n, char *message);
void *amjSafeRealloc(void *i, int n, char *message);


/****************************************************************************
 *                                                                          *
 *         In this section are specific array allocation routines           *
 *                                                                          *
 ****************************************************************************/

char *amjMalloc1dChar(int a, char *message);
void amjFree1dChar(char *d);
char **amjMalloc2dChar(int a, int b, char *messsage);
void amjFree2dChar(char **d);
char ***amjMalloc3dChar(int a, int b, int c, char *message);
void amjFree3dChar(char ***d);
unsigned char *amjMalloc1dUChar(int a, char *message);
void amjFree1dUChar(unsigned char *d);
unsigned char ***amjMalloc3dUChar(int a, int b, int c, char *message);
void amjFree3dUChar(unsigned char ***d);
uint8 ***amjMalloc3dUint8(int a, int b, int c, char *message);
void amjFree3dUint8(uint8 ***d);
short int *amjMalloc1dShortInt(int a, char *message);
void amjFree1dShortInt(short int *d);
short int **amjMalloc2dShortInt(int a, int b, char *message);
void amjFree2dShortInt(short int **d);
unsigned short int **amjMalloc2dShortUint(int a, int b, char *message);
void amjFree2dShortUint(unsigned short int **d);
int *amjMalloc1dInt(int a, char *message);
void amjFree1dInt(int *d);
int **amjMalloc2dInt(int a, int b, char *message);
void amjFree2dInt(int **d);
int32 *amjMalloc1dInt32(int a, char *message);
void amjFree1dInt32(int32 *d);
uint32 *amjMalloc1dUint32(int a, char *message);
void amjFree1dUint32(uint32 *d);
unsigned long *amjMalloc1dULong(int a, char *message);
void amjFree1dULong(unsigned long *d);
float *amjMalloc1dFloat(int a, char *message);
void amjFree1dFloat(float *d);
float **amjMalloc2dFloat(int a, int b, char *message);
void amjFree2dFloat(float **d);
float ***amjMalloc3dFloat(int a, int b, int c, char *message);
void amjFree3dFloat(float ***d);
float ****amjMalloc4dFloat(int a, int b, int c, int d, char *message);
void amjFree4dFloat(float ****d);
double *amjMalloc1dDouble(int a, char *message);
void amjFree1dDouble(double *d);
double **amjMalloc2dDouble(int a, int b, char *message);
void amjFree2dDouble(double **d);
double ***amjMalloc3dDouble(int a, int b, int c, char *message);
void amjFree3dDouble(double ***d);
double ****amjMalloc4dDouble(int a, int b, int c, int d, char *message);
void amjFree4dDouble(double ****d);
double *****amjMalloc5dDouble(int a, int b, int c, int d, int e, char *message);
void amjFree5dDouble(double *****d);
double ******amjMalloc6dDouble(int a, int b, int c, int d, int e, int f, 
			       char *message);
void amjFree6dDouble(double ******d);

#endif
