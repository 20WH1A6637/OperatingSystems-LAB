#include<stdio.h>
#include<stdlib.h>
int full = 0, empty = 5, mutex = 1, x = 0;

int wait(int s){
	s--;
	return s;
}

int signal(int s){
	s++;
	return s;
}

void producer(){
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	x++;
	printf("Producer producs the item: %d\n", x);
	mutex = signal(mutex);
}

void consumer(){
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("Consumer consumes the item: %d\n", x);
	x--;
	mutex = signal(mutex);
}

int main(){
	int ch;
	while(1){
		printf("1. Producer\n 2. Consumer\n 3. Exit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				if((mutex == 1) &&(empty != 0)){
					producer();
				}
				else{
					printf("Buffer is full\n");
				}
				break;
			case 2:
				if((mutex == 1) && (full != 0)){
					consumer();
				}
				else{
					printf("Buffer is empty\n");
				}
				break;
			case 3:
				exit(0);
		}
	}	
}
