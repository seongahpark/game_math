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
	float Length(); //������ ���̸� ����
	float Distance(const CVector& _vec);
	static float Distance(const CVector& _vec1, const CVector& _vec2);
	//static(����)�� ���̸� ��ü�� �ȸ���� �Լ��� ȣ���� �� �ִ�.
	//����ȭ(Normalize)
	//-> ��������(Unit Vector), ���⺤��(Direction Vector)
	//-> ��������(Normal vector)
	void Normalize();

public:
	CVector operator+(const CVector& _vec);
	CVector operator-(const CVector& _vec);
	friend CVector operator-(const CVector& _lhs, const CVector& _rhs);
	CVector operator*(float _scalar);
	CVector operator/(float _scalar);

	// * : ����(Dot Product)
	// ^ : ����(Cross Product)

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