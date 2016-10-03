#include"sort.h"
#include<stdlib.h>
#include<memory.h>

void swap(void* a, void* b, size_t type_size){
	char tmp;
	char *cur1 = a, *cur2 = b;
	for (int i = 0; i < type_size; i++){
		tmp = *cur1;
		*cur1 = *cur2;
		*cur2 = tmp;
		cur1++;
		cur2++;
	}
}

void bubble_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size - 1; j++){
			if (cmp((char*)base + j*type_size, (char*)base + (j + 1)*type_size) > 0)
				swap((char*)base + j*type_size, (char*)base + (j + 1)*type_size, type_size);
		}
	}
}

void selection_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	int i, j, m;
	for (i = 0; i < size; i++){
		m = 0;
		for (j = 0; j < size - i; j++){
			if (cmp((char*)base + m*type_size, (char*)base + j*type_size) < 0)
				m = j;
		}
		swap((char*)base + m*type_size, (char*)base + (size - i - 1)*type_size, type_size);
	}
}

void gnome_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	int i, j;
	for (i = 1; i < size; i++){
		j = i;
		while (j >= 0 && cmp((char*)base + (j - 1)*type_size, (char*)base + j*type_size)>0){
			swap((char*)base + (j - 1)*type_size, (char*)base + j*type_size, type_size);
			j--;
		}
	}
}

void insertion_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	int i, j;
	char* m = (char*)malloc(type_size);
	for (i = 1; i < size; i++){
		j = i - 1;
		memcpy(m, (char*)base + i*type_size, type_size);
		while (j >= 0 && cmp(m, (char*)base + j*type_size) < 0){
			memcpy((char*)base + (j + 1)*type_size, (char*)base + j*type_size, type_size);
			j--;
		}
		memcpy((char*)base + (j + 1)*type_size, m, type_size);
	}
}

void merge(void* a, size_t as, void* b, size_t bs, void* dst, size_t type_size, int(*cmp)(const void*, const void*)){
	int i = 0, j = 0, k = 0;
	while (i < as&&j < bs){
		if (cmp((char*)a + i*type_size, (char*)b + j*type_size) < 0){
			memcpy((char*)dst + (k++)*type_size, (char*)a + (i++)*type_size, type_size);
		}
		else{
			memcpy((char*)dst + (k++)*type_size, (char*)b + (j++)*type_size, type_size);
		}
	}
	while (i < as){
		memcpy((char*)dst + (k++)*type_size, (char*)a + (i++)*type_size, type_size);
	}
	while (j < bs){
		memcpy((char*)dst + (k++)*type_size, (char*)b + (j++)*type_size, type_size);
	}
}
void merge_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	char* tmp = (char*)malloc(size*type_size);
	char* p = (char*)base;
	char* q = tmp;
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
			merge(p + i*type_size, fs, p + (i + m)*type_size, ss, q + i*type_size, type_size, cmp);
		}
		m <<= 1;
		char* pt = p;
		p = q;
		q = pt;
	}
	if (p != base)
		memcpy(base, p, size*type_size);
}

void sort3(void* a, void* b, void*c, size_t type_size){
	if (cmp(a, b) > 0) swap(a, b, type_size);
	if (cmp(a, c) > 0) swap(a, c, type_size);
	if (cmp(b, c) > 0) swap(b, c, type_size);
}
int partition(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	sort3((char*)base + (size / 2)*type_size, base, (char*)base + (size - 1)*type_size, type_size);
	char* pivot = (char*)base;
	int L = 0, R = size;
	while (1){
		while (cmp((char*)base + (++L)*type_size, pivot) < 0);
		while (cmp((char*)base + (--R)*type_size, pivot) > 0);
		if (L > R)break;
		swap((char*)base + L*type_size, (char*)base + R*type_size, type_size);
	}
	swap(pivot, (char*)base + R*type_size, type_size);
	return R;
}
void quick_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*)){
	if (size > 50){
		int p = partition(base, size, type_size, cmp);
		quick_sort(base, p, type_size, cmp);
		quick_sort((char*)base + (p + 1)*type_size, size - p - 1, type_size, cmp);
	}
	else
		insertion_sort(base, size, type_size, cmp);
}