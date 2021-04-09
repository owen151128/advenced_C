#include <iostream>	
using namespace std;	

class FruitSeller	
{
private:	
	unsigned int APPLE_PRICE;	
	unsigned int numOfApples;	
	unsigned int myMoney;	
	
public:	
	void InitMembers(unsigned int price, unsigned int num, unsigned int money)	
	{
		APPLE_PRICE=price;	
		numOfApples=num;	
		myMoney=money;	
	}
	int SaleApples(unsigned int money)	// 사과를 파는 함수  
	{
		unsigned int num=money/APPLE_PRICE;	
		if(numOfApples < numOfApples - num) {
			myMoney += numOfApples * APPLE_PRICE;
			numOfApples = 0;

			return numOfApples;
		}
		numOfApples-=num;	
		myMoney+=money;	
		return num;	
	}
	void ShowSalesResult()	
	{
		cout<<"남은 사과: "<<numOfApples<<endl;	
		cout<<"판매 수익: "<<myMoney<<endl<<endl;	
	}
};

class FruitBuyer	
{
	unsigned int myMoney;		// private:
	unsigned int numOfApples;	// private:

public:	
	void InitMembers(unsigned int money)	
	{
		myMoney=money;	
		numOfApples=0;	
	}
	void BuyApples(FruitSeller &seller, unsigned int money)	
	{
		if(money > myMoney) {
			numOfApples += seller.SaleApples(myMoney);
			myMoney = 0;

			return;
		}
		numOfApples+=seller.SaleApples(money);	
		myMoney-=money;	
	}
	void ShowBuyResult()	
	{
		cout<<"현재 잔액: "<<myMoney<<endl;	
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;	
	}
};

int main(void)	
{
	FruitSeller seller;	
	seller.InitMembers(1000, 20, 0); 	
	FruitBuyer buyer;	
	buyer.InitMembers(5000);	
	buyer.BuyApples(seller, 40000);	
	
	cout<<"과일 판매자의 현황"<<endl;	
	seller.ShowSalesResult();	
	cout<<"과일 구매자의 현황"<<endl;	
	buyer.ShowBuyResult();	
	return 0;	
}
