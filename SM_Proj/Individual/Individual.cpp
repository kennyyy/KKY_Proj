#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//void Save(const char* filename, int* id, char* name);
//void Load(const char* filename);
//FILE* fpwrite;
//int main()
//{
//    char filename[20] = "data.txt";
//    int id[5] = { 1,2,3,4,5 };
//    char name[10] = "홍길동";	
//
//
//    Save(filename, id, name);
//
//
//    return 0;
//
//}
//
//void Save(const char* filename, int *id, char * name) {
//
//    for(int i=0;;)
//
//    FILE* fpwrite = fopen(filename, "w");
//    if (fpwrite != NULL) {
//            fprintf(fpwrite, "%d %s", *id+1, name);
//        fclose(fpwrite);
//    }
//
//}

//#include <iostream>
//
//
//class Animal{
//	private:
//		int food;
//		int weight;
//	public:
//		int free;
//void set_animal(int _food, int _weight) {
//	food = _food;
//	weight = _weight;
//}
//void increase_food(int inc) {
//	food += inc;
//	weight += (inc / 3);
//}
//void view_stat() {
//	std::cout << "이 동물의 free : " << free << std::endl;
//	std::cout << "이 동물의 food : " << food << std::endl;
//	std::cout << "이 동물의 weight : " << weight << std::endl;
//}
//}; // 세미콜론 잊지 말자!
//int main() {
//	Animal animal;
//	animal.free = 50;
//	animal.set_animal(100, 50);
//	animal.increase_food(30);
//	animal.view_stat();
//	return 0;
//}

#include <iostream>
using namespace std;

class SelfRef
{
private:
    int num;
public:
    SelfRef(int n) :num(n)
    {
        cout << "객체 생성" << endl;
    }
    SelfRef& Adder(int n)
    {
        num += n;
        return *this;
    }
    SelfRef& ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef& ref = obj.Adder(2);
    obj.Adder(1).Adder(2);
    obj.ShowTwoNumber();
   

    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
    return 0;

}
