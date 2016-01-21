#ifndef re(i,n)
#define re(i,n) for(int i=0;i<n;i++)
#endif // !re(i,n)
template<class DataType>
class SeqList
{
	int length;											//˳����ȡ�ͬʱ����˳����Ƿ�Ϊ��
	DataType *data;								//�±�� 0 �� length-1
public:
	SeqList(){ length = 0; data = NULL; }	//����հ�˳���
	SeqList(DataType a[], int n);				//ͨ������������˳���
	~SeqList();											
	int Length(){ return length; }				//�������鳤��
	DataType Get(int i);							//�õ���i������
	int find(DataType x);							//����ֵΪx �Ľڵ� ������š�ʧ���򷵻�-1
	void Insert(int i, DataType x);				//��data[i]����ڵ�
	DataType Delete(int i);						//ɾ���ڵ�
	void PrintList();									//���˳���
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
	data = new DataType[n];								//����ռ�
	memcpy(data, a, n*sizeof(DataType));			//�ڴ濽��
	length = n;													//ˢ��length
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
	if (i<0 || i>=length) throw "����λ�÷Ƿ�";
	return data[i];
}

template<class DataType> int SeqList<DataType>::
find(DataType x)
{
	re(i, length)							//ö�ٲ�������
		if (data[i] == x)
			return i;
	return -1;								//����ʧ�� ����-1.
}

template<class DataType>	void SeqList<DataType>::
Insert(int i, DataType x)
{
	if (i < 0 || i>length + 1)				
		throw "����λ�ó���";
	DataType *tempdata = new DataType[length + 1];	//�����µĿռ�
	memcpy(tempdata, data, i * sizeof(DataType));			//����ǰi������
	tempdata[i] = x;														//����
	memcpy(&tempdata[i+1], &data[i], (length - i) * sizeof(DataType));	//�����������������
	delete[] data;															//�ͷ�ԭ���ռ�
	data = tempdata;														//�滻
	length++;																	//ˢ��length
}

template<class DataType>DataType SeqList<DataType>::
Delete(int i)
{
	if (length == 0)							throw "��Ϊ��";
	if (i < 0 || i>length + 1)				throw "ɾ��λ�ó���";
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
