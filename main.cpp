#include <iostream>
#include <algorithm>
#include "homework3.h"

using namespace std;

StudentStruct *students = nullptr;
int numOfStudent = 0;

void printStudentList(){
   int idx = 0;
   for(idx = 0; idx < numOfStudent; ++idx){
        std::cout << "ID: " << students[idx].id 
                  << ",\t Name: " << students[idx].name
                  << ",\t Midterm: " << students[idx].record.midterm 
                  << ",\t Final: " << students[idx].record.final
                  << ",\t Total: " << students[idx].record.midterm + 
                                    students[idx].record.final << std::endl;
   }
   cout << "---------------------------" << endl;
}


// ID순으로 정렬하기 위한 Functor (SortByID) 정의 
//operator() 함수 뒤에 const를 붙이는 이유는 해당 함수가 클래스/구조체 멤버 변수의 값을 변경하지 않겠다는 것을 약속(promise)하는 것입니다.
//이 const는 이 함수가 호출될 때 this 포인터가 가리키는 객체(여기서는 SortByID의 인스턴스)의 상태(멤버 변수)를 변경하지 않겠다는 것을 의미합니다.
//operator() 함수의 매개변수에도 const가 사용되었습니다.
//이 const는 a와 b가 복사되는 것이 아니라 참조로 전달되면서도, 함수 내에서 이 두 객체의 멤버 변수를 변경하지 않겠다는 것을 의미합니다.
struct SortByID{
    int operator()(const StudentStruct& a, const StudentStruct& b) const{
        return a.id < b.id;
    }
};


// 이름순으로 정렬하기 위한 Functor (SortByName) 정의 
/* TODO */
struct SortByName{
    bool operator()(const StudentStruct& a, const StudentStruct& b)const{
        return a.name < b.name;
    }
};

// 중간고사 성적 높은 순서로 정렬하기 위한 Functor (SortByMidterm) 정의 
/* TODO */
struct SortByMidterm{
    int operator()(const StudentStruct& a, const StudentStruct& b)const{
        return a.record.midterm > b.record.midterm;
    }
};

// 기말고사 성적 높은 순서로 정렬하기 위한 Functor (SortByFinal) 정의 
/* TODO */
struct SortByFinal{
    int operator()(const StudentStruct& a, const StudentStruct& b)const{
        return a.record.final > b.record.final;
    }
};

// 중간+기말 성적 높은 순서로 정렬하기 위한 Functor (SortByTotal) 정의 
/* TODO */
struct SortByTotal{
    int operator()(const StudentStruct& a, const StudentStruct& b)const{
        return (a.record.midterm+a.record.final) > (b.record.midterm+b.record.final);
    }
};


void doTest1(){
    cout << "---------------------------" << endl;
    cout << "Test 1" << endl;

    printStudentList();

    // SortByID를 이용해 ID 순서로 정렬
    cout << "Sort by ID" << endl;
    std::sort(students, students + numOfStudent, SortByID{});
    printStudentList();

    // SortByName을 이용해 알파벳 순으로 이름 정렬 
    cout << "Sort by Name" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, SortByName{});
    printStudentList();

    // SortByMidterm을 이용해 중간고사 성적 높은 순으로 정렬
    cout << "Sort by Midterm" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, SortByMidterm{});
    printStudentList();

    // SortByFinal을 이용해 기말고사 성적 높은 순으로 정렬
    cout << "Sort by Final" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, SortByFinal{});
    printStudentList();

    // SortByTotal을 이용해 중간 + 기말 고사 높은 순으로 정렬
    cout << " Sort by Total" << endl;
    /* TODO */
    std::sort(students, students + numOfStudent, SortByTotal{});
    printStudentList();
}


void doTest2(){
    cout << "---------------------------" << endl;
    cout << "Test 2" << endl;

    // StudentStruct의 ID 필드를 기준으로 알파벳 순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by ID" << endl;
    auto sortByID = [](StudentStruct &a, StudentStruct &b) -> int {
        return a.id < b.id;
    };
    std::sort(students, students + numOfStudent, sortByID);
    printStudentList();

    // StudentStruct의 name 필드를 기준으로 알파벳 순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by Name" << endl;
    /* TODO */
    auto sortByName = [](StudentStruct &a, StudentStruct &b) -> bool {
        return a.name < b.name;
    };
    std::sort(students, students + numOfStudent, sortByName);
    printStudentList();

    // StudentStruct의 midterm 점수를 기준으로 높은순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by Midterm" << endl;
    /* TODO */
    auto sortByMidterm = [](StudentStruct &a, StudentStruct &b) -> int {
        return a.record.midterm > b.record.midterm;
    };
    std::sort(students, students + numOfStudent, sortByMidterm);
    printStudentList();


    // StudentStruct의 final 점수를 기준으로 높은순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << "Sort by Final" << endl;
    /* TODO */
    auto sortByFinal = [](StudentStruct &a, StudentStruct &b) -> int {
        return a.record.final > b.record.final;
    };
    std::sort(students, students + numOfStudent, sortByFinal);
    printStudentList();

    // StudentStruct의 midterm+final 점수를 기준으로 알파벳 순으로 정렬하는 lambda 함수 정의 및 std::sort를 이용해 정렬하기
    cout << " Sort by Total" << endl;
    /* TODO */
    auto sortByTotal = [](StudentStruct &a, StudentStruct &b) -> int {
        return (a.record.midterm+a.record.final) > (b.record.midterm+b.record.final);
    };
    std::sort(students, students + numOfStudent, sortByTotal);
    printStudentList();

}

int main(int argc, char **argv) {
    const int MAX_STUDENTS = 100;
    students = new StudentStruct[MAX_STUDENTS];

    /* FIXME: parameter numOfStudent를 reference 타입으로 바꿔보기 */
    fillStudentRecord(students, numOfStudent);


    if(argc == 2){
        int select = atoi(argv[1]);
        switch(select){
            case 1:
                doTest1();
                delete[] students;
                return 0;
            case 2:
                doTest2();
                delete[] students;
                return 0;
        }
    }

    doTest1();
    doTest2();


    delete[] students;
    return 0;
}