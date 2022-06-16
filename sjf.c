#include <stdio.h>
int main(){
    int i,j,n,pos,res=0,k;
    float avg_wt,avg_tat;
    printf("enter number of processes:");
    scanf("%d",&n);
    int wt[n],bt[n],p[n],temp,tr[n];
    for(i = 0;i<n;i++){
        printf("enter burst time");
        scanf("%d",&bt[i]);
        p[i]= i+1;
    }
    for(i = 0;i<n;i++){
        pos = i;
        for(j = i+1;j<n;j++){
            if(bt[j]<bt[pos]){
                pos = j;
             }
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i]= p[pos];
        p[pos]=temp;
    }
    wt[0] = 0;
    for(i = 1; i < n; i++){
        wt[i] = 0;
        for(j = 0; j < i; j++){
            wt[i] += bt[j];
        }
        res += wt[i];
    }

    avg_wt =(float)res/n;
    res = 0;
    printf("\nprocess\tbuffertime\twaitingtime\tturnaroundtime\n");
    for(k = 0; k < n; k++){
        tr[k] = wt[k] + bt[k];
        res += tr[k];
        printf("%d\t\t%d\t\t%d\t\t%d\n",p[k],bt[k],wt[k],tr[k]);
    }

    avg_tat =(float)res/n;
    printf("Average waiting time is:%f\n",avg_wt);
    printf("Average turn around time is:%f\n",avg_tat);
}
