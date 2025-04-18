
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

int Contact::getInstanceCount()
{
	return _instanceCount;
}

int Contact::getMaxInstances()
{
	return _MAX_INSTANCES;
}
const std::string& Contact::getFirstName(void) const
{
	return (this->_firstName);
}

const std::string& Contact::getLastName(void) const
{
	return (this->_lastName);
}

const std::string& Contact::getNickname(void) const
{
	return (this->_nickName);
}

const std::string& Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

const std::string& Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

void Contact::setFirstName(const std::string& str)
{
	this->_firstName = str;
}

void Contact::setLastName(const std::string& str)
{
	this->_lastName = str;
}

void Contact::setNickname(const std::string& str)
{
	this->_nickName = str;
}
void Contact::setPhoneNumber(const std::string& str)
{
	this->_phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string& str)
{
	this->_darkestSecret = str;
}