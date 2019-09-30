#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include <string.h>

using namespace std;

enum faces {
  ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};

enum suits {
  SPADES, HEARTS, DIAMONDS, CLUBS
};

// game board stacks
const int MAX_CARDS = 52;
const int MAX_CARD_SUITS = 4;
const int MAX_CARDS_PER_SUIT = 13;

class Card { 
  public:
  int weight;
  suits suit;
  faces face;
  bool isVisible;

  Card(faces face, suits suit);
  string* render();

  private:
  string* hidden() {
    string a[] = {"|_____|"};
    return a;
  };

  string* visible() {
    string myFace = "| " + getFaceChar(face) + "  ";
    string a[] = {"|     |",
                    myFace,
                  "|_____|"};
    return a;
  };

  inline string getFaceChar(faces face) {
    string tempFace = "";

    switch (face) {
      case ACE:
        tempFace = 'A';
      break;
      case TWO:
        tempFace = '2';
      break;
      case THREE:
        tempFace = '3';
      break;
      case FOUR:
        tempFace = '4';
      break;
      case FIVE:
        tempFace = '5';
      break;
      case SIX:
        tempFace = '6';
      break;
      case SEVEN:
        tempFace = '7';
      break;
      case EIGHT:
        tempFace = '8';
      break;
      case NINE:
        tempFace = '9';
      break;
      case TEN:
        tempFace = "10";
      break;
      case JACK:
        tempFace = 'J';
      break;
      case QUEEN:
        tempFace = 'Q';
      break;
      case KING:
        tempFace = 'K';
      break;
      default:
        tempFace = "";
      break;
    }
    return tempFace;
  }
};

string* Card::render() {
  return (isVisible) ? visible() : hidden();
}

Card::Card(faces face, suits suit) {
  this->face = face;
  this->suit = suit;
  this->isVisible = true;
}

class CardDeck {
  public:
  Card *cards[MAX_CARDS];

  CardDeck();
};

CardDeck::CardDeck() {
  int cardCounter = 0;

  for (unsigned int suit = 0; suit < MAX_CARD_SUITS; ++suit) {
    for (unsigned int face = 0; face < MAX_CARDS_PER_SUIT; ++face) {
      cards[cardCounter++]->suit = suits(suit);
      cards[cardCounter++]->face = faces(face);
    }
  }
}

// PushCard

// PopCard
// CardRender
class Solitaire {
  public:
  string cardStacks[7][13];

  Solitaire();

  string* cardDisplay(Card c);

  void GameRender();
};

string* Solitaire::cardDisplay(Card c) {
  
}

Solitaire::Solitaire() {

  cardStacks[0][0] = " _____"; cardStacks[0][1] = " _____"; cardStacks[0][2] = " _____"; cardStacks[0][3] = " _____"; cardStacks[0][4] = " _____"; cardStacks[0][5] = " _____"; cardStacks[0][6] = " _____";
  cardStacks[1][0] = ""; cardStacks[1][1] = "|_____|"; cardStacks[1][2] = "|_____|"; cardStacks[1][3] = "|_____|"; cardStacks[1][4] = "|_____|"; cardStacks[1][5] = "|_____|"; cardStacks[1][6] = "|_____|";
  cardStacks[2][0] = ""; cardStacks[2][1] = "|     |"; cardStacks[2][2] = "|_____|"; cardStacks[2][3] = "|_____|"; cardStacks[2][4] = "|_____|"; cardStacks[2][5] = "|_____|"; cardStacks[2][6] = "|_____|";
  cardStacks[3][0] = ""; cardStacks[3][1] = "|  K  |"; cardStacks[3][2] = "|_____|"; cardStacks[3][3] = "|_____|"; cardStacks[3][4] = "|_____|"; cardStacks[3][5] = "|_____|"; cardStacks[3][6] = "|_____|";
  cardStacks[4][0] = ""; cardStacks[4][1] = "|_____|"; cardStacks[4][2] = "|_____|"; cardStacks[4][3] = "|_____|"; cardStacks[4][4] = "|_____|"; cardStacks[4][5] = "|_____|"; cardStacks[4][6] = "|_____|";
  cardStacks[5][0] = ""; cardStacks[5][1] = ""; cardStacks[5][2] = "|_____|"; cardStacks[5][3] = "|_____|"; cardStacks[5][4] = "|_____|"; cardStacks[5][5] = "|_____|"; cardStacks[5][6] = "|_____|";
  cardStacks[6][0] = ""; cardStacks[6][1] = ""; cardStacks[6][2] = "|_____|"; cardStacks[6][3] = "|_____|"; cardStacks[6][4] = "|_____|"; cardStacks[6][5] = "|_____|"; cardStacks[6][6] = "|_____|";
  cardStacks[7][0] = ""; cardStacks[7][1] = ""; cardStacks[7][2] = "|_____|"; cardStacks[7][3] = "|_____|"; cardStacks[7][4] = "|_____|"; cardStacks[7][5] = "|_____|"; cardStacks[7][6] = "|_____|";
  cardStacks[8][0] = ""; cardStacks[8][1] = ""; cardStacks[8][2] = "|_____|"; cardStacks[8][3] = "|_____|"; cardStacks[8][4] = "|_____|"; cardStacks[8][5] = "|_____|"; cardStacks[8][6] = "|_____|";
  cardStacks[9][0] = ""; cardStacks[9][1] = ""; cardStacks[9][2] = "|_____|"; cardStacks[9][3] = "|_____|"; cardStacks[9][4] = "|_____|"; cardStacks[9][5] = "|_____|"; cardStacks[9][6] = "|_____|";
  cardStacks[10][0] = ""; cardStacks[10][1] = ""; cardStacks[10][2] = "|_____|"; cardStacks[10][3] = "|_____|"; cardStacks[10][4] = "|_____|"; cardStacks[10][5] = "|_____|"; cardStacks[10][6] = "|_____|";
  cardStacks[11][0] = ""; cardStacks[11][1] = ""; cardStacks[11][2] = "|_____|"; cardStacks[11][3] = "|_____|"; cardStacks[11][4] = "|_____|"; cardStacks[11][5] = "|_____|"; cardStacks[11][6] = "|_____|";
  cardStacks[12][0] = ""; cardStacks[12][1] = ""; cardStacks[12][2] = "|_____|"; cardStacks[12][3] = "|_____|"; cardStacks[12][4] = "|_____|"; cardStacks[12][5] = "|_____|"; cardStacks[12][6] = "|_____|";


  CardDeck cd = CardDeck();
  // for (unsigned int i = 0; i < sizeof(cd.cards) / sizeof(cd.cards[0]); ++i) {
  //   cd.cards[i]->render();
  // }
  
  
}
// GenerateGameDeck
// InitalizeGameBoard
// GameHandlers
// 

int main() {
/*
 _____
|_____|8
|_____|7
|_____|6
|_____|5
|_____|4
|_____|3
|_____|2
|_____|1
|     |
|  K  |
|     |
 -----
*/

  cout << string(50, '\n');
  Card *c = new Card(KING, SPADES);

  // cout << "face: " << c->face << "\nsuit: " << c->suit << endl;

  Solitaire *s = new Solitaire();

  s->GameRender();
}
