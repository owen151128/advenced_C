#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Person
{
protected:
	string name;
	unsigned int myMoney;
	Person() {}
	Person(string personName, int money) : name(personName), myMoney(money) {}
	virtual void showInfo() = 0;
};

class AppleSeller : public Person
{
protected:
	unsigned int APPLE_PRICE;
	unsigned int numOfApples;

public:
	AppleSeller() {}
	AppleSeller(string name, unsigned int price, unsigned int num, unsigned int money) : APPLE_PRICE(price), numOfApples(num), Person(name, money) {}
	AppleSeller(const AppleSeller &rhs)
	{
		this->APPLE_PRICE = rhs.APPLE_PRICE;
		this->numOfApples = rhs.numOfApples;
		this->myMoney = rhs.myMoney;
	}

	virtual void showInfo()
	{
		cout << "==================== AppleSeller 정보 출력 ====================" << endl;
		cout << "이름 : " << name << endl;
		cout << "남은 사과 : " << numOfApples << endl;
		cout << "소지금 : " << myMoney << endl;
	}

	int saleFruits(unsigned int money) // 사과를 파는 함수
	{
		unsigned int num = money / APPLE_PRICE;
		if (numOfApples < numOfApples - num)
		{
			myMoney += numOfApples * APPLE_PRICE;
			numOfApples = 0;

			return numOfApples;
		}
		numOfApples -= num;
		myMoney += money;
		return num;
	}
};

class UniqueAppleSeller : public AppleSeller
{
public:
	UniqueAppleSeller() {}
	UniqueAppleSeller(string name, unsigned int price, unsigned int num, unsigned int money) : AppleSeller(name, price, num, money) {}

	virtual void showInfo()
	{
		cout << "==================== UniqueAppleSeller 정보 출력 ====================" << endl;
		cout << "이름 : " << name << endl;
		cout << "남은 희귀 사과 : " << numOfApples << endl;
		cout << "소지금 : " << myMoney << endl;
	}
};

class BananaSeller : public Person
{
private:
	unsigned int banana_price;
	unsigned int numOfBanana;

public:
	BananaSeller() {}
	BananaSeller(string name, unsigned int price, unsigned int num, unsigned int money) : banana_price(price), numOfBanana(num), Person(name, money) {}
	BananaSeller(const BananaSeller &rhs)
	{
		this->banana_price = rhs.banana_price;
		this->numOfBanana = rhs.numOfBanana;
		this->myMoney = rhs.myMoney;
	}

	virtual void showInfo()
	{
		cout << "==================== BananaSeller 정보 출력 ====================" << endl;
		cout << "이름 : " << name << endl;
		cout << "남은 바나나 : " << numOfBanana << endl;
		cout << "소지금 : " << myMoney << endl;
	}

	int saleFruits(unsigned int money)
	{
		unsigned int num = money / banana_price;
		if (numOfBanana < numOfBanana - num)
		{
			myMoney += numOfBanana * banana_price;
			numOfBanana = 0;

			return numOfBanana;
		}
		numOfBanana -= num;
		myMoney += money;
		return num;
	}
};

template <typename Base, typename T>
bool instanceof (const T *)
{
	return is_base_of<Base, T>::value;
}

class FruitBuyer : Person
{
private:
	unsigned int myMoney;
	unsigned int numOfApples = 0;
	unsigned int numOfUniqueApples = 0;
	unsigned int numOfBanana = 0;

public:
	FruitBuyer(string name, unsigned int money) : myMoney(money), Person(name, money) {}

	virtual void showInfo()
	{
		cout << "==================== FruitBuyer 정보 출력 ====================" << endl;
		cout << "이름 : " << name << endl;
		cout << "보유한 사과 갯수 : " << numOfApples << endl;
		cout << "보유한 희귀 사과 갯수 : " << numOfUniqueApples << endl;
		cout << "보유한 바나나 갯수 : " << numOfBanana << endl;
		cout << "소지금 : " << myMoney << endl;
	}

