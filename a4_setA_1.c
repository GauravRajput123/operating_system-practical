// FIFO :-

#include <stdio.h>
int RS[16] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
int frame[10], n, pf = 0, fcnt = 0;
int search(int no)
{
    int i;
    for (i = 0; i < n; i++)
        if (frame[i] == no)
            return 1;
    return 0;
}
void add(int no)
{
    if (fcnt == n)
        fcnt = 0;
    frame[fcnt++] = no;
    pf++;
}
main()
{
    int i, j = 0;
    printf("\nEnter Frame Size : ");
    scanf("%d", &n);
    for (i = 0; i < 16; i++)
    {
        if (search(RS[i]) == 0)
            add(RS[i]);
    }
    printf("\nTOTAL PAGE FAULTS : %d\n", pf);
}

// LRU :-
#include <stdio.h>
// int RS[16]={12,15,18,12,12,8,18,7,8,10,7,13};
int RS[16] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
int RScnt[16], frame[10], framecnt[10], n, pf = 0, fcnt = 0, min, tt, Timer = 0, tp;
int search(int no, int pos)
{
    int i;
    for (i = 0; i < n; i++)
        if (frame[i] == no)
        {
            RScnt[pos] = ++Timer;
            framecnt[fcnt] = Timer;
            return 1;
        }
    return 0;
}
void add(int no, int pos)
{
    int i;
    if (fcnt < n)
    {
        tt = 0;
        min = framecnt[0];
        for (i = 1; i < n; i++)
        {
            if (framecnt[i] < min)
            {
                min = framecnt[i];
                tt = i;
            }
        }
        Timer++;
        frame[tt] = no;
        RScnt[pos] = Timer;
        framecnt[tt] = Timer;
        pf++;
    }
    else
    {
        Timer++;
        frame[fcnt] = no;
        framecnt[fcnt] = Timer;
        RScnt[pos] = Timer;
        pf++;
        fcnt++;
    }
}

void main()
{
    int i, j = 0;
    printf("\nEnter Frame Size : ");
    scanf("%d", &n);
    for (i = 0; i < 16; i++)
        if (search(RS[i], i) == 0)
            add(RS[i], i);

    printf("\nTOTAL PAGE FAULTS : %d\n", pf);
}
