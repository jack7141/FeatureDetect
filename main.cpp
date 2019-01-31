#include <QCoreApplication>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main(int argc, char *argv[])
{
    VideoCapture camera(0);

    if( !camera.isOpened() )
        cout << "Cannot open Camera" << endl;
    Mat frame, gray;
    vector<cv::Point2f>corner;
    while (1) {
        camera >> frame;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        goodFeaturesToTrack(gray,corner,255,0.1,5,cv::Mat(),3,false,0.04);

        for (size_t i = 0; i< corner.size(); i++) {
        circle(frame,corner[i],5,Scalar(255,255,0));
        }
        imshow("NonFilter",frame);
        char c = (char)waitKey(10);

        if( c == 27 || c == 'q' || c == 'Q' )break;
    }
}
