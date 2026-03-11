#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], pr[20];
    int ct[20], wt[20], tat[20];
    float twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input
    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];   // Remaining time
    }

    while(completed < n) {
        int highest = -1;
        int minPriority = INT_MAX;

        // Find process with highest priority
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && pr[i] < minPriority) {
                minPriority = pr[i];
                highest = i;
            }
        }

        if(highest == -1) {
            time++;   // CPU idle
        }
        else {
            rt[highest]--;   // Execute for 1 unit
            time++;

            if(rt[highest] == 0) {
                completed++;

                ct[highest] = time;
                tat[highest] = ct[highest] - at[highest];
                wt[highest] = tat[highest] - bt[highest];

                twt += wt[highest];
                ttat += tat[highest];
            }
        }
    }

    printf("\nPROCESS\tAT\tBT\tPR\tCT\tWT\tTAT");

    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",
        i+1, at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", twt/n);
    printf("\nAverage Turnaround Time = %.2f\n", ttat/n);

    return 0;
}
