#include <stdio.h>

int main() {
    int n, i, j, pos, time = 0;
    int at[20], bt[20], pr[20];
    int ct[20], wt[20], tat[20];
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

        printf("Priority: ");
        scanf("%d", &pr[i]);
    }

    for(i = 0; i < n; i++) {
        int highest = 999;

        for(j = 0; j < n; j++) {
            if(at[j] <= time && completed[j] == 0 && pr[j] < highest) {
                highest = pr[j];
                pos = j;
            }
        }

        time += bt[pos];
        ct[pos] = time;

        tat[pos] = ct[pos] - at[pos];
        wt[pos] = tat[pos] - bt[pos];

        twt += wt[pos];
        ttat += tat[pos];

        completed[pos] = 1;
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
