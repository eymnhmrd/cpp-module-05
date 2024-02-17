#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("burocrat")
{
    this->grade = 1;
    std::cout << "bureaucrat created : " << this->name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
    std::cout << "bureaucrat created : " << this->name << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "bureaucrat deleted : " << this->name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name) 
{
    std::cout << "bureaucrat created : " << this->name << std::endl;
    this->grade = obj.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
        this->~Bureaucrat();
        new (this) Bureaucrat(obj);
    }
    return (*this);
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void    Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--; 
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high exception";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low exception";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}
