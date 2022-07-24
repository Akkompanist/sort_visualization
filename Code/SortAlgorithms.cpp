#include "SortAlgorithms.hpp"

std::vector <std::string> get_sorts_table_origin() {
	return { "Bubble",		"Insertion",	"Gnome",		"Selection",
			 "Odd-Even",	"Count",		"Pigeonhole",	"Radix", 
			 "Comb",		"Shell",		"Merge",		"Quick",
			 "Pancake",		"Cocktail",		"Heap",			"Stooge" };
}

int get_number_of_sort_by_name(std::string name) {
	if		(name == "Bubble")		return  1;
	else if (name == "Insertion")	return  2;
	else if (name == "Selection")	return  3;
	else if (name == "Shell")		return  4;
	else if (name == "Gnome")		return  5;
	else if (name == "Count")		return  6;
	else if (name == "Merge")		return  7;
	else if (name == "Quick")		return  8;
	else if (name == "Radix")		return  9;
	else if (name == "Stooge")		return 10;
	else if (name == "Pigeonhole")	return 11;
	else if (name == "Heap")		return 12;
	else if (name == "Odd-Even")	return 13;
	else if (name == "Comb")		return 14;
	else if (name == "Cocktail")	return 15;
	else if (name == "Pancake")	return 16;
	else								exit(0);
}

void start_right_sort(std::vector<int>* array, std::string answer) {
	switch (get_number_of_sort_by_name(answer)) {
	case 1:
		bubble_sort(array);
		break;
	case 2:
		insertion_sort(array);
		break;
	case 3:
		selection_sort(array);
		break;
	case 4:
		shell_sort(array);
		break;
	case 5:
		gnome_sort(array);
		break;
	case 6:
		count_sort(array);
		break;
	case 7:
		merge_sort(array, 0, (*array).size() - 1);
		break;
	case 8:
		quick_sort(array, 0, (*array).size() - 1);
		break;
	case 9:
		radix_sort(array);
		break;
	case 10:
		stooge_sort(array, 0, (*array).size() - 1);
		break;
	case 11:
		pigeonhole_sort(array);
		break;
	case 12:
		heap_sort(array);
		break;
	case 13:
		odd_even_sort(array);
		break;
	case 14:
		comb_sort(array);
		break;
	case 15:
		cocktail_sort(array);
		break;
	case 16:
		pancake_sort(array);
		break;
	default:
		exit(-1);
	}
}

// -> PANCAKE SORT ALGORITHM 
void vector_reverse(std::vector<int>* array, int end) {
	int start = 0;

	while (start < end) {
		drawing(array, start, start, end);

		swap(&(*array)[end], &(*array)[start]);

		start++;
		end--;
	}
}

int find_max(std::vector<int>* array, int end) {
	int mi = 0, i;
	for (i = 1; i < end; i++)
		if ((*array)[i] > (*array)[mi])
			mi = i;
	return mi;
}

void pancake_sort(std::vector<int>* array) {
	// Start from the complete 
	// array and one by one 
	// reduce current size 
	// by one 
	for (int curr_size = (*array).size(); curr_size > 1; curr_size--) {
		// Find index of the 
		// maximum element in 
		// arr[0..curr_size-1] 
		int mi = find_max(array, curr_size);

		// Move the maximum 
		// element to end of 
		// current array if 
		// it's not already 
		// at the end 
		if (mi != curr_size - 1) {
			// To move at the end, 
			// first move maximum 
			// number to beginning 
			vector_reverse(array, mi);

			// Now move the maximum 
			// number to end by 
			// reversing current array 
			vector_reverse(array, curr_size - 1);
		}
	}
}

// -> COCKTAIL SORT ALGORITHM 
void cocktail_sort(std::vector<int>* array) {
	bool swapped = true;
	int start = 0;
	int end = (*array).size() - 1;

	while (swapped) {
		// reset the swapped flag on entering
		// the loop, because it might be true from
		// a previous iteration.
		swapped = false;

		// loop from left to right same as
		// the bubble sort
		for (int i = start; i < end; ++i) {
			drawing(array, i, i, i + 1);
			if ((*array)[i] > (*array)[i + 1]) {
				swap(&(*array)[i], &(*array)[i + 1]);
				swapped = true;
			}
		}

		// if nothing moved, then array is sorted.
		if (!swapped) {
			break;
		}

		// otherwise, reset the swapped flag so that it
		// can be used in the next stage
		swapped = false;

		// move the end point back by one, because
		// item at the end is in its rightful spot
		--end;

		// from right to left, doing the
		// same comparison as in the previous stage
		for (int i = end - 1; i >= start; --i) {
			drawing(array, i, i, i + 1);
			if ((*array)[i] > (*array)[i + 1]) {
				swap(&(*array)[i], &(*array)[i + 1]);
				swapped = true;
			}
		}

		// increase the starting point, because
		// the last stage would have moved the next
		// smallest number to its rightful spot.
		++start;
	}
}

