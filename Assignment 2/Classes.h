#pragma once

enum TYPE {
	KITCHEN_K, BUTTER_K, ROLLING_PIN,
	HANDLE, I_SPOON, I_BLOWER, I_KNIFEKITCHEN, I_KNIFEBUTTER, I_KNIFEBREAD, I_ROLLING, I_KEY };

class Item
{
private:
	TYPE variation;
	std::string name;
	std::string ability;
public:
	Item() {};

	Item(std::string n, std::string a, TYPE v)
	{
		name = n;
		ability = a;
		variation = v;
	}
	TYPE getType()
	{
		return variation;
	}

	std::string getName()
	{
		return name;
	}

	std::string getAbility()
	{
		return ability;
	}

	friend std::ostream& operator<<(std::ostream& os, const Item& obj)
	{
		os << "|| " << obj.name << " ||";
		return os;
	}
};

template <class T>
class Inventory
{
private:
	class InventorySlot
	{
		friend class Inventory;
		T item;
		InventorySlot* next;
		// Constructor
		InventorySlot(T item1, InventorySlot* next1 = nullptr)
		{
			item = item1;
			next = next1;
		}
	};
	InventorySlot* top;
public:
	Inventory() { top = nullptr; }

	void push(T item)
	{
		top = new InventorySlot(item, top);
	}

	void pop(T& item)
	{
		InventorySlot* temp;

		if (isEmpty())
		{
			std::cout << "The stack is empty.\n";
			exit(1);
		}
		else   // Pop value off top of stack
		{
			item = top->item;
			temp = top;
			top = top->next;
			delete temp;
		}
	}

	void displayInventory(InventorySlot* ptr)
	{
		if (ptr != nullptr)
		{
			std::cout << "\n\n " << ptr->item << std::endl;
			displayInventory(ptr->next);
		}
		else
		{
			if (isEmpty())
				std::cout << " Mr. Emptypockets over here.." << std::endl;
			
				std::cout << "\n Tip: You can use objects from your inventory\n by typing USE and item's name in specific situations!" << std::endl;
		}
	}

	bool isEmpty() const
	{

		if (!top)
			return true;
		else
			return false;
	}

	InventorySlot* getTop()
	{
		return top;
	}
};


Inventory<Item> Pockets;
Item Spoon("Spoon", "Key", I_SPOON);
Item Key("Key", "Key", I_KEY);
Item Blower("Dryer", "Fight", I_BLOWER);
Item KitchenKnife("Kitchen Knife", "Fight", I_KNIFEKITCHEN);
Item ButterKnife("Butter Knife", "Fight", I_KNIFEBUTTER);
Item BreadKnife("Bread Knife", "Fight", I_KNIFEBREAD);
Item RollingPin("Rolling Pin", "Fight", I_ROLLING);