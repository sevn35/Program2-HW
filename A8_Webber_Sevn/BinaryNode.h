
template <class T>
struct BinaryNode{
//    data members:
   T data; //(key,object)
   BinaryNode<T> *left;
   BinaryNode<T> *right;
//    constructors:
   BinaryNode();
   BinaryNode(const T&); 
   BinaryNode(const BinaryNode<T>&);

   // virtual methods: Used in data sturct class
   //virtual void set_balance(Balance_factor b);
   //virtual Balance_factor get_balance() const;
};

template <class T>
BinaryNode<T>::BinaryNode(){
   left = right = nullptr;
   //data = 1  not possible to initalize data using default constructor 
}

template <class T>
BinaryNode<T>::BinaryNode(const T &x){
   data = x;
   left = right = nullptr;
}

/* Data struct again
// Dummy functions
template <class T>
void BinaryNode<T>::set_balance(Balance_factor b){
}

template <class T>
Balance_factor BinaryNode<T>::get_balance() const {
	return equal_height;
}
*/