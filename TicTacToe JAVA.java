//EHAB ABDALLA - 02/2023 - JAVA SWING TICTACTOE GAME
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

class TicTacToeGame implements ActionListener { //ActionListener is the interface that allows user interaction with GUI components like buttons and menu items.
    //All the framing for the GUI
    JFrame frame = new JFrame(); //Big frame
    JPanel t_panel = new JPanel(); //Panel inside the big frame
    JPanel bt_Panel = new JPanel(); //Button panel inside the panel inside the big frame
    JLabel textfield = new JLabel(); //Label in java
    JButton [] bton = new JButton[9]; //Push button that generates and event when pressed
    int chances = 0; //counter for chances
    Random randomizer = new Random(); //randomizer
    boolean P1C; //Player One Chance
    
    //CLASS CONSTRUCTOR:
    TicTacToeGame(){
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //When user clicks the "close" button, the application will term and exit.
        frame.setSize(750, 750); //Width and Height of the Frame
        frame.getContentPane().setBackground(new Color(204, 204, 204)); //color during startup
        frame.setTitle("EHAB'S TIC TAC TOE GAME"); //title for the main frame
        frame.setLayout(new BorderLayout()); //sets the layout and uses BorderLayout to position and size any components that are added to the main frame.
        frame.setVisible(true); //makes everything visible on the screen as long as value is TRUE

        textfield.setBackground(new Color(255, 204, 51)); //Colors for the "Loading" and "X's Turn" Background
        textfield.setForeground(new Color(0,0,0)); //Colors for the "Loading" Font
        textfield.setFont(new Font(Font.SERIF, Font.BOLD, 85)); //Font for the "Loading" words on top
        textfield.setHorizontalAlignment(JLabel.CENTER); //Method call that sets the horizontal alignment
        textfield.setText("EHABS TIC TAC TOE GAME"); 
        textfield.setOpaque(true);  //Method call that sets the opacity of a JTextField object to be fully opaque.
        
        t_panel.setLayout(new BorderLayout()); //This divides the panel into five regions N,S,W,E and CENTER.
        t_panel.setBounds(0, 0, 800, 100); //method used to set the position and size of a panel

        bt_Panel.setLayout(new GridLayout(3, 3)); //Makes the 3x3 Grid 
        bt_Panel.setBackground(new Color(0, 0 , 0)); //Sets the grid color for the borders to black.

        for(int i=0; i<9; i++){ //for-loop for all 9 places that will act as buttons for the player to press
            bton[i] = new JButton(); //starting at button[i]
            bt_Panel.add(bton[i]); //adds the button to the bt_panel (bton[i] as this will happen 9 times)
            bton[i].setFocusable(false); //So that there is no [] box around the button for focus
            bton[i].setFont(new Font(Font.SERIF, Font.PLAIN, 100)); //Setting the font for X and O
            bton[i].addActionListener(this); //Implementing the ActionListener interface that will handle the button's actions
            bton[i].setBackground(Color.black); // Sets the background color of the buttons to black.
        }

        t_panel.add(textfield); //adds a text field on the panel
        frame.add(t_panel, BorderLayout.NORTH); //positions it NORTH of the frame.
        frame.add(bt_Panel); //ADDS another panel to the interface

        GAME(); //Runs the GAME() Function
    }
    
    public void GAME() { //GAME START FUNCTION that occurs when the game starts
        textfield.setText("Loading...."); //set the text field to loading when trying
        try {
            Thread.sleep(4000);
        } catch (InterruptedException e) { //catcher to catch errors
            e.printStackTrace();
        }
        int chance = randomizer.nextInt(100); //randomizes an integer and sets it to the variable chance.
        P1C = (chance % 2 == 0);
        textfield.setText(P1C ? "Player X turn" : "Player O turn");
    }

