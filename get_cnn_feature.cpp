#include "get_cnn_feature.h"


using namespace std;
using namespace cv;


int get_cnn_feature(Mat imgSrc ,double* feature)
{
	
	Mat imgresize(60,60,CV_64FC3);

	if(imgSrc.empty()) //�ж�ͼƬ�����Ƿ�ɹ�
		return -1; //����ͼƬʧ�����˳�
	Size sz=Size(60,60);
	resize(imgSrc,imgresize,sz);

	double x[10800];

	int h=imgresize.rows;
	int w=imgresize.cols;
	int c=imgresize.channels();
	int k=0;
	double l;
	for (int ch = 0; ch < c; ch++)  
	{  
		for (int j = 0; j < w; j++)  
		{  
			for (int i = 0; i < h; i++)  
			{
				l=(double)imgresize.row(i).col(j).data[c - 1- ch];
				x[k] =l/255;  
				k++;
			}  
		}  
	}
	emxArray_real_T *fv=emxCreate_real_T(1,256);
	gen_feature(x,fv);
	
	double *y=new double[256];
	y=fv->data;

	copy(y,y+255,feature);

	delete[] y;

	return 0;
}


int main(){

	return 0;
}