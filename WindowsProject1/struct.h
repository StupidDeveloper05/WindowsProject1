#pragma once

struct Vec2
{
	float x;
	float y;

public:
	float Length()
	{
		return sqrt(x * x + y * y);
	}

	Vec2& Nomalize()
	{
		x /= Length();
		y /= Length();
		return *this;
	}

public:
	Vec2& operator=(POINT _pt) // Equal 연산자 포인트 자료형과
	{
		x = (float)_pt.y;
		y = (float)_pt.x;
		return *this;
	}

	Vec2& operator=(const Vec2& _vOther) // Equal 연산자 벡터 끼리
	{
		x = _vOther.x;
		y = _vOther.y;
		return *this;
	}

	Vec2 operator+(const Vec2& _vOther) // + 연산자
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}

	Vec2 operator-(const Vec2& _vOther) // - 연산자
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}

	Vec2 operator*(const Vec2& _vOther) // * 연산자
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}

	Vec2 operator/(const Vec2& _vOther) // 나누기 연산자
	{
		assert(!(_vOther.x == 0.f || _vOther.y == 0.f)); // 0으로 나누면 오류나도록 설정
		return Vec2(x / _vOther.x, y / _vOther.y);
	}

public:
	Vec2() // 기본 생성자
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y) // 실수형으로 초기화하는 생성자
		: x(_x)
		, y(_y)
	{}

	Vec2(int _x, int _y) // 정수형으로 초기화
		: x((float)_x)
		, y((float)_y)
	{}

	Vec2(long _x, long _y) // 정수형으로 초기화
		: x((float)_x)
		, y((float)_y)
	{}

	Vec2(const POINT& _pt) // 포인트로 초기화
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};