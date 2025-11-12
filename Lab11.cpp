#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Node {
    public:
        Node(int val = 0) {
            value = val;
        }
        Node* mynext = nullptr;
        int get_value() {
            return value;
        }
        void set_value(int val) {
            value = val;
        }
        Node* next() {
            return mynext;
        }
        void set_next(Node* nextNode) {
            mynext = nextNode;
        }
    private:
        int value;
};

class LinkedList {
    public:
        LinkedList* next() {
            return mynext;
        }
        void set_next(LinkedList* nextlist) {
            mynext = nextlist;
        }
        int size() {
            int count = 0;
            Node* current = head;
            if (current == nullptr) {
                return 0;
            }
            while (current != nullptr) {
                count++;
                current = current->next();
            }
            return count;
        }
        void append(int val) {
            Node* nodey = new Node(val);
            if (head == nullptr) {
                head = nodey;
            }
            else {
                Node* current = head;
                while (current->next() != nullptr) {
                    current = current -> next();
                }
                current->set_next(nodey);
            }
        }
        void insert(int index, int val) {
            if (index >= size()) {
                cout << "Invalid index.";
            }
            else if (index == 0) {
                Node* temp = new Node(val);
                temp->set_next(head);
                head = temp;
            }
            else {
                int myin = 0;
                Node* current = head;
                while (myin != index - 1) {
                    current = current -> next();
                    myin++;
                }
                Node* temp = new Node(val);
                temp->set_next(current->next());
                current->set_next(temp);
            }
        }
        void set_value(int index, int val) {
            if (index >= size()) {
                cout << "Invalid index.";
            }
            else {
                int myin = 0;
                Node* current = head;
                while (myin != index) {
                    current = current -> next();
                    myin++;
                }
                current->set_value(val);
            }
        }
        int get_value(int index) {
            if (index >= size()) {
                cout << "Invalid index.";
                exit(1);
            }
            else {
                int myin = 0;
                Node* current = head;
                while (myin != index) {
                    current = current -> next();
                    myin++;
                }
                return current->get_value();
            }
        }
        void printList() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->get_value() << " ";
                current = current -> next();
            }
        }
        Node* get_head() {
            return head;
        }
        void set_head(Node* newhead) {
            head = newhead;
        }
    private:
        Node* head = nullptr;
        LinkedList* mynext = nullptr;
};

class Matrix {
    public:
        int size() {
            int count = 0;
            LinkedList* current = head;
            if (current == nullptr) {
                return 0;
            }
            while (current != nullptr) {
                count++;
                current = current->next();
            }
            return count;
        }

        LinkedList get_row(int index) {
            if (index >= size()) { // Matrix is square so only one size is required to check
                cout << "Invalid index." << endl;
                exit(1);
            }
            else {
                int myin = 0;
                LinkedList* current = head;
                while (myin != index) {
                    current = current -> next();
                    myin++;
                }
                return *current;
            }
        }
        void set_row(int index, LinkedList listy) {
            if (index >= size()) { // Matrix is square so only one size is required to check
                cout << "Invalid index." << endl;
            }
            else {
                int myin = 0;
                LinkedList* current = head;
                while (myin != index) {
                    current = current -> next();
                    myin++;
                }
                current->set_head(listy.get_head());
            }
        }
        int get_value(int index1, int index2) {
            if (index1 >= size()) { // Matrix is square so only one size is required to check
                cout << "Invalid index." << endl;
                exit(1);
            }
            else {
                int myin = 0;
                LinkedList* current = head;
                while (myin != index1) {
                    current = current -> next();
                    myin++;
                }
                return current->get_value(index2);
            }
        }
        void set_value(int index, int index2, int val) {
            if (index >= size()) {
                cout << "Invalid index.";
            }
            else {
                int myin = 0;
                LinkedList* current = head;
                while (myin != index) {
                    current = current -> next();
                    myin++;
                }
                current->set_value(index2, val);
            }
        }
        void append(LinkedList& listy) {
            LinkedList* mylist = new LinkedList(listy);
            if (head == nullptr) {
                head = mylist;
            }
            else {
                LinkedList* current = head;
                while (current->next() != nullptr) {
                    current = current -> next();
                }
                current->set_next(mylist);
            }
        }
        void insert(int index, LinkedList& listy) {
            LinkedList* temp = new LinkedList(listy);
            if (index >= size()) {
                cout << "Invalid index.";
            }
            else if (index == 0) {
                temp->set_next(head);
                head = temp;
            }
            else {
                int myin = 0;
                LinkedList* current = head;
                while (myin != index - 1) {
                    current = current -> next();
                    myin++;
                }
                temp->set_next(current->next());
                current->set_next(temp);
            }
        }
        void printMatrix() {
            LinkedList* current = head;
            while (current != nullptr) {
                current->printList();
                cout << endl;
                current = current -> next();
            }
        }

