#include "PurchasedCommodity.h"

PurchasedCommodity::PurchasedCommodity()
{
}

PurchasedCommodity::PurchasedCommodity(std::string name, float availableQuant, float cost, float BoughtAmount)
	:Commodity(name,availableQuant,cost),PurchasedAmount{BoughtAmount}
{

}

PurchasedCommodity::~PurchasedCommodity()
{
}

float PurchasedCommodity::GetPurchasedAmmount()
{
	return PurchasedAmount;
}