    public void gameOver(String message) { //Game over function that occurs when a condition from match check has been met
        chances = 0;
        Object[] options = {"Restart", "Exit"}; //Options that will show up (RESTART OR EXIT)
        int choice = JOptionPane.showOptionDialog(frame, "Game Over\n" + message, "Game Over", 
            JOptionPane.YES_NO_CANCEL_OPTION, JOptionPane.QUESTION_MESSAGE, null, options, options[0]); //This will show up the window that has the options
        if (choice == 0) {  
            frame.dispose();
            new TicTacToeGame();  //if the user wants to play again, we dispose of the old and start a new
        } 
        else {
            frame.dispose(); //otherwise dispose of the game and end the program
        }
    }

    //Function for checking who won
    public void matchCheck() {
        int[][] winConditions = { //2D Array that will store every win condition
            {0, 1, 2}, {0, 3, 6}, {0, 4, 8},
            {1, 4, 7}, {2, 4, 6}, {2, 5, 8},
            {3, 4, 5}, {6, 7, 8}
        };
        
        for (int[] condition : winConditions) { //Going to loop through each winning condition and check if it has been met
            String symbol = bton[condition[0]].getText();
            if (symbol.isEmpty()) { //if symbol is empty, we continue to get out of the for loop
                continue; //continue to break out
            }
            if (symbol.equals(bton[condition[1]].getText()) && symbol.equals(bton[condition[2]].getText())) {  //if all three symbols in the conditon match, there is a winner, so..
                if (symbol.equals("X")) { //If " x " won, we say that X won and show the winning condition
                    xWins(condition[0], condition[1], condition[2]);
                } else {
                    oWins(condition[0], condition[1], condition[2]); //else if " O " won, we say that o won and show the winning condition
                }
                return;
            }
        }
        
        if (chances == 9) { //If neither conditions are met, then we obviously have a draw, so we set the textfield to "GAME DRAW!" to display.
            textfield.setText("Game Draw!!");
            gameOver("Game Draw!!");
        }
    }
    

    // Method to print that Player X won and make the row that won highlighted
    public void xWins(int x1, int x2, int x3) {
        Color yellow = Color.YELLOW;
        for (int i : new int[]{x1, x2, x3}) { //Loop through those winning spots and make them highilated with that WINNING Color 
            bton[i].setBackground(yellow); 
        }
        Arrays.stream(bton).forEach(button -> button.setEnabled(false)); //Make sure all the buttons are disabled as the winner squares are showing and the message is displayed
        textfield.setText("Player X wins"); 
        gameOver("Player X Wins"); //Showing that X won
    }
    

    // Method to print that Player O won and make that row that won highlighted
    public void oWins(int x1, int x2, int x3)  
    {
        bton[x1].setBackground(Color.YELLOW); //Setting all three boxes that won with the color yellow
        bton[x2].setBackground(Color.YELLOW);
        bton[x3].setBackground(Color.YELLOW);

        for (int i = 0; i < 9; i++) 
        {
            bton[i].setEnabled(false); //disabling all 9 buttons (different method)
        }
        textfield.setText("Player O Wins"); //SHOW that O won
        gameOver("Player O Wins");
    }
    
    // Method for performing action after every turn
    
    @Override
    public void actionPerformed(ActionEvent e) {
    for (JButton button : bton) { //Loop through each button from the bton array
        if (e.getSource() == button && button.getText().isEmpty()) {  // Check if the button triggered the event and has no text yet
            if (P1C) { //if it's player 1's turn..
                button.setForeground(new Color(0, 188, 255));
                button.setText("X");
                textfield.setText("O turn");
            } else { //else, it's player O's turn so..
                button.setForeground(new Color(0, 255, 9));
                button.setText("O");
                textfield.setText("X turn");
            }
            P1C = !P1C; //switch to the other players turn 
            chances++; //increment the chance
            matchCheck(); //Check who won by caling the match check function
            break; //break out of the while
        }
    }
}

}

//  main code
class Main 
{
    public static void main(String[] args) throws Exception 
    {
       new TicTacToeGame(); //TICTACTOE METHOD/FUNCTION THAT RUNS THE PROGRAM
    }
}


