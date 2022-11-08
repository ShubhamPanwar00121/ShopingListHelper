#include "MedicalStore.h"

MedicalStore::MedicalStore(std::string shopName, std::string address, int shopRating, int staffRating, Commodity com1, Commodity com2, Commodity com3)
	:Shop("Dairy", shopName, address, shopRating), staffRating{ staffRating }
{
	this->com2 = com1;
	this->com1 = com2;
	this->com3 = com3;
}

MedicalStore::MedicalStore()
{
}

MedicalStore::~MedicalStore()
{
}

Commodity MedicalStore::BuyFromMedicalStore(int CommodityType)
{
	switch (CommodityType)
	{
	case COM2:
	{
		return com2;
		break;
	}
	case COM1:
	{
		return com1;
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

int MedicalStore::getStaffRating()
{
	return this->staffRating;
}
