//分区函数
int partition(vector<int> & arr,int left,int right){
    int pivotValue = arr[right];
    int sortIndex = left;
    for(int i = left;i<right;i++){
        if(arr[i]<pivotValue){
            swap(arr[i],arr[sortIndex]);
            sortIndex +=1;
        }
    }
    swap(arr[i],arr[sortIndex]);
    return sortIndex;
}

void quickSort(vecot<int> &arr,int left,int right){//注意快排的参数一定有数组，起始端和末尾端
    if(left>right)
        return;
    else{
        int index = partition(srr,left,right);
        quickSort(arr,left,index-1);
        quickSort(arr,index+1,right);
    }
}

void sort(vector<int> &vi){
    quickSort(vi,0,vi.size()-1);
}

int main()
{
    int a[] = {3,5,7,9,2,3,1,0,7,5,4};  
    vector<int> va(a, a+11);  
  
    cout<<"Before quicksort:\n";  
    for(auto x:va)  
        cout<<x<<" ";  
    cout<<endl;  
  
    qSort(va);  
  
    cout<<"After quicksort:\n";  
    for(auto x:va)  
        cout<<x<<" ";  
    cout<<endl;  
    system("pause");  
    return 0; 

}