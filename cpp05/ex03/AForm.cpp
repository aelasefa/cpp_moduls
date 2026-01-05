#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute)
	: name(name),
	isSigned(false),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute),
	target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();

	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name),
	isSigned(other.isSigned),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute),
    target(other.target)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;

	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const
{
	return this->name;
}

const std::string &AForm::getTarget() const
{
    return this->target;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return  this->gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->gradeToSign)
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw AFormNotSignedException();

    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::AFormNotSignedException::what() const throw()
{
    return "AForm is not signed, cannot execute";
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "AForm " << f.getName()
		<< ", signed: " << (f.getIsSigned() ? "true" : "false")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute();

	return out;
}

