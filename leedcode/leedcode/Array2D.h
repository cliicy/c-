#ifndef Array2D_HH
#define Array2D_HH

template<class T>
class Array2D {
	public :
	Array2D(int r = 0, int c = 0);
	Array2D(const Array2D<T>& m); //复制构造函数
	~Array2D() { delete[] row; }
	int Rows() const { return rows; }
	int Columns() const { return cols; }

	Array1D<T>& operator[](int i) const;
	Array2D<T>& operator=(const Array2D<T>& m);
	Array2D<T> operator+() const; //一元加法操作符
	Array2D<T> operator+(const Array2D<T>& m) const;
	Array2D<T> operator-() const; // 一元减法操作符
	Array2D<T> operator-(const Array2D<T>& m) const;
	Array2D<T> operator*(const Array2D<T>& m) const;
	Array2D<T>& operator+=(const T& x);
	private :
	int rows, cols; // 数组维数
	Array1D<T> *row; // 一维数组的数组
};

template<class T>
Array2D<T>::Array2D(int r, int c)
{// 二维数组的构造函数
	//合法的r和c
	if (r < 0 || c < 0) throw;// BadInitializers();
	if ((!r || !c) && (r || c))
		throw;// BadInitializers();
	rows = r;
	cols = c;
	// 分配r个具有缺省大小的一维数组
	row = new Array1D<T>[r];
	// 调整每个元素的大小
	for (int i = 0; i < r; i++)
		row[i].ReSize(c);
}



template<class T>
Array2D<T>::Array2D(const Array2D<T>& m)
{//二维数组的复制构造函数
	rows = m.rows;
	cols = m.cols;
	// 分配指向一维数组的数组
	row = new Array1D<T>[rows];
	// 复制每一行
	for (int i = 0; i < rows; i++)
		row[i] = m.row[i];
}


template<class T>
Array1D<T>& Array2D<T>::operator[](int i) const
{
	// 二维数组的第一个索引
	if (i < 0 || i >= rows) throw;// OutOfBounds();
	return row[i];
}

template<class T>
Array2D<T> Array2D<T>:: operator-(const Array2D<T>& m) const
{// 返回 w = (*this) - m.
	if (rows != m.rows || cols != m.cols)
		throw;// SizeMismatch();
	// ´´创建存放结果的数组w
	Array2D<T> w(rows, cols);
	for (int i = 0; i < rows; i++)
		w.row[i] = row[i] - m.row[i];
	return w;
}

template<class T>
Array2D<T> Array2D<T>:: operator*(const Array2D<T>& m) const
{// 矩阵乘，返回w = (*this) * m.
	if (cols != m.rows) throw;// SizeMismatch();
	// 创建存放结果的数组w
	Array2D<T> w(rows, m.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < m.cols; j++) {
		T sum = (*this)[i][0] * m[0][j];
		for (int k = 1; k < cols; k++)
			sum += (*this)[i][k] * m[k][j];
		w[i][j] = sum;
		}
	return w;
}


#endif