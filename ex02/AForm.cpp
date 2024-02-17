#include "Form.hpp"

Form::Form() : name("form"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "Form created : " << this->name << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : name(name), isSigned(false), gradeToSign(gradeSign), gradeToExecute(gradeExec)
{
    std::cout << "Form created : " << this->name << std::endl;
    if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
    else if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& obj) : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute)
{
    std::cout << "Form created : " << this->name << std::endl;
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        this->~Form();
        new (this) Form(obj);
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form deleted : " << this->name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high exception";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low exception";
}

std::string Form::getName() const
{
    return this->name;
}

bool    Form::getIsSigned() const
{
    return this->isSigned;
}

int     Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int     Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form name : " << obj.getName() << std::endl;
    os << "Form is signed : " << obj.getIsSigned() << std::endl;
    os << "Form grade to sign : " << obj.getGradeToSign() << std::endl;
    os << "Form grade to execute : " << obj.getGradeToExecute() << std::endl;
    return os;
}

void    Form::beSigned(Bureaucrat& obj)
{
    if (obj.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw Form::GradeTooLowException();
}
