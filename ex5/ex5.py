'''
Having formating problems regarding Hebrew.  
***********
*Roy Shefi*
* *
*  Mor 05  *
*   ex5    *
'''

import math
import string
import sys
'''*********************************************************************
* function name: PrintNoDrae                                           *
* The Input: the class deck, the object D. 							   *
* The output: none													   *
* The Function operation: Print cards without draewin them.	           *
************************************************************************'''
def PrintNoDraw(Deck,D):
    if D.in_deck:
        deck = reversed(D.in_deck)
        for card in deck:
            print "<"+card+">"
    elif D.out_deck:
        deck = D.out_deck
        for card in deck:
            print "<"+card+">"
'''*********************************************************************
* function name: NunmberOfCards                                        *
* The Input: the class deck, the object D. 							   *
* The output: number of cards in deck								   *
* The Function operation: gives number os cards in deck                *
************************************************************************'''
def NumberOfCards(Deck,D):
    if D.in_deck:
        deck = D.in_deck
        num = len(deck)
        print num
    elif D.out_deck:
        deck = D.out_deck
        num = len(deck)
        print num
'''*********************************************************************
* function name: NewDeck											   *   
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation: Add a New Full deck, Erase the last on.	   *	   
************************************************************************'''
def NewDeck(Deck,D):
    deck = ["2,diamond","3,diamond","4,diamond","5,diamond","6,diamond",
             "7,diamond","8,diamond","9,diamond","10,diamond","11,diamond",
            "12,diamond","13,diamond","14,diamond","2,spade","3,spade",
            "4,spade","5,spade","6,spade","7,spade","8,spade","9,spade",
            "10,spade","11,spade","12,spade","13,spade","14,spade","2,club",
            "3,club","4,club","5,club","6,club","7,club","8,club","9,club",
            "10,club","11,club","12,club","13,club","14,club","2,heart",
            "3,heart","4,heart","5,heart","6,heart","7,heart","8,heart",
            "9,heart","10,heart","11,heart","12,heart","13,heart","14,heart"]
    D.in_deck = deck
'''*********************************************************************
* function name: Draw											       *
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation: Draw a card from deck, call .pop			   *
************************************************************************'''
def Draw(Deck,D):
    #Safety.
    if D.out_deck or D.in_deck:
        card_out = D.Draw()
        print "<"+card_out+">"
'''*********************************************************************
* function name: AddCard										       * 
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation: gets string input,CheckCard, if valid summens*
*	class function Add to append input as card.	   					   *
*************************************************************************'''
def AddCard(Deck,D):
    x = 0
    while(x != 1):
        card = raw_input()
        #If card is valid, add it to deck.
        card = CheckCard(card)
        if card!= 0:
            D.Add(card)
            x = 1
# adding multiple cards to the deck
'''*********************************************************************
* function name:AddingCards											   *   
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation: gets number of cards to insert, gets each    *
*	input, checks it (CheckCard), if valid, calls Add to append card.  * 			   
************************************************************************'''
def AddingCards(Deck,D):
    input1 = raw_input()
    i = 0
    #Checking if valid input.
    if input1.isdigit():
        #Add cards as given number.
        while i < int(input1):
            card = raw_input()
            card = CheckCard(card)
            if card != 0:
                D.Add(card)
                #Keep reciving cards until all cards stated are in.
                i = 1 + i
'''*********************************************************************
* function name: War											       *
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation:Draws two cards, calls WhoIsBetter to         *
* determine which card is better, print result.			               *
************************************************************************'''
def War(Deck,D):
    #Safety, if there are sufficient cards in deck.
    if len(D.out_deck)>= 2 or len(D.in_deck)>=2:
        #Drawing two cards.
        card1 = D.Draw()
        card2 = D.Draw()
        if WhoIsBetter(card1,card2) == 1:
            print "<"+card1+">"+" is better than"+" <"+card2+">"
        else:
            print "<"+card1+">"+" is not better than"+" <"+card2+">"
'''*********************************************************************
* function name: WhoIsBetter										   *       
* The Input: card1,card2 - the cards drawed.						   *   
* The output: int - 1 if first card is better			               *  
* The Function operation:checks which num of card is higher, if same   *
* checks which type is better. returns 1 if first card is better.      *
* else - returnes 0.												   *			   
************************************************************************'''
def WhoIsBetter(card1,card2):
    #Order of who is better by type.
    cardKing = {"heart" : 4, "club" : 3, "spade" : 2, "diamond" : 1}
    #Checking who has a higher number.
    card1 = card1.split(",")
    card2 = card2.split(",")
    if card1[0] > card2[0]:
        return 1
    elif card1[0] == card2[0]:
            #Who has a better type.
            if cardKing[card1[1]]> cardKing[card2[1]]:
                return 1
            #if the card number is > 10.
            elif card2[2] == card1[2]:
                if cardKing[card1[3]]> cardKing[card2[3]]:
                    return 1
    return 0
