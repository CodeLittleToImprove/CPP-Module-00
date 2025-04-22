
#include <iostream>
#include "Contact.hpp"

int main()
{
	std::string command;
	Contact contacts[8];
	int contactCount = 0;
	int currentIndex = 0;
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
//	for (int i = 0; i < 8; ++i)
//	{
//		std::cout << "\nAdding contact #" << i + 1 << std::endl;
//		addContact(phonebook[i]);
//	}
	}
}
