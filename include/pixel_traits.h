#ifndef _INCLUDE_PIXEL_TRAITS_H_
#define _INCLUDE_PIXEL_TRAITS_H_

// C++ STL
#include <limits>

template <typename T>
struct pixel_traits_simpletype {

	constexpr static int nchannels = 1;
	constexpr static int depth     = sizeof(T);

	static T lowest() { return std::numeric_limits<T>::lowest(); }
	static T max()    { return std::numeric_limits<T>::max(); }

};

template <typename T, template <typename> class VT>
struct pixel_traits_vec {

	constexpr static int nchannels = VT<T>::num_components;
	constexpr static int depth     = sizeof(T);

	static VT<T> lowest() { return VT<T>::lowest(); }
	static VT<T> max()    { return VT<T>::max(); }

};

template <typename T> struct pixel_traits {};

template <> struct pixel_traits<double>    : public pixel_traits_simpletype<double> {};
template <> struct pixel_traits<float>     : public pixel_traits_simpletype<float> {};
template <> struct pixel_traits<uint8_t>   : public pixel_traits_simpletype<uint8_t> {};
template <> struct pixel_traits<uint16_t>  : public pixel_traits_simpletype<uint16_t> {};
template <> struct pixel_traits<uint32_t>  : public pixel_traits_simpletype<uint32_t> {};
template <> struct pixel_traits<uint64_t>  : public pixel_traits_simpletype<uint64_t> {};
template <> struct pixel_traits<int16_t>   : public pixel_traits_simpletype<int16_t> {};
template <> struct pixel_traits<int32_t>   : public pixel_traits_simpletype<int32_t> {};
template <> struct pixel_traits<int64_t>   : public pixel_traits_simpletype<int64_t> {};

#endif
