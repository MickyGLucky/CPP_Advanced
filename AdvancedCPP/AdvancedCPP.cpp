#include <iostream>
#include <iomanip>


// Object pointer
class Item
{
	int code;
	float price;
public:
	Item(int a, float b)
	{
		code = a;
		price = b;
	};
	~Item()
	{
		std::cout << "Destructor called" << std::endl;
		std::cout << "If I allocated memory or opened something, I could clean it up here" << std::endl;
	}
	void show(void)
	{
		std::cout << "Code: " << code << std::endl;
		std::cout << "Price: " << price << std::endl;
	}
};

// Friend function
class Base
{
private:
	int privateVar;
protected:
	int protectedVar;
public:
	Base() : privateVar(10), protectedVar(99) {};
	/*
	Base() {
    privateVar = 10;
    protectedVar = 99;
	}
	*/
	friend void friendFunction(Base& obj);
};

// Friend function implemented outside of class
void friendFunction(Base& obj)
{
	obj.privateVar = obj.privateVar + 1;
	std::cout << "Private variable: " << obj.privateVar << std::endl;
	std::cout << "Protected variable: " << obj.protectedVar << std::endl;
}


int main()
{
    int x = 5;
	char y = 'a';
	
	// Reference, is the address of a variable
	int& ref = x;
	char& ref2 = y;

	std::cout << std::setw(25) << std::setfill('-') << "Reference" << std::endl;
	std::cout << "x: " << x << " and it's reference is : " << &ref << std::endl;
	std::cout << "y: " << y << " and it's reference is : " << &ref2 << std::endl;

	std::cout << std::setw(25) << std::setfill('-') << "Pointer" << std::endl;
	// Pointer, is a variable that stores the address of another variable
	int* ptr = &x;
	int* ptr2 = &ref;
	std::cout << "x: " << x << " and it's pointer is : " << ptr << std::endl;
	std::cout << "x: " << x << " and it's pointer is : " << ptr2 << std::endl;
	std::cout << "I can derefernce the pointer to get the value of x: " << *ptr << std::endl;

	std::cout << std::setw(25) << std::setfill('-') << "Pointer to pointer" << std::endl;
	// Pointer to pointer
	int** ptr3 = &ptr;
	std::cout << "x: " << x << " and it's pointer to pointer is : " << ptr3 << std::endl;

	
	std::cout << std::setw(25) << std::setfill('-') << "Object pointer" << std::endl;
	Item* item = new Item(1, 2.5);
	item->show();
	delete item;


	std::cout << std::setw(25) << std::setfill('-') << "Friend function" << std::endl;
	// Pass by reference if using regular object
	Base object1;
	friendFunction(object1);

	// Deference the pointer if using object pointer
	Base* object2 = new Base();
	friendFunction(*object2);
	delete object2;

	return 0;


}

