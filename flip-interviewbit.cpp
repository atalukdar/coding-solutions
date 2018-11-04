vector<int> Solution::flip(string A) {
    int maxone, sl, sr, absmax, currmax, slhere, srhere, vlen, len, change;
    vlen = A.length();
    //printf("len is %d", vlen);
    len = vlen;
    sl = 0;
    sr = 0;
    srhere = 0;
    slhere = 0;
    absmax = 0;
    currmax = 0;
    /*for(int i =0; i < len; i++)
    {
        if (A[i] == '1')
        {absmax++;}
        //printf("under abs max %d", absmax);
    //printf("abs max %d, ai %c", absmax, A[i]);
    }*/

    vector <int> retur;
    
    // count total one
    for (int i = 0; i < vlen; i++)
    {
        if(A[i] == '0')
        {
            change = 1;
            
        }
        else
        {
            change = -1;
        }
        //printf("cange is %d", change);
        
        if(change > (currmax + change))
        {
            slhere = i;
            currmax = change;
        }
        else{
            currmax = currmax + change;
        }
        srhere = i;
        
        if(currmax > absmax)
        { //printf("i am here");
            sl = slhere + 1;
            sr = srhere + 1;
            
            absmax = currmax;
            retur.clear();
            retur.push_back(sl);
            retur.push_back(sr);
        }
    }
    //printf("vals are%d %d ", retur[0], retur[1]);
    return retur;
}

