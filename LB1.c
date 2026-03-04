#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sort processes based on Arrival Time
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                // Swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // FCFS Scheduling
    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++) {
        if(ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];   // CPU Idle
            wt[i] = 0;
        } else {
            wt[i] = ct[i - 1] - at[i];
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = bt[i] + wt[i];
    }

    // Calculate totals
    for(i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", twt/n);
    printf("\nAverage Turnaround Time = %.2f\n", ttat/n);

    return 0;
}
