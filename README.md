## LeetCode C++ Solutions (中文题名)

### Overview

This repository contains a curated set of LeetCode solutions written in C++. Filenames are in the format `<id>.<Chinese-title>.cpp`, for example `1.两数之和.cpp`, `42.接雨水.cpp`, `200.岛屿数量.cpp`. Each file typically defines a `class Solution` function per LeetCode’s requirements and is intended to be run directly on LeetCode.

### Repo structure

- Solutions live at the repository root as standalone `.cpp` files
- Naming convention: `<problem-id>.<Chinese-problem-title>.cpp`
- Example files:
  - `1.两数之和.cpp` — Two Sum
  - `42.接雨水.cpp` — Trapping Rain Water
  - `200.岛屿数量.cpp` — Number of Islands

### How to use these solutions

#### Run on LeetCode (recommended)

1) Open the corresponding problem on LeetCode
2) Choose C++ as the language
3) Paste the contents of the matching file into the editor
4) Click Run/Submit

Because these files target LeetCode’s environment, they may omit some standard headers and do not include a `main()`.

#### Compile locally (optional)

These source files are not designed to be compiled as-is on your machine because LeetCode provides:

- The online judge driver (`main()` and I/O)
- Some standard headers implicitly

If you still want to compile locally, you have two options:

1) Augment the file with any missing headers and write a small `main()` to feed inputs
2) Create a separate test harness that includes the solution header and calls its methods

Minimal example harness for `1.两数之和.cpp` (you may need to add missing includes like `<unordered_map>` in the solution file):

```cpp
#include <bits/stdc++.h>
using namespace std;

// Include or paste your Solution here
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_by_value;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int want = target - nums[i];
            if (index_by_value.count(want)) return {index_by_value[want], i};
            index_by_value[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    auto ans = Solution().twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << "\n"; // 0 1
    return 0;
}
```

Compile with a modern C++ compiler (C++17 or newer):

```bash
g++ -std=c++17 -O2 -pipe -Wall -Wextra -o run main.cpp
./run
```

Note: Some solution files rely on headers like `<unordered_map>`, `<queue>`, `<stack>`, etc., that LeetCode auto-provides in templates. Add them as needed for local builds.

### Environment

- C++17 (or newer)
- Compiler: g++ 11+ or clang++ 13+

### Contributing

- Follow the naming convention: `<id>.<Chinese-title>.cpp`
- Keep implementations self-contained in `class Solution`
- Prefer readable code, meaningful names, and handle edge cases
- If adding solutions intended for local compilation, include all necessary headers and an isolated driver or unit tests

### FAQ

- Why no `main()` in files?
  - LeetCode injects the driver and test cases; only `class Solution` is required.
- Why are some headers missing?
  - LeetCode templates often include common headers. For local builds, add any missing includes.

### Acknowledgements

Problems are from LeetCode. Filenames use the official Chinese problem titles for easy mapping.

