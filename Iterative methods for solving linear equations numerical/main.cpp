#include <math.h>
#include <iostream>
#define eps 0.0001//требуемая точность вычислений

using namespace std;

void menu() //функция для вывода меню
{
    
    cout<<" Выберете нужный пункт меню"<<endl;
    
    cout<<"1:  Метод простых итерации"<<endl;
    cout<<"2:  Метод Зейделя"<<endl;
    cout<<"2:  Метод Зейделя"<<endl;
    cout<<"0:  Выход"<<endl;
}

/*int * simpleIteration(int *A, int *B){
 
 
 };*/
int main(){
    int n=0;
    cout<<"Введите размерность матрицы N*N:";
    cin>>n;
    double A[n][n],B[n],xn[n],x[n];
    cout<<"Введите элементы м-цы:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"  A ["<<i+1<<"]["<<j+1<<"] = ";
            cin>>A[i][j];
        }
    }
    cout<<"Введите свободные члены:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"  B ["<<"|"<<i+1<<"|"<<"] = ";
        cin>>B[i];
    }
    int num = 0;
    menu();
    cin>>num;
    while (num != 0) {
        switch (num) {
            case 1:
            {
                for (int i=0; i<n; i++) {
                    x[i] = 0;
                }
                double measurementError = 0;
                int k = 0;
                do{
                    k++;
                    measurementError = 0;
                    for(int i = 0; i<n; i++){
                        xn[i] = -B[i];
                        for(int j = 0; j<n; j++){
                            if(i != j)
                                xn[i] += A[i][j] * x[j];
                        }
                        xn[i] /= (-A[i][i]);
                    }
                    if (k <= 2)
                        cout<<"Итерация "<< k <<endl;
                    for(int i=0; i<n; i++){
                        if (k <= 2){
                            cout<<"x"<<i<<" = "<<B[i]/A[i][i]<<" - ";
                            for (int j = 0; j<n; j++) {
                                if (i != j)
                                    cout<<A[i][j]/A[i][i]<<"*"<<x[j]<<" - ";
                            };
                            cout<<" = "<<xn[i]<<endl;
                        }
                        if (fabs(x[i]-xn[i]) > measurementError)
                            measurementError=fabs(x[i]-xn[i]);
                        x[i] = xn[i];
                    }
                }while(measurementError > 0.0001);
                
                cout<<"Кол-во итераций:"<< k <<endl;
                //cout<<"Максимальная погрешность: "<< norma <<endl;
                for(int i=0; i<n; i++)
                    cout<<"x ["<<i+1<<"] = "<<x[i]<<endl;
                break;
            }
                
                
                
                
            case 2:{
                for (int i=0; i<n; i++) {
                    x[i] = 0;
                    xn[i] = 0;
                }
                double norma = 0;
                int k = 0;
                do{
                    k++;
                    norma=0;
                    for(int i=0;i<n;i++){
                        x[i] = -B[i];
                        for(int j=0; j<n; j++){
                            if(i != j)
                                x[i] += A[i][j] * x[j];
                        }
                        x[i] /= -A[i][i];
                    }
                    if (k <= 2)
                        cout<<"Итерация "<< k <<endl;
                    for(int i=0; i<n; i++){
                        if (k <= 2){
                            cout<<"x"<<i<<" = "<<B[i]/A[i][i]<<" - ";
                            for (int j = 0; j<n; j++) {
                                if (i != j)
                                    cout<<A[i][j]/A[i][i]<<"*"<<x[j]<<" - ";
                            };
                            cout<<" = "<<xn[i]<<endl;
                        }
                        if(fabs(x[i]-xn[i]) > norma)
                            norma=fabs(x[i]-xn[i]);
                        xn[i]=x[i];
                    }
                }
                while(norma > eps);
                cout<<"Кол-во итераций:"<<k<<endl;
                for(int i=0;i<n;i++)
                    cout<<"x ["<<i+1<<"] = "<<x[i]<<endl;
                
                break;
                
            }
            default:
                break;
        }
        menu();
        cin>>num;
    }
}







