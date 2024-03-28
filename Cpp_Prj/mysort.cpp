#include"mysort.h"

// ֱ�Ӳ�������
void InsertSort(int arr[], int length)
{
	int i = 0, j = 0, temp = 0;
	for (i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

// �۰��������
void BinaryInsertSort(int arr[], int length)
{
	int i, j, temp, low, mid, high = 0;
	for (i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			low = 0;
			high = i - 1;
			while (low <= high)//��Ҫ�ӵ��ں�
			{
				mid = (low + high) / 2;
				if (arr[mid] > temp)
				{
					high = mid - 1;
				}
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= low; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[low] = temp;
		}
	}
}

// ϣ������
void ShellsSort(int arr[], int length)
{
	int i = 0, j = 0, temp = 0, d = length / 2;
	for (; d > 0; d = d / 2)
	{
		for (i = d; i < length; i++)
		{
			if (arr[i] < arr[i - d])
			{
				temp = arr[i];
				for (j = i - d; j >= 0 && arr[j] > temp; j = j - d)
				{
					arr[j + d] = arr[j];
				}
				arr[j + d] = temp;
			}
		}
	}
}


// ��������������ֵ
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// ð������
void BubbleSort(int arr[], int length)
{
	bool flag = false;//�Ƿ��������ı�־
	for (int i = 0; i < length; i++)
	{
		flag = false;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
}

// ��������
// ���֣����Ȼ�׼С��ֵ���ڻ�׼������ߣ��Ȼ�׼��������ڻ�׼�����ұߣ������ػ�׼�����±�
int partition(int arr[], int low, int high)//�˴���low��highΪ�±�
{
	int pivot = arr[high];//���û�׼
	int i = low - 1;//i�ᡰ���١��ϴ���
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			Swap(arr[i], arr[j]);//����
		}
	}
	//�˳�ѭ����iָ���λ��Ϊ���ڻ�׼���ĵ�һ��λ�ã�ֱ�����׼��������
	Swap(arr[i + 1], arr[high]);//������ŵ�Ӧ�е�λ��
	return i + 1;//���ػ�׼�±�
}

void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//����ǰ��������л���
		int mid = partition(arr, low, high);

		//�������࣬�ݹ�ش���������������
		QuickSort(arr, low, mid - 1);
		QuickSort(arr, mid + 1, high);
	}
}



//��ѡ������
void SelectSort(int arr[], int length)
{
	int min = 0;
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		if (min != i)
			Swap(arr[min], arr[i]);

	}
}

// ������
// ��������ָ����ָ��ı�����ֵ
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ������
void heapify(int arr[], int n, int i)
{
	int largest = i;		//�ٶ����ڵ�Ϊ���ֵ
	int left = 2 * i + 1;   //���ӵ��±�
	int right = 2 * i + 2;  //�Һ��ӵ��±�

	// �ҳ����Һ����Լ����ڵ��е������
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);  //�����Һ��ӵĽϴ��߽���
		heapify(arr, n, largest);      //���϶��µݹ�ؽ��ж�����
	}
}

//������
void heapSort(int arr[], int n)
{
	// �����һ�����ڵ㿪ʼ������ʼ�ѣ����¶���
	// ע��ֻ�����¶��Ͻ��ѣ��������ܱ�֤�Ѷ�Ϊ���ֵ
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);  // �Ѷ�Ԫ����δ����Ԫ���е����һ��Ԫ�ؽ���
		heapify(arr, i, 0);      // ������
	}
}



// �鲢����
void merge(vector<int>& nums, int left, int mid, int right)
{
	vector<int> temp(right - left + 1);   // Ԥ��ȷ����С
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (nums[i] < nums[j])
		{
			temp[k++] = nums[i++];
		}
		else
		{
			temp[k++] = nums[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = nums[i++];
	}
	while (j <= right)
	{
		temp[k++] = nums[j++];
	}
	for (int p = 0; p < temp.size(); p++)
	{
		nums[left + p] = temp[p];    // �޸�left�ұߵĲ���
	}
}

void mergeSort(vector<int>& nums, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	mergeSort(nums, left, mid);
	mergeSort(nums, mid + 1, right);
	merge(nums, left, mid, right);
}


// ��������
// ʵ��10���ڵ���������
const int MAXN = 100005;
int buf[MAXN], cnt[10] = { 0 };
void radix_sort(int* a, int n) {
	int max_val = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max_val) max_val = a[i];
	}
	for (int i = 0; i < 10; i++) {
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int idx = a[i] % 10;
		cnt[idx]++;
	}
	for (int i = 1; i < 10; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		int idx = a[i] % 10;
		buf[--cnt[idx]] = a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = buf[i];
	}
}


// �ϲ�������������
ListNode* merge(ListNode* l1, ListNode* l2) {
	if (!l1) {
		return l2;
	}
	else if (!l2) {
		return l1;
	}
	else if (l1->val < l2->val) {
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else {
		l2->next = merge(l1, l2->next);
		return l2;
	}
}

// �鲢��������
ListNode* sortList(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* l2 = slow->next;
	slow->next = nullptr;
	return merge(sortList(head), sortList(l2));
}

