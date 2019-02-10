// OpenCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include<iostream>

#define INPUTWINDOW "inputwindow"

using namespace std;
using namespace cv;
using namespace cv::dnn;
String labelfile="E:/caffe-ssd/data/ILSVRC2016/labelmap_ilsvrc_det.prototxt";
String modelfile="E:/caffe-ssd/models/VGG/VGG_ILSVRC_16_layers_fc_reduced.caffemodel";
string modeltext="E:/caffe-ssd/models/bvlc_reference_rcnn_ilsvrc13/deploy.prototxt";
string text = "D:/OpenCV/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml";
CascadeClassifier face;

void MyLine(Mat im);
void MyeEllipse(Mat im);
void CallBack(int, void*);
Mat src3, src4,src, gray_src, src1, src2, outsrc;
static Mat getMean(const size_t &w, const size_t &h)
{
	

	Mat mean;
	vector <Mat> channels;
	for (size_t i = 0; i < 3; i++)
	{
		Mat channel(h,w,CV_32F,Scalar(0,0,255));
		channels.push_back(channel);
	}
	merge(channels,mean);
	return mean;
}
static Mat preprocess(const Mat &frame) {
	Mat preprocessed;
	frame.convertTo(preprocessed,CV_32F);
	resize(preprocessed,preprocessed,Size(300,300));
	Mat mean = getMean(300,300);
	subtract(preprocessed,mean,preprocessed);
	return preprocessed;
}
//OpenCV通过两个函数的组合使用来实现仿射变换
//使用warpAffine来实现简单重映射
//使用getRotationMatrix2D来获得旋转矩阵
int main(int arge, char**argv[])
{


	//HoughLinesP();
	Mat src = imread("C:\\Users\\Administrator\\Desktop\\782383359571036204.jpg");
	Mat dst_warp, dst_warpRotateScale;
	Point2f srcPoints[3];//原图中的三点  
	Point2f dstPoints[3];//目标图中的三点  

						 //第一种仿射变换的调用方式：三点法
						 //三个点对的值,上面也说了，只要知道你想要变换后图的三个点的坐标，就可以实现仿射变换  
	srcPoints[0] = Point2f(0, 0);
	srcPoints[1] = Point2f(0, src.rows - 1);
	srcPoints[2] = Point2f(src.cols - 1, 0);
	//映射后的三个坐标值
	dstPoints[0] = Point2f(0, src.rows*0.3);
	dstPoints[1] = Point2f(src.cols*0.25, src.rows*0.75);
	dstPoints[2] = Point2f(src.cols*0.75, src.rows*0.25);

	Mat M1 = getAffineTransform(srcPoints, dstPoints);//由三个点对计算变换矩阵  
	warpAffine(src, dst_warp, M1, src.size());//仿射变换  


											  //第二种仿射变换的调用方式：直接指定角度和比例                                          
											  //旋转加缩放  
	Point2f center(src.cols / 2, src.rows / 2);//旋转中心  
	double angle = 45;//逆时针旋转45度  
	double scale =1;//缩放比例  

	Mat M2 = getRotationMatrix2D(center, angle, scale);//计算旋转加缩放的变换矩阵  
	warpAffine(dst_warp, dst_warpRotateScale, M2, src.size());//仿射变换  

	imshow("原始图", src);
	imshow("仿射变换1", dst_warp);
	imshow("仿射变换2", dst_warpRotateScale);
	face.load(text);
	namedWindow("1",WINDOW_AUTOSIZE);
	VideoCapture capture(0);
	Mat frame;
	Mat gray;
	vector<Rect> facec;
	while (capture.read(frame))
	{
		//imshow("1",frame);
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		equalizeHist(gray,gray);
		face.detectMultiScale(gray,facec,1.2,3,0,Size(30,30));
		for (size_t i = 0; i < facec.size(); i++)
		{
			rectangle(frame,facec[static_cast<int>(i)],Scalar(0,0,255),2,8,0);
		}
		imshow("1",frame);
		char c = waitKey(5);
		if (c==27)
		{
			break;
		}
	}
src=imread("C:\\Users\\Administrator\\Desktop\\782383359571036204.jpg");
imshow(INPUTWINDOW,src);
vector<Rect> faces;
face.detectMultiScale(src,faces,1.2,3,0,Size(24,24));
for (size_t i = 0; i < faces.size(); i++)
{
	rectangle(src,faces[static_cast<int>(i)],Scalar(0,0,255),2,8,0);
}
imshow("out",src);


///*
//int i4;
//i4=saturate_cast<int>(55);
//
//	cvtColor(src,gray_src,COLOR_RGB2BGR);
//	namedWindow("2");
//	MyLine(gray_src);
//	MyeEllipse(gray_src);
//
//
//	blur(gray_src,src3,Size(3,3),Point(-1,-1));
//	GaussianBlur(gray_src,src4,Size(3,3),11,11);
///*	imshow("2",gray_src);
//	imshow("3",src3);
//	imshow("4",src4);*/
//	printf("OK");
//	Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,-5,-1,0,-1,0);
//	filter2D(gray_src,src4,5,kernel,Point(-1,-1));//卷积
//	namedWindow("3");
//	int cc = 3;
//	createTrackbar("Name:", "3",&cc,20,CallBack);
//
//	threshold(src, src,150,200,THRESH_BINARY);
//	imshow("sss", src);
////	Sobel
//	//addWeighted();
//	//Laplacian
//	*/
	waitKey(0);
    return 0;
}

void	 MyLine(Mat im)
{
	Point point1 = Point(20,20);
	Point point2;
	point2.x = 300;
	point2.y = 300;
	Scalar color = Scalar(0,0,255);
	line(im, point1, point2, color);
}

void MyeEllipse(Mat im)
{
	Scalar color = Scalar(0, 255, 0);
	ellipse(im,Point(im.cols/2,im.rows/2),Size(im.cols/4,im.rows/8),45,0,360,color,2,LINE_8);
}
void CallBack(int, void*)
{

	imshow("3", gray_src);
}