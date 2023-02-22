//EHAB ABDALLA - 02/14/2023
//Importing the classes im going to be using..
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class GhostGame {
    public static void main(String[] args) {
        String[] wordsarray = new String[279496]; //array sized to store all the words from the .txt file
        int Players; //players in the game
        Scanner input = new Scanner(System.in); //Scanner for userinput

        //using a try and catch to read all the stored values in the file and storing it into the array
        try {
            BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\Ehab Abdalla\\Desktop\\words.txt"));
            String line;
            int i = 0;

            //while loop to read each line from the file and storing it into the array until it's null/empty.
            while ((line = reader.readLine()) != null) {
                //.trim to remove any white space stuff like spaces,tabs, and newlines. (Learned from CS211)
                wordsarray[i] = line.trim(); 
                i++;
            }
            reader.close(); //closing the reader object
        } 
        catch (IOException e) {
          //This method will be called on my Exception object "e" and will help me trace where 
          //the exception occured to help debug or troubleshoot when theres a problem with the code.  
          e.printStackTrace(); 
            
        }

        boolean turn = true;
        while(turn){

            System.out.print("Enter the number of players: ");
            Players = input.nextInt(); //read userinput for # of players by doing input.nextInt
            input.nextLine();

            //declare our beginning player, the leters, and challenge variables.
            int currentPlayer = 1; 
            String letters = "";
            boolean wordFormed = false;
            boolean challenged = false;
            int challengedPlayer = 0;

            while (!wordFormed) { //The ghost game while loop until a word is formeed:
                System.out.print("Player " + currentPlayer + ", it's your turn. The letters are " + letters + ". Enter a letter or enter * to challenge.\n");
                String letter = input.nextLine();

                //if a * is entered.. we check for a possible word 
                if (letter.equals("*")) {
                    
                    if(letter.length()<=4){ //if a star is entered.. we check first if the length of what we have is equal to 4 or greater..
                        String possibleWord = findPossibleWord(wordsarray, letters);
                    //if a possible word is found.. we print the loser # , we break out and end the game.
                        if (possibleWord != null) {
                            System.out.println(possibleWord + " begins with those letters. Player " + currentPlayer + " loses!");
                            break;
                        } else { //otherwise we intialize challenged player and make challenged = true so the if(challenged) functions
                            challenged = true;
                            challengedPlayer = (currentPlayer % Players) + 3;
                        }
                    }
                } 
                else {
                //Else, add that letter to our current string of letters and continue the game.
                    letters += letter;
                }

                if (letters.length() >= 4) { //if the length is atleast 4.. we check if it's a word..
                    if (okFunction(wordsarray, letters)) {
                    //if it is a word.. Print out the loser , break out and end the game.
                        System.out.println(letters + " is a word. Player " + currentPlayer + " loses!");
                        break;
                    }
                }

                if (challenged) { //if a player is challenged, we check if they formed a word..
                    challenged = false;

                    //if the curent letters in our string form a word, the challenged player loses.
                    if (okFunction(wordsarray, letters)) {
                        System.out.println(letters + " is a word. Player " + currentPlayer + " loses!");
                        break;
                    } 
                    else {
                        System.out.println("No word begins with those letters. Player " + challengedPlayer + " loses!");
                        break;
                    }
                }

                //we move on to the next player..
                currentPlayer = (currentPlayer + 1) % Players;

                //but if current player is 0, we move to the last player.
                if (currentPlayer == 0) {
                    currentPlayer = Players;
                }

                
            }

            //block of code to prompt user if they want to play again..

            //printing a border
            for(int i=0; i<20; i++){
            System.out.print("*");
            }
            System.out.println();

            System.out.println("WOULD YOU LIKE TO PLAY AGAIN? ENTER Y OR N");

            //printing a border
            for(int i=0; i<20; i++){
            System.out.print("*");
            }
            
            System.out.println();
            Scanner decision = new Scanner (System.in);
            String decisionn = decision.next();

            if(decisionn.equals("N")){
                System.out.println("HAVE A NICE DAY!");
                System.exit(0); //if they dont.. we end the program..
            }
            else{
                continue; //otherwise we loop again the beginning of the program so the user can play again.
            }

        }

            input.close(); //closer the scanner to avoid issues
        }

    //MY FUNCTIONS:
    //my boolean function that will check if a given string is a word in the wordsarray.
    public static boolean okFunction(String[] wordsarray, String letters) {
        for (String s : wordsarray) { //checks EVERY value in the words array.
            if (s.equals(letters)) { //compares it to "letters"..
                return true;  //and returns true if it's in my wordsarray[].
            }
        }

        return false; //otherwise it's not and we return false.
    }

    
    //while this function actually returns me the word "s" otherwise it returns null
    public static String findPossibleWord(String[] wordsarray, String letters) {
        for (String s : wordsarray) { //Loop through all the words in the array
            if (s.startsWith(letters)) { //check if letters aka our current formed word starts with the given letters..
                return s; //return the word if it does..
            }
        }

        return null; //return null if no word is found matching
    }
}
