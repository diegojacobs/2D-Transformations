#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <time.h>
#include "asm.h"
#include "image.h"


void main ()
{
    int i,j;

    if(!setVideoMode(v800x600x256, 800, 600)){
      printf("\r\nError couldn't initialize SVGA.\r\n");
      return;
    }

    for(i = 0; i < 800; i++)
        for(j = 0; j < 600; j++)
            putPixel(i, j , 15);

    do {

    }while(1);
    
    unsetVideoMode();
}