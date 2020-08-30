#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <bits/stdc++.h>
#include <mainwindow.h>
using namespace std;

extern QString out_box;
extern QString problems;
bool inverseM( vector<double>&resultOut)
{
    double temp[16], det; //for cofactors
    int i;

    //computing cofactors using diagnols for 3X3 matrix from the original 4X4
    temp[0] = (resultOut[5] * resultOut[10] * resultOut[15]) - (resultOut[5] * resultOut[11] * resultOut[14]) - (resultOut[9] * resultOut[6] * resultOut[15]) + (resultOut[9] * resultOut[7] * resultOut[14]) + (resultOut[13] * resultOut[6] * resultOut[11]) - (resultOut[13] * resultOut[7] * resultOut[10]);
    temp[2] = (resultOut[1] * resultOut[6] * resultOut[15]) - (resultOut[1] * resultOut[7] * resultOut[14]) - (resultOut[5] * resultOut[2] * resultOut[15]) + (resultOut[5] * resultOut[3] * resultOut[14]) + (resultOut[13] * resultOut[2] * resultOut[7]) - (resultOut[13] * resultOut[3] * resultOut[6]);
    temp[5] = (resultOut[0] * resultOut[10] * resultOut[15]) - (resultOut[0] * resultOut[11] * resultOut[14]) - (resultOut[8] * resultOut[2] * resultOut[15]) + (resultOut[8] * resultOut[3] * resultOut[14]) + (resultOut[12] * resultOut[2] * resultOut[11]) - (resultOut[12] * resultOut[3] * resultOut[10]);
    temp[7] = (resultOut[0] * resultOut[6] * resultOut[11]) - (resultOut[0] * resultOut[7] * resultOut[10]) - (resultOut[4] * resultOut[2] * resultOut[11]) + (resultOut[4] * resultOut[3] * resultOut[10]) + (resultOut[8] * resultOut[2] * resultOut[7]) - (resultOut[8] * resultOut[3] * resultOut[6]);
    temp[8] = (resultOut[4] * resultOut[9] * resultOut[15]) - (resultOut[4] * resultOut[11] * resultOut[13]) - (resultOut[8] * resultOut[5] * resultOut[15]) + (resultOut[8] * resultOut[7] * resultOut[13]) + (resultOut[12] * resultOut[5] * resultOut[11]) - (resultOut[12] * resultOut[7] * resultOut[9]);

    temp[10] = (resultOut[0] * resultOut[5] * resultOut[15]) - (resultOut[0] * resultOut[7] * resultOut[13]) - (resultOut[4] * resultOut[1] * resultOut[15]) + (resultOut[4] * resultOut[3] * resultOut[13]) + (resultOut[12] * resultOut[1] * resultOut[7]) - (resultOut[12] * resultOut[3] * resultOut[5]);
    temp[13] = (resultOut[0] * resultOut[9] * resultOut[14]) - (resultOut[0] * resultOut[10] * resultOut[13]) - (resultOut[8] * resultOut[1] * resultOut[14]) + (resultOut[8] * resultOut[2] * resultOut[13]) + (resultOut[12] * resultOut[1] * resultOut[10]) - (resultOut[12] * resultOut[2] * resultOut[9]);



    temp[1] = (-resultOut[1] * resultOut[10] * resultOut[15]) + (resultOut[1] * resultOut[11] * resultOut[14]) + (resultOut[9] * resultOut[2] * resultOut[15]) - (resultOut[9] * resultOut[3] * resultOut[14]) - (resultOut[13] * resultOut[2] * resultOut[11]) + (resultOut[13] * resultOut[3] * resultOut[10]);
    temp[3] = (-resultOut[1] * resultOut[6] * resultOut[11]) + (resultOut[1] * resultOut[7] * resultOut[10]) + (resultOut[5] * resultOut[2] * resultOut[11]) - (resultOut[5] * resultOut[3] * resultOut[10]) - (resultOut[9] * resultOut[2] * resultOut[7]) + (resultOut[9] * resultOut[3] * resultOut[6]);
    temp[4] = (-resultOut[4] * resultOut[10] * resultOut[15]) + (resultOut[4] * resultOut[11] * resultOut[14]) + (resultOut[8] * resultOut[6] * resultOut[15]) - (resultOut[8] * resultOut[7] * resultOut[14]) - (resultOut[12] * resultOut[6] * resultOut[11]) + (resultOut[12] * resultOut[7] * resultOut[10]);
    temp[6] = (-resultOut[0] * resultOut[6] * resultOut[15]) + (resultOut[0] * resultOut[7] * resultOut[14]) + (resultOut[4] * resultOut[2] * resultOut[15]) - (resultOut[4] * resultOut[3] * resultOut[14]) - (resultOut[12] * resultOut[2] * resultOut[7]) + (resultOut[12] * resultOut[3] * resultOut[6]);
    temp[9] = (-resultOut[0] * resultOut[9] * resultOut[15]) + (resultOut[0] * resultOut[11] * resultOut[13]) + (resultOut[8] * resultOut[1] * resultOut[15]) - (resultOut[8] * resultOut[3] * resultOut[13]) - (resultOut[12] * resultOut[1] * resultOut[11]) + (resultOut[12] * resultOut[3] * resultOut[9]);

    temp[11] = (-resultOut[0] * resultOut[5] * resultOut[11]) + (resultOut[0] * resultOut[7] * resultOut[9]) + (resultOut[4] * resultOut[1] * resultOut[11]) - (resultOut[4] * resultOut[3] * resultOut[9]) - (resultOut[8] * resultOut[1] * resultOut[7]) + (resultOut[8] * resultOut[3] * resultOut[5]);
    temp[12] = (-resultOut[4] * resultOut[9] * resultOut[14]) + (resultOut[4] * resultOut[10] * resultOut[13]) + (resultOut[8] * resultOut[5] * resultOut[14]) - (resultOut[8] * resultOut[6] * resultOut[13]) - (resultOut[12] * resultOut[5] * resultOut[10]) + (resultOut[12] * resultOut[6] * resultOut[9]);
    temp[14] = (-resultOut[0] * resultOut[5] * resultOut[14]) + (resultOut[0] * resultOut[6] * resultOut[13]) + (resultOut[4] * resultOut[1] * resultOut[14]) - (resultOut[4] * resultOut[2] * resultOut[13]) - (resultOut[12] * resultOut[1] * resultOut[6]) + (resultOut[12] * resultOut[2] * resultOut[5]);
    temp[15] = (resultOut[0] * resultOut[5] * resultOut[10]) - (resultOut[0] * resultOut[6] * resultOut[9]) - (resultOut[4] * resultOut[1] * resultOut[10]) + (resultOut[4] * resultOut[2] * resultOut[9]) + (resultOut[8] * resultOut[1] * resultOut[6]) - (resultOut[8] * resultOut[2] * resultOut[5]);

    //compute the determinant
    det = resultOut[0] * temp[0] + resultOut[1] * temp[4] + resultOut[2] * temp[8] + resultOut[3] * temp[12];

    //check if inverse exists for matrix
    if (det == 0)
    {
        for (i = 0; i < 16; i++)
        {
            resultOut[i] =  0;
        }
        return false;
    }

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
    {
        resultOut[i] = temp[i] * det;
    }
    return true;
}
int parse(string path )
{
    vector <vector<double>> matrices; //storing all matrices
    vector<double> invalidMatrix(16,0.0);//Default Matrix for when a matrix contains invalid data
    vector<int> problematic_matrices; //keeps track of matrices with issues
    string value;// for storing one matrix while reading csv

    int num_matrices = 0;
    int line_num = 1;
    bool test = path.substr(path.find_last_of(".") + 1) != "csv";

    if(path.substr(path.find_last_of(".") + 1) != "csv")
    {
        problems = "Error input is not a csv file!";

        return 0;
    }
    ifstream file(path);
    while (file.good())
    {
        getline(file, value );
        stringstream check1(value); //a stringstream for spliting based on , delimitter
        string intermediate; //used for storing result of spliting based on , delimitter
        vector <double> curr_matrix; //currmatrix being generated to push back into the collection of matrices

        int i = 0;//index of current matrix


        while(getline(check1, intermediate, ',')) //split current line by , and store results into intermediate
            {
                try //convert current cell to double else raise and exception break and store this as default martix and mark this as a problematic matrix.
                {
                    curr_matrix.push_back (stod(intermediate));
                    i++;
                }
                catch(exception e)
                {
                    break;
                }
            }
        if (i != 16) //if we didnt get 16 valid numbers then we mark this as problematic
            {
                matrices.push_back(invalidMatrix);
                problematic_matrices.push_back(line_num);
            }
            else //otherwise increase num_matrices which keeps track of valid matrices coverter nad appen this to the results.
            {
                num_matrices++;
                matrices.push_back((curr_matrix));
            }
            line_num++;//for keeping track of overall matrix lines from original file
    }
    if(num_matrices == 0) // No valid martices in file or its is empty
    {
        problems = " \The File either has no valid martices or is empty!";
        return 0;
    }
    matrices.pop_back();//eof line emitted

    vector <double> curr_temp;
    for(int i = 0; i < matrices.size();i++)
    {
        inverseM(matrices[i]);//find all inverses
    }

    ofstream myfile; //open the output file
    string out_fp = out_box.toLocal8Bit().constData();
    myfile.open( out_fp+ "/output.csv"); // add the output file if it doesnt exsit or create it.

    //the for loop writes this info as a comma seperated list for the output
    for(int i = 0; i<matrices.size();i++)
    {
        string s;
        for(int j = 0 ; j < 16; j ++)
        {
            s+= to_string(matrices[i][j])  +" , ";
        }
        s+= "\n";
        myfile<<s;
    }

    //tells user if any matrices had issues.
    if(problematic_matrices.size() > 1)
    {
        problems = "Matrices with issues : \n";

        for(int i = 0; i < problematic_matrices.size()-1;i++)
        {
            problems += QString::number(problematic_matrices[i])+"\n";
            cout<<problematic_matrices[i];
        }

    }
    return num_matrices;
}
