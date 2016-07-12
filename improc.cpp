#include "improc.h"

LhMat* lhCreatMatHead(int rows, int cols, int type)
{
	LhMat* dst = (LhMat*)malloc(sizeof(LhMat));
	if (type == LH_8UC1)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		dst->data.ptr = NULL;
	} 
	else if (type == LH_8UC2)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		dst->data.ptr = NULL;
	}
	else if (type == LH_8UC3)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		dst->data.ptr = NULL;
	}
	else if (type == LH_32FC1)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		dst->data.fl = NULL;
	}
	return dst;
}
void lhFreeMatHead(LhMat* src)
{
	free(src);
	src = NULL;
}
LhMat* lhCreatMat(int rows, int cols, int type, uchar* pSrc)
{
	LhMat* dst = (LhMat*)malloc(sizeof(LhMat));
	if (type == LH_8UC1)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		uchar* pd = (uchar*)malloc(sizeof(uchar)*rows*cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				pd[i*cols+j] = pSrc[i*cols+j];
			}
		}
		dst->data.ptr = pd;
	} 
	else if (type == LH_8UC2)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		uchar* pd = (uchar*)malloc(sizeof(uchar)*rows*cols*2);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				pd[2*(i*cols+j)] = pSrc[2*(i*cols+j)];
				pd[2*(i*cols+j)+1] = pSrc[2*(i*cols+j)+1];
			}
		}
		dst->data.ptr = pd;
	}
	else if (type == LH_8UC3)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		uchar* pd = (uchar*)malloc(sizeof(uchar)*rows*cols*3);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				pd[3*(i*cols+j)] = pSrc[3*(i*cols+j)];
				pd[3*(i*cols+j)+1] = pSrc[3*(i*cols+j)+1];
				pd[3*(i*cols+j)+2] = pSrc[3*(i*cols+j)+2];
			}
		}
		dst->data.ptr = pd;
	}
	else if (type == LH_32FC1)
	{
		dst->rows = rows;
		dst->cols = cols;
		dst->type = type;
		float* pd = (float*)malloc(sizeof(float)*rows*cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				pd[i*cols+j] = pSrc[i*cols+j];
			}
		}
		dst->data.fl = pd;
	}
	return dst;
}
void lhFreeMat(LhMat* src)
{
	if (src->data.fl)
	{
		free(src->data.fl);
		src->data.fl = NULL;
	}

	if (src->data.ptr)
	{
		free(src->data.ptr);
		src->data.ptr = NULL;
	}
	if (src)
	{
		free(src);
		src = NULL;
	}
}

void lhZeros(LhMat* src)
{
	int rows = src->rows;
	int cols = src->cols;
	if (src->type == LH_8UC1)
	{
		int length = rows*cols;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 0;
		}
		src->data.ptr = ptr;
	} 
	else if (src->type == LH_8UC2)
	{
		int length = rows*cols*2;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 0;
		}
		src->data.ptr = ptr;
	}
	else if (src->type == LH_8UC3)
	{
		int length = rows*cols*3;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 0;
		}
		src->data.ptr = ptr;
	}
	else if (src->type == LH_32FC1)
	{
		int length = rows*cols;
		float* ptr = (float*)malloc(sizeof(float)*length);
		float* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 0;
		}
		src->data.fl = ptr;
	}
}

void lhOnes(LhMat* src)
{
	int rows = src->rows;
	int cols = src->cols;
	if (src->type == LH_8UC1)
	{
		int length = rows*cols;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 1;
		}
		src->data.ptr = ptr;
	} 
	else if (src->type == LH_8UC2)
	{
		int length = rows*cols*2;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 1;
		}
		src->data.ptr = ptr;
	}
	else if (src->type == LH_8UC3)
	{
		int length = rows*cols*3;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 1;
		}
		src->data.ptr = ptr;
	}
	else if (src->type == LH_32FC1)
	{
		int length = rows*cols;
		float* ptr = (float*)malloc(sizeof(float)*length);
		float* pt = ptr;
		for (int i = 0; i < length; i++)
		{
			*pt++ = 1;
		}
		src->data.fl = ptr;
	}
}


