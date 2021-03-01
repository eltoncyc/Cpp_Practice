// Implementation of class TurtleGraphics.
// Author: Elton Chan
// Date: Feb 28, 2021

#include "TurtleGraphics.h"
#include <iostream>
using namespace std;

TurtleGraphics::TurtleGraphics() :
	pen(STARTING_PEN_POSITION),
	direction(STARTING_DIRECTION),
	row(STARTING_ROW),
	col(STARTING_COL)
{
	// m_floor should be set to all true to begin with
	for (auto &row : m_Floor)
	{
		for (auto &col : row)
		{
			col = true;
		}
	}
}

// Implementation of processTurleMoves
void TurtleGraphics::processTurtleMoves(const array<int, ARRAY_SIZE>& commands)
{
	int cmdNo = 0; // the position in commands array we are curretnly processing

	while (static_cast<Cmds>(commands[cmdNo]) != Cmds::END_OF_DATA && cmdNo < ARRAY_SIZE && commands[cmdNo] > 0)
	{
		switch (static_cast<Cmds>(commands[cmdNo])) {
		case Cmds::PEN_UP: // Pen up
			pen = false;
			break;

		case Cmds::PEN_DWN:
			pen = true;
			break;

		case Cmds::TURN_RIGHT:
			switch (direction) {
			case Directions::NORTH:
				direction = Directions::EAST;
				break;
			case Directions::EAST:
				direction = Directions::SOUTH;
				break;
			case Directions::SOUTH:
				direction = Directions::WEST;
				break;
			case Directions::WEST:
				direction = Directions::NORTH;
				break;
			default:
				cerr << "Incorrect direction when turning right.";
				direction = STARTING_DIRECTION;
				return;
			}
			break;

		case Cmds::TURN_LEFT:
			switch (direction) {
			case Directions::NORTH:
				direction = Directions::WEST;
				break;
			case Directions::EAST:
				direction = Directions::NORTH;
				break;
			case Directions::SOUTH:
				direction = Directions::EAST;
				break;
			case Directions::WEST:
				direction = Directions::SOUTH;
				break;
			default:
				cerr << "Incorrect direction when turning left.";
				direction = STARTING_DIRECTION;
				return;
			}
			break;

		case Cmds::DISPLAY:
			displayFloor();

		case Cmds::MOVE:
			++cmdNo;
			moveTurtle(commands[cmdNo]);
			break;
		
		default:
			cerr << "\n\nERROR - invalid command encountered at commands[" << cmdNo << "]:" << commands[cmdNo] << "\n";
			return;
		}
		++cmdNo; // to the next command
	}
}

// Implementation of moveTurle() to move turle and mark the m_floor
void TurtleGraphics::moveTurtle(const int& numOfSteps)
{
	switch (direction) {
	case Directions::SOUTH:
		for (int i = 0; i < numOfSteps; i++) {
			if (row < NROWS)
			{
				if (pen) {
					m_Floor[row][col] = false;
				}
				if (row < NROWS - 1) {
					++row; // move to the next row if the current position is not at the max row index 
				}
			}
			else {
				break; // exit loop immediately when reaching the edge
			}
		}
		break;

	case Directions::NORTH:
		for (int i = 0; i < numOfSteps; i++) {
			if (row >= 0) {
				if (pen) {
					m_Floor[row][col] = false;
				}
				if (row > STARTING_ROW) {
					--row;
				}
			}
			else {
				break; // exit loop when reaching the edge
			}
		}
		break;

	case Directions::EAST:
		for (int i = 0; i < numOfSteps; i++) {
			if (col < NCOLS) {
				if (pen) {
					m_Floor[row][col] = false;
				}
				if (col < NCOLS - 1) {
					++col;
				}
			}
			else {
				break;// exit loop when reaching the edge
			}
		}
		break;

	case Directions::WEST:
		for (int i = 0; i < numOfSteps; i++) {
			if (col >= 0) {
				if (pen) {
					m_Floor[row][col] = false;
				}
				if (col > STARTING_COL) {
					--col;
				}
			}
			else {
				break;
			}
		}
		break;

	default:
		cerr << "\n\nERROR - invalid command encountered at moveTurtle().\n";
		return;
	}
}

void TurtleGraphics::displayFloor() const
{
	for (auto const &row : m_Floor) {
		for (auto const &column : row) {
			if (!column) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}