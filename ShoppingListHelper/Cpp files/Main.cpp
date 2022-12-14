#include "Main.h"

Dairy selectedDairy{};
GroceryStore selectedGroceryStore{};
MedicalStore selectedMedicalStore{};
int shopSelectionCode{ 0 };
string category{ "" };
vector<pair<Shop, PurchasedCommodity>> purchasedItems{};

int main()
{
	cout << "Welcome to the shopping helper"<< endl;
	Sleep(1500);
	StartFunc();
}

void StartFunc()
{
	category = "";
	shopSelectionCode = 0;

	cout << "What are you Shopping today? or enter exit to exit\nDairy | Groceries | Medicines" << endl;
	cout << "-----------------------------------------------------------\n";
	cin >> category;
	ToLowerCase(category);
	SwitchToRequiredCategory(category);
	system("cls");
	SwitchToSelectedShop();
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
		selectedGroceryStore = GroceryStoreSelected();
		shopSelectionCode = 2;
	}
	else if (str == "medicines")
	{
		system("cls");
		selectedMedicalStore = MedicalStoreSelected();
		shopSelectionCode = 3;
	}
	else if (str == "exit")
	{
		system("cls");
		cout << "Checking for purchased items and making a text file" << endl;
		MakeTextFileAndExit();
		cout << "Exiting....";
		cout << "-----------------------------------------------------------------------------------";
		exit(0);
	}
	else
	{
		system("cls");
		RetryOrExit();
	}
}

void RetryOrExit()
{
	cout << "please enter a valid name or enter exit to exit\nDairy | Groceries | Medicines\n";
	cin >> category;
	ToLowerCase(category);
	SwitchToRequiredCategory(category);
}

Dairy DairySelected()
{
	int srNo{ 1 };
	int selectedDairy{ 0 };
	cout << "Welcome to dairy section\nPlease select the number of shop from where you want to buy\n";

	Commodity _milk1("Milk",112.0f,1.2f);
	Commodity _egg("Egg", 400.0f, 0.2f);
	Commodity _curd1("Curd", 50.0f, 4.0f);
	Dairy *Ptr_ColdMilk = new Dairy("Cold Milk", "Northern Streets", 4, 8, _milk1, _egg ,_curd1);

	Commodity _iceCream("Ice Cream", 200.0f, 0.5f);
	Commodity _cheese2("Cheese", 300.0f, 1.5f);
	Commodity _curd2("Curd", 80.0f, 4.2f);
	Dairy *Ptr_SayCheese = new Dairy("Say Cheese", "Western Tower, Whiterun", 5, 10, _iceCream, _cheese2, _curd2);

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
	
	for (int i = 0; i < (sizeof(Ptr_Dairies) / sizeof(Ptr_Dairies[0])); i++)
	{
		PrintShopsDetails(srNo, (*Ptr_Dairies[i]).Shop::GetShopName(), (*Ptr_Dairies[i]).Shop::GetShopAddress(), (*Ptr_Dairies[i]).Shop::GetShopRating(), (*Ptr_Dairies[i]).GetNumberOfCowsOwned());
		srNo++;
	}
	
	selectedDairy = GetSelectShopNumber();

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
	delete[] Ptr_Dairies;
}

