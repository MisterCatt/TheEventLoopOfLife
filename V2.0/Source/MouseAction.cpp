#include "MouseAction.h"

MouseAction::MouseAction()
{
	tm = TileManager::GetInstance();
	selected = false;
}

MouseAction::~MouseAction()
{
}

void MouseAction::Update()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		selectedTile = tm->GetTile((int)GetMousePosition().x, (int)GetMousePosition().y);
		std::cout << "X: " << (float)GetMousePosition().x << " Y: " << (float)GetMousePosition().y << std::endl;

		
		std::cout << "TileX: " << floor(selectedTile.GetTileBox().x / 20) << " TileY: " << floor(selectedTile.GetTileBox().y / 20) << std::endl;
		std::cout << "TileType: " << selectedTile.GetTileType() << std::endl;
		std::cout << "Energy: " << selectedTile.GetEnergy() << std::endl;
		std::cout << std::endl;

		selected = true;
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
		selected = false;
	}

	
}

void MouseAction::Render()
{
	if (!selected)
		return;
	
	DrawRectangle((int)floor(selectedTile.GetTileBox().x /20)*40, (int)floor(selectedTile.GetTileBox().y / 20)*40, (int)selectedTile.GetTileBox().width, (int)selectedTile.GetTileBox().height, RED);
}
