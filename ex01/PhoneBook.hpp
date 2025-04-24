/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui-quo <tbui-quo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:12:42 by tbui-quo          #+#    #+#             */
/*   Updated: 2025/04/24 16:12:58 by tbui-quo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define TESTMODE false
# define ENABLE_STRICT_INPUT true

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
	const Contact&	getContactByIndex(int index) const; // reference because we return a single object
	void			addContact();
	void			fillTestContacts();
};

void searchContact(const PhoneBook& book);
void displayContactDetails(const Contact& contact);
void displayContactsList(const Contact contacts[], int contactCount);
#endif