#include "Contact.hpp"
#include "Utils.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

void Contact::setContact(const std::string &fName, const std::string &lName, 
                       const std::string &nick, const std::string &phone, 
                       const std::string &secret) {
    firstName = fName;
    lastName = lName;
    nickname = nick;
    phoneNumber = phone;
    darkestSecret = secret;
}

std::string Contact::formatColumn(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void Contact::displayHeader(int index) const {
    std::cout << "|" << formatColumn(intToString(index))
              << "|" << formatColumn(firstName)
              << "|" << formatColumn(lastName)
              << "|" << formatColumn(nickname)
              << "|" << std::endl;
}

void Contact::displayContact() const {
    std::cout << YELLOWISH <<"First name: " << RESET << firstName << std::endl
              << YELLOWISH <<"Last name: " << RESET << lastName << std::endl
              << YELLOWISH <<"Nickname: " << RESET << nickname << std::endl
              << YELLOWISH <<"Phone number: " << RESET << phoneNumber << std::endl
              << YELLOWISH <<"Darkest secret: " << RESET << darkestSecret << std::endl;
}

bool Contact::isEmpty() const {
    return firstName.empty() && lastName.empty() && nickname.empty() && 
           phoneNumber.empty() && darkestSecret.empty();
}
