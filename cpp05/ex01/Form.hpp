#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string &name, const int grade_to_sign,
       const int grade_to_execute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  void beSigned(const Bureaucrat &bureaucrat);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const noexcept override {
      return "Grade too high";
    }
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const noexcept override {
      return "Grade too low";
    }
  };

private:
  const std::string name;
  bool is_signed;
  const int grade_to_sign;
  const int grade_to_execute;
};

std::ostream &operator<<(std::ostream &out, const Form &form); 