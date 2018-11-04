int Solution::colorful(int A) {
    unordered_map<long long int , int> color_map;
    char number_string[20];
    int num_len, i, j, val;
    val = 1;
    long long int mul;
    sprintf(number_string , "%d" , A);
    num_len = strlen(number_string);
    for (i=0; i < num_len ; i++)
    {
        mul = 1;
        for (j = i ; j < num_len ; j++)
        {
            mul = mul * (long long int)(number_string[j] - '0') ;
            if (color_map.find(mul) != color_map.end())
            {return 0;}
            else 
            {color_map.insert({mul , 1}); }
        }
    }
    return 1;
}

