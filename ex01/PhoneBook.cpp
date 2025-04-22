#include <iostream>
#include "Contact.hpp"

static bool isAllDigits(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

static void promptAndSet(const std::string& prompt, void (Contact::*setter)(const std::string&), Contact& contact)
{
	std::string buffer;

	if (!ENABLE_STRICT_INPUT)
	{

		std::cout << prompt;
		// std::cin >> buffer; // first method would be used if only use a single word as input
		std::getline(std::cin, buffer); // acts like getnextline
		(contact.*setter)(buffer); // pointer to a member function example syntax
	}
	else
	{
		while (true)
		{
			std::cout << prompt;
			std::getline(std::cin, buffer);

			if (setter == &Contact::setPhoneNumber)
			{
				bool isValid = isAllDigits(buffer);
				if (!isValid)
				{
					std::cout << "Phone number must contain only digits. Please try again" << std::endl;
					continue;
				}
			}
			if (!buffer.empty())
			{
				(contact.*setter)(buffer);
				break;
			}
			else
				std::cout << "Input cannot be empty. Please try again." << std::endl;
		}
	}
}

void addContact(Contact& new_contact)
{
	promptAndSet("First name	: ", &Contact::setFirstName, new_contact);
	promptAndSet("Last name		: ", &Contact::setLastName, new_contact);
	promptAndSet("Nickname         : ", &Contact::setNickname, new_contact);
	promptAndSet("Phone number     : ", &Contact::setPhoneNumber, new_contact);
	promptAndSet("Darkest secret   : ", &Contact::setDarkestSecret, new_contact);

	std::cout << std::endl << "Contact saved" << std::endl;
}

static std::string formatField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	else
		return field;

	// to prevent repetition like this for every field
//	std::string firstName = contacts[i].getFirstName();
//	if (firstName.length() > 10) {
//		firstName = firstName.substr(0, 9) + ".";
//	std::cout << std::setw(10) << firstName << "|";

}
void displayContactsList(const Contact contacts[], int contactCount)
{
	std::cout	<< std::setw(10) << "INDEX" << "|"
				 << std::setw(10) << "FIRST NAME" << "|"
				 << std::setw(10) << "LAST NAME" << "|"
				 << std::setw(10) << "NICKNAME" << std::endl;
	std::cout	<< std::string(43, '-') << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
}

void displayContactDetails(const Contact& contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

