#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string &name, const int grade_to_sign,
       const int grade_to_execute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  void beSigned(const Bureaucrat &bureaucrat);

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  // pure virtual funtion that will make the class abstract class.
  virtual void execute(Bureaucrat const &executor) const = 0;
  //this should be const as well as it will be called in the execute function()const;
  void validationTarget(Bureaucrat const &executor) const;

  class NotsignedException : public std::exception{
    public :
      virtual const char *what() const noexcept override {
        return "Not signed Form";
      }
  };

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

std::ostream &operator<<(std::ostream &out, const AForm &AForm); 