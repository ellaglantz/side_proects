#include <iostream>
#include <cmath>
#include <stack>
#include <sstream>
#include <string>

//g++ eval.cpp -o eval && ./eval "1 2 + "

int main(int argc, char* argv[]){
    std::string input = argv[1];

    int num;
    std::string temp;
    std::stringstream ss;
    std::stack<std::string> stack;

    // puts input into string stream
    ss << input;

    while(true){
        // puts elements into temp
        ss >> temp;
        // if number
        //     push it onto the stack
        // if operator
        //     pop two numbers (operands) from the stack, evaluate the operator on those numbers and push the result back to the stack
        // if end of the string
        //     pop the number from the stack and return it
        if(std::stringstream(temp) >> num){
            stack.push(temp);
        }
        // print temp
        //std::cout << temp << std::endl;
        if(temp == "*" || temp == "/" || temp == "^" || temp == "+" || temp == "-"){

            int holder = 0;
            double temp1 = std::stoi(stack.top());
            stack.pop();
            double temp2 = std::stoi(stack.top());
            stack.pop();
            if(temp == "*"){
                holder = floor(temp2 * temp1);
            }else if (temp == "/"){
                holder = floor(temp2 / temp1);
            }else if (temp == "+"){
                holder = temp2 + temp1;
            }else if (temp == "^"){
                holder = pow(temp2, temp1);
            }
            else{
                holder = temp2 - temp1;
            }
            // std::cout << temp2 << " " << temp << " " << temp1 << " " << holder << std::endl;
            std::string insert = std::to_string(holder);
            stack.push(insert);
        }
        if(ss.eof()){
            std::cout << stack.top() << std::endl;
            stack.pop();
            return 0;
        }
    }



    return 0;
}
