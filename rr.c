#include <stdio.h>

int main() {
    int n, tq;
    int at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];
    int i, time = 0, remain, flag = 0;

    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];  // Remaining time
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT\n");

    for(time = 0, i = 0; remain != 0; ) {

        if(rt[i] <= tq && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0) {
            rt[i] -= tq;
            time += tq;
        }

        // If process is completed
        if(rt[i] == 0 && flag == 1) {
            remain--;

            ct[i] = time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
                   i+1, at[i], bt[i], ct[i], wt[i], tat[i]);

            twt += wt[i];
            ttat += tat[i];

            flag = 0;
        }

        // Move to next process
        if(i == n - 1)
            i = 0;
        else if(at[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time = %.2f", twt / n);
    printf("\nAverage Turnaround Time = %.2f\n", ttat / n);

    return 0;
}
