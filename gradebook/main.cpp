#include <iostream>
#include "grades.h"
#include <vector>
#include <iomanip>

//RUN THIS CODE IN THE COMPILER
//g++ main.cpp grades.cpp -o finalgrades && ./finalgrades


int main(){

    double FinalGrade;
    bool nameTrue = false;
    std::string stuName;

    int count = 0;
    while(nameTrue == false){
        if (count == 0){
            std::cout << "Enter the Name of the Student you would like a gradebook for: \nRafael, Donavan, Ella, Caleb" << std::endl;
            count++;

        }else{
            std::cout << "Invalid name, try again." << std::endl;
        }
        std::cin >> stuName;
        if (stuName == "Rafael" || stuName == "Donavan" || stuName == "Ella" || stuName == "Caleb"){
            nameTrue = true;
        }
    }
    //std::cout<< stuName << std::endl;

    std::vector<Gradebook> gradeBookVec;

    double classGrade;
    std::string className, fname;

    for(int i = 0; i < 4; i++){
        switch(i){
            case 0:
            {
                Gradebook stu_MTH_grades("Math");
                gradeBookVec.push_back(stu_MTH_grades);
                className = "Math";
                break;
            }
            case 1:
            {
                Gradebook stu_SCI_grades("Science");
                gradeBookVec.push_back(stu_SCI_grades);
                className = "Science";
                break;
            }
            case 2:
            {
                Gradebook stu_WRT_grades("Writing");
                gradeBookVec.push_back(stu_WRT_grades);
                className = "Writing";
                break;
            }
            case 3:
            {
                Gradebook stu_CSC_grades("Computer");
                gradeBookVec.push_back(stu_CSC_grades);
                className = "Computer";
                break;
            }
        }
        fname = stuName + "_" + className + ".csv";
        classGrade = gradeBookVec[i].calculate(fname);
        
        std::cout << std::setprecision(2) << stuName << "'s " << className << " class grade is " << classGrade << "." << std::endl;
    }
    
    return 0;
}
