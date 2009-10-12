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

	std::wstring country;
	std::wstring province;
	std::wstring city;
	std::wstring address;
};

class Email
{
public:
	enum Type { Personal, Home, Work, Other};
};

typedef std::pair<Phone::Type, std::wstring> PhonePairType;
typedef std::pair<Address::Type, std::wstring> AddressPairType;
typedef std::pair<Messenger::Type, std::wstring> MessengerPairType;
typedef std::pair<Email::Type, std::wstring> EmailPairType;

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
	virtual std::wstring getTitle() { return familyName_ + personalName_ + title_; }
	virtual std::wstring getContents() { return note_; }

private:
	std::wstring familyName_;
	std::wstring personalName_;
	std::wstring company_;
	std::wstring title_;
	std::wstring department_;

	AddressListType addresses_;
	PhoneListType phones_;
	MessengerListType messenger_;
	EmailListType emails_;
	
	std::wstring note_;

	DateTimeType createdDate_;
};


#endif /* __CONTACT_H__ */
