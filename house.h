int house[5][2];
int roof[4][2];
int window[5][2];
int door[5][2];
coord houseCenter;
double factorX, factorY;

void initHouse();
void drawHouse();
void eraseHouse();
void houseTranslation(int direction);
void houseRotation();
void houseScale();
void houseShear();

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

    house[4][0] = 100;
    house[4][1] = 400;

    //Roof
    roof[0][0] = 100;
    roof[0][1] = 200;

    roof[1][0] = 200;
    roof[1][1] = 100;

    roof[2][0] = 300;
    roof[2][1] = 200;

    roof[3][0] = 100;
    roof[3][1] = 200;

    //Door
    door[0][0] = 135;
    door[0][1] = 400;

    door[1][0] = 135;
    door[1][1] = 300;

    door[2][0] = 195;
    door[2][1] = 300;

    door[3][0] = 195;
    door[3][1] = 400;

    door[4][0] = 135;
    door[4][1] = 400;

    //Window
    window[0][0] = 225;
    window[0][1] = 275;

    window[1][0] = 225;
    window[1][1] = 225;

    window[2][0] = 275;
    window[2][1] = 225;

    window[3][0] = 275;
    window[3][1] = 275;

    window[4][0] = 225;
    window[4][1] = 275;

    houseCenter.x = 200;
    houseCenter.y = 250;

    drawHouse();
}

void drawHouse(){
    scanline(house, SQUARE, BLUE);
    scanline(roof, TRIANGLE, 55);
    scanline(door, SQUARE, 75);
    scanline(window, SQUARE, SKYBLUE);
}

void eraseHouse(){
    scanline(house, SQUARE, WHITE);
    scanline(roof, TRIANGLE, WHITE);
    scanline(door, SQUARE, WHITE);
    scanline(window, SQUARE, WHITE);
}

void houseTranslation(int direction){
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
        point.x = roof[i][0];
        point.y = roof[i][1];
        point.z = 1;

        point = translation(factorX, factorY, point);

        roof[i][0] = point.x;
        roof[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = house[i][0];
        point.y = house[i][1];
        point.z = 1;

        point = translation(factorX, factorY, point);

        house[i][0] = point.x;
        house[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = door[i][0];
        point.y = door[i][1];
        point.z = 1;

        point = translation(factorX, factorY, point);

        door[i][0] = point.x;
        door[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = window[i][0];
        point.y = window[i][1];
        point.z = 1;

        point = translation(factorX, factorY, point);

        window[i][0] = point.x;
        window[i][1] = point.y;
    }

    houseCenter = translation(factorX, factorY, houseCenter);
}

void houseRotation(){
    int i;
    coord point;

    for(i = 0; i < TRIANGLE; i++){
        point.x = roof[i][0];
        point.y = roof[i][1];
        point.z = 1;

        point = rotation(point, houseCenter, 30);

        roof[i][0] = point.x;
        roof[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = house[i][0];
        point.y = house[i][1];
        point.z = 1;

        point = rotation(point, houseCenter, 30);

        house[i][0] = point.x;
        house[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = door[i][0];
        point.y = door[i][1];
        point.z = 1;

        point = rotation(point, houseCenter, 30);

        door[i][0] = point.x;
        door[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = window[i][0];
        point.y = window[i][1];
        point.z = 1;

        point = rotation(point, houseCenter, 30);

        window[i][0] = point.x;
        window[i][1] = point.y;
    }
}

void houseScale(int type, int axis){
    int i;
    coord point;
    double factorX = 1.0;
    double factorY = 1.0;
    
    if(type == BIG && axis == SCALEX)
        factorX = 1.1;
    
    if(type == SMALL && axis == SCALEX)
        factorX = 0.9;

    if(type == BIG && axis == SCALEY)
        factorX = 1.1;

    if(type == SMALL && axis == SCALEY)
        factorX = 0.9;

    for(i = 0; i < TRIANGLE; i++){
        point.x = roof[i][0];
        point.y = roof[i][1];
        point.z = 1;

        point = scale(point, houseCenter, factorX, factorY);

        roof[i][0] = point.x;
        roof[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = house[i][0];
        point.y = house[i][1];
        point.z = 1;

        point = scale(point, houseCenter, factorX, factorY);

        house[i][0] = point.x;
        house[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = door[i][0];
        point.y = door[i][1];
        point.z = 1;

        point = scale(point, houseCenter, factorX, factorY);

        door[i][0] = point.x;
        door[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = window[i][0];
        point.y = window[i][1];
        point.z = 1;

        point = scale(point, houseCenter, factorX, factorY);

        window[i][0] = point.x;
        window[i][1] = point.y;
    }
}

void houseShear(int direction){
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
        point.x = roof[i][0];
        point.y = roof[i][1];
        point.z = 1;

        point = shear(factorX, factorY, point, houseCenter);

        roof[i][0] = point.x;
        roof[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = house[i][0];
        point.y = house[i][1];
        point.z = 1;

        point = shear(factorX, factorY, point, houseCenter);

        house[i][0] = point.x;
        house[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = door[i][0];
        point.y = door[i][1];
        point.z = 1;

        point = shear(factorX, factorY, point, houseCenter);

        door[i][0] = point.x;
        door[i][1] = point.y;
    }

    for(i = 0; i < SQUARE; i++){
        point.x = window[i][0];
        point.y = window[i][1];
        point.z = 1;

        point = shear(factorX, factorY, point, houseCenter);

        window[i][0] = point.x;
        window[i][1] = point.y;
    }
}