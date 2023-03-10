#include "cvector.h"

int vector_example()
{
  int *numsPtr = new int[5];
  for (int i = 0; i < 5; i++)
    numsPtr[i] = i;
  delete numsPtr;




  /**
   * \brief: std::vector - basic level
   */

  /** \example: #1 */
  std::vector<int> nums1(10);
  for (int i = 0; i < 10; i++)
    nums1[i] = i;
  std::cout << nums1.size() << std::endl;
  std::cout << std::endl;

  /** \example: #2 */
  std::vector<int> nums2{0, 1, 2, 3, 4};
  nums2.emplace_back(5);
  std::cout << nums2.size() << std::endl;
  nums2.pop_back();
  std::cout << nums2.size() << std::endl;
  std::cout << std::endl;

  /** \example: #3 */
  for (std::size_t i = 0; i < nums2.size(); i++)
  {
    std::cout << nums2[i] << " ";
  }
  std::cout << std::endl;

  for (auto itr = nums2.begin(); itr != nums2.end(); itr++)
  {
    std::cout << *itr << " ";
  }
  std::cout << std::endl;

  for (const auto &itr : nums2)
  {
    std::cout << itr << " ";
  }
  std::cout << std::endl << std::endl;

  /** \example: #4 */
  std::vector<Cat1> cats1;
  cats1.emplace_back(Cat1(1));
  cats1.emplace_back(Cat1(2));
  cats1.emplace_back(Cat1(3));
  cats1.emplace_back(Cat1(4));
  cats1.emplace_back(Cat1(5));

  for (const auto &cat : cats1)
  {
    // std::cout << cat << " "; // Wrong!
    cat.speak1();
  }
  std::cout << std::endl << std::endl;




  /**
   * \brief: std::vector - intermediate level
   */

  /** \example: #1 */
  std::vector<int> nums3(10000, 1);
  nums3.emplace_back(2);           // O(1)
  nums3.pop_back();                // O(1)
  nums3.emplace(nums3.begin(), 3); // O(N), N=10000 (Need to move next for all elements) -> only at first or last position
  nums3.erase(nums3.begin());      // O(N), N=10000 (Need to move next for all elements) -> only at first or last position

  /** \example: #2 */
  std::vector<Cat1> cats2;
  cats2.emplace_back(Cat1{"cat0", 0});
  cats2.emplace_back(Cat1{"cat1", 0});
  cats2.emplace_back(Cat1{"kitty", 2});
  cats2.emplace_back("kitty", 3); // Will not be generated temp memory to move
  for (const auto &cat : cats2)
  {
    cat.speak2();
  }
  std::cout << std::endl
            << std::endl;

  Cat1 nabi{"nabi", 3};
  cats2.emplace_back(nabi);            // L-Value : copy
  cats2.emplace_back(std::move(nabi)); // R-Value : move




  /**
   * \brief: std::vector - intermediate level (On memory issue)
   */

  /** \example: #1 */
  std::vector<int> nums4{1, 2, 3, 4, 5};
  std::cout << nums4.size() << " ";
  std::cout << nums4.capacity() << " " << std::endl;
  nums4.emplace_back(6);
  std::cout << nums4.size() << " ";
  std::cout << nums4.capacity() << " " << std::endl;
  for (std::size_t i = nums4.size(); i < 25; i++)
  {
    nums4.emplace_back(i+1);
    std::cout << nums4[i] << " ";
  }
  std::cout << std::endl;
  std::cout << nums4.size() << " ";           // Size: Num
  std::cout << nums4.capacity() << std::endl; // Capacity: retained memory by vector
  // Normarly capacity tries to retain temp memory wi th double size (5 - >10)
  // Need additional time to alloc extra memory (-> reserve)

  std::cout << sizeof(nums4) << std::endl; // Total byte(24) = Pointer(8) + size info(8) + capacity info(8)
  std::cout << std::endl;
  
  /** \example: #2 */
  std::vector<Cat2> cats3;  
  cats3.emplace_back("Kitty3");
  cats3.emplace_back("Nabi3"); // will happen mem copy (not mem`ove) -> unefficient.. it is reason to declare "noexcept" keyword

  std::vector<Cat2> cats4;
  cats4.reserve(2); // MORE CLEAN!
  cats4.emplace_back("Kitty4");
  cats4.emplace_back("Nabi4");





  /**
   * \brief: std::vector - intermediate level (On for loop)
   */

  /** \example: #1 */
  std::size_t n = 10000;
  std::size_t l = 1000;
  std::vector<int> numsa(n, 1);
  std::vector<int> numsb(n, 1);
  std::vector<int> numsc(n, 1);

  // Index-based
  auto start1 = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < l; i++)
  {
    for (std::size_t idx = 0; idx < numsa.size(); idx++)
    {
      numsa[idx] *= 2;
    }
  }
  auto end1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time1 = end1 - start1;
  std::cout << "Index-based loop: " << time1.count() << std::endl;

  // Iterator-based
  auto start2 = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < l; i++)
  {
    for (auto itr = numsb.begin(); itr != numsb.end(); itr++)
    {
      *itr *= 2;
    }
  }
  auto end2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time2 = end2 - start2;
    std::cout << "Iterator-based loop: " << time2.count() << std::endl;

  // Range-based (Safe and stable method)
  auto start3 = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < l; i++)
  {
    for (auto &num : numsc)
    {
      num *= 2;
    }
  }
  auto end3 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> time3 = end3 - start3;
  std::cout << "Range-based loop: " << time3.count() << std::endl;
  std::cout << std::endl;

  /** \example: #2 - In case of coding in index-based loop  */
  std::vector<int> nums11{0, 1, 0, 1};
  std::vector<int> nums22{0, 1, 0, 1};
  std::vector<int> nums33{0, 1, 0, 1};

  for (size_t i = 0; i < nums11.size(); i++)
  {
    if (nums11[i] == 0)
      nums11.emplace_back(2); // If size of vector is changes, index-based loop must use!
  }

  for (auto itr = nums22.begin(); itr != nums22.end(); itr++)
  {
    if (*itr == 0)
      nums22.emplace_back(2); // Possible to copy & move whole vectors another address in memory due to push process! Therefore, itr points meaningless pos in memory
  }

  for (auto &num : nums33)
  {
    if (num == 0)
      nums33.emplace_back(2); // Possible to change capacity. 
  }

  for (const int n : nums11)
    std::cout << n << " ";
  std::cout << std::endl;

  for (const int n : nums22)
    std::cout << n << " ";
  std::cout << std::endl;

  for (const int n : nums33)
    std::cout << n << " ";
  std::cout << std::endl << std::endl;





  /**
   * \brief: std::vector - intermediate level (On erase VS remove)
   * \details: std::remove, std::remove_if
   * Removes all elements satisfying specific criteria from the range [first, last) and returns a past-the-end iterator for the new end of the range.
   * Removing is done by shifting (by means of copy assignment (until C++11) move assignment (since C++11)) the elements in the range in such a way that the elements that are not to be removed appear in the beginning of the range. 
   */

  std::vector<int> nums111 = {0, 1, 0, 1, 0, 1, 0};
  std::vector<int> nums222 = {0, 1, 0, 1, 0, 1, 0};
  std::vector<int> nums333 = {0, 1, 2, 3, 4, 5, 6};
  std::vector<Cat1> cats111;

  /** \example: #1 */
  nums111.erase(std::remove(nums111.begin(), nums111.end(), 0), nums111.end());
  for (const int n : nums111)
    std::cout << n << " ";
  std::cout << std::endl;

  /** \example: #2-1 */
  /** \details: std::remove process
   *             ???(begin)                    ???(end)
   * step 1. [   0   1   0   1   0   1   0   ]

   *             ???   ???                       ???(end)
   * step 2. [   0   1   0   1   0   1   0   ] : Compare [0] VS [1]

   *             ???   ???                       ???(end)
   * step 3. [   1   1   0   1   0   1   0   ] : Delete [0] and Move and Copy from [1] to [0]

   *                 ???   ???                   ???(end)
   * step 4. [   1   1   0   1   0   1   0   ] : pointers are moved next

   *                 ???       ???               ???(end)
   * step 5. [   1   1   0   1   0   1   0   ] : pointer move

   *                     ???       ???           ???(end)
   * step 6. [   1   1   0   1   0   1   0   ] : 2nd pointer points [4] (value 0) So, move next

   *                     ???                   ???(end)
   * step 7. [   1   1   1   1   0   1   0   ] : Delete [5] and Move and Copy from [5] to [3]
   */
  auto itr = std::remove(nums222.begin(), nums222.end(), 0); // *** Very important ***
  for (const int n : nums222)
    std::cout << n << " ";
  std::cout << std::endl;

  /** \example: #2-2 */
  nums222.erase(itr, nums222.end());
  for (const int n : nums222)
    std::cout << n << " ";
  std::cout << std::endl;

  /** \example: #3 */
  nums333.erase(std::remove_if(nums333.begin(), nums333.end(), 
  [](int n){ if(n % 2 == 0) {return true;} return false; } // lamda function (can be set function pointer)
  ), nums333.end());
  for (const int n : nums333)
    std::cout << n << " ";
  std::cout << std::endl;

  /** \example: #4 */
  cats111.emplace_back("cat1", 1);
  cats111.emplace_back("cat2", 2);
  cats111.emplace_back("cat3", 3);
  cats111.emplace_back("cat4", 4);
  cats111.erase(std::remove_if(cats111.begin(), cats111.end(), [](const Cat1 & cat){if(cat.age() % 2 == 0) {return true;} return false;}), cats111.end());
  for (const Cat1 & cat : cats111)
    cat.speak1();
  std::cout << std::endl << std::endl;

  return 0;
}