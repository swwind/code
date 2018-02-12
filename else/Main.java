import java.util.Scanner;

public class Main {

    public static void main(String args[]){
        Scanner sr = new Scanner(System.in);
        int n=sr.nextInt();
        int a[]=new int[n];
        for (int i = 0; i < n; i++) {
          System.out.println(i);
          a[i]=sr.nextInt();
        }
        new QuickSort().quickSort(a, 0, n-1);
        for (int i = 0; i < a.length; i++) {         
            System.out.print(a[i]+" ");
        }
    }           
}
class QuickSort{
    public void quickSort(int a[],int left,int right){
        if(left<right){
            int mid=getMiddle(a,left,right);
            quickSort(a,0,mid-1);
            quickSort(a, mid+1, right);
        }
    }

    private void swap(int a,int b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }

    private int getRandom(int left,int right){
        int size=right-left+1;
        int index=left+(int)(Math.random()*100000)%size;
        return index;
    }
    private int getMiddle(int[] a, int left, int right) {
        int index=getRandom(left, right);
        swap(a[left],a[index]);
        int temp=a[left];
        while(left<right){
            while(left<right&&temp<=a[right]){
                right--;
            }
            a[left]=a[right];
            while(left<right&&temp>=a[left]){
                left++;
            }
            a[right]=a[left];
        }
        a[left]=temp;
        return left;
    }
}