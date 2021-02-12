# C++ cheat sheet

標準ライブラリに関するメモ

```cpp
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

const int MOD = 1e9+7;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  puts("min-max");
  {
    ll a[] = {1,2,3,4};
    vll b = {1,2,3,4};
    
    cout<<min({1,2,3,4})<<endl;
    // cout<<min(a)<<endl; // この書き方は許容されない
    
    // 配列、vector の最大値、最小値の取得
    cout<<*min_element(a,a+4)<<endl; // 1
    cout<<*min_element(all(b))<<endl; // 1
    
    // 区間を指定することもできる（半開区間なので第二引数には index+1 の値を指定する）
    cout<<*max_element(a+1,a+3)<<endl; // 3
    cout<<*min_element(b.begin()+1,b.begin()+3)<<endl; // 2
    
    cout<<endl;
  }
  
  puts("rand");
  {
    // 実行毎に乱数生成されるようになる
    srand((unsigned)time(NULL));
    
    // 0以上2^31-1以下の正整数の乱数が生成される（Visual Studio 2019 の場合、2^15-1 までの値となる）
    if(rand()%10<=8) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
   
    cout<<endl; 
  }
  
  puts("time");
  {
    // 実行時間の計測
    ll start_time = clock();
    
    ll x = rand();
    rep(i,10000) x%=MOD; // 適当な計算
    
    // CLOCKS_PER_SEC で計算結果の時間の単位を秒にしている
    printf("Execution Time: %.10lf sec\n", 1.0*(clock()-start_time)/CLOCKS_PER_SEC);
    
    cout<<endl;
  }
 
  puts("stack");
  {
    // push / top / pop / size / empty などが使える
    // push / pop / top は O(1)
    stack<ll> a;
    a.push(1);
    a.push(2);
    a.push(3); // この時点で {1,2,3}
    ll x1=a.top(); // 3
    a.pop(); // {1,2}
    a.push(4); // {1,2,4}
    ll x2=a.top(); // 4
    cout<<x1<<" "<<x2<<endl;
    
    cout<<endl;
  }
  
  puts("queue");
  {
    // push / front / pop / size / empty などが使える
    // push / front / pop は O(1)
    queue<ll> q;
    q.push(1);
    q.push(2);
    q.push(3);
    ll x1=q.front();
    q.pop();
    ll x2=q.front();
    cout<<x1 <<" "<<x2<<endl;
    
    cout<<endl;
  }
  
  puts("priority_queue");
  {
    // push / top / pop / size / empty などが使える
    // push / top / push は O(log N)
    
    // デフォルトでは降順となる
    priority_queue<ll> q;
    q.push(1);
    q.push(3);
    q.push(2);
    ll x1=q.top();
    q.pop();
    ll x2=q.top();
    q.pop();
    cout<<x1 <<" "<<x2<<endl;
    
    // 昇順
    priority_queue<ll, vector<ll>, greater<ll>> qa;
    qa.push(1);
    qa.push(2);
    qa.push(3);
    ll y1=qa.top();
    qa.pop();
    ll y2=qa.top();
    qa.pop();
    cout<<y1 <<" "<<y2<<endl;
    
    cout<<endl;
  }
  
  puts("lower_bound");
  {
    // 第三引数以上の値が初めて登場する index のイテレータを返す
    
    // 配列
    ll a[] = {5,3,2,1,4};
    sort(a,a+5);
    cout<<lower_bound(a,a+5,2)-a<<endl; // 1
    
    // vector
    vll b = {5,3,2,1,4};
    vsort(b);
    cout<<lower_bound(b.begin(), b.end(), 2)-b.begin()<<endl; // 1
    
    cout<<endl;
  }
  
  puts("upper_bound");
  {
    // 第三引数より大きい値が初めて登場する index のイテレータを返す
    
    // 配列
    ll a[] = {5,3,2,1,4};
    sort(a,a+5);
    cout<<upper_bound(a,a+5,2)-a<<endl; // 2
    
    // vector
    vll b = {5,3,2,1,4};
    vsort(b);
    cout<<upper_bound(b.begin(), b.end(), 2)-b.begin()<<endl; // 2
    
    cout<<endl;
  }
  
  puts("set");
  {
    // insert / erase / lower_bound / clear
    // おおよその操作は O(log N)
    // set 内は昇順に要素が並んでおり、イテレータ itr に対して itr++ とすると次に大きい要素を指すようになる
    set<ll> se;
    se.insert(1);
    se.insert(2);
    se.insert(3);
    auto itr=se.lower_bound(4);
    if(itr==se.end()) cout<<"End"<<endl; // 出力される
    
    se.erase(3);
    se.insert(4);
    auto itr2=se.lower_bound(2);
    cout<<*itr2<<endl; // 2
    itr2++;
    cout<<*itr2<<endl; // 4
    
    se.clear();
    se.insert(4); se.insert(1); se.insert(2); se.insert(3); se.insert(5);
    
    // 1 2 3 4 5 と昇順に出力される
    auto itr3=se.begin();
    while(itr3!=se.end()){
      cout<<*itr3<<" ";
      itr3++;
    }
    cout<<endl;
    
    cout<<endl;
  }
  
  puts("map");
  {
    // 存在しない key を指定した場合、map<Key, T> の T() がデフォルト値として返る
    map<ll, char> m1;
    if(m1[0]==char()) cout<<"There is not such a key."<<endl;
    
    map<ll, ll> m2;
    if(m2[0]==ll()) cout<<"also"<<endl;
  }
  
  puts("tuple");
  {
    tuple<ll,ll,ll> a;
    get<0>(a)=1, get<1>(a)=2, get<2>(a)=3;
    cout<<get<0>(a) <<" "<<get<1>(a) <<" "<< get<2>(a) <<endl;
    
    tuple<ll,ll,ll> b = {3,4,5};
    cout<<get<0>(b) <<" "<<get<1>(b) <<" "<< get<2>(b) <<endl;
    
    vector<tuple<ll,ll,ll>> v;
    v.push_back({1,2,4});
    v.push_back({1,2,3});
    vsort(v);
    // 以下の順で出力される
    // 1 2 3
    // 1 2 4
    for(auto e: v){
      cout<<get<0>(e) <<" "<<get<1>(e) <<" "<< get<2>(e) <<endl;
    }
    
    // make_tuple(a1,a2,...,an) は、引数のコピーから tuple が作られる
    ll x=1;
    tuple<ll> c=make_tuple(x);
    x=2;
    cout<<get<0>(c)<<endl; // 1
    
    // make_tuple と同じ挙動
    ll y=1;
    tuple<ll> d={y};
    y=2;
    cout<<get<0>(d)<<endl; // 1
    
    cout<<endl;
  }
  
  puts("assert");
  {
    ll n=1000;
    assert(n<=1000); // nが1000より大きいならば、ここで終了 ... int main(): Assertion `n<=1000' failed.
    
    cout<<endl;
  }
  
  puts("iota");
  {
    // 指定された値から始まる整数列を生成する
    
    vll v(5);
    iota(all(v),0);
    rep(i,5) cout<<v[i]<<" ";
    cout<<endl;
    
    ll a[5];
    iota(a,a+5,5);
    rep(i,5) cout<<a[i]<<" ";
    cout<<endl;
    
    cout<<endl;
  }
  
  puts("count");
  {
    // 配列、vector のある区間内に指定した値がいくつ含まれるかを返す
    int a[] = {1,2,3,4,1,2,3,1,2,1};
    cout<<count(a,a+10,1)<<endl; // 4
    cout<<count(a+5,a+10,1)<<endl; // 対象区間は {2,3,1,2,1} なので、2
    
    // 区間[l,r] に対象要素はいくつあるか、というQ回のクエリを回す
    vll b={1,2,3,4,1,2,3,1,2,1};
    ll q=3;
    vector<pll> v={{3,4}, {5,7}, {0,9}};
    rep(i,q){
      ll l=v[i].first, r=v[i].second+1;
      cout<<count(b.begin()+l,b.begin()+r,1)<<" "; // 1 1 4 と出力
    }
    cout<<endl;
    
    cout<<endl;
  }
  
  puts("find");
  {
    // 配列、vector のある区間内に指定の要素が含まれるかを返す
    
    ll l=2, r=5;
    
    // 配列
    int a[] = {1,2,3,4,1,2,3,1,2,1};
    ll index=find(a+l,a+r+1,3)-a;
    if(index==r+1) puts("-1");
    else cout<<index<<endl; // 2
    
    // vector
    vll b={1,2,3,4,1,2,3,1,2,1};
    index=find(b.begin()+l,b.begin()+r+1,100)-b.begin();
    if(index==r+1) puts("-1"); // -1
    else cout<<index<<endl;
    
    cout<<endl;
  }
}
```
