#include "Dairy.h"

Dairy::Dairy(std::string shopName, std::string address, int shopRating, int numberOfCowsOwned, Commodity com1, Commodity com2, Commodity com3)
	:Shop("Dairy", shopName, address, shopRating), cowsOwned{ numberOfCowsOwned }
{
	this->com1 = com1;
	this->com3 = com2;
	this->com2 = com3;
}

Dairy::Dairy()
{
}

Commodity Dairy::BuyFromDairy(int CommodityType)
{
	switch (CommodityType)
	{
	case COM1:
	{
		return com1;
		break;
	}
	case COM2:
	{
		return com2;
		break;
	}
	case COM3:
	{
		return com3;
		break;
	}

	default:
		Commodity defaultCommodity = Commodity("null", 0.0f, 0.0f);
		return defaultCommodity;
		break;
	}
}

int Dairy::GetNumberOfCowsOwned()
{
	return this->cowsOwned;
}

Dairy::~Dairy()
{
}
