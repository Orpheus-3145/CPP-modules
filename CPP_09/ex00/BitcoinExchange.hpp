/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 21:40:30 by fra           #+#    #+#                 */
/*   Updated: 2023/10/25 00:46:58 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

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
		BitcoinExchange( void ) noexcept;
		BitcoinExchange( BitcoinExchange const& ) noexcept;
		~BitcoinExchange( void ) noexcept;
		BitcoinExchange& operator=(BitcoinExchange const&) noexcept;

		static time_t	getTimestamp(std::string to_cast) noexcept;
		static float	getValue(std::string strValue) noexcept;
		static bool isDate(std::string toCheck) noexcept;
		static bool isValue(std::string toCheck) noexcept;

		data_t	getDatabase( void ) const ;
		void	setDatabase( data_t const& );
		void	parseDB(std::string file_path);

	private:
		data_t _database;
};