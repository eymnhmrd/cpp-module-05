#ifndef BUREAUCRATE_HPP
#define BUREAUCRATE_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& obj);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& obj);
        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const _NOEXCEPT;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const _NOEXCEPT;
        };
        void    signForm(Form& obj);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif

