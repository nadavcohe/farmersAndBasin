//question from :
// https://www.hackerrank.com/challenges/predicting-house-prices
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<float> matrix_row;
typedef vector<matrix_row > matrix;

matrix matrix_malt(matrix &a,matrix &b){
    matrix c;
    matrix_row c_row;
    float cur_sum;
    for (int k=0;k<b[0].size();k++){
        c_row.clear();
        for (int i=0;i<a.size();i++){
            cur_sum=0;
            for (int g=0;g<a[0].size();g++){
                cur_sum+=a[i][g]*b[g][i];
            }
            c_row.push_back(cur_sum);
        }
        c.push_back(c_row);
    }
    return(c);   
}

matrix matrix_maltT(matrix &a,matrix &b){
    matrix c;
    matrix_row c_row;
    float cur_sum;
    for (int k=0;k<b[0].size();k++){
        c_row.clear();
        for (int i=0;i<a[0].size();i++){
            cur_sum=0;
            for (int g=0;g<a.size();g++){
                cur_sum+=a[g][i]*b[g][k];
            }
            c_row.push_back(cur_sum);
        }
        c.push_back(c_row);
    }
    return(c);   
}


void print_mat(matrix a){
    for (int i=0;i<a.size();i++){
        for (int g=0;g<a[0].size();g++){
            cerr << a[i][g] << "\t";
        }
        cerr << endl;
    }
}

float calc_pred(matrix_row x,matrix_row theta){
    float res=0;
    for (int i=0;i<x.size();i++){
        res+=x[i]*theta[i];
    }
    return res;
}

matrix_row learn_data(matrix x,matrix_row y){
    float sum_of_errors;
    matrix_row theta(x[0].size(),0.25);
    matrix_row theta_temp(x[0].size(),0.25);
    for (int itr=0;itr < 400 ; itr++){
        for (int g=0;g<x[0].size();g++){
            sum_of_errors=0;
             for (int i=0;i<x.size();i++){
                 sum_of_errors+=(calc_pred(x[i],theta_temp) - y[i]) * x[i][g];
             }
            theta[g]-=(sum_of_errors*((0.15)/x.size()));
        }
        theta_temp=theta;
       // cerr << itr << "\t";
    }
    
    return(theta_temp);
}


int main() {
    // init of data
    int fetures,learn_n;
    cin >> fetures ;
    cin >> learn_n;
    matrix learn_set;
    matrix_row y_set;
    float input;
    matrix_row input_row;
    for (int i=0 ; i<learn_n;i++){
        input_row.clear();
        for (int g =0; g < fetures;g++){
            cin >> input;
            input_row.push_back(input);//learn_set[i][g];
        }
        cin >> input;
        y_set.push_back(input);
        input_row.push_back(1);
        learn_set.push_back(input_row);
    }
    int test_n;
    cin >> test_n;
    matrix test_set;
    for (int i=0 ; i<test_n;i++){
        input_row.clear();
        for (int g =0; g < fetures;g++){
            cin >> input;
            input_row.push_back(input);//learn_set[i][g];
        }
        input_row.push_back(1);
        test_set.push_back(input_row);
    }
    //end of init of data
    matrix_row W = learn_data(learn_set,y_set);
    matrix WW;
    WW.push_back(W);
    //cout << "results";
    float res;
    for (int g=0;g<test_set.size();g++){
        res=0;
        for (int i=0;i<test_set[0].size();i++)
            res+=test_set[g][i]*W[i];
        cout << res << endl;
    }
    return 0;
}
