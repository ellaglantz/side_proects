#include <iostream>
#include <sstream>
#include <stack>

// g++ in2pos.cpp -o conv && ./conv "-10 + 20 * ( 30 / 2 )"


void add_pop(std::string & output, std::stack<std::string> &notation){
    output += notation.top();
    output += " ";
    notation.pop();
}

int main(int argc, char*argv[]){
    std::string output, input;

    std::stack<std::string> notation;

    input = argv[1];

    int num;
    std::string temp;
    std::stringstream ss;

    //stores input into stringstream
    ss << input;

    while(true){


        //pushes next element into temp
        ss >> temp;


        // std::cout << "OUTPUT: " << output << std::endl;
        // std::cout << "TEMP: " << temp << std::endl;



        // if left parenthesis
        //     push it onto the stack
        if(temp == "("){
            notation.push(temp);
        }
        // if operator
        //     pop and write to the output string all consecutive operators that are either operators of higher precedence, or left-associative operators of equal precedence
        //     push the operator onto the stack
        // || temp == "/" || temp == "*" || temp == "^"
        if(temp == "+" || temp == "-"){
            if(!notation.empty() && (notation.top() == "*" || notation.top() == "/" || notation.top() == "^" || notation.top() == "+" || notation.top() == "-" )){ //if previous notation is of the same precedence
                while(!notation.empty() && (notation.top() == "*" || notation.top() == "/" || notation.top() == "^" || notation.top() == "+" || notation.top() == "-")){
                    add_pop(output, notation);
                }
                notation.push(temp);
            }else{  //if previous notation is of a different precedence
                notation.push(temp);
            }
        }else if (temp == "/" || temp == "*"){
            if(!notation.empty() && (notation.top() == "*" || notation.top() == "/" || notation.top() == "^" )){      //if previous notation is greater or equal precedence
                while(!notation.empty() && (notation.top() == "*" || notation.top() == "/" || notation.top() == "^")){
                    add_pop(output, notation);
                }
                notation.push(temp);
            }else{
                notation.push(temp);
            }
        }else if (temp == "^"){
            notation.push(temp);
        }
        // if right parenthesis
        //     pop and write to the output string all operators until a left parenthesis is popped off the stack
        if(temp == ")"){
            while(notation.top() != "("){
                add_pop(output, notation);
            }
            notation.pop();

        }
        // if number
        //     it may be immediately written to the output string
        if(std::stringstream(temp) >> num){
            output += temp;
            output += " ";
        }
        if(ss.eof()){
            while(!notation.empty()){
                add_pop(output, notation);
            }
            break;
        }
    }

    std::cout << output << std::endl;

    return 0;

}
