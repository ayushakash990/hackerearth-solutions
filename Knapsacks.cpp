// BY AYUSH AKASH
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct object
{
    int weight, value;

    object(){};

    int operator <(const object &O)
    {
        if(value == O.value)
        {
            return (weight < O.weight);
        }

        return (value > O.value);
    }
};

const int MAX_N = 1e3 + 5, MAX_VALUE = 55, oo = 1e9;
int minimum_weight[MAX_N][MAX_VALUE];

int main()
{
    int no_of_objects, capacity;
    cin >> no_of_objects >> capacity;

    vector <object> O(no_of_objects + 1);
    for(int i = 1; i <= no_of_objects; i++)
        cin >> O[i].value;

    for(int i = 1; i <= no_of_objects; i++)
        cin >> O[i].weight;

    long long total_value = 0;
    for(int i = 1; i <= no_of_objects; i++)
    {
        total_value += O[i].value;
    }

    int answer = 0;
    vector <long long> minimum_weight(total_value + 1, -1);
    total_value = 0;
    minimum_weight[0] = 0;

    for(int i = 1; i <= no_of_objects; i++)
    {
        total_value += O[i].value;

        for(int v = total_value; v >= O[i].value; v--)
        {
            if(minimum_weight[v - O[i].value] != -1)
            {
                int weight_required = minimum_weight[v - O[i].value] + O[i].weight;

                if(weight_required <= capacity)
                {
                    answer = max(answer, v);
                }

                if(minimum_weight[v] == -1 || minimum_weight[v] > weight_required)
                {
                    minimum_weight[v] = weight_required;
                }
            }
        }
    }

    cout << answer;

    return 0;
}
