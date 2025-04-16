
# ifndef CPP00_CONTACT_HPP
# define CPP00_CONTACT_HPP
#include <iostream>
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
	void			setFirstName(std::string);
	void			setLastName(std::string);
	void			setNickname(std::string);
	void			setPhoneNumber(std::string );
	void			setDarkestSecret(std::string);
	std::string		getFirstName(void);
	std::string		getLastName(void);
	std::string		getNickname(void);
	std::string		getPhoneNumber(void);
	std::string		getDarkestSecret(void);
};

Contact addContact(void);
#endif //CPP00_CONTACT_HPP
