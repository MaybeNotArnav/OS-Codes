#include <stdio.h>
#include <stdlib.h>
void FCFS(int ref[], int n, int frame)
{
    int page[frame];
    int i, j, dist, flag = 0, out_ind = 0;
    int hit = 0, miss = 0;
    int order = 0;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < frame; j++)
        {
            if (ref[i] == page[j])
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            miss++;
            page[order] = ref[i];
            if (order == frame - 1)
                order = 0;
            else
                order++;
        }
        for (j = 0; j < frame; j++)
        {

            printf("%d ", page[j]);
        }
        printf("\n");
    }
    printf("The numberof hits are %d and miss are %d ", hit, miss);
}

void LRU(int ref[], int n, int frame)
{
    int page[frame];
    int i, j, k, dist, out_ind, flag = 0;
    int hit = 0, miss = 0, max;
    int order = 0;

    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < frame; j++)
        {
            if (ref[i] == page[j])
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            miss++;
            if (order < frame && miss <= 3)
            {
                page[order] = ref[i];
                order++;
            }
            else
            {
                max = 0;
                for (j = 0; j < frame; j++)
                {
                    out_ind = 0;
                    for (k = i; k >= 0; k--) // change loop to go behind
                    {
                        if (ref[k] == page[j])
                        {
                            out_ind = 1;
                            dist = i - k; // change order to not go neg
                            if (dist > max)
                            {
                                max = dist;
                                order = j;
                                break;
                            }
                            else
                                break;
                        }
                    }
                    if (out_ind == 0)
                    {
                        order = j;
                        break;
                    }
                }
                page[order] = ref[i];
            }
        }
        for (j = 0; j < frame; j++)
        {
            printf("%d ", page[j]);
        }
        printf("\n");
    }
    printf("The number of hits are %d and miss are %d ", hit, miss);
}
void optimal(int ref[], int n, int frame)
{
    int page[frame];
    int i, j, k, dist, out_ind, flag = 0;
    int hit = 0, miss = 0, max;
    int order = 0;

    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < frame; j++)
        {
            if (ref[i] == page[j])
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            miss++;
            if (order < frame && miss <= 3)
            {
                page[order] = ref[i];
                order++;
            }
            else
            {
                max = 0;
                for (j = 0; j < frame; j++)
                {
                    out_ind = 0;
                    for (k = i + 1; k < n; k++)
                    {
                        if (ref[k] == page[j])
                        {
                            out_ind = 1;
                            dist = k - i;
                            if (dist > max)
                            {
                                max = dist;
                                order = j;
                                break;
                            }
                            else
                                break;
                        }
                    }
                    if (out_ind == 0)
                    {
                        order = j;
                        break;
                    }
                }
                page[order] = ref[i];
            }
        }
        for (j = 0; j < frame; j++)
        {
            printf("%d ", page[j]);
        }
        printf("\n");
    }
    printf("The number of hits are %d and miss are %d ", hit, miss);
}

void main()
{
    int i, n, frame;
    int ref[100];
    printf("Number of page \n");
    scanf("%d", &n);
    printf("Number of frame \n");
    scanf("%d", &frame);
    printf("page red \n");
    for (i = 0; i < n; i++)
    {

        scanf("%d", &ref[i]);
    }
    LRU(ref, n, frame);
}