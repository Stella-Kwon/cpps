#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150) {
  std::cout << "Default construtor called" << std::endl;
  std::cout << "Bureaucrat " << name << " is created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  std::cout << "Constructor called" << std::endl;
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
  this->grade = grade;
  std::cout << "Bureaucrat " << name << " is created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade) {
  std::cout << "Copy constructor called" << std::endl;
  std::cout << "Bureaucrat " << name << " is copied." << std::endl;
  //   *this = other; // we can use the assignment operator to copy the grade
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    // Can't assign name since it's const
    // const member can only be initialized once.
    // It cannot be assigned a new value in the assignment operator
    // this is how does const member works.
    // it is supposed to be has the initial name and not change but only the
    // grade

    //  It's why library designers need to be careful about making members const
    //  - they cannot be changed after initialization, even in assignment
    //  operations.
    this->grade = other.grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Destructor called" << std::endl;
  std::cout << "Bureaucrat " << name << " is destroyed." << std::endl;
}

std::string Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::setGrade(const int &grade) {
  if (grade > 1 && grade < 150) {
    std::cout << "Grade set to " << this->grade << " to  " << grade
              << std::endl;
    this->grade = grade;
  } else if (grade < 1)
    throw GradeTooHighException();
  else
    throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
  if (grade <= 1)
    throw GradeTooHighException();
  grade--;
}

void Bureaucrat::decrementGrade() {
  if (grade >= 150)
    throw GradeTooLowException();
  grade++;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << name << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
    std::cout << name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << name << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
  return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
  return "Grade too low"; // Returns pointer to string literal (safe) : saved in
                          // static memory exsists until the program ends
}

// out of the class
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}
