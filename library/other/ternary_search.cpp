/// @see [https://pione.hatenablog.com/entry/2021/02/07/223219]
double ternary_search(double l, double r, const function<double(double)> f,const bool is_downward_convex = true) {
  int loop = 500;
  if (is_downward_convex) {
    while (loop--) {
      auto mid_l = (l * 2 + r) / 3, mid_r = (l + 2 * r) / 3;
      if (f(mid_l) >= f(mid_r))
        l = mid_l;
      else
        r = mid_r;
    }
  } else {
    while (loop--) {
      auto mid_l = (l * 2 + r) / 3, mid_r = (l + 2 * r) / 3;
      if (f(mid_l) <= f(mid_r))
        l = mid_l;
      else
        r = mid_r;
    }
  }
  return l;
}