// -> COMB SORT ALGORITHM 
void comb_sort(std::vector<int>* array) {
	// Initialize gap
	int gap = (*array).size();

	// Initialize swapped as true to make sure that
	// loop runs
	bool swapped = true;

	// Keep running while gap is more than 1 and last
	// iteration caused a swap
	while (gap != 1 || swapped == true) {
		// Find next gap
		gap = (gap * 10) / 13;
		if (gap < 1) {
			gap = 1;
		}

		// Initialize swapped as false so that we can
		// check if swap happened or not
		swapped = false;

		// Compare all elements with current gap
		for (int i = 0; i < (*array).size() - gap; i++) {
			drawing(array, i, i, i + gap);

			if ((*array)[i] > (*array)[i + gap]) {
				drawing(array, i, i, i + gap);

				swap(&(*array)[i], &(*array)[i + gap]);
				swapped = true;
			}
		}
	}
}

// -> ODD - EVEN SORT ALGORITHM
void odd_even_sort(std::vector<int>* array)
{
	bool isSorted = false; // Initially array is unsorted

	while (!isSorted)
	{
		isSorted = true;

		// Perform Bubble sort on odd indexed element
		for (int i = 1, j = 0; i <= (*array).size() - 2 && j <= (*array).size() - 2; i = i + 2, j = j + 2)
		{
			drawing(array, i, i, i+1);

			if ((*array)[i] > (*array)[i + 1])
			{
				drawing(array, i, i, i + 1);

				swap(&(*array)[i], &(*array)[i + 1]);
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed element
		for (int i = 0; i <= (*array).size() - 2; i = i + 2)
		{
			drawing(array, i, i, i + 1);

			if ((*array)[i] > (*array)[i + 1])
			{
				drawing(array, i, i, i + 1);

				swap(&(*array)[i], &(*array)[i + 1]);
				isSorted = false;
			}
		}
	}

	return;
}

// -> HEAP SORT ALGORITHM

// To heapify a subtree rooted with node i
// which is an index in arr[]. 
// n is size of heap
void heapify(std::vector<int>* array, int n, int i) {

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l <  n && (*array)[l] > (*array)[largest]) {
		largest = l;
	}

	// If right child is larger than largest 
	// so far
	if (r < n && (*array)[r] > (*array)[largest]) {
		largest = r;
	}

	// If largest is not root
	if (largest != i) {
		drawing(array, n, i, largest);

		swap(&(*array)[i], &(*array)[largest]);

		// Recursively heapify the affected 
		// sub-tree
		heapify(array, n, largest);
	}
}

// Main function to do heap sort
void heap_sort(std::vector<int>* array) {

	// Build heap (rearrange array)
	for (int i = (*array).size() / 2 - 1; i >= 0; i--) {
		heapify(array, (*array).size(), i);
	}

	// One by one extract an element 
	// from heap
	for (int i = (*array).size() - 1; i > 0; i--) {

		// Move current root to end
		drawing(array, i, 0, i);
		swap(&(*array)[0], &(*array)[i]);

		// call max heapify on the reduced heap
		heapify(array, i, 0);
	}
}

// -> PIGEONHOLE SORT ALGORITHM
void pigeonhole_sort(std::vector<int>* array) {
	// Find minimum and maximum values in arr[]
	int min = (*array)[0];
	int max = (*array)[0];
	for (int i = 1; i < (*array).size(); i++)
	{
		drawing(array, i, i, -1);

		if ((*array)[i] < min) {
			min = (*array)[i];
		}
		if ((*array)[i] > max) {
			max = (*array)[i];
		}
	}
	int const range = max - min + 1; // Find range

	// Create an array of vectors. Size of array
	// range. Each vector represents a hole that
	// is going to contain matching elements.
	std::vector<int>* holes = new std::vector<int>[range];

	// Traverse through input array and put every
	// element in its respective hole
	for (int i = 0; i < (*array).size(); i++) {
		drawing(array, i, i, -1);

		holes[(*array)[i] - min].push_back((*array)[i]);
	}
	// Traverse through all holes one by one. For
	// every hole, take its elements and put in
	// array.
	int index = 0;  // index in sorted array
	for (int i = 0; i < range; i++)
	{
		std::vector<int>::iterator it;
		for (it = holes[i].begin(); it != holes[i].end(); ++it) {
			drawing(array, index, index, -1);

			(*array)[index++] = *it;
		}
	}
}

// -> STOOGE SORT ALGORITHM
void stooge_sort(std::vector<int>* array, int l, int h) {
	if (l >= h) { return; }

	drawing(array, l, l, h);

	// If first element is smaller than last,
	// swap them
	if ((*array)[l] > (*array)[h]) {
		swap(&(*array)[l], &(*array)[h]);
	}
	// If there are more than 2 elements in
	// the array
	if (h - l + 1 > 2) {
		int t = (h - l + 1) / 3;

		// Recursively sort first 2/3 elements
		stooge_sort(array, l, h - t);

		// Recursively sort last 2/3 elements
		stooge_sort(array, l + t, h);

		// Recursively sort first 2/3 elements
		// again to confirm
		stooge_sort(array, l, h - t);
	}
}

// -> RADIX SORT ALGORITHM
void radix_count_sort(std::vector<int>* array, int exp) {
	std::vector<int> output((*array).size()); // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < (*array).size(); i++) {
		drawing(array, i, i, -1);
		count[((*array)[i] / exp) % 10]++;
	}
	/* Change count[i] so that count[i] now contains actual
	 position of this digit in output[] */
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	// Build the output array
	for (i = (*array).size() - 1; i >= 0; i--) {
		drawing(array, i, i, -1);

		output[count[((*array)[i] / exp) % 10] - 1] = (*array)[i];
		count[((*array)[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < (*array).size(); i++) {
		drawing(array, i, i, -1);

		(*array)[i] = output[i];
	}
}

void radix_sort(std::vector<int>* array) {
	// Find the maximum number to know number of digits
	int max = (*array)[find_index_of_max(*array)];

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; max / exp > 0; exp *= 10)
		radix_count_sort(array, exp);
}

// -> QUICK SORT ALGORITHM

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(std::vector<int>* array, int low, int high) {
	int pivot = (*array)[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) {
		drawing(array, i, i, j);

		// If current element is smaller than the pivot
		if ((*array)[j] < pivot) {
			drawing(array, j, i, j);

			i++; // increment index of smaller element
			swap(&(*array)[i], &(*array)[j]);
		}
	}
	drawing(array, i, i + 1, high);

	swap(&(*array)[i + 1], &(*array)[high]);

	return (i + 1);
}

void quick_sort(std::vector<int>* array, int low, int high) {
	if (low < high) {

		int part = partition(array, low, high);

		// Separately sort elements before
		// partition and after partition
		quick_sort(array, low, part - 1);
		quick_sort(array, part + 1, high);
	}
}

// -> MERGE SORT ALGORITHM
void merge_sort(std::vector<int>* array, int const begin, int const end) {
	if (begin >= end) { return; }

	auto mid = begin + (end - begin) / 2;

	merge_sort(array, begin, mid);
	merge_sort(array, mid + 1, end);

	// Merges two subarrays of array[].
	// First subarray is array[begin..mid]
	// Second subarray is array[mid+1..end]

	int const first_array_len = mid - begin + 1;
	int const second_array_len = end - mid;

	// Create temp arrays
	std::vector<int> left_array(first_array_len), right_array(second_array_len);

	// Copy data to temp arrays 
	for (int i = 0; i < first_array_len; i++) {
		drawing(array, i, begin + i, -1);

		left_array[i] = (*array)[begin + i];
	}
	for (int j = 0; j < second_array_len; j++) {
		drawing(array, j, mid + 1 + j, -1);

		right_array[j] = (*array)[mid + 1 + j];
	}

	int index_of_first_array = 0; // Initial index of first sub-array
	int index_of_second_array = 0;  // Initial index of second sub-array
	int index_of_main_array = begin;  // Initial index of merged array

	// Merge the temp arrays back into array
	while (index_of_first_array < first_array_len && index_of_second_array < second_array_len) {
		if (left_array[index_of_first_array] <= right_array[index_of_second_array]) {
			drawing(array, index_of_main_array, index_of_main_array, -1);

			(*array)[index_of_main_array] = left_array[index_of_first_array];
			index_of_first_array++;
		}
		else {
			drawing(array, index_of_main_array, index_of_main_array, -1);

			(*array)[index_of_main_array] = right_array[index_of_second_array];
			index_of_second_array++;
		}
		index_of_main_array++;
	}

	// Copy the remaining elements of
	// left_array, if there are any
	while (index_of_first_array < first_array_len) {
		drawing(array, index_of_main_array, index_of_main_array, -1);

		(*array)[index_of_main_array] = left_array[index_of_first_array];
		index_of_first_array++;
		index_of_main_array++;
	}
	// Copy the remaining elements of
	// right_array, if there are any
	while (index_of_second_array < second_array_len) {
		drawing(array, index_of_main_array, index_of_main_array, -1);

		(*array)[index_of_main_array] = right_array[index_of_second_array];
		index_of_second_array++;
		index_of_main_array++;
	}
}

// -> COUNTING SORT ALGORITHM
void count_sort(std::vector<int>* array) {
	int max = *std::max_element((*array).begin(), (*array).end());
	int min = *std::min_element((*array).begin(), (*array).end());
	int range = max - min + 1;
	int i;

	std::vector<int> count(range), output((*array).size());

	// Store the count of each element
	for (i = 0; i < (*array).size(); i++) {
		drawing(array, i, i, -1);

		count[(*array)[i] - min]++;
	}
	// Store the cummulative count of each array
	for (i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}
	// Find the index of each element of the original array in count array, and
	// place the elements in output array
	for (i = (*array).size() - 1; i >= 0; i--) {
		drawing(array, i, i, -1);

		output[count[(*array)[i] - min] - 1] = (*array)[i];
		count[(*array)[i] - min]--;
	}
	// Copy the sorted elements into original array
	for (i = 0; i < (*array).size(); i++) {
		drawing(array, i, i, -1);

		(*array)[i] = output[i];
	}
}

// -> GNOME SORT ALGORITHM
void gnome_sort(std::vector<int>* array) {
	int i = 0;
	while (i < (*array).size()) {
		drawing(array, i, i, -1);

		if (i == 0) {
			i++;
		}
		if ((*array)[i] >= (*array)[i - 1]) {
			i++;
		}
		else {
			drawing(array, i, i, i - 1);

			swap(&(*array)[i], &(*array)[i - 1]);
			i--;
		}
	}
}

// -> SHELL SORT ALGORITHM
void shell_sort(std::vector<int>* array) {
	// Start with a big gap, then reduce the gap
	for (int gap = (*array).size() / 2; gap > 0; gap /= 2)
	{
		/* Do a gapped insertion sort for this gap size.
		 The first gap elements a[0..gap-1] are already in gapped order
		 keep adding one more element until the entire array is
		 gap sorted */
		for (int i = gap; i < (*array).size(); i += 1) {
			drawing(array, i, i, -1);

			/* add a[i] to the elements that have been gap sorted
			 save a[i] in temp and make a hole at position i */
			int temp = (*array)[i];
			/* shift earlier gap-sorted elements up until the correct
			 location for a[i] is found */
			int j;
			for (j = i; j >= gap && (*array)[j - gap] > temp; j -= gap) {
				drawing(array, j, j - gap, -1);

				(*array)[j] = (*array)[j - gap];
			}

			//  put temp (the original a[i]) in its correct location
			(*array)[j] = temp;
		}
	}
}

// -> SELECTION SORT ALGORITHM
void selection_sort(std::vector<int>* array) {
	int i, j, min_index;

	/* One by one move boundary of
	 unsorted subarray */
	for (i = 0; i < (*array).size() - 1; i++) {
		/* Find the minimum element in
		 unsorted array */
		min_index = i;


		for (j = i + 1; j < (*array).size(); j++) {
			drawing(array, j, j, min_index);


			if ((*array)[j] < (*array)[min_index]) {
				min_index = j;
			}
		}
		drawing(array, i, i, min_index);
		/* Swap the found minimum element
		 with the first element */
		swap(&(*array)[min_index], &(*array)[i]);
	}
}

// -> INSERTION SORT ALGORITHM
void insertion_sort(std::vector<int>* array) {
	int i, key, j;
	for (i = 1; i < (*array).size(); i++)
	{
		key = (*array)[i];
		j = i - 1;

		/* Move elements of arr[0..i-1],
		 that are greater than key, to one
		 position ahead of their
		 current position */
		while (j >= 0 && (*array)[j] > key)
		{
			(*array)[j + 1] = (*array)[j];

			drawing(array, j, j, j + 1);

			j--;
		}
		(*array)[j + 1] = key;

	}
}

// -> BUBBLE SORT ALGORITHM
void bubble_sort(std::vector<int>* array) {
	for (int i = 0; i < (*array).size(); i++) {
		for (int j = 0; j < (*array).size() - 1 - i; j++) {
			drawing(array, j, j, -1);

			if ((*array)[j] > (*array)[j + 1]) {
				drawing(array, j, j, j + 1);

				swap(&(*array)[j + 1], &(*array)[j]);
			}
		}
	}
}
