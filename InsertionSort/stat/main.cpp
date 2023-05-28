#include <iostream>
#include <vector>
#include <string>

int main (int argc, char *argv[])
{
    int n_test = 0;
    std::string dump;
    double time = 0;
    double total_time = 0;
    while (true)
    {
	if (!(std::cin >> dump))
	    break;
	std::cin >> time;
	total_time += time;
	n_test++;
    }
    std::cout << "average time: " << total_time / n_test << std::endl;

    // std::cin >> n_test >> n_ele;
    // std::vector<double> time(n_test);
    // std::vector<double>::iterator time_begin = time.begin();
    // for (std::vector<double>::iterator time_iterator = time_begin;
    // 	 time_iterator != time.end();
    // 	 ++time_iterator)
    // 	std::cin >> *time_iterator;
    // for (std::vector<double>::iterator time_iterator = time_begin;
    // 	 time_iterator != time.end();
    // 	 ++time_iterator)
    // 	std::cout << *time_iterator << "\t";
    // std::cout << std::endl;
    return 0;
};
