#include <iostream>
using namespace std;

class abtdrk
{
public:
    virtual void boil() = 0;

    virtual void brew() = 0;

    virtual void pourin() = 0;

    virtual void puts() = 0;
    
    void makedrk()
    {
        boil();
        brew();
        pourin();
        puts();
    }
};

class coffee :public abtdrk
{
public:

    virtual void boil()
    {
        cout << "water in" << endl;

    }
    virtual void brew()
    {
        cout << "coffee mixed in" << endl;

    }
    virtual void pourin()
    {
        cout << "pour into cup" << endl;

    }
    virtual void puts()
    {
        cout << "sugar&milk" << endl;

    }

};

class tea :public abtdrk
{
public:
    virtual void boil()
    {
        cout << "water in" << endl;

    }
    virtual void brew()
    {
        cout << "tea leaves mixed in" << endl;

    }
    virtual void pourin()
    {
        cout << "pour into cup" << endl;

    }
    virtual void puts()
    {
        cout << "lemonin" << endl;

    }

};

void doWork(abtdrk* abs)
{
    abs->makedrk();
    delete abs;
}

void test01()
{
    //coffee
    doWork(new coffee);
    cout << "---------------" << endl;
    doWork(new tea);

}

int main()
{
    test01();
    system("pause");
    return 0;
}