#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <math.h>
#include <time.h>
#include "enums.h"
#include "asm.h"
#include "matrix.h"
#include "graph.h"
#include "house.h"

void main ()
{
    int i,j;
    int tree[20][2];
    int trunk[20][2];
    char c;

    if(!setVideoMode(v800x600x256, 800, 600)){
      printf("\r\nError couldn't initialize SVGA.\r\n");
      return;
    }

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

    drawFilledRectangle(0, 0, 800, 600, 15);
    initHouse();
    scanline(tree, 3, 2);
    scanline(trunk, 4, 67);
 
    c = 0;
    while(c != 'y'){
        if (kbhit()) {
            c = getch();
            switch(c){
                //House Left
                case 'a':
                    eraseHouse();
                    houseTranslation(LEFT);
                    drawHouse();
                    break;
                //House Up
                case 'w':
                    eraseHouse();
                    houseTranslation(UP);
                    drawHouse();
                    break;            
                //House Down
                case 's':
                    eraseHouse();
                    houseTranslation(DOWN);
                    drawHouse();
                    break;
                //House Right
                case 'd':
                    eraseHouse();
                    houseTranslation(RIGHT);
                    drawHouse();
                    break;

                //House Rotation
                case '1':
                    break;
                //House Scaling
                case '2':
                    break;
                //House Shear Horizontal
                case '3':
                    break;
                //House Shear Vertical
                case '4':
                    break;

                //Tree Right
                case 'k':
                    break;
                //Tree Up
                case 'o':
                    break;
                //Tree Down
                case 'l':
                    break;
                //Tree Left
                case ';':
                    break;  
            };
        }
    }

    unsetVideoMode();
}