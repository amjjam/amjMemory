#include "amjMemory.h"

char msg[1000];

/****************************************************************************
 *                                                                          *
 *         In this section are general memory allocation routines           *
 *                                                                          *
 ****************************************************************************/

/*==========================================================================
  amjSafeMalloc
 
  Allocates memory, but exits with an error message if the memory
  allocation fails.
 
  ==========================================================================*/
 
void *amjSafeMalloc(int n, char *message){
  
  void *d;

  d=malloc(n);

  if(d==NULL){
    fprintf(stderr,"amjSafeMalloc error: Could not allocate %d bytes "
	    "for %s. Exiting.\n",n,message);
    exit(1);
  }
  
  return d;
}


/*==========================================================================
  amjSafeRealloc
 
  Re-allocates memory, but exits with an error message if the memory
  allocation fails.
 
  ==========================================================================*/
 
void *amjSafeRealloc(void *i, int n, char *message){
  
  void *d;

  d=realloc(i,n);

  if(d==NULL){
    fprintf(stderr,"amjSafeRealloc error: Could not re-allocate %d bytes "
	    "for %s. Exiting.\n",n,message);
    exit(1);
  }
  
  return d;
}



/****************************************************************************
 *                                                                          *
 *         In this section are specific array allocation routines           *
 *                                                                          *
 ****************************************************************************/

char *amjMalloc1dChar(int a, char *message){
  char *d;

  sprintf(msg,"%s: amjMalloc1dChar:d",message);
  d=(char *)amjSafeMalloc(sizeof(char)*a,msg);
  
  return d;
}

/****************************************************************************/

void amjFree1dChar(char *d){

  free(d);
}
   
/****************************************************************************/

char **amjMalloc2dChar(int a, int b, char *message){
  char **d;
  int i;

  sprintf(msg,"%s: amjMalloc2dChar:d",message);
  d=(char **)amjSafeMalloc(sizeof(char *)*a,msg);
  d[0]=(char *)amjSafeMalloc(sizeof(char)*a*b,msg);
  for(i=1;i<a;i++) d[i]=d[i-1]+b;
  
  return d;
}

/****************************************************************************/

void amjFree2dChar(char **d){

  free(d[0]);
  free(d);
}
   
/****************************************************************************/

char ***amjMalloc3dChar(int a, int b, int c, char *message){
  char ***d;
  int i,j;

  sprintf(msg,"%s: amjMalloc3dChar:d",message);
  d=(char ***)amjSafeMalloc(sizeof(char **)*a,msg);
  sprintf(msg,"%s: amjMalloc3dChar:d[0]",message);
  d[0]=(char **)amjSafeMalloc(sizeof(char *)*a*b,msg);
  sprintf(msg,"%s:amjMalloc3dChar:d[0][0]",message);
  d[0][0]=(char *)amjSafeMalloc(sizeof(char)*a*b*c,msg);

  for(i=0;i<a;i++){
    d[i]=d[0]+i*b;
    for(j=0;j<b;j++)
      d[i][j]=d[0][0]+(i*b+j)*c;
  }

  return d;
}

/****************************************************************************/

