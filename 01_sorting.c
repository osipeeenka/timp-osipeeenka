#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int first, int last, FILE* fp, int length)
{
    int tmp, i;
    int left, right, middle;
    if (first < last)
    {
        left = first;
        right = last;
        middle = arr[(left + right) / 2];

        do {
            while (arr[left] < middle) { left++;}
            while (arr[right] > middle) { right--;}

            if (left <= right)
            {
                tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;


                for (i = 0; i < length; i++)
                {
                    if (i != 0)
                        fprintf(fp, " ");
                    fprintf(fp, "%d", arr[i]);
                }
                fprintf(fp, "\n");

            }
        } while (left <= right);

        quickSort(arr, first, right, fp, length);
        quickSort(arr, left, last, fp, length);
    }
}


void siftDown(int *arr, int root, int bottom, int length, FILE* fp)
{
    int j, tmp;
    int maxChild;
    int done = 0;

    while ((root * 2 <= bottom) && (!done))
    {

        if (root * 2 == bottom)
        {
            maxChild = root * 2;
        }
        else
        {
            if (arr[root * 2] > arr[root * 2 + 1])
                maxChild = root * 2;
            else
                maxChild = root * 2 + 1;

        }
        if (arr[root] < arr[maxChild])
        {
            tmp = arr[root];
            arr[root] = arr[maxChild];
            arr[maxChild] = tmp;
            root = maxChild;

            for (j = 0; j < length; j++)
            {
                if (j != 0)
                    fprintf(fp, " ");
                fprintf(fp, "%d", arr[j]);
            }
            fprintf(fp, "\n");

        }
        else
            done = 1;

    }
}

void heapSort(int *arr, int length, FILE* fp)
{
    int tmp, j;
    for (int i = (length / 2); i >= 0; i--)
    {
        siftDown(arr, i, length - 1, length, fp);

    }

    for (int i = length - 1; i >= 1; i--)
    {
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        for (j = 0; j < length; j++)
        {
            if (j != 0)
                fprintf(fp, " ");
            fprintf(fp, "%d", arr[j]);
        }
        fprintf(fp, "\n");

        siftDown(arr, 0, i - 1, length, fp);
    }
}

int main()
{
    int length, i;
    scanf("%d", &length);
    int *a1 = (int*)malloc(sizeof(int) * length);
    int *a2 = (int*)malloc(sizeof(int) * length);
    for (i = 0; i < length; i++)
    {
        scanf("%d", &a1[i]);
        a2[i] = a1[i];
    }

    char qlog [] = "quicksort.log";
    FILE *fp = fopen(qlog, "w+");
    for (i = 0; i < length; i++)
    {
        if (i != 0)
            fprintf(fp, " ");
        fprintf(fp, "%d", a1[i]);
    }
    fprintf(fp, "\n");

    quickSort(a1, 0, length-1, fp, length);
    fclose(fp);

    for(int i = 0; i < length; i++)
    {
        printf("%d", a1[i]);
        if(i<length-1)
            printf(" ");
    }

    char hlog [] = "heapsort.log";
    fp = fopen(hlog, "w+");
    for (i = 0; i < length; i++)
    {
        if (i != 0)
            fprintf(fp, " ");
        fprintf(fp, "%d", a2[i]);
    }
    fprintf(fp, "\n");

    heapSort(a2, length, fp);
    fclose(fp);
    free(a1);
    free(a2);
    printf("\n");
    return 0;
}
