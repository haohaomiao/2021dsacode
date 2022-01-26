#include <iostream>

//Ҫ���������ݾ��޸�����
typedef int datatype;

//������������
class ListNode{
public:
//���캯��
    //������Ĭ�Ϲ��캯��
    ListNode(){}
    //һ�㹹�캯��
    ListNode(datatype data_, ListNode* pred_, ListNode* succ_): data(data_), pred(pred_), succ(succ_){}
    //Ȼ���ǳ�Ա����
    ListNode* pred; ListNode* succ;
//��������
    ~ListNode(){}
//�����ӿ�
    //�������ݷ���
    datatype getdata(){return data;}
private:
//�洢���ݣ��ڱ�������ID;ǰ��������
    datatype data; 
};


//�����б���
class List{
protected:
//�����ӿ�
    //���δ����б�ʱ��ʼ��������ͷ�ڱ��ڵ㣬���ӽڵ�
    void init(){
        header = new ListNode;
        header->succ = header;
        header->pred = header;
        _size = 0;
    }
    //������нڵ�
    datatype clear(){
        datatype oldsize = _size;
        while(_size > 0){
            remove(header->succ);
        }
        return oldsize;
    }
public:
    //���캯��
    List(){init();}
    //����������δд��
    ~List(){clear(); delete header;}
    //�����½ڵ�,�����µĽڵ�
    ListNode* insertAsSucc(datatype data_, ListNode* p){
        ListNode* newNode = new ListNode(data_, p, p->succ);
        p->succ->pred = newNode;
        p->succ = newNode;
        _size++;
        return newNode;
    }
    //���ĳ���ڵ�
    datatype remove(ListNode* p){
        //��������
        if(p == header){return 0;}
        datatype temp = p->getdata();
        p->pred->succ = p->succ;
        p->succ->pred = p->pred;
        delete p;
        _size--;
    }
    //�пպ���
    bool isempty(){
        return (header->succ == header);
    }
    //��Ա����
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