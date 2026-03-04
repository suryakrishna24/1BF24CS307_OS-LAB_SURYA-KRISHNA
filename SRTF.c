#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], ct[20], wt[20], tat[20];
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
        rt[i] = bt[i];   // Remaining time initially equals burst time
    }

    while(completed < n) {
        int shortest = -1;
        int min = INT_MAX;

        // Find process with shortest remaining time
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1) {
            time++;   // No process available (CPU idle)
        } else {
            rt[shortest]--;  // Execute process for 1 unit
            time++;

            // If process finishes
            if(rt[shortest] == 0) {
                completed++;
                ct[shortest] = time;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];

                twt += wt[shortest];
                ttat += tat[shortest];
            }
        }
    }

    // Output
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", twt/n);
    printf("\nAverage Turnaround Time = %.2f\n", ttat/n);

    return 0;
}
