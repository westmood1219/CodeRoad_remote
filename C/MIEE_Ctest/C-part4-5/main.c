#include "swap.h"
//1����Ҫ��дһ����ṹ��صĺ��������ýṹ��ָ����Ϊ�����������ýṹ����Ϊ�����ͷ���ֵ�����߸���ʲô��ȱ�㣿
//�����ҵ�ʹ�ýṹ����Ϊ���������ͷ���ֵ��ʾ�����룬�������дΪʹ�ýṹ��ָ����Ϊ����������д������֮Ҳ�ɡ�

//1���ýṹ��ָ����Ϊ�������ýṹ����Ϊ�����ͷ���ֵ��������һ���βΣ��˷����ڴ�ռ䣬��ָ����ܺõĽ����˲���ѹջ��û�����Ĺ������ܡ�
//struct Books
//{
//    char  title[50];
//    char  author[50];
//    char  subject[100];
//    unsigned long long book_id; // �޸�Ϊ unsigned long long
//};
//
//void print1(struct Books p)
//{
//    printf("%s %s %s %llu\n", p.title, p.author, p.subject, p.book_id); // ʹ�� %llu ��ʽ�����
//}
//
//void print2(struct Books* sp)
//{
//    printf("%s %s %s %llu\n", sp->title, sp->author, sp->subject, sp->book_id); // ʹ�� %llu ��ʽ�����
//}
//
//int main()
//{
//    struct Books book = { "\n��·", "���Դ", "������Ϣ", 9787040565539ULL }; // ʹ�� ULL ��׺
//    print1(book);
//    print2(&book);
//    return 0;
//}

//2������֦�ṹ��(Litchi) .��������(���ζ��Ŵ�ס���֦������֦��)����ɫ�������С�ȡ���ȡ����ۡ������·ݡ����صȵ���Ϣ��
//������֦�ṹ�����飬�������� 3 ��Ʒ�ֵĹ� 6 ����֦���ýṹ���Ա����(.)����ʽ��������� 6 ����֦����ϸ��Ϣ��

 // ������֦�ṹ��
//struct Litchi {
//    char type[20];       // ����
//    char color[20];      // ��ɫ
//    char kernelSize[20]; // �����С��
//    char sweetness[20];  // ���
//    double price;        // ����
//    char ripeMonth[20];  // �����·�
//    char origin[20];     // ����
//};
//
//int main() {
//    struct Litchi litchis[6] = {
//        {"��ζ", "�ʺ�", "С��", "����", 15.5, "6��", "�㶫"},
//        {"Ŵ����", "���", "�еȺ�", "����", 13.8, "7��", "����"},
//        {"��֦��", "���", "���", "������", 20.0, "8��", "����"},
//        {"��֦", "����", "С��", "����", 9.9, "5��", "����"},
//        {"�����", "�ʺ�", "С��", "����", 18.0, "6��", "�㶫"},
//        {"����", "����", "С��", "����", 25.0, "7��", "�㶫"}
//    };
//    //���
//    // ��ӡ��ͷ
//    printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s\n",
//        "����", "��ɫ", "�����С��", "���", "����", "�����·�", "����");
//
//    // ��ӡÿ����֦����Ϣ
//    for (int i = 0; i < 6; i++) {
//        printf("%-10s %-10s %-10s %-10s %-10.1f %-10s %-10s\n",
//            litchis[i].type, litchis[i].color, litchis[i].kernelSize, litchis[i].sweetness,
//            litchis[i].price, litchis[i].ripeMonth, litchis[i].origin);
//    }
//    return 0;
//}


//3���� Task 1���ýṹ��ָ�� (->)����ʽ������֦�ṹ�����飬����ÿ����֦�ļ۸񰴴Ӹߵ��������������֦����Ϣ
//struct Litchi {
//    char type[20];       // ����
//    char color[20];      // ��ɫ
//    char kernelSize[20]; // �����С��
//    char sweetness[20];  // ���
//    double price;        // ����
//    char ripeMonth[20];  // �����·�
//    char origin[20];     // ����
//};
//
//int main() {
//    struct Litchi litchis[6] = {
//        {"��ζ", "�ʺ�", "С��", "����", 15.5, "6��", "�㶫"},
//        {"Ŵ����", "���", "�еȺ�", "����", 13.8, "7��", "����"},
//        {"��֦��", "���", "���", "������", 20.0, "8��", "����"},
//        {"��֦", "����", "С��", "����", 9.9, "5��", "����"},
//        {"�����", "�ʺ�", "С��", "����", 18.0, "6��", "�㶫"},
//        {"����", "����", "С��", "����", 25.0, "7��", "�㶫"}
//    };
//    //ð����
//    for (int i = 0; i < 6 - 1; i++) {
//        for (int j = 0; j < 6 - 1 - i; j++) {
//            struct Litchi* lp1 = &litchis[j];
//            struct Litchi* lp2 = &litchis[j + 1];
//            if (lp1->price < lp2->price) {
//                // ���������ṹ��
//                struct Litchi temp = *lp1;
//                *lp1 = *lp2;
//                *lp2 = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < 6; i++) {
//        printf("%-10s %-10s %-10s %-10s %-10.1f %-10s %-10s\n",
//            litchis[i].type, litchis[i].color, litchis[i].kernelSize, litchis[i].sweetness,
//            litchis[i].price, litchis[i].ripeMonth, litchis[i].origin);
//    }
//    return 0;
//}

