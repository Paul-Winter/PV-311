#include <iostream>
#include <iterator>
#include <vector>

template <typename Iterator>
double average(Iterator first, Iterator last)
{
    int n = 0;
    double sum = 0;

    while (first != last) {
        sum += *first++;
        ++n;
    }

    return sum / n;
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4 };
    std::cout << average(v.begin(), v.end());
}





template<typename T>
void f1(const T& a, const T& b, T& x, bool& res)
{
    if (a == 0)
    {
        res = false;
        return;
    }

    res = true;
    x = -b / a;
}

template<typename T>
void f2(const T& a, const T& b, const T& c, T& x1, T& x2, bool& res)
{
    const T D = b * b - 4 * a * c;

    if (D < 0)
    {
        res = false;    // нет корней
        return;
    }

    res = true;
    x1 = (-b - sqrtf(D)) / (2 * a);
    x2 = (-b + sqrtf(D)) / (2 * a);
}





namespace cf {

    template<class T>
    T max(T left, T right) {
        return left > right ? left : right;
    }

}

int main() {

    int iNum = cf::max(5, 6);
    double dNum = cf::max(3.5, 1.2);
    char cNum = cf::max('a', 'b');
    long lNum = cf::max(10L, 15L);

    std::cout << "int " << iNum << std::endl;
    std::cout << "double " << dNum << std::endl;
    std::cout << "char " << cNum << std::endl;
    std::cout << "long " << lNum << std::endl;

    return 0;
}








using namespace std;
template <class type>
type minimum(type x, type y)
{
    type min;
    if (y < x) min = y;
    else min = x;
    return min;
}


int _tmain()
{
    int a1, a2, minia;
    float b1, b2, minib;
    char c1, c2, minic;
    printf("vvedite 2 celyx chisla\n");
    if (scanf("%d %d", &a1, &a2) == 2)
    {
        cin >> a1, a2;
        minia = minimum(a1, a2);
        cout << "\n" << minia << "\n";
    }
    else
    {
        printf("Vvedeno necorrectnoe znachenie\n");
    }
    printf("vvedite 2 proizvolnyh chisla\n");
    cin >> b1, b2;
    if (scanf("%f %f", &b1, &b2) == 2)
    {
        minib = minimum(b1, b2);
        cout << "\n" << minib << "\n";
    }
    else
    {
        printf("Vvedeno necorrectnoe znachenie\n");
    }
    printf("vvedite 2 simvola cherez zapyatuyu\n");
    cin >> a1, a2;
    if (scanf(" %c, %c", &c1, &c2) == 2)
    {
        minic = minimum(c1, c2);
        cout << "\n" << minic << "\n";
    }
    else
    {
        printf("Vvedeno necorrectnoe znachenie\n");
    }
    return 0;
}