#pragma once
#include <cstdlib>

class xstring
{
public:
	xstring(const char*str=NULL);
	xstring(const xstring &other );
	~xstring();
	xstring & operator = (const xstring &other);

private:
	char *m_data;
};

