#include <iostream>
#include "Contact.hpp"

static void promptAndSet(const std::string& prompt, void (Contact::*setter)(const std::string&), Contact& contact)
{
	std::string buffer;
	std::cout << prompt;
	// std::cin >> buffer; // first method would be used if only use a single word as input
	std::getline(std::cin, buffer); // acts like getnextline
	(contact.*setter)(buffer); // pointer to a member function example syntax
}

Contact addContact()
{
	Contact new_contact;

	promptAndSet("First name	: ", &Contact::setFirstName, new_contact);
	promptAndSet("Last name		:", &Contact::setLastName, new_contact);
	promptAndSet("Nickname         : ", &Contact::setNickname, new_contact);
	promptAndSet("Phone number     : ", &Contact::setPhoneNumber, new_contact);
	promptAndSet("Darkest secret   : ", &Contact::setDarkestSecret, new_contact);

	std::cout << std::endl << "Contact saved" << std::endl;
	return new_contact;
}

