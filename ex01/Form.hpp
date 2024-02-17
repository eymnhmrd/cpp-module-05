#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool    isSigned;
    const int gradeToSign;
    const int gradeToExecute;
    Form();
public:
    Form(std::string name, int gradeSign, int gradeExec);
    ~Form();
    Form(const Form& obj);
    Form& operator=(const Form& obj);
    std::string getName() const;
    bool    getIsSigned() const;
    int     getGradeToSign() const;
    int     getGradeToExecute() const;
    void    beSigned(Bureaucrat& obj);
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);


#endif