// IocContainer.h: interface for the IocContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IOCCONTAINER_H__71D269C3_B514_446A_8F22_1CDDF6AB3110__INCLUDED_)
#define AFX_IOCCONTAINER_H__71D269C3_B514_446A_8F22_1CDDF6AB3110__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/************************************************************************/
/* Chat or Posts?                                                                     */
/************************************************************************/
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>
#include <string>

class IocContainer  
{
private:
	std::map<std::string, void*> members; /* UUID as the key. */

protected:

public:
	IocContainer();
	virtual ~IocContainer();

};

#endif // !defined(AFX_IOCCONTAINER_H__71D269C3_B514_446A_8F22_1CDDF6AB3110__INCLUDED_)
