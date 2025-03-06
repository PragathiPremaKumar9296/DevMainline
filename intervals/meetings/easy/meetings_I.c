#include <stdbool.h>
int compare (const void *a, const void *b) {
    int* intervalA = *(int **)a;
    int* intervalB = *(int **)b;
    return intervalA[0] - intervalB[0];
}

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort (intervals, intervalsSize, sizeof(int*), compare);

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < intervals[i - 1][1])
            return false;
    }
    return true;
}