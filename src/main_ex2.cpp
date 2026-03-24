#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

size_t quick_sort_partition(std::vector<int> & vec, size_t left, size_t right);
//place pivot
void quick_sort(std::vector<int> & vec, size_t const left, size_t const right);
//tab des 2 coté
void quick_sort(std::vector<int> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}
//tab général
void merge_sort_merge(std::vector<int> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<int> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<int> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}