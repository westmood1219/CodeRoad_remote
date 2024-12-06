////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）
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
//状态不好,写的很垃圾

#include <stdio.h>

int main() {
    int money = 20;
    int bottle = money; // 用钱买汽水，得到相同数量的空瓶
    int empty = bottle; // 初始空瓶数

    while (empty >= 2) {
        int exchange = empty / 2; // 可以换多少瓶汽水
        bottle += exchange; // 增加总汽水数
        empty = exchange + (empty % 2); // 换回来的空瓶加上剩余的空瓶
    }

    printf("%d\n", bottle);
    return 0;
}