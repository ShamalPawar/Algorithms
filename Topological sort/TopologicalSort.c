/**
 * @author : shamal Pawar
 * @details : Topological sort function. Graph is stored in 2D array
 * @Note : Test case file name is TopologicalSearchTestCase.txt. If want to add any
 * test case change in this file. First number in file is indicating number of test cases. Then number of nodes and matrix
 * related to graph for this test case.
 * @date : 10/02/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include "TopologicalSort.h"
#define ZERO_ASCII 48
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
void topologicalSort(int **matrix,int n)
{
    int j,k,l;
    int *visited, *indeg;
    visited=(int*)malloc(n*sizeof(int));
    indeg=(int*)malloc(n*sizeof(int));
    
    ArrayInitialization(indeg,n);
    ArrayInitialization(visited, n);
     for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {
                    indeg[j] = indeg[j] + matrix[k][j];
                }
            }
            printf("Topological sort is = \n");
            for (l = 0; l < n; l++)
            {
                for (j = 0; j < n; j++)
                {
                    if (indeg[j] == 0 && visited[j] == 0)
                    {
                        printf("%d ", j);
                        visited[j] = 1;
                        for (k = 0; k < n; k++)
                        {
                            if (matrix[j][k] == 1)
                            {
                                indeg[k]--;
                            }
                        }
                    }
                }
            }
}


int main()
{
    int T, n, i,j,k;
    int **matrix;

    FILE *pfileptr;
    pfileptr = fopen("TopologicalSearchTestCase.txt", "r");
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
            }
            topologicalSort(matrix,n);
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
