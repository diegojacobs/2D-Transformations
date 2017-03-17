
void translation(int n, double factorX, double factorY, double *mat[20][2]);

void translation(int n, double factorX, double factorY, double *mat[20][2]){
    int i;
    
    for(i = 0; i < n; i++) {
        mat[i][0] = mat[i][0] + factorX;
        mat[i][1] = mat[i][1] + factorY;
    }
}

void mul(int n, float b[][3], float c[][3], float a[][3]){
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
            a[i][j] = 0;

    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++) 
                a[i][j] = a[i][j] + (c[i][k] * b[k][j]); 
}