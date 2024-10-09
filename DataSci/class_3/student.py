class Card:
    def __init__(self, value, suit):
        self.v = int(self.getValueIndex(value))
        self.s = int(self.getSuitIndex(suit))
    def __str__(self):
        return '(' + self.getValue(self.v) + ' ' + self.getSuit(self.s) + ')'
    def next1(self):
        nextv = self.v
        nexts = self.s
        if(self.s == 3):
            if(self.v == 12):
                nexts = 0
                nextv = 0
            else:
                nexts = self.s+1
                nextv = self.v+1
        else:
            nexts = self.s+1
        return Card(self.getValue(nextv),self.getSuit(nexts))
            
    def next2(self):
        nextv = self.v
        nexts = self.s
        if(self.s == 3):
            if(self.v == 12):
                nexts = 0
                nextv = 0
            else:
                nexts = self.s+1
                nextv = self.v+1
        else:
            nexts = self.s+1
        self.s = nexts
        self.v = nextv
    def getValueIndex(self, value):
        values = ['3','4','5','6','7','8','9','10','J','Q','K','A','2']
        return values.index(value)
    def getSuitIndex(self, suit):
        suits = ['club','diamond','heart','spade']
        return suits.index(suit)
    def getValue(self, value):
        values = ['3','4','5','6','7','8','9','10','J','Q','K','A','2']
        return values[value%len(values)]
    def getSuit(self, suit):
        suits = ['club','diamond','heart','spade']
        return suits[suit%len(suits)]
#**Copy and paste your class with modified functions when submitting to the grader.
n = int(input())
cards = []
for i in range(n):
    value, suit = input().split()
    cards.append(Card(value, suit))
for i in range(n):
    print(cards[i].next1())
print("----------")
for i in range(n):
    print(cards[i])
print("----------")
for i in range(n):
    cards[i].next2()
    cards[i].next2()
    print(cards[i]) 
