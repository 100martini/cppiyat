#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int currentSize;
    int oldestIndex;
    
public:
    PhoneBook();
    
    void addContact(const Contact &contact);
    bool searchContact() const;
    void displayContactList() const;
};

#endif