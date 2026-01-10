#Exercise 2: Social media

## 1. Which users created a message that is liked ?
User ⨝ ρ email←m_creator(π m_creator Likes)

## 2. Which users that are 20, have friends that are also 20?
ρ user1←U1.email, user2←U2.email (π U1.email, U2.email (σ U1.age=20 ∧ U2.age=20 (ρ U1(User) ⨯ ρ U2(User)))) ⨝ Friends

## 3. Which friends do Toon and Len share?
toon_friends = π user2 σ user1='toon.calders@uantwerpen.be' Friends ∪
π user1 σ user2='toon.calders@uantwerpen.be' Friends

len_friends = π user2 σ user1='len.feremans@uantwerpen.be' Friends ∪
π user1 σ user2='len.feremans@uantwerpen.be' Friends

toon_friends ∩ len_friends

## 4. Who likes messages created by members of the group UAntwerpen?
members_of_uantwerpen = π user_email σ group_name='UAntwerpen' Member

π liker_user_email (Likes ⨝ m_creator=user_email members_of_uantwerpen)

## 5. Which friend of Toon does not like any message?
toon_friends = ρ tfriend←user2 (π user2 σ user1='toon.calders@uantwerpen.be' Friends) ∪ (π user1 σ user2='toon.calders@uantwerpen.be' Friends)

friends_who_like = π liker_user_email (Likes ⨝ liker_user_email=tfriend toon_friends)

toon_friends - friends_who_like

## 6. Which friend of Toon likes all messages?
