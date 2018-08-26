#ifndef _INCLUDE_VEC2_H_
#define _INCLUDE_VEC2_H_

// core3dr
#include <common/pixel_traits.h>

// C++ STL
#include <cstdint>
#include <cstring>

template <typename T>
struct vec2 {

  // Type Traits
  typedef T value_type;

  enum { num_components = 2 };

	static vec2 lowest() {
		return vec2(std::numeric_limits<T>::lowest());
	}
	static vec2 max() {
		return vec2(std::numeric_limits<T>::max());
	}


  // Constructor
  vec2(value_type x, value_type y) {
    _alloc();
    m_v[0] = x; m_v[1] = y;
  }

	vec2(value_type v) :
		vec2(v, v) {}

  vec2() {
    _alloc();
    m_v[0] = 0; m_v[1] = 0;
  }

  vec2(const vec2& o) {
    _alloc();
    memcpy(m_v, o.m_v, num_components * sizeof(value_type));
  }

  vec2(vec2&& o) {
    m_v = o.m_v;
    o.m_v = nullptr;
  }

  ~vec2() {
    delete[] m_v;
    m_v = nullptr;
  }

  vec2& operator=(const vec2& p) {
    memcpy(m_v, p.m_v, num_components * sizeof(value_type));
    return *this;
  }

  vec2& operator=(vec2&& o) {

    if (this != &o) {
      m_v = o.m_v;
      o.m_v = nullptr;
    }

    return *this;
  }

  inline T  operator [] (int i) const { return m_v[i]; }
  inline T& operator [] (int i)       { return m_v[i]; }

  inline T x() const { return m_v[0]; }
  inline T y() const { return m_v[1]; }

  inline T& x() { return m_v[0]; }
  inline T& y() { return m_v[1]; }

protected:

  void _alloc() { m_v = new value_type[num_components]; }

  value_type* m_v;

};



// Types
typedef vec2<double>   vec2d;
typedef vec2<float>    vec2f;
typedef vec2<int>      vec2i;
typedef vec2<long>     vec2l;
typedef vec2<uint8_t>  vec2b;

template <typename T> struct pixel_traits<vec2<T>>    : public pixel_traits_vec<T, vec2> {};

#endif
