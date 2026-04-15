#include <stdio.h>

#define MAX 10

typedef struct {
    int id, burst, remaining, weight;
} Process;

int main() {
    Process p[MAX];
    int n, total_weight = 0;
    int quantum = 10, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        p[i].id = i + 1;

        printf("Burst Time: ");
        scanf("%d", &p[i].burst);

        printf("Weight: ");
        scanf("%d", &p[i].weight);

        p[i].remaining = p[i].burst;
        total_weight += p[i].weight;
    }

    printf("\nExecution:\n");

    while (completed < n) {
        for (int i = 0; i < n; i++) {

            if (p[i].remaining > 0) {
                int slice = (p[i].weight * quantum) / total_weight;
                if (slice == 0) slice = 1;

                printf("P%d ", p[i].id);

                if (p[i].remaining <= slice) {
                    p[i].remaining = 0;
                    completed++;
                    total_weight -= p[i].weight;
                } else {
                    p[i].remaining -= slice;
                }
            }
        }
    }

    return 0;
}