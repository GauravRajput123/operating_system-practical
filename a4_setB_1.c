//Implement OPT

#include <stdio.h>

int RS[16] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
int frame[10], n, pf = 0;

int search(int no) {
    for (int i = 0; i < n; i++) {
        if (frame[i] == no) {
            return i;
        }
    }
    return -1;
}

void add(int no, int recent[]) {
    int replace_idx = 0;
    int max_future = -1;
    for (int i = 0; i < n; i++) {
        int future = 0;
        for (int j = pf; j < 16; j++) {
            if (RS[j] == frame[i]) {
                break;
            }
            future++;
        }
        if (future > max_future) {
            max_future = future;
            replace_idx = i;
        }
    }
    frame[replace_idx] = no;
    pf++;
}

int main() {
    printf("\nEnter Frame Size : ");
    scanf("%d", &n);

    int recent[n];
    for (int i = 0; i < n; i++) {
        recent[i] = 0;
    }

    for (int i = 0; i < 16; i++) {
        int idx = search(RS[i]);
        if (idx == -1) {
            add(RS[i], recent);
        }
    }

    printf("\nTOTAL PAGE FAULTS : %d\n", pf);

    return 0;
}