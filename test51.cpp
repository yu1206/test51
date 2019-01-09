#include <iostream>
#include <vector>
#include<stdlib.h>
#include <time.h> 
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "fstream"
#include <direct.h>
#include <io.h>
#include <Windows.h>
#include <direct.h> 
using namespace std;
using namespace cv;

extern int readDir(char *dirName, vector<string> &filesName);


int test51(int argc, char *argv[])
{



	srand((unsigned)time(NULL));

	string imgpath1 = "E:/清晰车牌-wm/val-遮挡制作";
	string savepath = "E:/清晰车牌-wm/val-遮挡";

	int nmask = 1;//一个原图像，一个mask图像，对mask在原图像的位置随机几次
	vector<string> v1_img_;
	readDir((char*)imgpath1.c_str(), v1_img_);

	for (int i = 0; i < v1_img_.size(); i++)
	{
		string imagename = v1_img_[i];

		//string imagename = "E:/yu1-plate-data/4_正常车牌-制作污损/1-苏E8C93Q.jpg";

		int npos = imagename.find_last_of('/');
		int npos2 = imagename.find_last_of('.');

		string name1 = imagename.substr(npos + 1, npos2 - npos - 1);
		Mat src1 = imread(imagename.c_str());

		cout << imagename.c_str() << endl;

		if (src1.data == NULL)
		{
			printf("img.data = NULL！\n");
			system("pause");
			continue;
		}


		

		int num = 0;


		for (int k = 0; k < nmask; k++)
		{


			

			num++;

			
			int  imgH = src1.rows; int imgW = src1.cols;
			int roix = 0; int roiy = 0; int roiw = 0; int roih = 0;

			int stdw = imgW*1.0 *5/ 7;
			
			roiw = rand() % stdw +  imgW*1.0  / 7;
			roix = rand() % (imgW - roiw);

			int stdh = imgH*1.0 / 2;
			roih = rand() % (imgH - stdh-1) + stdh;
			roiy = rand() % (imgH - roih-1);

			printf("x=%d,y=%d,w=%d,h=%d\n", roix, roiy, roiw, roih);

			Mat res = src1.clone();
			
			Mat roi=res(Rect(roix,roiy,roiw,roih));
			roi.setTo(cv::Scalar(0, 0, 0));

			//imshow("4_1", res);

			//waitKey(0);

			char file[1024];

			sprintf(file, "%s/%s-%d.jpg", savepath.c_str(), name1.c_str(),  num);
			imwrite(file, res);

			int jjjj = 0;

		}


	}
	return 0;
}









