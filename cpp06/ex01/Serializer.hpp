#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
typedef unsigned long uintptr_t;
class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &other);
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	Serializer &operator=(const Serializer &other);
};

#endif

