### Exercise 1

#### 1\.

π maker, model, price (σ price < 1000 (PC ⨝ Product))

#### 2\.

π maker (Product⨝PC)

#### 3\.

π maker (Product ⨝ (π model σ ram ≥ 2048 PC ∪ π model σ ram ≥ 2048 Laptop))

#### 4\.

π maker Product - π maker ((Product⨝ π model Laptop) ∪ (Product ⨝ π model Printer))

#### 5\.

all\_pairs = π maker, omaker (σ type = otype ∧ maker ≠ omaker (Product ⨯ ρ omaker←maker, omodel←model, otype←type Product))



all\_pairs

#### 6\.

b\_pcs = (π model, price PC ⨝ π model σ maker='B' Product)

b\_laptops = (π model, price Laptop ⨝ π model σ maker='B' Product)

b\_printers = (π model, price Printer ⨝ π model σ maker='B' Product)



b\_pcs ∪ b\_laptops ∪ b\_printers

#### 7\.

mani\_sell\_pcs = π maker (Product ⨝ PC)

mani\_sell\_laptops = π maker (Product ⨝ Laptop)



mani\_sell\_laptops - mani\_sell\_pcs

#### 8\.

pc1 = ρ hd1←hd (π hd PC)

pc2 = ρ hd2←hd (π hd PC)





#### 9\.



#### 10\.



#### 11\.



#### 12\.



#### 13\.





### Exercise 2

#### 1\.

User ⨝ ρemail←m\_creator(π m\_creator Likes)



#### 3\.

toon\_friends =  (π user2 σ user1='toon.calders@uantwerpen.be' Friends) ∪ (π user1 σ user2='toon.calders@uantwerpen.be' Friends)



len\_friends =  (π user2 σ user1='len.feremans@uantwerpen.be' Friends) ∪ (π user1 σ user2='len.feremans@uantwerpen.be' Friends)



toon\_friends ∩ len\_friends

