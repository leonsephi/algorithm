#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;
const static size_t CARD_CNT_DECK=54; //单幅牌个数

struct card
{
    public:
        card(int color, int num )
        {
            sprintf(this->content,"%d_%d", color, num);
            this->_next = NULL;
        }
        ~card()
        {
        }
        card* operator+(size_t cnt)
        {
            card* _tmp = this;
            while( cnt>0 )
            {
                if ( _tmp->_next!= NULL )
                {
                    _tmp = _tmp->_next;
                    cnt--;
                }
                else
                {
                    break;
                }
            }
            return _tmp;
        }
    public:
        char content[10];
        card* _next;
};

card* init(size_t deck_cnt=1)
{
    if ( deck_cnt<1 ) return NULL;
    card* head = new card(0,0);
    for( size_t i=0; i<deck_cnt; ++i )
    {
        // jokers, num:0
        for( size_t j=1; j<=2; ++j )
        {
            card* _joker = new card(j,0);
            _joker->_next = head->_next;
            head->_next = _joker;
        }
        // num, 1->13
        for( size_t num=1; num<=13; ++num )
        {
            for( size_t color=1; color<=4; ++color )
            {
                card* _num_card = new card(color,num);
                _num_card->_next = head->_next;
                head->_next = _num_card;
            }
        }
    }
    return head;
}

void print_deck( card* head )
{
    card* temp = head->_next;
    int _row = 1;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout.setf(ios::left);
    while( temp!=NULL )
    {
        cout << setw(8) <<  temp->content;
        if ( _row%13==0 )
        {
            cout << endl;
        }
        _row++;
        temp = temp->_next;
    }
    cout << endl;
}

// @returnvalue: >0:succeed, !0:faild 
card* shuffling( card* head, size_t deck_cnt )
{
    srand(time(NULL));
    card* shuffled_head = new card(0,0);
    size_t cnt_left = CARD_CNT_DECK*deck_cnt;
    for( size_t i=0; i<CARD_CNT_DECK*deck_cnt; ++i )
    { 
        size_t pick = rand()%cnt_left+1;
        card* _pre_pick = *head+(pick-1);
        card* _pick = *head+pick;
        if ( !_pre_pick || !_pick )
        {
            break;
        }
        _pre_pick->_next = _pick->_next;
        _pick->_next = shuffled_head->_next;
        shuffled_head->_next = _pick;

        cnt_left--;
    }
    return shuffled_head;
}

int main(int argc, char** argv)
{
    if ( argc<2 ) return 0;
    int deck = atoi(argv[1]);
    deck = deck<0?1:deck;
    card* new_deck = init(deck);
    print_deck(new_deck);
    card* shuffled = shuffling(new_deck,deck);
    print_deck(shuffled);
    return 0;
}
