
#include "Contact.hpp"

int Contact::_instanceCount = 0;
const int Contact::_MAX_INSTANCES = 8;

Contact::Contact()
{
	if (_instanceCount >= _MAX_INSTANCES)
		std::cout << "Maximum number of instances reached!" << _instanceCount << std::endl;
	_instanceCount++;
	std::cout << "Instance created. Total: " << _instanceCount << std::endl;
}
Contact::~Contact()
{
	_instanceCount--;
	std::cout << "Instance destroyed. Total: " << _instanceCount << std::endl;
}

std::string Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string Contact::getNickname(void)
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}

void Contact::setFirstName(std::string str)
{
	this->_firstName = str;
	return ;
}

void Contact::setLastName(std::string str)
{
	this->_lastName = str;
	return ;
}

void Contact::setNickname(std::string str)
{
	this->_nickName = str;
	return ;
}
void Contact::setPhoneNumber(std::string str)
{
	this->_phoneNumber = str;
	return ;
}

void Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
	return ;
}