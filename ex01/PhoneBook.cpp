#include "PhoneBook.hpp"

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

void PhoneBook:: promptAndFillContact(Contact& new_contact)
{
	promptAndSet("First name	: ", &Contact::setFirstName, new_contact);
	promptAndSet("Last name		: ", &Contact::setLastName, new_contact);
	promptAndSet("Nickname         : ", &Contact::setNickname, new_contact);
	promptAndSet("Phone number     : ", &Contact::setPhoneNumber, new_contact);
	promptAndSet("Darkest secret   : ", &Contact::setDarkestSecret, new_contact);

	std::cout << std::endl << "Contact saved" << std::endl;
}

PhoneBook::PhoneBook()
{
	contactCount = 0;
	currentIndex = 0;
	std::cout << "Phonebook created" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

int PhoneBook::getContactCount() const
{
	return contactCount;
}

const Contact* PhoneBook::getContacts() const
{
	return contacts;
}

const Contact& PhoneBook::getContactByIndex(int index) const
{
	if (index >= 0 && index < contactCount)
		return contacts[index];
	throw std::out_of_range("Index is out of range");
}

void PhoneBook::addContact()
{
	if (contactCount < 8)
	{
		std::cout << "Adding contact #" << (contactCount + 1) << std::endl;
		promptAndFillContact(contacts[currentIndex]);
		contactCount++;
	}
	else
	{
		std::cout << "Phonebook is full! Replacing oldest contact." << std::endl;
		promptAndFillContact(contacts[currentIndex]);
	}
	currentIndex = (currentIndex + 1) % 8;
}

void PhoneBook::fillTestContacts()
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

static int ftStoi(const std::string& str)
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

void searchContact(const PhoneBook& book)
{
	if (book.getContactCount() <= 0)
	{
		std::cout << "No contacts exist yet!" << std::endl;
		return;
	}

	displayContactsList(book.getContacts(), book.getContactCount());

	std::string indexInput;
	std::cout << "Enter index of contact to display: ";
	std::getline(std::cin, indexInput);

	try
	{
		int index = ftStoi(indexInput);
		if (index >= 0 && index < book.getContactCount())
			displayContactDetails(book.getContactByIndex(index));
		else
			std::cout << "Invalid index. Please enter a number between 0 and " << (book.getContactCount() - 1) << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Invalid input. Please enter a valid number." << std::endl;
	}
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

