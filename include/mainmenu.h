//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// StyleAsCode exporter v2.0 - Style data exported as a values array            //
//                                                                              //
// USAGE: On init call: GuiLoadStyleMainMenu();                                   //
//                                                                              //
// more info and bugs-report:  github.com/raysan5/raygui                        //
// feedback and support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2020-2023 raylib technologies (@raylibtech)                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#define MAINMENU_STYLE_PROPS_COUNT  15

// Custom style name: mainMenu
static const GuiStyleProp mainmenuStyleProps[MAINMENU_STYLE_PROPS_COUNT] = {
    { 0, 0, 0xffffffff },    // DEFAULT_BORDER_COLOR_NORMAL 
    { 0, 1, 0x000000ff },    // DEFAULT_BASE_COLOR_NORMAL 
    { 0, 2, 0xffffffff },    // DEFAULT_TEXT_COLOR_NORMAL 
    { 0, 3, 0xffffffff },    // DEFAULT_BORDER_COLOR_FOCUSED 
    { 0, 4, 0x000000ff },    // DEFAULT_BASE_COLOR_FOCUSED 
    { 0, 5, 0xffffffff },    // DEFAULT_TEXT_COLOR_FOCUSED 
    { 0, 6, 0x00ff00ff },    // DEFAULT_BORDER_COLOR_PRESSED 
    { 0, 7, 0x000000ff },    // DEFAULT_BASE_COLOR_PRESSED 
    { 0, 8, 0xffffffff },    // DEFAULT_TEXT_COLOR_PRESSED 
    { 0, 16, 0x00000019 },    // DEFAULT_TEXT_SIZE 
    { 0, 18, 0xff0000ff },    // DEFAULT_LINE_COLOR 
    { 0, 19, 0x000000ff },    // DEFAULT_BACKGROUND_COLOR 
    { 0, 20, 0x0000000f },    // DEFAULT_TEXT_LINE_SPACING 
    { 2, 12, 0x00000005 },    // BUTTON_BORDER_WIDTH
	{ 3, 12, 0x00000005 },    // TOGGLE_BORDER_WIDTH 
};

// Style loading function: mainMenu
static void GuiLoadStyleMainMenu(void)
{
    // Load style properties provided
    // NOTE: Default properties are propagated
    for (int i = 0; i < MAINMENU_STYLE_PROPS_COUNT; i++)
    {
        GuiSetStyle(mainmenuStyleProps[i].controlId, mainmenuStyleProps[i].propertyId, mainmenuStyleProps[i].propertyValue);
    }

    //-----------------------------------------------------------------

    // TODO: Custom user style setup: Set specific properties here (if required)
    // i.e. Controls specific BORDER_WIDTH, TEXT_PADDING, TEXT_ALIGNMENT
}
