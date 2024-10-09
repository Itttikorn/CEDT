class Card:
    def __init__(self, value, suit):
        self.v = int(self.getValueIndex(value))
        self.s = int(self.getSuitIndex(suit))
    def __str__(self):
        return '(' + self.getValue(self.v) + ' ' + self.getSuit(self.s) + ')'
    def getScore(self):
        value = self.getValue(self.v)
        if(value == 'A'): return 1
        if(value in ['J','Q','K']): return 10
        else: return(int(value))
    def sum(self, other):
        return (self.getScore() + other.getScore())%10
    def __lt__(self, rhs):
        if self.v != rhs.v:
            return self.v < rhs.v
        return self.s < rhs.s
    def getValueIndex(self, value):
        values = ['3','4','5','6','7','8','9','10','J','Q','K','A','2']
        return values.index(value)
    def getSuitIndex(self, suit):
        suits = ['club','diamond','heart','spade']
        return suits.index(suit)
    def getValue(self, value):
        values = ['3','4','5','6','7','8','9','10','J','Q','K','A','2']
        return values[value]
    def getSuit(self, suit):
        suits = ['club','diamond','heart','spade']
        return suits[suit]
    
        
#**Copy and paste your class with modified functions when submitting to the grader.
n = int(input())
cards = []
for i in range(n):
    value, suit = input().split()
    cards.append(Card(value, suit))
for i in range(n):
    print(cards[i].getScore())
print("----------")
for i in range(n-1):
    print(Card.sum(cards[i], cards[i+1]))
print("----------")
cards.sort()
for i in range(n):
    print(cards[i])
