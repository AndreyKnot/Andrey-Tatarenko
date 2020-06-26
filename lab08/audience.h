#pragma once
#include <string>

using std::string;
using std::ostream;
using std::istream;

typedef short sint;

class Aud
{
private:
	sint aud_numb;

public:
	sint get_aud_numb() const;
	void set_aud_numb(sint);

	Aud();
	Aud(sint);
	Aud(const Aud& other);
	~Aud();
/////////////////////////////////////////////////////
	friend istream& operator>> (istream&, Aud&);
	friend ostream& operator<< (ostream&, const Aud&);
	bool operator==(const sint) const;
};