        Matrix operator+(Matrix matrix2) {
            Matrix matrix3;
            for (int i = 0; i < this->size(); i++) {
                LinkedList row;
                for (int j = 0; j < this->size(); j++) {
                    int sum = this->get_value(i, j) + matrix2.get_value(i, j);
                    row.append(sum);
                }
                matrix3.append(row);
            }
            return matrix3;
        }
        Matrix operator*(Matrix matrix2) {
            Matrix matrix3;
            int length = this->size();
            for (int i = 0; i < length; i++) {
                LinkedList myline;
                for (int j = 0; j < length; j++) {
                    int result = 0;
                    for (int k = 0; k < length; k++){
                        if (this->get_value(i,k) && matrix2.get_value(k,j)) {
                            result += this->get_value(i, k) * matrix2.get_value(k, j);
                        }
                    }
                    myline.append(result);
                }
                matrix3.append(myline);
            } 
            return matrix3;
        }

    private:
    LinkedList* head = nullptr;
};

// Task 1 Function
vector<Matrix> get_matrices() {
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;
    ifstream myfile(filename);
    if (!myfile) {
        cout << "Invalid file name." << endl;
        exit(1);
    }
    string mystr;
    Matrix matrix1;
    Matrix matrix2;
    string nstring;
    getline(myfile, nstring);
    int n = stoi(nstring);
    getline(myfile, nstring);

    int myint;
    while (getline(myfile, mystr)) {
        if (matrix1.size() < n) {
            LinkedList line;
            stringstream ss(mystr);
            string token;
            while (ss >> token) {
                line.append(stoi(token));
            }
            matrix1.append(line); 
        }
        else {
            LinkedList line;
            stringstream ss(mystr);
            string token;
            while (ss >> token) {
                line.append(stoi(token));
            }
            matrix2.append(line); 
        }
    };
    vector<Matrix> matrices;
    matrices.push_back(matrix1);
    matrices.push_back(matrix2);
    return matrices;
}

// Task 1 Function
void print_matrix(Matrix matrix) {
    int biggest = 0; 
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix.get_value(i, j) > biggest) {
                biggest = matrix.get_value(i, j);
            }
        }
    }
    int maxdigits = to_string(biggest).length();
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            int num = matrix.get_value(i, j);
            int numdigits = maxdigits - to_string(num).length();
            string zerostring = "";
            if (numdigits > 0) {
                for (int i = 0; i < numdigits; i++) {
                    zerostring += "0";
                }
            }
            cout << zerostring << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Task 3 Function
Matrix multiply_matrix(Matrix matrix1, Matrix matrix2) {
    Matrix matrix3;
    int length = matrix1.size();
    for (int i = 0; i < length; i++) {
        LinkedList myline;
        for (int j = 0; j < length; j++) {
            int result = 0;
            for (int k = 0; k < length; k++){
                if (matrix1.get_value(i,k) && matrix2.get_value(k,j)) {
                    result += matrix1.get_value(i, k) * matrix2.get_value(k, j);
                }
            }
            myline.append(result);
        }
        matrix3.append(myline);
    } 
    return matrix3;
}

// Task 4 Function
int diagnonal_sum(Matrix matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix.get_value(i, i);
        sum += matrix.get_value(i, n - 1 - i);
    }
    return sum;
}

// Task 5 Function
Matrix row_swap(Matrix matrix, int row1, int row2) {
    int n = matrix.size();
    if (row1 >= n || row2 >= n) {
        cout << "Invalid index." << endl;
        return matrix;
    }
    Matrix retmatrix;
    for (int i = 0; i < n; i++) {
        LinkedList newRow;
        int source = i;
        if (i == row1)  {
            source = row2;
        }
        else if (i == row2) { 
            source = row1;
        }
        // Copy the chosen row
        for (int j = 0; j < n; j++) {
            newRow.append(matrix.get_value(source, j));
        }
        retmatrix.append(newRow);
    }
    LinkedList temprow = retmatrix.get_row(row1);
    retmatrix.set_row(row1, retmatrix.get_row(row2));
    retmatrix.set_row(row2, temprow);
    return retmatrix;
}

