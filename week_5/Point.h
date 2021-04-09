#ifndef __POINT_H_	//	Point.h 헤더 시작
#define __POINT_H_	//	Point.h 헤더 정의 시작

class Point	// Point 클래스 정의
{
private:	//	private 접근제어 지시자 사용
	int x;	//	int 형 변수 x 선언
	int y;	//	int 형 변수 y 선언  

public:	//	public 접근제어 지시자 사용
	bool InitMembers(int xpos, int ypos);	//	맴버변수 초기화 함수 선언
	int GetX() const;	//	x getter 함수 선언
	int GetY() const;	//	y getter 함수 선언
	bool SetX(int xpos);	//	x setter 함수 선언
	bool SetY(int ypos);	//	y setter 함수 선언
};

#endif	//	Point.h 헤더 끝