'''*********************************************************************
* function name: DrawAll											   *   
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation: Draws all cards in deck and prints them by   *
* class func Drew			   										   *
************************************************************************'''
def DrawAll(Deck,D):
    #Safety measure to not draw on an empty list.
    if D.out_deck or D.in_deck:
        #Draw until empty.
       while D.out_deck or D.in_deck:
            card_out = D.Draw()
            #card_out = CheckCard(card_out)
            print "<"+card_out+">"
'''*********************************************************************
* function name:DrawSequence 										   *       
* The Input: the class deck, the object D. 							   * 
* The output: none													   *  
* The Function operation:gets input for how many cards to draw. drawes *
* them, call IsValidSeq. if valid sequence, prints it.				   *			   
************************************************************************'''
def DrawSequence(Deck,D):
    drawNum = raw_input()
    drawNum = int(drawNum)
    i = 0
    seq = []
    #Safety.
    if len(D.out_deck) >= drawNum or len(D.in_deck)>= drawNum:
        i = 0
        a=1
        #Draw cards
        while(i < drawNum):
            card = D.Draw()
            seq = seq + [card]
            i += 1
            x = " is not"
        #If the sequence is valid
        if IsValidSeq(seq) == 1:
            x = " is"
        print "[",
        sys.stdout.softspace=0
        for i in seq:
            card = i
            # if - for print formating
            if a == 1:
                print "<"+card+">",
                sys.stdout.softspace=0
            else:
                print ",<"+card+">",
                sys.stdout.softspace=0
            a =0
        sys.stdout.softspace=0
        print "]"+x+" a valid sequence"
'''*********************************************************************
* function name:IsValidSeq 											   *    
* The Input: The seq. 							    			       *
* The output: 1 - if valid sequnce.									   *			     
* The Function operation:Checks if each card is the same color as 	   *
* previous card, and if it has a higher number.			   		       * 
************************************************************************'''
def IsValidSeq(seq):
    #checking if the sequence is valid.
    cardKing = {"h" : 1, "d" : 1 ,"s" : 2, "c" : 2}
    i = 1
    cou = 0
    for i in range(len(seq)):
    	#Geting each card from list.
        card2 = seq[i]
        if i != 0:
            card1 = seq[i-1]
            #checking if same color.
            if cardKing[card2[2]] == cardKing[card1[2]]:
                if card2[0] > card1[0]:
                    cou += 1
        i +=1
    #If valid, return 1.
    if cou +1 == i:
        return 1
'''*********************************************************************
* function name: CheckCard											   *    
* The Input: the card. 							    				   *
* The output: 0 - if not valid card, card - if valid.				   *								     
* The Function operation: Gets card, splits it, checks if number is in *
* range (2-14) and if it has a valid type.						       *
************************************************************************'''
def CheckCard(card):
    # Defying a valid card type.
    type = ["heart", "club","spade","diamond"]
    cardSp = card.split()
    num = int(math.fabs(float(cardSp[0])))
    num = int(num)
    cardType = cardSp[1]
    #After splitting input and converting to positive int,
    #checking if in range and valid.
    if num in range(2, 15) and (cardType in type):
        cardSp[0] = str(int(num))
        card = ",".join(cardSp)
        return card
    return 0

def main():
    # making a class of 'first in first out' - help from:
    # http://code.activestate.com/recipes/210459-quick-and-easy-fifo-queue-class
    class Deck:
    	#Defying class.
        def __init__(self):
        	#Cards input to deck.
            self.in_deck = []
            #Cards after Draw, were the cards are to be Drawn.
            self.out_deck = []
		#Function receives card,appends it to list.(last)
        def Add(self, card):
            self.in_deck.append(card)
        #First in first out, switching between two lists.
        def Draw(self):
            if not self.out_deck:
                self.in_deck.reverse()
                self.out_deck = self.in_deck + self.out_deck
                self.in_deck = []
            return self.out_deck.pop()

    #Defying the class object.
    D = Deck()
    userInput = 1
    #"main fool prof" accepts only valid input.
    while (userInput != "0"):
        userInput = raw_input()
        #Defying key for user input.
        deckOptions = {"1": NewDeck, "2": Draw, "3": AddCard, "4": AddingCards,
                       "5": War, "6": DrawAll, "7": DrawSequence}
        while (userInput not in deckOptions and userInput != "0"):
            userInput = raw_input()
        if userInput != "0":
            choice = deckOptions[userInput]
            choice(Deck,D)
main()
