#pragma once
#include "AnotherFunc.hpp"

int const shuffle_count = 5;

struct Shuffle
{
	int times_shuffling, type_of_shuffle;
	int data_for_shuffle[5];
};

// ---------------- help functions
Shuffle generate_shuffle(bool start);
void start_shuffle(std::vector<int>* array, Shuffle shuffler);

void random_shuffle_vector(std::vector<int>* array, bool draw);
void reverse_random_shuffle_vector(std::vector<int>* array);
void vector_reverse(std::vector<int>* array);

// - extra edit vector
void custom_swap_shuffle_vector(std::vector<int>* array, int start, int end, int step, int x, int plus);
void custom_vector_reverse(std::vector<int>* array, int from, int to, int how_much, int step);
