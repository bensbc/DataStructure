#include <iostream>  
using namespace std;

// ��������ڵ�ṹ��
typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  //��ʼ��
}ListNode;

// ����������
class LinkedList {
public:
    ListNode* head;
    // ���캯��    
    LinkedList() {
        head = new ListNode(0);   // ͷ���
    }

    // β�巨����ڵ�    
    bool insert(int val) {
        if (!head)
        {
            cout << "��������" << endl;
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

    // ͷ�巨����ڵ�    
    bool insertAtHead(int val) {
        if (!head)
        {
            cout << "��������" << endl;
            return false;
        }
        ListNode* node = new ListNode(val);
        node->next = head -> next;
        head -> next = node;
        head->val++;
        return true;

    }

    // ��ֵɾ���ڵ�    
    bool remove(int val) {
        if (head == NULL) {
            cout << "��������" << endl;
            return false;
        }
        if (head->next == nullptr)
        {
            cout << "����Ϊ��" << endl;
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

    // ��ֵ���ҽڵ�    
    ListNode* search(int val) {
        ListNode* cur = head -> next;
        while (cur != NULL && cur->val != val) {
            cur = cur->next;
        }
        return cur;
    }

    // �������    
    void print() const {
        ListNode* cur = head -> next;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // ��ָ��λ���ϲ�����
    bool insert_by_position(int value,int position)
    {
        if (!head)
        {
            cout << "��������" << endl;
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

    // ��ֵ�޸�
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

    // ��λ���޸�
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

    // ��������
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
    cout << "-----��������-----" << endl;
    LinkedList*list = new LinkedList;
    if(list)
        cout << "-----�������-----" << endl;
    else
        cout << "-----����ʧ��-----" << endl;

    cout << "\n-----����ͷ�巨-----" << endl;
    list->insertAtHead(9);
    list->insertAtHead(34);
    list->insertAtHead(134);
    cout << "������ɣ���ǰ����Ϊ��";
    list->print();
    cout << "\n-----����β�巨-----" << endl;
    list->insert(12);
    list->insert(175);
    cout << "������ɣ���ǰ����Ϊ��";
    list->print();

    cout << "\n-----������ָ��λ���ϲ���-----" << endl;
    if (list->insert_by_position(86, 1))
    {
        cout << "�ڵ�һ��λ���ϲ�����86�ɹ�����ǰ������Ϊ";
        list->print();
    }
    else
        cout << "����ʧ��" << endl;

    cout << "----����ģ��������-----" << endl;

    cout << "\n-----���԰�ֵ����ģ��-----" << endl;
    if (list->search(175))
        cout << "Ԫ��" << list->search(175)->val << "���ҳɹ�" << endl;
    else
        cout << "����ʧ��" << endl;
    cout << "-----�������-----" << endl;

    cout << "\n-----���԰�ֵɾ��ģ��-----" << endl;
    if (list->remove(86))
    {
        cout << "Ԫ��86ɾ���ɹ�����ǰ������Ϊ";
        list->print();
        cout << "��ǰ������Ϊ" << list->head->val << endl;
    }
    else
        cout << "ɾ��ʧ��" << endl;
    

    cout << "\n***********�����޸�ģ��**********" << endl;
    int value,position;
    cout << "���԰�λ���޸�" << endl;
    cout << "������λ�ã�";  cin >> position;
    cout << "�������µ�ֵ��";  cin >> value;
    if (list->modify_by_location(position, value))
        cout << "�޸ĳɹ�" << endl;
    else
        cout << "�޸�ʧ��" << endl;
    cout << "��ǰ������Ϊ��";  list->print();
    cout << "\n���԰�ֵ�޸�" << endl;
    cout << "������Ҫ�޸ĵ�ֵ��"; cin >> position;
    cout << "�������µ�ֵ��";   cin >> value;
    if (list->modify_by_value(position, value))
        cout << "�޸ĳɹ�";
    else
        cout << "�޸�ʧ��" << endl;
    cout << "��ǰ������Ϊ��";  list->print();
    cout << "**********�������***********" << endl;


    cout << "\n**************��������**********" << endl;
    list->Destroy();
    if (!list->head)
        cout << "���ٳɹ�" << endl;
    else
        cout << "����ʧ��" << endl;
    cout << "*********�������**********" << endl;
}

