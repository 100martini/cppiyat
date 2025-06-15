#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data originalData(42, "Test Data", 3.14);
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "ID: " << originalData.id << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << std::endl;
    
    uintptr_t serialized = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;
    
    Data* deserializedPtr = Serializer::deserialize(serialized);
    
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "ID: " << deserializedPtr->id << std::endl;
    std::cout << "Name: " << deserializedPtr->name << std::endl;
    std::cout << "Value: " << deserializedPtr->value << std::endl;
    std::cout << "Address: " << deserializedPtr << std::endl;
    std::cout << std::endl;
    
    if (deserializedPtr == &originalData) {
        std::cout << "Success: Deserialized pointer equals original pointer <3" << std::endl;
    } else {
        std::cout << "Error: Pointers don't match!" << std::endl;
    }
    
    return 0;
}