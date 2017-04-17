#include <opencv2/opencv.hpp>

#include <iostream>
#include <cstdlib>

using namespace cv;
using std::cout;
using std::endl;

int main(int argc, char **argv){
    char mainWin[] = "Захват видео потока ";
    char thresholdWin[] = "Применение порога";
    int min = 0, max = 1000;
    int hueMin = 0, saturationMin = 0, valueMin = 0,
        hueMax = 255, saturationMax = 255, valueMax = 255;
    Mat frame, HSV, threshold, blurred;
    VideoCapture cap;

    //Создаем окна
    namedWindow(mainWin, 0);
    namedWindow("win1", 0);
    namedWindow(thresholdWin, 0);

    //Создаем трэкбар
    createTrackbar("Hue min:", "win1", &hueMin, hueMax);
    createTrackbar("Hue max:", "win1", &hueMax, hueMax);
    createTrackbar("Saturation min:", "win1", &saturationMin, saturationMax);
    createTrackbar("Saturation max:", "win1", &saturationMax, saturationMax);
    createTrackbar("Value min:", "win1", &valueMin, valueMax);
    createTrackbar("Value max:", "win1", &valueMax, valueMax);
    createTrackbar("Size min:", "win1", &min, max);
    createTrackbar("Size max:", "win1", &max, max);

    //Открываем камеру
    cap.open(0);
    if(!cap.isOpened()){
        cout << "Камера не может быть открыта." << endl;
        exit(1);
    }

    //Запускаем цикл чтения с камеры
    for(;;){
        cap >> frame;
        cvtColor(frame, HSV, COLOR_BGR2HSV);
        medianBlur(HSV, blurred, 21);
        inRange(blurred, Scalar(hueMin, saturationMin, valueMin), Scalar(hueMax, saturationMax, valueMax), threshold);
        for(int y = 0; y < threshold.rows; y++){
            for(int x = 0; x < threshold.cols; x++){
                int value = threshold.at<uchar>(y, x);
                if(value == 255){
                    Rect rect;
                    int count = floodFill(threshold, Point(x, y), Scalar(200), &rect);
                    if(rect.width >= min && rect.width <= max
                        && rect.height >= min && rect.height <= max){
                        rectangle(frame, rect, Scalar(0, 0, 0));

                    }
                }
            }
        }
        imshow(mainWin, frame);
        imshow(thresholdWin, threshold);
        if(waitKey(33) == 27) break;
    }
    return 0;
}
