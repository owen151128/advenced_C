#ifndef __RECTANGLE_H_	//	Rectangle.h 헤더 시작
#define __RECTANGLE_H_	//	Rectangle.h 헤더 정의

#include "Point.h"	//	Point.h 파일 포함

class Rectangle	// Rectangle 클래스 정의
{
private:	//	private 접근제어 지시자 사용
	Point upLeft;	//	Point 형 변수 upLeft 선언
	Point lowRight;	//	Point 형 변수 lowRight 선언

public:	//	public 접근제어 지시자 사용
	bool InitMembers(const Point &ul, const Point &lr);	//	맴버변수 초기화 함수 선언
	void ShowRecInfo() const;	//	Rectangle 정보를 출력하는 함수 선언
};

#endif	//	Rectangle.h 헤더 끝
