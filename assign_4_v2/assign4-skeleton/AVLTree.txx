//
// Implementation
//
template <typename E>					// constructor
  AVLTree<E>::AVLTree() : ST() { }

template <typename E>
  AVLTree<E>::~AVLTree(){}    //destructor

template <typename E>					// node height utility
  int AVLTree<E>::height(const TPos& v) const
    { return (v.isExternal() ? 0 : (*v).height()); }

template <typename E>					// set height utility
  void AVLTree<E>::setHeight(TPos v) {
    int hl = height(v.left());
    int hr = height(v.right());
    (*v).setHeight(1 + std::max(hl, hr));			// max of left & right 
    
    
  }

template <typename E>					// is v balanced?
  bool AVLTree<E>::isBalanced(const TPos& v) const {	
    int bal = height(v.left()) - height(v.right());
    return ((-1 <= bal) && (bal <= 1));
  }

template <typename E>					// get tallest grandchild
  typename AVLTree<E>::TPos AVLTree<E>::tallGrandchild(const TPos& z) const {
    TPos zl = z.left();
    TPos zr = z.right();
    if (height(zl) >= height(zr))			// left child taller
      if (height(zl.left()) >= height(zl.right()))
        return zl.left();
      else
        return zl.right();
    else 						// right child taller
      if (height(zr.right()) >= height(zr.left()))
        return zr.right();
      else
        return zr.left();
  }


//
// ToDo
//

template <typename E>					// remove key k entry
  void AVLTree<E>::erase(const K& k) {
    
    // ToDo
    // 1. use finder to find key k
    TPos f = ST::finder(k, ST::root());
    if(!f.isExternal()) 
    {
      TPos e = ST::eraser(f);
      rebalance(e);
    }
    // 2. if found, remove it => rebalance again
    
  }


  


template <typename E>				// Binary Search Tree Rotation
  typename AVLTree<E>::TPos AVLTree<E>::restructure(const TPos& v) {
   
	// ToDo
  //Input v : A node of a bst T that has both a parent y and a grandparent z
  //if(v.isExternal()) expandExternal(v);
  TPos x = v;
  TPos y = x.parent();
  TPos z = y.parent();
  TPos gp = z;
  TPos ggp= z.parent();
  // Let (a, b, c) be a left-to-right(inorder) listing of the nodes x, y, and z, 
  //and let (T0, T1, T2, T3) be a left-to-right listing of four subtrees
  TPos a, b, c, T0, T1, T2, T3;
  //struct LinkedBinaryTree<E>::Position::v* a_n, b_n, c_n, T0_n, T1_n, T2_n, T3_n;

  if(y ==z.left() && x == y.left()){
    // R Rotate
    a = x;
    b = y; 
    c = z;
    T0 = a.left();
    T1 = a.right();
    T2 = b.right();
    T3 = c.right();

    //std::cout << "R Rotate " ;
  }
  else if(z.right() == y && y.right() ==x){
    // L Rotate
    a = z;
    b = y;
    c = x;
    T0 = a.left();
    T1 = b.left();
    T2 = c.left();
    T3 = c.right();
   //std::cout << "L Rotate " ;
  }
  else if(z.right() == y && y.left() ==x){
    // RL Rotate
    a = z;
    b = x;
    c = y;
    T0 = a.left();
    T1 = b.left();
    T2 = b.right();
    T3 = c.right();
    //std::cout << "RL Rotate " ;
  }
  else if(z.left() == y && y.right() == x){
    a = y;
    b = x;
    c = z;
    T0 = a.left();
    T1 = b.left();
    T2 = b.right();
    T3 = c.right();
    //std::cout << "LR Rotate " ;
  }
  // 2. Replace the subtree rooted at z with a new subtree rooted at b.
  
  if(z == ST::root()){
    ST::root() = b;
    //Iterator(b.parent()) = ST::end();
    b.v->par = ST::root().v;
  }
  else{
    if(ggp.left() == gp){
      ggp.v->left = b.v;
      b.v->par = gp.v->par;
    }
   else if(ggp.right() == gp){
      ggp.v->right = b.v;   
      b.v->par = gp.v->par;    
    }
  }    
  
  b.v->left = a.v;
  b.v->right = c.v;
  a.v->par=b.v;
  c.v->par =b.v;
   // std::cout << ((b.left() == a) ? "True " : "False ");
  //  std::cout << ((a.parent() == b)? "True " : "False ");
   // std::cout << ((b.right() == c) ? "True " : "False ");
  //  std::cout << ((c.parent() ==b )? "True " : "False ") << std::endl << std::endl;

  
  T0.v->par = a.v;
  a.v->left = T0.v;
  T1.v->par = a.v;
  a.v->right = T1.v;
  T2.v->par = c.v;
  c.v->left = T2.v;
  
  T3.v->par =c.v;
  c.v->right = T3.v;

  return b;

}

template <typename E>					// rebalancing utility
  void AVLTree<E>::rebalance(const TPos& v) {
    
    // ToDo
    TPos z = v;
    while(!(z==ST::root())){
      z = z.parent();
      setHeight(z);
      if(!isBalanced(z)){
        TPos x = tallGrandchild(z);
        z= restructure(x);
        setHeight(z.left());
        setHeight(z.right());
        setHeight(z);
      }
    }
   
  }
template <typename E>					// insert (k,x)
  typename AVLTree<E>::Iterator AVLTree<E>::insert(const K& k, const V& x) {
    
    // ToDo
    // 1. use inserter
    TPos  v = ST::inserter(k, x);
    setHeight(v);
    rebalance(v);
    return Iterator(v);
  }