#ifndef _CVECTOR_H_
#define _CVECTOR_H_
#include <iostream>

class CVector
{
private:
	float m_fx;
	float m_fy;
	float m_fz;

public:
	CVector();
	CVector(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
	CVector(const CVector& _vec);
	~CVector();

	float Dot(const CVector& _vec);
	CVector Cross(const CVector& _vec);
	float Length(); //벡터의 길이를 구함
	float Distance(const CVector& _vec);
	static float Distance(const CVector& _vec1, const CVector& _vec2);
	//static(정적)을 붙이면 객체를 안만들고도 함수를 호출할 수 있다.
	//정규화(Normalize)
	//-> 단위벡터(Unit Vector), 방향벡터(Direction Vector)
	//-> 법선벡터(Normal vector)
	void Normalize();

public:
	CVector operator+(const CVector& _vec);
	CVector operator-(const CVector& _vec);
	friend CVector operator-(const CVector& _lhs, const CVector& _rhs);
	CVector operator*(float _scalar);
	CVector operator/(float _scalar);

	// * : 내적(Dot Product)
	// ^ : 외적(Cross Product)

	CVector& operator+=(const CVector& _vec);
	CVector& operator-=(const CVector& _vec);
	CVector& operator*=(float _scalar);
	CVector& operator/=(float _scalar);

	bool operator==(const CVector& _vec);
	bool operator!=(const CVector& _vec);

	CVector& operator=(const CVector& _vec);

	friend std::ostream& operator<<(
		std::ostream& _os, const CVector& _vec);
};

#endif