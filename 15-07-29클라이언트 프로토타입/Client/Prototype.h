#pragma once
#include "Define.h"


class CPrototype
{
public:
	virtual HRESULT InitProtoInstance()PURE;
	virtual void Release()PURE;

public:
	CPrototype(void);
	virtual ~CPrototype(void);
};

