#include <stdio.h>

int main() {
    int n, i, j, time = 0, smallest;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int completed[20] = {0};
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

    int done = 0;

    while(done < n) {
        smallest = -1;

        // Find process with minimum burst time among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0) {
                if(smallest == -1 || bt[i] < bt[smallest]) {
                    smallest = i;
                }
            }
        }

        if(smallest == -1) {
            time++;   // If no process has arrived, increment time
        } else {
            time += bt[smallest];
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            twt += wt[smallest];
            ttat += tat[smallest];

            completed[smallest] = 1;
            done++;
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
