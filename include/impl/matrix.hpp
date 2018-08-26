#ifndef _INCLUDE_IMPL_MATRIX_HPP_
#define _INCLUDE_IMPL_MATRIX_HPP_

// core3dr
#include <pixel_traits.h>

template <typename T>
matrix matrix::create(int width, int height, const T* data /* = nullptr */)  {

	return matrix(
			width, 
			height, 
			pixel_traits<T>::depth, 
			pixel_traits<T>::nchannels, 
			reinterpret_cast<const uint8_t*>(data));

}

template <typename T>
matrix matrix::zeros(int width, int height)  {

	auto m = create<T>(width, height);

	memset(m.data(), 0, m.memory_bytes());

	return m;

}

template <typename T>
T* matrix::ptr() {
	return reinterpret_cast<T*>(data());
}

template <typename T>
const T* matrix::ptr() const {
	return reinterpret_cast<const T*>(data());
}

template <typename T>
T* matrix::ptr(int x, int y) {
	return reinterpret_cast<T*>(data()) + (x + y * width());
}

template <typename T>
const T* matrix::ptr(int x, int y) const {
	return reinterpret_cast<T*>(data()) + (x + y * width());
}

#endif
