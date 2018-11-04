int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int k = A.size(), sum = 0;
    for (int i = 0; i < k - 1 ; i++)
    {
        int m1 = abs(A[i+1] - A[i]);
        int m2 = abs(B[i+1] - B[i]);
        sum = sum + max(m1 , m2);
    }
    
    return sum;
}

