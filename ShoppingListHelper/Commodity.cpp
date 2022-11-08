#include "Commodity.h"

Commodity::Commodity()
{
}

Commodity::Commodity(std::string name, float availableQuantity, float cost)
{
	this->name = name;
	this->availableQuantity = availableQuantity;
	this->cost = cost;
}

Commodity::~Commodity()
{
}

std::string Commodity::GetCommodityName()
{
	return this->name;
}

float Commodity::GetAvaialbleQuantity()
{
	return this->availableQuantity;
}

float Commodity::GetCommodityCost()
{
	return this->cost;
}
