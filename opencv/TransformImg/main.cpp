#include <opencv2/highgui.hpp>
#include <opencv/cv.h>

void TransformImg( IplImage* image ) {
    cvNamedWindow( "Transform-in" ); // Окно для отображения исходного изображения
    cvNamedWindow( "Transform-out" ); // Окно для преобразованного изображения
    cvShowImage( "Transform-in", image );

    // Создание контейнера для преобразованного изображения

    IplImage* out = cvCreateImage(cvGetSize( image ),IPL_DEPTH_8U,3);

    // Сглаживание

    cvSmooth( image, out, CV_GAUSSIAN, 15,15 );
    // Отображение результата преобразования

    cvShowImage( "Transform-out", out );
    // Высвобождение выделяемой памяти

    cvReleaseImage( &out );
    // Ожидание нажатия клавиши для завершения программы

    cvWaitKey( 0 );
    cvDestroyWindow( "Transform-out" );
    cvDestroyWindow( "Transform-in" );

    }

    IplImage* doPyrDown( IplImage* in, int filter = IPL_GAUSSIAN_5x5 ) {
    // Проверка деления исходного изображения на 2

    cvNamedWindow( "doPyrDown" );
    //assert( 0 == in->width%2 && 0 == in->height%2 );
    // Создание контейнера с размером вдвое меньшим, чем исходное изображение.
    // В остальном параметры те же

    IplImage* out = cvCreateImage(cvSize( in->width/2, in->height/2 ),in->depth,in->nChannels);

    // Сжатие исходного изображения

    cvPyrDown( in, out );
    cvShowImage( "doPyrDown", out );
    cvReleaseImage( &out );
    return( out );
}



IplImage* doCanny(
IplImage* in // Одноканальное изображение
,double lowThresh // Нижний порог
,double highThresh // Верхний порог
,double aperture // Размер оператора Собеля
) {

    // Canny работает только с одноканальными изображениями

    cvNamedWindow("cvCanny");
    if( 1 != in->nChannels ) {
        return(0);
    }

    // Создание контейнера под конечное изображение

    IplImage* out = cvCreateImage(cvGetSize( in ) ,IPL_DEPTH_8U ,1);

    // Преобразования

    cvCanny( in, out, lowThresh, highThresh, aperture );
    cvShowImage( "cvCanny", out );
    return( out );
}

int main( int argc, char** argv ) {
    IplImage* img = cvLoadImage( argv[1] ); // Получение имени изображения
//    doPyrDown(img,IPL_GAUSSIAN_5x5);
    doCanny(img,10,100,3);
    TransformImg( img ); // Преобразование исходного изображения
    cvReleaseImage( &img ); // Освобождение памяти из под изображения
}
