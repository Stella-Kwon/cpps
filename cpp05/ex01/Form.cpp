#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name(""), is_signed(false), grade_to_sign(150), grade_to_execute(150) {
  std::cout << "Default constructor called" << std::endl;
  std::cout << "Form " << name << " is created." << std::endl;
}

Form::Form(const std::string &name, const int grade_to_sign, const int grade_to_execute):
name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
  std::cout << "Constructor called" << std::endl;
  if (grade_to_sign < 1 || grade_to_execute < 1)
    throw GradeTooHighException();
  if (grade_to_sign > 150 || grade_to_execute > 150)
    throw GradeTooLowException();
  std::cout << "Form " << name << " is created." << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
  std::cout << "Copy constructor called" << std::endl;
  std::cout << "Form " << name << " is copied." << std::endl;
  //   *this = other; // we can use the assignment operator to copy the grade
}

Form &Form::operator=(const Form &other){
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form() {
  std::cout << "Destructor called" << std::endl;
  std::cout << "Form " << name << " is destroyed." << std::endl;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= grade_to_sign)
    {
        is_signed = true;
    }
    else {
        throw GradeTooLowException();
    }
}

std::string Form::getName() const
{
    return std::string();
}

bool Form::getIsSigned() const
{
    return is_signed;
}

int Form::getGradeToSign() const
{
    return grade_to_sign;
}

int Form::getGradeToExecute() const
{
    return grade_to_execute;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form.getName()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}
