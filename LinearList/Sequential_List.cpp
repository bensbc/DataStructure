#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

#define MAXSIZE 100
#define DataType int 

// 顺序表结构体
typedef struct SqList
{
	DataType Data[MAXSIZE];   // 用于存放数据的数组
	int length;               // 有效长度
}SqList;

//初始化顺序表
static SqList* InitSqList()
{
	SqList* L = (SqList*)malloc(sizeof(SqList));
	if (!L)
		return NULL;
	// 初始化有效长度
	L->length = 0;
	// 返回指向堆空间的指针
	return L;
}

//插入元素
static int Insert(SqList* L, int  pos, DataType data)
{
	int i = pos - 1, k = L->length - 1;   // 目标位置的下标  数组最后一个元素的下标

	if (L->length == MAXSIZE || pos > MAXSIZE || pos < 1)
		return 0;    //无法插入

	// 将原处于pos以及以后的元素后移一位
	// 必须从最后的元素开始移动，否则数据会丢失
	for (k = L->length - 1; k >= i; k--)
		L->Data[k + 1] = L->Data[k];

	// 插入数据
	L->Data[i] = data;
	// 更新有效长度
	L->length++;

	//插入成功
	return 1;
}

//输出顺序表中的所有元素
static void PrintSqList(SqList* L)
{
	if (L->length == 0)
	{
		printf("数组为空\n");
		return;
	}

	int i = 0;
	while (i < L->length)
	{
		cout << L->Data[i]<<" ";
		i++;
	}
	puts("");
}


//返回表长
static int getLength(SqList* L)
{
	return L->length;
}

//判断表是否为空
static int IsEmpty(SqList* L)
{
	if (!L)
	{
		printf("指针未指向堆空间\n");
		return 1;
	}

	if (L->length == 0)
		return 1;

	return 0;

}

//返回顺序表某一位置的元素
static DataType* getElem(SqList* L, int pos)
{
	if (pos<1 || pos>L->length)
	{
		printf("位置有误\n");
		
		return nullptr;
	}
	
	return &(L->Data[pos - 1]);

}

//输出关键字的位置
static int Locate(SqList* L, DataType data)
{
	int i = 0;
	// 遍历
	for (; i < L->length; i++)
		if (L->Data[i] == data)
			return i + 1;

	//未找到该元素
	return 0;

}

//删除某一位置上的元素
static int DeleteElem(SqList* L, int pos)
{
	if (pos<1 || pos>L->length)
		return 0;   //位置有误 

	int i = pos - 1;
	// 用后面的元素依次覆盖前一个元素
	// 必须从当前元素或后一个元素开始
	for (; i < L->length; i++)
		L->Data[i] = L->Data[i + 1];
	// 更新有效长度
	L->length--;

	//删除成功
	return 1;

}

//释放顺序表
static bool DestroySqList(SqList** L)
{
	if(*L != NULL)
		free(*L);

	*L = NULL;
	return true;
}

// 修改顺序表
// 指定位置修改
static bool Modify_By_Location(SqList* L,int location,DataType value)
{
	DataType* val = getElem(L, location);
	if (val)
	{
		*val = value;
		return true;
	}
	else
		return false;
}

// 指定元素修改（修改所有）
static bool Modify_By_Value(SqList* L,DataType value, DataType exchanger)
{
	if (Locate(L, value))
	{
		for (int i = 0; i < L->length; i++)
		{
			if (L->Data[i] == value)
				L->Data[i] = exchanger;
		}
		return true;
	}
	else
		return false;
}

static void test_sqlist()
{
	// 创建顺序表并初始化
	cout << "创建顺序表并进行初始化" << endl;
	SqList* L = InitSqList();
	cout << "完成" << endl;

	// 插入元素
	cout << endl << "插入元素并输出顺序表" << endl;
	Insert(L, 1, 134);
	Insert(L, 2, 34);
	Insert(L, 3, 9);
	Insert(L, 4, 12);
	Insert(L, 5, 175);
	// 输出顺序表 
	PrintSqList(L);
	//判断顺序表是否为空 
	cout << "判断顺序表是否为空: ";
	if (IsEmpty(L))
		printf("顺序表为空\n");
	else
		printf("顺序表不为空\n");
	// 输出顺序表的长度
	printf("当前顺序表的长度为：");
	printf("%d\n", getLength(L));

	// 输出位置为3的元素
	cout << "----测试按位置寻找元素----" << endl;
	if (getElem(L, 3))
		printf("位置为3的元素为：%d\n", *getElem(L, 3));
	else
		cout << "无法获取" << endl;
	cout << "----测试完毕----" << endl;


	// 输出175的位置
	cout << endl << "----测试寻找指定元素的位置----" << endl;
	if(Locate(L,175))
		printf("元素175的位置:%d\n", Locate(L, 175));
	cout << "----测试完毕----" << endl;


	// 在第一个位置上插入元素86
	cout << endl << "----测试插入元素----" << endl;
	if (Insert(L, 1, 86))
	{
		printf("在第一个位置上插入元素86成功，当前的顺序表为");
		PrintSqList(L);
	}
	else
		printf("插入不成功\n");
	cout << "----测试完毕----" << endl;



	// 删除第三个元素
	cout << endl << "-----测试删除元素-----" << endl;
	if (!DeleteElem(L, 3))
		printf("第三个位置上的元素删除失败\n");
	else
	{
		printf("第三个元素删除成功，当前顺序表为");
		PrintSqList(L);
	}
	cout << "----测试完毕----" << endl;



	cout << "\n**************测试修改元素***************" << endl;
	cout << "测试按位置修改" << endl;
	cout << "请输入要修改的值的位置：";
	int location; cin >> location;
	cout << "请输入新的值：";
	int value; cin >> value;
	if (Modify_By_Location(L, location, value))
		cout << "修改成功" << endl;
	else
		cout << "修改失败" << endl;
	cout << "当前的顺序表为：";
	PrintSqList(L);


	cout << "测试按值修改" << endl;
	cout << "请输入要修改的值：";
	cin >> location;
	cout << "请输入新的值：";
	cin >> value;
	if (Modify_By_Value(L, location, value))
		cout << "修改成功" << endl;
	else
		cout << "修改失败" << endl;

	cout << "当前的顺序表为：";
	PrintSqList(L);

	cout << "************测试完毕*************" << endl;



	//释放顺序表
	cout << "-----测试释放顺序表-----" << endl;
	DestroySqList(&L);
	if (IsEmpty(L))
		printf("顺序表已清空，空间释放成功\n");
	else
		printf("释放失败！\n");
	cout << "----测试完毕----" << endl;
}

