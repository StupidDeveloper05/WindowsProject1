#pragma once

enum class KEY_STATE
{
	TAP,
	HOLD,
	AWAY,
	NONE
};

enum class KEY
{
	Q,
	W,
	E,
	R,
	T,
	Y,
	U,
	I,
	O,
	P,
	A,
	S,
	D,
	F,
	G,
	H,
	J,
	K,
	L,
	Z,
	X,
	C,
	V,
	B,
	N,
	M,

	ENTER,
	SPACE,
	ALT, 
	LEFT,
	RIGHT,
	UP,
	DOWN,
	CTRL,
	SHIFT,

	LAST
};

struct tKeyInfo
{
	bool			bPrevPressed;
	KEY_STATE	eState;
};

class CKeyManager
{
	SINGLE(CKeyManager);
private:
	vector<tKeyInfo> m_vecKey;

public:
	void init();
	void update();
	KEY_STATE GetKeyState(KEY _eKey) { return m_vecKey[(int)_eKey].eState; }
};