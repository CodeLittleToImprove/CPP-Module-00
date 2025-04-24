
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
