#pragma once
#include <vector>
#include <iostream>
class Game final
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update(float elapsedSec);
	void Draw() const;

	// Event handling
	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e);
	void ProcessMouseDownEvent(const SDL_MouseButtonEvent& e);
	void ProcessMouseUpEvent(const SDL_MouseButtonEvent& e);

private:
	// DATA MEMBERS
	const Window m_Window;
	std::vector<int> m_Sudoku{};
	 

	std::vector<std::vector<int>*> m_Rows;
	std::vector<int>* m_Row1;
	std::vector<int>* m_Row2;
	std::vector<int>* m_Row3;
	std::vector<int>* m_Row4;
	std::vector<int>* m_Row5;
	std::vector<int>* m_Row6;
	std::vector<int>* m_Row7;
	std::vector<int>* m_Row8;
	std::vector<int>* m_Row9;

	std::vector<std::vector<int>*> m_Columns;
	std::vector<int>* m_Column1;
	std::vector<int>* m_Column2;
	std::vector<int>* m_Column3;
	std::vector<int>* m_Column4;
	std::vector<int>* m_Column5;
	std::vector<int>* m_Column6;
	std::vector<int>* m_Column7;
	std::vector<int>* m_Column8;
	std::vector<int>* m_Column9;

	std::vector<std::vector<int>*> m_Squares;
	std::vector<int>* m_Square1;
	std::vector<int>* m_Square2;
	std::vector<int>* m_Square3;
	std::vector<int>* m_Square4;
	std::vector<int>* m_Square5;
	std::vector<int>* m_Square6;
	std::vector<int>* m_Square7;
	std::vector<int>* m_Square8;
	std::vector<int>* m_Square9;

	int m_AmountOfSolutions{};

	const std::vector<int> m_Values{
	1,2,3,4,5,6,7,8,9};
	std::vector<int> m_TestValues{
	1,2,3,4,5,6,7,8,9 };
	// FUNCTIONS
	void Initialize();
	void Cleanup();
	void ClearBackground() const;

	int GetRandInt(std::vector<int>& values);
	void FillFullSudoku();
	bool FillNextNumber(int index);
	bool IsCurrentNumberValid(int index, std::vector<int> sudoku);
	void EmptyCells(std::vector<int>& sudoku);

	std::vector<int> SolveSudoku(std::vector<int>& sudoku);
	bool FillNextNumberSolver(int index, std::vector<int>& sudoku);
};