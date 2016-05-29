/*
	a) Bubble sort and variants
		-- bubble sort
		-- shell sort
		-- comb sort
	b) Simple sort
		-- insertion sort
		-- selection sort
	c) Efficient sorts
		-- merge sort
		-- heap sort
		-- quick sort
	d) Distribution sort
		-- counting sort
		-- Bucket sort
		-- Radix sort 
*/
void bubble_sort(double [], int);
void buble_sort_with_if_no_match(double [], int);
void shell_sort();
void comb_sort();

void insertion_sort(double [], int);
void selection_sort(double [], int);

// ascending order
void bubble_sort(double arr[], int arr_size) {
    /* worse case, Avg and best case: O(n^2) */
	int i,j;
	double tmp;
	for (i=0; i < arr_size; i++) {
		for (j=0; j < arr_size-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				// can we do without tmp
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			} 
		}
	}
	
}	

void bubble_sort_with_if_no_match(double arr[], int arr_size) {
	/* 
	worse case, Avg and best case: O(n^2) 
	stable?, in-place, offline?(have to check)
	*/
	int i,j, found = 0;
	double tmp;
	for (i=0; i < arr_size; i++) {
		for (j=0; j < arr_size-i-1; j++) {
			found = 0;
			if (arr[j] > arr[j+1]) {
				// can we do without tmp
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
				found = 1;
			} 
		}
		if (found == 0) {
			break;
		}
	}
	
}


void insertion_sort(double arr[], int arr_size) {
	int i, j, tmp;
	
	/* 
	worse and Avg case: O(n^2)
	best case: O(n)
	look one at time and compare selected one to left sublist with is already  sorted. 
	
	stable?,in-place, online 
	*/
	for (i = 1; i < arr_size; ++i) {
		tmp = arr[i];
		for(j=i-1; j >= 0 && arr[j] > tmp; j--) {
			arr[j+1] = arr[j];
		}
		arr[j+1] = tmp;
	}
}

void selection_sort(double arr[], int arr_size) {
	/* 
	start with select smallest or largest and put it to front and move other to right on position.
		eg.
		start: 4,3,1,2
		step1: 1,4,3,2
		step2: 1,2,4,3
		step3: 1,2,3,4
		stable, in-place, offline
		
	*/
	int i, j, at_index, tmp;
	for (i = 0; i < arr_size; ++i) {
		at_index = i;
		
		for (j=i + 1; j < arr_size; ++j) {
			if (arr[j] < arr[at_index]) {
				at_index = j;
			}
		}

		//  not moving  elements from i to at_index instead just swaping elements
		// for (j=at_index; j >= i; j--) {
		//	arr[j] = arr[j-1];
		//}
		tmp = arr[at_index]; 
		arr[at_index] = arr[i];
		arr[i] = tmp;
	}
}

