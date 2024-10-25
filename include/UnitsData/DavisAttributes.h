#pragma once
#include "UnitsAttributes.h"

class DavisAttributes : public UnitsAttributes {
	static bool m_bool_init;
public:
	DavisAttributes();

	virtual ~DavisAttributes() = default;
};