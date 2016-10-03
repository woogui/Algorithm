#include"sort.h"
#include<stdio.h>
#define MAX 100000
int a[MAX];
int main(){
	
	for (int i = 0; i < MAX; i++)
		a[i] = MAX-i;
	for (int i = 0; i < MAX; i++){
		int r = rand() % MAX;
		int tmp = a[r];
		a[r] = a[i];
		a[i] = tmp;
	}
	quick_sort(a, MAX);
	for (int i = 0; i < MAX; i++)
		printf("%d ", a[i]);
}