#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name(""), is_signed(false), grade_to_sign(150), grade_to_execute(150) {
  std::cout << "Default constructor called" << std::endl;
  std::cout << "AForm " << name << " is created." << std::endl;
}

AForm::AForm(const std::string &name, const int grade_to_sign, const int grade_to_execute):
name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
  std::cout << "Constructor called" << std::endl;
  if (grade_to_sign < 1 || grade_to_execute < 1)
    throw GradeTooHighException();
  if (grade_to_sign > 150 || grade_to_execute > 150)
    throw GradeTooLowException();
  std::cout << "AForm " << name << " is created." << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
  std::cout << "Copy constructor called" << std::endl;
  std::cout << "AForm " << name << " is copied." << std::endl;
  //   *this = other; // we can use the assignment operator to copy the grade
}

AForm &AForm::operator=(const AForm &other){
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

AForm::~AForm() {
  std::cout << "Destructor called" << std::endl;
  std::cout << "AForm " << name << " is destroyed." << std::endl;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= grade_to_sign)
    {
        is_signed = true;
    }
    else {
        throw GradeTooLowException();
    }
}

std::string AForm::getName() const
{
    return std::string();
}

bool AForm::getIsSigned() const
{
    return is_signed;
}

int AForm::getGradeToSign() const
{
    return grade_to_sign;
}

int AForm::getGradeToExecute() const
{
    return grade_to_execute;
}

void AForm::validationTarget(Bureaucrat const &executor) const
{
  if (!is_signed)
    throw NotsignedException();
  if (executor.getGrade() > grade_to_execute)
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
    out << "AForm " << AForm.getName()
        << ", signed: " << (AForm.getIsSigned() ? "yes" : "no")
        << ", grade to sign: " << AForm.getGradeToSign()
        << ", grade to execute: " << AForm.getGradeToExecute();
    return out;
}