void lhSetValUchar(LhMat* src, int rowIndex, int colIndex, uchar val)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return ;
	}
	src->data.ptr[rowIndex*src->cols+colIndex] = val;
}
void lhSetValInt(LhMat* src, int rowIndex, int colIndex, int val)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return ;
	}
	src->data.i[rowIndex*src->cols+colIndex] = val;
}
void lhSetValFloat(LhMat* src, int rowIndex, int colIndex, float val)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return ;
	}
	src->data.fl[rowIndex*src->cols+colIndex] = val;
}
void lhSetValDouble(LhMat* src, int rowIndex, int colIndex, double val)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return ;
	}
	src->data.db[rowIndex*src->cols+colIndex] = val;
}
uchar lhGetValUchar(LhMat* src, int rowIndex, int colIndex)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return 0;
	}
	return src->data.ptr[rowIndex*src->cols+colIndex];
}
int lhGetValInt(LhMat* src, int rowIndex, int colIndex)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return 0;
	}
	return src->data.i[rowIndex*src->cols+colIndex];
}
float lhGetValFloat(LhMat* src, int rowIndex, int colIndex)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return 0;
	}
	return src->data.fl[rowIndex*src->cols+colIndex];
}
double lhGetValDouble(LhMat* src, int rowIndex, int colIndex)
{
	if (rowIndex > src->rows || colIndex > src->cols)
	{
		return 0;
	}
	return src->data.db[rowIndex*src->cols+colIndex];
}
LhScalar cvScalar( double val0, double val1,double val2, double val3 )
{
	LhScalar scalar;
	scalar.val[0] = val0; scalar.val[1] = val1; scalar.val[2] = val2; scalar.val[3] = val3;
	return scalar;
}
double lhSum(LhMat* src)
{
	int rows = src->rows;
	int cols = src->cols;
	double sumVal = 0;
	if (src->type == LH_8UC1)
	{
		int length = rows*cols;
		uchar* ptr = src->data.ptr;
		for (int i = 0; i < length; i++)
		{
			sumVal += (double)*ptr++;
		}
	} 
	else if (src->type == LH_8UC2)
	{
		int length = rows*cols*2;
		uchar* ptr = src->data.ptr;
		for (int i = 0; i < length; i++)
		{
			sumVal += (double)*ptr++;
		}
	}
	else if (src->type == LH_8UC3)
	{
		int length = rows*cols*3;
		uchar* ptr = src->data.ptr;
		for (int i = 0; i < length; i++)
		{
			sumVal += (double)*ptr++;
		}
	}
	else if (src->type == LH_32FC1)
	{
		int length = rows*cols;
		float* ptr = src->data.fl;
		for (int i = 0; i < length; i++)
		{
			sumVal += (double)*ptr++;
		}
	}
	return sumVal;
}

//////////////////////////////////////////////////////////////////////////图像处理
LhMat* lhCvtCimgToMat(LhMat* src) //rgb
{
	if (src->type != LH_8UC3)
	{
		return NULL;
	}
	LhMat* dst;
	int rows = src->rows;
	int cols = src->cols;
	dst = lhCreatMatHead(rows, cols, LH_8UC3);
	int step = rows*cols;
	int length = step*3;
	uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
	uchar* p = ptr;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			p[3*(i*cols+j)+2] = src->data.ptr[i*cols+j];
			p[3*(i*cols+j)+1] = src->data.ptr[i*cols+j+step];
			p[3*(i*cols+j)+0] = src->data.ptr[i*cols+j+2*step]; 
		}
	}
	dst->data.ptr = ptr;
	return dst;
}

LhMat* lhCvtMatToCimg(LhMat* src)
{
	if (!src->type == LH_8UC3)
	{
		return NULL;
	}
	LhMat* dst;
	int rows = src->rows;
	int cols = src->cols;
	dst = lhCreatMatHead(rows, cols, LH_8UC3);
	int step = rows*cols;
	int length = step*3;
	uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
	uchar* p = ptr;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			p[i*cols+j+2*step] = src->data.ptr[i*cols+j];
			p[i*cols+j+step] = src->data.ptr[i*cols+j+1];
			p[i*cols+j] = src->data.ptr[i*cols+j+2]; 
		}
	}
	dst->data.ptr = ptr;
	return dst;
}

