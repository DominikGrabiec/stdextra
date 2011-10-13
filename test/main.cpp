#include "../source/transform_if.hpp"

#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	int items = 0;
	std::vector<int> a;
	std::generate_n(std::back_inserter(a), 10, [&items]() { return items++; });

	std::vector<int> b;
	stdextra::transform_if(a.begin(), a.end(), std::back_inserter(b), [](int& i) { return i % 2 == 0; }, [](int& i) { return i * 2; });

	std::vector<int> c;
	stdextra::transform_if(a.begin(), a.end(), a.begin(), std::back_inserter(c), [](int& i, int& j) { return i == j; }, [](int& i, int& j) { return i + j; });

	return 0;
}