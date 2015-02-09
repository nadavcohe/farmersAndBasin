// this question is from here
// http://www.careercup.com/question?id=15380670
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> matrix_row;
typedef vector< matrix_row > matrix;

void print_mat(matrix mat){
    for (int i = 0; i < mat.size() ; i++){
        for (int g = 0 ; g < mat[0].size() ;g++){
            cout << mat[i][g] << " ";
        }
        cout << endl;
    }
}

class game{
    private:
        matrix mat;
        matrix markerMat;
        int n;
        int max_group;
        matrix_row group_count;
    public:
        game(matrix &init_mat,int init_n){
            if (init_n<1){
                cerr << "error";
            }
            n=init_n;
            mat=init_mat;
            markerMat=init_mat;
            max_group = -1;
        };
        
        void solve_game(){
            for (int i = 0; i < mat.size() ; i++){
                for (int g = 0 ; g < mat[0].size() ;g++){
                    run_down(i,g);
                }
            }
            //i need to sort here
            sort(group_count.begin(),group_count.end());
            for (int i = group_count.size()-1 ; i >= 0 ;i--){
                cout << group_count[i] << " ";
            }
            cout << endl;
            cout << "draw of basins map:\n";
            print_mat(markerMat);
        };
        
        int run_down(int x,int y){
            if (markerMat[x][y]<0)
                return markerMat[x][y];
            int best_x,best_y;
            best_down(x,y,best_x,best_y);
            if ((best_x!=-1) && (best_y!=-1)){
                markerMat[x][y] = run_down(best_x,best_y);
                group_count[-markerMat[x][y]-1]++;
            }else{
                markerMat[x][y] = max_group--;
                group_count.push_back(1);
            }
            return (markerMat[x][y]);
        };
        
        void best_down(int x,int y,int &best_x,int &best_y){
            best_x=-1;
            best_y=-1;
            int lowset=mat[x][y];
            int value=mat[x][y];
            check_next(value,x-1,y,lowset,best_x,best_y);
            check_next(value,x+1,y,lowset,best_x,best_y);
            check_next(value,x,y-1,lowset,best_x,best_y);
            check_next(value,x,y+1,lowset,best_x,best_y);
        };
        
        bool check_next(int value,int next_x,int next_y,int &lowset,int &best_x,int &best_y){
                if ((0<=next_x && next_x<n) && (0<=next_y && next_y<n)){
                    if ((value > mat[next_x][next_y]) && (lowset > mat[next_x][next_y] )){
                        best_x = next_x;
                        best_y = next_y;
                        lowset= mat[next_x][next_y];
                        return true;
                    }
                }
                return false;
        };
};

int main(){
    int n;
    cin >> n;
    if (n < 1){
        cerr << "error";
        return 0;
    }
    matrix mat;
    matrix_row row;
    int value;
    for (int i = 0; i < n ; i++){
        row.clear();
        for (int g = 0 ; g < n;g++){
            cin >> value;
            // check if negative
            row.push_back(value);
        }
        mat.push_back(row);
    }
    game a_game(mat,n);
    a_game.solve_game();
    
    return 0;
}