#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num_of_cards = 5;
    cin >> num_of_cards;

    vector<int> v(num_of_cards);
    for (int i = 0; i < num_of_cards; i++)
    {
        int card;
        cin >> card;
        v[i] = card;
    }
    int sereja_score = 0,  dima_score=0;
    int left = 0, right = num_of_cards-1;
    for (int i = 0; i < num_of_cards; i++)
    {
        int current_card;
        if (v[left] > v[right])
        {
            current_card = v[left];
            left++;
        }
        else{
            current_card = v[right];
            right--;
        }
        
        if (i%2 == 0) // sereja turn
        {
            sereja_score += current_card;
        }
        else{
            dima_score += current_card;
        }
        
    }
    cout << sereja_score << " " << dima_score;
    return 0;
}