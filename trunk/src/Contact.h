#ifndef __CONTACT_H__
#define __CONTACT_H__

#include "Item.h"

class Messenger 
{
public:
	enum Type { MSN, NateOn, ICQ, GoogleTalk, AIM, Yahoo, Other };
};

class Phone
{
public:
	enum Type { HomePhone, HomeFax, WorkPhone, WorkFax, Mobile, Fax, Other};
};

class Address
{
public:
	enum Type { Home, Work, Other };

	std::tstring country;
	std::tstring province;
	std::tstring city;
	std::tstring address;
};

class Email
{
public:
	enum Type { Personal, Home, Work, Other};
};

typedef std::pair<Phone::Type, std::tstring> PhonePairType;
typedef std::pair<Address::Type, std::tstring> AddressPairType;
typedef std::pair<Messenger::Type, std::tstring> MessengerPairType;
typedef std::pair<Email::Type, std::tstring> EmailPairType;

typedef std::vector<PhonePairType> PhoneListType;
typedef std::vector<AddressPairType> AddressListType;
typedef std::vector<MessengerPairType> MessengerListType;
typedef std::vector<EmailPairType> EmailListType;

class Contact : public Item
{
public:
	Contact(void);
	~Contact(void);
	

	virtual Item::Type getType() { return Item::Contact; }
	virtual DateTimeType getDateForDisplay() { return createdDate_; }
	virtual std::tstring getTitle() { return familyName_ + personalName_ + title_; }
	virtual std::tstring getContents() { return note_; }

private:
	std::tstring familyName_;
	std::tstring personalName_;
	std::tstring company_;
	std::tstring title_;
	std::tstring department_;

	AddressListType addresses_;
	PhoneListType phones_;
	MessengerListType messenger_;
	EmailListType emails_;
	
	std::tstring note_;

	DateTimeType createdDate_;
};


#endif /* __CONTACT_H__ */
