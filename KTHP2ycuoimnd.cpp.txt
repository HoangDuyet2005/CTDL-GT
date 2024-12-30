void chenSauSinhVienMax(TRO& L, SINHVIEN X) {
    if (L == NULL) {
        cout << "Danh sách rỗng, không thể tìm sinh viên lớn nhất." << endl;
        return;
    }

    TRO maxNode = L; // Giả định sinh viên đầu tiên có dtk lớn nhất
    TRO Q = L;
    while (Q != NULL) {
        if (Q->infor.dtk > maxNode->infor.dtk) {
            maxNode = Q;
        }
        Q = Q->next;
    }

    // Tạo nút mới để chèn
    TRO P = new Node;
    P->infor = X;      // Gán thông tin sinh viên mới
    P->next = maxNode->next; // Liên kết nút mới
    maxNode->next = P;  // Chèn nút mới vào sau maxNode

    cout << "Đã chèn sinh viên mới sau sinh viên có điểm lớn nhất." << endl;
}
============================================================================
void tinhTBCSinhVienB1(TRO L) {
    if (L == NULL) {
        cout << "Danh sách rỗng, không thể tính TBC." << endl;
        return;
    }

    TRO Q = L;
    double tongDTK = 0.0;
    int dem = 0;

    while (Q != NULL) {
        SINHVIEN X = Q->infor;
        if (strcmp(X.hoten, "b1") == 0) { // So sánh tên
            tongDTK += X.dtk; // Cộng dồn điểm
            dem++;            // Đếm số sinh viên có tên "b1"
        }
        Q = Q->next; // Chuyển sang nút tiếp theo
    }

    if (dem == 0) {
        cout << "Không có sinh viên nào tên 'b1' trong danh sách." << endl;
    } else {
        double tbc = tongDTK / dem;
        cout << "TBC điểm tổng kết của các sinh viên tên 'b1': " << tbc << endl;
    }
}
