#pragma once

#define SINGLE(Type) public:\
						static Type* GetInst()\
						{\
							static Type mgr; \
							return &mgr; \
						}\
					private:\
						Type();\
						~Type();

#define KEY_CHECK(key, state) CKeyManager::GetInst()->GetKeyState(key) == state

#define KEY_TAP(Key)	KEY_CHECK(Key, KEY_STATE::TAP)
#define KEY_HOLD(Key) KEY_CHECK(Key, KEY_STATE::HOLD)
#define KEY_AWAY(Key) KEY_CHECK(Key, KEY_STATE::AWAY)
#define KEY_NONE(Key) KEY_CHECK(Key, KEY_STATE::NONE)

#define DT CTimeManager::GetInst()->GetDT();
#define fDT CTimeManager::GetInst()->GetfDT();