#pragma once

namespace utils {
// C++14 compile time square root using binary search
// for integer constants
//
// https://stackoverflow.com/a/27709195

template<typename T>
constexpr T sqrt_helper(T x, T lo, T hi) {
  if (lo == hi) {
    return lo;
  }

  const T mid = (lo + hi + 1) / 2;

  if (x / mid < mid) {
    return sqrt_helper<T>(x, lo, mid - 1);
  } else {
    return sqrt_helper(x, mid, hi);
  }
}

template<typename T>
constexpr T ct_sqrt(T x) {
  return sqrt_helper<T>(x, 0, x / 2 + 1);
}
}