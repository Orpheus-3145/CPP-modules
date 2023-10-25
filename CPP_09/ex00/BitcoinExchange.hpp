/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 21:40:30 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 02:26:19 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
#define DATA_PATH "./data.csv"

class BitException : std::exception
{
	public:
		BitException( std::string const& msg) noexcept : std::exception() , _msg(msg) {}
		virtual const char* what() const noexcept override {return (this->_msg.c_str());}
		virtual ~BitException( void ) noexcept {}
	
	private:
		std::string _msg;
};

class BitcoinExchange
{
	typedef std::map<time_t, float> data_t;

	public:
		BitcoinExchange( void ) noexcept {}
		BitcoinExchange( std::string ) noexcept;
		BitcoinExchange( BitcoinExchange const& ) noexcept;
		~BitcoinExchange( void ) noexcept {}
		BitcoinExchange& operator=(BitcoinExchange const&) noexcept;

		static time_t	getTimestamp(std::string to_cast) noexcept;
		static float	getValue(std::string strValue) noexcept;
		static bool isDate(std::string toCheck) noexcept;
		static bool isValue(std::string toCheck) noexcept;

		data_t const		getDatabase( void ) const ;
		void				setDatabase( data_t const& );
		std::string const&	getInputFile( void ) const ;
		void				setInputFile( std::string const& );

		void	fillData(std::string file_path);
		float	getValueByDate( time_t ) const ;
		bool	checkInputFile( std::string ) const ;

		void	_addNewItem( std::string, std::string );

	private:
		data_t		_database;
		std::string	_inputFile;
};