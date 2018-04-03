#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Item {
  int weight;
  double value;
public:
  Item(int w, double v) {
    weight = w;
    value = v;
  }

  double getValuePerW(){
    return value / weight;
  }

  int getWeight() { return weight; }
  int getTotal() { return weight * value; }
};

class Knapsack {
  int capacity, remain;
  double value;
public:
  Knapsack(int c) {
    capacity = c;
    remain = c;
    value = 0.0;
  }

  void add(double v, int w) {
    value += v * w;
    remain -= w;
  }

  void addTotal(double b, int w) {
    value += b;
    remain -= w;
  }

  int getRemain() { return remain;}
  bool canAdd(int w) { return w < remain; }
  double getValue() { return value; }
};

double step(Knapsack knapsack, vector<Item> items) {
  Item cur = items.back();

  if (!knapsack.canAdd(cur.getWeight())) {
    knapsack.add(cur.getValuePerW(), knapsack.getRemain());
    return knapsack.getValue();
  }
  
  items.pop_back();
  knapsack.addTotal(cur.getTotal(), cur.getWeight());
  return step(knapsack, items);
}

double get_optimal_value(Knapsack knapsack, vector<Item> items) {
  return step(knapsack, items);
}

bool comp(Item i, Item j) { return i.getValuePerW() < j.getValuePerW(); }

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  int w;
  double v;

  vector<Item> items;
  Knapsack k = Knapsack(capacity);
 
  for (int i = 0; i < n; i++) {
    std::cin >> v >> w;
    items.push_back(Item(w, v));
  }

  sort(items.begin(), items.end(), comp);

  double optimal_value = get_optimal_value(k, items);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
