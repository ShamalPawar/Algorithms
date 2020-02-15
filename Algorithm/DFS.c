#include<stdio.h>
#include<stdlib.h>
#include "DFS.h"
#define ZERO_ASCII 48
int count;
/**
 * Function name : ArrayInitialization
 * Input parameters : pointer to array and number of elements in array
*/
void ArrayInitialization(int *arr,int n)
{
    int j;
    for (j = 0; j < n; j++)
    {
        arr[j] = 0;
    }
}
/**
 * Function name : topologicalSort
 * Paramters : Pointer to 2D array and number of nodes
*/
void DFS(int v, int n, int **matrix)
{
   
    int i,j;
    int *visited;
    visited=(int*)malloc(n*sizeof(int));
    ArrayInitialization(visited, n);
    visited[v] = 1;
    count++;
    printf("%d ",v);
    for (i = 0; i < n; i++)
        {
            if(matrix[v][i] == 1 && visited[i] == 0)
            {
                DFS(i,n,matrix);
            }
        }
    free(visited);
}
int main()
{
    int **matrix;
    int n,T,i,j,k,startnode;
    FILE *pfileptr;
    pfileptr = fopen("DFSTestCases.txt", "r");
    if (NULL == pfileptr)
        printf("Error: File open\n");
    else
    {
        T = fgetc(pfileptr) - ZERO_ASCII;
        printf("Number of test case are T = %d", T);
        fgetc(pfileptr);
        for (i = 0; i < T; i++)
        {
            n = fgetc(pfileptr) - ZERO_ASCII;
            printf("\nNumber of nodes = %d\n", n);

            fgetc(pfileptr);
            startnode = fgetc(pfileptr) - ZERO_ASCII;
            printf("\nstart node = %d\n", startnode);
            //Dynamic memory allocation
            matrix = (int **)malloc(n * sizeof(int *));
            for (j = 0; j < n; j++)
                matrix[j] = (int *)malloc(n * sizeof(int));
            fgetc(pfileptr);
            printf("matrix value\n");
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    matrix[j][k] = fgetc(pfileptr) - ZERO_ASCII;
                    printf("%d ", matrix[j][k]);
                }
                printf("\n");
                fgetc(pfileptr);
               // printf("hii = %d\n",fgetc(pfileptr) - ZERO_ASCII);
            }
            
            printf("Node visited list is :\n");
            DFS(startnode,n,matrix);
            if(count < n)
            {
                printf("\nGraph is not connected");
            }
            printf("\n-----------------------------------------\n");
            //free dynamically allocated memory
            for (j = 0; j < n; j++)
            {
                free(matrix[j]);
            }
            free(matrix);
            

        }
    }
    return 0;
}