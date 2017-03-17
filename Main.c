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
#include "tree.h"

void main ()
{
    char c;

    if(!setVideoMode(v800x600x256, 800, 600)){
      printf("\r\nError couldn't initialize SVGA.\r\n");
      return;
    }

    drawFilledRectangle(0, 0, 800, 600, 15);
    initHouse();
    initTree();
 
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

                //Tree Left
                case 'k':
                    eraseTree();
                    treeTranslation(LEFT);
                    drawTree();
                    break;
                //Tree Up
                case 'o':
                    eraseTree();
                    treeTranslation(UP);
                    drawTree();
                    break;
                //Tree Down
                case 'l':
                    eraseTree();
                    treeTranslation(DOWN);
                    drawTree();
                    break;
                //Tree Right
                case ';':
                    eraseTree();
                    treeTranslation(RIGHT);
                    drawTree();
                    break;  
            };
        }
    }

    unsetVideoMode();
}