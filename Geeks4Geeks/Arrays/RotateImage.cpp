// http://www.geeksforgeeks.org/turn-an-image-by-90-degree

#include <stdio.h>
#include <stdlib.h>

void displayMatrix(unsigned int const *p, unsigned int row, unsigned int col);
void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col);

int main()
{
    // declarations
    unsigned int image[][4] = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9,10,11,12}};
    unsigned int *pSource;
    unsigned int *pDestination;
    unsigned int m, n;

    // setting initial values and memory allocation
    m = 3, n = 4, pSource = (unsigned int *)image;
    pDestination = (unsigned int *)malloc(sizeof(int)*m*n);

    // process each buffer
    displayMatrix(pSource, m, n);

    //rotate(pSource, pDestination, m, n);

    //displayMatrix(pDestination, n, m);

    //free(pDestination);/

    getchar();
    return 0;
}
void displayMatrix(unsigned int const *p, unsigned int row, unsigned int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ",*(p + i*col + j));
        }
        printf("\n");
    }

}
void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col){

    for(int i = 0; i< row; i++){
        for(int j = 0; j< col ; j++){
            *(pD + )  =  *(pS + i*col + j)
        }
    }


}
