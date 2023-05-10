#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct process
{
    int execute, arrival;
    int pid;
};

void SJF(struct process p[], int n)
{
    struct process temp;
    int order[n];
    int min;
    int wait_time = 0, turnaround_time = 0;
    float avg_wait, avg_turn;
    int st[n], ct[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (p[j].arrival > p[j + 1].arrival)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    st[0] = p[0].arrival;
    ct[0] = p[0].execute;
    order[0] = 1;
    for (i = 1; i < n; i++)
    {
        if (p[i].arrival <= p[i - 1].execute)
        {
            min = i;
            for (j = i + 1; j < n; j++)
            {
                if (p[j].execute < p[min].execute)
                {
                    min = j;
                }
            }
            st[i] = p[i - 1].execute + st[i - 1];
            ct[i] = p[i].execute + ct[i - 1];
            order[i] = min;
        }
    }

    for (i = 0; i < n; i++)
    {
        wait_time += st[i] - p[i].arrival;
        turnaround_time += ct[i] - p[i].arrival;
    }

    printf("The total wait is %d and the total turnaround is %d \n", wait_time, turnaround_time);

    printf("Gant Chart \n");
    for (i = 0; i < n; i++)
    {

        printf("%d - P%d - %d\n", st[i], order[i], ct[i]);
    }
}
void FCFS(struct process p[], int n)
{
    struct process temp;
    int wait_time = 0, turnaround_time = 0;
    float avg_wait, avg_turn;
    int st[n], ct[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (p[j].arrival > p[j + 1].arrival)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    st[0] = p[0].arrival;
    for (i = 1; i < n; i++)
    {
        st[i] = p[i - 1].execute + st[i - 1];
    }
    ct[0] = p[0].execute;
    for (i = 1; i < n; i++)
    {
        ct[i] = p[i].execute + ct[i - 1];
    }

    for (i = 0; i < n; i++)
    {
        wait_time += st[i] - p[i].arrival;
        turnaround_time += ct[i] - p[i].arrival;
    }

    printf("The total wait is %d and the total turnaround is %d \n", wait_time, turnaround_time);

    printf("Gant Chart \n");
}
void main()
{
    int i, n;
    struct process p[10];
    printf("Enter the number of prcoesses you want to enter ");
    scanf("%d", &n);
    printf("Enter burst time ");
    for (i = 0; i < n; i++)
    {
        p[i].pid = i;
        scanf("%d", &p[i].execute);
    }
    printf("Enter arrival time ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].arrival);
    }
    SJF(p, n);
}