#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

void full_array(int* ptr_array, int size) {
	for (int i = 0; i < size; i++) {
		ptr_array[i] = (rand() % 100 - 10);
	}
}

void array_on_screen(int* ptr_array, int size)
{
	for (int i = 0; i < size; i++)
	{
		float b = ptr_array[i];
		printf("array[%d] = %3.f\n", i, b);
	}
	printf("\n");
}

void sort_shake(int* ptrarr, int n) {
	int left = 0;
	int right = n - 1;
	int flag = 1;
	int temp;

	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) {
			if (ptrarr[i] > ptrarr[i + 1]) {
				temp = ptrarr[i];
				ptrarr[i] = ptrarr[i + 1];
				ptrarr[i + 1] = temp;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (ptrarr[i - 1] > ptrarr[i]) {
				temp = ptrarr[i];
				ptrarr[i] = ptrarr[i - 1];
				ptrarr[i - 1] = temp;
				flag = 1;
			}
		}
		left++;
	}
}

void sort_bubble(int* ptr_array, int  size) {
	int  x = 0;
	for (int ch = 1; ch == 1; ch = ch) {
		ch = 0;
		for (int i = 1; i < size; i++) {
			if (ptr_array[i] < ptr_array[i - 1]) {
				ch = 1;
				x = ptr_array[i];
				ptr_array[i] = ptr_array[i - 1];
				ptr_array[i - 1] = x;
			}
		}
	}
}

void sort_select(int* ptr_array, int size) {
	int x = 0;
	int min;
	for (int i = 0; i < size; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (ptr_array[min] > ptr_array[j])
				min = j;
		}
		x = ptr_array[i];
		ptr_array[i] = ptr_array[min];
		ptr_array[min] = x;
	}
}

void sort_insert(int* ptr_array, int size) {
	int x, l;
	for (int i = 1; i < size; i++) {
		x = ptr_array[i];
		for (l = i - 1; l >= 0 && ptr_array[l] > x; l--)
			ptr_array[l + 1] = ptr_array[l];
		ptr_array[l + 1] = x;
	}
}

void task1() {
	setlocale(LC_ALL,"RUS");
	int* ptr_array;
	int size, choice;
	clock_t start, end;
	float time;
	printf("¬ведите размер массива: ");
	scanf_s("%i", &size);
	ptr_array = (int*)malloc(size * sizeof(int));
	if (ptr_array == NULL) {
		puts("error");
		return -1;
	}
	full_array(ptr_array, size);
	array_on_screen(ptr_array, size);
	printf("1.Sort Shake\n2.Sort Bubble\n3.Sort Select\n4.Sort Insert\n");
	scanf_s("%i", &choice);
	printf("\n");
	start = clock();
	switch (choice) {
	case 1:
		sort_shake(ptr_array, size);
		break;
	case 2:
		sort_bubble(ptr_array, size);
		break;
	case 3:
		sort_select(ptr_array, size);
		break;
	case 4:
		sort_insert(ptr_array, size);
		break;

	}
	array_on_screen(ptr_array, size);
	end = clock();
	time = (end - start) * 1. / CLOCKS_PER_SEC;
	printf("¬ремени затрачено: %.20f\n\n", time);
	free(ptr_array);



}

void main() {
	task1();
}