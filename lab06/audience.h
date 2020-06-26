#pragma once
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
};