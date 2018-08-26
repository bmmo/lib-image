// core3dr
#include <matrix.h>

matrix::matrix() :
	matrix(0, 0, 1, 1) {}

matrix::matrix(int width, int height, int depth, int channels, const uint8_t* _data /* = nullptr */) :
  m_width(width),
  m_height(height),
  m_depth(depth),
  m_nchannels(channels) {

  auto ib = memory_bytes();

  m_pixels.resize(ib);

  if (nullptr != _data) {
    memcpy(data(), _data, ib);
  }

}

int matrix::width() const {

  return m_width;

}

int matrix::height() const {

  return m_height;

}

int matrix::depth() const {

  return m_depth;

}

int matrix::nchannels() const {

  return m_nchannels;

}


int matrix::npixels() const {

  return width() * height();

}

int matrix::bpp() const {

  return nchannels() * depth();

}

int matrix::memory_bytes() const {

  return npixels() * bpp();

}

uint8_t* matrix::data() {

  return m_pixels.data();

}

const uint8_t* matrix::data() const {

  return m_pixels.data();

}

uint8_t* matrix::data(int x, int y) {

  return data() + pixel_delta(x, y);

}

const uint8_t* matrix::data(int x, int y) const {

  return data() + pixel_delta(x, y);

}

int matrix::pixel_delta(int x, int y) const {

  return (x + y * width()) * bpp();

}


