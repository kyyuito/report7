#include <stdio.h>

void sortScores(int scores[], int size);
void printScores(int scores[], int size); //配列の要素を出力する関数

void sortScores(int scores[], int size){
    int number = 0; //配列の場所を記憶しておく
    int max ; //最大値を記憶しておく
    int index ; //最大値の場所を記憶しておく

    while((size - 1) - number){ //最後の要素はただ一つ決まるため大小判別は要らない
        max = scores[number];
        index  = number;

        for(int i=0; i < (size - number); i++){ //下記の動作より、ループ回数を減らさなければいけない
            if(max < scores[i + number]){ //numberをプラスすることで一周目に最大値を代入した配列の０を二周目には無視できる。以降の周回も同じ
                max = scores[i + number];
                index = i + number;
            }
            if(scores[i] < 0 || 100 < scores[i]){
                printf("WARNING:適切ではない要素が存在します。\n");
                printf("配列の%d番目の値が %d です。\n", i+1, scores[i]);
                number = size - 2;
                break;
            }
        }
        scores[index] = scores[number]; //最大値はmaxに保管しているため上書きしても大丈夫
        scores[number] = max;
        number += 1;
    }

    printScores(scores, size);
    
}

void printScores(int scores[], int size){
    printf("scores = ");
    for(int i=0; i < size; i++){
        printf("%d ", scores[i]);
    }
    printf("\n");
}

int main(){
    const int SIZE = 6; //定数として配列のサイズを宣言                          
    int scores[SIZE] = {100, 60, 70, 1000, 90, 80};
    //処理コード
    
    printf("元の配列↓\n");
    printScores(scores, SIZE);

    printf("並び替えた配列↓\n");
    sortScores(scores, SIZE);
    
    return 0;
}