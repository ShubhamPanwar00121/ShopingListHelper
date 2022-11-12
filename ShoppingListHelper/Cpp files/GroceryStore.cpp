#include "GroceryStore.h"

GroceryStore::GroceryStore(std::string shopName, std::string address, int shopRating, int numberOfOutlets, Commodity com1, Commodity com2, Commodity com3)
	:Shop("GroceryStore", shopName, address, shopRating), outletsCount{ numberOfOutlets }
{
	this->com1 = com1;
	this->com2 = com2;
	this->com3 = com3;
}

GroceryStore::GroceryStore()
{
}

GroceryStore::~GroceryStore()
{
}

int GroceryStore::GetNumberOfOutlets()
{
	return this->outletsCount;
}

Commodity GroceryStore::BuyFromGroceryStore(int CommodityType, float purchasedAmmount)
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

Commodity GroceryStore::BuyFromGroceryStore(std::string name, float purchasedAmmount)
{
	if (name == com1.GetCommodityName())
	{
		com1.SetAvailableQuantity(com1.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromGroceryStore(0, purchasedAmmount);
	}
	else if (name == com2.GetCommodityName())
	{
		com2.SetAvailableQuantity(com2.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromGroceryStore(1, purchasedAmmount);
	}
	else if (name == com3.GetCommodityName())
	{
		com3.SetAvailableQuantity(com3.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromGroceryStore(2, purchasedAmmount);
	}
	else
	{
		return BuyFromGroceryStore(3, purchasedAmmount);
	}
}
