#include<stdio.h>
 
int main(){
int b[20],w[20],t[20];
    int aw, at, i, n, temp, sw = 0, st = 0;
    printf("enter no .of processors : ");
    scanf("%d",&n);

    printf("enter burst time of processors : ");
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);  
    }
   
    for(i=0;i<=n;i++){
if(b[i]>b[i+1]){
            temp=b[i];
            b[i]=b[i+1];
            b[i+1]=temp;
        }
    }
     w[0]=0;
      for(i=1;i<n;i++){
          w[i]=w[i-1]+b[i-1];
          sw = sw+w[i];
      }
      t[0]=b[0];
      for(i=1;i<n;i++){
          t[i]=b[i]+t[i-1];
          st = st+t[i];
      }
      st=st+t[0];
     aw=sw/n;
     at= st/n;
      printf("turnaround time\n");
      for(i=0;i<n;i++){
          printf("%d ",t[i]);
     }
    printf("\n");
    printf("burst time\n");
    for(i=0;i<n;i++){
         printf("%d ",b[i]);
     }
      printf("\n");
      printf("waiting time\n");
      for(i=0;i<n;i++){
          printf("%d ",w[i]);
      }
      printf("\n");
      printf("average waiting time : %d \n",aw);
     printf("average turnaround time : %d \n",at);
     
      return 0;
  }
