int tree[3][2];
int trunk[4][2];

void initTree();
void drawTree();
void eraseTree();
void treeTranslation(int direction);

void initTree(){
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

    drawTree();
}

void drawTree(){
    scanline(tree, 3, 2);
    scanline(trunk, 4, 67);
}

void eraseTree(){
    scanline(tree, TRIANGLE, WHITE);
    scanline(trunk, SQUARE, WHITE);
}

void treeTranslation(int direction){
    int factorX, factorY;

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

    translation(TRIANGLE, factorX, factorY, tree);
    translation(SQUARE, factorX, factorY, trunk);
}