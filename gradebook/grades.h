#ifndef GRADES_H
#define GRADES_H
#include <string>

class Gradebook{
    //grade percentage weights
    private:
        std::string class_type;
        float labs_weight; 
        float attendance; 
        float assignments; 
        float participation; 
        float classwork; 
        float quizzes; 
        float midterms; 
        float final_exam; 
        float final_project; 
        float final_paper;
        float review_project;
    public:
        Gradebook(std::string classType);
        double calculate(std::string filename);
};


#endif
