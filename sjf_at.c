#include<stdio.h>

void swap(int* x, int* y){
	int t = *x;
	*x = *y;
	*y = t;
}

int main(){
	int n;
	int p[20], tat[20], bt[20], wt[20], at[20], st[20];
	int total_wt = 0, total_tat = 0;
	float avg_wt, avg_tat;
	int i, j;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the burst time and arrival time of each process: \n");
	
	for(i = 0; i < n; i++){
		printf("p[%d]", i+1);
		p[i] = i + 1;
		scanf("%d %d", &bt[i], &at[i]);
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(at[i] < at[j]){
				swap(&at[i], &at[j]);
				swap(&bt[i], &bt[j]);
				swap(&p[i], &p[j]);
			}
			else if(at[i] == at[j]){
				if(bt[i] < bt[j]){
					swap(&at[i], &at[j]);
					swap(&bt[i], &bt[j]);
					swap(&p[i], &p[j]);
				}
			}
		}
	}




	st[0] = at[0];
	wt[0] = 0;
	for(i = 1; i < n; i++){
		st[i] = st[i-1] + bt[i-1];
		wt[i] = st[i] - at[i];
		total_wt = total_wt + wt[i];
	}	
	
	for(i = 0; i < n; i++){
		tat[i] = wt[i] + bt[i];
		total_tat = total_tat + tat[i];
	}
	
    printf("\nprocess burst_time   arrivaltime      waiting_time      turnaround_time\n");
    for(i = 0; i < n; i++){
        printf(" p[%d]        %d             %d          %d          %d \n", p[i], bt[i], at[i], wt[i], tat[i]);
    }
	avg_wt = (float)(total_wt / n);
	avg_tat = (float)(total_tat / n);
	printf("Average waiting time: %f \nAverage turn around tme: %f", avg_wt, avg_tat);
}
