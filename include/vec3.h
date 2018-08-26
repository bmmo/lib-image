#ifndef _INCLUDE_VEC3_H_
#define _INCLUDE_VEC3_H_

// C++ STL
#include <cstdint>
#include <cstring>

template <typename T>
struct vec3 {

  // Type Traits
  typedef T value_type;

  enum { num_components = 3 };

	static vec3 lowest() {
		return vec3(std::numeric_limits<T>::lowest());
	}
	static vec3 max() {
		return vec3(std::numeric_limits<T>::max());
	}

  // Constructor
  vec3(value_type x, value_type y, value_type z) {
    _alloc();
    m_v[0] = x; m_v[1] = y; m_v[2] = z;
  }

	vec3(value_type v) :
		vec3(v, v, v) {}

  vec3() {
    _alloc();
    m_v[0] = 0; m_v[1] = 0; m_v[2] = 0;
  }

  vec3(const vec3& o) {
    _alloc();
    memcpy(m_v, o.m_v, num_components * sizeof(value_type));
  }

  vec3(vec3&& o) {
    m_v = o.m_v;
    o.m_v = nullptr;
  }

  ~vec3() {
    delete[] m_v;
    m_v = nullptr;
  }

  vec3& operator=(const vec3& p) {
    memcpy(m_v, p.m_v, num_components * sizeof(value_type));
    return *this;
  }

  vec3& operator=(vec3&& o) {

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

  inline T& x() { return m_v[0]; }
  inline T& y() { return m_v[1]; }
  inline T& z() { return m_v[2]; }

  inline T r() const { return m_v[0]; }
  inline T g() const { return m_v[1]; }
  inline T b() const { return m_v[2]; }

  inline T& r() { return m_v[0]; }
  inline T& g() { return m_v[1]; }
  inline T& b() { return m_v[2]; }

protected:

  void _alloc() { m_v = new value_type[num_components]; }

  value_type* m_v;

};



// Types
typedef vec3<double>   vec3d;
typedef vec3<float>    vec3f;
typedef vec3<int>      vec3i;
typedef vec3<long>     vec3l;
typedef vec3<uint8_t>  vec3b;

template <typename T> struct pixel_traits<vec3<T>>    : public pixel_traits_vec<T, vec3> {};

#endif
