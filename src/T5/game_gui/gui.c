#include "raylib.h"
#include "../defines.h"
#include <stdlib.h>
#include <queue.h>
#include <vector.h>
#include <assert.h>
#include "gui.h"

GuiContainer *init_gui(const int screenWidth, const int screenHeight, char *windowName, int frameRate) {
    GuiContainer *gui = malloc(sizeof(GuiContainer));
    assert(gui != NULL);
    gui->screenWidth = screenWidth;
    gui->screenHeight = screenHeight;
    gui->windowName = windowName;
    
    gui->elems = vector_create(sizeof(GuiElem));
    
    InitWindow(screenWidth, screenHeight, windowName);
    SetExitKey(0);
    SetTargetFPS(frameRate); 
 
    return gui;
}

void close_gui(GuiContainer *gui) {
    while (!vector_empty(gui->elems)) {
        GuiElem *elem;
        vector_back(gui->elems, elem);
        GuiElem_destroy(elem);
        vector_pop(gui->elems);
    }
    vector_destroy(gui->elems);
    free(gui);
}

GuiElem *GuiElem_create(char type, int id, int phase, void *elem, void *draw, void *destroyElem) {
    GuiElem *guiElem = malloc(sizeof(GuiElem));
    guiElem->type = type;  
    guiElem->id = id;
    guiElem->phase = phase;
    guiElem->elem = elem;
    guiElem->draw = draw;
    guiElem->destroyElem = destroyElem;
    return guiElem;
}

void GuiElem_destroy(GuiElem *guiElem) {
    if (guiElem->destroyElem != NULL)
        guiElem->destroyElem(guiElem->elem);
    free(guiElem);
}

TextBoxElem *TextBoxElem_create(Rectangle rect, bool editMode, char *text, char *placeHolder) {
    TextBoxElem *textBox = malloc(sizeof(TextBoxElem));
    textBox->editMode = editMode;
    textBox->text = text;
    textBox->placeHolder = placeHolder;
    textBox->rect = rect;
    return textBox;
}

void TextBoxElem_destroy(TextBoxElem *textBox) {
    free(textBox);
}

SpinnerElem *SpinnerElem_create(Rectangle rect, char *text, int value, int rMin, int rMax, bool editMode) {
    SpinnerElem *spinner = malloc(sizeof(SpinnerElem));
    spinner->rect = rect;
    spinner->text = text;
    spinner->value = value;
    spinner->rMin = rMin;
    spinner->rMax = rMax;
    spinner->editMode = editMode;
    return spinner;
}

void SpinnerElem_destroy(SpinnerElem *spinner) {
    free(spinner);
}

RectangleElem *RectangleElem_create(int x, int y, int width, int height, Color color) {
    RectangleElem *rectangle = malloc(sizeof(RectangleElem));
    rectangle->x = x;
    rectangle->y = y;
    rectangle->width = width;
    rectangle->height = height;
    rectangle->color = color;
    return rectangle;
}

void RectangleElem_destroy(RectangleElem *rectangle) {
    free(rectangle);
}

TextElem *TextElem_create(char *value, int x, int y, int fontSize, Color fontColor) {
    TextElem *text = malloc(sizeof(TextElem));
    text->value = value;
    text->x = x;
    text->y = y;
    text->fontSize = fontSize;
    text->fontColor = fontColor;
    return text;
}

void TextElem_destroy(TextElem *text) {
    free(text);
}

ButtonElem *ButtonElem_create(Rectangle rect, char *text, int clicked) {
    ButtonElem *button = malloc(sizeof(ButtonElem));
    button->rect = rect;
    button->text = text;
    button->clicked = clicked;
    return button;
}

void ButtonElem_destroy(ButtonElem *button) {
    free(button);
}
