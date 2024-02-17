#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy", 72, 45)
{
    std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy", 72, 45)
{
    this->target = target;
    std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj)
{
    std::cout << "RobotomyRequestForm created" << std::endl;
    this->target = obj.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
        this->~RobotomyRequestForm();
        new (this) RobotomyRequestForm(obj);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm deleted" << std::endl;
}

