#include <iostream>

//要用哪种数据就修改这里
typedef int datatype;

//定义链表结点类
class ListNode{
public:
//构造函数
    //首先是默认构造函数
    ListNode(){}
    //一般构造函数
    ListNode(datatype data_, ListNode* pred_, ListNode* succ_): data(data_), pred(pred_), succ(succ_){}
    //然后是成员变量
    ListNode* pred; ListNode* succ;
//析构函数
    ~ListNode(){}
//操作接口
    //返回数据方法
    datatype getdata(){return data;}
private:
//存储数据，在本题中是ID;前驱、后驱
    datatype data; 
};


//定义列表类
class List{
protected:
//操作接口
    //初次创建列表时初始化：创建头哨兵节点，链接节点
    void init(){
        header = new ListNode;
        header->succ = header;
        header->pred = header;
        _size = 0;
    }
    //清除所有节点
    datatype clear(){
        datatype oldsize = _size;
        while(_size > 0){
            remove(header->succ);
        }
        return oldsize;
    }
public:
    //构造函数
    List(){init();}
    //析构函数（未写）
    ~List(){clear(); delete header;}
    //插入新节点,返回新的节点
    ListNode* insertAsSucc(datatype data_, ListNode* p){
        ListNode* newNode = new ListNode(data_, p, p->succ);
        p->succ->pred = newNode;
        p->succ = newNode;
        _size++;
        return newNode;
    }
    //清除某个节点
    datatype remove(ListNode* p){
        //储存数据
        if(p == header){return 0;}
        datatype temp = p->getdata();
        p->pred->succ = p->succ;
        p->succ->pred = p->pred;
        delete p;
        _size--;
    }
    //判空函数
    bool isempty(){
        return (header->succ == header);
    }
    //成员变量
    ListNode* header; int _size;
};

int main(){
    int people;
    int interval;
    std::cin >> people;
    std::cin >> interval;
    List myList;
    ListNode* posptr;
    for (int i = 0; i < people; i++){
        int ID;
        std::cin >> ID;
        if(myList.isempty()){
            myList.insertAsSucc(ID, myList.header);
            posptr = myList.header->succ;
            //
            //std::cout << posptr->getdata() << std::endl;
            //
        }
        else{
            for(int j = 0; j < interval; j++){
                posptr = posptr->pred; 
                if(posptr == myList.header){posptr = posptr->pred;}               
            }
            myList.insertAsSucc(ID, posptr);
            posptr = posptr->succ;
        }
    }
    for(int i = 0; i < people; i++){
        if(posptr == myList.header){
            posptr = myList.header->succ;
        }
        std::cout << posptr->getdata() << " ";
        posptr = posptr->succ;
    }
    return 0;
}