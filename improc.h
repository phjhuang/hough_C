#ifndef _IMPROC_H_
#define _IMPROC_H_
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"
#include "assert.h"
typedef unsigned char uchar;
#ifndef MIN
#  define MIN(a,b)  ((a) > (b) ? (b) : (a))
#endif
#define LH_8UC1 81
#define LH_8UC2 82
#define LH_8UC3 83
#define LH_32FC1 321
#define LH_BGR2GRAY 0
#define LH_PI 3.1415926
struct LhMat
{
	int type;
	/* for internal use only */
	int* refcount;
	int hdr_refcount;
	union
	{
		uchar* ptr;
		short* s;
		int* i;
		float* fl;
		double* db;
	} data;
	int rows;
	int cols;
};

struct LhPoint2i
{
	int x;
	int y;
};

struct LhPoint2f
{
	float x;
	float y;
};

struct LhRect
{
	int x;
	int y;
	int width;
	int height;
};
typedef struct LhScalar
{
	double val[4];
}LhScalar;

struct LhLine
{
	float angle, rho;
};

LhMat* lhCreatMatHead(int rows, int cols, int type);

void lhFreeMatHead(LhMat* src);

LhMat* lhCreatMat(int rows, int cols, int type, uchar* pSrc);

void lhFreeMat(LhMat* src);

void lhZeros(LhMat* src);

void lhOnes(LhMat* src);

void lhSetValUchar(LhMat* src, int rowIndex, int colIndex, uchar val);
void lhSetValInt(LhMat* src, int rowIndex, int colIndex, uchar val);
void lhSetValFloat(LhMat* src, int rowIndex, int colIndex, uchar val);
void lhSetValDouble(LhMat* src, int rowIndex, int colIndex, uchar val);

uchar lhGetValUchar(LhMat* src, int rowIndex, int colIndex);
int lhGetValInt(LhMat* src, int rowIndex, int colIndex);
float lhGetValFloat(LhMat* src, int rowIndex, int colIndex);
double lhGetValDouble(LhMat* src, int rowIndex, int colIndex);
double lhSum(LhMat* src);
//////////////////////////////////////////////////////////////////////////
LhMat* lhCvtColor(LhMat* src, int type);
LhMat* lhCvtCimgToMat(LhMat* src);
LhMat* lhCvtMatToCimg(LhMat* src);
LhMat* lhHistNormolize(LhMat* srcM);
LhMat* lhGaussianBlur5(LhMat* src);
LhMat* lhGaussianBlur3(LhMat* src);
LhMat* lhadaptiveThreshold( LhMat* src, int _Block, int _Idelta, int _MaxValue );
void lhThreshold(LhMat* src, uchar thr);
LhPoint2f getCrossPoint(LhPoint2i p11, LhPoint2i p12, LhPoint2i p21, LhPoint2i p22);
LhMat* lhAdaptiveThreshold(LhMat* src, double maxValue, int thresholdType, int blockSize);
//////////////////////////////////////////////////////////////////////////
LhMat* xHistEqual(LhMat* src);
int houghStd(uchar* pdata, int width,int height,float rho, float theta, int threshold, LhLine *lines, int linesMax);
int lhHoughStd(LhMat* src, float rho, float theta, int threshold, LhLine *lines, int linesMax);
#endif