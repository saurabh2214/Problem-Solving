#include <iostream>
#include <vector>
using namespace std;

int subarraySum(const vector<int>& A, int X) {
    int N = A.size();
    int sum = 0;
    for(int i = 0; i < X; ++i) {
        sum += A[i];
    }
    int result = sum;
    for(int i = X; i < N; ++i) {
        sum += A[i] - A[i - X];
        result = max(result, sum);
    }
    return result;
}

int findMaxX(const vector<int>& A, int S) {
    int left = 1, right = A.size(), result = 0;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(subarraySum(A, mid) <= S) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> A = {1, 3, 4, 2};
    int S = 7;
    int result = findMaxX(A, S);
    cout << result << endl; 
    return 0;
}
