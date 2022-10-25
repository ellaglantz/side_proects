#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

//g++ path.cpp -o path && ./path map1.txt 5 5

//g++ path.cpp -o path && ./path map3.txt 20 20

void path(int row_idx, int col_idx, int rows, int cols, int prev_val, int high, std::vector<std::vector<int>> &vect, bool &yes_no){
    if(row_idx < 0 || row_idx >= rows || col_idx < 0 || col_idx >= cols || vect[row_idx][col_idx] < prev_val){  //checks valid index values and number values
        return;
    }else if(vect[row_idx][col_idx] == high){
        yes_no = true;
        return;
    }

     // std::cout << row_idx << " " << col_idx << std::endl;

    prev_val = vect[row_idx][col_idx];
    vect[row_idx][col_idx] *= -1;       //sets value to negative to show it has been visited

    for(int i = 0; i < 4; i++){
        if(i == 0){     //top
            path(row_idx-1, col_idx, rows, cols, prev_val, high, vect, yes_no);
            if(yes_no == true){
                break;
            }
        }else if (i == 1){  //bot
            path(row_idx+1, col_idx, rows, cols, prev_val, high, vect, yes_no);
            if(yes_no == true){
                break;
            }
        }else if (i == 2){  //left
            path(row_idx, col_idx-1, rows, cols, prev_val, high, vect, yes_no);
            if(yes_no == true){
                break;
            }
        }else{          //right
            return path(row_idx, col_idx+1, rows, cols, prev_val, high, vect, yes_no);
            if(yes_no == true){
                break;
            }
        }
    }
    vect[row_idx][col_idx] *= -1;       //resets value to positive if that line did not work
    return;
}

int main(int argc, char* argv[]){

    std::string fname = argv[1];
    int rows = std::stoi(argv[2]);
    int cols = std::stoi(argv[3]);



    //opens file
    std::ifstream input_file;
    input_file.open(fname);

    std::string line;
    std::vector<std::vector<int>> input_vector;
    std::vector<int> cols_vec;


    int col_count = 0;
    if(input_file.is_open()){
        while(std::getline(input_file, line)){
            std::stringstream ss;

            //stores each line into a string stream
            ss << line;

            // std::cout << line << std::endl;


            //runs until end of file flag for string stream
            double num;
            while(!ss.eof()){
                // std::cout << count << std::endl;
                std::string temp;
                //splits up each number in string stream and stores into temp to then go into the double array
                ss >> temp;
                if (std::stringstream(temp) >> num){
                    col_count++;
                    cols_vec.push_back(num);
                    if(col_count == cols){
                        col_count = 0;
                        input_vector.push_back(cols_vec);
                        cols_vec.clear();
                    }

                }
                temp = "";

            }
        }
        input_file.close();
    }


    int low_row = 0, low_col = 0, high_row = 0, high_col = 0;
    bool yes_no = false;

    int low = input_vector[0][0], high = input_vector[0][0];


    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(input_vector[i][j] < low){
                low = input_vector[i][j];
                low_row = i;
                low_col = j;
            }
            if(input_vector[i][j] > high){
                high = input_vector[i][j];
                high_row = i;
                high_col = j;
            }
        }
    }

    // std::cout << "CHECK" << std::endl;


    //function call at low
    path(low_row, low_col, rows, cols, low, high, input_vector, yes_no);

    std::cout << low_row+1 << " " << low_col+1 << " " << high_row+1 << " " << high_col+1 << " ";
    if(yes_no == false){
        std::cout << "no" << std::endl;
    }else{
        std::cout << "yes" << std::endl;
    }








    return 0;
}
