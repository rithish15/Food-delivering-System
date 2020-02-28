// Some standard headers
#include <iostream> // std::cin, std::cout
#include <fstream> // std::ofstream
#include <cstdio> // stricmp()
#include <iomanip> // std::setw(), std::setfill()
#include <string> // std::string
#include <cctype> // isdigit()
#include <vector> // std::vector
#include <cstdlib> // system(), itoa(), rand(), srand()
#include <conio.h> // getchr()
#include <ctime> // time()
#include <sstream> // std::stringstream
#include <cstring> // stricmp()
#include <windows.h> // GetStdHandle(), SetConsoleTextAttribute()
#include <algorithm> // std::reverse()

using namespace std;

int stricmp(const char * pStr1, const char *pStr2)
{
    char c1, c2;
    int  v;

    do {
        c1 = *pStr1++;
        c2 = *pStr2++;
        /* The casts are necessary when pStr1 is shorter & char is signed */
        v = (unsigned int) tolower(c1) - (unsigned int) tolower(c2);
    } while ((v == 0) && (c1 != '\0') && (c2 != '\0') );

    return v;
}

char *itoa(int i, char *buffer, int n = 10)
{
   std::string str;
   do
   {
       str += (char)('0' + (i % 10)); i /= 10;
   }while(i != 0);
    
   std::reverse(str.begin(), str.end());

   strcpy(buffer, str.c_str());
   return buffer;
}

// This code works on Windows only. In case if the program needs to be run on another platform, we can easily change the function and that's it.

enum
{
	Color_White = 7,
	Color_Yellow = 14,
	Color_Purple = 13,
	Color_Green = 10, 
	Color_Bright_White = 15,
	Color_Light_Blue = 11,
	Color_Pink_Blue_Background = 23,
	Color_Red = 12
};

static std::ostream& setConsoleTextColor(int myColor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,myColor);

	return cout;
}

// Some constants
const int TOTAL_ITEMS = 12;
const int ZERO_FOR_CAL = 0; // Zero for cal(calculation)
const int ONE_FOR_CAL = 1;
const int TWO_FOR_CAL = 2;
const int THREE_FOR_CAL = 3;
const int FOUR_FOR_CAL = 4;

const int MINUS_ONE_FOR_CAL = -1; 

// General item structure for all restaurants
struct Item_Raw
{
	char name[100];
	char description[500];
	double price;	
};

// Global Restaurant Appetizer Items
enum
{
	Item_Crispy_Crab_Wontons = 0,
	Item_Presunto_Pot_Stickers,
	Item_Crab_Cakes
};

// Global Restaurant Main Dishes Items
enum
{
	Item_Presunto_And_Ricotta_Flatbread = Item_Crab_Cakes + 1,
	Item_Fresh_Kale_Salad,
	Item_Shrimp_Scampi,
};

// Global Restaurant Beverages Items
enum
{
	Item_Fresh_Orange_Juice_Infused_With_Passion_Fruit_Seeds = Item_Shrimp_Scampi + 1,
	Item_Cold_Green_Ice_Tea,
	Item_Flavored_Lemonades
};

// Global Restaurant Desserts Items
enum
{
	Item_Lemoncello_Cream_Torte = Item_Flavored_Lemonades + 1,
	Item_Chocolate_Tower_Truffle_Cake,
	Item_Warm_Apple_Crisp
};


// Quick-initialization can be done if we use a char array instead of a std::string
Item_Raw globalRestaurantItems[TOTAL_ITEMS] = {
// Restaurant Appetizer
	{
		"Crispy Crab Wontons", 
		"Crabmeat Blended with Cream Cheese, Green Onion, Water Chestnuts and Sweet Chili Sauce Fried Crisp in Wonton Wrappers.",
		6.50
	},
	{
		"Presunto pot stickers", 
		"Asian Dumplings Pan-Fried in the Classic Tradition. Served with Our Soy-Ginger Sesame Sauce.",
		5.50
	},
	{
		"Crab cakes", 
		"Served with Mustard and Tartar Sauce.",
		6.50
	},

// Restaurant Main Dishes
	{
		"Presunto and Ricotta Flatbread", 
		"Fontina, Parmesan and Romano Cheeses with Kale and Herbs.",
		10.50
	},
	{
		"Fresh Kale Salad", 
		"Apples, Marcona Almonds, Golden Raisins and Green Beans Tossed with Our Buttermilk-Black Pepper Dressing.",
		7.50
	},
	{
		"Shrimp Scampi", 
		"Bistro-Style! Saute'ed with Whole Cloves of Garlic, White Wine, Fresh Basil and Tomato. Served with Angel Hair Pasta.",
		14.50
	},

// Restaurant Beverages
	{
		"Fresh Orange Juice infused with Passion fruit seeds", 
		"Hand-squeezed daily.",
		4.50
	},
	{
		"Cold Green Ice Tea", 
		"Cold green ice tea infused with mint.",
		2.50
	},
	{
		"Flavored Lemonades", 
		"Strawberry, Raspberry, Hibiscus or Cucumber.",
		3.50
	},

// Restaurant Desserts
	{
		"Lemoncello Cream Torte", 
		"Layers of Vanilla Cake and Lemon Mascarpone Cream Topped with Streusel and Served with Strawberries and Whipped Cream.",
		4.50
	},
	{
		"Chocolate Tower Truffle Cake", 
		"Layers and Layers of Fudge Cake with Chocolate Truffle Cream and Chocolate Mousse.",
		4.50
	},
	{
		"Warm Apple Crisp", 
		"Our Delicious Crispy Nutty Topping and Vanilla Ice Cream.",
		4.50
	}
};


