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
    int low= 1, high= A.size(), ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(subarraySum(A, mid) <= S) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {1, 3, 4, 2};
    int S = 7;
    int result = findMaxX(A, S);
    cout << result << endl; 
    return 0;
}
