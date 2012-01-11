#include "../source/transform_if.hpp"

#include <vector>
#include <algorithm>
#include <iterator>

namespace
{
}


void test_transform_if()
{
	int items = 0;
	std::vector<int> source_data;
	std::generate_n(std::back_inserter(source_data), 10, [&items]() { return items++; });
	// source_data <- 0 1 2 3 4 5 6 7 8 9

	std::vector<int> result_a;
	stdextra::transform_if(source_data.begin(), source_data.end(), std::back_inserter(result_a), [](int& i) { return i % 2 == 0; }, [](int& i) { return i * 2; });
	// result_a <- 0 4 8 12 16

	struct Doubler
	{
		int operator()(int& i) { return i * 2; }
	};
	struct OddOnly
	{
		bool operator()(int& i) { return (i & 1) == 1; }
	};
	std::vector<int> result_b;
	stdextra::transform_if(source_data.begin(), source_data.end(), std::back_inserter(result_b), OddOnly(), Doubler());
	// result_b <- 2 6 10 14 18

	std::vector<int> result_c;
	stdextra::transform_if(source_data.begin(), source_data.end(), source_data.begin(), std::back_inserter(result_c), 
		[](int& i, int& j) { return i == j; }, 
		[](int& i, int& j) { return i + j; });
	// result_c <- 0 2 4 6 8 10 12 14 16 18
}
