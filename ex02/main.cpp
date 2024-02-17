#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try 
    {
        Bureaucrat a("aymn", 130);
        Form       f("form", 120, 120);

        a.signForm(f);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
