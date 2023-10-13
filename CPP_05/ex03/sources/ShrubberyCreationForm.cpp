/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 22:09:02 by fra           #+#    #+#                 */
/*   Updated: 2023/10/13 20:47:58 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

brt::forms::ShrubberyCreationForm& brt::forms::ShrubberyCreationForm::operator=(brt::forms::ShrubberyCreationForm const& other) throw()
{
	if (this != &other)
	{
		this->_target = other.getTarget();
		*this = other;
	}
	return (*this);
}

std::string const&	brt::forms::ShrubberyCreationForm::getTarget( void ) const throw()
{
	return (this->_target);
}

void 	brt::forms::ShrubberyCreationForm::execute( void ) const throw(brt::GenericException)
{
    std::string     fileName = this->_target + "_shrubbery";
    std::fstream    ofile;

	ofile.open(fileName.c_str(), std::ios::out);
	if (ofile.is_open() == false)
		throw std::runtime_error("File could not be opened");
	ofile << "     _ _,---._ " << std::endl;
	ofile << "   ,-','       `-.___ " << std::endl;
	ofile << "  /-;'               `._ " << std::endl;
	ofile << " /\\/          ._   _,'o \\ " << std::endl;
	ofile << "( /\\       _,--'\\,','\"`. ) " << std::endl;
	ofile << " |\\      ,'o     \\'    //\\ " << std::endl;
	ofile << " |      \\        /   ,--'\"\"`-. " << std::endl;
	ofile << " :       \\_    _/ ,-'         `-._ " << std::endl;
	ofile << "  \\        `--'  /                ) " << std::endl;
	ofile << "   `.  \\`._    ,'     ________,',' " << std::endl;
	ofile << "     .--`     ,'  ,--` __\\___,;' " << std::endl;
	ofile << "      \\`.,-- ,' ,`_)--'  /`.,' " << std::endl;
	ofile << "       \\( ;  | | )      (`-/ " << std::endl;
	ofile << "         `--'| |)       |-/ " << std::endl;
	ofile << "           | | |        | | " << std::endl;
	ofile << "           | | |,.,-.   | |_ " << std::endl;
	ofile << "           | `./ /   )---`  ) " << std::endl;
	ofile << "          _|  /    ,',   ,-' " << std::endl;
	ofile << "         ,'|_(    /-<._,' |--, " << std::endl;
	ofile << "         |    `--'---.     \\/ \\ " << std::endl;
	ofile << "         |          / \\    /\\  \\ " << std::endl;
	ofile << "       ,-^---._     |  \\  /  \\  \\ " << std::endl;
	ofile << "    ,-'        \\----'   \\/    \\--`. " << std::endl;
	ofile << "   /            \\              \\   \\ " << std::endl;
	ofile.close();
}

brt::AForm* brt::forms::ShrubberyCreationForm::ShrubberyCreationForm::newInstance( std::string const& target)
{
	return (new brt::forms::ShrubberyCreationForm(target));
}