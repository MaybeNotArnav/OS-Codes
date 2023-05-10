#include <conio.h>
#include <stdio.h>

void ResourceAlloc(int pro, int reso)
{
    int alloc[pro][reso], max[pro][reso], avail[reso] need[pro][reso];
    int finish[pro];
    int seq[pro];
    int safe = 0;
    int i, j, k, l, flag = 0;
    printf("Enter the allocation matrix \n");
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < reso; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix \n");
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < reso; j++)
        {
            scanf("%d", &max[i][j]);
        }
        finish[i] = 0;
    }
    printf("Enter the available matrix \n");
    for (i = 0; i < reso; i++)
        scanf("%d", &avail[i]);
    printf("The need matrix will be \n");
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < reso; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for (l = 0; l < 5; l++)
    {
        for (i = 0; i < pro; i++)
        {
            flag = 0;
            for (j = 0; j < reso; j++)
            {
                if (finish[i] == 0)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = -1;
                    }
                }
            }
            if (flag == 0 && finish[i] == 0)
            {
                finish[i] = 1;
                seq[safe] = i;
                safe++;
                for (k = 0; k < reso; k++)
                {
                    avail[k] = avail[k] + alloc[i][k];
                }
            }
        }
    }
    if (safe == pro)
    {
        printf("The safe sequence is \n");
        for (i = 0; i < pro; i++)
        {
            printf("%d ", seq[i]);
        }
    }
    else
    {
        printf("There is no safe sequence ");
    }
}
void Safety(int pro, int reso)
{
    int alloc[pro][reso], max[pro][reso], avail[reso], need[pro][reso];
    int finish[pro];
    int seq[pro];
    int safe = 0;
    int i, j, k, l, flag = 0;
    printf("Enter the allocation matrix \n");
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < reso; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix \n");
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < reso; j++)
        {
            scanf("%d", &max[i][j]);
        }
        finish[i] = 0;
    }
    printf("Enter the available matrix \n");
    for (i = 0; i < reso; i++)
        scanf("%d", &avail[i]);
    printf("The need matrix will be \n");
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < reso; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for (l = 0; l < 5; l++)
    {
        for (i = 0; i < pro; i++)
        {
            flag = 0;
            for (j = 0; j < reso; j++)
            {
                if (finish[i] == 0)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = -1;
                    }
                }
            }
            if (flag == 0 && finish[i] == 0)
            {
                finish[i] = 1;
                seq[safe] = i;
                safe++;
                for (k = 0; k < reso; k++)
                {
                    avail[k] = avail[k] + alloc[i][k];
                }
            }
        }
    }
    if (safe == pro)
    {
        printf("The safe sequence is \n");
        for (i = 0; i < pro; i++)
        {
            printf("%d ", seq[i]);
        }
    }
    else
    {
        printf("There is no safe sequence ");
    }
}
void main()
{
    int i, j;
    int process, resources;
    printf("Enter the number od processes \n");
    scanf("%d", &process);
    printf("Enter the number of resources \n");
    scanf("%d", &resources);
    Safety(process, resources);
}