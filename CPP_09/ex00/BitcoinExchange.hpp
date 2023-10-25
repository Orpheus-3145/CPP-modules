/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 21:40:30 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 17:13:01 by fra           ########   odam.nl         */
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
		BitcoinExchange( std::string, std::string ) noexcept;
		BitcoinExchange( BitcoinExchange const& ) noexcept;
		~BitcoinExchange( void ) noexcept {}
		BitcoinExchange& operator=(BitcoinExchange const&) noexcept;

		static time_t	getTimestamp(std::string, bool);
		static float	getValue(std::string, bool);

		data_t const		getDatabase( void ) const noexcept;
		void				setDatabase( data_t const& ) noexcept;
		std::string const&	getDbPath( void ) const noexcept;
		void				setDbPath( std::string const& ) noexcept;
		std::string const&	getInputFile( void ) const noexcept;
		void				setInputFile( std::string const& ) noexcept;

		void	fillData( void ) noexcept;
		void	readInput( void ) const noexcept;

		float	_getAmountByDate( time_t ) const noexcept;
		void	_addNewItem( time_t, float ) noexcept;
		void	_printLine( std::string ) const ;

	private:
		data_t		_database;
		std::string	_dbPath;
		std::string	_inputFilePath;
};