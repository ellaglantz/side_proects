#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

//g++ blobs.cpp -o blobs && ./blobs grid.txt 8 8 4

void checkNeighbors(int rIdx, int cIdx, std::vector<std::vector<int>> &vect, int type, int rows, int cols){
            //base case
            if(vect[rIdx][cIdx] == 0 || vect[rIdx][cIdx] == 2){
                return;
            }
            //set current idx to 2
            vect[rIdx][cIdx] = 2;

            //switch all visited values to zero
            if(type == 4){
                //top
                if(rIdx - 1 >= 0 && vect[rIdx-1][cIdx] == 1){
                    checkNeighbors(rIdx-1, cIdx, vect, type, rows, cols);
                }
                //bot
                if(rIdx + 1 < rows && vect[rIdx+1][cIdx] == 1){
                    checkNeighbors(rIdx+1, cIdx, vect, type, rows, cols);
                }
                //left
                if(cIdx - 1 >= 0 && vect[rIdx][cIdx-1] == 1){
                    checkNeighbors(rIdx, cIdx-1, vect, type, rows, cols);
                }
                //right
                if(cIdx + 1 < cols && vect[rIdx][cIdx+1] == 1){
                    checkNeighbors(rIdx, cIdx+1, vect, type, rows, cols);
                }
            }else{
                //top
                if(rIdx - 1 >= 0 && vect[rIdx-1][cIdx] == 1){
                    checkNeighbors(rIdx-1, cIdx, vect, type, rows, cols);
                }
                //bot
                if(rIdx + 1 < rows && vect[rIdx+1][cIdx] == 1){
                    checkNeighbors(rIdx+1, cIdx, vect, type, rows, cols);
                }
                //left
                if(cIdx - 1 >= 0 && vect[rIdx][cIdx-1] == 1){
                    checkNeighbors(rIdx, cIdx-1, vect, type, rows, cols);
                }
                //right
                if(cIdx + 1 < cols && vect[rIdx][cIdx+1] == 1){
                    checkNeighbors(rIdx, cIdx+1, vect, type, rows, cols);
                }
                //topleft
                if(rIdx - 1 >= 0 && cIdx - 1 >= 0 && vect[rIdx-1][cIdx-1] == 1){
                    checkNeighbors(rIdx-1, cIdx-1, vect, type, rows, cols);
                }
                //botright
                if(rIdx + 1 < rows && cIdx + 1 < cols && vect[rIdx+1][cIdx+1] == 1){
                    checkNeighbors(rIdx+1, cIdx+1, vect, type, rows, cols);
                }
                //botleft
                if(rIdx + 1 < rows && cIdx - 1 >= 0 && vect[rIdx+1][cIdx-1] == 1){
                    checkNeighbors(rIdx+1, cIdx-1, vect, type, rows, cols);
                }
                //topright
                if(rIdx - 1 >= 0 && cIdx + 1 < cols && vect[rIdx-1][cIdx+1] == 1){
                    checkNeighbors(rIdx-1, cIdx+1, vect, type, rows, cols);
                }
            }
}

int main(int argc, char* argv[]){

    std::string fname = argv[1];
    int rows = std::stoi(argv[2]);
    int cols = std::stoi(argv[3]);
    int conn_type = std::stoi(argv[4]);


    //std::cout << fname << rows << cols << starting_row << starting_col << conn_type << std::endl;

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





    int blobCount = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(input_vector[i][j] == 1){
                // std::cout << "Index: " << i << " " << j << std::endl;
                checkNeighbors(i, j, input_vector, conn_type, rows, cols);
                blobCount++;
                // for(int z = 0; z < rows; z++){
                //     for(int k = 0; k < cols; k++){
                //         std::cout << input_vector[z][k] << " ";
                //     }
                //     std::cout << std::endl;
                // }
                // std::cout << std::endl;
            }
        }
    }


    std::cout << blobCount << std::endl;

    return 0;
}
