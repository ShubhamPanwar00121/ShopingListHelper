#include "GroceryStore.h"

GroceryStore::GroceryStore(std::string shopName, std::string address, int shopRating, int numberOfOutlets, Commodity rice, Commodity cola, Commodity soap)
	:Shop("Dairy", shopName, address, shopRating), outletsCount{ numberOfOutlets }
{
	this->rice = rice;
	this->cola = cola;
	this->soap = soap;
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

Commodity GroceryStore::BuyFromGroceryStore(int CommodityType)
{
	switch (CommodityType)
	{
	case RICE:
	{
		return rice;
		break;
	}
	case COLA:
	{
		return cola;
		break;
	}
	case SOAP:
	{
		return soap;
		break;
	}

	default:
		Commodity defaultCommodity = Commodity("null", 0.0f, 0.0f);
		return defaultCommodity;
		break;
	}
}
