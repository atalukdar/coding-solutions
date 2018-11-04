vector<int> Solution::lszero(vector<int> &A) {
    int len = A.size();
    int i, j, len_seq, sum = 0, max_len =0, end = -1, start = -1, len_present = 0;
    unordered_map <int, int> len_map;
for (j = 0 ; j < len ; j++)
        {
            sum = sum + A[j];
            if(sum == 0)
            {
                len_present = j + 1;
                if(max_len < len_present)
                {
                    max_len = len_present;
                    start = -1;
                    end = j;
                }
            }
            else if(len_map.find(sum) != len_map.end())
            {
                len_present  = j - len_map[sum] ;
                //printf("-%d-", len_present);
                if(max_len < len_present)
                
                {
                    //printf("s %d ", sum);
                    max_len = len_present;
                    start = len_map[sum];
                    end = j;
                    
                    //printf("_%d_%d_", start, end);
                }
            }
            else
            {
                len_map[sum] = j;
            }
                
        }
             
        
    vector<int> max_string;
    for (i = start + 1 ; i <= end ; i++)
    {
        max_string.push_back(A[i]);
    }

    return max_string;
}

