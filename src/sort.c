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

void double_merge(long double *master, long double *child, uint32_t start, uint32_t mid, uint32_t end) {
    int32_t n1 = mid - start + 1;
    int32_t n2 = end - mid;

    int32_t i, j;
    long double *master_left_array = malloc(n1 * sizeof(long double));
    long double *master_right_array = malloc(n2 * sizeof(long double));
    long double *child_left_array = malloc(n1 * sizeof(long double));
    long double *child_right_array = malloc(n2 * sizeof(long double));

	for (i = 0; i < n1; i++) {
		master_left_array[i] = master[start + i];
        child_left_array[i] = child[start + i];
	}

	for (j = 0; j < n2; j++) {
		master_right_array[j] = master[mid + 1 + j];
        child_right_array[j] = child[mid + 1 + j];
	}

	i = j = 0;

	for (uint32_t k = start; k <= end; k++) {
		if (i < n1) {
			if (j < n2) {
                if (master_left_array[i] <= master_right_array[j]) {
                    master[k] = master_left_array[i];
                    child[k] = child_left_array[i++];
                } else {
                    master[k] = master_right_array[j];
                    child[k] = child_right_array[j++];
                }
			} else {
				master[k] = master_left_array[i];
                child[k] = child_left_array[i++];
			}
		} else {
			master[k] = master_right_array[j];
            child[k] = child_right_array[j++];
		}
	}
}

void double_merge_sort(long double *master, long double *child, uint32_t start, uint32_t end) {
    if (start < end) {
        uint32_t mid = start + (end - start) / 2;
        double_merge_sort(master, child, start, mid);
        double_merge_sort(master, child, mid + 1, end);
        double_merge(master, child, start, mid, end);
    }
}