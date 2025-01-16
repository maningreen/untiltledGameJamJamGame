#include "button.h"
#include "include.h"

bool positionInRect(Rectangle rect, Vector2 position) {
  return rect.x < position.x && rect.x + rect.width > position.x && rect.y < position.y && rect.y + rect.height > position.y;
}

bool buttonIsPressed(Button* button) {
  Vector2 mousePos = GetMousePosition();
  return positionInRect(button->rect, mousePos) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT);
}

void drawButton(Button* button) {
  DrawRectangleRec(button->rect, button->rectCol);
  Vector2 dems = MeasureTextEx(GetFontDefault(), button->text, button->textSize, GetFontDefault().baseSize);
  DrawText(button->text, (button->rect.width - dems.x) / 2.0f + button->rect.x, button->rect.y + dems.y/2.0f, button->textSize, button->textCol);
}