LhMat* lhCvtColor(LhMat* src, int type)
{
	
	if (type == LH_BGR2GRAY)
	{
		LhMat* dst;
		int rows = src->rows;
		int cols = src->cols;
		dst = lhCreatMatHead(rows, cols, LH_8UC1);
		int length = rows*cols;
		uchar* ptr = (uchar*)malloc(sizeof(uchar)*length);
		uchar* p = ptr;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				//p[i*cols+j] = src->data.ptr[i*cols+j]*0.229 + src->data.ptr[i*cols+j+length]*0.587 + src->data.ptr[i*cols+j+2*length]*0.114; 
				p[i*cols+j] = uchar(src->data.ptr[3*(i*cols+j)]*0.114 + src->data.ptr[3*(i*cols+j)+1]*0.587 + src->data.ptr[3*(i*cols+j)+2]*0.229); //Gray = 0.29900 * R + 0.58700 * G + 0.11400 * B
			}
		}
		dst->data.ptr = ptr;
		return dst;
	}
}

//void lhHistNormolize(unsigned char **pImg, unsigned char **pNormImg,int width,int height)
LhMat* lhHistNormolize(LhMat* srcM)
{
	LhMat* dstM = lhCreatMatHead(srcM->cols, srcM->rows, LH_8UC1);
	const unsigned char* src = srcM->data.ptr;
	unsigned char* dst = (uchar*)malloc(sizeof(uchar)*srcM->rows*srcM->cols);
	int width = srcM->cols;
	int height = srcM->rows;
	int x,y;
	const int hist_sz = 256;
	int hist[hist_sz];
	memset(hist, 0, sizeof(hist));
	int size = width*height;
	//统计每个灰度值出现的次数
	for(x=0;x<size;x++){
		assert(*(src+x)<257 && *(src+x)>=0);
		hist[*(src+x)]++;
	}

	float scale = 255.f/(width*height);
	int sum = 0;
	uchar lut[hist_sz+1];


	for(x = 0; x < hist_sz; x++ )
	{
		sum += hist[x];
		//int val = round(sum*scale);
		int val =(sum*scale+0.5);
		lut[x] = val;
	}


	lut[0] = 0;
	for( y = 0; y < size; y++ )
	{
		*(dst+y) = lut[*(src+y)];
		//if(y%100==0)
		//	printf("%d\n",*(dst+y));
	}

	dstM->data.ptr = dst;
	return dstM;
}

// http://wenku.baidu.com/link?url=oe8Jc6RW8eqNEUcY8ga2erx7ySSYBTcHz5h_RqVE7RtMoaPU6j9DMqcRFW6f6Z-9yFVZ69oihtM1K5jrXfVxXC09xaSJUjkyvDOfSrtlH4G
void gaussianFilter3(uchar* data, int rows, int cols)
{
	int i, j, index, sum;
	int templates[9] = { 1, 2, 1,
	2, 4, 2,
	1, 2, 1 };
	sum = cols * rows * sizeof(uchar);
	uchar *tmpdata = (uchar*)malloc(sum);
	memcpy((char*)tmpdata,(char*)data, sum);
	for(i = 1;i < cols - 1;i++)
	{
		for(j = 1;j < rows - 1;j++)
		{
			index = sum = 0;
			for(int m = i - 1;m < i + 2;m++)
			{
				for(int n = j - 1; n < j + 2;n++)
				{
					sum +=
						tmpdata[m * rows + n] *
						templates[index++];
				}
			}
			data[i * rows + j] = sum / 16;
		}
	}
	free(tmpdata);
}

void gaussianFilter5(uchar* data, int rows, int cols)
{
	int i, j, index, sum;
	int templates[25] = { 1, 4, 7, 4, 1,
		4, 16, 26, 16, 4,
		7, 26, 41, 26, 7,
		4, 16, 26, 16, 4,
		1, 4, 7, 4, 1 };
	sum = cols * rows * sizeof(uchar);
	uchar *tmpdata = (uchar*)malloc(sum);
	memcpy((char*)tmpdata,(char*)data, sum);
	for(i = 2;i < rows - 2;i++)
	{
		for(j = 2;j < cols - 2;j++)
		{
			index = sum = 0;
			for(int m = i - 2;m < i + 3;m++)
			{
				for(int n = j - 2; n < j + 3;n++)
				{
					sum += tmpdata[m * cols + n] * templates[index++];
				}
			}
			data[i * cols + j] = sum / 273;
		}
	}
	free(tmpdata);
}

