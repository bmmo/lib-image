#ifndef _INCLUDE_VEC4_H_
#define _INCLUDE_VEC4_H_

// C++ STL
#include <cstdint>
#include <cstring>

template <typename T>
struct vec4 {

  // Type Traits
  typedef T value_type;

  enum { num_components = 4 };

	static vec4 lowest() {
		return vec4(std::numeric_limits<T>::lowest());
	}
	static vec4 max() {
		return vec4(std::numeric_limits<T>::max());
	}

  // Constructor
  vec4(value_type x, value_type y, value_type z, value_type w) {
    _alloc();
    m_v[0] = x; m_v[1] = y; m_v[2] = z; m_v[3] = w;
  }

	vec4(value_type v) :
		vec4(v, v, v, v) {}

  vec4() {
    _alloc();
    m_v[0] = 0; m_v[1] = 0; m_v[2] = 0; m_v[3] = 0;
  }

  vec4(const vec4& o) {
    _alloc();
    memcpy(m_v, o.m_v, num_components * sizeof(value_type));
  }

  vec4(vec4&& o) {
    m_v = o.m_v;
    o.m_v = nullptr;
  }

  ~vec4() {
    delete[] m_v;
    m_v = nullptr;
  }

  vec4& operator=(const vec4& p) {
    memcpy(m_v, p.m_v, num_components * sizeof(value_type));
    return *this;
  }

  vec4& operator=(vec4&& o) {

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
  inline T z() const { return m_v[2]; }
  inline T w() const { return m_v[3]; }

  inline T& x() { return m_v[0]; }
  inline T& y() { return m_v[1]; }
  inline T& z() { return m_v[2]; }
  inline T& w() { return m_v[3]; }

  inline T r() const { return m_v[0]; }
  inline T g() const { return m_v[1]; }
  inline T b() const { return m_v[2]; }
  inline T a() const { return m_v[3]; }

  inline T& r() { return m_v[0]; }
  inline T& g() { return m_v[1]; }
  inline T& b() { return m_v[2]; }
  inline T& a() { return m_v[3]; }

protected:

  void _alloc() { m_v = new value_type[num_components]; }

  value_type* m_v;

};



// Types
typedef vec4<double>   vec4d;
typedef vec4<float>    vec4f;
typedef vec4<int>      vec4i;
typedef vec4<long>     vec4l;
typedef vec4<uint8_t>  vec4b;

template <typename T> struct pixel_traits<vec4<T>>    : public pixel_traits_vec<T, vec4> {};

#endif

