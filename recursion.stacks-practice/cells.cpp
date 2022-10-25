#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

//g++ main.cpp -o cells && ./cells grid.txt 8 8 3 4 4

void checkVisited(std::vector<int>& idxVect, int row_idx, int col_idx, bool &topIdx, bool &leftIdx, bool &bottomIdx, bool &rightIdx, 
                  bool &topRightIdx, bool &topLeftIdx, bool &bottomRightIdx, bool &bottomLeftIdx, int type){
    if(type == 4){
        //finds if these indexes have already been checked
        if(idxVect.size() != 0){
            for(int i = 0; i < idxVect.size()-1; i+=2){
                //print out idxvect
                // std::cout << idxVect[i] << ", " << idxVect[i+1] << std::endl;
                    
                if(idxVect[i] == row_idx-1 && idxVect[i+1] == col_idx){  //top
                    topIdx = true;
                }
                if(idxVect[i] == row_idx && idxVect[i+1] == col_idx-1){  //left
                    leftIdx = true;
                }
                if(idxVect[i] == row_idx+1 && idxVect[i+1] == col_idx){  //bottom
                    bottomIdx = true;
                }
                if(idxVect[i] == row_idx && idxVect[i+1] == col_idx+1){ //right
                    rightIdx = true;
                }
            }
        }
        return;
    }
    else{
        if(idxVect.size() != 0){
            for(int i = 0; i < idxVect.size()-1; i+=2){
                //print out idxvect
                // std::cout << idxVect[i] << ", " << idxVect[i+1] << std::endl;
                    
                if(idxVect[i] == row_idx-1 && idxVect[i+1] == col_idx){  //top
                    topIdx = true;
                }
                if(idxVect[i] == row_idx && idxVect[i+1] == col_idx-1){  //left
                    leftIdx = true;
                }
                if(idxVect[i] == row_idx+1 && idxVect[i+1] == col_idx){  //bottom
                    bottomIdx = true;
                }
                if(idxVect[i] == row_idx && idxVect[i+1] == col_idx+1){ //right
                    rightIdx = true;
                }
                if(idxVect[i] == row_idx-1 && idxVect[i+1] == col_idx+1){  //topRight
                    topRightIdx = true;
                }
                if(idxVect[i] == row_idx-1 && idxVect[i+1] == col_idx-1){  //topLeft
                    topLeftIdx = true;
                }
                if(idxVect[i] == row_idx+1 && idxVect[i+1] == col_idx+1){  //bottomRight
                    bottomRightIdx = true;
                }
                if(idxVect[i] == row_idx+1 && idxVect[i+1] == col_idx-1){ //bottomLeft
                    bottomLeftIdx = true;
                }
            }
        }
        return;
    }
}

