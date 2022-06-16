#include<stdio.h>

int main(){
	int n, r;
	printf("Enter the no of processes: \n");
	scanf("%d", &n);
	printf("Enter the no of resources: \n");
	scanf("%d", &r);
	
	int max[n][r], alloc[n][r], avail[r], need[n][r];
	int i, j;
	int flag = 1;
	int status[n];
	
	printf("Enter the values of max need matrix: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < r; j++){
			scanf("%d", &max[i][j]);
		}
	}

	printf("Enter the values Allocate matrix: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < r; j++){
			scanf("%d", &alloc[i][j]);
		}
	}

	printf("Enter the values of available matrix: \n");
	for(i = 0; i < r; i++){
		scanf("%d", &avail[i]);
	}

	for(i = 0; i < n; i++){
		status[i] = 0;
	}	

	for(i = 0; i < n; i++){
		for(j = 0; j < r; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	while(flag){
	    flag = 0;
		for(i = 0; i < n; i++){
			int c = 0;
			for(j = 0; j < r; j++){
				if(status[i] == 0 && avail[j] >= need[i][j]){
					c++;
				}
			}
			if(c == r){
				for(int k = 0; k < r; k++){
					avail[k] = avail[k] + alloc[i][k];
				}
				status[i] = 1;
				printf("P[%d]", i + 1);
				flag = 1;
			}
		}
	}

	int c1 = 0;
	for(i = 0; i < n; i++){
		if(status[i] == 1){
			c1 += status[i];
		}
	} 
    if(c1 == n){
		printf("SAFE STATE");
		flag = 0;
	}
	else{
		printf("DEAD LOCK");
	} 
	
}
