//Modularity
    //Interface and Its Implementations

//Interface
class Vector1{
    public:
        Vector1(int s);
        double& operator[](int i);
        int size();
    private:
        double* elem;
        int sz;
};   