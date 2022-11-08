#include "Main.h"

Dairy selectedDairy{};
int shopSelectionCode{ 0 };

int main()
{
	cout << "Welcome to the shopping helper"<< endl;
	Sleep(1500);
	cout << "What are you Shopping today?\nDairy | Groceries | Medicines" << endl;
	cout << "-----------------------------------------------------------\n";
	cin >> category;
	ToLowerCase(category);
	SwitchToRequiredCategory(category);
	system("cls");

	if (shopSelectionCode == 1)
	{
		ShowAvaialbleCommoditiesInSelectedShop(selectedDairy);
	}
}

void ToLowerCase(string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

void SwitchToRequiredCategory(string str)
{
	if (str == "dairy")
	{
		system("cls");
		selectedDairy = DairySelected();
		shopSelectionCode = 1;
	}
	else if (str == "groceries")
	{
		system("cls");
		shopSelectionCode = 2;
	}
	else if (str == "Medicines")
	{
		system("cls");
		shopSelectionCode = 3;
	}
	else if (str == "exit")
	{
		system("cls");
		cout << "Exiting....";
	}
	else
	{
		system("cls");
		RetryOrExit();
	}
}

void RetryOrExit()
{
	cout << "please enter a valid name enter exit to exit/n";
	cin >> category;
	ToLowerCase(category);
	SwitchToRequiredCategory(category);

	Sleep(1000);
	cout << "What are you Shopping today?\nDairy | Groceries | Medicines" << endl;
	cout << "-----------------------------------------------------------\n";
}

Dairy DairySelected()
{
	int srNo{ 1 };
	int selectedDairy{ 0 };
	cout << "Welcome to dairy section\nPlease select the number of shop from where you want to buy\n";

	Commodity _milk1("Milk",112.0f,1.2f);
	Commodity _cheese1("Cheese", 100.0f, 1.6f);
	Commodity _curd1("Curd", 50.0f, 4.0f);
	Dairy *Ptr_ColdMilk = new Dairy("Cold Milk", "Northern Streets", 4, 8, _milk1, _cheese1 ,_curd1);

	Commodity _milk2("Milk", 200.0f, 1.25f);
	Commodity _cheese2("Cheese", 300.0f, 1.5f);
	Commodity _curd2("Curd", 80.0f, 4.2f);
	Dairy *Ptr_SayCheese = new Dairy("Say Cheese", "Western Tower, Whiterun", 5, 10, _milk2, _cheese2, _curd2);

	Commodity _milk3("Milk", 812.0f, 1.1f);
	Commodity _cheese3("Cheese", 700.0f, 1.2f);
	Commodity _curd3("Curd", 500.0f, 3.8f);
	Dairy *Ptr_HappyCow = new Dairy("Happy Cow", "Near Lumber Mill, Riverwood", 3, 12, _milk3, _cheese3, _curd3);

	Dairy *Ptr_Dairies[]{ Ptr_ColdMilk, Ptr_HappyCow, Ptr_SayCheese};

	cout << left;
	cout << setw(10) << "Number" 
		<< setw(20) << "Name" 
		<< setw(30) << "Address" 
		<< setw(10) << "Rating" 
		<< setw(20) << "Number Of Cows Owned"
		<<endl;
	
	for (int i = 0; i < 3; i++)
	{
		PrintShopsDetails(srNo, (*Ptr_Dairies[i]).Shop::GetShopName(), (*Ptr_Dairies[i]).Shop::GetShopAddress(), (*Ptr_Dairies[i]).Shop::GetShopRating(), (*Ptr_Dairies[i]).GetNumberOfCowsOwned());
		srNo++;
	}
	
	selectedDairy = GetSelectDairyNumber();

	switch (selectedDairy)
	{
	case 1:
	{
		return *Ptr_ColdMilk;
		break;
	}
	case 2:
	{
		return *Ptr_HappyCow;
		break;
	}
	case 3:
	{
		return *Ptr_SayCheese;
		break;
	}
	default:
	{
		cout << "selected dairy number not valid\n";
		return *Ptr_ColdMilk;
		break;
	}
	}

	delete Ptr_ColdMilk;
	Ptr_ColdMilk = nullptr;
	delete Ptr_SayCheese;
	Ptr_SayCheese = nullptr;
	delete Ptr_HappyCow;
	Ptr_HappyCow = nullptr;
}

void PrintShopsDetails(int SrNum, string name, string address, int rating, int numberOfCows)
{

	cout << setw(10)<<SrNum
		<< setw(20) << name
		<< setw(30) << address
		<< setw(10) << rating
		<< setw(20) << numberOfCows
		<< endl;
}

int GetSelectDairyNumber()
{
	int selectedDairy;
	cin >> selectedDairy;

	if (selectedDairy > 0 && selectedDairy < 4)
	{
		return selectedDairy;
	}
	else
	{
		cout << "please input a valid number (1,2 or 3)\n";
		return GetSelectDairyNumber();
	}
}

void ShowAvaialbleCommoditiesInSelectedShop(Dairy DairyShop)
{
		cout << "welcome to " << DairyShop.GetShopName() <<"\n\nHere we have following Commodities Avaialble:----\n"<< endl;
		cout << setw(20) << "NAME" << setw(25) << "AVAILABLE QUANTITY" << setw(10) << "COST" << endl;
		DisplayCommoditiesDetail(DairyShop.BuyFromDairy(Dairy::MILK));
		DisplayCommoditiesDetail(DairyShop.BuyFromDairy(Dairy::CHEESE));
		DisplayCommoditiesDetail(DairyShop.BuyFromDairy(Dairy::CURD));
}

void DisplayCommoditiesDetail(Commodity c)
{
	cout << left;
	cout << setw(20) << c.GetCommodityName() << setw(25) << c.GetAvaialbleQuantity() << setw(10) << c.GetCommodityCost() << endl;
}