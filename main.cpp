#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
#include "../utils/ListNode.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int getDecimalValue(ListNode *head) {
    ListNode *curr = head;
    unsigned int total = 0;
    while (curr != nullptr) {
      total <<= 1;
      total |= curr->val;
      curr = curr->next;
    }
    return total;
  }

  int getDecimalValue2(ListNode *head) {
    ListNode *curr = head;
    unsigned int unitValue = 1;
    while (curr != nullptr) {
      unitValue <<= 1;
      curr = curr->next;
    }
    unitValue >>= 1;
    int total = 0;
    curr = head;
    while (curr != nullptr) {
      if (curr->val == 1)
        total += unitValue;
      unitValue >>= 1;
      curr = curr->next;
    }
    return total;
  }
};

void test1() {
  string str = "1,0,1";
  ListNode *lx = new ListNode(str);

  cout << "5 ? " << Solution().getDecimalValue(lx) << endl;
}

void test2() {

}

void test3() {

}