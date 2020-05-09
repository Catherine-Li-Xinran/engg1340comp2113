# engg1340comp2113
fishing game

Identification of the team members:
Li Xinran UID:3035638612
Bai QingYu UID:3035693480
 
Game description with basic game rules:
A fishing game, the things you can catch are random. Fishing requires the use of baits and fishing rods. Bait is a consumable item that needs to be purchased. Fishing rods can be upgraded as players upgrade, the better it is, the higher the probability of catching expensive fish. Fishing can gain money(for purchasing baits) and experience(for the player upgrade his level). Player level increases with experience, and fishing rods can also be upgraded.
Players have a certain amount of initial money at the beginning and earn more money by selling fish.
Sometimes it’s not the fish but junk or jewels that are caught, there is a certain chance that fishing times will trigger a random event, we will try to bring surprises to this game.

List of features/functions:
1. About variable storage:
 1.1 Use data structures for storing player values:  money, experience, level, bait. 
 1.2 Use an array to store types and quantity of fish.
 1.3 Use "userFile.txt" as the player's archive and use file I/O to save and read the file.
2. Random fishing: There is a chance of catching different kinds of fish, and also a certain chance of not catching things or catching garbage. (We used several functions to achieve this.)
3. Sell the fish and get money.
4. Use money to buy the baits. (Players have discounts when buying large amounts of bait at once.)
5. The quality of the fishing rod increases with the player's level, the better the quality, the greater the probability of catching an item.
6. Automatically save every time the player exit the game.
7. In the main menu, players can choose to fish, buy baits, sell fish or quit.
8. Fishing can accumulate experience, the player will upgrade if the experience reaches a certain level.
9. After the player performs an operation, the program will ask if you want to do it again, making the operation more convenient.
10. When the player does not have enough money, bait and fish(for sell), the program will remind the player.
