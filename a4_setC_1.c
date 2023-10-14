//Implement MRU

#include <stdio.h>

int RS[16] = {2, 5, 2, 8, 5, 4, 1, 2, 3, 2, 6, 1, 2, 5, 9, 8};
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
    int max_recent = -1;
    for (int i = 0; i < n; i++) {
        if (recent[i] > max_recent) {
            max_recent = recent[i];
            replace_idx = i;
        }
    }
    frame[replace_idx] = no;
    pf++;
    recent[replace_idx] = 0;
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