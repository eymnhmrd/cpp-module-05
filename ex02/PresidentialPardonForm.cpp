#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential", 25, 5)
{
    std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential", 25, 5)
{
    this->target = target;
    std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj)
{
    std::cout << "PresidentialPardonForm created" << std::endl;
    this->target = obj.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
    {
        this->~PresidentialPardonForm();
        new (this) PresidentialPardonForm(obj);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm deleted" << std::endl;
}

