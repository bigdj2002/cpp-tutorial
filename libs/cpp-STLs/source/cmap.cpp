#include "cmap.h"

void map_example()
{
  /* ---------------------------------------------------------------------------------------------------------- */

  /**
   * \brief: [1] std::map
   * \details:
   *    - std::map is a sorted associative container that contains key-value pairs with unique keys
   *    - Keys are sorted by using the comparison function Compare.
   *    - Search, removal, and insertion operations have logarithmic complexity. 
   *    - Maps are usually implemented as red-black trees.
   *    - Everywhere the standard library uses the Compare requirements, uniqueness is determined by using the equivalence relation. 
   *    - In imprecise terms, two objects a and b are considered equivalent (not unique) if neither compares less than the other: !comp(a, b) && !comp(b, a).
   */

  std::map<int, int> numPairs;
  numPairs.emplace(1, 101);
  numPairs.emplace(2, 102);
  numPairs.emplace(3, 103);
  numPairs.emplace(4, 104);
  numPairs.emplace(5, 105);
  numPairs.emplace(1, 200);
  numPairs.emplace(1, 300);
  numPairs[1] = 200; // Overwrite!
  for (const auto &numPair : numPairs)
  {
    std::cout << numPair.first << " " << numPair.second << std::endl;
  }
  std::cout << "------------------------------------- [↑ Example 1-1 ↑] -------------------------------------" << std::endl;

  std::map<int, std::string> nameList;
  nameList.emplace(1, "Dongjae");
  nameList.emplace(2, "kitty");
  nameList.emplace(3, "nabi");
  nameList.emplace(2, "bingo");
  nameList.emplace(1, "meow");
  for (const auto &nameList : nameList)
  {
    std::cout << nameList.first << " " << nameList.second << std::endl;
  }

  std::cout << "------------------------------------- [↑ Example 1-2 ↑] -------------------------------------" << std::endl;

  /* ---------------------------------------------------------------------------------------------------------- */

  /**
   * \brief: [4] hash map / std::unordered_map
   * \details:
   */

  std::unordered_map<int, std::string> idNames1;
  std::unordered_multimap<int, std::string> idNames2;

  idNames1.emplace(1, "Dongjae");
  idNames1.emplace(2, "kitty");
  idNames1.emplace(3, "nabi");
  idNames1.emplace(1, "bingo");
  idNames1[1] = "bingo";
  std::cout << idNames1[100];

  idNames2.emplace(1, "Dongjae");
  idNames2.emplace(2, "kitty");
  idNames2.emplace(3, "nabi");
  idNames2.emplace(1, "bingo");

  for (const auto &idName : idNames1)
  {
    std::cout << idName.first << " " << idName.second << std::endl;
  }
  for (const auto &idName : idNames2)
  {
    std::cout << idName.first << " " << idName.second << std::endl;
  }

  std::cout << "------------------------------------- [↑ Example 2 ↑] -------------------------------------" << std::endl;

  /* ---------------------------------------------------------------------------------------------------------- */
}