#pragma once
#include <array>

// Define some enum types that will be used in solution

enum class Cmds : unsigned short { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum class Directions : unsigned short { NORTH, EAST, SOUTH, WEST };

class TurtleGraphics
{
private:
	const static size_t NROWS = 22;  // number of rows in floor
	const static size_t NCOLS = 70;  // number of colums in floor

	const static int STARTING_ROW = 0;    // row that turtle will start in
	const static int STARTING_COL = 0;    // column that turtle will start in

	const static Directions STARTING_DIRECTION = Directions::SOUTH; // direction 
	                      // that turtle will be facing at the start

	const static bool STARTING_PEN_POSITION = false; // Pen will be up when 
	                            // program starts
                                // false means pen up, true means pen down

	void displayFloor() const;  // will display floor on the screen
	
	void moveTurtle(const int& numOfSteps);

	std::array <std::array <bool, NCOLS>, NROWS> m_Floor;   // floor on which turtle will draw

	// additional member data
	bool pen; // current pen state
	Directions direction; //current direction
	int row; // current row position
	int col; // current column position
	
public:
	const static int ARRAY_SIZE = 250;

	TurtleGraphics(void); //ctor will init. floor to all "true" values, 
	                      //     as well as initialization of other data members
	void processTurtleMoves( const std::array< int, ARRAY_SIZE> &);  // will process
	                   // the commands contained in array "commands"	
};


