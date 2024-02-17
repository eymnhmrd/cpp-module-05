#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat a("aymn", 4);
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        // a.incrementGrade();
        // std::cout << a << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
