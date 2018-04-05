/*给定一个矩阵，求子矩阵*/
#include <stdio.h>
const int N=7;
int matA[N][N], matB[N][N];
int main()
{
    puts("Please input a matrix:");
    for(int i=1; i<N; i++)
        for(int j=1; j<N; j++) {
            scanf("%d", matA[i]+j);
            matB[i][j]=matB[i-1][j]+matA[i][j];
        }
    puts("The Preprocessed matrix is:");
    for(int i=1; i<N; i++)
        for(int j=1; j<N; j++)
            printf("%d%c", matB[i][j], j==N-1?'\n':' ');

    int a, b, p, q, res;
    while(puts("Please input a, b and p, q:"),
          ~scanf("%d%d%d%d", &a, &b, &p, &q) )
    {
        res=0;
        puts("Sum from A_ab to A_pq is:");
        for(int j=b; j<=q; j++)
            res+=matB[p][j]-matB[a-1][j];
        printf("%d\n\n", res);
    }
    return 0;
}
