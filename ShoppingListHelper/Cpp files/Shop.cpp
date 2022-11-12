#include "Shop.h"

Shop::Shop()
{

}

Shop::Shop(std::string shopType, std::string shopName, std::string shopAddress, int shopRating)
{
	this->shopType = shopType;
	this->shopName = shopName;
	this->shopAddress = shopAddress;
	this->shopRating = shopRating; 
}

Shop::~Shop()
{
}

std::string Shop::GetShopName()
{
	return shopName;
}

std::string Shop::GetShopType()
{
	return shopType;
}

std::string Shop::GetShopAddress()
{
	return shopAddress;
}

int Shop::GetShopRating()
{
	return shopRating;
}
