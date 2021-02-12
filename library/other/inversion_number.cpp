/* BIT */
/// @see [https://pione.hatenablog.com/entry/2021/01/31/023406]
long long inversion_number(const vector<long long>& v){
  auto u=v;
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  
  auto bit=BIT<long long>(u.size());
  
  long long res=0;
  for(int i=0; i<v.size(); i++){
    int rank=lower_bound(u.begin(), u.end(), v[i])-u.begin()+1;
    res+=i-bit.sum(rank);
    bit.add(rank);
  }
  return res;
}