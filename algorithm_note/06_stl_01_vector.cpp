#include <cstdio>
#include <vector>

using namespace std;

int main(){
    vector<int> nameInt;
    vector<double> nameDouble;
    vector<char> nameChar;
    // artor<node> name;
    
 vector<vector<int> > nameVector;
    vector<int> nameIntArray[100];

 vector<int>::const_iterator it;

    for(int i = 1; i <= 5; i++)
        nameInt.push_back(i);
    for(it = nameInt.cbegin(); it < nameInt.end(); it++)
        printf("%d\n", *it);

    printf("nameInt size: %lu\n", nameInt.size());

    auto j = nameInt.size();

    for(unsigned long i = 0; i < j - 3; i++)
        nameInt.pop_back();

    for(it = nameInt.cbegin(); it < nameInt.end(); it++)
        printf("%d\n", *it);

    printf("nameInt size: %lu\n", nameInt.size());

    nameInt.insert(nameInt.begin() + 2, -1);
    nameInt.insert(nameInt.begin() + 1, -2);

    for(it = nameInt.cbegin(); it < nameInt.end(); it++)
        printf("%d\n", *it);

    printf("nameInt size: %lu\n", nameInt.size());

    nameInt.erase(nameInt.begin() + 1);

    for(it = nameInt.cbegin(); it < nameInt.end(); it++)
        printf("%d\n", *it);

    printf("nameInt size: %lu\n", nameInt.size());

    nameInt.erase(nameInt.begin() + 1, nameInt.begin() + 3);

    for(it = nameInt.cbegin(); it < nameInt.end(); it++)
        printf("%d\n", *it);

    printf("nameInt size: %lu\n", nameInt.size());

    // nameInt.clear();
    // printf("After clear() nameInt size: %lu\n", nameInt.size());

    return 0;
}
