int tree[4][2];
int trunk[5][2];
coord treeCenter;
coord trunkCenter;

void initTree();
void drawTree();
void eraseTree();
void treeTranslation(int direction);
void treeRotation();
void treeScale();
void treeShear(int direction);

void initTree(){
    //Tree
    tree[0][0] = 500;
    tree[0][1] = 350;

    tree[1][0] = 600;
    tree[1][1] = 150;

    tree[2][0] = 700;
    tree[2][1] = 350;

    tree[3][0] = 500;
    tree[3][1] = 350;

    //Trunk
    trunk[0][0] = 575;
    trunk[0][1] = 400;

    trunk[1][0] = 575;
    trunk[1][1] = 350;

    trunk[2][0] = 625;
    trunk[2][1] = 350;

    trunk[3][0] = 625;
    trunk[3][1] = 400;

    trunk[4][0] = 575;
    trunk[4][1] = 400;

    treeCenter.x = 600;
    treeCenter.y = 275;

    drawTree();
}
void showPalette(){
    int i, j, k, l, color;
    int startX = 0;
    int startY = 0;
    int size = 16;
    int columns = 12;
    color = 0;

    for(i = startX; color < 256; i = i + size, color++){
        if(color % columns == 0)
            i = startX;
        
        j = startY + ((color - 0) / columns) * size;

        for(k = 0;k < size; j++, k++)
            for (l = 0; l < size; l++)
                putPixel(i + l, j, color); 
    }
}

void drawTree(){
    showPalette();
    scanline(tree,TRIANGLE, GREEN);
    scanline(trunk, SQUARE, BROWN);
}

void eraseTree(){
    scanline(tree, TRIANGLE, WHITE);
    scanline(trunk, SQUARE, WHITE);
}

void treeTranslation(int direction){
    double factorX, factorY;
    int i;
    coord point;
    
    if(direction == UP){
        factorX = 0;
        factorY = -10;
    }

    if(direction == DOWN){
        factorX = 0;
        factorY = 10;
    }

    if(direction == RIGHT){
        factorX = 10;
        factorY = 0;
    }

    if(direction == LEFT){
        factorX = -10;
        factorY = 0;
    }

    for(i = 0; i < TRIANGLE; i++){
        point.x = tree[i][0];
        point.y = tree[i][1];
        point.z = 1;

        point = translation(factorX, factorY, point);

        tree[i][0] = point.x;
        tree[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = trunk[i][0];
        point.y = trunk[i][1];
        point.z = 1;

        point = translation(factorX, factorY, point);

        trunk[i][0] = point.x;
        trunk[i][1] = point.y;
    }

    treeCenter = translation(factorX, factorY, treeCenter);
}

void treeRotation(){
    int i;
    coord point;

    for(i = 0; i < TRIANGLE; i++){
        point.x = tree[i][0];
        point.y = tree[i][1];
        point.z = 1;

        point = rotation(point, treeCenter, 30);

        tree[i][0] = point.x;
        tree[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = trunk[i][0];
        point.y = trunk[i][1];
        point.z = 1;

        point = rotation(point, treeCenter, 30);

        trunk[i][0] = point.x;
        trunk[i][1] = point.y;
    }
}

void treeScale(int type, int axis){
    int i;
    coord point;
    double factorX = 1.0;
    double factorY = 1.0;
    
    if(type == BIG && axis == SCALEX)
        factorX = 1.1;
    
    if(type == SMALL && axis == SCALEX)
        factorX = 0.9;

    if(type == BIG && axis == SCALEY)
        factorY = 1.1;

    if(type == SMALL && axis == SCALEY)
        factorY = 0.9;

    for(i = 0; i < TRIANGLE; i++){
        point.x = tree[i][0];
        point.y = tree[i][1];
        point.z = 1;

        point = scale(point, treeCenter, factorX, factorY);

        tree[i][0] = point.x;
        tree[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = trunk[i][0];
        point.y = trunk[i][1];
        point.z = 1;

        point = scale(point, treeCenter, factorX, factorY);

        trunk[i][0] = point.x;
        trunk[i][1] = point.y;
    }
}

void treeShear(int direction){
    int i;
    coord point;

    if(direction == UP){
        factorX = 0;
        factorY = 0.1;
    }

    if(direction == DOWN){
        factorX = 0;
        factorY = -0.1;
    }

    if(direction == RIGHT){
        factorX = 0.1;
        factorY = 0;
    }

    if(direction == LEFT){
        factorX = -0.1;
        factorY = 0;
    }

    for(i = 0; i < TRIANGLE; i++){
        point.x = tree[i][0];
        point.y = tree[i][1];
        point.z = 1;

        point = shear(factorX, factorY, point, treeCenter);

        tree[i][0] = point.x;
        tree[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = trunk[i][0];
        point.y = trunk[i][1];
        point.z = 1;

        point = shear(factorX, factorY, point, treeCenter);

        trunk[i][0] = point.x;
        trunk[i][1] = point.y;
    }
}