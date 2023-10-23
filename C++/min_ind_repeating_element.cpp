#include <iostream>
using namespace std;

int find_min_ind_repeating_ele(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    int size=0;
    cout<<"How many elements do you want to enter?"<<endl;
    cin>>size;
    cout<<"Enter elements: "<<endl;
    int Mainarr[size];
    for(int i=0;i<size;i++){
        cin>>Mainarr[i];
    }
    int result = find_min_ind_repeating_ele(Mainarr,size);
    if(result!=-1){
        cout<<"Minimum index of repeating element is: "<<result<<endl;
    }
    else{
        cout<<"There's no repeating element in array"<<endl;
    }
    return 0;
}