
#include <queue>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
///////////////////Function Stubaronis/////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void process_input(queue<int>& deck);
void process_deck(queue<int>& deck, vector<int>& discard);
void show_progress(queue<int>& deck, vector<int>& discard);



///////////////////////////////////////////////////////////////////////////////
///////////////////Main Function-a-roni////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int main(){

    queue<int> deck;        // Stores the deck of cards
    vector<int> discard;    // Stores the discarded cards


    process_input(deck);            // Calls function to process input
    process_deck(deck, discard);    // Processes the inputs to deck
    show_progress(deck, discard);   // shows the final output

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////Function Definition-a-ronis/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/// @brief This processes the input, and adds it to the queue
/// @param deck this is the deck of cards to be sorted through
void process_input(queue<int>& deck){
    int add_to_deck;                    // number to add to the deck
    bool found_zero = false;            // bool to end loop if 0 is found
    while(cin >> add_to_deck && !found_zero){
        if (add_to_deck != 0){
            deck.push(add_to_deck);     // pushes number to deck
        } else {
            found_zero = true;          // changes loop condition
        }
    }
};


/// @brief This sorts through the input, and handles processing of cards
/// @param deck stores the cards we are going to keep
/// @param discard stores the discarded cards
void process_deck(queue<int>& deck, vector<int>& discard){

    int push_to_deck;                       // value to add to deck
    int push_to_discard;                    // value to add to disc

    deck.pop();                             // Drops the top value
    int check = deck.front();               // Saves first value

    while (deck.size() != 1){   
        if (deck.size() > 1){
        
        push_to_deck = deck.front();        // Sets number to push to back
        deck.push(push_to_deck);            // Pushes the copy to the back
        deck.pop();                         // pops original

        push_to_discard = deck.front();     // Saves number to discard
        discard.push_back(push_to_discard); // pushes number to discard
        deck.pop();                         // removes discard from que
        } else {
            cout << deck.front() << endl;   // ouputs last card to stream
        }
    }
}


/// @brief This outputs the last card in the deck, and the dicard pile
/// @param deck holds the last kept card
/// @param discard holds the discard pile
void show_progress(queue<int>&deck, vector<int>& discard){
    string delim = "";   // This seperates the items in i
    
    for (auto i : discard){
        cout << delim << i;
        delim = ", ";
    }

    cout << '\n';
    cout << deck.front() << endl;
}