void amjFree3dChar(char ***d){
  
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

unsigned char *amjMalloc1dUChar(int a, char *message){
  unsigned char *d;

  sprintf(msg,"%s: amjMalloc1dUChar:d",message);
  d=(unsigned char *)amjSafeMalloc(sizeof(unsigned char)*a,msg);
  
  return d;
}


/****************************************************************************/

void amjFree1dUChar(unsigned char *d){

  free(d);
}

/****************************************************************************/
   
unsigned char ***amjMalloc3dUChar(int a, int b, int c, char *message){
  unsigned char ***d;
  int i,j;

  sprintf(msg,"%s: amjMalloc3dChar:d",message);
  d=(unsigned char ***)amjSafeMalloc(sizeof(char **)*a,msg);
  sprintf(msg,"%s: amjMalloc3dChar:d[0]",message);
  d[0]=(unsigned char **)amjSafeMalloc(sizeof(char *)*a*b,msg);
  sprintf(msg,"%s:amjMalloc3dChar:d[0][0]",message);
  d[0][0]=(unsigned char *)amjSafeMalloc(sizeof(char)*a*b*c,msg);

  for(i=0;i<a;i++){
    d[i]=d[0]+i*b;
    for(j=0;j<b;j++)
      d[i][j]=d[0][0]+(i*b+j)*c;
  }

  return d;
}

/****************************************************************************/

void amjFree3dUChar(unsigned char ***d){
  
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

uint8 ***amjMalloc3dUint8(int a, int b, int c, char *message){
  uint8 ***d;
  int i,j;

  sprintf(msg,"%s: amjMalloc3dChar:d",message);
  d=(unsigned char ***)amjSafeMalloc(sizeof(uint8 **)*a,msg);
  sprintf(msg,"%s: amjMalloc3dChar:d[0]",message);
  d[0]=(unsigned char **)amjSafeMalloc(sizeof(uint8 *)*a*b,msg);
  sprintf(msg,"%s:amjMalloc3dChar:d[0][0]",message);
  d[0][0]=(unsigned char *)amjSafeMalloc(sizeof(uint8)*a*b*c,msg);

  for(i=0;i<a;i++){
    d[i]=d[0]+i*b;
    for(j=0;j<b;j++)
      d[i][j]=d[0][0]+(i*b+j)*c;
  }

  return d;
}

/****************************************************************************/

void amjFree3dUint8(uint8 ***d){
  
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

short int *amjMalloc1dShortInt(int a, char *message){
  short int *d;
  sprintf(msg,"%s: amjMalloc1dShortInt:d",message);
  d=(short int *)amjSafeMalloc(sizeof(short int)*a,msg);
 
  return d;
}

/****************************************************************************/

void amjFree1dShortInt(short int *d){
  free(d);
}

/****************************************************************************/

short int **amjMalloc2dShortInt(int a, int b, char *message){
  short int **d;
  int i;

  sprintf(msg,"%s:amjMalloc2dShortInt:d",message);
  d=(short int **)amjSafeMalloc(sizeof(short int *)*a,msg);
  sprintf(msg,"%s:amjMalloc2dShortInt:d[0]",message);
  d[0]=(short int *)amjSafeMalloc(sizeof(short int)*a*b,msg);
  
  for(i=1;i<a;i++) d[i]=d[i-1]+b;
  
  return d;
}

/****************************************************************************/

void amjFree2dShortInt(short int **d){

  free(d[0]);
  free(d);
}

/****************************************************************************/

unsigned short int **amjMalloc2dShortUint(int a, int b, char *message){
  unsigned short int **d;
  int i;

  sprintf(msg,"%s:amjMalloc2dShortUint:d",message);
  d=(short unsigned int **)amjSafeMalloc(sizeof(unsigned short int *)*a,msg);
  sprintf(msg,"%s:amjMalloc2dShortUint:d[0]",message);
  d[0]=(short unsigned int *)amjSafeMalloc(sizeof(unsigned short int)*a*b,msg);
  
  for(i=1;i<a;i++) d[i]=d[i-1]+b;
  
  return d;
}

/****************************************************************************/

void amjFree2dShortUint(unsigned short int **d){

  free(d[0]);
  free(d);
}

/****************************************************************************/

int *amjMalloc1dInt(int a, char *message){
  int *d;

  sprintf(msg,"%s: amjMalloc1dInt:d",message);
  d=(int *)amjSafeMalloc(sizeof(int)*a,msg);
  
  return d;
}

/****************************************************************************/

void amjFree1dInt(int *d){

  free(d);
}

/****************************************************************************/

int **amjMalloc2dInt(int a, int b, char *message){
  int **d;
  int i;

  sprintf(msg,"%s: amjMalloc2dInt:d",message);
  d=(int **)amjSafeMalloc(sizeof(int *)*a,msg);
  d[0]=(int *)amjSafeMalloc(sizeof(int)*a*b,msg);
  for(i=1;i<a;i++) d[i]=d[i-1]+b;
  
  return d;
}

/****************************************************************************/

void amjFree2dInt(int **d){

  free(d[0]);
  free(d);
}
   
/****************************************************************************/

int32 *amjMalloc1dInt32(int a, char *message){
  int *d;

  sprintf(msg,"%s: amjMalloc1dInt32:d",message);
  d=(int32 *)amjSafeMalloc(sizeof(int32)*a,msg);
  
  return d;
}

/****************************************************************************/

void amjFree1dInt32(int32 *d){

  free(d);
}

/****************************************************************************/

uint32 *amjMalloc1dUint32(int a, char *message){
  uint32 *d;

  sprintf(msg,"%s: amjMalloc1dInt:d",message);
  d=(uint32 *)amjSafeMalloc(sizeof(uint32)*a,msg);
  
  return d;
}

/****************************************************************************/

void amjFree1dUint32(uint32 *d){

  free(d);
}

/****************************************************************************/

unsigned long *amjMalloc1dULong(int a, char *message){
  unsigned long *d;

  sprintf(msg,"%s: amjMalloc1dULong:d",message);
  d=(unsigned long *)amjSafeMalloc(sizeof(unsigned long)*a,msg);
  
  return d;
}

/****************************************************************************/

void amjFree1dULong(unsigned long *d){
  
  free(d);
}

/****************************************************************************/

float *amjMalloc1dFloat(int a, char *message){

  float *d;

  sprintf(msg,"%s:amjMalloc1DFloat:d",message);
  d=(float *)amjSafeMalloc(sizeof(float)*a,msg);
  
  return d;
}

/****************************************************************************/

void amjFree1dFloat(float *d){

  free(d);
}

/****************************************************************************/

float **amjMalloc2dFloat(int a, int b, char *message){
  
  float **d;
  int i;

  sprintf(msg,"%s:amjMalloc2DFloat:d",message);
  d=(float **)amjSafeMalloc(sizeof(float *)*a,msg);
  sprintf(msg,"%s:amjMalloc2DFloat:d[0]",message);
  d[0]=(float *)amjSafeMalloc(sizeof(float)*a*b,msg);
  
  for(i=1;i<a;i++) d[i]=d[i-1]+b;
  
  return d;
}

/****************************************************************************/

void amjFree2dFloat(float **d){

  free(d[0]);
  free(d);
}

/****************************************************************************/

float ***amjMalloc3dFloat(int a, int b, int c, char *message){
  
  float ***d;
  int i,j;

  sprintf(msg,"%s:amjMalloc3dFloat:d",message);
  d=(float ***)amjSafeMalloc(sizeof(float **)*a,msg);
  sprintf(msg,"%s:amjMalloc3dFloat:d[0]",message);
  d[0]=(float **)amjSafeMalloc(sizeof(float *)*a*b,msg);
  sprintf(msg,"%s:amjMalloc3dFloat:d[0][0]",message);
  d[0][0]=(float *)amjSafeMalloc(sizeof(float)*a*b*c,msg);
  
  for(i=0;i<a;i++){
    d[i]=d[0]+i*b;
    for(j=0;j<b;j++)
      d[i][j]=d[0][0]+(i*b+j)*c;
  }
  
  return d;
}

/****************************************************************************/

void amjFree3dFloat(float ***d){

  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

float ****amjMalloc4dFloat(int a, int b, int c, int d, char *message){
  
  float ****e;
  int i,j,k;

  sprintf(msg,"%s:amjMalloc4dFloat:e",message);
  e=(float ****)amjSafeMalloc(sizeof(float ***)*a,msg);
  sprintf(msg,"%s:amjMalloc4dFloat:e[0]",message);
  e[0]=(float ***)amjSafeMalloc(sizeof(float **)*a*b,msg);
  sprintf(msg,"%s:amjMalloc4dFloat:e[0][0]",message);
  e[0][0]=(float **)amjSafeMalloc(sizeof(float *)*a*b*c,msg);
  sprintf(msg,"%s:amjMalloc4dFloat:e[0][0][0]",message);
  e[0][0][0]=(float *)amjSafeMalloc(sizeof(float)*a*b*c*d,message);
  for(i=0;i<a;i++){
    e[i]=e[0]+i*b;
    for(j=0;j<b;j++){
      e[i][j]=e[0][0]+(i*b+j)*c;
      for(k=0;k<c;k++)
	e[i][j][k]=e[0][0][0]+((i*b+j)*c+k)*d;
    }
  }
  return e; 
}

/****************************************************************************/

void amjFree4dFloat(float ****e){
  
  free(e[0][0][0]);
  free(e[0][0]);
  free(e[0]);
  free(e);
}

/****************************************************************************/

double *amjMalloc1dDouble(int a, char *message){
  
  double *d;
  
  sprintf(msg,"%s:amjMalloc1dDouble:d",message);
  d=(double *)amjSafeMalloc(sizeof(double)*a,msg);

  return d;
}

/****************************************************************************/

void amjFree1dDouble(double *d){

  free(d);
}

/****************************************************************************/

double **amjMalloc2dDouble(int a, int b, char *message){

  double **d;
  int i;

  sprintf(msg,"%s:amjMalloc2dDouble:d",message);
  d=(double **)amjSafeMalloc(sizeof(double *)*a,msg);
  sprintf(msg,"%s:amjMalloc2dDouble:d[0]",message);
  d[0]=(double *)amjSafeMalloc(sizeof(double)*a*b,msg);

  for(i=1;i<a;i++) d[i]=d[i-1]+b;

  return d;
}

/****************************************************************************/

void amjFree2dDouble(double **d){
  
  free(d[0]);
  free(d);
}

/****************************************************************************/

double ***amjMalloc3dDouble(int a, int b, int c, char *message){

  double ***d;
  int i,j;

  sprintf(msg,"%s:amjMalloc3dDouble:d",message);
  d=(double ***)amjSafeMalloc(sizeof(double **)*a,msg);
  sprintf(msg,"%s:amjMalloc3dDouble:d[0]",message);
  d[0]=(double **)amjSafeMalloc(sizeof(double *)*a*b,msg);
  sprintf(msg,"%s:amjMalloc3dDouble:d[0][0]",message);
  d[0][0]=(double *)amjSafeMalloc(sizeof(double)*a*b*c,msg);
  
  for(i=0;i<a;i++){
    d[i]=d[0]+i*b;
    for(j=0;j<b;j++)
      d[i][j]=d[0][0]+(i*b+j)*c;
  }
  
  return d;
}

/****************************************************************************/

void amjFree3dDouble(double ***d){
  
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

double ****amjMalloc4dDouble(int a, int b, int c, int d, char *message){

  double ****e;
  int i,j,k;

  sprintf(msg,"%s:amjMalloc4dDouble:e",message);
  e=(double ****)amjSafeMalloc(sizeof(double ***)*a,msg);
  sprintf(msg,"%s:amjMalloc4dDouble:e[0]",message);
  e[0]=(double ***)amjSafeMalloc(sizeof(double **)*a*b,msg);
  sprintf(msg,"%s:amjMalloc4dDouble:e[0][0]",message);
  e[0][0]=(double **)amjSafeMalloc(sizeof(double *)*a*b*c,msg);
  sprintf(msg,"%s:amjMalloc4dDouble:e[0][0][0]",message);
  e[0][0][0]=(double *)amjSafeMalloc(sizeof(double)*a*b*c*d,message);
  for(i=0;i<a;i++){
    e[i]=e[0]+i*b;
    for(j=0;j<b;j++){
      e[i][j]=e[0][0]+(i*b+j)*c;
      for(k=0;k<c;k++)
	e[i][j][k]=e[0][0][0]+((i*b+j)*c+k)*d;
    }
  }
  return e;
}

/****************************************************************************/

void amjFree4dDouble(double ****d){

  free(d[0][0][0]);
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

double *****amjMalloc5dDouble(int a, int b, int c, int d, int e, char *message){

  double *****f;
  int i,j,k,l;

  sprintf(msg,"%s: amjMalloc5dDouble:f",message);
  f=(double *****)amjSafeMalloc(sizeof(double ****)*a,msg);
  sprintf(msg,"%s: amjMalloc5dDouble:f[0]",message);
  f[0]=(double ****)amjSafeMalloc(sizeof(double ***)*a*b,msg);
  sprintf(msg,"%s: amjMalloc5dDouble:f[0][0]",message);
  f[0][0]=(double ***)amjSafeMalloc(sizeof(double **)*a*b*c,msg);
  sprintf(msg,"%s: amjMalloc5dDouble:f[0][0][0]",message);
  f[0][0][0]=(double **)amjSafeMalloc(sizeof(double *)*a*b*c*d,msg);
  sprintf(msg,"%s: amjMalloc5dDouble:f[0][0][0][0]",message);
  f[0][0][0][0]=(double *)amjSafeMalloc(sizeof(double)*a*b*c*d*e,msg);
  for(i=0;i<a;i++){
    f[i]=f[0]+i*b;
    for(j=0;j<b;j++){
      f[i][j]=f[0][0]+(i*b+j)*c;
      for(k=0;k<c;k++){
	f[i][j][k]=f[0][0][0]+((i*b+j)*c+k)*d;
	for(l=0;l<d;l++)
	  f[i][j][k][l]=f[0][0][0][0]+(((i*b+j)*c+k)*d+l)*e;
      }
    }
  }

  return f;
}

/****************************************************************************/

void amjFree5dDouble(double *****d){
  free(d[0][0][0][0]);
  free(d[0][0][0]);
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/

double ******amjMalloc6dDouble(int a, int b, int c, int d, int e, int f, 
			       char *message){

  double ******g;
  int i,j,k,l,m;

  sprintf(msg,"%s: amjMalloc6dDouble:g",message);
  g=(double ******)amjSafeMalloc(sizeof(double *****)*a,msg);
  sprintf(msg,"%s: amjMalloc6dDouble:g[0]",message);
  g[0]=(double *****)amjSafeMalloc(sizeof(double ****)*a*b,msg);
  sprintf(msg,"%s: amjMalloc6dDouble:g[0][0]",message);
  g[0][0]=(double ****)amjSafeMalloc(sizeof(double ***)*a*b*c,msg);
  sprintf(msg,"%s: amjMalloc6dDouble:g[0][0][0]",message);
  g[0][0][0]=(double ***)amjSafeMalloc(sizeof(double **)*a*b*c*d,msg);
  sprintf(msg,"%s: amjMalloc6dDouble:g[0][0][0][0]",message);
  g[0][0][0][0]=(double **)amjSafeMalloc(sizeof(double *)*a*b*c*d*e,msg);
  sprintf(msg,"%s: amjMalloc6dDouble:g[0][0][0][0][0]",message);
  g[0][0][0][0][0]=(double *)amjSafeMalloc(sizeof(double)*a*b*c*d*e*f,msg);
  for(i=0;i<a;i++){
    g[i]=g[0]+i*b;
    for(j=0;j<b;j++){
      g[i][j]=g[0][0]+(i*b+j)*c;
      for(k=0;k<c;k++){
	g[i][j][k]=g[0][0][0]+((i*b+j)*c+k)*d;
	for(l=0;l<d;l++){
	  g[i][j][k][l]=g[0][0][0][0]+(((i*b+j)*c+k)*d+l)*e;
	  for(m=0;m<e;m++)
	    g[i][j][k][l][m]=g[0][0][0][0][0]+((((i*b+j)*c+k)*d+l)*e+m)*f;
	}
      }
    }
  }

  return g;
}

/****************************************************************************/

void amjFree6dDouble(double ******d){

  free(d[0][0][0][0][0]);
  free(d[0][0][0][0]);
  free(d[0][0][0]);
  free(d[0][0]);
  free(d[0]);
  free(d);
}

/****************************************************************************/


