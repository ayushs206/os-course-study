#include <stdio.h>

#define P 3
#define R 4

// Check whether the system is in a safe state
int isSafe(int available[], int allocation[P][R],
           int need[P][R]) {
    int work[R], finish[P] = {0};
    int safeSequence[P];
    int count = 0;

    for (int j = 0; j < R; j++)
        work[j] = available[j];

    while (count < P) {
        int found = 0;

        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;

                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allocation[i][k];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found)
            break;
    }

    if (count == P) {
        printf("System is in a SAFE state.\n");
        printf("Safe sequence: ");

        for (int i = 0; i < P; i++)
            printf("P%d%s", safeSequence[i],
                   i == P - 1 ? "\n" : " -> ");

        return 1;
    }

    printf("System is in an UNSAFE state.\n");
    printf("No safe sequence exists.\n");
    return 0;
}

// Process a resource request using the Banker's Algorithm
void requestResources(int available[],
                      int allocation[P][R],
                      int need[P][R],
                      int process, int request[R]) {
    printf("\nRequest by P%d: ", process);
    for (int j = 0; j < R; j++)
        printf("%d ", request[j]);
    printf("\n");

    // Request cannot exceed the process's remaining need
    for (int j = 0; j < R; j++) {
        if (request[j] > need[process][j]) {
            printf("Error: Request exceeds maximum claim.\n");
            return;
        }
    }

    // Request must be currently available
    for (int j = 0; j < R; j++) {
        if (request[j] > available[j]) {
            printf("Resources not available. Request denied.\n");
            return;
        }
    }

    // Temporarily allocate the requested resources
    for (int j = 0; j < R; j++) {
        available[j] -= request[j];
        allocation[process][j] += request[j];
        need[process][j] -= request[j];
    }

    printf("Checking safety after tentative allocation...\n");

    if (isSafe(available, allocation, need)) {
        printf("Request GRANTED.\n");
    } else {
        // Roll back if the resulting state is unsafe
        for (int j = 0; j < R; j++) {
            available[j] += request[j];
            allocation[process][j] -= request[j];
            need[process][j] += request[j];
        }

        printf("Request DENIED. Allocation rolled back.\n");
    }
}

int main() {
    int available[R] = {3, 3, 2, 2};

    int allocation[P][R] = {
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };

    int max[P][R] = {
        {2, 1, 1, 1},
        {1, 2, 1, 2},
        {2, 2, 2, 1}
    };

    int need[P][R];
    int request[R] = {1, 0, 0, 0};
    int process = 1;

    // Calculate Need = Maximum - Allocation
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Initial system state:\n");
    isSafe(available, allocation, need);

    requestResources(available, allocation, need,
                     process, request);

    printf("\nDemonstrating an unsafe state:\n");

    // Independent test case with insufficient available resources
    int unsafeAvailable[R] = {0, 0, 0, 0};

    isSafe(unsafeAvailable, allocation, need);

    return 0;
}