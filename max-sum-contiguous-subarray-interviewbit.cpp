int Solution::maxSubArray(const vector<int> &A) {
    int len = A.size();
    int i, max_sum, curr_max;
    //max_sum = INT_MIN;
    curr_max = A[0];
    max_sum = A[0];
    for (i = 1; i < len ; i++)
    {
        //if (new_sum_here < 0) { new_sum_here = 0; }
        
        curr_max = max (curr_max + A[i] , A[i]);
        //new_sum_here = new_sum_here + A[i];
        max_sum = max (max_sum , curr_max);
        
    }
    
    return max_sum;
}

