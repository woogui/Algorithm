#include"sort.h"
#include<stdio.h>
#define MAX 100000
int a[MAX];

int cmp(const void* a, const void* b){
	return *(int*)a<*(int*)b ? -1 : *(int*)a>*(int*)b;
}

int main(){

	for (int i = 0; i < MAX; i++)
		a[i] = i;
	for (int i = 0; i < MAX; i++){
		int r = rand() % MAX;
		int tmp = a[r];
		a[r] = a[i];
		a[i] = tmp;
	}
	quick_sort(a, MAX, sizeof(int), cmp);
	for (int i = 0; i < MAX; i++)
		printf("%d ", a[i]);
}