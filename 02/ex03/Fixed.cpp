#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) {
    this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_value >> this->_fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->_value > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_value < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_value >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_value <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_value != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long temp = (long)this->_value * (long)other.getRawBits();
    result.setRawBits(temp >> this->_fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long temp = ((long)this->_value << this->_fractionalBits) / other.getRawBits();
    result.setRawBits(temp);
    return result;
}

Fixed& Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}