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
                //Tree Shear Horizontal
                case '9':
                    break;
                //Tree Shear Vertical
                case '0':
                    break;
            };
        }
    }

    unsetVideoMode();
}