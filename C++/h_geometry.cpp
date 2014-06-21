#include "h_geometry.hpp"

namespace h_utility{

template <class T>
void Vector3D<T>::set(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

}	// end namespace h_utility