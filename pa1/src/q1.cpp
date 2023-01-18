#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

int lsa(std::vector<int> &A) {
    // Trivial
    if (A.size() == 0) {
        return 0;
    }

    int k = A.size() - 1;
    int max_prefix_sum = std::max(0, A[k]);
    int last_largest_sum = A[k];
    k--;
    
    while (k >= 0) {
        max_prefix_sum += A[k];
        int max_sum = std::max(max_prefix_sum, last_largest_sum);
        max_sum = std::max(max_sum, A[k]);
        
        if (max_sum == max_prefix_sum) {
            last_largest_sum = max_prefix_sum;
        } else if (max_sum == A[k]) {
            max_prefix_sum = A[k];
            last_largest_sum = A[k];
        } else {
            max_prefix_sum = std::max(0, max_prefix_sum);
        }

        k--;
    }

    return last_largest_sum;
}

int main() {
    std::vector< std::vector<int> > ins = 
    {
        {-6,12,-7,0,14,-7,5},
        {2,-1,2},
        {},
        {-1,-2},
        {-2,1,-3,4,-1,2,1,-5,4},
        {1,2,-1},
    };

    std::vector<int> exp = 
    {
        19,
        3,
        0,
        -1,
        6,
        3
    };

    int i = 0;
    int from_tc = 0;
    int to_tc = 5;

    for (int i = from_tc; i <= to_tc; i++) {
        auto act = lsa(ins[i]);

        if (act != exp[i]) {
            std::cout << "Test " << std::to_string(i) << " FAILS!!!" << std::endl;
            std::cout << "Expected: " << std::to_string(exp[i]) << "\tActual: " 
                << std::to_string(act) << std::endl;
        }
    }

    return 0;
}
