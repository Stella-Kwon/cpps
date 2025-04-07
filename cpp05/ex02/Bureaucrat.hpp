#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

  // Getters
  std::string getName() const;
  int getGrade() const;

  void setGrade(const int &grade);

  // Grade modification
  void incrementGrade();
  void decrementGrade();

  void signForm(AForm &form);
  void executeForm(AForm const &form);
  // Exception classes
  class GradeTooHighException : public std::exception {
  public:
    GradeTooHighException() = default;
    virtual const char *what() const noexcept override;
  };

  class GradeTooLowException : public std::exception {
  public:
    GradeTooLowException() = default;
    virtual const char *what() const noexcept override;
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif