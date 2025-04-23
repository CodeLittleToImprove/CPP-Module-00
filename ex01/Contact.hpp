
# ifndef CPP00_CONTACT_HPP
# define CPP00_CONTACT_HPP
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


class	Contact
{
private:
	static int			_instanceCount;
	static const int	_MAX_INSTANCES;
	std::string			_firstName;
	std::string			_lastName;
	std::string			_nickName;
	std::string			_phoneNumber;
	std::string			_darkestSecret;
public:
	Contact();
	~Contact();
	static int getInstanceCount();
	static int getMaxInstances();
	void					setFirstName(const std::string&);
	void					setLastName(const std::string&);
	void					setNickname(const std::string&);
	void					setPhoneNumber(const std::string&);
	void					setDarkestSecret(const std::string&);
	const std::string&		getFirstName(void)const;
	const std::string&		getLastName(void)const;
	const std::string&		getNickname(void)const;
	const std::string&		getPhoneNumber(void)const;
	const std::string&		getDarkestSecret(void)const;
};

#endif //CPP00_CONTACT_HPP
