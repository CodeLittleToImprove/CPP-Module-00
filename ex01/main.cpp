/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:11:14 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 16:11:15 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main(void)
{
	std::string	command;
	PhoneBook	book;

	if (TESTMODE)
		book.fillTestContacts();
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
			book.addContact();
		else if (command == "SEARCH")
			searchContact(book);
		else if (command == "EXIT")
		{
			std::cout << "Existing program." << std::endl;
			break;
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}
}
