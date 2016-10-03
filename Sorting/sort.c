#include"sort.h"
#include<malloc.h>
#include<memory.h>
void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int* base, int size){
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size - 1; j++){
			if (base[j]>base[j + 1])
				swap(base + j, base + j + 1);
		}
	}
}

void selection_sort(int* base, int size){
	int i, j, m;
	for (i = 0; i < size; i++){
		m = 0;
		for (j = 1; j < size - i; j++){
			if (base[m] < base[j])
				m = j;
		}
		swap(base + m, base + (size - i - 1));
	}
}

void gnome_sort(int* base, int size){
	int i, j;
	for (int i = 1; i < size; i++){
		j = i;
		while (j >= 0 && base[j - 1]>base[j]){
			swap(base + (j - 1), base + j);
			j--;
		}
	}
}

void insertion_sort(int* base, int size){
	int i, j, m;
	for (int i = 1; i < size; i++){
		j = i - 1;
		m = base[i];
		while (j >= 0 && base[j]>m){
			base[j + 1] = base[j];
			j--;
		}
		base[j + 1] = m;
	}
}

void merge(int* a, int as, int* b, int bs, int* dst){
	int i = 0, j = 0, k = 0;
	while (i < as&&j < bs){
		if (a[i]<b[j])dst[k++] = a[i++];
		else dst[k++] = b[j++];
	}
	while (i < as)dst[k++] = a[i++];
	while (j < bs)dst[k++] = b[j++];
}
void merge_sort(int* base, int size){
	int* tmp = (int*)calloc(size,sizeof(int));
	int* p = base;
	int* q = tmp;
	int i, m = 1;
	while (m < size){
		for (i = 0; i < size; i += m * 2){
			int fs = m, ss = m;
			if (size - i < m * 2){
				ss = size - (i + m);
				if (size - i < m){
					fs = size - i;
					ss = 0;
				}
			}
			merge(p + i, fs, p + i + m, ss, q + i);
		}
		m <<= 1;
		int* pt = p;
		p = q;
		q = pt;
	}
	if (p != base)
		memcpy(base, p, size*sizeof(int));
}

void sort3(int*a, int*b, int*c){
	if (*a > *b) swap(a, b);
	if (*a > *c) swap(a, c);
	if (*b > *c) swap(b, c);
}
int partition(int* base, int size){
	sort3(base + size / 2, base, base + size-1);
	int *pivot = base, L = 0, R = size;
	while (1){
		while (base[++L] < *pivot);
		while (base[--R] > *pivot);
		if (L > R)break;
		swap(base + L, base + R);
	}
	swap(pivot, base + R);
	return R;
}
void quick_sort(int* base, int size){
	if (size > 50){
		int p = partition(base, size);
		quick_sort(base, p);
		quick_sort(base + p + 1, size - p - 1);
	}
	else
		insertion_sort(base, size);
}