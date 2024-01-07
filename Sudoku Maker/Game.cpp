#include "pch.h"
#include "Game.h"

Game::Game(const Window& window)
	:m_Window{ window }
{
	Initialize();
}

Game::~Game()
{
	Cleanup();
}

void Game::Initialize()
{
	std::srand(int(time(nullptr)));
	m_Sudoku.assign(81, 0);
	//initialize all rows
	m_Row1 = new std::vector<int>{};
	m_Row2 = new std::vector<int>{};
	m_Row3 = new std::vector<int>{};
	m_Row4 = new std::vector<int>{};
	m_Row5 = new std::vector<int>{};
	m_Row6 = new std::vector<int>{};
	m_Row7 = new std::vector<int>{};
	m_Row8 = new std::vector<int>{};
	m_Row9 = new std::vector<int>{};

	//initialize all columns
	m_Column1 = new std::vector<int>{};
	m_Column2 = new std::vector<int>{};
	m_Column3 = new std::vector<int>{};
	m_Column4 = new std::vector<int>{};
	m_Column5 = new std::vector<int>{};
	m_Column6 = new std::vector<int>{};
	m_Column7 = new std::vector<int>{};
	m_Column8 = new std::vector<int>{};
	m_Column9 = new std::vector<int>{};

	//initialize all squares
	m_Square1 = new std::vector<int>{};
	m_Square2 = new std::vector<int>{};
	m_Square3 = new std::vector<int>{};
	m_Square4 = new std::vector<int>{};
	m_Square5 = new std::vector<int>{};
	m_Square6 = new std::vector<int>{};
	m_Square7 = new std::vector<int>{};
	m_Square8 = new std::vector<int>{};
	m_Square9 = new std::vector<int>{};

	//push back all rows in m_Rows
	m_Rows.push_back(m_Row1);
	m_Rows.push_back(m_Row2);
	m_Rows.push_back(m_Row3);
	m_Rows.push_back(m_Row4);
	m_Rows.push_back(m_Row5);
	m_Rows.push_back(m_Row6);
	m_Rows.push_back(m_Row7);
	m_Rows.push_back(m_Row8);
	m_Rows.push_back(m_Row9);


	//push back all columns in m_Columns
	m_Columns.push_back(m_Column1);
	m_Columns.push_back(m_Column2);
	m_Columns.push_back(m_Column3);
	m_Columns.push_back(m_Column4);
	m_Columns.push_back(m_Column5);
	m_Columns.push_back(m_Column6);
	m_Columns.push_back(m_Column7);
	m_Columns.push_back(m_Column8);
	m_Columns.push_back(m_Column9);

	//push back all squares in m_Squares
	m_Squares.push_back(m_Square1);
	m_Squares.push_back(m_Square2);
	m_Squares.push_back(m_Square3);
	m_Squares.push_back(m_Square4);
	m_Squares.push_back(m_Square5);
	m_Squares.push_back(m_Square6);
	m_Squares.push_back(m_Square7);
	m_Squares.push_back(m_Square8);
	m_Squares.push_back(m_Square9);

	//forloop hell van initialisatie
	for (int i{}; i < 80; i += 9)
	{
		switch (i / 9)
		{
		case 0:
			m_Row1->push_back(i);
			m_Row1->push_back(i + 1);
			m_Row1->push_back(i + 2);
			m_Row1->push_back(i + 3);
			m_Row1->push_back(i + 4);
			m_Row1->push_back(i + 5);
			m_Row1->push_back(i + 6);
			m_Row1->push_back(i + 7);
			m_Row1->push_back(i + 8);
			break;
		case 1:
			m_Row2->push_back(i);
			m_Row2->push_back(i + 1);
			m_Row2->push_back(i + 2);
			m_Row2->push_back(i + 3);
			m_Row2->push_back(i + 4);
			m_Row2->push_back(i + 5);
			m_Row2->push_back(i + 6);
			m_Row2->push_back(i + 7);
			m_Row2->push_back(i + 8);
			break;
		case 2:
			m_Row3->push_back(i);
			m_Row3->push_back(i + 1);
			m_Row3->push_back(i + 2);
			m_Row3->push_back(i + 3);
			m_Row3->push_back(i + 4);
			m_Row3->push_back(i + 5);
			m_Row3->push_back(i + 6);
			m_Row3->push_back(i + 7);
			m_Row3->push_back(i + 8);
			break;
		case 3:
			m_Row4->push_back(i);
			m_Row4->push_back(i + 1);
			m_Row4->push_back(i + 2);
			m_Row4->push_back(i + 3);
			m_Row4->push_back(i + 4);
			m_Row4->push_back(i + 5);
			m_Row4->push_back(i + 6);
			m_Row4->push_back(i + 7);
			m_Row4->push_back(i + 8);
			break;
		case 4:
			m_Row5->push_back(i);
			m_Row5->push_back(i + 1);
			m_Row5->push_back(i + 2);
			m_Row5->push_back(i + 3);
			m_Row5->push_back(i + 4);
			m_Row5->push_back(i + 5);
			m_Row5->push_back(i + 6);
			m_Row5->push_back(i + 7);
			m_Row5->push_back(i + 8);
			break;
		case 5:
			m_Row6->push_back(i);
			m_Row6->push_back(i + 1);
			m_Row6->push_back(i + 2);
			m_Row6->push_back(i + 3);
			m_Row6->push_back(i + 4);
			m_Row6->push_back(i + 5);
			m_Row6->push_back(i + 6);
			m_Row6->push_back(i + 7);
			m_Row6->push_back(i + 8);
			break;
		case 6:
			m_Row7->push_back(i);
			m_Row7->push_back(i + 1);
			m_Row7->push_back(i + 2);
			m_Row7->push_back(i + 3);
			m_Row7->push_back(i + 4);
			m_Row7->push_back(i + 5);
			m_Row7->push_back(i + 6);
			m_Row7->push_back(i + 7);
			m_Row7->push_back(i + 8);
			break;
		case 7:
			m_Row8->push_back(i);
			m_Row8->push_back(i + 1);
			m_Row8->push_back(i + 2);
			m_Row8->push_back(i + 3);
			m_Row8->push_back(i + 4);
			m_Row8->push_back(i + 5);
			m_Row8->push_back(i + 6);
			m_Row8->push_back(i + 7);
			m_Row8->push_back(i + 8);
			break;
		case 8:
			m_Row9->push_back(i);
			m_Row9->push_back(i + 1);
			m_Row9->push_back(i + 2);
			m_Row9->push_back(i + 3);
			m_Row9->push_back(i + 4);
			m_Row9->push_back(i + 5);
			m_Row9->push_back(i + 6);
			m_Row9->push_back(i + 7);
			m_Row9->push_back(i + 8);
			break;
		}
	}
	for (int i{}; i < 9; ++i)
	{
		switch (i)
		{
		case 0:
			m_Column1->push_back((*m_Row1)[i]);
			m_Column1->push_back((*m_Row2)[i]);
			m_Column1->push_back((*m_Row3)[i]);
			m_Column1->push_back((*m_Row4)[i]);
			m_Column1->push_back((*m_Row5)[i]);
			m_Column1->push_back((*m_Row6)[i]);
			m_Column1->push_back((*m_Row7)[i]);
			m_Column1->push_back((*m_Row8)[i]);
			m_Column1->push_back((*m_Row9)[i]);
			break;
		case 1:
			m_Column2->push_back((*m_Row1)[i]);
			m_Column2->push_back((*m_Row2)[i]);
			m_Column2->push_back((*m_Row3)[i]);
			m_Column2->push_back((*m_Row4)[i]);
			m_Column2->push_back((*m_Row5)[i]);
			m_Column2->push_back((*m_Row6)[i]);
			m_Column2->push_back((*m_Row7)[i]);
			m_Column2->push_back((*m_Row8)[i]);
			m_Column2->push_back((*m_Row9)[i]);
			break;
		case 2:
			m_Column3->push_back((*m_Row1)[i]);
			m_Column3->push_back((*m_Row2)[i]);
			m_Column3->push_back((*m_Row3)[i]);
			m_Column3->push_back((*m_Row4)[i]);
			m_Column3->push_back((*m_Row5)[i]);
			m_Column3->push_back((*m_Row6)[i]);
			m_Column3->push_back((*m_Row7)[i]);
			m_Column3->push_back((*m_Row8)[i]);
			m_Column3->push_back((*m_Row9)[i]);
			break;
		case 3:
			m_Column4->push_back((*m_Row1)[i]);
			m_Column4->push_back((*m_Row2)[i]);
			m_Column4->push_back((*m_Row3)[i]);
			m_Column4->push_back((*m_Row4)[i]);
			m_Column4->push_back((*m_Row5)[i]);
			m_Column4->push_back((*m_Row6)[i]);
			m_Column4->push_back((*m_Row7)[i]);
			m_Column4->push_back((*m_Row8)[i]);
			m_Column4->push_back((*m_Row9)[i]);
			break;
		case 4:
			m_Column5->push_back((*m_Row1)[i]);
			m_Column5->push_back((*m_Row2)[i]);
			m_Column5->push_back((*m_Row3)[i]);
			m_Column5->push_back((*m_Row4)[i]);
			m_Column5->push_back((*m_Row5)[i]);
			m_Column5->push_back((*m_Row6)[i]);
			m_Column5->push_back((*m_Row7)[i]);
			m_Column5->push_back((*m_Row8)[i]);
			m_Column5->push_back((*m_Row9)[i]);
			break;
		case 5:
			m_Column6->push_back((*m_Row1)[i]);
			m_Column6->push_back((*m_Row2)[i]);
			m_Column6->push_back((*m_Row3)[i]);
			m_Column6->push_back((*m_Row4)[i]);
			m_Column6->push_back((*m_Row5)[i]);
			m_Column6->push_back((*m_Row6)[i]);
			m_Column6->push_back((*m_Row7)[i]);
			m_Column6->push_back((*m_Row8)[i]);
			m_Column6->push_back((*m_Row9)[i]);
			break;
		case 6:
			m_Column7->push_back((*m_Row1)[i]);
			m_Column7->push_back((*m_Row2)[i]);
			m_Column7->push_back((*m_Row3)[i]);
			m_Column7->push_back((*m_Row4)[i]);
			m_Column7->push_back((*m_Row5)[i]);
			m_Column7->push_back((*m_Row6)[i]);
			m_Column7->push_back((*m_Row7)[i]);
			m_Column7->push_back((*m_Row8)[i]);
			m_Column7->push_back((*m_Row9)[i]);
			break;
		case 7:
			m_Column8->push_back((*m_Row1)[i]);
			m_Column8->push_back((*m_Row2)[i]);
			m_Column8->push_back((*m_Row3)[i]);
			m_Column8->push_back((*m_Row4)[i]);
			m_Column8->push_back((*m_Row5)[i]);
			m_Column8->push_back((*m_Row6)[i]);
			m_Column8->push_back((*m_Row7)[i]);
			m_Column8->push_back((*m_Row8)[i]);
			m_Column8->push_back((*m_Row9)[i]);
			break;
		case 8:
			m_Column9->push_back((*m_Row1)[i]);
			m_Column9->push_back((*m_Row2)[i]);
			m_Column9->push_back((*m_Row3)[i]);
			m_Column9->push_back((*m_Row4)[i]);
			m_Column9->push_back((*m_Row5)[i]);
			m_Column9->push_back((*m_Row6)[i]);
			m_Column9->push_back((*m_Row7)[i]);
			m_Column9->push_back((*m_Row8)[i]);
			m_Column9->push_back((*m_Row9)[i]);
			break;
		}
	}
	for (int i{}; i < 9; ++i)
	{
		switch (i)
		{
		case 0:
			m_Square1->push_back((*m_Row1)[0]);
			m_Square1->push_back((*m_Row1)[1]);
			m_Square1->push_back((*m_Row1)[2]);
			m_Square1->push_back((*m_Row2)[0]);
			m_Square1->push_back((*m_Row2)[1]);
			m_Square1->push_back((*m_Row2)[2]);
			m_Square1->push_back((*m_Row3)[0]);
			m_Square1->push_back((*m_Row3)[1]);
			m_Square1->push_back((*m_Row3)[2]);
			break;
		case 1:
			m_Square2->push_back((*m_Row1)[3]);
			m_Square2->push_back((*m_Row1)[4]);
			m_Square2->push_back((*m_Row1)[5]);
			m_Square2->push_back((*m_Row2)[3]);
			m_Square2->push_back((*m_Row2)[4]);
			m_Square2->push_back((*m_Row2)[5]);
			m_Square2->push_back((*m_Row3)[3]);
			m_Square2->push_back((*m_Row3)[4]);
			m_Square2->push_back((*m_Row3)[5]);
			break;
		case 2:
			m_Square3->push_back((*m_Row1)[6]);
			m_Square3->push_back((*m_Row1)[7]);
			m_Square3->push_back((*m_Row1)[8]);
			m_Square3->push_back((*m_Row2)[6]);
			m_Square3->push_back((*m_Row2)[7]);
			m_Square3->push_back((*m_Row2)[8]);
			m_Square3->push_back((*m_Row3)[6]);
			m_Square3->push_back((*m_Row3)[7]);
			m_Square3->push_back((*m_Row3)[8]);
			break;
		case 3:
			m_Square4->push_back((*m_Row4)[0]);
			m_Square4->push_back((*m_Row4)[1]);
			m_Square4->push_back((*m_Row4)[2]);
			m_Square4->push_back((*m_Row5)[0]);
			m_Square4->push_back((*m_Row5)[1]);
			m_Square4->push_back((*m_Row5)[2]);
			m_Square4->push_back((*m_Row6)[0]);
			m_Square4->push_back((*m_Row6)[1]);
			m_Square4->push_back((*m_Row6)[2]);
			break;
		case 4:
			m_Square5->push_back((*m_Row4)[3]);
			m_Square5->push_back((*m_Row4)[4]);
			m_Square5->push_back((*m_Row4)[5]);
			m_Square5->push_back((*m_Row5)[3]);
			m_Square5->push_back((*m_Row5)[4]);
			m_Square5->push_back((*m_Row5)[5]);
			m_Square5->push_back((*m_Row6)[3]);
			m_Square5->push_back((*m_Row6)[4]);
			m_Square5->push_back((*m_Row6)[5]);
			break;
		case 5:
			m_Square6->push_back((*m_Row4)[6]);
			m_Square6->push_back((*m_Row4)[7]);
			m_Square6->push_back((*m_Row4)[8]);
			m_Square6->push_back((*m_Row5)[6]);
			m_Square6->push_back((*m_Row5)[7]);
			m_Square6->push_back((*m_Row5)[8]);
			m_Square6->push_back((*m_Row6)[6]);
			m_Square6->push_back((*m_Row6)[7]);
			m_Square6->push_back((*m_Row6)[8]);
			break;
		case 6:
			m_Square7->push_back((*m_Row7)[0]);
			m_Square7->push_back((*m_Row7)[1]);
			m_Square7->push_back((*m_Row7)[2]);
			m_Square7->push_back((*m_Row8)[0]);
			m_Square7->push_back((*m_Row8)[1]);
			m_Square7->push_back((*m_Row8)[2]);
			m_Square7->push_back((*m_Row9)[0]);
			m_Square7->push_back((*m_Row9)[1]);
			m_Square7->push_back((*m_Row9)[2]);
			break;
		case 7:
			m_Square8->push_back((*m_Row7)[3]);
			m_Square8->push_back((*m_Row7)[4]);
			m_Square8->push_back((*m_Row7)[5]);
			m_Square8->push_back((*m_Row8)[3]);
			m_Square8->push_back((*m_Row8)[4]);
			m_Square8->push_back((*m_Row8)[5]);
			m_Square8->push_back((*m_Row9)[3]);
			m_Square8->push_back((*m_Row9)[4]);
			m_Square8->push_back((*m_Row9)[5]);
			break;
		case 8:
			m_Square9->push_back((*m_Row7)[6]);
			m_Square9->push_back((*m_Row7)[7]);
			m_Square9->push_back((*m_Row7)[8]);
			m_Square9->push_back((*m_Row8)[6]);
			m_Square9->push_back((*m_Row8)[7]);
			m_Square9->push_back((*m_Row8)[8]);
			m_Square9->push_back((*m_Row9)[6]);
			m_Square9->push_back((*m_Row9)[7]);
			m_Square9->push_back((*m_Row9)[8]);
			break;
		}
	}

	FillFullSudoku();
	for (int i{}; i < 80; i += 9)
	{
		std::cout << m_Sudoku[i] << "|" << m_Sudoku[i + 1] << "|" << m_Sudoku[i + 2] << "|" << m_Sudoku[i + 3] << "|" << m_Sudoku[i + 4]
			<< "|" << m_Sudoku[i + 5] << "|" << m_Sudoku[i + 6] << "|" << m_Sudoku[i + 7] << "|" << m_Sudoku[i + 8] << "|\n";
	}
	EmptyCells(m_Sudoku);
	std::cout << "\n";
	for (int i{}; i < 80; i += 9)
	{
		std::cout << m_Sudoku[i] << "|" << m_Sudoku[i + 1] << "|" << m_Sudoku[i + 2] << "|" << m_Sudoku[i + 3] << "|" << m_Sudoku[i + 4]
			<< "|" << m_Sudoku[i + 5] << "|" << m_Sudoku[i + 6] << "|" << m_Sudoku[i + 7] << "|" << m_Sudoku[i + 8] << "|\n";
	}
}

