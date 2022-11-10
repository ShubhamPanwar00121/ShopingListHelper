#include "MedicalStore.h"

MedicalStore::MedicalStore(std::string shopName, std::string address, int shopRating, int staffRating, Commodity com1, Commodity com2, Commodity com3)
	:Shop("MedicalStore", shopName, address, shopRating), staffRating{ staffRating }
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

Commodity MedicalStore::BuyFromMedicalStore(int CommodityType, float purchasedQuantity)
{
	switch (CommodityType)
	{
	case COM2:
	{
		return com2;
		com2.SetAvailableQuantity(purchasedQuantity);
		break;
	}
	case COM1:
	{
		return com1;
		com1.SetAvailableQuantity(purchasedQuantity);
		break;
	}
	case COM3:
	{
		return com3;
		com3.SetAvailableQuantity(purchasedQuantity);
		break;
	}

	default:
		Commodity defaultCommodity = Commodity("null", 0.0f, 0.0f);
		return defaultCommodity;
		break;
	}
}

Commodity MedicalStore::BuyFromMedicalStore(std::string name, float purchasedAmmount)
{
	if (name == com1.GetCommodityName())
	{
		com1.SetAvailableQuantity(com1.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromMedicalStore(0, purchasedAmmount);
	}
	else if (name == com2.GetCommodityName())
	{
		com2.SetAvailableQuantity(com2.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromMedicalStore(1, purchasedAmmount);
	}
	else if (name == com3.GetCommodityName())
	{
		com3.SetAvailableQuantity(com3.GetAvaialbleQuantity()-purchasedAmmount);
		return BuyFromMedicalStore(2, purchasedAmmount);
	}
	else
	{
		return BuyFromMedicalStore(3, purchasedAmmount);
	}
}

int MedicalStore::getStaffRating()
{
	return this->staffRating;
}