LhMat* lhGaussianBlur5(LhMat* src)
{
	LhMat* dst = lhCreatMatHead(src->rows, src->cols, src->type);
	gaussianFilter5(src->data.ptr, src->rows, src->cols);
	dst->data.ptr = src->data.ptr;
	return dst;
}

LhMat* lhGaussianBlur3(LhMat* src)
{
	LhMat* dst = lhCreatMatHead(src->rows, src->cols, src->type);
	gaussianFilter3(src->data.ptr, src->rows, src->cols);
	dst->data.ptr = src->data.ptr;
	return dst;
}

void boxFilter( unsigned char* _Gray, const int _Width, const int _Height, int _CoreSize )
{
	unsigned char* grayBorder = NULL;
	int* firstWidthBlock = NULL;
	int widthBorder = _Width + _CoreSize - 1;
	int heightBorder = _Height + _CoreSize - 1;
	int halfCore = (_CoreSize-1)>>1;
	int i = 0, j = 0, l = 0, n = 0;
	int coreCounts = 0;
	int stepWidthGray = (_Width + 3) & ~3;
	int stepWidthBorder = (widthBorder + 3) & ~3;


	firstWidthBlock = ( int *)malloc( _Width * sizeof(int) );
	memset(firstWidthBlock, 0, _Width * sizeof(int));
	grayBorder = ( unsigned char *)malloc( stepWidthBorder*heightBorder );
	memset( grayBorder, 0, stepWidthBorder*heightBorder );//全图置0

	for ( i = 0; i < _Height; i ++ )//灰度图嵌入边框图中间
		for ( j = 0; j < _Width; j ++ )
		{
			grayBorder[ ( i + halfCore )*stepWidthBorder + j + halfCore ] = _Gray[ i*stepWidthGray + j ];
		}

		for ( i = 0; i < _CoreSize; i ++ )
			for ( j = 0; j < _CoreSize; j ++ ) firstWidthBlock[0] += grayBorder[ i*stepWidthBorder + j ];

		for ( i = 1; i < _Width; i++ )
		{
			firstWidthBlock[i] += firstWidthBlock[i-1];
			for ( l = 0; l < _CoreSize; l ++ )
			{ 

				firstWidthBlock[i] += grayBorder[ l*stepWidthBorder + i+_CoreSize-1 ] 
				- grayBorder[ l*stepWidthBorder + i-1 ];
			}
		}

		for ( i = halfCore+1; i < heightBorder-halfCore; i ++ )
			for ( j = halfCore; j < widthBorder-halfCore; j ++ )//全图均值滤波
			{
				coreCounts = 0;
				for ( n = j-halfCore; n < j+halfCore; n ++ ) 
					firstWidthBlock[j-halfCore] += grayBorder[ (i+halfCore)*stepWidthBorder + n ]
				- grayBorder[ (i-halfCore)*stepWidthBorder + n ];
				coreCounts = firstWidthBlock[j-halfCore];
				_Gray[ (i-halfCore)*stepWidthGray + j-halfCore ] = ( unsigned char)(coreCounts/(_CoreSize*_CoreSize));
			}
}

