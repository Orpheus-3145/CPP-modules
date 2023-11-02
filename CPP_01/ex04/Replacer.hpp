/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Replacer.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 23:41:15 by fra           #+#    #+#                 */
/*   Updated: 2023/09/29 04:07:28 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H
# define REPLACER_H
# include <iostream>
# include <filesystem>
# include <fstream>
# include <string>

class Replacer
{
    public:
        Replacer( void ) ;
        Replacer( std::string, std::string, std::string ) ;
        ~Replacer( void ) ;
        int replace( void ) const ;

    private:
        static std::string	_ext;
        std::string			_file_path;
        std::string			_old_str;
        std::string			_new_str;

        bool    _validate_input( std::string, std::string, std::string ) const ;
        void    _replace_str( std::fstream&, std::string) const ;
};

#endif