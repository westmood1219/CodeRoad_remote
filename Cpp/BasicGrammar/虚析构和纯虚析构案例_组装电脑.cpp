#include <iostream>
using namespace std;

class CPU
{
public:
    virtual void calculate() = 0;
};

class videoCard
{
public:
    virtual void display() = 0;
};

class memory
{
public:
    virtual void storage() = 0;
};


class computer
{
public:
    computer(CPU* cpu, videoCard *vc, memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    void doWork()
    {
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

    ~computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU* m_cpu;
    videoCard* m_vc;
    memory* m_mem;

};

class IntelCpu :public CPU
{
public:
    void calculate()
    {
        cout << "Intel'CPU working" << endl;
    }
};

class IntelvideoCard :public videoCard
{
public:
    void display()
    {
        cout << "Intel videocark working" << endl;
    }
};

class Intelmemory :public memory
{
public:
    void storage()
    {
        cout << "Intel memory working" << endl;
    }
};

class AMDCpu :public CPU
{
public:
    void calculate()
    {
        cout << "AMD'CPU working" << endl;
    }
};

class AMDvideoCard :public videoCard
{
public:
    void display()
    {
        cout << "AMD videocark working" << endl;
    }
};

class AMDmemory :public memory
{
public:
    void storage()
    {
        cout << "AMD memory working" << endl;
    }
};

void test1()
{
    CPU* Intelcpu = new IntelCpu;
    videoCard* intelCard = new IntelvideoCard;
    memory* AMDMem = new AMDmemory;

    computer* computer1 = new computer(Intelcpu, intelCard, AMDMem);
    computer1->doWork();
    delete computer1;
}
int main()
{
    test1();
    system("pause");
    return 0;
}