void cellCount(int type, std::vector<std::vector<int>>& vect, int row_idx, int col_idx, int rows, int cols, std::vector<int>& idxVect, int &total){
    bool topIdx = false;
    bool leftIdx = false;
    bool bottomIdx = false;
    bool rightIdx = false;
    
    bool topRightIdx = false;
    bool topLeftIdx = false;
    bool bottomRightIdx = false;
    bool bottomLeftIdx = false;

    if((vect[row_idx][col_idx]) == 0){
        return;
    }

    if(type == 4){
        //check visited function must be called each time.
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(topIdx == false && row_idx-1 >= 0 && row_idx-1 < rows && col_idx >= 0 && col_idx < cols && (vect[row_idx-1][col_idx]) == 1){
            total++;
            // std::cout << "Row-Index: " << row_idx-1 << " Col-Index: " << col_idx << " Total: " << total << " Top" << std::endl;
            //adds index to vector
            idxVect.push_back(row_idx-1);
            idxVect.push_back(col_idx);
            cellCount(type, vect, row_idx-1, col_idx, rows, cols, idxVect, total);   //top
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(leftIdx == false && row_idx >= 0 && row_idx < rows && col_idx-1 >= 0 && col_idx-1 < cols && (vect[row_idx][col_idx-1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx << " Col-Index: " << col_idx-1 << " Total: " << total << " Left" << std::endl;
            idxVect.push_back(row_idx);
            idxVect.push_back(col_idx-1);
            cellCount(type, vect, row_idx, col_idx-1, rows, cols, idxVect, total);   //left
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(bottomIdx == false && row_idx+1 >= 0 && row_idx+1 < rows && col_idx >= 0 && col_idx < cols && (vect[row_idx+1][col_idx]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx+1 << " Col-Index: " << col_idx << " Total: " << total << " Bottom" << std::endl;
            idxVect.push_back(row_idx+1);
            idxVect.push_back(col_idx);
            cellCount(type, vect, row_idx+1, col_idx, rows, cols, idxVect, total);   //bottom
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(rightIdx == false && row_idx >= 0 && row_idx < rows && col_idx+1 >= 0 && col_idx+1 < cols && (vect[row_idx][col_idx+1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx << " Col-Index: " << col_idx+1 << " Total: " << total << " Right" << std::endl;
            idxVect.push_back(row_idx);
            idxVect.push_back(col_idx+1);
            cellCount(type, vect, row_idx, col_idx+1, rows, cols, idxVect, total);   //right
        }
        return;
    }
    else{
        //check visited function must be called each time.
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(topIdx == false && row_idx-1 >= 0 && row_idx-1 < rows && col_idx >= 0 && col_idx < cols && (vect[row_idx-1][col_idx]) == 1){
            total++;
            // std::cout << "Row-Index: " << row_idx-1 << " Col-Index: " << col_idx << " Total: " << total << " Top" << std::endl;
            //adds index to vector
            idxVect.push_back(row_idx-1);
            idxVect.push_back(col_idx);
            cellCount(type, vect, row_idx-1, col_idx, rows, cols, idxVect, total);   //top
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(leftIdx == false && row_idx >= 0 && row_idx < rows && col_idx-1 >= 0 && col_idx-1 < cols && (vect[row_idx][col_idx-1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx << " Col-Index: " << col_idx-1 << " Total: " << total << " Left" << std::endl;
            idxVect.push_back(row_idx);
            idxVect.push_back(col_idx-1);
            cellCount(type, vect, row_idx, col_idx-1, rows, cols, idxVect, total);   //left
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(bottomIdx == false && row_idx+1 >= 0 && row_idx+1 < rows && col_idx >= 0 && col_idx < cols && (vect[row_idx+1][col_idx]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx+1 << " Col-Index: " << col_idx << " Total: " << total << " Bottom" << std::endl;
            idxVect.push_back(row_idx+1);
            idxVect.push_back(col_idx);
            cellCount(type, vect, row_idx+1, col_idx, rows, cols, idxVect, total);   //bottom
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(rightIdx == false && row_idx >= 0 && row_idx < rows && col_idx+1 >= 0 && col_idx+1 < cols && (vect[row_idx][col_idx+1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx << " Col-Index: " << col_idx+1 << " Total: " << total << " Right" << std::endl;
            idxVect.push_back(row_idx);
            idxVect.push_back(col_idx+1);
            cellCount(type, vect, row_idx, col_idx+1, rows, cols, idxVect, total);   //right
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(topRightIdx == false && row_idx-1 >= 0 && row_idx-1 < rows && col_idx+1 >= 0 && col_idx+1 < cols && (vect[row_idx-1][col_idx+1]) == 1){
            total++;
            // std::cout << "Row-Index: " << row_idx-1 << " Col-Index: " << col_idx << " Total: " << total << " Top" << std::endl;
            //adds index to vector
            idxVect.push_back(row_idx-1);
            idxVect.push_back(col_idx+1);
            cellCount(type, vect, row_idx-1, col_idx+1, rows, cols, idxVect, total);   //topRight
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(topLeftIdx == false && row_idx-1 >= 0 && row_idx-1 < rows && col_idx-1 >= 0 && col_idx-1 < cols && (vect[row_idx-1][col_idx-1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx << " Col-Index: " << col_idx-1 << " Total: " << total << " Left" << std::endl;
            idxVect.push_back(row_idx-1);
            idxVect.push_back(col_idx-1);
            cellCount(type, vect, row_idx-1, col_idx-1, rows, cols, idxVect, total);   //topLeft
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(bottomRightIdx == false && row_idx+1 >= 0 && row_idx+1 < rows && col_idx+1 >= 0 && col_idx+1 < cols && (vect[row_idx+1][col_idx+1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx+1 << " Col-Index: " << col_idx << " Total: " << total << " Bottom" << std::endl;
            idxVect.push_back(row_idx+1);
            idxVect.push_back(col_idx+1);
            cellCount(type, vect, row_idx+1, col_idx+1, rows, cols, idxVect, total);   //bottomRight
        }
        checkVisited(idxVect, row_idx, col_idx, topIdx, leftIdx, bottomIdx, rightIdx, topRightIdx, topLeftIdx, bottomRightIdx, bottomLeftIdx, type);
        if(bottomLeftIdx == false && row_idx+1 >= 0 && row_idx+1 < rows && col_idx-1 >= 0 && col_idx-1 < cols && (vect[row_idx+1][col_idx-1]) == 1){
            total++;
            //adds index to vector
            // std::cout << "Row-Index: " << row_idx << " Col-Index: " << col_idx+1 << " Total: " << total << " Right" << std::endl;
            idxVect.push_back(row_idx+1);
            idxVect.push_back(col_idx-1);
            cellCount(type, vect, row_idx+1, col_idx-1, rows, cols, idxVect, total);   //bottomLeft
        }
        return;
    }
}

int main(int argc, char* argv[]){

    std::string fname = argv[1];
    int rows = std::stoi(argv[2]);
    int cols = std::stoi(argv[3]);
    int starting_row = std::stoi(argv[4]);
    int starting_col = std::stoi(argv[5]);
    int conn_type = std::stoi(argv[6]);


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


    //print out vector
    // for(int i = 0; i < rows; i++){
    //     for(int j = 0; j < cols; j++){
    //         std::cout << input_vector[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }


    int totalCells = 0;

    std::vector<int> idxVistedVec;


    cellCount(conn_type, input_vector, starting_row-1, starting_col-1, rows, cols, idxVistedVec, totalCells);

    std::cout << totalCells << std::endl;



    return 0;
}