GroceryStore GroceryStoreSelected()
{
	int srNo{ 1 };
	int selectedGrocery{ 0 };
	cout << "Welcome to Grocery Store section\nPlease select the number of shop from where you want to buy\n";

	Commodity _Rice("Rice", 100.0f, 1.5f);
	Commodity _cola("Cola", 50.0f, 0.6f);
	Commodity _soap("Soap", 50.0f, 0.5f);
	GroceryStore* Ptr_GreenBasket = new GroceryStore("Green Basket", "Deep Well, Riften", 4, 1, _Rice, _cola, _soap);

	Commodity _biscuits("Biscuit", 100.0f, 0.5f);
	Commodity _toffee("Toffee", 500.0f, 0.1f);
	Commodity _chips("Chips", 55.0f, 0.5f);
	GroceryStore* Ptr_RisingSun = new GroceryStore("Rising Sun", "Long Tower, Falkreth", 3, 2, _biscuits, _toffee, _chips);

	Commodity _carrot("Carrot", 812.0f, 0.4f);
	Commodity _flour("Flour", 70.0f, 0.2f);
	Commodity _shampoo("Shampoo", 50.0f, 0.8f);
	GroceryStore* Ptr_dailySupply = new GroceryStore("Daily Supply", "Near Lumber Mill, Riverwood", 5, 6, _carrot, _flour, _shampoo);

	GroceryStore* Ptr_GroceryStores[]{ Ptr_GreenBasket, Ptr_RisingSun, Ptr_dailySupply };

	cout << left;
	cout << setw(10) << "Number"
		<< setw(20) << "Name"
		<< setw(30) << "Address"
		<< setw(10) << "Rating"
		<< setw(20) << "Number Of Outlets"
		<< endl;

	for (int i = 0; i < (sizeof(Ptr_GroceryStores) / sizeof(Ptr_GroceryStores[0])); i++)
	{
		PrintShopsDetails(srNo, (*Ptr_GroceryStores[i]).Shop::GetShopName(), (*Ptr_GroceryStores[i]).Shop::GetShopAddress(), (*Ptr_GroceryStores[i]).Shop::GetShopRating(), (*Ptr_GroceryStores[i]).GetNumberOfOutlets());
		srNo++;
	}

	selectedGrocery = GetSelectShopNumber();

	switch (selectedGrocery)
	{
	case 1:
	{
		return *Ptr_GreenBasket;
		break;
	}
	case 2:
	{
		return *Ptr_RisingSun;
		break;
	}
	case 3:
	{
		return *Ptr_dailySupply;
		break;
	}
	default:
	{
		cout << "selected Grocery Store number not valid\n";
		return *Ptr_GreenBasket;
		break;
	}
	}

	delete Ptr_dailySupply;
	Ptr_dailySupply = nullptr;
	delete Ptr_RisingSun;
	Ptr_RisingSun = nullptr;
	delete Ptr_GreenBasket;
	Ptr_GreenBasket = nullptr;
	delete[] Ptr_GroceryStores;
}

MedicalStore MedicalStoreSelected()
{
	int srNo{ 1 };
	int selectedMedical{ 0 };
	cout << "Welcome to Medical Store section\nPlease select the number of shop from where you want to buy\n";

	Commodity _perasitamol("Perasitamol", 100.0f, 0.1f);
	Commodity _nocold("Nocold", 20.0f, 0.2f);
	Commodity _inhaler("Inhaler", 10.0f, 0.5f);
	MedicalStore* Ptr_pureHealth = new MedicalStore("Pure Health", "Rice Field, Riften", 4, 5, _perasitamol, _nocold, _inhaler);

	Commodity _perasitamol2("Perasitamol", 100.0f, 0.1f);
	Commodity _ratPoison("Rat Poison", 1000.0f, 0.3f);
	Commodity _sleepingPill("Sleeping Pill", 1000.0f, 0.15f);
	MedicalStore* Ptr_redDoctor = new MedicalStore("Red Doctor", "Haunted House, Riften", 1, 0, _perasitamol2, _ratPoison, _sleepingPill);

	MedicalStore* Ptr_MedicalStore[]{ Ptr_pureHealth, Ptr_redDoctor };

	cout << left;
	cout << setw(10) << "Number"
		<< setw(20) << "Name"
		<< setw(30) << "Address"
		<< setw(10) << "Rating"
		<< setw(20) << "Staff Rating"
		<< endl;

	for (int i = 0; i < (sizeof(Ptr_MedicalStore)/sizeof(Ptr_MedicalStore[0])); i++)
	{
		PrintShopsDetails(srNo, (*Ptr_MedicalStore[i]).Shop::GetShopName(), (*Ptr_MedicalStore[i]).Shop::GetShopAddress(), (*Ptr_MedicalStore[i]).Shop::GetShopRating(), (*Ptr_MedicalStore[i]).getStaffRating());
		srNo++;
	}

	selectedMedical = GetSelectShopNumber();

	switch (selectedMedical)
	{
	case 1:
	{
		return *Ptr_pureHealth;
		break;
	}
	case 2:
	{
		return *Ptr_redDoctor;
		break;
	}
	default:
	{
		cout << "selected Medical Store number not valid\n";
		return *Ptr_pureHealth;
		break;
	}
	}

	delete Ptr_pureHealth;
	Ptr_pureHealth = nullptr;
	delete Ptr_redDoctor;
	Ptr_redDoctor = nullptr;
	delete[] Ptr_MedicalStore;
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

int GetSelectShopNumber()
{
	int selectedShop{0};

	cin >> selectedShop;

	if (selectedShop > 0 && selectedShop < 4)
	{
		return selectedShop;
	}
	else
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "please input a valid number (1,2 or 3)\n";
		return GetSelectShopNumber();
	}
}

