#ifndef __CONTACT_H__
#define __CONTACT_H__

#include "Item.h"

class Messenger 
{
public:
	enum Type { MSN, NateOn, ICQ, GoogleTalk, AIM, Yahoo, Other };

	Type type;
	std::string id;
};

class Phone
{
public:
	enum Type { HomePhone, HomeFax, WorkPhone, WorkFax, Mobile, Fax, Other};

	Type type;
	std::string number;
};

class Address
{
public:
	enum Type { Home, Work, Other };

	Type type;
	std::string country;
	std::string province;
	std::string city;
	std::string address;
	std::string post;
};

class SpecialDay
{
	enum Type {Birthday, };

	Type type;
	DateTimeType datetime;
};

class Email
{
public:
	enum Type { Personal, Home, Work, Other};

	Type type;
	std::string address;
};

typedef std::vector<Phone>		PhoneListType;
typedef std::vector<Address>	AddressListType;
typedef std::vector<Messenger>	MessengerListType;
typedef std::vector<Email>		EmailListType;
typedef std::vector<SpecialDay> SpecialDayListType;

class Contact : public Item
{
public:
	Contact(void);
	~Contact(void);
	

	virtual Item::Type getType() { return Item::Contact; }
	virtual DateTimeType getDisplayDate() { return createdDate_; }
	virtual std::string getTitle() { return familyName_ + personalName_ + title_; }
	virtual std::string getContents() { return note_; }

private:
	std::string familyName_;
	std::string personalName_;
	std::string company_;
	std::string title_;
	std::string department_;

	AddressListType addresses_;
	PhoneListType phones_;
	MessengerListType messenger_;
	EmailListType emails_;
	SpecialDayListType specialdays_;
	
	std::string note_;

	DateTimeType createdDate_;
};


#endif /* __CONTACT_H__ */
