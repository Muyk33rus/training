#include <iostream>

using namespace std;

template<typename T>
class UnidirectionalList{
    struct node;
public:
    void Show();
    void AddBegin(T value);
    void AddEnd(T value);
    int Size();
    int Find(T value);
    void InsertByPosition(T value , int pos);
    bool DeleteByPosition(int pos);
    bool DeleteByValue(T value);
    void Delete();
    void Copy( const UnidirectionalList &list);
    void SortInsertion();
    UnidirectionalList();
    ~UnidirectionalList();
private:
    struct node{
        T value;
        node* pNode;
    };
    node * pHead;
    int size;
};

template<typename T>
void UnidirectionalList<T>::Show()
{
    node* temp=pHead;
    int pos=0;
    while(temp!=nullptr){
        cout<<"pos "<<++pos<<"= "<<temp->value<<endl;
        temp=temp->pNode;
    }
}

template<typename T>
void UnidirectionalList<T>::AddBegin(T value)
{
    node* temp=new node;
    temp->pNode=pHead;
    temp->value=value;
    pHead=temp;
    size++;
}

template<typename T>
void UnidirectionalList<T>::AddEnd(T value)
{
   node* temp=pHead;
   while(temp->pNode!=nullptr){
       temp=temp->pNode;
   }
   temp->pNode=new node;
   temp->pNode->value=value;
   temp->pNode->pNode=nullptr;
   size++;
}

template<typename T>
int UnidirectionalList<T>::Size()
{
    return size;
}

template<typename T>
int UnidirectionalList<T>::Find(T value)
{
    int count=0;
    node* temp=pHead;
    while(temp->pNode!=nullptr){
        count++;
        if(temp->value==value)
            return count;
        temp=temp->pNode;
    }
    return -1;
}

template<typename T>
void UnidirectionalList<T>::InsertByPosition(T value, int pos)
{
    int count=0;
    node* temp=pHead;
    while(temp->pNode!=nullptr){
        count++;
        if(count==pos-1){
            node* newNode=new node;
            newNode->pNode=temp->pNode;
            newNode->value=value;
            temp->pNode=newNode;
            size++;
            return;
        }
        temp=temp->pNode;
    }

}

template<typename T>
bool UnidirectionalList<T>::DeleteByPosition(int pos)
{
    int count=0;
    node* temp=pHead;
    while(temp->pNode!=nullptr){
        count++;
        if(count==pos-1){
            delete temp->pNode;
            temp->pNode=temp->pNode->pNode;
            size--;
            return true;
        }
        temp=temp->pNode;
    }
    return false;
}

template<typename T>
bool UnidirectionalList<T>::DeleteByValue(T value)
{
    node* temp=pHead;
    node* tmp=pHead;
    while(temp!=nullptr){
        if(temp->value==value){
            tmp->pNode=temp->pNode;
            size--;
            return true;
        }
        tmp=temp;
        temp=temp->pNode;
    }
    return  false;
}

template<typename T>
void UnidirectionalList<T>::Delete()
{
    while(pHead!=nullptr){
        node* temp=pHead;
        pHead=pHead->pNode;
        delete temp;
    }
}

template<typename T>
void UnidirectionalList<T>::Copy(const UnidirectionalList &list)
{
    Delete();
    pHead =new node;
    pHead->value=list.pHead->value;
    pHead->pNode=nullptr;
    node* tempList=list.pHead->pNode;
    node* temp=pHead;
    while(tempList!=nullptr){
        temp->pNode= new node;
        temp->pNode->value=tempList->value;
        temp->pNode->pNode=nullptr;
        temp=temp->pNode;
        tempList=tempList->pNode;
    }

}


template<typename T>
void UnidirectionalList<T>::SortInsertion(){
    node* tmpSortList,* temp, * sortList=pHead;
    pHead=pHead->pNode;
    sortList->pNode=nullptr;

    while(pHead != nullptr){
        temp = pHead;
        pHead = pHead->pNode;
        if(temp->value < sortList->value){
            temp->pNode = sortList;
            sortList = temp;
        }else{
            tmpSortList = sortList;
            while(tmpSortList->pNode != NULL){
                if(tmpSortList->pNode->value > temp->value)
                    break;
                tmpSortList = tmpSortList->pNode;
            }
            temp->pNode = tmpSortList->pNode;
            tmpSortList->pNode = temp;
        }
    }
    pHead = sortList;
}

template<typename T>
UnidirectionalList<T>::UnidirectionalList()
{
    pHead=nullptr;
    size=0;
}

template<typename T>
UnidirectionalList<T>::~UnidirectionalList()
{
    cout<<"~UnidirectionalList()"<<endl;
    Delete();
}


int main(int argc, char *argv[])
{
    UnidirectionalList<int> list,list2;
    list.AddBegin(10);
    list.AddBegin(11);
    list.AddBegin(32);
    list.AddEnd(45);
    list.AddEnd(6);
    list.AddEnd(10);
    list.Show();
    list2.Copy(list);
    list2.Show();
    list2.SortInsertion();
    list2.Show();
    cout << "size= "<<list.Size() << endl;
    cout << "Find(32)= "<<list.Find(32) << endl;
    cout << "Find(45)= "<<list.Find(45) << endl;
    cout << "Find(100)= "<<list.Find(100) << endl;
    list.InsertByPosition(44,4);
    list.Show();
    list.DeleteByPosition(3);
    list.Show();
    list.DeleteByValue(44);
    list.Show();
    list.Delete();
    list.AddBegin(100);
    list.Show();
    list2.Show();
    return 0;
}
