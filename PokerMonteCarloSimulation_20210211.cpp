/******************************************************************************

THIS PROGRAM IS A POKER MONTE CARLO SIMULATION.
It computes the occurence of straights/flushes in 5-card-stud poker.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <ostream>

using namespace std;

//This is the suit of the card:
enum class suit: short {SPADE, HEART, DIAMOND, CLUB};

//This represents the "value" of the card - Jack=11, Queen=12, King=13, Ace=1
class pips{
    public:
        //constructor while asserting certain values of handed over val:
        pips(int val):v(val){assert(v>0 && v<14);}
        //<< needs to be type friend because we're going to access a private member:
        friend ostream& operator<<(ostream& out, const pips& p);
        //return the card value:
        int get_pips(){return v;}
    private:
        //declaration of card value:
        int v;
};

//This is going to be the card as a whole:
class card{
    public:
        //card constructor - assigns suit SPADE, assigns value v=1
        card():s(suit::SPADE),v(1){};
        //??
        card(suit s, pips v):s(s), v(v){};
        //<< needs to be type friend because we're going to access a private member:
        //ostream operator is NOT a member  - hence necessary to use friend
        friend ostream& operator<<(ostream& out, const card& c);
        suit get_suit(){return s;}
        pips get_v(){return v;}
    private:
        suit s;
        pips v;
};

ostream& operator<<(ostream& out, const card& c){
    cout << c.v << c.s ; // presumes << overloaded for pips and suit
    return out;
}

//Initialize whole card deck:
void init_deck(vector <card>& d){
    //Only for 1 suit (SPADE) - d pointer dereferenced to card c
    for(i=1; i<14; ++i){
        card c(suit::SPADE, i);
        d[i-1]=c;
    }
    //Only for 1 suit (HEART) - d pointer dereferenced to card c
    for(i=1; i<14; ++i){
        card c(suit::SPADE, i);
        d[i+12]=c;
    }
    //Only for 1 suit (DIAMOND) - d pointer dereferenced to card c
    for(i=1; i<14; ++i){
        card c(suit::SPADE, i);
        d[i+25]=c;
    }
    //Only for 1 suit (CLUB) - d pointer dereferenced to card c
    for(i=1; i<14; ++i){
        card c(suit::SPADE, i);
        d[i+38]=c;
    }
}

//print feature: 
void print(vector <card>& deck){
    //for(auto p=deck.begin(); p!=deck.end(); ++p)
    //    cout << *p;
    //cout endl;
    for(auto cardval:deck)
        cout << cardval;
    cout << endl;
}

//Checks if this hand contains a flush:
//expects vector, call-by-ref of hand of class "card"
bool is_flush(vector <card>& hand){
    //declare suit of first card, initialize it:
    suit s = hand[0].get_suit();
    
    //iterate through whole hand, compare first card's suit with current card's suit:
    //auto here saves us time since we do not have to mention a complicated iterator here:
    for(auto p=hand.begin(); p!=hand.end();++p)
        if(s!=p -> get_suit())
            //if you find that the suits differ - return false and exit functon:
            return false;
    return true;
    
    //so at the end of this function, we've only checked if all cards are of the SAME SUIT, NOT if they're in a row
}

bool is_straight(<vector> card& hand){
    int pips_v[5], i=0;
    
    //initialize the pips_v with the VALUES of the cards:
    for(auto p=hand.begin(); p!=hand.end(); ++p)
        //get_pips returns VALUE of the respective card
        pips_v[i++]=(p->get_pips()).get_pips();
    
    //Sort values increasing order:
    sort(pips_v, pips_v+5); //STL iterator range
     
    if(pips_v[0]!=1){
        //hand contains no aces:
        return((pips_v[0]==pips_v[1]-1) && (pips_v[1]==pips_v[2]-1) && (pips_v[2]==pips_v[3]-1) && (pips_v[4]==pips_v[3]-1));    
        
    } else{
        //special logic for aces:
        return(((pips_v[0]==pips_v[1]-1) && (pips_v[1]==pips_v[2]-1) && (pips_v[2]==pips_v[3]-1) && (pips_v[4]==pips_v[3]-1))
            || ((pips_v[1]==10) && (pips_v[2]==11) && (pips_v[3]==12) && (pips_v[4]==13)));
    }

}

//Check for straight flush, i.e. has to be a flush and a straight at the same time:
bool is_straight_flush(vector <card>& hand){
    return( is_straight(hand) && is_flush(hand) );
}

int main()
{
    //declare card deck, 52 cards:
    vector <card> deck(52);
    
    //set anchor point for randomized number generation:
    srand(time(0));
    
    //initialize deck card numbers:
    init_deck(deck);
    
    //declare and initialize counters:
    int i_how_many, i_flush_count=0, i_straight_count=0, i_straight_flush_count=0;
    
    cout << "******** POKER STRAIGHTS & FLUSHES EVALUATION *********" << "\n How many shuffles desired?";
    cin >> i_how_many;
    
    for (int i_loop=0; i_loop<i_how_many; ++i_loop){
        
        // STL algorithm for random shuffling of deck vector
        random_shuffle(deck.begin(), deck.end());
        
        //Set up a hand of cards:
        vector <card> hand[5];
        //initialize hand:
        int i=0; 
        for(auto p=deck.begin(); i<5; ++p)
            hand[i++] = *p;
        
        if(is_flush(hand))
            i_flush_count++;
        if(is_straight(hand))
            i_straight_count++;
        if(is_straight_flush(hand))
            i_straight_flush_count++;

    }
    
    cout << "\n\nResults:" << "\nFlushes: " << i_flush_count << "\nStraights: " << i_straight_count << "\nStraight Flushes: " << i_straight_flush_count; 
    
    return 0;
}
