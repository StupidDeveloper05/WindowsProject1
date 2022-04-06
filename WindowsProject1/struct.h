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
	Vec2& operator=(POINT _pt) // Equal ������ ����Ʈ �ڷ�����
	{
		x = (float)_pt.y;
		y = (float)_pt.x;
		return *this;
	}

	Vec2& operator=(const Vec2& _vOther) // Equal ������ ���� ����
	{
		x = _vOther.x;
		y = _vOther.y;
		return *this;
	}

	Vec2 operator+(const Vec2& _vOther) // + ������
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}

	Vec2 operator-(const Vec2& _vOther) // - ������
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}

	Vec2 operator*(const Vec2& _vOther) // * ������
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}

	Vec2 operator/(const Vec2& _vOther) // ������ ������
	{
		assert(!(_vOther.x == 0.f || _vOther.y == 0.f)); // 0���� ������ ���������� ����
		return Vec2(x / _vOther.x, y / _vOther.y);
	}

public:
	Vec2() // �⺻ ������
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y) // �Ǽ������� �ʱ�ȭ�ϴ� ������
		: x(_x)
		, y(_y)
	{}

	Vec2(int _x, int _y) // ���������� �ʱ�ȭ
		: x((float)_x)
		, y((float)_y)
	{}

	Vec2(long _x, long _y) // ���������� �ʱ�ȭ
		: x((float)_x)
		, y((float)_y)
	{}

	Vec2(const POINT& _pt) // ����Ʈ�� �ʱ�ȭ
		: x((float)_pt.x)
		, y((float)_pt.y)
	{}
};