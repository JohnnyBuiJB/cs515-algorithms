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
    int last_prefix_sum = 0;
    int last_largest_sum = A[k];
    k--;

    while (k >= 0) {
        int combined_sum = A[k] + last_largest_sum + last_prefix_sum;
        int max_sum = std::max(A[k], last_largest_sum);
        max_sum = std::max(max_sum, combined_sum);
        
        if (max_sum == combined_sum) {
            last_prefix_sum = 0;
            last_largest_sum = combined_sum;
        } else if (max_sum == A[k]) {
            last_prefix_sum = 0;
            last_largest_sum = A[k];
        } else {
            last_prefix_sum += A[k];
        }

        k--;
    }

    return last_largest_sum;
}

int main() {
    std::vector<int> in1 = {-6,12,-7,0,14,-7,5};
    auto out1 = lsa(in1);
    assert(out1 == 19);

    std::vector<int> in2 = {2,-1,2};
    auto out2 = lsa(in2);
    assert(out2 == 3);

    std::vector<int> in3 = {};
    auto out3 = lsa(in3);
    assert(out3 == 0);

    std::vector<int> in4 = {-1,-2};
    auto out4 = lsa(in4);
    assert(out4 == -1);

    return 0;
}
