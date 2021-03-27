#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define not_equals(a, b) !(fabs((a) - (b)) < EPS)

class Point;
int ccw(Point &p0, Point &p1, Point &p2);

class Point {
public:
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  void console_out() { cout << std::setprecision(15) << x << ' ' << y << endl; }

  void print() { printf("%.15lf %.15lf\n", x, y); }

  Point operator+(const Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(const double k) const { return Point(x * k, y * k); }
  Point operator/(const double k) const { return Point(x / k, y / k); }

  /** 原点からの距離 */
  double abs() { return sqrt(norm()); }
  /** ノルム(大きさの二乗) */
  double norm() { return x * x + y * y; }

  /** x座標 => y座標 の優先度で大小比較を行う */
  bool operator<(const Point &p) const { return not_equals(x, p.x) ? x < p.x : y < p.y; }
  bool operator>(const Point &p) const { return not_equals(x, p.x) ? x > p.x : y > p.y; }
  bool operator==(const Point &p) const { return equals(x, p.x) and equals(y, p.y); }
  
  /** 内積(dot product) .. a*b = |a||b|cosΘ = a_x*b_x+a_y*b_y */
  double dot(const Point &p) const { return x * p.x + y * p.y; }
  /** 外積(cross product) .. |a*b| = |a||b|sinΘ = a_x*b_y+a_y*b_x */
  double cross(const Point &p) const { return x * p.y - y * p.x; }

  bool is_parallel(const Point &p) const { return equals(cross(p), 0.0); }
  bool is_orthogonal(const Point &p) const { return equals(dot(p), 0.0); }
};
typedef Point Vector;

double dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
double cross(const Point &p, const Point &q) { return p.x * q.y - p.y * q.x; }
bool is_parallel(const Point &p, const Point &q) { return equals(cross(p, q), 0.0); }
bool is_orthogonal(const Point &p, const Point &q) { return equals(dot(p, q), 0.0); }

class Segment {
public:
  Point p1, p2;
  Segment(Point &p1, Point &p2): p1(p1), p2(p2) {}

  Segment(double x1, double y1, double x2, double y2) {
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
  }

  double dot(const Segment &s) const {
    auto p = p2 - p1;
    auto q = s.p2 - s.p1;
    return p.dot(q);
  }

  double cross(const Segment &s) const {
    auto p = p2 - p1;
    auto q = s.p2 - s.p1;
    return p.cross(q);
  }

  bool is_parallel(const Segment &s) const { return equals(cross(s), 0.0); }
  bool is_orthogonal(const Segment &s) const { return equals(dot(s), 0.0); }

  /// 線分に対する点pの射影
  Point project(const Point &p) {
    Vector base = p2 - p1;
    double r = (p - p1).dot(base) / base.norm();
    return p1 + base * r;
  }
  
  /// 線分を対称軸とした点pの線対称の点
  Point reflect(const Point &p) { return p + (project(p) - p) * 2.0; }
  
  // 線分交差判定
  bool intersect(Segment &s){
    return ccw(p1, p2, s.p1) * ccw(p1, p2, s.p2) <= 0.0 &&
           ccw(s.p1, s.p2, p1) * ccw(s.p1, s.p2, p2) <= 0.0;
  }
  
  /// 直線と点pの距離
  double get_distance_line(const Point &p){
    return abs((p2-p1).cross(p-p1) / (p2-p1).abs());
  }
  
  /// 線分と点pの距離
  double get_distance_segment(const Point &p) {
    if ((p2 - p1).dot(p - p1) < 0.0) return (p - p1).abs();
    if ((p1 - p2).dot(p - p2) < 0.0) return (p - p2).abs();
    return get_distance_line(p);
  }

  /// 線分と線分の距離
  double get_distance(Segment &s) {
    if (intersect(s)) return 0.0;
    return min(min(get_distance_segment(s.p1), get_distance_segment(s.p2)),
               min(s.get_distance_segment(p1), s.get_distance_segment(p2)));
  }
  
  /// 直線同士の交点（線分の場合は交差判定を行う必要がある）
  Point get_cross_point(Segment &s){
    Vector base = s.p2 - s.p1;
    double d1 = abs(base.cross(p1 - s.p1));
    double d2 = abs(base.cross(p2 - s.p1));
    double t = d1 / (d1 + d2);
    return p1 + (p2 - p1) * t;
  }
};
typedef Segment Line;

// 線分(p0, p1)と点p2の位置関係(p0->p1をベクトルa、p0->p2をベクトルbとする)
static const int COUNTER_CLOCKWISE = 1; // bはaに対して反時計回りの位置
static const int CLOCKWISE = -1;     // bはaに対して時計回りの位置
static const int ONLINE_BACK = 2;   // p2 -> p0 -> p1
static const int ONLINE_FRONT = -2; // p0 -> p1 -> p2
static const int ON_SEGMENT = 0;    // p0 -> p2 -> p1

/// 線分(p0, p1)と点p2の位置関係 (counter-clockwise)
int ccw(Point &p0, Point &p1, Point &p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (a.cross(b) > EPS) return COUNTER_CLOCKWISE;
  if (a.cross(b) < -EPS) return CLOCKWISE;
  if (a.dot(b) < -EPS) return ONLINE_BACK;
  if (a.norm() < b.norm()) return ONLINE_FRONT;
  return ON_SEGMENT;
}

typedef vector<Point> Polygon;

const int IN_POLYGON = 1;
const int OUT_OF_POLYGON = 0;
const int ON_POLYGON = -1;

/// 多角形gにおける点pの位置
int contains(Polygon &g, Point &p) {
  int n = g.size();
  bool in_polygon = 0;
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    if (abs(a.cross(b)) < EPS && a.dot(b) < EPS) return ON_POLYGON;
    if (a.y > b.y) swap(a, b);
    if (a.y < EPS && EPS < b.y && a.cross(b) > EPS) in_polygon = !in_polygon;
  }
  return in_polygon;
}

