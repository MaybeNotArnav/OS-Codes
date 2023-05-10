#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void FCFS(int req[], int n, int start)
{
    int i;
    int total = 0;
    int prev = start;
    printf("%d \n", abs(start - req[0]));
    for (i = 0; i < n; i++)
    {
        total = total + abs(prev - req[i]);
        prev = req[i];
    }
    printf("The total seek time is %d", total);
}

void SSTF(int req[], int n, int start)
{
    int i, j;
    int finish[n];
    int total = 0;
    int prev = start;
    int min = 9999;
    int travel;

    for (i = 0; i < n; i++)
        finish[i] = -1;

    for (j = 0; j < n; j++)
    {
        min = 9999;
        for (i = 0; i < n; i++)
        {
            if (finish[i] == -1 && abs(prev - req[i]) < min)
            {
                min = abs(prev - req[i]);
                travel = i;
            }
        }
        printf("%d \n", min);
        finish[travel] = 0;
        total = total + min;
        prev = req[travel];
    }
    printf("The total seek time is %d", total);
}

void SCAN(int req[], int n, int start, int max, int direction)
{
    int i, j, temp;
    int total = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (req[j] > req[j + 1])
            {
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", req[i]);

    if (direction == 1)
    {
        printf("%d ", req[1]);
        total = total + (max - start) + (max - req[0]);
    }
    else if (direction == -1)
    {
        total = total + start + req[n - 1];
    }
    printf("The total seek time is %d", total);
}

void main()
{
    int req[100];
    int i, n, start;
    printf("Enter the number of requests \n");
    scanf("%d", &n);
    printf("Enter the requests \n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter the starting position \n");
    scanf("%d", &start);
    SCAN(req, n, start, 199, -1);
}