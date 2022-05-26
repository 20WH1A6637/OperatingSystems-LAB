#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int pd1[2], pd2[2];
	char s1[] = "bvrit", s2[] = "hyderabad", s3[100], s4[100];
	pipe(pd1);
	pipe(pd2);
	int p = fork();
	if(p > 0){
		close(pd1[0]);
		write(pd1[1], s1, strlen(s1));
		close(pd1[1]);
		wait(NULL);
	}
	else if(p == 0){
		close(pd1[1]);
		write(pd1[0], s3, strlen(s3));
		printf("String1 %s\n", s3);
		close(pd1[0]);
		close(pd2[0]);
		write(pd2[1], s2,strlen(s2));
		close(pd2[1]);
		exit(0);
		read(pd2[0], s4, strlen(s4));
		printf("String2 %s\n", s4);
	}
}

