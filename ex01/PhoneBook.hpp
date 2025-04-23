#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

# define TESTMODE false
# define ENABLE_STRICT_INPUT false
class PhoneBook
{
private:
	Contact			contacts[8];
	int				contactCount;
	int				currentIndex;
	void			promptAndFillContact(Contact& new_contact);
public:
					PhoneBook();
					~PhoneBook();
	int				getContactCount() const;
	const Contact*	getContacts() const; //pointer because we return an array
	const Contact&	getContactByIndex(int index) const; // reference because we returning a single object
	void			addContact();
	void			fillTestContacts();
};

void searchContact(const PhoneBook& book);
void displayContactDetails(const Contact& contact);
void displayContactsList(const Contact contacts[], int contactCount);
#endif