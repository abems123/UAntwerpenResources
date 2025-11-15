#include <iostream>
#include <string>
#include <list>


typedef std::pair<int, int> Item; // weight, value pairs
typedef std::list<Item> ItemList;

std::string inttobin(int i){
  if (i == 0)
    return "";
  return inttobin(i/2) + std::to_string(i % 2);
}

int knapsack(int capacity, const ItemList& items){
  
  int largest_total_value = 0;
  Item item_with_ltv;

  for (int i = 0; i < capacity; i++)
  {
    string current_combination_bin = inttobin(i);
    while (current_combination_bin.size() < capacity) {
      current_combination_bin = "0" + current_combination_bin;
    }

    int total_weight = 0;
    int total_value = 0;
    for (int j = 0; j < capacity; j++){
      if ()
    }

  }
  return 0;
}

int main()
{
  std::cout << inttobin(39);
}
