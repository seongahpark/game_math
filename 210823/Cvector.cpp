#include "CVector.h"
#include <iostream>
#include <math.h> //root 사용 위함

using namespace std;

CVector::CVector() :
	m_fx(0.0f), m_fy(0.0f), m_fz(0.0f) {
	cout << "CVECTOR Constructor" << endl;
}

CVector::CVector(float _x, float _y, float _z) :
	m_fx(_x), m_fy(_y), m_fz(_z) {
	cout << "CVECTOR OVERLOADING CONSTRUCTOR" << endl;
}

CVector::CVector(const CVector& _vec) :
	m_fx(_vec.m_fx), m_fy(_vec.m_fy), m_fz(_vec.m_fz) {
	cout << "CVector Copy Constructor" << endl;
}

CVector::~CVector() {
	cout << "Cvector Destructor" << endl;
}

float CVector::Dot(const CVector& _vec) {
	return (m_fx * _vec.m_fx)
		+ (m_fy * _vec.m_fy)
		+ (m_fz * _vec.m_fz);
}

CVector CVector::Cross(const CVector& _vec) {
	return CVector(
		(m_fy * _vec.m_fz) - (m_fz * _vec.m_fy),
		(m_fz  *_vec.m_fx) - (m_fx * _vec.m_fz),
		(m_fx * _vec.m_fy) - (m_fy * _vec.m_fx)
	);
}

float CVector::Length() {
	return sqrtf((m_fx * m_fx) + (m_fy * m_fy) + (m_fz * m_fz));
	//결과를 float으로 반환 -> sqrtf
}

float CVector::Distance(const CVector& _vec) {
	return (*this - _vec).Length();
}

float CVector::Distance(const CVector& _vec1, const CVector& _vec2) {
	return (_vec1 - _vec2).Length();
}

void CVector::Normalize() {
	float len = Length();
	*this /= len;
	//m_fx /= len;
}

CVector CVector::operator+(const CVector& _vec) {
	//임시객체
	return CVector(
		m_fx + _vec.m_fx,
		m_fy + _vec.m_fy,
		m_fz + _vec.m_fz
	);
}

CVector CVector::operator-(const CVector& _vec) {
	//임시객체
	return CVector(
		m_fx - _vec.m_fx,
		m_fy - _vec.m_fy,
		m_fz - _vec.m_fz
	);
}

CVector operator-(const CVector& _vec1, const CVector& _vec2) {
	return CVector(
		_vec1.m_fx - _vec2.m_fx,
		_vec1.m_fy - _vec2.m_fy,
		_vec1.m_fz - _vec2.m_fz
	);
}

CVector CVector::operator*(float _scalar) {
	return CVector(
		m_fx * _scalar,
		m_fy * _scalar,
		m_fz * _scalar
	);
}

CVector CVector::operator/(float _scalar) {
	if (_scalar == 0.0f) _scalar = 1.0f; //예외처리
	return CVector(
		m_fx / _scalar,
		m_fy / _scalar,
		m_fz / _scalar
	);
}

CVector& CVector::operator+=(const CVector& _vec) {
	m_fx += _vec.m_fx;
	m_fy += _vec.m_fy;
	m_fz += _vec.m_fx;
	return *this;
}

CVector& CVector::operator-=(const CVector& _vec) {
	m_fx -= _vec.m_fx;
	m_fy -= _vec.m_fy;
	m_fz -= _vec.m_fx;
	return *this;
}

CVector& CVector::operator*=(float _scalar) {
	m_fx *= _scalar;
	m_fy *= _scalar;
	m_fz *= _scalar;
	return *this;
}

CVector& CVector::operator/=(float _scalar) {
	if (_scalar == 0.0f) _scalar = 1.0f;
	m_fx /= _scalar;
	m_fy /= _scalar;
	m_fz /= _scalar;
	return *this;
}

bool CVector::operator==(const CVector& _vec) {
	return (m_fx == _vec.m_fx) &&
		(m_fy == _vec.m_fy) &&
		(m_fz == _vec.m_fz);
}

bool CVector::operator!=(const CVector& _vec) {
	return (m_fx != _vec.m_fx) ||
		(m_fy != _vec.m_fy) ||
		(m_fz != _vec.m_fz);
}

CVector& CVector::operator=(const CVector& _vec) {
	m_fx = _vec.m_fx;
	m_fy = _vec.m_fy;
	m_fz = _vec.m_fz;

	return *this;
}

//전역 연산자
std::ostream& operator<<(std::ostream& _os, const CVector& _vec) {
	//(x,y,z)
	_os << "(" << _vec.m_fx << ", "
		<< _vec.m_fy << ", "
		<< _vec.m_fz << ")";
	
	return _os;
}