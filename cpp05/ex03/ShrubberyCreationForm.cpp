/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:41:34 by mrabelo-          #+#    #+#             */
/*   Updated: 2025/11/06 14:12:14 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#define NAME "Shrubbery Creation Form"
#define GRADE_TO_SIGN 145 //defined by the subject
#define GRADE_TO_EXECUTE 137 //defined by the subject
#define TARGET "ShrubberyTargetDefault"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(TARGET)
{
	std::cout << "Shrubbery Creation Form Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(NAME, GRADE_TO_SIGN, GRADE_TO_EXECUTE), target(target)
{
	std::cout << "Shrubbery Creation Form Parameterized Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	std::cout << "Shrubbery Creation Form Copy Constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Shrubbery Creation Form Copy Assignment Operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form Destructor called" << std::endl;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream outFile;
	std::string filename = target + "_shrubbery";
	outFile.open(filename.c_str());
	outFile.open(filename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
		return;
	}

	outFile << "                                              ." << std::endl;
	outFile << "                                   .         ;  " << std::endl;
	outFile << "      .              .              ;%     ;;   " << std::endl;
	outFile << "        ,           ,                :;%  %;   " << std::endl;
	outFile << "         :         ;                   :;%;'     .,   " << std::endl;
	outFile << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	outFile << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	outFile << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	outFile << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	outFile << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	outFile << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	outFile << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	outFile << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
	outFile << "             `@%.  `;@%.      ;@@%;         " << std::endl;
	outFile << "               `@%%. `@%%    ;@@%;        " << std::endl;
	outFile << "                 ;@%. :@%%  %@@%;       " << std::endl;
	outFile << "                   %@bd%%%bd%%:;     " << std::endl;
	outFile << "                     #@%%%%%:;;" << std::endl;
	outFile << "                     %@@%%%::;" << std::endl;
	outFile << "                     %@@@%(o);  . '         " << std::endl;
	outFile << "                     %@@@o%;:(.,'         " << std::endl;
	outFile << "                 `.. %@@@o%::;         " << std::endl;
	outFile << "                    `)@@@o%::;         " << std::endl;
	outFile << "                     %@@(o)::;        " << std::endl;
	outFile << "                    .%@@@@%::;         " << std::endl;
	outFile << "                    ;%@@@@%::;.          " << std::endl;
	outFile << "                   ;%@@@@%%:;;;. " << std::endl;
	outFile << "               ...;%@@@@@%%:;;;;,.." << std::endl;

	outFile.close();
	std::cout << "Shrubbery created and written to " << filename << std::endl;
}