unsigned char* adaptiveThreshold( const unsigned char* _Gray,
					   const int _Width, const int _Height,
					   int _Block, int _Idelta, int _MaxValue )
{
	int i = 0, j = 0;
	unsigned char _Tab[768] = {0};
	unsigned char* _GrayFilter = NULL;
	unsigned char* ptrBinary = NULL;
	int nRowBytes = (_Width + 3) & ~3;


	uchar* _Binary = ( unsigned char *)malloc( sizeof(uchar)*nRowBytes*_Height );
	memset( _Binary, 0, nRowBytes*_Height );
	ptrBinary = _Binary;
	_GrayFilter = ( unsigned char *)malloc( sizeof(uchar)*nRowBytes*_Height );
	memcpy( _GrayFilter, _Gray, nRowBytes*_Height );
	boxFilter( _GrayFilter, _Width, _Height, _Block );
	for ( i = 0; i < 768; i ++ )//防止数据溢出的三倍tab
		_Tab[i] = ( unsigned char)( i-255 > -_Idelta ? _MaxValue : 0 );

	for ( i = 0; i < _Height; i ++ )//自适应阈值二值化核心代码
		for ( j = 0; j < _Width; j ++ )
			ptrBinary[ i*nRowBytes + j] = _Tab[ _Gray[ i*nRowBytes + j] 
		- _GrayFilter[ i*nRowBytes + j]
		+ 255];
		//boxFilter( ptrBinary, _Width, _Height, _Block );
		return ptrBinary;
}

LhMat* lhadaptiveThreshold( LhMat* src, int _Block, int _Idelta, int _MaxValue )
{
	int _Width = src->cols;
	int _Height = src->rows;
	unsigned char* _Gray = src->data.ptr;
	unsigned char* _Binary = NULL; 
	_Binary = adaptiveThreshold(_Gray, src->cols, src->rows, _Block, _Idelta, _MaxValue);
	LhMat* tmp = lhCreatMat(src->rows, src->cols, src->type, _Binary);
	return tmp;
}

//////////////////////////////////////////////////////////////////////////
void hist_equal(uchar *img, uchar* dst, int _W, int _H)
{
	int localHistogram[256] = { 0 };
	int globalHist[256] = { 0 };

	int x = 0;
	int size = _W *_H;

	const uchar* ptr = img;
	const size_t step = _W;

	for (; x <= size - 4; x += 4)
	{
		int t0 = ptr[x], t1 = ptr[x + 1];
		localHistogram[t0]++; localHistogram[t1]++;
		t0 = ptr[x + 2]; t1 = ptr[x + 3];
		localHistogram[t0]++; localHistogram[t1]++;
	}

	for (; x < size; ++x)
		localHistogram[ptr[x]]++;


	for (int i = 0; i < 256; i++)
	{
		globalHist[i] += localHistogram[i];
	}


	int lut[256];

	int i = 0;
	while (!globalHist[i]) ++i;

	float scale = (256 - 1.f) / (size - globalHist[i]);
	int sum = 0;

	for (lut[i++] = 0; i < 256; ++i)
	{
		sum += globalHist[i];

		int tmp = sum * scale;
		lut[i] = tmp < 255 ? tmp : 255;
	}


	ptr = img;
	x = 0;
	for (; x <= size - 4; x += 4)
	{
		int v0 = ptr[x];
		int v1 = ptr[x + 1];
		int x0 = lut[v0];
		int x1 = lut[v1];
		dst[x] = (uchar)x0;
		dst[x + 1] = (uchar)x1;

		v0 = ptr[x + 2];
		v1 = ptr[x + 3];
		x0 = lut[v0];
		x1 = lut[v1];
		dst[x + 2] = (uchar)x0;
		dst[x + 3] = (uchar)x1;
	}

	for (; x < size; ++x)
		dst[x] = (uchar)lut[ptr[x]];

} 

