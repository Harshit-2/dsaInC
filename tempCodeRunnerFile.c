#include <stdio.h>

void findFreq(int arr[], int n)
{
    int m[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (int i = 0; i < 1000; i++)
    {
        if (m[i] > 0)
        {
            printf("Element %d occurs %d times.\n", i, m[i]);
        }
    }
}

int main()
{
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    findFreq(arr, 10);

    return 0;
}