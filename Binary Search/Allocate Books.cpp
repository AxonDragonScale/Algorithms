// https://www.interviewbit.com/problems/allocate-books/
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

// Given an array books where books[i] is the number of pages in book i and number of students n.
// You have to allocate books to n students so that maximum number of pages alloted to a student is minimum. A book will
// be allocated to exactly one student. Each student has to be allocated at least one book. Allotment should be in
// contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
// NOTE: Return -1 if a valid assignment is not possible

bool canAllocate(vector<int> &books, int n, int maxPages) {
    int pos = 0;
    for (int i = 0; i < n; i++) {
        int curPages = 0;
        while (pos < books.size() && curPages + books[pos] <= maxPages) {
            curPages += books[pos++];
        }
        if (pos == books.size()) return true;
    }
    return false;
}

// books[i] is the number of pages in book i
// n is the number of students
int Solution::books(vector<int> &books, int n) {
    if (books.size() < n) return -1;

    int totalPages = 0;
    for (int i : books) {
        totalPages += i;
    }

    int min = 0, max = totalPages;
    while (min < max) {
        int mid = min + (max - min) / 2;
        if (canAllocate(books, n, mid)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    return min;  // or max
}
