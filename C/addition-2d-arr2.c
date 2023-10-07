#include <stdio.h>

int main()
{
    int arr1[3][3], arr2[3][3], arr3[3][3];

    printf("Enter array 1 = ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("X[%d][%d]", i, j);
            scanf("%d ", &arr1[i][j]);
        }
    }
    printf("\n");

    printf("Enter array 2 = ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Y[%d][%d]", i, j);
            scanf("%d ", &arr2[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("The array output = \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d", arr1[i][j]);
        }
        printf("\t");
        for (int j = 0; j < 3; j++)
        {
            printf("%4d", arr2[i][j]);
        }
        printf("\t");
        for (int j = 0; j < 3; j++)
        {
            printf("%4d", arr3[i][j]);
        }

        printf("\n");
    }

    return 0;
}