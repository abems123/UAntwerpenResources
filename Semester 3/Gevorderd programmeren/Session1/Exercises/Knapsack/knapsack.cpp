#include <iostream>
#include <string>
#include <vector>

typedef std::pair<int, int> Item; // weight, value pairs
typedef std::vector<Item> ItemList;

int knapsack(int i, const ItemList& items, const int capacity){
  if (i < 0)
    return 0;
  
  if (items[i].first > capacity)
    return knapsack(i-1, items,capacity);
  else{
    int include = items[i].second + knapsack(i-1, items, capacity - items[i].first);
    int exclude = knapsack(i-1,items,capacity);

    return std::max(include, exclude);
  }
}

int main()
{
  ItemList items = {
    Item{2, 12},   // weight 2, value 12
    Item{1, 10},   // weight 1, value 10
    Item{3, 20},   // weight 3, value 20
    Item{2, 15},   // weight 2, value 15
    Item{5, 90}    // weight 5, value 30
  };
  
  std::cout << knapsack(4, items, 7) << std::endl;
}
