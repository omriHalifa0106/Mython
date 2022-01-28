#include <iostream>
#include <string>

#ifndef TYPE_H
#define TYPE_H

class Type
{
public:
	bool GetIsTemp();
	void SetIsTemp(bool isTemp);
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0 ;
protected:
	bool _IsTemp = false;
};


#endif //TYPE_H