//4MIEEЭ���� 10 λͬѧ������Ϣ¼�룬������(�ַ�������)��ѧ�š�רҵ��ѧԺ(�ַ�������)���Ѿ����ѧϰ�Ĳ�����C�����½�2��(�ַ�������)�������ṹ������������� 10 λͬѧ����Ϣ���ýṹ��ָ����ʸ����飬�����û������ѧ�ź���������������λͬѧ����Ϣ
//struct MIEE {
//    char name[10];
//    int studentId;
//    char major[20];
//    char college[20];
//    char completedCourses[20];
//};
//int main()
//{
//    struct MIEE newbirds[10] = {
//        {"����", 1001, "�������ѧ", "�����ѧԺ", "C�����½�2"},
//        {"����", 1002, "�������", "�����ѧԺ", "C�����½�1"},
//        {"����", 1003, "���繤��", "ͨ��ѧԺ", "C�����½�3"},
//        {"����", 1004, "�˹�����", "�����ѧԺ", "C�����½�4"},
//        {"����", 1005, "���ݿ�ѧ", "��ѧѧԺ", "C�����½�5"},
//        {"�ܰ�", 1006, "������Ϣ", "���ӹ���ѧԺ", "C�����½�6"},
//        {"���", 1007, "������", "�����ѧԺ", "C�����½�7"},
//        {"֣ʮ", 1008, "������", "��е����ѧԺ", "C�����½�8"},
//        {"��ʮһ", 1009, "��������", "����ѧԺ", "C�����½�9"},
//        {"��ʮ��", 1010, "���Ͽ�ѧ", "����ѧԺ", "C�����½�10"}
//    };
//    int id;
//    char name1[20];
//    scanf_s("%d %s", &id, name1);
//    int index = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        if (newbirds[i].studentId == id)
//        {
//            index = i;
//            break;
//        }
//    }
//    printf("%s %d %s %s %s", newbirds[index].name, newbirds[index].studentId, newbirds[index].major, newbirds[index].college, newbirds[index].completedCourses);
//    return 0;
//}

//challenge:����������LED�ƣ�ÿ��LED�ƶ������Ӧ����ɫ����-��-���������ȣ����Ϊ0�����Ϊ100��
// ����Ҫʵ������LED���Ժ��->�̵�->���Ƶ�˳����ʾ����ÿ���Ƶĵ���ʱ��Ϊ2s������Ϊ0->100->0��ʹ��printf���ģ���������
//struct LED {
//    char color[10];
//    int brightness;
//
//};
//int main()
//{
//    struct LED Led[3] = {
//        {"Red LED", 0},
//        {"Green LED", 0},
//        {"Blue LED", 0},
//    };
//    for (int i = 0; i < 3; i++)
//    {
//        printf("Turning on %s...\n", Led[i].color);
//        int time_interval = 10;  // 2 ��ֳ� 200 �ݣ�ÿ�� 10����
//        while (Led[i].brightness <= 100)
//        {
//            printf("LED %d: Brightness = %d%%\n", i+1, Led[i].brightness);
//            Led[i].brightness++;
//            Sleep(time_interval);  // �ӳ� 10 ����
//        }//�������Ϊ101����Ҫ������ʵ��ֱ�ӽ�����
//        Led[i].brightness -= 2;
//        while (Led[i].brightness >= 0)
//        {
//            printf("LED %d: Brightness = %d%%\n", i+1, Led[i].brightness);
//            Led[i].brightness--;
//            Sleep(time_interval);  // �ӳ� 10 ����
//        }
//    }
//    return 0;
//}
//�Ӽ��̻�ȡ��������������ֵ������ a �� b,Ҫ���� swap ������ʽʵ�� a ��b ����ֵ�����������β�Ҫ�������ָ�������
// //�����������Զ��ļ�����֯��ʽʵ�� ��main.c����ֻ�������̹������彻�������ɺ������ú�ʵ�֣��Һ����������䶨��ֱ�����swap.h��swap.c�С�
int main()
{
    int a = 0;
    int b = 0;
    printf("����a��b��");
    scanf_s("%d %d", &a, &b);
    swap(&a, &b);
    return 0;
}