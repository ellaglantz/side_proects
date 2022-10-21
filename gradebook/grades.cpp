#include "grades.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>


Gradebook::Gradebook(std::string classType){
    class_type = classType;
    int switchCase;

    //Checking which switch statemnet to go into
    if (class_type == "Math"){
        switchCase = 0;
    }
    else if (class_type == "Science"){
        switchCase = 1;
    }
    else if (class_type == "Computer"){
        switchCase = 2;
    }
    else if (class_type == "Writing"){
        switchCase = 3;
    }

    switch(switchCase){
        case 0:
            //taken from my MTH - 142 course
            assignments = 0.15;
            attendance = 0.5;
            final_exam = 0.20;
            midterms = 0.45;
            quizzes = 0.15;
            labs_weight = 0;
            participation = 0;
            classwork = 0;
            final_project = 0;
            final_paper = 0;
            break;
        case 1:
            //taken from my GEO - 103 course
            assignments = 0.20;
            classwork = 0.15;
            final_exam = 0.10;
            final_paper = 0.10;
            final_project = 0.10;
            labs_weight = 0.25;
            midterms = 0.10;
            participation = 0;
            attendance = 0;
            quizzes = 0;
            break;
        case 2:
            //taken from our CSC - 212 course
            assignments = 0.4854;           //(500/1030)
            final_exam = 0.0971;            // (100/1030)
            final_project = 0.3398;         // (350/1030)
            labs_weight = 0.0485;           // (50/1030)
            review_project = 0.0291;        // (30/1030)
            midterms = 0;
            classwork = 0;
            final_paper = 0;
            participation = 0;
            attendance = 0;
            quizzes = 0;
            break;
        case 3:
            assignments = 0.30;
            attendance = 0.5;
            classwork = 0.15;
            final_paper = 0.30;
            final_project = 0.15;
            participation = 0.5;
            quizzes = 0;
            midterms = 0;
            review_project = 0;
            final_exam = 0;
            labs_weight = 0;
            break;
    }
}

double Gradebook::calculate(std::string filename){
    //create sum variable
    double gradeSum;

    //Reading file and putting into 2D vector
    std::ifstream inFile(filename);
    std::string line;
    std::vector<std::vector<double>> subVector;
    while (std::getline(inFile, line)) {
        std::vector <double> temp;
        std::istringstream stream(line);
        double val;
        while(stream >> val) {
            temp.push_back(val);
        }
        //std::cout<< temp.size() << std::endl;
        subVector.push_back(temp);
    }
    //std::cout<< subVector.size() << std::endl;

    if (class_type == "Math"){
            std::vector<double> finalGs;
            double sum = 0;
            int count = 0;
            //get average for each subvector
            for(int i = 0; i < subVector.size(); i++){
            for(int j = 0; j < subVector[i].size(); j++){
                sum += subVector[i][j];
                count += 1;
            }
            finalGs.push_back(sum/count);
            sum = 0;
            count = 0;
            }

            double finalG = 0;
            //use average and multiply by respective weight to get
            for (int k = 0; k < finalGs.size(); k++){
                if(k == 0 || k == 4){
                    finalG += (finalGs[k] * assignments);
                }
                else if (k == 1){
                    finalG += (finalGs[k] * attendance);
                }
                else if (k == 2){
                    finalG += (finalGs[k] * final_exam);
                }
                else if (k == 3){
                    finalG += (finalGs[k] * midterms);
                }
            }
            return finalG/1.45;
            //std::cout << finalG/1.45 << std::endl;;

    }
        else if (class_type == "Science"){
            std::vector<double> finalGs;
            double sum = 0;
            int count = 0;
            //get average for each subvector
            for(int i = 0; i < subVector.size(); i++){
            for(int j = 0; j < subVector[i].size(); j++){
                sum += subVector[i][j];
                count += 1;
            }
            finalGs.push_back(sum/count);
            sum = 0;
            count = 0;
            }

            double finalG = 0;
            //use average and multiply by respective weight to get
            for (int k = 0; k < finalGs.size(); k++){
                if(k == 0){
                    finalG += (finalGs[k] * assignments);
                }
                else if (k == 1){
                    finalG += (finalGs[k] * classwork);
                }
                else if (k == 2 || k == 3 || k == 4 || k == 6){
                    finalG += (finalGs[k] * final_exam);
                }
                else if (k == 5){
                    finalG += (finalGs[k] * labs_weight);
                }
            }

            return finalG;
            //std::cout << finalG << std::endl;
        }
        else if (class_type == "Computer"){
            std::vector<double> finalGs;
            double sum = 0;
            int count = 0;
            //get average for each subvector
            for(int i = 0; i < subVector.size(); i++){
            for(int j = 0; j < subVector[i].size(); j++){
                sum += subVector[i][j];
                count += 1;
            }
            finalGs.push_back(sum/count);
            sum = 0;
            count = 0;
            }

            double finalG = 0;
            //use average and multiply by respective weight to get
            for (int k = 0; k < finalGs.size(); k++){
                if(k == 0){
                    finalG += (finalGs[k] * assignments);
                }
                else if (k == 1){
                    finalG += (finalGs[k] * final_exam);
                }
                else if (k == 2){
                    finalG += (finalGs[k] * final_project);
                }
                else if (k == 3){
                    finalG += (finalGs[k] * labs_weight);
                }
                else if (k == 4){
                    finalG += (finalGs[k] * review_project);
                }
                //std::cout << finalG << std::endl;
            }
            return finalG;
            //std::cout << finalG << std::endl;;
        }
        if (class_type == "Writing"){
            std::vector<double> finalGs;
            double sum = 0;
            int count = 0;
            //get average for each subvector
            for(int i = 0; i < subVector.size(); i++){
            for(int j = 0; j < subVector[i].size(); j++){
                sum += subVector[i][j];
                count += 1;
            }
            finalGs.push_back(sum/count);
            sum = 0;
            count = 0;
            }

            double finalG = 0;
            //use average and multiply by respective weight to get
            for (int k = 0; k < finalGs.size(); k++){
                if(k == 0){
                    finalG += (finalGs[k] * assignments);
                }
                else if (k == 1){
                    finalG += (finalGs[k] * attendance);
                }
                else if (k == 2){
                    finalG += (finalGs[k] * classwork);
                }
                else if (k == 3){
                    finalG += (finalGs[k] * final_paper);
                }
                else if (k == 4){
                    finalG += (finalGs[k] * final_project);
                }
                else if (k == 5){
                    finalG += (finalGs[k] * participation);
                }
            }
            return finalG/1.9;
            //std::cout << finalG/1.9 << std::endl;;
        }
        return -1;
    }