void hist_equal0(uchar *img, uchar* dst, int _W, int _H)
{
	int localHistogram[256] = { 0 };
	int globalHistogram_[256] = { 0 };
	const size_t sstep = _W;
	int width = _W;
	int height = _H;
	width *= height;
	height = 1;
	for (const uchar* ptr = img; height--; ptr += sstep)
	{
		int x = 0;
		for (; x <= width - 4; x += 4)
		{
			int t0 = ptr[x], t1 = ptr[x + 1];
			localHistogram[t0]++; localHistogram[t1]++;
			t0 = ptr[x + 2]; t1 = ptr[x + 3];
			localHistogram[t0]++; localHistogram[t1]++;
		}

		for (; x < width; ++x)
			localHistogram[ptr[x]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		globalHistogram_[i] += localHistogram[i];
		//cout << i << "   " << globalHistogram_[i] << "  gl  ";
	}
	const size_t dstep = _W;
	width = _W;
	height = _H;
	int lut[256];
	auto hist = globalHistogram_;
	int i = 0;
	while (!hist[i]) ++i;
	int total = _W*_H;
	float scale = (256 - 1.f) / (total - hist[i]);
	int sum = 0;
	for (lut[i++] = 0; i < 256; ++i)
	{
		sum += hist[i];
		lut[i] = (sum * scale)<255 ? (sum * scale):255;
	}
	width *= height;
	height = 1;
	const uchar* sptr = img;
	uchar* dptr = dst;
	for (; height--; sptr += sstep, dptr += dstep)
	{
		int x = 0;
		for (; x <= width - 4; x += 4)
		{
			int v0 = sptr[x];
			int v1 = sptr[x + 1];
			int x0 = lut[v0];
			int x1 = lut[v1];
			dptr[x] = (uchar)x0;
			dptr[x + 1] = (uchar)x1;
			v0 = sptr[x + 2];
			v1 = sptr[x + 3];
			x0 = lut[v0];
			x1 = lut[v1];
			dptr[x + 2] = (uchar)x0;
			dptr[x + 3] = (uchar)x1;
		}
		for (; x < width; ++x)
			dptr[x] = (uchar)lut[sptr[x]];
	}
}

LhMat* xHistEqual(LhMat* src)
{
	int _W = src->cols, _H = src->rows;
	uchar* ps = src->data.ptr;
	uchar* pd = ( unsigned char *)malloc( sizeof(uchar)*_W*_H );
	hist_equal0(ps, pd, _W, _H);
	LhMat* tmp = lhCreatMat(_H, _W, src->type, pd);
	return tmp;
}

int houghStd(uchar* pdata, int width,int height,float rho, float theta, int threshold, LhLine *lines, int linesMax)
{
	const float PI = 3.1415926535897932384626433832795;
	const uchar* image;
	int step;
	int numangle, numrho;
	int total = 0;
	float ang;
	int r, n;
	int i, j;
	float irho = 1 / rho;
	double scale;

	image = pdata ;
	step = width;

	numangle = (PI / theta + 0.5f);
	numrho = (((width + height) * 2 + 1) / rho) + 0.5f;

	int acc_size = (numangle + 2) * (numrho + 2);
	int sort_size = numangle * numrho;
	int* _accum = (int*)malloc(acc_size* sizeof(int));
	int* _sort_buf = (int*)malloc(sort_size* sizeof(int));
	float* _tabSin = (float*)malloc(numangle* sizeof(float));
	float* _tabCos = (float*)malloc(numangle* sizeof(float));

	int *accum = _accum, *sort_buf = _sort_buf;
	float *tabSin = _tabSin, *tabCos = _tabCos;

	memset(accum, 0, sizeof(accum[0]) * (numangle + 2) * (numrho + 2));

	for (ang = 0, n = 0; n < numangle; ang += theta, n++) // 计算正弦曲线的准备工作，查表
	{
		tabSin[n] = (float)(sin(ang) * irho);
		tabCos[n] = (float)(cos(ang) * irho);
	}

	// stage 1. fill accumulator
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
		{
			if (image[i * step + j] != 0)      // 将每个非零点，转换为霍夫空间的离散正弦曲线，并统计。
				for (n = 0; n < numangle; n++)
				{
					//r = cvRound(j * tabCos[n] + i * tabSin[n]);
					r = 0.5f+(j * tabCos[n] + i * tabSin[n]);
					r += (numrho - 1) / 2;
					accum[(n + 1) * (numrho + 2) + r + 1]++;
				}
		}

		// stage 2. find local maximums  // 霍夫空间，局部最大点，采用四邻域判断，比较。（也可以使8邻域或者更大的方式）, 如果不判断局部最大值，同时选用次大值与最大值，就可能会是两个相邻的直线，但实际上是一条直线。选用最大值，也是去除离散的近似计算带来的误差，或合并近似曲线。
		for (r = 0; r < numrho; r++)
			for (n = 0; n < numangle; n++)
			{
				int base = (n + 1) * (numrho + 2) + r + 1;
				if (accum[base] > threshold &&
					accum[base] > accum[base - 1] && accum[base] >= accum[base + 1] &&
					accum[base] > accum[base - numrho - 2] && accum[base] >= accum[base + numrho + 2])
					sort_buf[total++] = base;
			}

			// stage 3. sort the detected lines by accumulator value    // 由点的个数排序，依次找出哪些最有可能是直线


			int temp;
			int idx_0,idx_1;
			for (j = 0; j < total - 1; j++)
			{
				for (i = 0; i < total - 1 - j; i++)
				{
					idx_0 = sort_buf[i];
					idx_1 = sort_buf[i+1];
					if (accum[idx_0] < accum[idx_1])
					{
						temp = sort_buf[i];
						sort_buf[i] = sort_buf[i + 1];
						sort_buf[i + 1] = temp;
					}
				}
			}


			//  icvHoughSortDescent32s(sort_buf, total, accum);

			// stage 4. store the first min(total,linesMax) lines to the output buffer
			linesMax = MIN(linesMax, total);
			scale = 1. / (numrho + 2);
			for (i = 0; i < linesMax; i++)  // 依据霍夫空间分辨率，计算直线的实际r，theta参数
			{
				LhLine line;
				int idx = sort_buf[i];
				//int n = cvFloor(idx*scale) - 1;
				int n = (int)(idx*scale) - 1;
				int r = idx - (n + 1)*(numrho + 2) - 1;
				line.rho = (r - (numrho - 1)*0.5f) * rho;
				line.angle = n * theta;

				lines[i].rho = line.rho;
				lines[i].angle = line.angle;


				//H_PRINT(sort_buf[i]);

			}
			//printf("%f\n", lines[i].angle);

			free(_accum);
			free(_sort_buf);
			free(_tabSin);
			free(_tabCos);

			return linesMax;

}

int lhHoughStd(LhMat* src, float rho, float theta, int threshold, LhLine *lines, int linesMax)
{
	uchar* p = src->data.ptr;
	int width = src->cols;
	int height = src->rows;
	return houghStd(p, width, height, rho, theta, threshold, lines, linesMax);
}
void lhThreshold(LhMat* src, uchar thr)
{
	int cols = src->cols;
	int rows = src->rows;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			src->data.ptr[i*cols+j] = src->data.ptr[i*cols+j] > thr ? 255 : 0;
		}
	}
}
LhPoint2f getCrossPoint(LhPoint2i p11, LhPoint2i p12, LhPoint2i p21, LhPoint2i p22)   //求两直线交点
{
	LhPoint2f out_inter_point;
	float x1 = p11.x;
	float x2 = p12.x;
	float y1 = p11.y;
	float y2 = p12.y;

	float x3 = p21.x;
	float x4 = p22.x;
	float y3 = p21.y;
	float y4 = p22.y;

	if(x2!=x1&&x3!=x4)
	{
		double k1 = (y2-y1)/(x2-x1);
		double k2 = (y3-y4)/(x3-x4);

		if(abs(k1-k2)<0.0001)
		{
			out_inter_point.x = 10000.0;
			out_inter_point.y = 10000.0;
		}
		else
		{
			out_inter_point.x = (k1*x1-k2*x3+y3-y1)/(k1-k2);
			out_inter_point.y = y1+(out_inter_point.x-x1)*k1;
		}
	}
	else if(x1 == x2 && x3 != x4)
	{
		out_inter_point.x  = x1;
		double k2 = (y3-y4)/(x3-x4);
		out_inter_point.y = k2*(out_inter_point.x-x3)+y3;
	}
	else if(x1!=x2&&x3==x4)
	{
		out_inter_point.x  = x3;
		double k1 = (y1-y2)/(x1-x2);
		out_inter_point.y = k1*(out_inter_point.x-x1)+y1;
	}
	else
	{
		out_inter_point.x = 100000.0;
		out_inter_point.y = 100000.0;
	}
	return out_inter_point;
}

