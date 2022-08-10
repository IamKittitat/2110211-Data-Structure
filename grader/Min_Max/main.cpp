#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int row,col,rValue;
    int rStart,cStart,rEnd,cEnd;
    int maxValue;
    cin >> row >> col;
    cin >> rValue;
    int matrix[row][col];
    int r[rValue][4];
    for(int i = 0 ; i < row; i++){
        for(int j = 0; j< col ; j++){
            cin >> matrix[i][j];
        }
    }
    for (int i=0;i<rValue;i++){
        for(int j =0; j<4 ; j++){
            cin >> r[i][j];
        }
    }

    for (int i =0 ; i<rValue;i++){
        rStart = r[i][0]-1;
        cStart = r[i][1]-1;
        rEnd = r[i][2]-1;
        cEnd = r[i][3]-1;
        maxValue = matrix[rStart][cStart];
        //cout << "CHECK" << rStart << " "  << cStart << " "  << rEnd << " " << cEnd << endl;
        if(rStart > rEnd || cStart > cEnd){
            cout << "INVALID" << endl;
        } else if((rStart > row-1 || cStart > col -1)){
            cout << "OUTSIDE" << endl;
        } else{
            rEnd = min(r[i][2]-1,row-1);
            cEnd = min(r[i][3]-1,col-1);
            for(int rIdx = rStart ; rIdx<=rEnd;rIdx++){
                for(int cIdx = cStart ; cIdx<=cEnd;cIdx++){
                    if(matrix[rIdx][cIdx] > maxValue){
                        maxValue = matrix[rIdx][cIdx];
                    }
                }
            }
            cout << maxValue << endl;
        }

    }
}
