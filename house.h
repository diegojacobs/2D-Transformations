int house[4][2];
int roof[3][2];
int window[4][2];
int door[4][2];

void initHouse();
void drawHouse();
void eraseHouse();
void houseTranslation(int direction);

void initHouse(){

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

    //Door
    door[0][0] = 135;
    door[0][1] = 400;

    door[1][0] = 135;
    door[1][1] = 300;

    door[2][0] = 195;
    door[2][1] = 300;

    door[3][0] = 195;
    door[3][1] = 400;

    //Window
    window[0][0] = 225;
    window[0][1] = 275;

    window[1][0] = 225;
    window[1][1] = 225;

    window[2][0] = 275;
    window[2][1] = 225;

    window[3][0] = 275;
    window[3][1] = 275;

    drawHouse();
}

void drawHouse(){
    scanline(house, SQUARE, 32);
    scanline(roof, TRIANGLE, 4);
    scanline(door, SQUARE, 4);
    scanline(window, SQUARE, 3);
}

void eraseHouse(){
    scanline(house, SQUARE, WHITE);
    scanline(roof, TRIANGLE, WHITE);
    scanline(door, SQUARE, WHITE);
    scanline(window, SQUARE, WHITE);
}

void houseTranslation(int direction){
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

    translation(SQUARE, factorX, factorY, house);
    translation(TRIANGLE, factorX, factorY, roof);
    translation(SQUARE, factorX, factorY, door);
    translation(SQUARE, factorX, factorY, window);
}