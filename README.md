# Summary
This program allows a user to parse the contents of their Elder Scrolls Online inventory and sort by Name, Quantity, or Price.
The sample data was scraped from my account using the "CraftBagger" addon for the game, which outputs the contents of your inventory into a CSV file.
I had the idea for this program when I noticed you could not sort by quantity or market price in game, and it is very valuable information to have when buying and selling.

# Dependencies
- CraftBagger: Not used directly in the code, but used to generate the CSV file to be parsed by the program.
- Boost/lexical_cast: Used to cast strings from getline into the desired type, so that it may be sorted properly by the rest of the program.
  - ex. Converts the quantity of each item from a string into an integer.

# Usage
First, the user must acquire a CSV file containing their ESO inventory data, likely using the CraftBagger addon. 
There are 3 flags when running the program:
- \-c, the CSV file to be read
- \-s, the sorting method to be used: name, quantity, price (default: price)
- \-o, the output file

When run properly, the program will take the CSV file, read it, and parse it into the output file, sorted according to the user's preference.
