#pragma once
#include "AnotherFunc.hpp"

int const sort_count = 16;

std::vector <std::string> get_sorts_table_origin();

int get_number_of_sort_by_name(std::string name);

void start_right_sort(std::vector<int>* array, std::string answer);

// -> PANCAKE SORT ALGORITHM (16)
void vector_reverse(std::vector<int>* array, int end);
int find_max(std::vector<int>* array, int end);
void pancake_sort(std::vector<int>* array);

// -> COCKTAIL SORT ALGORITHM (15)
void cocktail_sort(std::vector<int>* array);

// -> COMB SORT ALGORITHM (14)
void comb_sort(std::vector<int>* array);

// -> ODD - EVEN SORT ALGORITHM (13)
void odd_even_sort(std::vector<int>* array);

// -> HEAP SORT ALGORITHM (12)
void heapify(std::vector<int>* array, int n, int i);
void heap_sort(std::vector<int>* array);

// -> PIGEONHOLE SORT ALGORITHM (11)
void pigeonhole_sort(std::vector<int>* array);

// -> STOOGE SORT ALGORITHM (10)
void stooge_sort(std::vector<int>* array, int l, int h);

// -> RADIX SORT ALGORITHM (9)
void radix_count_sort(std::vector<int>* array, int exp);
void radix_sort(std::vector<int>* array);

// -> QUICK SORT ALGORITHM (8)
int partition(std::vector<int>* array, int low, int high);
void quick_sort(std::vector<int>* array, int low, int high);

// -> MERGE SORT ALGORITHM (7)
void merge_sort(std::vector<int>* array, int const begin, int const end);

// -> COUNTING SORT ALGORITHM (6)
void count_sort(std::vector<int>* array);

// -> GNOME SORT ALGORITHM (5)
void gnome_sort(std::vector<int>* array);

// -> SHELL SORT ALGORITHM (4)
void shell_sort(std::vector<int>* array);

// -> SELECTION SORT ALGORITHM (3)
void selection_sort(std::vector<int>* array);

// -> INSERTION SORT ALGORITHM (2)
void insertion_sort(std::vector<int>* array);

// -> BUBBLE SORT ALGORITHM (1)
void bubble_sort(std::vector<int>* array);