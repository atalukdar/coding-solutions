vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    int len = A.size();
    int j, diff, indi1, indi2, arr[2];
    std::vector<int> ints;


    unordered_map <int , int> sum_map;
    for (j = 0; j < len ; j++)
    {
        diff = B - A[j];
        
        if(sum_map.find(diff) != sum_map.end())
        {
            
            if( sum_map[diff] == j)
            {
                continue;
            }
            else{
                ints.push_back(sum_map[diff] + 1);
            ints.push_back(j+1);
            //arr[0] = ;
            //arr[1] = j;
            break; }
        }
        
        if(sum_map.find(A[j]) == sum_map.end())
        {
            sum_map[A[j]] = j;
        }
        
        
    }
    
    return ints;
}

