#include "PhoneBook.hpp"
#include "Utils.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

PhoneBook::PhoneBook() : currentSize(0), oldestIndex(0) {}

void PhoneBook::addContact(const Contact &contact) {
    contacts[oldestIndex] = contact;
    oldestIndex = (oldestIndex + 1) % 8;
    if (currentSize < 8) currentSize++;
    std::cout << "\n" << GREEN << "Contact added successfully." << RESET << std::endl;
}

void PhoneBook::displayContactList() const {
    if (currentSize == 0) {
        std::cout << "\n" << RED << "PhoneBook is empty.. Try to ADD." << RESET << std::endl;
        return;
    }

    std::cout << "+----------+----------+----------+----------+" << std::endl;
    std::cout << "|   "<< YELLOW <<"INDEX"<< RESET <<"  |"<< YELLOW <<"FIRST NAME"<< RESET <<"| "<< YELLOW <<"LAST NAME"<< RESET <<"| "<< YELLOW <<"NICKNAME"<< RESET <<" |" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    
    for (int i = 0; i < currentSize; i++) {
        contacts[i].displayHeader(i + 1);
        std::cout << "+----------+----------+----------+----------+" << std::endl;
    }
}

bool PhoneBook::searchContact() const {
    if (currentSize == 0) {
        std::cout << "\n" << RED << "PhoneBook is empty.. Try to ADD." << RESET << std::endl;
        return true;
    }

    displayContactList();
    
    std::cout << "Enter the index of the contact you want to view: ";
    std::string input;
    std::getline(std::cin, input);

    if (std::cin.eof()) {
        std::cin.clear();
        std::cout << "\nCTRL+D was pressed.\n";
        return false;
    }

    for (std::string::size_type i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            std::cout << "\n" << RED << "Ghalat: index is not a number." << RESET << std::endl;
            return true;
        }
    }

    int index = std::atoi(input.c_str());

    if (index < 1 || index > currentSize) {
        std::cout << "\n" << RED << "Ghalat: index is out of range." << RESET << std::endl;
        return true;
    }
    
    contacts[index - 1].displayContact();
    return true;
}
