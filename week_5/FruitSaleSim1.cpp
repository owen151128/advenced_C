#include <iostream>	//	iostream 헤더 포함
using namespace std;	//	기본 네임스페이스로 std 사용

class FruitSeller	//	FruitSeller 클래스 정의
{
private:	//	private 접근제어 지시자 사용
	int APPLE_PRICE;	//	int 형 APPLE_PRICE 선언
	int numOfApples;	//	int 형 numOfApples 선언
	int myMoney;	//	int 형 myMoney 선언
	
public:	//	public 접근제어 지시자 사용
	void InitMembers(int price, int num, int money)	//	맴버변수들을 init 하는 함수 정의
	{
		APPLE_PRICE=price;	//	인자들을 맴버변수에 셋팅
		numOfApples=num;	//	인자들을 맴버변수에 셋팅
		myMoney=money;	//	인자들을 맴버변수에 셋팅
	}
	int SaleApples(int money)	// 사과를 파는 함수  
	{
		int num=money/APPLE_PRICE;	//	사과 가격 으로 money 를 나눔
		numOfApples-=num;	//	위에서 구한 갯수만큼 사과 보유갯수에서 차감
		myMoney+=money;	//	myMoney 변수에 money 만큼 더함
		return num;	//	팔린 사과 갯수 리턴
	}
	void ShowSalesResult()	//	판매 결과를 보여주는 함수 정의
	{
		cout<<"남은 사과: "<<numOfApples<<endl;	//	해당 문자열, 사과갯수, 개행문자 출력
		cout<<"판매 수익: "<<myMoney<<endl<<endl;	//	해당 문자열, 돈, 개행문자 2개 출력
	}
};

class FruitBuyer	//	FruitBuyer 클래스 정의
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:	//	접근제어 지시자 public 사용
	void InitMembers(int money)	//	맴버변수 들을 init 하는 함수 정의
	{
		myMoney=money;	//	가지고 있는 돈을 인자로 초기화
		numOfApples=0;	//	가지고 있는 사과갯수를 0 으로 초기화
	}
	void BuyApples(FruitSeller &seller, int money)	//	사과를 구매하는 함수 정의
	{
		numOfApples+=seller.SaleApples(money);	//	판매자로부터 사과를 사는 함수 호출
		myMoney-=money;	//	사과를 산 금액만큼 돈에서 차감
	}
	void ShowBuyResult()	//	구매 결과를 보여주는 함수 정의
	{
		cout<<"현재 잔액: "<<myMoney<<endl;	//	해당 문자열, 돈, 개행문자 출력
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;	//	해당 문자열, 사과갯수, 개행문자 2개 출력
	}
};

int main(void)	//	main 함수 정의
{
	FruitSeller seller;	//	과일 판매자 클래스 선언 
	seller.InitMembers(1000, 20, 0); 	//	사과 가격은 1000원, 갯수는 20개, 가지고 있는 돈은 0원으로 초기화
	FruitBuyer buyer;	//	과일 구매자 클래스 선언
	buyer.InitMembers(5000);	//	가지고 있는 돈을 5000원으로 초기화
	buyer.BuyApples(seller, 40000);	//	사과를 판매자로부터 40000원 어치 구매
	
	cout<<"과일 판매자의 현황"<<endl;	//	문자열, 개행문자 출력
	seller.ShowSalesResult();	//	판매자 결과 보는 함수 호출
	cout<<"과일 구매자의 현황"<<endl;	//	문자열, 개행문자 출력
	buyer.ShowBuyResult();	//	구매자 결과 보는 함수 호출
	return 0;	//	0 반환
}
