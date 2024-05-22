int NthRoot(int n, int m) {
  // Write your code here.
  int low=0;
  int high=m;
  if(m==1){
    return 1;
  }
  if(n==1){
    return m;
  }
  if(m==0){
    return 0;
  }
  auto pow = [](int x, int y, int limit) {
    long long result = 1;
    for (int i = 0; i <y; ++i) {
      result *= x;
      if (result > limit) {
        return (long long)(limit) + 1; 
      }
    }
    return result;
  };
  while(low<=high){
    int mid=(low+high)/2;
    int midPower=pow(mid,n,m);
    if(midPower==m){
      return mid;
    }else if(midPower<m){
      low=mid+1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
