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
                //House Scaling
                case '2':
                    eraseHouse();
                    houseScale();                    
                    drawTree();
                    drawHouse();
                    break;
                //House Shear UP
                case '3':
                    eraseHouse();
                    houseShear(UP);
                    drawTree();
                    drawHouse();
                    break;
                //House Shear DOWN
                case '4':
                    eraseHouse();
                    houseShear(DOWN);
                    drawTree();
                    drawHouse();
                    break;
                //House Shear LEFT
                case '5':
                    eraseHouse();
                    houseShear(LEFT);
                    drawTree();
                    drawHouse();
                    break;
                //House Shear RIGHT
                case '6':
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
                case '7':
                    eraseTree();
                    treeRotation();
                    drawHouse();
                    drawTree();
                    break;
                //Tree Scaling
                case '8':
                    eraseTree();
                    treeScale();
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear UP
                case '9':
                    eraseTree();
                    treeShear(UP);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear DOWN
                case '0':
                    eraseTree();
                    treeShear(DOWN);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear LEFT
                case '-':
                    eraseTree();
                    treeShear(LEFT);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Shear RIGHT
                case '=':
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