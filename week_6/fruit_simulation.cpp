#include <iostream>
using namespace std;

class FruitSeller
{
private:
	unsigned int APPLE_PRICE;
	unsigned int numOfApples;
	unsigned int myMoney;

public:
	FruitSeller(unsigned int price, unsigned int num, unsigned int money) : APPLE_PRICE(price), numOfApples(num), myMoney(money) {}
	FruitSeller(const FruitSeller &rhs)
	{
		this->APPLE_PRICE = rhs.APPLE_PRICE;
		this->numOfApples = rhs.numOfApples;
		this->myMoney = rhs.myMoney;
	}
	~FruitSeller()
	{
		cout << "과일 판매자의 현황" << endl;
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl;
	}
	int SaleApples(unsigned int money) // 사과를 파는 함수
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

class FruitBuyer
{
	unsigned int myMoney;	  // private:
	unsigned int numOfApples; // private:

public:
	FruitBuyer(unsigned int money) : myMoney(money), numOfApples(0) {}
	~FruitBuyer()
	{
		cout << "과일 구매자의 현황" << endl;
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl;
	}
	void BuyApples(FruitSeller &seller, unsigned int money)
	{
		if (money > myMoney)
		{
			numOfApples += seller.SaleApples(myMoney);
			myMoney = 0;

			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
};

int main(void)
{
	unsigned int price, numOfApples, sellerMoney, buyerMoney; //	1000, 20, 0, 5000
	cout << "과일 판매자의 사과 가격, 갯수, 가지고 있는돈, 구매자가 가지고 있는 돈을 차례로 입력해 주세요 : ";
	cin >> price >> numOfApples >> sellerMoney >> buyerMoney;

	FruitSeller seller[3] = {FruitSeller(price, numOfApples, sellerMoney), FruitSeller(seller[0]), FruitSeller(seller[0])};
	FruitBuyer buyer(buyerMoney);

	int buyerSelect = -1;
	while (buyerSelect <= 0 || buyerSelect > 3)
	{
		cout << "과일장수 3명중 누구에게 과일을 구매하시겠습니까 ex) 1, 2, 3 : ";
		cin >> buyerSelect;
	}

	buyer.BuyApples(seller[buyerSelect - 1], 20000);

	return 0;
}
