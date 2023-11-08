#include <vector>
#include <iostream>
using namespace std;

/* Matrix Class
Data:
    vector<vector<T>> A
Constructor:
    Matrix()
    Matrix(int)
    Matrix(int,int)
Matrix Properties:
    getRowCount()
    getColCount()
    isSqrMatrix()
    order()
Matrix Data Manipulate:
    T& ()(int,int)
Matrix Function:
    getIdentity(int)
Matrix Helper:
    print()
Matrix Manipulation
    Matrix +(Matrix)

*/
template<typename T>
class Matrix{
    
    public:
    vector<vector<T>> A;

    Matrix()
    {
    }
    Matrix(int order)
    {
        //square matrix
        A = vector<vector<T>>(order,vector<T>(order,0));
    }
    Matrix(int row,int col)
    {
        A = vector<vector<T>>(row,vector<T>(col,0));
    }

    static Matrix<int> getIdentity(int order)
    {
        //identity matrix is always square
        Matrix<T> temp(order);
        for(int i = 0; i < temp.A.size(); i++)
        {
            for(int j = 0; j < temp.A[0].size(); j++)
            {
                if(i == j)
                {
                    temp.A[i][i] = 1;
                }
                else
                {
                    temp.A[i][j] = 0;
                }
            }
        }
        return temp;
    }

    int getRowCount()
    {
        return A.size();
    }
    int getColCount()
    {
        return A[0].size();
    }
    bool isSqrMatrix()
    {
        return (getRowCount == getColCount) ?  true : false;
    }
    int order()
    {
        //Square Matrix of order n
        if (isSquareMatrix())
        return getRowCount();
        else
        return -1;  
    }
    T& operator()(int row,int col)
    {
        return A[row][col];
    }
    void print()
    {
        for(int i = 0; i < getRowCount(); i++)
        {
            for(int j =0; j < getColCount(); j++)
            {
                cout << A[i][j];
                cout << "\t";
            }
            cout << endl;
        }

    }

    Matrix<T> operator+(Matrix<T> B)
    {
        if(B.getRowCount() != getRowCount() || B.getColCount() != getColCount())
        {
            //addition not possible
            return getIdentity(1);
        }
        else
        {
            Matrix<T> C(getRowCount(),getColCount());
            for(int i = 0; i < getRowCount(); i++)
            {
                for(int j = 0; j < getColCount(); j++)
                {
                    C(i,j) = A[i][j]+B(i,j);
                }
            }
            return C;
        }
        
    }

};

template<typename T>
class Homogenous : public Matrix<T>
{
    Matrix<T> translationMatrix(vector<T> t)
    {

    }
};

int main()
{
    Matrix<int> I;
    Matrix<int> K = I.getIdentity(10);
    K.print();
    Matrix<int> obj(2,3);
        obj(0,0) = 1;
        obj(0,1) = 10;
        obj(1,1) = 99;
        obj(1,0) = 5;
    Matrix<int> obj1(2,3);
        obj1(0,0) = 5;
        obj1(0,1) = 12;
        obj1(1,1) = 8;
        obj1(1,0) = 23;
    Matrix<int> obj3 = I.getIdentity(2);
    Matrix<int> obj2 = obj+obj1+I;
    obj2.print();
    return 1;

}