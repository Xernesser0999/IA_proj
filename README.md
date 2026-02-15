# AI Project  
A project using behavior trees to drive NPCs with Artificial Intelligence.
## How it works  
The simulation runs in three phases, represented by a clock at the top-right corner of the screen :  
- Morning
- Daytime
- Evening  
# Morning
Shops restock their inventory, and no NPCs appear.  
# Daytime  
An NPC appears every 2 seconds and goes to buy something in one of the available shops, chosen at random.
If the shop has no stock left, the NPC leaves dissatisfied.
# Evening  
NPCs leave the area, and merchants tally their earnings.
