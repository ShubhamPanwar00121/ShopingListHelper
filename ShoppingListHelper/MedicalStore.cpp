#include "MedicalStore.h"

MedicalStore::MedicalStore(std::string shopName, std::string address, int shopRating, int staffRating, Commodity combiflame, Commodity perasitamol, Commodity noflue)
	:Shop("Dairy", shopName, address, shopRating), staffRating{ staffRating }
{
	this->combiflame = combiflame;
	this->perasitamol = perasitamol;
	this->noflue = noflue;
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
	case COMBIFLAME:
	{
		return combiflame;
		break;
	}
	case PERASITAMOL:
	{
		return perasitamol;
		break;
	}
	case NOFLUE:
	{
		return noflue;
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