// Task 6 Function
Matrix rotate_matrix(Matrix matrix) {
    Matrix retmatrix;
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        LinkedList row;
        for (int j = 0; j < n; j++) {
            row.append(matrix.get_value(n - 1 - j, i));
        }
        retmatrix.append(row);
    }
    return retmatrix;
}

// Task 6 Function
Matrix col_swap(Matrix matrix, int col1, int col2) {
    Matrix retmatrix;
    for (int i = 0; i < matrix.size(); i++) {
        LinkedList row;
        for (int j = 0; j < matrix.size(); j++) {
            int val = matrix.get_value(i, j);
            row.append(val);
        }
        retmatrix.append(row);
    }
    int n = matrix.size();
    if (col1 >= n || col2 >= n) {
        cout << "Invalid index." << endl;
        return matrix;
    }
    retmatrix = rotate_matrix(retmatrix);
    LinkedList temprow = retmatrix.get_row(col1);
    retmatrix.set_row(col1, retmatrix.get_row(col2));
    retmatrix.set_row(col2, temprow);
    retmatrix = rotate_matrix(retmatrix);
    retmatrix = rotate_matrix(retmatrix);
    retmatrix = rotate_matrix(retmatrix);
    return retmatrix;
}

// Task 7 Function
Matrix replace_val(Matrix matrix, int row, int col, int val) {
    Matrix retmatrix;
    for (int i = 0; i < matrix.size(); i++) {
        LinkedList row;
        for (int j = 0; j < matrix.size(); j++) {
            int myval = matrix.get_value(i, j);
            row.append(myval);
        }
        retmatrix.append(row);
    }
    int n = retmatrix.size();
    if (row >= n || col >= n) {
        cout << "Invalid Index." << endl;
        return matrix;
    }
    retmatrix.set_value(row, col, val);
    return retmatrix;
}

int main() { 
    // Question 1
    cout << "-----------------------------------------" << endl << endl;
    cout << "Task 1: Read values from file and print as matrices: " << endl;
    vector<Matrix> matrices = get_matrices();
    Matrix matrix1 = matrices[0];
    Matrix matrix2 = matrices[1];
    cout << "Matrix 1:" << endl;
    print_matrix(matrix1);
    cout << "Matrix 2:" << endl;
    print_matrix(matrix2);
    cout << "-----------------------------------------" << endl << endl;
    
    // Question 2
    cout << "Task 2: Addition Matrix:" << endl;
    print_matrix(matrix1 + matrix2);
    cout << "-----------------------------------------" << endl << endl;

    // Question 3
    cout << "Task 3: Multiplication Matrix:" << endl;
    matrix1 = matrices[0];
    matrix2 = matrices[1];
    print_matrix(matrix1 * matrix2);
    cout << "-----------------------------------------" << endl << endl;


    // Question 4
    matrix1 = matrices[0];
    cout << "Task 4: Diagonal Sum of Matrix " << endl << endl;
    cout << "Diagonal Sum of Matrix 1: " << endl;
    cout << diagnonal_sum(matrix1) << endl << endl;
    cout << "-----------------------------------------" << endl << endl;

    // Question 5
    matrix1 = matrices[0];
    cout << "Task 5: Matrix with swapped rows: " << endl;
    cout << "Matrix 1 with rows 1 and 3 swapped: " << endl;
    cout << "Initial: " << endl;
    print_matrix(matrix1);
    cout << "Swapped: " << endl;
    print_matrix(row_swap(matrix1, 1, 3));
    cout << "-----------------------------------------" << endl << endl;

    // Question 6
    matrix1 = matrices[0];
    cout << "Task 6: Matrix with swapped columns: " << endl << endl;
    cout << "Matrix 1 with columns 1 and 3 swapped: " << endl;
    cout << "Initial: " << endl;
    print_matrix(matrix1);
    cout << "Swapped: " << endl;
    print_matrix(col_swap(matrix1, 1, 3));
    cout << "-----------------------------------------" << endl << endl;

    // Question 7
    matrix1 = matrices[0];
    cout << "Task 7: Function to replace matrix value from given row, column, and new value" << endl << endl;
    cout << "Matrix 1 with row 0, column 2 set to 500: " << endl;
    print_matrix(replace_val(matrix1, 0, 2, 500));

    cout << "In the case of invalid bounds, initial matrix is returned." << endl << endl;
}
