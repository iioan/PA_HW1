#include <cstdint>
#include <fstream>
#include <vector>

using namespace std;

/*
 * Cauta maximul dintr-un vector
 */
long long FindMax(vector<long long> a) {
    long long max = 0LL;
    for (auto elem : a) {
        if (elem > max) max = elem;
    }
    return max;
}

/*
 * Calculeaza suma elementelor din vector
 */
long long GetSum(vector<long long> a) {
    long long sum = 0LL;
    for (auto elem : a) {
        sum += elem;
    }
    return sum;
}

/*
 * Calculeaza numarul de feriboturi folosite,
 * care au capacitatea limita 'capacity'
 */
int FindMinCost(vector<long long> cars, long long capacity) {
    int ferryboats = 1;
    long long weight = 0LL;
    for (auto car : cars) {
            weight += car;
            if (weight > capacity) {
            weight = car;
            ferryboats++;
        }
    }
    return ferryboats;
}

/*
 * Cauta costul minim, folosind K feriboturi
 */
long long Feribot(vector<long long> cars, int K) {
    long long left = FindMax(cars);
    long long right = GetSum(cars);
    long long middle = 0LL;
    while (left <= right) {
        middle = (left + right) / 2;
        int k = FindMinCost(cars, middle);
        if (k <= K) right = middle - 1;
        else
            left = middle + 1;
    }
    return left;
}

/*
 * Citeste elementele unui vector si il returneaza
 */
vector<long long> ReadVector(istream &is, int size) {
    vector<long long> vec(size);
    for (auto &num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");

    int n, ferryboats;
    fin >> n >> ferryboats;
    auto cars = ReadVector(fin, n);
    auto res = Feribot(cars, ferryboats);

    fout << res << "\n";
    return 0;
}
