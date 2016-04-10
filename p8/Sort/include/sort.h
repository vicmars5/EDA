#ifndef SORT_H
#define SORT_H


class Sort {
    public:
        float bubbleTime(int*, int);
        float insertTime(int*, int);
        float quickTime(int*, int, int);
        float mergeTime(int*, int, int, int);
        float selectTime(int*, int);
        float shellTime(int*, int);

    private:
        void bubble(int*, const int&);
        void insertSort(int*, const int&);
        void quick(int*, int, int);
        void mergeSort(int*, int, int, int);
        void mergeS(int*, int, int, int, int);
        void selectSort(int*, const int&);
        void shell(int*, const int&);

        void exchange(int& a, int& b);
        float getElapsedTimeInMs();

};

#endif // SORT_H
