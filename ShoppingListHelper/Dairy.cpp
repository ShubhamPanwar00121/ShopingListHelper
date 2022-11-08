#include "Dairy.h"

Dairy::Dairy(std::string shopName, std::string address, int shopRating, int numberOfCowsOwned, Commodity milk, Commodity cheese, Commodity curd)
	:Shop("Dairy", shopName, address, shopRating), cowsOwned{ numberOfCowsOwned }
{
	this->milk = milk;
	this->cheese = cheese;
	this->curd = curd;
}

Dairy::Dairy()
{
}

Commodity Dairy::BuyFromDairy(int CommodityType)
{
	switch (CommodityType)
	{
	case MILK:
	{
		return milk;
		break;
	}
	case CURD:
	{
		return curd;
		break;
	}
	case CHEESE:
	{
		return cheese;
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
