#include <iostream>
#include <cmath>


using namespace std;

double function1(double x){
    return (1+x+sin(2*x));
}
//функция аппроксимации области под кривой(function) используется несколько прямоугольников одинаковой ширины
double UseRectangleRule(double (*fun)(double),double xmin,double xmax ,int num_intervals){
    // Вычисляем ширину прямоугольника
    double dx=(xmax-xmin)/num_intervals;
    // Добавляем области прямоугольников
    double total_area=0;
    double x=xmin;
    for(int i=1;i<=num_intervals;i++){
        total_area+=dx*fun(x);
        x=x+dx;
    }
    return total_area;
}

//функция аппроксимации области под кривой(function) используется несколько трапециями одинаковой ширины
double UseTrapezoidRule(double (*fun)(double),double xmin,double xmax ,int num_intervals){
    // Вычисляем ширину прямоугольника
    double dx=(xmax-xmin)/num_intervals;
    // Добавляем области прямоугольников
    double total_area=0;
    double x=xmin;
    for(int i=1;i<=num_intervals;i++){
        total_area+=dx*(fun(x)+fun(x+dx))/2;
        x=x+dx;
    }
    return total_area;
}

//лямда функция которая возвращае площадь данной области
double SliceArea(double (*fun)(double),double x1,double x2,double max_slice_error ){
    // Вычисляем значение функции на конечных и центральной точках
    double y1=fun(x1);
    double y2=fun(x2);
    double xm =(x1+x2)/2;
    double ym =fun(xm);
    // Вычисляем площадь большой трапеции и двух меньших трапеций.
    double area12=(x2-x1)*(y1+y2)/2.0;
    double area1m=(xm-x1)*(y1+ym)/2.0;
    double aream2=(x2-xm)*(ym+y2)/2.0;
    double area1m2=area1m+aream2;
    // Оцениваем, насколько мы близко
    double error =(area1m2-area12)/area12;
    if(abs(error)<max_slice_error)
        return area1m2;
    // Погрешность слишком большая. Делим трапецию и пробуем еще раз
    return SliceArea(fun,x1,xm,max_slice_error)+SliceArea(fun,xm,x2,max_slice_error);
}

//функция аппроксимации области под кривой(function) используется адаптивная квадратура
double IntegrateAdaptiveMidpoint(double (*fun)(double),double xmin,double xmax ,int num_intervals,double max_slice_error){
    // Вычисляем ширину прямоугольника
    double dx=(xmax-xmin)/num_intervals;
    // Добавляем области прямоугольников
    double total_area=0;
    double x=xmin;

    for(int i=1;i<=num_intervals;i++){
        total_area+=SliceArea(fun,x,x+dx,max_slice_error);
        x=x+dx;
    }
    return total_area;
}

int main(){
  cout<<UseRectangleRule(function1,0,5,10)<<endl;
  cout<<UseTrapezoidRule(function1,0,5,10)<<endl;
  cout<<IntegrateAdaptiveMidpoint(function1,0,5,24,1)<<endl;
}
