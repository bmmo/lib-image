#ifndef _INCLUDE_MATRIX_H_
#define _INCLUDE_MATRIX_H_

// C++ STL
#include <cstdint>
#include <vector>

class matrix {

public:

	matrix();
  matrix(int width, int height, int depth, int channels, const uint8_t* data = nullptr);

	// Factories
	template <typename T>
	static matrix create(int width, int height, const T* data = nullptr);	
	template <typename T>
	static matrix zeros(int width, int height);	

  int width()        const;
  int height()       const;
  int depth()        const;
  int nchannels()    const;

  int npixels()      const;
  int bpp()          const;

  int memory_bytes() const;


  // Pixel access
  uint8_t*        data();
  const uint8_t*  data() const;
  uint8_t*        data(int x, int y);
  const uint8_t*  data(int x, int y) const;

	template <typename T> T*       ptr();
	template <typename T> const T* ptr() const;
	template <typename T> T*       ptr(int x, int y);
	template <typename T> const T* ptr(int x, int y) const;

  // Helpers
  int pixel_delta(int x, int y) const;

protected:

  std::vector<uint8_t> m_pixels;

  int m_width;
  int m_height;
  int m_depth;
  int m_nchannels;

};


// Implementation
#include <impl/matrix.hpp>

#endif
