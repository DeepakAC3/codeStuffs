#include<iostream>
#include<ctime>
using namespace std;
void insertionSort(string &st){
    for (int i = 1; i < st.size(); i++) {
        char key = st[i];
        int j = i - 1;
        while (j >= 0 && st[j] > key) {
            st[j + 1] = st[j];
            j--;
        }
        st[j + 1] = key;
    }
}

int partition(string &st,int low,int high)
{

  int pivot=st[high];
 
  int i=(low-1);

  for(int j=low;j<=high;j++)
  {

    if(st[j]<pivot)
    {

      i++;
      swap(st[i],st[j]);
    }
  }
  swap(st[i+1],st[high]);
  return (i+1);
}
 

void quicksort(string &st,int low,int high)
{

  if(low<high)
  {


    int pi=partition(st,low,high);


    quicksort(st,low,pi-1);
    quicksort(st,pi+1,high);
  }
}


int main(){
    std::string st = "askodnaosidfnaoisdnoasidfnoiadsnfoiadnfiopasjdpoajspdjaspsodjapdfjsdpiipasjfpiajsf";
    std::string st1 = st;
    int size = st.size();
    clock_t start,end;
    start=clock();
    insertionSort(st);
    end=clock();
     double tt1=double(end-start)/double(CLOCKS_PER_SEC);
    cout<<tt1<<endl;
    clock_t start1,end1;
    start1 = clock();
    quicksort(st1,0,size-1);
    end1 = clock();
    double tt2 = double(end1-start1)/double(CLOCKS_PER_SEC);
    cout<<tt2<<endl;
    cout<<st;
    return 0;
}