/// 凸法（ソートを必要とするため値渡し）
Polygon andrew_scan(Polygon s) {
  Polygon u, l;
  if (s.size() < 3) return s;
  sort(s.begin(), s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);
  for (int i = 2; i < s.size(); i++) {
    for (int n = u.size(); n >= 2; n--) {
      auto pos = ccw(u[n - 2], u[n - 1], s[i]);
      if(pos != COUNTER_CLOCKWISE) break;
      u.pop_back();
    }
    u.push_back(s[i]);
  }
  for (int i = s.size() - 3; i >= 0; i--) {
    for (int n = l.size(); n >= 2; n--) {
      auto pos = ccw(l[n - 2], l[n - 1], s[i]);
      if(pos != COUNTER_CLOCKWISE) break;
      l.pop_back();
    }
    l.push_back(s[i]);
  }
  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);
  return l;
}

/// 偏角
double arg(Vector &v) { return atan2(v.y, v.x); }
/// 極座標（始点と角の大きさで表される座標）
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

struct Circle {
  Point c;  // 中心
  double r; // 半径
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}

  // 円との交差判定
  bool intersect(Circle &cr){
    auto d = (c - cr.c).abs();
    return d - abs(r - cr.r) >= EPS && (r + cr.r) - d >= EPS;
  }

  // 直線との交差判定
  bool intersect_line(Line &l) {
    auto dist = (l.project(c) - c).abs();
    return dist - r <= EPS;
  }

  /// 線分との交差判定
  bool intersect_segment(Segment &s) {
    auto pr = s.project(c);
    return intersect_line(s) && ccw(s.p1, s.p2, pr) == ON_SEGMENT;
  }

  /// 直線との交点を返す
  pair<Point, Point> get_cross_point(Line &l) {
    // assert(intersect_line(l));
    Vector pr = l.project(c);
    Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs(); // 直線l上の単位ベクトル
    double base = sqrt(r * r - (pr - c).norm());
    return make_pair(pr + e * base, pr - e * base);
  }

  /// 円との交点
  pair<Point, Point> get_cross_point(Circle &cr) {
    // assert(intersect(cr));
    Vector base = cr.c - c;
    double d = base.abs();
    double a = acos((r * r + d * d - cr.r * cr.r) / (2 * r * d));
    double t = arg(base);
    return make_pair(c + polar(r, t + a), c + polar(r, t - a));
  }
};

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

/// 平面走査
class EndPoint {
public:
  Point p;
  int id, type;
  EndPoint() {}
  EndPoint(Point p, int id, int type) : p(p), id(id), type(type) {}

  bool operator<(const EndPoint &ep) const {
    return (p.y == ep.p.y ? type < ep.type : p.y < ep.p.y);
  }
};

/// 線分交差問題（マンハッタン幾何）
int manhattan_intersection(vector<Segment> S) {
  int n = S.size();
  vector<EndPoint> EP(2 * n);
  
  for (int i = 0, k = 0; i < n; i++) {
    if (S[i].p1.y == S[i].p2.y) {
      if (S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
    } else if (S[i].p1.y > S[i].p2.y) swap(S[i].p1, S[i].p2);

    if (S[i].p1.y == S[i].p2.y) {
      EP[k++] = EndPoint(S[i].p1, i, LEFT);
      EP[k++] = EndPoint(S[i].p2, i, RIGHT);
    } else {
      EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
      EP[k++] = EndPoint(S[i].p2, i, TOP);
    }
  }

  sort(EP.begin(), EP.end());

  set<int> BT;
  BT.insert(1e9 + 1);
  int cnt = 0;

  for (int i = 0; i < 2 * n; i++) {
    if (EP[i].type == TOP) {
      BT.erase(EP[i].p.x);
    } else if (EP[i].type == BOTTOM) {
      BT.insert(EP[i].p.x);
    } else if (EP[i].type == LEFT) {
      auto b = BT.lower_bound(S[EP[i].id].p1.x);
      auto e = BT.upper_bound(S[EP[i].id].p2.x);
      cnt += distance(b, e);
    }
  }
  
  return cnt;
}
