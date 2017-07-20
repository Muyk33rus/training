#include <iostream>
#include <string>
#include <memory>
using std::string;

template <typename T>
void print(const T &t){
    for(typename T::const_iterator it =t.begin();it!=t.end();it++){
        std::cout<<*it;
    }
    std::cout<<std::endl;
}

template<typename T>
struct Node{
private:
    template<typename Iter>
    struct NodeIterator{
        friend class Node;
    public:
        typedef Iter iterator_type;
        typedef std::input_iterator_tag iterator_category;
        typedef iterator_type value_type;
        typedef ptrdiff_t difference_type;
        typedef iterator_type& reference;
        typedef iterator_type* pointer;
        iterator_type* value;
    private:
        NodeIterator(Iter*p):value(p){}
    public:
        NodeIterator(const NodeIterator& it):value(it.value){}
        bool operator !=(NodeIterator const & other)const{
            return value != other.value;
        }
        bool operator ==(NodeIterator const & other)const{
            return value == other.value;
        }
        typename NodeIterator::reference operator*(){
            return *value;
        }
        NodeIterator& operator ++(){
            if(value->parent==nullptr){
                value=nullptr;
            }
            else if(value->parent->right.get()==value){
               value=value->parent;
            }
            else{
               value=value->parent;
               if(value->right.get()!=nullptr){
                  value=value->right.get();
                  while(value->left.get()!=nullptr){
                      value=value->left.get();
                  }
               }
            }
            return *this;
        }
    };
public:
    T value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    Node * parent;
    Node (const T & value,std::unique_ptr<Node> left ,std::unique_ptr<Node> right,Node* parent):value(value), left(std::move(left)),right(std::move(right)),parent(parent){}
    Node(const Node&)=delete;
    typedef NodeIterator<Node> iterator;
    typedef NodeIterator<const Node> const_iterator;
    iterator begin(){
        Node* node =this;
        while (node->left!=nullptr) {
            node=node->left.get();
        }
        return iterator (node);
    }
    iterator end(){
        return nullptr;
    }
    const_iterator begin() const{

    }
    const_iterator end() const{
        return nullptr;
    }
};

int main(){
    string str("hello max\n");
    for(string::iterator it =str.begin();it!=str.end();it++){
        std::cout<<*it;
    }
    for(auto it =str.begin();it!=str.end();it++){
        std::cout<<*it;
    }
    for(auto&&s :str){
        std::cout<<s;
    }
    print(str);

    auto root= std::make_unique<Node<string>>("a",nullptr,nullptr,nullptr);
    root->left=std::make_unique<Node<string>>("b1",nullptr,nullptr,root.get());
    root->right=std::make_unique<Node<string>>("b1",nullptr,nullptr,root.get());
    auto b1=root->left.get();
    auto b2=root->right.get();
    b1->left=std::make_unique<Node<string>>("c1",nullptr,nullptr,b1);
    b1->right=std::make_unique<Node<string>>("c2",nullptr,nullptr,b1);
    b2->left=std::make_unique<Node<string>>("c3",nullptr,nullptr,b2);
    b2->right=std::make_unique<Node<string>>("c4",nullptr,nullptr,b2);
    auto c1=b1->left.get();
    auto c2=b1->right.get();
    auto c3=b2->left.get();
    auto c4=b2->right.get();
    std::cout<<root->value <<std::endl;
    std::cout<<b1->value <<std::endl;
    std::cout<<b2->value <<std::endl;
    std::cout<<c1->value <<std::endl;
    std::cout<<c2->value <<std::endl;
    std::cout<<c3->value <<std::endl;
    std::cout<<c4->value <<std::endl;

    return 0;
}

