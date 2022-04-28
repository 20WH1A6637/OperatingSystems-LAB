#include<stdio.h>
int main() {
    int n,temp,avgw = 0,avgt = 0;
    int p[20];
    int w[20];
    int t[20];
   
   
    printf("\nenter the num of processes\n");
    scanf("%d",&n);
    printf("\nenter the burst time for each process\n");
    for(int i = 0;i < n;i++) {
        scanf("%d",&p[i]);
    }
   
    w[0] = 0;
    for(int i = 1;i <= n;i++){
       w[i] = w[i-1] + p[i -1];
       t[i-1] = w[i-1] + p[i-1];      
   }

   
    printf("\nprocess burst_time    waiting_time      turnaround_time\n");
    for(int i = 0;i<n;i++){
        printf(" p[%d]        %d             %d              %d \n" ,i,p[i],w[i],t[i]);
        avgw = avgw + w[i];
        avgt = avgt + t[i];
    }
   
    printf("\navg waiting time =  %d",avgw/n);
     printf("\navg turnaround time =  %d\n",avgt/n);
    return 0;
}
