#ifndef re(i,n)
#define re(i,n) for(int i=0;i<n;i++)
#endif // !re(i,n)
template<class DataType>
class SeqList
{
	int length;											//顺序表长度。同时代表顺序表是否为空
	DataType *data;								//下标从 0 到 length-1
public:
	SeqList(){ length = 0; data = NULL; }	//构造空白顺序表
	SeqList(DataType a[], int n);				//通过数组来构造顺序表
	~SeqList();											
	int Length(){ return length; }				//返回数组长度
	DataType Get(int i);							//得到第i个数据
	int find(DataType x);							//查找值为x 的节点 返回序号。失败则返回-1
	void Insert(int i, DataType x);				//在data[i]插入节点
	DataType Delete(int i);						//删除节点
	void PrintList();									//输出顺序表
	friend std::ostream& operator<<(std::ostream& out, const SeqList<T>& other)
	{
		re(i, other.length)
			out << other.data[i] << ' ';
	}
	void invert()
	{

	}
};

template<class DataType>  SeqList<DataType>::
SeqList(DataType a[], int n)
{
	data = new DataType[n];								//申请空间
	memcpy(data, a, n*sizeof(DataType));			//内存拷贝
	length = n;													//刷新length
}

template<class DataType>
SeqList<DataType>::~SeqList()
{
	if (length)
		delete[] data;
}

template<class DataType> DataType SeqList<DataType>::
Get(int i)
{
	if (i<0 || i>=length) throw "查找位置非法";
	return data[i];
}

template<class DataType> int SeqList<DataType>::
find(DataType x)
{
	re(i, length)							//枚举查找数据
		if (data[i] == x)
			return i;
	return -1;								//查找失败 返回-1.
}

template<class DataType>	void SeqList<DataType>::
Insert(int i, DataType x)
{
	if (i < 0 || i>length + 1)				
		throw "插入位置出错";
	DataType *tempdata = new DataType[length + 1];	//申请新的空间
	memcpy(tempdata, data, i * sizeof(DataType));			//拷贝前i份数据
	tempdata[i] = x;														//插入
	memcpy(&tempdata[i+1], &data[i], (length - i) * sizeof(DataType));	//继续拷贝后面的数据
	delete[] data;															//释放原来空间
	data = tempdata;														//替换
	length++;																	//刷新length
}

template<class DataType>DataType SeqList<DataType>::
Delete(int i)
{
	if (length == 0)							throw "表为空";
	if (i < 0 || i>length + 1)				throw "删除位置出错";
	DataType *tempdata = new DataType[length - 1];
	memcpy(tempdata, data, i  * sizeof(DataType));
	memcpy(&tempdata[i], &data[i + 1], (length - i) * sizeof(DataType));
	DataType tempX = data[i];
	delete[] data;
	data = tempdata;
	length--;
	return tempX;
}

template<class DataType> void SeqList<DataType>::
PrintList()
{
	cout << length << endl;
	re(i, length)cout << data[i]<<' ';
	cout << endl;
}
