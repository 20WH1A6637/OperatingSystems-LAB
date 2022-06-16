#include<stdio.h>

int main(){
    int bt[20], wt[20], tat[20];
    int i, n;
    float wtavg, tatavg;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter burst times:");
    for(i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i = 1; i < n; i++){
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\process \tburst time \twaiting time \t turnaround time\n");
    for(i = 0; i < n; i++){
        printf("\n p%d \t\t %d \t\t %d \t\t %d\n", i, bt[i], wt[i], tat[i]);

    }
    printf("avg wt: %f \n", wtavg/n);
    printf("avg tat: %f ", tatavg/n);
}