void ShowAvaialbleCommoditiesInSelectedShop(Dairy DairyShop, bool recalled)
{
	string commoditySelected{ "" };
	
		cout << "welcome to " << DairyShop.GetShopName() <<"\n\nHere we have following Commodities Avaialble:----\n"<< endl;
		cout << setw(20) << "NAME" << setw(25) << "AVAILABLE QUANTITY" << setw(10) << "COST" << endl;
		DisplayCommoditiesDetail(DairyShop.BuyFromDairy(Dairy::COM1));
		DisplayCommoditiesDetail(DairyShop.BuyFromDairy(Dairy::COM2));
		DisplayCommoditiesDetail(DairyShop.BuyFromDairy(Dairy::COM3));
		cout << "\nplease enter the name of commodity that you want to buy or enter exit to exit" << endl;
		if (!recalled)cin.ignore();
		getline(cin, commoditySelected);
		ToLowerCase(commoditySelected);
		system("cls");

		string com1Name = DairyShop.BuyFromDairy(Dairy::COM1).GetCommodityName();
		ToLowerCase(com1Name);
		string com2Name = DairyShop.BuyFromDairy(Dairy::COM2).GetCommodityName();
		ToLowerCase(com2Name);
		string com3Name = DairyShop.BuyFromDairy(Dairy::COM3).GetCommodityName();
		ToLowerCase(com3Name);

		if (commoditySelected ==  com1Name)
		{
			Purchaser(DairyShop.BuyFromDairy(Dairy::COM1), DairyShop);
		}
		else if (commoditySelected == com2Name)
		{
			Purchaser(DairyShop.BuyFromDairy(Dairy::COM2), DairyShop);
		}
		else if (commoditySelected == com3Name)
		{
			Purchaser(DairyShop.BuyFromDairy(Dairy::COM3), DairyShop);
		}
		else if (commoditySelected == "exit")
		{
			category = "";
			StartFunc();
		}
		else
		{
			cout << "Please enter complete name and try again" << endl;
			ShowAvaialbleCommoditiesInSelectedShop(selectedDairy,true);
		}
}

void ShowAvaialbleCommoditiesInSelectedShop(GroceryStore groceryStore, bool recalled)
{
	string commoditySelected{ "" };
	
	cout << "welcome to " << groceryStore.GetShopName() << "\n\nHere we have following Commodities Avaialble:----\n" << endl;
	cout << setw(20) << "NAME" << setw(25) << "AVAILABLE QUANTITY" << setw(10) << "COST" << endl;
	DisplayCommoditiesDetail(groceryStore.BuyFromGroceryStore(GroceryStore::COM1));
	DisplayCommoditiesDetail(groceryStore.BuyFromGroceryStore(GroceryStore::COM3));
	DisplayCommoditiesDetail(groceryStore.BuyFromGroceryStore(GroceryStore::COM2));
	cout << "\nplease enter the name of commodity that you want to buy or enter exit to exit" << endl;
	if (!recalled)cin.ignore();
	getline(cin, commoditySelected);
	ToLowerCase(commoditySelected);
	system("cls");

	string com1Name = groceryStore.BuyFromGroceryStore(GroceryStore::COM1).GetCommodityName();
	ToLowerCase(com1Name);
	string com2Name = groceryStore.BuyFromGroceryStore(GroceryStore::COM2).GetCommodityName();
	ToLowerCase(com2Name);
	string com3Name = groceryStore.BuyFromGroceryStore(GroceryStore::COM3).GetCommodityName();
	ToLowerCase(com3Name);

	if (commoditySelected == com1Name)
	{
		Purchaser(groceryStore.BuyFromGroceryStore(GroceryStore::COM1), groceryStore);
	}
	else if (commoditySelected == com2Name)
	{
		Purchaser(groceryStore.BuyFromGroceryStore(GroceryStore::COM2), groceryStore);
	}
	else if (commoditySelected == com3Name)
	{
		Purchaser(groceryStore.BuyFromGroceryStore(GroceryStore::COM3), groceryStore);
	}
	else if (commoditySelected == "exit")
	{
		category = "";
		StartFunc();
	}
	else
	{
		cout << "Please enter complete name and try again" << endl;
		ShowAvaialbleCommoditiesInSelectedShop(selectedGroceryStore, true);
	}
}