// Some constant
const double TEXAS_RESTAURANT_TAX = 0.0825;

// An item structure for an user-defined restaurant
class Item
{
private : 
	std::string name;
	std::string description;
	double price;

public : 
	void importItem(const Item_Raw &item);

	void setName(std::string _name);

	void setDescription(std::string _description);

	void setPrice(double _price);

	void setItem(std::string _name, std::string _description, double _price);

	std::string getName() const;

	std::string getDescription() const;

	double getPrice() const;
};

// User-defined restaurant items
enum RestaurantAppetizer
{
	Restaurant_Appetizer_1,
	Restaurant_Appetizer_2,
	Restaurant_Appetizer_3
};

enum RestaurantMainDishes
{
	Restaurant_Main_Dishes_1,
	Restaurant_Main_Dishes_2,
	Restaurant_Main_Dishes_3
};

enum RestaurantBeverages
{
	Restaurant_Beverages_1,
	Restaurant_Beverages_2,
	Restaurant_Beverages_3
};

enum RestaurantDesserts
{
	Restaurant_Desserts_1,
	Restaurant_Desserts_2,
	Restaurant_Desserts_3
};

// User-defined restaurant constants
const int RESTAURANT_APPETIZER_ITEMS = 3;
const int RESTAURANT_MAIN_DISHES_ITEMS = 3;
const int RESTAURANT_BEVERAGES_ITEMS = 3;
const int RESTAURANT_DESSERTS_ITEMS = 3;

class Restaurant
{
private : 
	Item restaurantAppetizerItems[RESTAURANT_APPETIZER_ITEMS];
	Item restaurantMainDishesItems[RESTAURANT_MAIN_DISHES_ITEMS];
	Item restaurantBeveragesItems[RESTAURANT_BEVERAGES_ITEMS];
	Item restaurantDessertsItems[RESTAURANT_DESSERTS_ITEMS];
		
	public : 
		
	// The receipt structure for the user-defined Restaurant
	struct Receipt
	{
		Receipt()
		{
			totalPrice = 0;
			taxPrice = 0;
			gratuity = 0;			
		}

		vector<Item> itemsOrdered;

		double totalPrice;
		double taxPrice;
		double gratuity;
	};

	// Default constructor
	Restaurant();

	// Default constructor will also call this function
	void initialize();

	// Show restaurant menu (If bHelp is toggled, the restaurant will show the customer how food items are ordered)
	void showMenu(bool bHelp = false);

	// Show restaurant help
	void showHelp();

	// Validate the customer's choice
	// Returns -1 if fails, 0 if no action should be taken, and 1 if successful
	int getInput(Item &theItem);

	// Formatting function
	static std::string printName(const std::string &s, int len = 0);

	// Generates a Html Receipt
	static std::string generateReceiptHtml(const Receipt &myReceipt);

	// A customer has entered the restaurant. Run the restaurant
	void runRestaurant();

private : 

	// A helper function for Restaurant::getInput()
	// Return 0 if successful, 1 to proceed to order, -1 if fails
	int getDescription(unsigned int category, unsigned int item_id);

	// A helper function for Restaurant::getInput()
	// Return 1 if successful, -1 if fails
	int getPrice(unsigned int category, unsigned int item_id, Item &theItem);

	// A helper function for Restaurant::getInput()
	// Return false (0) if no action should be taken, and return true (1) otherwise
	static int descriptionOrder(const Item &item);

