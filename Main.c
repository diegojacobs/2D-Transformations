#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <time.h>
#include "asm.h"
#include "image.h"
#include "graph.h"


void main ()
{
    int i,j;
    int house[20][2];
    int roof[20][2];
    int window[20][2];
    int door[20][2];
    int tree[20][2];
    int trunk[20][2];

    if(!setVideoMode(v800x600x256, 800, 600)){
      printf("\r\nError couldn't initialize SVGA.\r\n");
      return;
    }
    
    //House
    house[0][0] = 100;
    house[0][1] = 400;

    house[1][0] = 100;
    house[1][1] = 200;

    house[2][0] = 300;
    house[2][1] = 200;

    house[3][0] = 300;
    house[3][1] = 400;

    //Roof
    roof[0][0] = 100;
    roof[0][1] = 200;

    roof[1][0] = 200;
    roof[1][1] = 100;

    roof[2][0] = 300;
    roof[2][1] = 200;

    //Tree
    tree[0][0] = 500;
    tree[0][1] = 350;

    tree[1][0] = 600;
    tree[1][1] = 150;

    tree[2][0] = 700;
    tree[2][1] = 350;

    //Trunk
    trunk[0][0] = 575;
    trunk[0][1] = 400;

    trunk[1][0] = 575;
    trunk[1][1] = 350;

    trunk[2][0] = 625;
    trunk[2][1] = 350;

    trunk[3][0] = 625;
    trunk[3][1] = 400;

    drawFilledRectangle(0, 0, 800, 600, 15, 15, 1, 0, 0);
    scanline(house, 4, 3, 3, 1, 0, 0);
    scanline(roof, 3, 4, 4, 1, 0, 0);
    scanline(tree, 3, 2, 2, 1, 0, 0);
    scanline(trunk, 4, 67, 67, 1, 0, 0);

    while(1){

    }

    unsetVideoMode();
}