void ShowAvaialbleCommoditiesInSelectedShop(MedicalStore medicalStore, bool recalled)
{
	string commoditySelected{ "" };

	cout << "welcome to " << medicalStore.GetShopName() << "\n\nHere we have following Commodities Avaialble:----\n" << endl;
	cout << setw(20) << "NAME" << setw(25) << "AVAILABLE QUANTITY" << setw(10) << "COST" << endl;
	DisplayCommoditiesDetail(medicalStore.BuyFromMedicalStore(MedicalStore::COM1));
	DisplayCommoditiesDetail(medicalStore.BuyFromMedicalStore(MedicalStore::COM3));
	DisplayCommoditiesDetail(medicalStore.BuyFromMedicalStore(MedicalStore::COM2));
	cout << "\nplease enter the name of commodity that you want to buy or enter exit to exit" << endl;
	if (!recalled)cin.ignore();
	getline(cin, commoditySelected);
	ToLowerCase(commoditySelected);
	system("cls");

	string com1Name = medicalStore.BuyFromMedicalStore(MedicalStore::COM1).GetCommodityName();
	ToLowerCase(com1Name);
	string com2Name = medicalStore.BuyFromMedicalStore(MedicalStore::COM2).GetCommodityName();
	ToLowerCase(com2Name);
	string com3Name = medicalStore.BuyFromMedicalStore(MedicalStore::COM3).GetCommodityName();
	ToLowerCase(com3Name);

	if (commoditySelected == com1Name)
	{
		Purchaser(medicalStore.BuyFromMedicalStore(MedicalStore::COM1), medicalStore);
	}
	else if (commoditySelected == com2Name)
	{
		Purchaser(medicalStore.BuyFromMedicalStore(MedicalStore::COM2), medicalStore);
	}
	else if (commoditySelected == com3Name)
	{
		Purchaser(medicalStore.BuyFromMedicalStore(MedicalStore::COM3), medicalStore);
	}
	else if (commoditySelected == "exit")
	{
		category = "";
		StartFunc();
	}
	else
	{
		cout << "Please enter complete name and try again" << endl;
		ShowAvaialbleCommoditiesInSelectedShop(selectedMedicalStore, true);
	}

}

void DisplayCommoditiesDetail(Commodity c)
{
	cout << left;
	cout << setw(20) << c.GetCommodityName() << setw(25) << c.GetAvaialbleQuantity() << setw(10) << c.GetCommodityCost() << endl;
}

void SwitchToSelectedShop()
{
	if (shopSelectionCode == 1)
	{
		ShowAvaialbleCommoditiesInSelectedShop(selectedDairy);
	}
	else if (shopSelectionCode == 2)
	{
		ShowAvaialbleCommoditiesInSelectedShop(selectedGroceryStore);
	}
	else if (shopSelectionCode == 3)
	{
		ShowAvaialbleCommoditiesInSelectedShop(selectedMedicalStore);
	}
	else
	{
		cout << "error in getting shopSelectedCode\n";
	}
}

