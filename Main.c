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
#include "image.h"
#include "ccp.h"

void main ()
{
    char c;
    BITMAP bmp;

    if(!setVideoMode(v800x600x256, 800, 600)){
      printf("\r\nError couldn't initialize SVGA.\r\n");
      return;
    }

    loadImage(0, 0, "2D/Images/back.bmp", &bmp);
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
                //House Scale Big x
                case '2':
                    eraseHouse();
                    houseScale(BIG, SCALEX);                    
                    drawTree();
                    drawHouse();
                    break;
                //House Scale Small x
                case '3':
                    eraseHouse();
                    houseScale(SMALL, SCALEX);                    
                    drawTree();
                    drawHouse();
                    break;
                //House Scale Big y
                case '4':
                    eraseHouse();
                    houseScale(BIG, SCALEY);                    
                    drawTree();
                    drawHouse();
                    break;
                //House Scale Small y
                case '5':
                    eraseHouse();
                    houseScale(SMALL, SCALEY);                    
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
                //Tree Scale Big x
                case '9':
                    eraseTree();
                    treeScale(BIG, SCALEX);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Scale Small x
                case '0':
                    eraseTree();
                    treeScale(SMALL, SCALEX);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Scale Big y
                case '-':
                    eraseTree();
                    treeScale(BIG, SCALEY);
                    drawHouse();
                    drawTree();
                    break;
                //Tree Scale Small y
                case '=':
                    eraseTree();
                    treeScale(SMALL, SCALEY);
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

                //Help
                case 'h':
                    copyFile(0, 0, 800, 600);
                    loadImage(0, 0, "2D/Images/help.bmp", &bmp);
                    c = ' ';
                    while(c != 'h'){
                        if (kbhit()) {
                            c = getch();
                        }
                    }
                    pasteFile(0, 0);
                    break;
            }
        }
    }

    unsetVideoMode();
}