#ifndef ALGORITHM_GENERIC_SORTING_16_10_02_WC_INCLUDE
#define ALGORITHM_GENERIC_SORTING_16_10_02_WC_INCLUDE
#include<stddef.h>

void bubble_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*));
void selection_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*));
void gnome_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*));
void insertion_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*));
void merge_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*));
void quick_sort(void* base, size_t size, size_t type_size, int(*cmp)(const void*, const void*));

#endif