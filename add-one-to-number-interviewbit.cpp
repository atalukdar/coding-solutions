vector<int> Solution::plusOne(vector<int> &A) {
    
    int s = A.size(), flag = 1;
    //printf(" %d ", s);
    while( flag )
    {
        if(A[s - 1] == 9)
        {
            A[s - 1] = 0;
            s--;
            if (s == 0)
            {
                A.push_back(0);
                A[0] = 1;
                flag = 0;
            }
            //printf("k%d ", s);
        }
        else {
            A[s-1] = A[s-1] + 1 ;
            //printf("%d", A[s]);
            flag = 0;
            //printf("t%d ", s);
        }
    }
    while (A[0] == 0){
      A.erase(A.begin());
  }
    return A;
}

