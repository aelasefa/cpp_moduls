#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data myData;
    myData.name = "Ayman";
    myData.number = 333;

    std::cout << "Original Data pointer: " << &myData << std::endl;
    std::cout << "Data contents: name = " << myData.name << ", number = " << myData.number << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized uintptr_t value: " << raw << std::endl;

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Deserialized Data pointer: " << deserializedPtr << std::endl;
    std::cout << "Data contents after deserialize: name = " << deserializedPtr->name << ", number = " << deserializedPtr->number << std::endl;


    return 0;
}

