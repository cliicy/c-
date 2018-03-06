#include "xstring.h"
#include <string>
#include <iostream>
#include "assert.h"

xstring::xstring(const char*str)
{
	if (str == NULL){
		m_data = new char[1];
		*m_data = '\0';
	}
	else {
		int length = strlen(str);
		m_data = new char[length + 1];
		if (m_data){

		}		//strcpy(m_data, str);
		else{
			//cout << "alocate fail" << endl;
		}

	}
	
}


xstring::xstring(const xstring& other)
{
	int length = strlen(other.m_data);
	m_data = new char[length + 1];
	assert(m_data != NULL);
	strcpy(m_data, other.m_data);
}


xstring::~xstring()
{
		delete [] m_data;
}

xstring & xstring::operator = (const xstring &other){
	if (this == &other)
		return *this;
	delete[] m_data;
	int length = strlen(other.m_data);
	m_data = new char(length + 1);
	strcpy(m_data, other.m_data);
	return *this;
}