#include <direct.h> 
#include <stdio.h>


#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>


#include "FindFiles.h"
#include "DataAugment.h"

using namespace std;
using namespace cv;

// first: Resize    Second:  Flip    Third:   Rotate


/************************************************************************/
/*  Image Resize                                                        */
/************************************************************************/
//void main(){}



/************************************************************************/
/*  Image Rotate                                                        */
/************************************************************************/
void main()
{
	FindFiles ff;
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\img\\aug_data\\0.0_1_0\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\img\\aug_data\\0.0_1_1\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\img\\aug_data_scale_0.5\\0.0_1_0\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\img\\aug_data_scale_0.5\\0.0_1_1\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\img\\aug_data_scale_1.5\\0.0_1_0\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\img\\aug_data_scale_1.5\\0.0_1_1\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\SegmentationClass\\aug_gt\\0.0_1_0\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\SegmentationClass\\aug_gt\\0.0_1_1\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_0.5\\0.0_1_0\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_0.5\\0.0_1_1\\");
	//std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_1.5\\0.0_1_0\\");
	std::vector<std::string> fileNames = ff.findFiles("F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_1.5\\0.0_1_1\\");


	std::vector<std::string> r_list(2);
	/*r_list[0] = "22.5_1_0";
	r_list[1] = "337.5_1_0";*/
	r_list[0] = "22.5_1_1";
    r_list[1] = "337.5_1_1";

	//std::string savePath = "F:\\train_six_stage\\img\\aug_data\\";
	//std::string savePath = "F:\\train_six_stage\\img\\aug_data_scale_0.5\\";
	//std::string savePath = "F:\\train_six_stage\\img\\aug_data_scale_1.5\\";
	//std::string savePath = "F:\\train_six_stage\\SegmentationClass\\aug_gt\\";
	//std::string savePath = "F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_0.5\\";
	std::string savePath = "F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_1.5\\";

	/*double theta = 22.5;*/
	double theta = 22.5;
	double theta2 = 315;

	//for (int j = 0; j<15; j++)
	for (int j = 0; j<2; j++)
	{
		std::string curPath = savePath + r_list[j] + "\\";
		_mkdir(curPath.c_str());

		for (int i = 0; i<fileNames.size(); i++)
		{
			string fname;
			int iBeginIndex = fileNames[i].find_last_of("\\") + 1;
			//int iEndIndex    = fileNames[i].find_last_of(".");
			int iEndIndex = fileNames[i].length();
			fname = fileNames[i].substr(iBeginIndex, iEndIndex - iBeginIndex);
			std::cout << fname << std::endl;

			cv::Mat curImage = cv::imread(fileNames[i], IMREAD_UNCHANGED);

			DataAugment da;
			cv::Mat rMat;
			da.imageRotate(curImage, rMat, theta, AU_ANG);
			cv::imwrite(curPath + fname, rMat);
		}
		//theta += 22.5;
		theta += theta2;
	}
}


/************************************************************************/
/*  Image Flip                                                          */
/************************************************************************/
//void main()
//{
//	/*char *folder = "F:\\train_six_stage\\img\\aug_data\\0.0_1_0";
//	std::string savePath = F:\\train_six_stage\\img\\aug_data\\0.0_1_1\\";*/
//
//	/*char *folder = "F:\\train_six_stage\\img\\aug_data_scale_0.5\\0.0_1_0";
//	std::string savePath = "F:\\train_six_stage\\img\\aug_data_scale_0.5\\0.0_1_1\\";*/
//
//	/*char *folder = "F:\\train_six_stage\\img\\aug_data_scale_1.5\\0.0_1_0";
//	std::string savePath = "F:\\train_six_stage\\img\\aug_data_scale_1.5\\0.0_1_1\\";*/
//
//	char *folder = "F:\\train_six_stage\\SegmentationClass\\aug_gt\\0.0_1_0";
//	std::string savePath = "F:\\train_six_stage\\SegmentationClass\\aug_gt\\0.0_1_1\\";
//
//	/*char *folder = "F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_0.5\\0.0_1_0";
//	std::string savePath = "F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_0.5\\0.0_1_1\\";*/
//
// //char *folder         = "F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_1.5\\0.0_1_0";
// //std::string savePath = "F:\\train_six_stage\\SegmentationClass\\aug_gt_scale_1.5\\0.0_1_1\\";
//
// _mkdir(savePath.c_str());
//
//	FindFiles ff;
//	std::vector<std::string> fileNames = ff.findFiles(folder);
//
//	for ( int j=0; j<fileNames.size(); j++ )
//	{
//		string fname;
//		int iBeginIndex  = fileNames[j].find_last_of("\\")+1;
//		//int iEndIndex    = fileNames[j].find_last_of(".");
//		int iEndIndex    = fileNames[j].length();
//		fname            = fileNames[j].substr( iBeginIndex, iEndIndex-iBeginIndex );
//		std::cout << fname << std::endl;
//
//		cv::Mat curImage = cv::imread(fileNames[j], IMREAD_UNCHANGED);
//
//		DataAugment da;
//		cv::Mat iMat;
//		da.imageFlip(curImage, iMat, MIRROR_H);
//		cv::imwrite(savePath+fname, iMat);
//	}
//}
