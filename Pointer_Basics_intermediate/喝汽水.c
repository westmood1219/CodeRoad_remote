////����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֣�
//
//#include <stdio.h>
//
//int main()
//{
//    int money = 20;
//    int bottle = money;
//    int empty = bottle;
//    while (empty)
//    {
//        bottle += (empty / 2);
//        if (empty == 2)
//        {
//            break;
//        }
//        else if (empty == 1)
//        {
//            break;
//        }
//        else if (empty % 2 == 1)
//        {
//            empty = empty / 2 + 1;
//        }
//        else if(empty%2 ==0)
//        {
//            empty /= 2;
//        }
//    }
//    printf("%d", bottle);
//    return 0;
//}
//״̬����,д�ĺ�����

#include <stdio.h>

int main() {
    int money = 20;
    int bottle = money; // ��Ǯ����ˮ���õ���ͬ�����Ŀ�ƿ
    int empty = bottle; // ��ʼ��ƿ��

    while (empty >= 2) {
        int exchange = empty / 2; // ���Ի�����ƿ��ˮ
        bottle += exchange; // ��������ˮ��
        empty = exchange + (empty % 2); // �������Ŀ�ƿ����ʣ��Ŀ�ƿ
    }

    printf("%d\n", bottle);
    return 0;
}