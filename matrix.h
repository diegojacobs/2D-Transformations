
void translation(int n, int factorX, int factorY, int *mat[20][2]);

void translation(int n, int factorX, int factorY, int *mat[20][2]){
    int i;
    for(i = 0; i < n; i++) {
        mat[i][0] = mat[i][0] + factorX;
        mat[i][1] = mat[i][1] + factorY;
    }
}