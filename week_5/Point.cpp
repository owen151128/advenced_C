#include <iostream>	//	iostream 헤더 포함
#include "Point.h"	//	Point.h 헤더 포함
using namespace std;	//	기본 네임스페이스로 std 사용

bool Point::InitMembers(int xpos, int ypos)	//	initMembers 함수 정의
// Point:: 지금 내용을 쓰고 있는 함수는 Point클래스의 InitMembers의 내용이다.
// 함수 InitMembers 는 Point의 맴버함수이다.

{
	if(xpos<0 || ypos<0)	//	xpos or ypos 값이 0보다 작을 경우
	{
		cout<<"벗어난 범위의 값 전달"<<endl;	//	해당 문자열 과 개행문자 출력
		return false;	//	false 반환	
	}
	
	x=xpos;	//	x 에 xpos 값 셋팅
	y=ypos;	//	y 에 ypos 값 셋팅
	return true;	//	true 반환
}

int Point::GetX() const {return x;}	//	x getter 함수 정의
int Point::GetY() const {return y;}	//	y getter 함수 정의

bool Point::SetX(int xpos)	//	x setter 함수 정의
{
	if(0>xpos || xpos>100)	//	xpos 값이 100보다 크거나 0보다 작을 경우
	{
		cout<<"벗어난 범위의 값 전달"<<endl;	//	해당 문자열 과 개행문자 출력
		return false;	//	false 반환	
	}

	x=xpos;	//	x 에 xpos 값 셋팅
	return true;	//	true 반환
}	
bool Point::SetY(int ypos)	//	y getter 함수 정의
{
	if(0>ypos || ypos>100)	//	ypos 값이 100보다 크거나 0보다 작을 경우
	{
		cout<<"벗어난 범위의 값 전달"<<endl;	//	해당 문자열 과 개행문자 출력
		return false;	//	false 반환
	}

	y=ypos;	//	y 에 ypos 값 셋팅
	return true;	//	true 반환
}