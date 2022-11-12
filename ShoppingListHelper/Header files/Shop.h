#pragma once
#include <string>

class Shop
{
public:
	Shop();
	Shop(std::string, std::string, std::string, int);
	~Shop();
	std::string GetShopName();
	std::string GetShopType();
	std::string GetShopAddress();
	int GetShopRating();
private:
	std::string shopType{""};
	std::string shopName{""};
	std::string shopAddress{""};
	int shopRating{0};
};

