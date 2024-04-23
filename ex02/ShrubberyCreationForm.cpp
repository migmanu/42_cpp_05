#include "ShrubberyCreationForm.hpp"

static int SignLevel = 145;
static int ExecLevel = 137;

void	writeTree(std::string name)
{
	name = name + "ShrubberyForm.txt";
	std::ofstream file;
	file.open(name.c_str());
	file << "                                                         ." << std::endl;
	file << "                                              .         ;  " << std::endl;
	file << "                                              .         ;  " << std::endl;
	file << "                   ,           ,                :;%  %;   " << std::endl;
	file << "                    :         ;                   :;%;'     .,   " << std::endl;
	file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
	file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
	file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
	file << "                            ;@%. :@%%  %@@%;       " << std::endl;
	file << "                              %@bd%%%bd%%:;     " << std::endl;
	file << "                                #@%%%%%:;;" << std::endl;
	file << "                                %@@%%%::;" << std::endl;
	file << "                                %@@@%(o);  . '         " << std::endl;
	file << "                                %@@@o%;:(.,'         " << std::endl;
	file << "                            `.. %@@@o%::;         " << std::endl;
	file << "                               `)@@@o%::;         " << std::endl;
	file << "                                %@@(o)::;        " << std::endl;
	file << "                               .%@@@@%::;         " << std::endl;
	file << "                               ;%@@@@%::;.          " << std::endl;
	file << "                              ;%@@@@%%:;;;. " << std::endl;
	file << "                          ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;

	file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", SignLevel, ExecLevel), _target("No target")
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", SignLevel, ExecLevel), _target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm for " << this->_target << " parameterized constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm("ShrubberyCreationForm", SignLevel, ExecLevel), _target(src.getTarget())
{
	std::cout << GREEN << "ShrubberyCreationForm for " << this->_target << " copy constructor called" << RESET << std::endl;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED << "ShrubberyCreationForm for " << this->_target << " default destructor called" << RESET << std::endl;
	return;
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqSignGrade)
	{
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	if (this->_signed == true)
	{
		std::cout << "ShrubberyCreationForm is already signed!" << std::endl;
		return;
	}
	std::cout << "ShrubberyCreationForm signed by " << agent.getName() << std::endl;
	this->_signed = true;
	return;
}

void ShrubberyCreationForm::signForm(const Bureaucrat &agent)
{
	if (agent.getGrade() > this->_reqExecGrade)
	{
		std::cout << "ShrubberyCreationForm could not be executed: agent " << agent.getName()
				  << " has no execution privileges" << std::endl;
		return;
	}
	if (this->_signed == false)
	{
		std::cout << "ShrubberyCreationForm could not be executed: not signed" << std::endl;
		return;
	}
	writeTree(this->getTarget());
	return;
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &rhs)
{
	o << rhs.getName();
	o << ", form required sign grade ";
	o << rhs.getReqSignGrade();
	o << ", required execution grade ";
	o << rhs.getReqExecGrade();
	o << std::endl;
	return o;
}
