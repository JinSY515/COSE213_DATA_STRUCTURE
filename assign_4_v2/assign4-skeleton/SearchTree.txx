  template <typename E>					// constructor
  SearchTree<E>::SearchTree() : T(), n(0)
    { T.addRoot(); T.expandExternal(T.root()); }	// create the super root
  
  template <typename E>
  SearchTree<E>::~SearchTree(){
    //destructor
  }

  template <typename E>					// get virtual root
  typename SearchTree<E>::TPos SearchTree<E>::root() const
    { return T.root().left(); }				// left child of super root
  
   template <typename E>					// iterator to first entry
  typename SearchTree<E>::Iterator SearchTree<E>::begin() {
    TPos v = root();					// start at virtual root
    while (v.isInternal()) v = v.left();		// find leftmost node
    return Iterator(v.parent());
  }
  
  template <typename E>					// iterator to end entry
  typename SearchTree<E>::Iterator SearchTree<E>::end()
    { return Iterator(T.root()); }			// return the super root
    
  template <typename E>					// remove key k entry
  void SearchTree<E>::erase(const K& k) { //throw(NonexistentElement) {
    TPos v = finder(k, root());				// search from virtual root
    if (! v.isExternal())					// found
      eraser(v);						// remove it
  }
  
  template <typename E>					// erase entry at p
  void SearchTree<E>::erase(const Iterator& p)
    { eraser(p.v); }
    
  template <typename E>					// find entry with key k
  typename SearchTree<E>::Iterator SearchTree<E>::find(const K& k) {
    TPos v = finder(k, root());				// search from virtual root
    if (v.isInternal()) return Iterator(v);		// found it
    else return end();					// didn't find it
  }  
  
  template <typename E>					// insert (k,x)
  typename SearchTree<E>::Iterator SearchTree<E>::insert(const K& k, const V& x)
    { TPos v = inserter(k, x); return Iterator(v); }  
 
  template <typename E>
  int SearchTree<E>::size() const { return n; }  
    
    
//
// ToDo
//    
 
  template <typename E>					// inorder successor
  typename SearchTree<E>::Iterator& SearchTree<E>::Iterator::operator++() {
   
   // ToDo
   // 1. if the node v has a right child, the inorder successor is the LEFTMOST
   //    internal node of its right subtree
   TPos rc = v.right(); // right subtree of V
   if(rc.isInternal()){
     do{
       v = rc;
       rc = rc.left();  
     }while(rc.isInternal()); //leftmost
   }
   // 2. if not, v is the largest key in the left subtree of some node rc.
   //    Trace up the tree through successive ancestors.
   else{
     rc = v.parent();
     // 3. move up right chain
     while(v == rc.right()){
       v = rc; 
       rc = rc.parent();
     }
     v = rc;
   }
   return *this;
  }
     
    
    
  template <typename E>					// remove utility
  typename SearchTree<E>::TPos SearchTree<E>::eraser(TPos& v) {
       
    // ToDo
    // 1. If the node v has an external child, set z to point to this child.
    TPos z;
    if(v.left().isExternal()) z = v.left();
    else if(v.right().isExternal()) z = v.right();
    // 2. If not, let z be the leftmost external node in v's right subtree.
    else{
      z = v.right(); 
      do{ z = z.left();} while(z.isInternal()); //move down to the leftmost node of the right subtree.
      // 3. Let y be z's parent.
      TPos y = z.parent();
      // 4. Copy y's entry to v.
      (*v).setKey((*y).key());
      (*v).setValue((*y).value());
    }
    // 5. reduce the size n
    n--;
    // 6. remove the external node z and its parent.
    return T.removeAboveExternal(z);
  }
      
  template <typename E>					// find utility
  typename SearchTree<E>::TPos SearchTree<E>::finder(const K& k, const TPos& v) {
    
    // ToDo
    // 1. is it external?
    //std::cout << "finder : " << (*v).key() << std::endl;
    if(v.isExternal()) return v; // cannot find the key and terminate at the external node
    // 2. move down subtree
    if(k<(*v).key()) return finder(k, v.left()); //find left subtree
    else if(k > (*v).key()) return finder(k, v.right()); //find right subtree
    // 3. Found?
    else return v; // found!
  }
  
  template <typename E>					// insert utility
  typename SearchTree<E>::TPos SearchTree<E>::inserter(const K& k, const V& x) {
    
    // ToDo
    // 1. use finder
    
    TPos f = finder(k, root());
    // 2. if key already exists, replace the value

    if(f.isExternal()){
      T.expandExternal(f);
      (*f).setKey(k);   //set entry
      (*f).setValue(x);
      //TPos fp = f.parent();
      //std::cout << "f's parent : " << (*fp).key() << std::endl;
      n++;
    }
    // 3. if not, finding terminates at the external
    else{
      // if key already exists
      (*f).setValue(x);
      // just change the value
    }

    //std::cout << "num : " <<size() << " " << T.size() <<std::endl;
  
    //4. return the inserting point
    
   /*
    TPos f = finder(k, root());
    while(f.isInternal()){
      f = finder(k, f.right());
    }
    T.expandExternal(f);
    (*f).setKey(k);
    (*f).setValue(x);
    */
    //n++;
    
    
    return f;
  }
  