// improc_c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CImg.h"
#include "improc.h"
using namespace cimg_library;
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/ocl/ocl.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;
using namespace std;


#define CV_VERSION_ID       CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)

#ifdef _DEBUG
#define cvLIB(name) "opencv_" name CV_VERSION_ID "d"
#else
#define cvLIB(name) "opencv_" name CV_VERSION_ID
#endif

#pragma comment( lib, cvLIB("core") )
#pragma comment( lib, cvLIB("imgproc") )
#pragma comment( lib, cvLIB("highgui") )
#pragma comment( lib, cvLIB("flann") )
#pragma comment( lib, cvLIB("features2d") )
#pragma comment( lib, cvLIB("calib3d") )
#pragma comment( lib, cvLIB("gpu") )
#pragma comment( lib, cvLIB("legacy") )
#pragma comment( lib, cvLIB("ml") )
#pragma comment( lib, cvLIB("objdetect") )
#pragma comment( lib, cvLIB("ts") )
#pragma comment( lib, cvLIB("video") )
#pragma comment( lib, cvLIB("contrib") )
#pragma comment( lib, cvLIB("nonfree") )
#pragma comment( lib, "user32.lib")
int _tmain(int argc, _TCHAR* argv[])
{
	VideoCapture cvcap("1 (5).avi");
	Mat cvframe;
	Mat cvgray;
	Mat cvbw;
	LhPoint2i move[3];
	int i = 0;
	int thrDistance = 10;
	for (;;)
	{
		cvcap>>cvframe;
		if (!cvframe.data)
		{
			break;
		}
		LhMat* gray;
		int rows = cvframe.rows;
		int cols = cvframe.cols;
		if (cvframe.channels() == 3)
		{
			LhMat* rgb = lhCreatMat(cvframe.rows, cvframe.cols, LH_8UC3, cvframe.data);
			gray = lhCvtColor(rgb, LH_BGR2GRAY);
		}
		else
		{
			gray = lhCreatMat(cvframe.rows, cvframe.cols, LH_8UC1, cvframe.data);
		}
		LhMat* xhisteqMat;
		xhisteqMat = xHistEqual(gray);
		LhMat* gaussMat;
		gaussMat = lhGaussianBlur5(xhisteqMat);
		LhMat* adapt = lhAdaptiveThreshold(gaussMat, 255, 1, 7);
		Mat my2(gray->rows, gray->cols, CV_8UC1, adapt->data.ptr);
		imshow("my2", my2);
		Mat bestLine = Mat::zeros(cvframe.size(), CV_8UC1);
#pragma region
		LhLine* lines = (LhLine*)malloc(sizeof(LhLine)*100);
		int lineCount;
		lineCount = lhHoughStd(adapt, 1, LH_PI/180, 70, lines, 100);
		float th1 = -1, th2 = -1;
		float rho1 = 0, rho2 = 0;
		LhPoint2i p11, p12;
		LhPoint2i p21, p22;
		bool isFirst = true;
		for (size_t i=0; i< 100; i++) {
			float rho = lines[i].rho; 
			float theta = lines[i].angle;
			Point pt1,pt2;
			double a=cos(theta);
			double b=sin(theta);
			double x0 = rho*a;
			double y0 = rho*b;
			pt1.x = cvRound(x0+1000*(-b));
			pt1.y = cvRound(y0+1000*a);
			pt2.x = cvRound(x0-1000*(-b));
			pt2.y = cvRound(y0-1000*a);
			//line(draw, pt1, pt2, Scalar(255), 1, CV_AA);

			if (isFirst == true)
			{
				rho1 = rho;
				th1 = theta;
				p11.x = pt1.x;
				p11.y = pt1.y;
				p12.x = pt2.x;
				p12.y = pt2.y;
				isFirst = false;
			}
			else
			{
				if (abs(abs(th1-1.57) - abs(theta-1.57)) < 1)
				{
					continue;
				}
				rho2 = rho;
				th2 = theta;
				p21.x = pt1.x;
				p21.y = pt1.y;
				p22.x = pt2.x;
				p22.y = pt2.y;
				break;
			}
		} 
		//cout<<th1<<"  "<<th2<<endl;
		//waitKey();
		if ((th1> -1.1&&th1<-0.9) || (th2 >-1.1&&th2<-0.9))
		{
			cout<<"no detection 2 lines\n";
			continue;
		}

		line(bestLine, Point(p11.x, p11.y), Point(p12.x, p12.y), Scalar(255), 1, CV_AA); 
		line(bestLine, Point(p21.x, p21.y), Point(p22.x, p22.y), Scalar(125), 1, CV_AA); 

		LhPoint2f ctr;
		ctr = getCrossPoint(p11, p12, p21, p22);
		if (ctr.x > 1000 || ctr.y > 1000)
		{
			continue;
		}

		if ( i == 0 )
		{
			move[0].x = ctr.x;
			move[0].y = ctr.y;
		}
		else if (i == 1)
		{
			move[1].x = ctr.x;
			move[1].y = ctr.y;
		}
		else if ( i == 2)
		{
			move[2].x = ctr.x;
			move[2].y = ctr.y;
		}
		else
		{
			move[0].x = move[1].x;
			move[0].y = move[1].y;
			move[1].x = move[2].x;
			move[1].y = move[2].y;
			move[2].x = ctr.x;
			move[2].y = ctr.y;
			if ( abs(move[2].x - move[1].x) + abs(move[2].y - move[1].y) < thrDistance && abs(move[2].x - move[0].x) + abs(move[2].y - move[0].y) < thrDistance)
			{
				//cout<<ctr.x<<"  "<<ctr.y<<endl;
				cout<<move[2].x-move[1].x<<"  "<<move[2].y - move[1].y<<endl;
				circle(bestLine, Point(ctr.x, ctr.y), 3, Scalar(255));
			}
		}
		imshow("bestLine", bestLine);
#pragma endregion

		//Mat test(rows, cols, CV_8UC1, gaussMat->data.ptr);
		//imshow("test", test);
		i++;
		waitKey(33);
	}



	

 	return 0;
}

