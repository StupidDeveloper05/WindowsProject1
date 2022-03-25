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