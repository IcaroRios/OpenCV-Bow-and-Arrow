/*
#include "opencv2/opencv.hpp"
using namespace cv;

int main(int, char**)
{
    VideoCapture capUm(0); // open the default camera
    capUm.set(CV_CAP_PROP_FRAME_WIDTH,1024);
    capUm.set(CV_CAP_PROP_FRAME_HEIGHT,768);
    capUm.set(CV_CAP_PROP_FPS,15);

    if(!capUm.isOpened())  // check if we succeeded
        return -1;

    Mat frame;
    namedWindow("Frame",1);
    while(1){

        capUm >> frame; // get a new frame from camera
        if(frame.empty()==0) {
            imshow("Frame", frame);

            if(waitKey(30) >= 0)
                break;
        }
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}

*/
