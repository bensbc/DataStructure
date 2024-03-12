#include <iostream>  
using namespace std;

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  //初始化
}ListNode;

// 定义链表类
class LinkedList {
public:
    ListNode* head;
    // 构造函数    
    LinkedList() {
        head = new ListNode(0);   // 头结点
    }

    // 尾插法插入节点    
    bool insert(int val) {
        if (!head)
        {
            cout << "链表不存在" << endl;
            return false;
        }
        ListNode* node = new ListNode(val);
        if (head->next == NULL) {
            head->next = node;
        }
        else {
            ListNode* cur = head->next;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = node;
        }
        head->val++;
        return true;
        
    }

    // 头插法插入节点    
    bool insertAtHead(int val) {
        if (!head)
        {
            cout << "链表不存在" << endl;
            return false;
        }
        ListNode* node = new ListNode(val);
        node->next = head -> next;
        head -> next = node;
        head->val++;
        return true;

    }

    // 按值删除节点    
    bool remove(int val) {
        if (head == NULL) {
            cout << "链表不存在" << endl;
            return false;
        }
        if (head->next == nullptr)
        {
            cout << "链表为空" << endl;
            return false;
        }

        ListNode* cur = head;
        while (cur->next != NULL && cur->next->val != val) {
            cur = cur->next;
        }
        if (cur->next != NULL) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            head->val--;
            return true;
        }
        else
            return false;
        
    }

    // 按值查找节点    
    ListNode* search(int val) {
        ListNode* cur = head -> next;
        while (cur != NULL && cur->val != val) {
            cur = cur->next;
        }
        return cur;
    }

    // 输出链表    
    void print() const {
        ListNode* cur = head -> next;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // 在指定位置上插入结点
    bool insert_by_position(int value,int position)
    {
        if (!head)
        {
            cout << "链表不存在" << endl;
            return false;
        }
        int index = position - 1;
        if (index<0 || index>head->val)
            return false;
        ListNode* cur = head;
        while (cur -> next && index)
        {
            cur = cur->next;
            index--;
        }
        ListNode* tmp = new ListNode(value);
        tmp->next = cur->next;
        cur->next = tmp;
        head->val++;
        return true;

    }

    // 按值修改
    bool modify_by_value(int value, int exchanger)
    {
        ListNode* tmp = this->search(value);
        if (tmp)
        {
            tmp = this->head->next;
            for (int i = 0; i < this->head->val; i++)
            {
                if(tmp->val==value)
                    tmp->val = exchanger;
                tmp = tmp->next;
            }
            return true;
        }
        else
            return false;
    }

    // 按位置修改
    bool modify_by_location(int location, int exchanger)
    {
        if (location <= 0 || location > this->head->val)
            return false;
        ListNode* tmp = this->head;
        while (location)
        {
            tmp = tmp->next;
            location--;
        }
        tmp->val = exchanger;
        return true;
    }

    // 销毁链表
    void Destroy()
    {
        if (!this->head)
            return;
        ListNode* tmp = head;
        while (tmp)
        {
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
        this->head = nullptr;
    }

};

static void test_linked_list() {
    cout << "-----创建链表-----" << endl;
    LinkedList*list = new LinkedList;
    if(list)
        cout << "-----创建完成-----" << endl;
    else
        cout << "-----创建失败-----" << endl;

    cout << "\n-----测试头插法-----" << endl;
    list->insertAtHead(9);
    list->insertAtHead(34);
    list->insertAtHead(134);
    cout << "插入完成，当前链表为：";
    list->print();
    cout << "\n-----测试尾插法-----" << endl;
    list->insert(12);
    list->insert(175);
    cout << "插入完成，当前链表为：";
    list->print();

    cout << "\n-----测试在指定位置上插入-----" << endl;
    if (list->insert_by_position(86, 1))
    {
        cout << "在第一个位置上插入结点86成功，当前的链表为";
        list->print();
    }
    else
        cout << "插入失败" << endl;

    cout << "----插入模块测试完成-----" << endl;

    cout << "\n-----测试按值查找模块-----" << endl;
    if (list->search(175))
        cout << "元素" << list->search(175)->val << "查找成功" << endl;
    else
        cout << "查找失败" << endl;
    cout << "-----测试完毕-----" << endl;

    cout << "\n-----测试按值删除模块-----" << endl;
    if (list->remove(86))
    {
        cout << "元素86删除成功，当前的链表为";
        list->print();
        cout << "当前链表长度为" << list->head->val << endl;
    }
    else
        cout << "删除失败" << endl;
    

    cout << "\n***********测试修改模块**********" << endl;
    int value,position;
    cout << "测试按位置修改" << endl;
    cout << "请输入位置：";  cin >> position;
    cout << "请输入新的值：";  cin >> value;
    if (list->modify_by_location(position, value))
        cout << "修改成功" << endl;
    else
        cout << "修改失败" << endl;
    cout << "当前的链表为：";  list->print();
    cout << "\n测试按值修改" << endl;
    cout << "请输入要修改的值："; cin >> position;
    cout << "请输入新的值：";   cin >> value;
    if (list->modify_by_value(position, value))
        cout << "修改成功";
    else
        cout << "修改失败" << endl;
    cout << "当前的链表为：";  list->print();
    cout << "**********测试完成***********" << endl;


    cout << "\n**************测试销毁**********" << endl;
    list->Destroy();
    if (!list->head)
        cout << "销毁成功" << endl;
    else
        cout << "销毁失败" << endl;
    cout << "*********测试完成**********" << endl;
}

