from Bestelling import Bestelling
from LinkedChain import LinkedChain
from MyQueue import MyQueue
from MyStack import MyStack
from Reservatiesysteem import Reservatiesysteem
from Werknemer import Werknemer


r = Reservatiesysteem()
r.werknemers = LinkedChain()

stack = MyStack()

werknemerA = Werknemer('A', '', 10)
r.werknemers.insert(1, werknemerA)
stack.push(werknemerA)

werknemerB = Werknemer('B','',3)
r.werknemers.insert(1, werknemerB)
stack.push(werknemerB)

r.bestellingen = MyQueue()

b_1 = Bestelling(5,0)
r.bestellingen.enqueue(b_1)

b_2 = Bestelling(8,1)
r.bestellingen.enqueue(b_2)

b_2.tijdstip = 2

print(r.bestellingen.items[0])
print(r.werknemers.retrieve(0))

