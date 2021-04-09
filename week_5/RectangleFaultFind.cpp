#include<iostream>	//	iostream 헤더 포함
#include "Point.h"	// Point.h 헤더 포함
#include "Rectangle.h"	//	Rectangle.h 헤더 포함
using namespace std;

int main(void)	//	main 함수 정의
{
	Point pos1;	//	Point 형 변수 pos1 선언
	if(!pos1.InitMembers(-2, 4))	//	pos1 -2, 4 로 초기화
		cout<<"초기화 실패"<<endl;	//	false 리턴될 경우 문자열, 개행문자 출력
	if(!pos1.InitMembers(2, 4))	//	pos1 2, 4 로 초기화
		cout<<"초기화 실패"<<endl;	//	false 리턴될 경우 문자열, 개행문자 출력

	Point pos2;	//	Point 형 변수 pos2 선언
	if(!pos2.InitMembers(5, 9))	//	pos1 5, 9 로 초기화
		cout<<"초기화 실패"<<endl;	//	false 리턴될 경우 문자열, 개행문자 출력

	Rectangle rec;	//	Rectangle 형 변수 rec 선언
	if(rec.InitMembers(pos2, pos1))	//	pos2, pos1 으로 초기화
		cout<<"직사각형 초기화 실패"<<endl;	//	false 리턴될 경우 문자열, 개행문자 출력

	if(rec.InitMembers(pos1, pos2))	//	pos1, pos2 으로 초기화
		cout<<"직사각형 초기화 실패"<<endl;	//	false 리턴될 경우 문자열, 개행문자 출력
	
	rec.ShowRecInfo();	//	Rectangle 정보 출력
	return 0;	//	0 반환
}
