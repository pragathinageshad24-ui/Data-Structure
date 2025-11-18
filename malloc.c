#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;

    arr = (int *)malloc(10 * sizeof(int));
    if (arr != NULL)
    {
        printf("Memory is created using malloc function\n");
    }
    else
    {
        printf("Memory is not created");
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        printf("%d %u\n", arr[i],&arr[i]);
    }

    free(arr);

    return 0;
}
