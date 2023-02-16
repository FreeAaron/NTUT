#include <iostream>
using namespace std;

// Define an empty virtual function to be implemented by derived classes
class Compute {
public:
    virtual void func() {} // Empty virtual function
    virtual void print() = 0; // Pure virtual function
};

// Declare a private integer variable
int _size;

// Create a template class that takes an integer or float array and its size
template <class T>
class AbstractData {
public:
    AbstractData(int size, T score[]) {
        _size = size;
        _score = new T[size];
        for (int i = 0; i < size; i++) {
            _score[i] = score[i];
        }
    }

    // Compute the mean value of the data and return it
    T mean() {
        T mValue = 0;
        for (int i = 0; i < _size; i++) {
            mValue += _score[i];
        }
        return mValue / _size;
    }

private:
    T* _score;
    int _size;
};

// Define a class that initializes _size and _score in the constructor
class Data {
public:
    Data(int size) {
        _size = size;
        _score = new int[size];
        for (int i = 0; i < _size; i++) {
            _score[i] = 80 + 2 * i;
        }
    }

    // Compute the mean value of the data and return it
    int mean() {
        int mValue = 0;
        for (int i = 0; i < _size; i++) {
            mValue += _score[i];
        }
        return mValue / _size;
    }

private:
    int* _score;
    int _size;
};

// Define a class that takes two instances of AbstractData and Data
class Group : public Compute {
public:
    Group(int size, int score[]) {
        data1 = new AbstractData<int>(size, score);
        data2 = new Data(size);
    }

    // Compare the mean value of data 1 and data 2 and return false if data 1's mean value is greater than data 2's, true otherwise
    bool lessThan() {
        if (data1->mean() > data2->mean()) {
            return false;
        } else {
            return true;
        }
    }

    // Output the mean values of data 1 and data 2
    void print() {
        cout << "data set 1: " << data1->mean() << endl;
        cout << "data set 2: " << data2->mean() << endl;
    }

private:
    AbstractData<int>* data1;
    Data* data2;
};

int main() {
    int size = 5;
    int score[] = {90, 80, 85, 88, 86};
    Group g(5, score);
    Data data(8);
    cout << data.mean() << endl;

    // Call the print function of Group and output the mean values of data 1 and data 2
    g.print();

    // Call the lessThan function of Group and output the result
    cout << g.lessThan();

    return 0;
}
