
#include <iostream>
#include "Contact.hpp"

int main()
{
	Contact phonebook[8];
	for (int i = 0; i < 8; ++i)
	{
		std::cout << "\nAdding contact #" << i + 1 << std::endl;
		addContact(phonebook[i]);
	}

}
