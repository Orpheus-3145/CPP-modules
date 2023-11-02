/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:04:19 by fra           #+#    #+#                 */
/*   Updated: 2023/10/09 15:28:11 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal 
{
	public:
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const& );
		virtual ~WrongAnimal( void );
		void				setType( std::string& );
		std::string const&	getType( void ) const ;
		virtual void		makeSound( void ) const ;
		WrongAnimal& 		operator=( WrongAnimal const& );

	protected:
		std::string _type;
};

#endif