#include <bits/stdc++.h>
using namespace std;

// 二分探索木

// node *root = NULL; node型のポインタを宣言する
// root = insert(root, 1);
// find(root, 1);

// ノードを表す構造体
struct node{
  int val;
  node *lch, *rch; // left child, right child
};

// 数xを追加. 引数、戻り値はnode型のポインタとなる
node *insert(node *p, int x){
  if(p == NULL){ // 移動先にノードが存在していなければ、値がxのノードを新規作成する
    node *q = new node;
    q->val = x;
    q->lch = q->rch = NULL; // 子ノードをNULLで初期化する
    return q;
  }else{
    if(x < p->val){ // 現在のノード>x ならば、左の子ノードへ移動
      p->lch = insert(p->lch, x);
    }else{ // 現在のノード<=x ならば、右のノードへ移動
      p->rch = insert(p->rch, x);
    }
    return p; // rootノードを返却する
  }
}

// 数xを検索
bool find(node *p, int x){
  if(p == NULL) return false;
  else if(x == p->val) return true;
  else if(x < p->val) find(p->lch, x);
  else return find(p->rch, x);
}

// 数xを削除. 削除対象が存在しない場合を想定していないため、removeを呼び出し前にfindで削除対象の値が存在するかの確認を行う必要がある
// 削除ノードの埋め合わせ方の場合分けの仕方.
// (左の子の数のグループ) < 削除するノード <= (右の子の数のグループ)
// 削除後にも上記の関係を保持するには、左の子が存在する場合、左の子の数のグループの最大値を持ってくる. 左の子のが存在しない場合、右の子の数のグループの根を持ってくる
// (1) 削除したいノードが左の子を持っていない場合、右の子を持ってくる. 
// (2) 削除したいノードの左の子が右の子を持たない場合、左の子を持ってくる. 左の子の数のグループの中で、左の子が最大の数になるため
// (3) どちらでもない場合(つまり左の子が存在し、それが右の子を持つ場合)、左の子の数のグループの中で最大のノードを持ってくる
node *remove(node *p, int x){
  if(p == NULL) return NULL;
  else if(x < p->val) p->lch = remove(p->lch, x); // 左の子を探索
  else if(x > p->val) p->rch = remove(p->rch, x); // 右の子を探索
  else if(p->lch == NULL){ // (1)
    node *q = p->rch;
    delete p; // ノードを削除. deleteは確保したメモリの解放を行う
    return q;
  }else if(p->lch->rch == NULL){ // (2)
    node *q = p->lch;
    q->rch = p->rch; // pの左の子ノードの右の子の場所へ、pの右の子を持っていく
    delete p;
    return q;
  }else{ // (3)
    node *q;
    for (q = p->lch; q->rch->rch != NULL; q = q->rch); // qの右の子ノードの右の子ノードがNULLになるまでqを右の子へ下っていく. 2つ下を探索するのは (2) の分岐でqには右の子があることがわかっているため
    node *r = q->rch; // q->rchが、左の子の数のグループの中で最大のノードとなる. q->rchをポインタ変数rへ退避
    q->rch = r->lch; // q->rchは削除されることになるためここに対してもノードの移動が必要. qは右の子ノードを持たないため左の子ノードを持ってくれば関係は保持される
    r->lch = p->lch; // pの左の子をrの左の子へ連結
    r->rch = p->rch; // pの右の子をrの右の子へ連結
    delete p;
    return r;
  }
  return p; // 最後にrootノードを返すときに呼ばれる
}