void Game::Cleanup()
{
	for (int i{}; i < m_Rows.size(); ++i)
	{
		delete m_Rows[i];
		m_Rows[i] = nullptr;
	}

	for (int i{}; i < m_Columns.size(); ++i)
	{
		delete m_Columns[i];
		m_Columns[i] = nullptr;
	}

	for (int i{}; i < m_Squares.size(); ++i)
	{
		delete m_Squares[i];
		m_Squares[i] = nullptr;
	}
}

void Game::Update(float elapsedSec)
{
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void Game::Draw() const
{
	ClearBackground();
}

void Game::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground() const
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

int Game::GetRandInt(std::vector<int>& values)
{
	int returnValue{ values[rand() % values.size()] };
	return returnValue;
}

void Game::FillFullSudoku()
{
	std::vector<int> testValues = m_Values;
	m_Sudoku[0] = GetRandInt(testValues);
	while (!IsCurrentNumberValid(0, m_Sudoku))
	{
		for (int j{}; j < testValues.size(); ++j)
		{
			if (testValues[j] == m_Sudoku[0])
			{
				testValues.erase(testValues.begin() + j);
			}
		}
		m_Sudoku[0] = GetRandInt(testValues);
	}
	FillNextNumber(1);
}
bool Game::FillNextNumber(int index)
{
	std::vector<int> testValues{ m_Values };
	bool lookingForNumber{ true };
	while (lookingForNumber)
	{
		while (!IsCurrentNumberValid(index, m_Sudoku))
		{
			m_Sudoku[index] = GetRandInt(testValues);
			for (int j{}; j < testValues.size(); ++j)
			{
				if (testValues[j] == m_Sudoku[index])
				{
					testValues.erase(testValues.begin() + j);
				}
			}
			if (testValues.size() == 0)
			{
				m_Sudoku[index] = 0;
				return false;
			}
		}
		if (index != 80)
		{
			if (FillNextNumber(++index))
			{
				return true;
			}
			m_Sudoku[index] = 0;
		}
		if (index == 80)
		{
			return true;
		}
	}
	return false;
}
bool Game::IsCurrentNumberValid(int index, std::vector<int> sudoku)
{
	int currentRow{ index / 9 };
	int currentColumn{ index % 9 };
	int currentSquare{};
	bool foundCurrentSquare{ false };
	if (sudoku[index] == 0)
	{
		return false;
	}
	for (std::vector<int>* square : m_Squares)
	{
		for (int i : (*square))
		{
			if (i == index)
			{
				foundCurrentSquare = true;
				break;
			}
		}
		if (foundCurrentSquare)
		{
			break;
		}
		++currentSquare;
	}

	for (int i : (*m_Rows[currentRow]))
	{
		if (i != index)
		{
			if (sudoku[i] == sudoku[index])
			{
				return false;
			}
		}
	}

	for (int i : (*m_Columns[currentColumn]))
	{
		if (i != index)
		{
			if (sudoku[i] == sudoku[index])
			{
				return false;
			}
		}
	}

	for (int i : (*m_Squares[currentSquare]))
	{
		if (i != index)
		{
			if (sudoku[i] == sudoku[index])
			{
				return false;
			}
		}
	}
	return true;
}
void Game::EmptyCells(std::vector<int>& sudoku)
{
	std::vector<int> sudokuMakerHelper{};
	int lastThrownInt{};
	int indexRemoverHelper{};
	int lastThrownIndex{};
	for (int i{}; i < 81; ++i)
	{
		sudokuMakerHelper.push_back(i);
	}
	while (sudokuMakerHelper.size() != 0)
	{
		indexRemoverHelper = rand() % sudokuMakerHelper.size();
		lastThrownIndex = sudokuMakerHelper[indexRemoverHelper];
		lastThrownInt = sudoku[lastThrownIndex];
		sudoku[sudokuMakerHelper[indexRemoverHelper]] = 0;
		sudokuMakerHelper.erase(sudokuMakerHelper.begin() + indexRemoverHelper);
		std::vector<int> solveTestCopy{ sudoku };
		SolveSudoku(solveTestCopy);
		if (m_AmountOfSolutions != 1)
		{
			sudoku[lastThrownIndex] = lastThrownInt;
		}

	}


}
std::vector<int> Game::SolveSudoku(std::vector<int>& sudoku)
{
	m_AmountOfSolutions = 0;
	if (sudoku[0] != 0)
	{
		if (FillNextNumberSolver(1, sudoku))
		{
			return sudoku;
		}
	}
	else
	{
		std::vector<int> testValues = m_Values;
		sudoku[0] = GetRandInt(testValues);
		while (!IsCurrentNumberValid(0, sudoku))
		{
			for (int j{}; j < testValues.size(); ++j)
			{
				if (testValues[j] == sudoku[0])
				{
					testValues.erase(testValues.begin() + j);
				}
			}
			sudoku[0] = GetRandInt(testValues);
		}
		if (FillNextNumberSolver(1, sudoku))
		{
			return sudoku;
		}
	}
	return std::vector<int>{};
}
bool Game::FillNextNumberSolver(int index, std::vector<int>& sudoku)
{
	if (sudoku[index] != 0)
	{
		if (index != 80)
		{
			if (FillNextNumberSolver(++index, sudoku))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (index == 80)
		{
			++m_AmountOfSolutions;
			return false;
		}
	}
	if (sudoku[index] == 0)
	{
		std::vector<int> testValues{ m_Values };
		bool lookingForNumber{ true };
		while (lookingForNumber)
		{
			while (!IsCurrentNumberValid(index, sudoku))
			{
				sudoku[index] = GetRandInt(testValues);
				for (int j{}; j < testValues.size(); ++j)
				{
					if (testValues[j] == sudoku[index])
					{
						testValues.erase(testValues.begin() + j);
					}
				}
				if (testValues.size() == 0)
				{
					sudoku[index] = 0;
					return false;
				}
			}
			if (index != 80)
			{
				if (FillNextNumberSolver(++index, sudoku))
				{
					return true;
				}
				sudoku[index] = 0;
			}
			if (index == 80)
			{
				++m_AmountOfSolutions;
				return false;
			}
		}
	}
	return false;
}