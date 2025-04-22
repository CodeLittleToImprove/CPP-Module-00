#include <iostream>
#include "Contact.hpp"

int ftStoi(const std::string& str)
{
	int result = 0;
	int sign = 1;
	size_t i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	for (;i < str.length(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			throw std::invalid_argument("Invalid input string");
	}

	return sign * result;
}

int main()
{
	std::string	command;
	Contact	contacts[8];
	int contactCount = 0;
	int currentIndex = 0;

	if (TESTMODE)
	{
		for (int i = 0; i < 8; ++i)
		{
			std::stringstream ss;
			ss << "First" << i;
			contacts[i].setFirstName(ss.str());
			ss.str(""); ss << "Last" << i;
			contacts[i].setLastName(ss.str());
			ss.str(""); ss << "Nick" << i;
			contacts[i].setNickname(ss.str());
			ss.str(""); ss << "1234567" << i;
			contacts[i].setPhoneNumber(ss.str());
			ss.str(""); ss << "Secret" << i;
			contacts[i].setDarkestSecret(ss.str());
		}

		contactCount = 8;
		currentIndex = 0;
	}
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			if (contactCount < 8)
			{
				std::cout << "adding contact #" << (contactCount + 1) << std::endl;
				addContact(contacts[currentIndex]);
				contactCount++;
			}
			else
			{
				std::cout << "Phonebook is full! Replacing oldest contact." << std::endl;
				addContact(contacts[currentIndex]);
			}
			currentIndex = (currentIndex + 1) % 8;
		}
		else if (command == "SEARCH")
		{
			if (contactCount <= 0)
			{
				std::cout << "No contacts exists yet !" << std::endl;
				continue;
			}
			displayContactsList(contacts, contactCount);

			std::string indexInput;
			std::cout << "Enter index of contact to display: ";
			std::getline(std::cin, indexInput);
			try
			{
				int index = ftStoi(indexInput);
				if (index >= 0 && index < contactCount)
					displayContactDetails(contacts[index]);
				else
					std::cout << "Invalid index. Please enter a number between 0 and " << (contactCount -1 ) << std::endl;
			}
			catch (const std::exception&)
			{
				std::cout << "Invalid input. Please enter a valid number." <<std::endl;
			}
		}
		else if (command == "EXIT")
		{
			std::cout << "Existing program." << std::endl;
			break;
		}
		else
			std::cout << "Invalid command!" << std::endl;
	}
}
