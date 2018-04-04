#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

class Segment {
  int start, end;
public:
  Segment(int s, int e) {
    start = s;
    end = e;
  }

  bool isInside(int p) {
    return p > start && p < end;
  }

  int getStart() { return start; }
  int getEnd() { return end; }

};

// криво косо, сложно. safe move - выбрать точку с минимальной end,
// поэтому сравнивать надо не со следующим сегментом, а с последней добавленной точкой
// если она > начала очередного сегмента, то скипаем, иначе добавляем конец сегмента как точку.
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int tmp;
  for(int i = 0; i < segments.size(); ++i) {
    if(i + 1 < segments.size()) {
      if(segments[i].isInside(segments[i+1].getStart())) {
        tmp = std::min(segments[i].getEnd(), segments[i+1].getEnd());
        if(points.size() > 0) {
          if(points.back() < segments[i].getStart()) {
            points.push_back(tmp);
          }
        } else {
          points.push_back(tmp);
        }
      }
    } else {
      if (segments[i].getStart() > points.back()) {
         points.push_back(segments[i].getEnd());
      }
    }
  }
  return points;
}

bool comp(Segment a, Segment b) {
  return a.getStart() < b.getStart();
}

int main() {
  int n, s, e;
  std::cin >> n;
  vector<Segment> segments;
  for (size_t i = 0; i < n; ++i) {
    std::cin >>s >> e;
    segments.push_back(Segment(s, e));
  }

  std::sort(segments.begin(), segments.end(), comp);


  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
