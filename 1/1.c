#include <stdio.h>

void find(int*);

int * first = NULL, * second = NULL;

int main(){
	int input[10];
	for(int i = 0; i < 10; i++){
		scanf("%d",&input[i]);
	}
	
	find(input);
	
	printf("first=%d\nsecond=%d\n", *first, *second);
	
	return 0;
}

void find(int * a){
	int * temp = NULL;
	first = &a[0];
	second = &a[1];
	if( *second > *first ){
		temp = first;
		first = second;
		second = temp;
	}
	for(int i = 2; i < 10; i++){
		if( a[i] > *second ){
			second = &a[i];
			if( *second > *first ){
				temp = first;
				first = second;
				second = temp;
			}
		}
	}
}
