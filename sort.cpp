#include <iostream>
#include <vector>
#include <stdint.h>

void quicksort(std::vector<uint32_t>& vec, uint32_t low, uint32_t high)
{
	if (low < high) {
		uint32_t i = low - 1, j;
		for (j = low; j <= high; j++) {
			if (vec[j] < vec[high]) {
				i++;
				std::swap(vec[i], vec[j]);
			}
		}
		std::swap(vec[i + 1], vec[high]);
		quicksort(vec, low, i);
		quicksort(vec, i + 2, high);
	}
}

int main() {
	std::vector<uint32_t> a = {10, 2, 12, 32, 15, 81, 0, 1};
	quicksort(a, 0, a.size() - 1);
	for (uint32_t i = 0; i < a.size(); i++) {
		std::cout << a[i] << " ";
	}
}
