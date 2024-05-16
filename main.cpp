#include <iostream>
using namespace std;

// Merge Sort là một thuật toán sắp xếp mạnh mẽ với độ phức tạp thời gian
//𝑂
//(
//𝑛
//log
//⁡
//𝑛
//)
//O(nlogn) ổn định, thích hợp cho các ứng dụng yêu cầu tính ổn định và hiệu quả trên dữ liệu lớn hoặc dữ liệu ngoài bộ nhớ.
// Tuy nhiên, nó đòi hỏi bộ nhớ phụ thêm và có thể không hiệu quả bằng các thuật toán sắp xếp khác khi xử lý các dãy dữ liệu nhỏ hoặc khi bộ nhớ bị giới hạn.
// Việc chọn thuật toán sắp xếp phụ thuộc vào các yêu cầu cụ thể của ứng dụng và tài nguyên hệ thống có sẵn.

void mergeSort(int arr[], int left, int middle, int right) {
    // bên trái là đi từ left đến middle
    // bên phải là đi từ middle + 1 đến right

    int length_left = middle - left + 1; // chiều dài của mảng bên trái
    int length_right = right - middle;// chiều dài cuẩ m b phải

    // tạo ra mảng tạm thời trái phải
    int arr_left[length_left];
    int arr_right[length_right];

    for (int i = 0; i < length_left; ++i) {
        arr_left[i] = arr[left+i];
    }
    for(int i = 0; i < length_right; i++) {
        arr_right[i] = arr[middle+1+i];
    }
    // gộp/ trộn hai mảng lại theo quy tắc phần tử nhỏ hơn được thêm vào mảng trước
    int i1 = 0; // vị trí hiện tại của phaàn tử mảng của bên trái
    int i2 = 0; // vị trí h tại của b phải
    int k = left;
    while(i1 < length_left && i2 < length_right) {
        if(arr_left[i1] <= arr_right[i2]) {
            arr[k] = arr_left[i1];
            i1++;
        } else {
            arr[k] = arr_right[i2];
            i2++;
        }
        k++;
    }

    // copy của những phần tử của mảng bên trái chưa được đưa vào,
    // khi mảng bên phải đax được đưa vào hết.
    while (i1 < length_left) {
        arr[k] = arr_left[i1];
        i1++;
        k++;
    }

    while (i2 < length_right) {
        arr[k] = arr_right[i2];
        i2++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int middle = (right + left)/2; // tìm vị trí giữa mảng

        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);

        mergeSort(arr, left, middle, right);
    }
}


int main() {
    int n;
    cout << "Nhap vao so luong phan tu: " << endl;
    cin >> n;
    int arr[n];
    cout << "Nhap vao tung phan tu cua mang: ";
    for (int i = 0; i < n; ++i) {
       cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Mang sau khi da duoc sap xep la: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}