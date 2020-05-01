#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<Windows.h>
#include<stdlib.h>

void main()
{
    int n, b[10], w[10], i, j, h, t, tt;
    int stmp,wtmp;
    int stime[10], a[10];
    int lastP = 0;
    float avg = 0;
    system("cls");
    printf("\n\tJOB SCHEDULING ALGORITHM[SJF]");
    printf("\n\t*****************************************************\n");
    printf("\nEnter howmany jobs:");
    scanf("%d", &n);
    printf("\nEnter burst time and arrival time for corresponding job....\n");

    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d burst time:", i + 1);
        scanf("%d", &b[i]);
        printf("\nProcess %d arrival time:", i + 1);
        scanf("%d", &stime[i]);
        a[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (stime[i] > stime[j])
            {
                t = b[i];
                tt = a[i];
                stmp = stime[i];
                b[i] = b[j];
                a[i] = a[j];
                stime[i] = stime[j];
                b[j] = t;
                a[j] = tt;
                stime[j] = stmp;
            }
        }
    }

    w[0] = 0;

    printf("\nprocess %d waiting time: 0", a[0]);

    for (i = lastP + 1; i < n; i++) {
        if (stime[i] <= b[lastP] + w[lastP] + stime[lastP]) {
            for (j = i + 1; j < n; j++) {
                if (stime[j] <= b[lastP] + w[lastP] + stime[lastP]) {
                    if (b[j] < b[i]) {
                        t = b[i];
                        b[i] = b[j];
                        b[j] = t;

                        tt = a[i];
                        a[i] = a[j];
                        a[j] = tt;
                        
                        stmp = stime[i];
                        stime[i] = stime[j];
                        stime[j] = stmp;

                        wtmp = w[i];
                        w[i] = w[j];
                        w[j] = wtmp;
                        continue;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    break;
                }
            }
            lastP ++;
            w[lastP] = b[lastP - 1] + w[lastP - 1] + stime[lastP - 1] - stime[lastP];
            printf("\nProcess %d waiting time: %d", a[lastP], w[lastP]);
            avg += w[lastP];
            continue;
        }
        else {
            lastP++;
            w[lastP] = b[lastP - 1] + w[lastP - 1] + stime[lastP - 1] - stime[lastP];
            printf("\nProcess %d waiting time: %d", a[lastP], w[lastP]);
            avg += w[lastP];
        }
    }

    printf("\ntotal waiting time:%f", avg);
    printf("\n\nthe average waiting time is:%f\n", avg / n);

    printf("\nGaunt Chart\n***************************************\n\n\t");

    h = 22;

    for (i = 0; i < n; i++)
    {
        printf("%d", b[i]);
        for (j = 0; j < b[i]; j++) {
            printf("%c", h);
        }
    }
    printf("\n\t");

    for (i = 0; i < n; i++)
    {
        printf("%d", w[i]);
        for (j = 0; j < w[i]; j++) {
            printf("%c", h);
        }
        Sleep(1000);
    }
    _getch();
}