void Purchaser(Commodity com, Shop selectedShop)
{
	float quantityBought;
	bool purchaseMade{ false };

	cout << "You have Selected " << com.GetCommodityName() <<" which have total "<< com.GetAvaialbleQuantity() << " units availabe." << endl;
	cout << "\nPlease enter the amount in numbers that you want to buy" << endl;
	cin >> quantityBought;

	if (quantityBought <= com.GetAvaialbleQuantity())
	{
		PurchasedCommodity purchasedCom(com.GetCommodityName(), com.GetAvaialbleQuantity(), com.GetCommodityCost(), quantityBought);
		purchasedItems.push_back(make_pair(selectedShop, purchasedCom));
		system("cls");
		cout << "added to purchased item list" << endl;
		purchaseMade = true;
	}
	else
	{
		system("cls");
		cout << "please enter quantity less than avaialble quantity" << endl;
		cout << "Not added to Purchased items list" << endl;
	}

	if (selectedShop.GetShopType() == "Dairy")
	{
		if(purchaseMade) selectedDairy.BuyFromDairy(com.GetCommodityName(), quantityBought);
		ShowAvaialbleCommoditiesInSelectedShop(selectedDairy);
	}
	else if (selectedShop.GetShopType() == "GroceryStore")
	{
		if(purchaseMade) selectedGroceryStore.BuyFromGroceryStore(com.GetCommodityName(), quantityBought);
		ShowAvaialbleCommoditiesInSelectedShop(selectedGroceryStore);
	}
	else if (selectedShop.GetShopType() == "MedicalStore")
	{
		if(purchaseMade) selectedMedicalStore.BuyFromMedicalStore(com.GetCommodityName(),quantityBought);
		ShowAvaialbleCommoditiesInSelectedShop(selectedMedicalStore);
	}
}

void MakeTextFileAndExit()
{
	if (purchasedItems.size() == 0)
	{
		cout << "you have not bought anything" << endl;
	}
	else
	{
		cout << "purchased items found\nmaking list----------------" << endl;

		AddDoublicateComodities();

		float billAmount{0};
		ofstream myFile;
		myFile.open("ShoppingList.txt");
		myFile << "Shopping List-----------\n";
		myFile << "\n";
		myFile << "\n";
		myFile << setw(20) << "Shop Name" << setw(15) << "Product" << setw(20) << "Quantity Purchased" << setw(10) << "cost\n";
		
		myFile << "\n";
		for (int i=0; i < purchasedItems.size(); i++)
		{
			myFile << setw(20) << purchasedItems[i].first.GetShopName() << setw(15) << purchasedItems[i].second.Commodity::GetCommodityName() << setw(20) << purchasedItems[i].second.GetPurchasedAmmount() << setw(10) << purchasedItems[i].second.Commodity::GetCommodityCost() << endl;
			billAmount += (purchasedItems[i].second.GetPurchasedAmmount() * purchasedItems[i].second.GetCommodityCost());
		}
		myFile << "\n";

		myFile << setw(55) << "--------------------------------------" << setw(10) << billAmount << endl;
		myFile.close();
		
		cout << "text file of your shopping items has been created in the same location where this exe file is located\nplease click enter to exit";
		string temp{ "" };
		cin >> temp;
	}
}

void AddDoublicateComodities()
{
	vector<pair<Shop, PurchasedCommodity>> purchasedItemsNew{};
	Shop s("","", "",0);
	PurchasedCommodity p("",0.0f,0.0f,0.0f);
	pair<Shop, PurchasedCommodity>  nullPair;

	nullPair.first = s;
	nullPair.second = p;

	//--------combining doubles------------------
	for (int i=0; i < purchasedItems.size(); i++)
	{
		if (purchasedItems[i].first.GetShopName() != nullPair.first.GetShopName())
		{
			for (int j = i+1; j < purchasedItems.size(); j++)
			{
				if (purchasedItems[i].first.GetShopName() == purchasedItems[j].first.GetShopName() && purchasedItems[i].second.GetCommodityName() == purchasedItems[j].second.GetCommodityName())
				{
					purchasedItems[i].second.SetPurchasedAmount(purchasedItems[j].second.GetPurchasedAmmount());
					purchasedItems[j] = nullPair;
				}
			}
			purchasedItemsNew.push_back(purchasedItems[i]);
		}
	}

	//-------sorting same shops together---------

	for (int i = 0; i < purchasedItemsNew.size() - 1; i++)
	{
		if (purchasedItemsNew[i].first.GetShopName() != purchasedItemsNew[i + 1].first.GetShopName())
		{
			for (int j = i; j < purchasedItemsNew.size(); j++)
			{
				if (purchasedItemsNew[j].first.GetShopName() == purchasedItemsNew[i].first.GetShopName())
				{
					swap(purchasedItemsNew[i + 1], purchasedItemsNew[j]);
				}
			}
		}
	}

	purchasedItems = purchasedItemsNew;
}
