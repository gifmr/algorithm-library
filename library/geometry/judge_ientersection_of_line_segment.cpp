/// 二次元平面における線分交差判定
template <class T>
bool judge_ientersection_of_line_segment(T ax, T ay,
                                         T bx, T by,
                                         T cx, T cy,
                                         T dx, T dy,
                                         bool should_include_endpoint = true) {
  auto ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
  auto tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
  auto tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
  auto td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
  if (should_include_endpoint) return tc * td <= 0 && ta * tb <= 0;
  else return tc * td < 0 && ta * tb < 0;
};