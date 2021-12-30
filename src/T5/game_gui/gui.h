#ifndef GUI_H
#define GUI_H

typedef struct {
    char type;
    int id;
    int phase;  // -1 for elemets displayed in every phase, 0 - input, 1 - placement, 2 - movement, 3 - end 
    void *elem; // element properties, different for every type
    void (*draw)(void *);
    void (*destroyElem)(void *);
} GuiElem;
// constructor and destructor
GuiElem *GuiElem_create(char, int, int, void *, void *, void *);
void GuiElem_destroy(GuiElem *);

typedef struct {
    vector *elems;
    int screenWidth;
    int screenHeight;
    char *windowName;
    void *render;
} GuiContainer;
// constructor and destructor
GuiContainer *init_gui(int, int, char *, int);
void close_gui(GuiContainer *);

typedef struct {
    Rectangle rect;
    bool editMode;
    char *text;
    char *placeHolder;
} TextBoxElem;
// constructor and destructor
TextBoxElem *TextBoxElem_create(Rectangle, bool, char *, char *);
void TextBoxElem_destroy(TextBoxElem *);

typedef struct {
    Rectangle rect; // raylib defined type
    char *text;     // text next to spinner
    int value;      // spinner value
    int rMin;       // range - min value
    int rMax;       // range - max value
    bool editMode;  // if can be edited
} SpinnerElem;
// constructor and destructor
SpinnerElem *SpinnerElem_create(Rectangle, char *, int, int, int, bool);
void SpinnerElem_destroy(SpinnerElem *);

typedef struct {
    int x;
    int y;
    int width;
    int height;
    Color color;
} RectangleElem;
// constructor and destructor
RectangleElem *RectangleElem_create(int, int, int, int, Color);
void RectangleElem_destroy(RectangleElem *);

typedef struct {
    char *value;
    int x;
    int y;
    int fontSize;
    Color fontColor;
} TextElem;
// constructor and destructor
TextElem *TextElem_create( char *, int, int, int, Color);
void TextElem_destroy(TextElem *);

typedef struct {
    Rectangle rect;
    char *text;
    int clicked;
} ButtonElem;
// constructor and destructor
ButtonElem *ButtonElem_create(Rectangle, char *, int);
void ButtonElem_destroy(ButtonElem *);
#endif