	template <class T>
	void buyFruits(T &seller, unsigned int money)
	{
		string type = typeid(seller).name();
		if (money > myMoney)
		{
			if (type.find("UniqueAppleSeller") != string::npos)
			{
				numOfUniqueApples += seller.saleFruits(myMoney);
			}
			else if (type.find("AppleSeller") != string::npos)
			{
				numOfApples += seller.saleFruits(myMoney);
			}
			else if (type.find("BananaSeller") != string::npos)
			{
				numOfBanana += seller.saleFruits(myMoney);
			}

			myMoney = 0;
			return;
		}

		if (type.find("UniqueAppleSeller") != string::npos)
		{
			numOfUniqueApples += seller.saleFruits(money);
		}
		else if (type.find("AppleSeller") != string::npos)
		{
			numOfApples += seller.saleFruits(money);
		}
		else if (type.find("BananaSeller") != string::npos)
		{
			numOfBanana += seller.saleFruits(money);
		}

		myMoney -= money;
	}
};

string joinToString(vector<string> strings, string delimiter)
{
	string result = "";
	int size = strings.size();
	for (int i = 0; i < size; i++)
	{
		result.append(strings[i]);
		if (i != size - 1 && delimiter.length() > 0)
		{
			result.append(delimiter);
		}
	}

	return result;
}

int main(void)
{
	vector<string> sellerNames;
	sellerNames.push_back("사과");
	sellerNames.push_back("희귀 사과");
	sellerNames.push_back("바나나");

	AppleSeller appleSeller;
	UniqueAppleSeller uniqueAppleSeller;
	BananaSeller bananaSeller;
	string name;
	unsigned int currentPrice, curretCountOfFruits, currentSellerMoney, buyerMoney; //	1000, 20, 0, 5000
	for (int i = 0; i < 4; i++)
	{
		if (i == 4 - 1)
		{
			cout << "구매자 이름과 가지고 있는 돈을 입력해 주세요 : ";
			cin >> name >> buyerMoney;
			buyerMoney = 100000;
		}
		else
		{
			cout << sellerNames[i] << "의 판매자 이름, 과일 가격, 갯수, 가지고 있는 돈을 차례로 입력해 주세요 : ";
			cin >> name >> currentPrice >> curretCountOfFruits >> currentSellerMoney;

			switch (i)
			{
			case 0:
				// currentPrice = 1000;
				// curretCountOfFruits = 10;
				// currentSellerMoney = 0;
				// name = "김철수";
				appleSeller = AppleSeller(name, currentPrice, curretCountOfFruits, currentSellerMoney);
				break;
			case 1:
				// currentPrice = 2000;
				// curretCountOfFruits = 20;
				// currentSellerMoney = 0;
				// name = "바둑이";
				uniqueAppleSeller = UniqueAppleSeller(name, currentPrice, curretCountOfFruits, currentSellerMoney);
				break;
			case 2:
				// currentPrice = 3000;
				// curretCountOfFruits = 30;
				// currentSellerMoney = 0;
				// name = "이미나";
				bananaSeller = BananaSeller(name, currentPrice, curretCountOfFruits, currentSellerMoney);
			}
		}
	}

	FruitBuyer buyer(name, buyerMoney);

	unsigned int buyerUseMoney;
	int buyerSelect = -1;
	while (1)
	{
		while (buyerSelect <= -1 || buyerSelect > 3)
		{
			cout << joinToString(sellerNames, ", ") << " 중 어떤걸 구매하시겠습니까 ex) 1, 2, 3 (-1 을 입력하면 종료) : ";
			cin >> buyerSelect;
			if (buyerSelect == -1)
			{
				break;
			}
			cout << "돈을 얼마나 쓰시겠습니까? : " << endl;
			cin >> buyerUseMoney;
		}

		if (buyerSelect == -1)
		{
			break;
		}

		buyerSelect -= 1;
		switch (buyerSelect)
		{
		case 0:
			buyer.buyFruits<AppleSeller>(appleSeller, buyerUseMoney);
			buyerSelect = -255;
			break;
		case 1:
			buyer.buyFruits<UniqueAppleSeller>(uniqueAppleSeller, buyerUseMoney);
			buyerSelect = -255;
			break;
		case 2:
			buyer.buyFruits<BananaSeller>(bananaSeller, buyerUseMoney);
			buyerSelect = -255;
			break;
		}
	}

	appleSeller.showInfo();
	uniqueAppleSeller.showInfo();
	bananaSeller.showInfo();
	buyer.showInfo();

	return 0;
}
