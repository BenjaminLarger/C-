/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:29:16 by blarger           #+#    #+#             */
/*   Updated: 2024/05/29 13:04:29 by blarger          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <vector>

int Account::_totalAmount = 0;
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* UTILS */

//------------TIME
void Account::_displayTimestamp()
{
    std::time_t result = std::time(NULL);
    struct tm * timeinfo = std::localtime(&result);
    char buffer[80];

    std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
    std::cout << buffer << ' ';
}

//------------INDEX
static void    print_index(int index, bool end)
{
    std::cout << "index:" << index;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

//------------AMOUNT
static void    print_amount(int amount, bool end)
{
    std::cout << "amount:" << amount;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

static void    print_p_amount(int amount, bool end)
{
    std::cout << "p_amount:" << amount;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

//------------DEPOSIT
void	print_deposit(int deposit, bool end)
{
	std::cout << "deposit:" << deposit;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

void	print_deposits(int deposit, bool end)
{
	std::cout << "deposits:" << deposit;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

void	print_nb_deposits(int deposit, bool end)
{
	std::cout << "nb_deposits:" << deposit;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

//------------WITHDRAWAL
void	print_withdrawal(int withdrawal, bool end)
{
	std::cout << "withdrawal:" << withdrawal;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

void	print_withdrawals(int withdrawal, bool end)
{
	std::cout << "withdrawals:" << withdrawal;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

//------------ACCOUNTS
void	print_accounts(int accounts, bool end)
{
	std::cout << "accounts:" << accounts;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

//------------TOTAL
void	print_total(int accounts, bool end)
{
	std::cout << "total:" << accounts;
	if (end)
		std::cout << std::endl;
	else
		std::cout << ';';
}

/* GETTERS */

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    print_accounts(Account::_nbAccounts, false);
	print_total(Account::_totalAmount, false);
	print_deposits(Account::_totalNbDeposits, false);
	print_withdrawals(Account::_totalNbWithdrawals, true);

}

void    Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	print_index(this->_accountIndex, false);
	print_p_amount(this->_amount, false);
	print_deposit(deposit, false);

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	print_amount(this->_amount, false);
	print_nb_deposits(this->_nbDeposits, true);
}

bool    Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	print_index(this->_accountIndex, false);
	print_p_amount(this->_amount, false);

	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;

	print_withdrawal(withdrawal, false);
	print_amount(this->_amount, false);
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void    Account::displayStatus(void) const
{
	_displayTimestamp();
	print_index(this->_accountIndex, false);
	print_amount(this->_amount, false);
	print_deposits(this->_nbDeposits, false);
	print_withdrawals(this->_nbWithdrawals, true);
}

/* CONSTRUCTOR */
Account::Account(int initial_deposit)
{
    _displayTimestamp();
    print_index(this->_accountIndex, false);
    print_amount(initial_deposit, false);
    std::cout << "created" << std::endl;

    Account::_totalAmount += initial_deposit; 
    Account::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_accountIndex = Account::_nbAccounts - 1;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    return ;
}

/* DECONSTRUCTOR */
Account::~Account(void)
{
	_displayTimestamp();
	print_index(this->_accountIndex, false);
	print_amount(this->_amount, false);
	std::cout << "closed" << std::endl;
    return ;
}