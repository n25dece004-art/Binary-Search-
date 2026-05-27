#include <bits/stdc++.h> 
using namespace std;

// 1. Tìm kiếm nhị phân cơ bản 
int binarySearch(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        else if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1; 
}

// 2. Tìm kiếm nhị phân cơ bản (Sử dụng Đệ quy)
int recursiveBinarySearch(const vector<int>& a, int l, int r, int x) {
    if (l > r) return -1;
    
    int m = l + (r - l) / 2;
    if (a[m] == x) return m;
    else if (a[m] < x) return recursiveBinarySearch(a, m + 1, r, x);
    else return recursiveBinarySearch(a, l, m - 1, x);
}

// 3. Tìm vị trí xuất hiện ĐẦU TIÊN của X
int firstPos(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) {
            res = m;     
            r = m - 1;   
        } else if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

// 4. Tìm vị trí xuất hiện CUỐI CÙNG của X
int lastPos(const vector<int>& a, int x) {
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) {
            res = m;     
            l = m + 1;   
        } else if (a[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    vector<int> a(n);
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << "\nMang SAU KHI SAP XEP (tang dan) de ap dung Binary Search:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    int x;
    cout << "Nhap gia tri X can tim: ";
    cin >> x;

    cout << "----------------------------------------\n";
    cout << "KET QUA TIM KIEM:\n";
    
    // 1. Chạy hàm lặp while
    int bsResult = binarySearch(a, x);
    if (bsResult != -1) 
        cout << "- [Co ban - Lanh while] Tim thay " << x << " tai chi so: " << bsResult << "\n";
    else 
        cout << "- [Co ban - Lanh while] Khong tim thay " << x << " trong mang.\n";

    // 2. Chạy hàm đệ quy
    int recResult = recursiveBinarySearch(a, 0, n - 1, x);
    if (recResult != -1) 
        cout << "- [De quy] Tim thay " << x << " tai chi so: " << recResult << "\n";
    else 
        cout << "- [De quy] Khong tim thay " << x << " trong mang.\n";

    // 3. Chạy hàm tìm vị trí đầu tiên
    int firstResult = firstPos(a, x);
    if (firstResult != -1) 
        cout << "- [Vi tri DAU TIEN] Cua " << x << " la chi so: " << firstResult << "\n";
    else 
        cout << "- [Vi tri DAU TIEN] Khong ton tai " << x << ".\n";

    // 4. Chạy hàm tìm vị trí cuối cùng
    int lastResult = lastPos(a, x);
    if (lastResult != -1) 
        cout << "- [Vi tri CUOI CUNG] Cua " << x << " la chi so: " << lastResult << "\n";
    else 
        cout << "- [Vi tri CUOI CUNG] Khong ton tai " << x << ".\n";
        
    cout << "----------------------------------------\n";

    return 0;
}