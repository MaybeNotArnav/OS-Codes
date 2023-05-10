#include <stdio.h>
#include <stdlib.h>

void first(int mem[], int process[], int parts, int pro)
{
    int i, j;
    int alloc[parts];
    for (i = 0; i < parts; i++)
        alloc[i] = -1;
    for (i = 0; i < pro; i++)
    {
        for (j = 0; j < parts; j++)
        {
            if (mem[j] >= process[i] && alloc[j] == -1)
            {
                alloc[j] = i;
                break;
            }
        }
    }
    printf("The memory partition after allocation looks like \n");
    for (i = 0; i < parts; i++)
    {
        printf("%d ", alloc[i]);
    }
}
void best(int mem[], int process[], int parts, int pro)
{
    int i, j;
    int best = -1;
    int diff = 999;
    int alloc[parts];
    for (i = 0; i < parts; i++)
        alloc[i] = -1;

    for (i = 0; i < pro; i++)
    {
        best = -1;
        diff = 999;
        for (j = 0; j < parts; j++)
        {
            if (mem[j] >= process[i] && alloc[j] == -1 && mem[j] - process[i] < diff)
            {
                best = j;
                diff = mem[j] - process[i];
            }
        }
        if (best != -1)
        {
            alloc[best] = i;
        }
    }
    printf("The memory partition after allocation looks like \n");
    for (i = 0; i < parts; i++)
    {
        printf("%d ", alloc[i]);
    }
}
void worst(int mem[], int process[], int parts, int pro)
{
    int i, j;
    int worst = -1;
    int diff = 0;
    int alloc[parts];
    for (i = 0; i < parts; i++)
        alloc[i] = -1;

    for (i = 0; i < pro; i++)
    {
        worst = -1;
        diff = 0;
        for (j = 0; j < parts; j++)
        {
            if (mem[j] >= process[i] && alloc[j] == -1 && mem[j] - process[i] >= diff)
            {
                worst = j;
                diff = mem[j] - process[i];
            }
        }
        if (worst != -1)
        {
            alloc[worst] = i;
        }
    }
    printf("The memory partition after allocation looks like \n");
    for (i = 0; i < parts; i++)
    {
        printf("%d ", alloc[i]);
    }
}

void main()
{
    int mem[10], size[10], process[10];
    int parts, i, pro;
    printf("Enter the number of memory partitions \n");
    scanf("%d", &parts);

    printf("Enter the size of each partition \n");
    for (i = 0; i < parts; i++)
        scanf("%d", &mem[i]);

    printf("Enter the number of processes \n");
    scanf("%d", &pro);

    printf("Enter the size of the processes \n");
    for (i = 0; i < pro; i++)
        scanf("%d", &process[i]);

    worst(mem, process, parts, pro);
}