	// A helper function for Restaurant::getInput() and Restaurant::getPrice()
	// This indicates that an order is completed. 
	static void completeOrder(const Item &item, Item &theItem);
};

	void Item::importItem(const Item_Raw &item)
	{
		setName(item.name);
		setDescription(item.description);
		setPrice(item.price);
	}

	void Item::setName(std::string _name)
	{
		name = _name;
	}

	void Item::setDescription(std::string _description)
	{
		description = _description;
	}

	void Item::setPrice(double _price)
	{
		price = _price;
	}

	void Item::setItem(std::string _name, std::string _description, double _price)
	{
		setName(_name);
		setDescription(_description);
		setPrice(_price);
	}

	std::string Item::getName() const 
	{
		return name;
	}

	std::string Item::getDescription() const 
	{
		return description;
	}

	double Item::getPrice() const
	{
		return price;
	}

	Restaurant::Restaurant() {initialize();}

	void Restaurant::initialize()
	{
		restaurantAppetizerItems[Restaurant_Appetizer_1].importItem(globalRestaurantItems[Item_Crispy_Crab_Wontons]);
		restaurantAppetizerItems[Restaurant_Appetizer_2].importItem(globalRestaurantItems[Item_Presunto_Pot_Stickers]);
		restaurantAppetizerItems[Restaurant_Appetizer_3].importItem(globalRestaurantItems[Item_Crab_Cakes]);

		restaurantMainDishesItems[Restaurant_Main_Dishes_1].importItem(globalRestaurantItems[Item_Presunto_And_Ricotta_Flatbread]);
		restaurantMainDishesItems[Restaurant_Main_Dishes_2].importItem(globalRestaurantItems[Item_Fresh_Kale_Salad]);
		restaurantMainDishesItems[Restaurant_Main_Dishes_3].importItem(globalRestaurantItems[Item_Shrimp_Scampi]);

		restaurantBeveragesItems[Restaurant_Beverages_1].importItem(globalRestaurantItems[Item_Fresh_Orange_Juice_Infused_With_Passion_Fruit_Seeds]);
		restaurantBeveragesItems[Restaurant_Beverages_2].importItem(globalRestaurantItems[Item_Cold_Green_Ice_Tea]);
		restaurantBeveragesItems[Restaurant_Beverages_3].importItem(globalRestaurantItems[Item_Flavored_Lemonades]);

		restaurantDessertsItems[Restaurant_Desserts_1].importItem(globalRestaurantItems[Item_Lemoncello_Cream_Torte]);
		restaurantDessertsItems[Restaurant_Desserts_2].importItem(globalRestaurantItems[Item_Chocolate_Tower_Truffle_Cake]);
		restaurantDessertsItems[Restaurant_Desserts_3].importItem(globalRestaurantItems[Item_Warm_Apple_Crisp]);
	}

	// This function guarantees all the strings will have the same length, making it easier to format the output
	std::string Restaurant::printName(const std::string &s, int len)
	{
		int i;
		std::string str = s;

		len -= s.size();
		for(i = 0; i < len; i++) str += ' ';
		
		return str;
	}

	void Restaurant::showMenu(bool bHelp)
	{
		int i;
		int len;
		const int len_max = 65;

		system("cls");
		cout << setfill(' ');
		setConsoleTextColor(Color_Bright_White) << setw((len_max + 10) / 2 + (len_max + 10) / 4) << "Sabor Intenso Restaurant Menu : " << endl;
		setConsoleTextColor(Color_White) << endl;

		cout.setf(ios::fixed);
		cout.precision(2);

		len = restaurantAppetizerItems[0].getName().size();
		for(i = 1; i < RESTAURANT_APPETIZER_ITEMS; i++)
		{
			if(len < restaurantAppetizerItems[i].getName().size()) len = restaurantAppetizerItems[i].getName().size();
		}
		len += 1;
		
		cout << setfill('-');

		setConsoleTextColor(Color_Yellow) << "A";
		setConsoleTextColor(Color_White) << ". ";
		setConsoleTextColor(Color_Pink_Blue_Background) << "Appretizer";
		setConsoleTextColor(Color_White) << " : " << endl;

		for(i = 0; i < RESTAURANT_APPETIZER_ITEMS; i++)
		{
			setConsoleTextColor(Color_Purple) << " " << i + 1 << ". ";
			setConsoleTextColor(Color_White) << printName(restaurantAppetizerItems[i].getName(), len) << setw(len_max - len);
			setConsoleTextColor(Color_Yellow) << "$ " << restaurantAppetizerItems[i].getPrice() << endl;
		}
		cout << endl;

		len = restaurantMainDishesItems[0].getName().size();
		for(i = 1; i < RESTAURANT_MAIN_DISHES_ITEMS; i++)
		{
			if(len < restaurantMainDishesItems[i].getName().size()) len = restaurantMainDishesItems[i].getName().size();
		}
		len += 1;
		
		cout << setfill('-');

		setConsoleTextColor(Color_Yellow) << "B";
		setConsoleTextColor(Color_White) << ". ";
		setConsoleTextColor(Color_Pink_Blue_Background) << "Main Dishes";
		setConsoleTextColor(Color_White) << " : " << endl;

		for(i = 0; i < RESTAURANT_MAIN_DISHES_ITEMS; i++)
		{
			setConsoleTextColor(Color_Purple) << " " << i + 1 << ". ";
			setConsoleTextColor(Color_White) << printName(restaurantMainDishesItems[i].getName(), len) << setw(len_max - len);
			setConsoleTextColor(Color_Green) << "$ " << restaurantMainDishesItems[i].getPrice() << endl;
		}
		cout << endl;

		len = restaurantBeveragesItems[0].getName().size();
		for(i = 1; i < RESTAURANT_BEVERAGES_ITEMS; i++)
		{
			if(len < restaurantBeveragesItems[i].getName().size()) len = restaurantBeveragesItems[i].getName().size();
		}
		len += 1;
		
		cout << setfill('-');

		setConsoleTextColor(Color_Yellow) << "C";
		setConsoleTextColor(Color_White) << ". ";
		setConsoleTextColor(Color_Pink_Blue_Background) << "Beverages";
		setConsoleTextColor(Color_White) << " : " << endl;

		for(i = 0; i < RESTAURANT_BEVERAGES_ITEMS; i++)
		{
			setConsoleTextColor(Color_Purple) << " " << i + 1 << ". ";
			setConsoleTextColor(Color_White) << printName(restaurantBeveragesItems[i].getName(), len) << setw(len_max - len);
			setConsoleTextColor(Color_Yellow) << "$ " << restaurantBeveragesItems[i].getPrice() << endl;
		}
		cout << endl;

		len = restaurantDessertsItems[0].getName().size();
		for(i = 1; i < RESTAURANT_DESSERTS_ITEMS; i++)
		{
			if(len < restaurantDessertsItems[i].getName().size()) len = restaurantDessertsItems[i].getName().size();
		}
		len += 1;
		
		cout << setfill('-');

		setConsoleTextColor(Color_Yellow) << "D";
		setConsoleTextColor(Color_White) << ". ";
		setConsoleTextColor(Color_Pink_Blue_Background) << "Desserts";
		setConsoleTextColor(Color_White) << " : " << endl;

		for(i = 0; i < RESTAURANT_DESSERTS_ITEMS; i++)
		{
			setConsoleTextColor(Color_Purple) << " " << i + 1 << ". ";
			setConsoleTextColor(Color_White) << printName(restaurantDessertsItems[i].getName(), len) << setw(len_max - len);
			setConsoleTextColor(Color_Green) << "$ " << restaurantDessertsItems[i].getPrice() << endl;
		}
		cout << endl;

		setConsoleTextColor(Color_White);


		if(bHelp == true) showHelp();
	}

	void Restaurant::showHelp()
	{
		cout << "How to order an item : \n";
		cout << "+ ";
		setConsoleTextColor(Color_Purple) << 'A';
		setConsoleTextColor(Color_White) << ", ";
		setConsoleTextColor(Color_Purple) << 'B';
		setConsoleTextColor(Color_White) << ", ";
		setConsoleTextColor(Color_Purple) << 'C';
		setConsoleTextColor(Color_White) << ", or ";
		setConsoleTextColor(Color_Purple) << "D ";
		setConsoleTextColor(Color_White) << "to select a category, and ";
		
		setConsoleTextColor(Color_Purple) << '1';
		setConsoleTextColor(Color_White) << ", ";
		setConsoleTextColor(Color_Purple) << '2';
		setConsoleTextColor(Color_White) << ", or ";
		setConsoleTextColor(Color_Purple) << "3 ";
		setConsoleTextColor(Color_White) << "to order the desired item\n";

		switch(rand() % 2)
		{
			case 0 :
			{
				cout << "+ E.g : If you choose ";
				setConsoleTextColor(Color_Bright_White) << "C2";
				setConsoleTextColor(Color_White) << ", you are ordering the '";

				setConsoleTextColor(Color_Green) << "Cold Green Ice Tea";
				setConsoleTextColor(Color_White) << "' item\n\n";
			}
			break;
			default : 
			{
				cout << "+ E.g : If you choose ";
				setConsoleTextColor(Color_Bright_White) << "B2";
				setConsoleTextColor(Color_White) << ", you are ordering the '";

				setConsoleTextColor(Color_Green) << "Fresh Kale Salad";
				setConsoleTextColor(Color_White) << "' item\n\n";
			}
			break;
		}

		cout << "How to get food description : \n";
		cout << "+ Append a '";

		setConsoleTextColor(Color_Purple) << 'H';
		setConsoleTextColor(Color_White) << "' character at the end of your choice to get description\n";
		cout << "+ For example, to get the food description of the item '";

		setConsoleTextColor(Color_Green) << "Crab cakes";
		setConsoleTextColor(Color_White) << "', type '";
		setConsoleTextColor(Color_Bright_White) << "A3H";
		setConsoleTextColor(Color_White) << "'\n\n";	
	}

	void Restaurant::completeOrder(const Item &item, Item &theItem)
	{

		cout << "+ You have successfully ordered : '";
		setConsoleTextColor(Color_Green) << item.getName();
		setConsoleTextColor(Color_White) << "'" << endl;
		setConsoleTextColor(Color_White) << "+ Your order's price : ";
		setConsoleTextColor(Color_Light_Blue) << item.getPrice() << "$";
		setConsoleTextColor(Color_White) << endl;

		theItem = item;
	}

	// Return false (0) if no action should be taken, and return true (1) otherwise
	int Restaurant::descriptionOrder(const Item &item)
	{
		std::string choice;

		cout << "+ The item : '";
		setConsoleTextColor(Color_Green) << item.getName();
		setConsoleTextColor(Color_White) << "'" << endl;
		cout << "  " << item.getDescription() << endl;		
		cout << "+ Item price : ";
		setConsoleTextColor(Color_Light_Blue) << item.getPrice() << "$";
		setConsoleTextColor(Color_White) << endl << endl;

		// Random response may be a good feature
		if(rand() % 100 >= 50)
		{
			cout << "Do you want to order this one? (";
			setConsoleTextColor(Color_Yellow) << "Y";
			setConsoleTextColor(Color_White) << " to proceed) : "; 
			
			setConsoleTextColor(Color_Yellow);
			cin >> choice;
			setConsoleTextColor(Color_White);
		}
		else
		{
			cout << "Would you like to order this one? (";
			setConsoleTextColor(Color_Yellow) << "Y";
			setConsoleTextColor(Color_White) << " to proceed) : "; 
			
			setConsoleTextColor(Color_Yellow);
			cin >> choice;
			setConsoleTextColor(Color_White);
		}

		if(stricmp(choice.c_str(), "Y") == ZERO_FOR_CAL || stricmp(choice.c_str(), "Yes") == ZERO_FOR_CAL)
		{
			// Proceed to order
			return ONE_FOR_CAL;
		}
		else if(stricmp(choice.c_str(), "N") == ZERO_FOR_CAL || stricmp(choice.c_str(), "No") == ZERO_FOR_CAL)
		{
			cout << endl;
			cout << "+ You chose not to order the '";
			setConsoleTextColor(Color_Green) << item.getName();
			setConsoleTextColor(Color_White) << "' item" << endl;
			cout << "+ Please press any key to resume your ordering. . ."; getch();
		}

		// Don't want to order yet
		return ZERO_FOR_CAL;
	}


	// Return 0 if successful, 1 to proceed to order, -1 if fails
	int Restaurant::getDescription(unsigned int category, unsigned int item_id)
	{
		switch(category)
		{
			case ZERO_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_APPETIZER_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				return descriptionOrder(restaurantAppetizerItems[item_id]);
			}
			break;
			case ONE_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_MAIN_DISHES_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				return descriptionOrder(restaurantMainDishesItems[item_id]);
			}
			break;
			case TWO_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_BEVERAGES_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				return descriptionOrder(restaurantBeveragesItems[item_id]);
			}
			break;
			case THREE_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_DESSERTS_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				return descriptionOrder(restaurantDessertsItems[item_id]);
			}
			break;
		}

		return 0;
	}

	// Return 1 if successful, -1 if fails
	int Restaurant::getPrice(unsigned int category, unsigned int item_id, Item &theItem)
	{
		switch(category)
		{
			case ZERO_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_APPETIZER_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				completeOrder(restaurantAppetizerItems[item_id], theItem);
			}
			break;
			case ONE_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_MAIN_DISHES_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				completeOrder(restaurantMainDishesItems[item_id], theItem);
			}
			break;
			case TWO_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_BEVERAGES_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				completeOrder(restaurantBeveragesItems[item_id], theItem);
			}
			break;
			case THREE_FOR_CAL : 
			{
				if(item_id >= RESTAURANT_DESSERTS_ITEMS)
				{
					cout << "+ You have selected the wrong food item. Please try again." << endl; 
					cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
				}
				completeOrder(restaurantDessertsItems[item_id], theItem);
			}
			break;
		}

		return 1;
	}

	// Returns -1 if fails, 0 if no action is taken, and 1 if successful
	int Restaurant::getInput(Item &theItem)
	{
		int retValue;
		unsigned int item_id = ZERO_FOR_CAL;
		std::string choice;

		cout << "What do you want to order : ";
		switch(rand() % 4)
		{
			case 0 : setConsoleTextColor(Color_Bright_White); break;
			case 1 : setConsoleTextColor(Color_Yellow); break;
			case 2 : setConsoleTextColor(Color_Light_Blue); break;
			default : setConsoleTextColor(Color_Purple); break;
		}
		cin >> choice;

		setConsoleTextColor(Color_White); 

		if(choice.size() > THREE_FOR_CAL)
		{
			cout << "+ You have made an invald choice. Please try again." << endl; 
			cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
		}

		if(isdigit(choice[ONE_FOR_CAL]))
		{
			item_id = (choice[ONE_FOR_CAL] - '0');
		}
		else
		{
			cout << "+ You have made an invald choice. Please try again." << endl; 
			cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
		}

		if(choice.size() == THREE_FOR_CAL)
		{
			if(toupper(choice[TWO_FOR_CAL]) != 'H')
			{
				cout << "+ You have made an invald choice. Please try again." << endl; 
				cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;	
			}
			else
			{
				switch(toupper(choice[ZERO_FOR_CAL]))
				{
					case 'A' : retValue = getDescription(ZERO_FOR_CAL, item_id - 1); break;
					case 'B' : retValue = getDescription(ONE_FOR_CAL, item_id - 1); break;
					case 'C' : retValue = getDescription(TWO_FOR_CAL, item_id - 1); break;
					case 'D' : retValue = getDescription(THREE_FOR_CAL, item_id - 1); break;
					default : 
						cout << "+ You have made an invalid choice. Please try again." << endl; 
						cout << "+ Please press any key to resume your ordering. . ."; getch(); retValue = MINUS_ONE_FOR_CAL;
					break;
				}
				if(retValue <= ZERO_FOR_CAL) return retValue;
			}
		}


		switch(toupper(choice[ZERO_FOR_CAL]))
		{
			case 'A' : return getPrice(ZERO_FOR_CAL, item_id - 1, theItem); break;
			case 'B' : return getPrice(ONE_FOR_CAL, item_id - 1, theItem); break;
			case 'C' : return getPrice(TWO_FOR_CAL, item_id - 1, theItem); break;
			case 'D' : return getPrice(THREE_FOR_CAL, item_id - 1, theItem); break;
			default : 
				cout << "+ You have made an invalid choice. Please try again." << endl;
				cout << "+ Please press any key to resume your ordering. . ."; getch(); return MINUS_ONE_FOR_CAL;
			break;
		}
		return ONE_FOR_CAL;
	}

	std::string Restaurant::generateReceiptHtml(const Receipt &myReceipt)
	{
		int i;
		char buffer[300];
		stringstream ss;
		std::string fileName = "Receipt_ID";

		int file_id = 1000 + rand() % 9000;

		fileName += (itoa(file_id, buffer, 10), buffer);
		fileName += ".html";

		ofstream myFile(fileName.c_str());

		myFile << "<html>\n";
		myFile << "<head>\n";

		myFile << "<meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\" />\n";
		myFile << "<style type=\"text/css\">\n";
		myFile << "td, th {border: 1px solid black;}\n";
		myFile << "</style>\n";

		myFile << "<title>" << "Sabor Intenso Restaurant Receipt" << "</title>\n";
		myFile << "</head>\n";

		myFile << "<body background= \"bg_001.jpg\">\n";
		myFile << "<font face=\"verdana\" size=\"6\">" << "<center>" << "Sabor Intenso Restaurant Receipt" << "</center>"  << "</font>" ;

		myFile << "<br>\n";

		myFile << "<font face=\"verdana\" size=\"4\">";

		myFile << "<table style=\"width: 100%\">\n";
		myFile << "<tr bgcolor=\"#FFFF00\">\n";
		myFile << "<th>" << "Id" << "</th>\n";
		myFile << "<th>" << "Item name" << "</th>\n";
		myFile << "<th>" << "Item price" << "</th>\n";
		myFile << "<th>" << "Total" << "</th>\n";
		myFile << "</tr>\n";

		for(i = 0; i < myReceipt.itemsOrdered.size(); i++)
		{
			if(i % 2 == 0)
			myFile << "<tr bgcolor=\"#FFBBBB\">\n";
			else
			myFile << "<tr bgcolor=\"#BBFFBB\">\n";

			myFile << "<td>" << "<center>" << itoa(i + 1, buffer, 10) << "</center>" << "</td>\n";
			myFile << "<td>" << "<center>" << myReceipt.itemsOrdered[i].getName().c_str() << "</center>" << "</td>\n";

			ss.str("");
			ss.clear();
	
			ss.setf(ios::fixed);
			ss.precision(2);

			ss << "$" << myReceipt.itemsOrdered[i].getPrice();
			myFile << "<td>" << "<center>" << ss.str().c_str() << "</center>" << "</td>\n";
			myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";

			myFile << "</tr>\n";
		}


			myFile << "<tr bgcolor=\"#CCCCFF\">\n";
			myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
			myFile << "<td>" << "<center>" << "<b>" << "Subtotal" << "</b>" << "</center>" << "</td>\n";

			ss.str("");
			ss.clear();

			ss << "$" << myReceipt.totalPrice;
			myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
			myFile << "<td>" << "<center>" << "<b>" << ss.str().c_str() << "</b>" << "</center>" << "</td>\n";

			myFile << "</tr>\n";

			myFile << "<tr bgcolor=\"#CCCCFF\">\n";

			myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
			myFile << "<td>" << "<center>" << "<b>" << "Tax" << "</b>" << "</center>" << "</td>\n";

			ss.str("");
			ss.clear();

			ss << "$" << myReceipt.taxPrice;
			myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
			myFile << "<td>" << "<center>" << "<b>" << ss.str().c_str() << "</b>" << "</center>" << "</td>\n";

			myFile << "</tr>\n";

			if(myReceipt.gratuity > 0)
			{
				myFile << "<tr bgcolor=\"#CCCCFF\">\n";

				myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
				myFile << "<td>" << "<center>" << "<b>" << "Gratuity" << "</b>" << "</center>" << "</td>\n";

				ss.str("");
				ss.clear();

				ss << "$" << myReceipt.gratuity;
				myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
				myFile << "<td>" << "<center>" << "<b>" << ss.str().c_str() << "</b>" << "</center>" << "</td>\n";

				myFile << "</tr>\n";
			}

		myFile << "<tr bgcolor=\"#BBBBFF\">\n";

		myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
		myFile << "<td>" << "<center>" << "<b>" << "Total price" << "</b>" << "</center>" << "</td>\n";

		ss.str("");
		ss.clear();

		ss << "$" << (myReceipt.totalPrice + myReceipt.taxPrice + myReceipt.gratuity);
		myFile << "<td>" << "<center>" << "---" << "</center>" << "</td>\n";
		myFile << "<td>" << "<center>" << "<b>" << "<font face=\"verdana\" size=\"4\" color=\"#454500\">" << ss.str().c_str() << "</font>" << "</b>" << "</center>" << "</td>\n";

		myFile << "</tr>\n";
		myFile << "</table>\n";

		myFile << "<h4>" << "<center>" << "-- -- --Thank you for your business-- -- --" << "</h4>" << "</center>\n";

		myFile << "</font>";

		myFile << "</body>\n";
		myFile << "</html>\n";

		myFile.close();
		return fileName;
	}

	void Restaurant::runRestaurant()
	{
		int i, k, len;
		Restaurant &myRestaurant = (*this); // An useful trick, since the code is moved from function main()
		Restaurant::Receipt myReceipt;

		const int len_max = 65;
		const int len2 = 4;
		
		int retValue;

		Item theItem;
		std::string choice;

		srand(time(NULL));

		bool bHelpNeeded = true;
		bool bFinishedOrdering = false;
		while(bFinishedOrdering == false)
		{
			myRestaurant.showMenu(bHelpNeeded);

			k = (int)myReceipt.itemsOrdered.size() - 1;

			if(k >= 0)
			{
				cout << "Your previous order : ";
				setConsoleTextColor(Color_Green) << myReceipt.itemsOrdered[k].getName();
				setConsoleTextColor(Color_White) << " (";
				setConsoleTextColor(Color_Light_Blue) << myReceipt.itemsOrdered[k].getPrice() << "$";
				setConsoleTextColor(Color_White) << ")" << endl;
			}

			if((retValue = myRestaurant.getInput(theItem)) > ZERO_FOR_CAL)
			{
				bHelpNeeded = false;
				myReceipt.itemsOrdered.push_back(theItem);
				myReceipt.totalPrice += theItem.getPrice();

				cout << "+ Total items you have ordered : ";
				setConsoleTextColor(Color_Yellow) << myReceipt.itemsOrdered.size() << endl;
				setConsoleTextColor(Color_White) << "+ Total price (without tax) : ";
				setConsoleTextColor(Color_Yellow) << myReceipt.totalPrice << "$";
				setConsoleTextColor(Color_White) << endl;

				cout << endl;
				cout << "+ Do you want to order more (";
				setConsoleTextColor(Color_Yellow) << "Y";
				setConsoleTextColor(Color_White) << " to continue) : "; 
				
				setConsoleTextColor(Color_Yellow);
				cin >> choice;
				setConsoleTextColor(Color_White);

				// If the customer chooses "Y", the program will continue to prompt the customer for order.
				// Otherwise, the program will simply interpret the user response as "No" and stop the ordering
				if(stricmp(choice.c_str(), "Y") == ZERO_FOR_CAL || stricmp(choice.c_str(), "Yes") == ZERO_FOR_CAL)
				{
					bFinishedOrdering = false;
				}
				else
				{
					bFinishedOrdering = true;			
				}
			}
			else
			{
				if(retValue < ZERO_FOR_CAL)
				{
					// In case a customer made an invalid choice, the restaurant will provide the user with additional information
					//  so that the customer makes a valid choice next time
					bHelpNeeded = true; 
				}
				else 
				{
					bHelpNeeded = false;
				}
			}
		}

		myReceipt.taxPrice = (myReceipt.totalPrice * TEXAS_RESTAURANT_TAX);

		cout << endl;
		setConsoleTextColor(Color_Bright_White) << "You have finished ordering ";
		setConsoleTextColor(Color_Yellow) << myReceipt.itemsOrdered.size();
		setConsoleTextColor(Color_Bright_White) << " items";
		setConsoleTextColor(Color_White) << endl;

		// Handling Gratuity (If any)
		double gratuity_temp;
		if(rand() % 100 >= 55)
		{
			if(rand() % 100 >= 50)
			myReceipt.gratuity = myReceipt.totalPrice * 0.20;
			else
			myReceipt.gratuity = myReceipt.totalPrice * 0.15;

			// When it comes to gratuity, customers can only afford to "pay" with their own money notes
			// We have to round the (gratuity) of course, and round to the nearest exact unit (0.25$ per unit each)
			for(gratuity_temp = 0.25; gratuity_temp < myReceipt.gratuity; gratuity_temp += 0.25)
			{
				if(gratuity_temp + 0.25 > myReceipt.gratuity) break;
			}

			myReceipt.gratuity = gratuity_temp;
			setConsoleTextColor(Color_Bright_White) << "Your gratuity : ";
			setConsoleTextColor(Color_Green) << "$" << myReceipt.gratuity << endl;
		}

		len = myReceipt.itemsOrdered[0].getName().size();
		for(i = 1; i < myReceipt.itemsOrdered.size(); i++)
		{
			if(len < myReceipt.itemsOrdered[i].getName().size()) len = myReceipt.itemsOrdered[i].getName().size();
		}
		len += 1;

		cout << setfill('-');
		for(i = 0; i < myReceipt.itemsOrdered.size(); i++)
		{
			setConsoleTextColor(Color_Yellow) << " " << i + 1 << ". ";
			setConsoleTextColor(Color_White) << Restaurant::printName(myReceipt.itemsOrdered[i].getName(), len) << setw(len_max - len);
			setConsoleTextColor(Color_Light_Blue) << "$" << myReceipt.itemsOrdered[i].getPrice() << endl;
		}
		cout << endl;

		setConsoleTextColor(Color_Bright_White) << Restaurant::printName(" Subtotal : ", len) << setw(len_max - len + len2);
		
		setConsoleTextColor(Color_Yellow);
		cout << "$" << myReceipt.totalPrice << endl; 
		setConsoleTextColor(Color_White);

		setConsoleTextColor(Color_Bright_White) << Restaurant::printName(" Tax : ", len) << setw(len_max - len + len2);

		setConsoleTextColor(Color_Yellow);
		cout << "$" << myReceipt.taxPrice << endl; 
		setConsoleTextColor(Color_White);

		if(myReceipt.gratuity > 0)
		{
			setConsoleTextColor(Color_Green) << Restaurant::printName(" Gratuity : ", len) << setw(len_max - len + len2);
			
			setConsoleTextColor(Color_Green);
			cout << "$" << myReceipt.gratuity << endl; 	
			setConsoleTextColor(Color_White);
		}

		cout << endl;
		setConsoleTextColor(Color_Bright_White) << Restaurant::printName(" Total : ", len) << setw(len_max - len + len2);

		setConsoleTextColor(Color_Yellow);
		cout << "$" << (myReceipt.totalPrice + myReceipt.taxPrice + myReceipt.gratuity) << endl; 
		setConsoleTextColor(Color_White);

		cout << endl;

		while(true)
		{
			std::string paymentMethod;
			while(true)
			{
				cin.ignore();

				cout << "+ Do you want to pay by cash or by credit card : ";

				if(rand() % 100 >= 55)
				setConsoleTextColor(Color_Green);
				else
				setConsoleTextColor(Color_Yellow);

				getline(cin, paymentMethod);
				setConsoleTextColor(Color_White);

				if(stricmp(paymentMethod.c_str(), "cash") == 0 || stricmp(paymentMethod.c_str(), "credit card") == 0) break;

				cout << "Please enter valid choice. '";
				setConsoleTextColor(Color_Green) << "cash";
				setConsoleTextColor(Color_White) << "' or '";
				setConsoleTextColor(Color_Green) << "credit card";
				setConsoleTextColor(Color_White) << "'\n\n";
			}

			if(stricmp(paymentMethod.c_str(), "cash") == 0)
			{
				cout << "+ You have successfully pay ";

				if(rand() % 100 >= 55)
				setConsoleTextColor(Color_Yellow) << "$" << (myReceipt.totalPrice + myReceipt.taxPrice + myReceipt.gratuity);
				else
				setConsoleTextColor(Color_Light_Blue) << "$" << (myReceipt.totalPrice + myReceipt.taxPrice + myReceipt.gratuity);

				setConsoleTextColor(Color_White) << " in cash" << endl;
				break;
			}
			else
			{
				std::string card_name;
				std::string card_number;
				std::string card_expiration;
				std::string security_code;

				cout << "Please enter your card details." << endl;
				cout << Restaurant::printName("+ Name on card : ", 25); 
				getline(cin, card_name);

				cout << Restaurant::printName("+ Card number : ", 25); 
				getline(cin, card_number);

				cout << Restaurant::printName("+ Expiration : ", 25); 
				getline(cin, card_expiration);

				cout << Restaurant::printName("+ Security code : ", 25); 
				getline(cin, security_code);

				cout << endl;
				cout << "Is this above correct? (Y/N) : ";
				
				setConsoleTextColor(Color_Yellow);
				cin.ignore(1000, '\n');
				cin >> choice;
				setConsoleTextColor(Color_White);

				if(stricmp(choice.c_str(), "Y") == 0 || stricmp(choice.c_str(), "Yes") == 0)
				{
					cout << "+ You have successfully pay ";

					if(rand() % 100 >= 55)
					setConsoleTextColor(Color_Yellow) << "$" << (myReceipt.totalPrice + myReceipt.taxPrice + myReceipt.gratuity);
					else
					setConsoleTextColor(Color_Light_Blue) << "$" << (myReceipt.totalPrice + myReceipt.taxPrice + myReceipt.gratuity);

					setConsoleTextColor(Color_White) << " with your credit card" << endl;
					break;
				}
				cout << endl;
			}
		}

		std::string generatedReceipt = Restaurant::generateReceiptHtml(myReceipt);

		cout << endl;
		cout << "+ A customer receipt named '";
		setConsoleTextColor(Color_Light_Blue) << generatedReceipt;
		setConsoleTextColor(Color_White) << "' has been generated.\n";

		cout << setfill(' ');
		setConsoleTextColor(Color_Bright_White) << setw((len_max + 10) / 2 + (len_max + 10) / 4 + 2) << "--- Thanks for eating out at our restaurant ---" << endl;
		setConsoleTextColor(Color_White) << endl;

		system(generatedReceipt.c_str());

		cin.get();	
	}


int main()
{
	string choice;

	// This is my restaurant
	Restaurant myRestaurant;

	while(true)
	{
		// A customer has entered the restaurant! Begin serving him/her now
		myRestaurant.runRestaurant();

		cout << "Do you want to order again? (";
		setConsoleTextColor(Color_Yellow) << "Y";
		setConsoleTextColor(Color_White) << " to continue) : "; 
		
		setConsoleTextColor(Color_Yellow);
		cin >> choice;
		setConsoleTextColor(Color_White);

		if(stricmp(choice.c_str(), "y") == 0 || stricmp(choice.c_str(), "Yes") == 0)
		{
			// Do nothing
		}
		else
		{
			break;
		}
	}

	system("pause");

	return 0;
}
