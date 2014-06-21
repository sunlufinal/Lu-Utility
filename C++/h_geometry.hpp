#ifndef __H_GEOMETRY_HPP__
#define __H_GEOMETRY_HPP__

namespace h_utility{

template <class T>
class Vector3D{

public:

	T x;
	T y;
	T z;

public:

	void set(T x, T y, T z);

	// Vector3D operator -(const Vector3D& v1, const Vector3D& v2);

};	// end class Vector3D

} // end namespace h_utility

#endif