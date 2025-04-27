#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    
    std::string formatColumn(const std::string &str) const;

public:
    Contact();
    
    void setContact(const std::string &fName, const std::string &lName, 
                   const std::string &nick, const std::string &phone, 
                   const std::string &secret);
    
    void displayHeader(int index) const;
    void displayContact() const;
    
    bool isEmpty() const;
};

#endif