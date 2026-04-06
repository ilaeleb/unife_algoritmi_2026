#include <sort.h>

void insertion_sort(long double *data, uint32_t start, uint32_t end) {
    int32_t i, j;
    long double key;

    for (i = start + 1; i <= end; i++) {
        j = i - 1;
        key = data[i];

        while(j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void merge(long double *data, uint32_t start, uint32_t mid, uint32_t end) {
    int32_t n1 = mid - start + 1;
    int32_t n2 = end - mid;

    int32_t i, j;
    long double left_array[n1], right_array[n2];

	for (i = 0; i < n1; i++) {
		left_array[i] = data[start + i];
	}

	for (j = 0; j < n2; j++) {
		right_array[j] = data[mid + 1 + j];
	}

	i = j = 0;

	for (uint32_t k = start; k <= end; k++) {
		if (i < n1) {
			if (j < n2) {
				data[k] = (left_array[i] <= right_array[j]) ? left_array[i++] : right_array[j++];
			} else {
				data[k] = left_array[i++];
			}
		} else {
			data[k] = right_array[j++];
		}
	}
}

void merge_sort(long double *data, uint32_t start, uint32_t end) {
    if (start < end) {
        uint32_t mid = start + (end - start) / 2;
        merge_sort(data, start, mid);
        merge_sort(data, mid + 1, end);
        merge(data, start, mid, end);
    }
}

