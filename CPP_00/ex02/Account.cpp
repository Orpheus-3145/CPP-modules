// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <iomanip>		// std::setw, std::setfill
#include <ctime>        // std::tm

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts 
		<< ";total:" << Account::_totalAmount 
		<< ";deposits:" << Account::_totalNbDeposits 
		<< ";withdrawals:" << Account::_totalNbWithdrawals 
		<< std::endl;
}


Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";created" << std::endl; 
}

Account::~Account( void )
{
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";closed" << std::endl; 
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";p_amount:" << this->_amount - deposit
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int currAmount = this->checkAmount();
	if (withdrawal <= currAmount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
	}
	else
		withdrawal = 0;

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount + withdrawal;
	if (withdrawal == 0)
		std::cout << ";withdrawal:refused" << std::endl;
	else
	{
		std::cout << ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	}
	return (withdrawal <= currAmount);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";deposits:" << this->_nbDeposits 
		<< ";withdrawals:" <<this->_nbWithdrawals 
		<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t currentTime;
    std::tm* timeInfo;

    std::time(&currentTime);
    timeInfo = std::localtime(&currentTime);
	std::cout << "[" 
			<< 1900 + timeInfo->tm_year 
			<< std::setw(2) << std::setfill('0') << timeInfo->tm_mon + 1 
			<< std::setw(2) << std::setfill('0') << timeInfo->tm_mday 
			<< "_"
			<< std::setw(2) << std::setfill('0') << timeInfo->tm_hour 
			<< std::setw(2) << std::setfill('0') << timeInfo->tm_min 
			<< std::setw(2) << std::setfill('0') << timeInfo->tm_sec 
			<< "] ";
}

Account::Account( void )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
}
