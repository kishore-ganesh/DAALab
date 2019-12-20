#include<stdio.h>
#include<stdlib.h>

struct Item{
    float price, quantity;
    float ratio;
};

int itemComparator(const void* a, const void* b){
    Item* first = (Item*) a;
    Item* second = (Item*) b;
    if(first->ratio > second->ratio){
        return -1;
    }
    else{
        return 1;
    }
}

float min(float a, float b){
    return a < b ? a : b;
}
int main(){
    int N;
    scanf("%d", &N);
    struct Item items[N];
    for(int i = 0; i< N; i++){
        float price, quantity;
        scanf("%f%f", &price, &quantity);
        items[i] = {price, quantity};
    }
    float W = 0;
    scanf("%f", &W);
    for(int i = 0; i < N; i++){
        // printf("%f %f\n", items[i].price, items[i].quantity);
        items[i].ratio=items[i].price/items[i].quantity;
    }



    // WPrice/Quantity
    qsort(items, N, sizeof(Item), itemComparator);
    float w = 0;
    int p = 0;
    for(int i = 0; i < N && w<=W; i++){
        p+= min((W-w)/items[i].quantity, 1)*items[i].price;
        w+= min((W-w)/items[i].quantity, 1)*items[i].quantity;
    }
    printf("%d\n", p);
}