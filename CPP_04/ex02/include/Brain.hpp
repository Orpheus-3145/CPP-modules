/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 16:39:03 by fra           #+#    #+#                 */
/*   Updated: 2023/10/10 00:17:21 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
	public:
		Brain( void );
		Brain( std::string* );
		Brain( Brain const& );
		~Brain( void );
		Brain& 				operator=( Brain const& );
		std::string const*	getIdeas( void ) const ;
		void				setIdeas( std::string const* );
		void				printIdeas( void ) const ;

	private:
		std::string _ideas[100];
};

#endif