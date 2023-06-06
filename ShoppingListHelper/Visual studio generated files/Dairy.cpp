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

Commodity Dairy::BuyFromDairy(int CommodityType, float purchasedAmmount)
{
	switch (CommodityType)
	{
	case COM1:
	{
		return com1;
		com1.SetAvailableQuantity(purchasedAmmount);
		break;
	}
	case COM2:
	{
		return com2;
		com2.SetAvailableQuantity(purchasedAmmount);
		break;
	}
	case COM3:
	{
		return com3;
		com3.SetAvailableQuantity(purchasedAmmount);
		break;
	}

	default:
		Commodity defaultCommodity = Commodity("null", 0.0f, 0.0f);
		return defaultCommodity;
		break;
	}
}

Commodity Dairy::BuyFromDairy(std::string name, float purchasedAmmount)
{
	if (name == com1.GetCommodityName())
	{
		com1.SetAvailableQuantity(com1.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromDairy(0, purchasedAmmount);
	}
	else if (name == com2.GetCommodityName())
	{
		com2.SetAvailableQuantity(com2.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromDairy(1, purchasedAmmount);
	}
	else if (name == com3.GetCommodityName())
	{
		com3.SetAvailableQuantity(com3.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromDairy(2, purchasedAmmount);
	}
	else
	{
		return BuyFromDairy(3, purchasedAmmount);
	}
}

int Dairy::GetNumberOfCowsOwned()
{
	return this->cowsOwned;
}

Dairy::~Dairy()
{
}
