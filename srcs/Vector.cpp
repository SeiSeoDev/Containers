#include "Stack.hpp"
#include "Vector.hpp"

int main()
{
    ft::vector<int> test2(5,10);
    // std::vector<int> test(5, 10);
    test2.print();
    test2.pop_back();
    std::cout << "_______pop_back_______" << std::endl;
    test2.print();
    test2.push_back(42);
    std::cout << "_______push_back(42)_______" << std::endl;
    test2.print();
    test2.erase(test2.begin());
    std::cout << "_______erase first element_______" << std::endl;
}