void mean_filter(uchar* img, int _W, int _H, int masksize)
{

	int	 size = _W * _H;
	if (img == NULL || size <= 0) return;

	int  i, j, r = masksize / 2;
	int  area = masksize * masksize;
	int  half = area / 2;

	uchar *tmp = (uchar*)malloc(size*sizeof(uchar));
	uchar **p_row = (uchar**)malloc(_H*sizeof(uchar*));
	uchar **imgdata = (uchar**)malloc(_H*sizeof(uchar*));

	//initialize 
	memcpy(tmp, img, size);
	imgdata[0] = img;
	p_row[0] = tmp;

	for (i = 1; i < _H; i++)
	{
		imgdata[i] = imgdata[i - 1] + _W;
		p_row[i] = p_row[i - 1] + _W;
	}

	int dx, dy, nG;
	int EndX = _W - r, EndY = _H - r;
	for (j = r; j < EndY; j++)
	{
		for (i = r; i < EndX; i++)
		{
			for (nG = 0, dy = -r; dy <= r; dy++)
				for (dx = -r; dx <= r; dx++)
					nG += p_row[j + dy][i + dx];

			imgdata[j][i] = (nG + half) / area;
		}
	}
	uchar* tmp_ = (uchar*)malloc(_W*_H*sizeof(uchar));
	memset(tmp_, 0, _W*_H*sizeof(uchar));
	int c = masksize / 2;
	for (i = c; i < _H - 2; ++i)
	{
		memcpy(tmp_ + (_W*i + c)*sizeof(uchar), img + (_W*i + c)*sizeof(uchar), (_W - 2 * c)*sizeof(uchar));
	}
	if (tmp_)
	{
		memcpy(img, tmp_, _W*_H*sizeof(uchar));
		free(tmp_);
		tmp_ = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (p_row)
	{
		free(p_row);
		p_row = NULL;
	}
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (imgdata)
	{
		free(imgdata);
		imgdata = NULL;
	}
}


void adaptive_bin1(uchar* src,uchar* dst,int w, int h, double maxValue, int thresholdType, int blockSize)
{
	uchar* tmp = (uchar*)malloc(sizeof(uchar)*w*h);
	memcpy(tmp, src, sizeof(uchar)*w*h);
	mean_filter(tmp, w, h, blockSize);
	int i, j;
	uchar imaxval = maxValue<255 ? maxValue:255;
	uchar tab[768];
	if (thresholdType == 0)
		for (i = 0; i < 768; i++)
			tab[i] = (uchar)(i - 255 > 0 ? imaxval : 0);
	else if (thresholdType == 1)
		for (i = 0; i < 768; i++)
			tab[i] = (uchar)(i - 255 <= 0 ? imaxval : 0);
	for (j = 0; j < w*h; j++)
	{	
		dst[j] = tab[src[j] - tmp[j] + 255];
	}
	free(tmp);
}
void adaptive_bin(uchar* src, uchar* dst, int w, int h, int thresholdType, int blockSize, int idelta)
{
	uchar* tmp = (uchar*)malloc(sizeof(uchar)*w*h);
	memcpy(tmp, src, sizeof(uchar)*w*h);
	mean_filter(tmp, w, h, blockSize);
	int i, j;
	uchar imaxval = 255;   //	maxValue < 255 ? maxValue : 255;
	uchar tab[768];
	if (thresholdType == 0)
		for (i = 0; i < 768; i++)
			tab[i] = (uchar)(i - 255 > -idelta ? imaxval : 0);
	else if (thresholdType == 1)
		for (i = 0; i < 768; i++)
			tab[i] = (uchar)(i - 255 <= -idelta ? imaxval : 0);
	for (j = 0; j < w*h; j++)
	{	
		dst[j] = tab[src[j] - tmp[j] + 255];
	}
	free(tmp); 
}

LhMat* lhAdaptiveThreshold(LhMat* src, double maxValue, int thresholdType, int blockSize)
{
	uchar* ptr = src->data.ptr;
	int cols = src->cols;
	int rows = src->rows;
	uchar* pd = (uchar*)malloc(sizeof(uchar)*rows*cols);
	adaptive_bin(ptr, pd, cols, rows, thresholdType, blockSize, 7);
	//adaptive_bin1(ptr, pd, cols, rows, maxValue, thresholdType, blockSize);
	LhMat* dst = lhCreatMat(rows, cols, src->type, pd);
	return dst;
}