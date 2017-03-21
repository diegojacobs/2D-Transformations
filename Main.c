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
                    drawTree();
                    drawHouse();
                    break;
                //House Up
                case 'w':
                    eraseHouse();
                    houseTranslation(UP);
                    drawTree();
                    drawHouse();
                    break;            
                //House Down
                case 's':
                    eraseHouse();
                    houseTranslation(DOWN);
                    drawTree();
                    drawHouse();
                    break;
                //House Right
                case 'd':
                    eraseHouse();
                    houseTranslation(RIGHT);
                    drawTree();
                    drawHouse();
                    break;

                //House Rotation
                case '1':
                    eraseHouse();
                    houseRotation();    
                    drawTree();
                    drawHouse();
                    break;
                //House Scale Big
                case '2':
                    eraseHouse();
                    houseScale(BIG);                    
                    drawTree();
                    drawHouse();
                    break;
                //House Scale Small
                case '3':
                    eraseHouse();
                    houseScale(SMALL);                    
                    drawTree();
                    drawHouse();
                    break;
                //House Shear UP
                case 'z':
                    eraseHouse();
                    houseShear(UP);
                    drawTree();
                    drawHouse();
                    break;
                //House Shear DOWN
                case 'x':
                    eraseHouse();
                    houseShear(DOWN);
                    drawTree();
                    drawHouse();
                    break;
                //House Shear LEFT
                case 'c':
                    eraseHouse();
                    houseShear(LEFT);
                    drawTree();
                    drawHouse();
                    break;
                //House Shear RIGHT
                case 'v':
                    eraseHouse();
                    houseShear(RIGHT);
                    drawTree();
                    drawHouse();
                    break;

                //Tree Left
                case 'k':
                    eraseTree();
                    treeTranslation(LEFT);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Up
                case 'o':
                    eraseTree();
                    treeTranslation(UP);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Down
                case 'l':
                    eraseTree();
                    treeTranslation(DOWN);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Right
                case ';':
                    eraseTree();
                    treeTranslation(RIGHT);
                    drawHouse();
                    drawTree();
                    break;  

                //Tree Rotation
                case '8':
                    eraseTree();
                    treeRotation();
                    drawHouse();
                    drawTree();
                    break;
                //Tree Scale Big
                case '9':
                    eraseTree();
                    treeScale(BIG);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Scale Small
                case '0':
                    eraseTree();
                    treeScale(SMALL);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear UP
                case 'm':
                    eraseTree();
                    treeShear(UP);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear DOWN
                case ',':
                    eraseTree();
                    treeShear(DOWN);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear LEFT
                case '.':
                    eraseTree();
                    treeShear(LEFT);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear RIGHT
                case '/':
                    eraseTree();
                    treeShear(RIGHT);
                    drawHouse();
                    drawTree();
                    break;
            };
        }
    }

    unsetVideoMode();
}