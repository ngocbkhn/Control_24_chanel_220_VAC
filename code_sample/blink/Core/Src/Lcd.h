#ifndef _LCD_H
#define _LCD_H

#define LCD_INITIAL_VALUE                   (0x03u)
/** @brief Clear Display Command */
#define CLEAR_DISPLAY_CMD                   (0x01u)
/** @brief Return Home Command */
#define RETURN_HOME_CMD                     (0x02u)

/** @brief Entry Mode Set Command */
#define ENTRY_MODE_SET_CMD(ID, S)           (0x04u | (ID << 1u) | (S))
#define ENTRY_MODE_SET_INCREASE             (0x01u)
#define ENTRY_MODE_SET_DECREASE             (0x00u)
#define ENTRY_MODE_SET_DISPLAY_SHIFT        (0x01u)
#define ENTRY_MODE_SET_NON_DISPLAY_SHIFT    (0x00u)

/** @brief Display Control Command */
#define DISPLAY_CONTROL_CMD(D, C, B)        (0x08u | (D << 2u) | (C << 1u) | (B))
#define DISPLAY_CONTROL_ENTIRE_DISPLAY_ON   (0x01u)
#define DISPLAY_CONTROL_ENTIRE_DISPLAY_OFF  (0x00u)
#define DISPLAY_CONTROL_CURSOR_ON           (0x01u)
#define DISPLAY_CONTROL_CURSOR_OFF          (0x00u)
#define DISPLAY_CONTROL_BLINK_CURSOR_ON     (0x01u)
#define DISPLAY_CONTROL_BLINK_CURSOR_OFF    (0x00u)

/** @brief Cursor or Display Shift Command */
#define CURSOR_OR_DISPLAY_SHIFT_CMD(SC, RL) (0x10u | (SC << 3u) | (RL << 2u))
#define CURSOR_OR_DISPLAY_DISPLAY_SHIFT     (0x01u)
#define CURSOR_OR_DISPLAY_CURSOR_MOVE       (0x00u)
#define CURSOR_OR_DISPLAY_SHIFT2RIGHT       (0x01u)
#define CURSOR_OR_DISPLAY_SHIFT2LEFT        (0x00u)

/** @brief Function Set Command */
#define FUNCTION_SET_CMD(DL, N, F)          (0x20u | (DL << 4u) | (N << 3u) | (F << 2u))
#define FUNCTION_SET_DL_8BIT                (0x01u)
#define FUNCTION_SET_DL_4BIT                (0x00u)
#define FUNCTION_SET_N_2LINES               (0x01u)
#define FUNCTION_SET_N_1LINE                (0x00u)
#define FUNCTION_SET_F_5X10_DOTS            (0x01u)
#define FUNCTION_SET_F_5X8_DOTS             (0x00u)

#define SET_CGRAM_ADDR_CMD(ACG)             (0x40u | (ACG & 0x3Fu))
#define SET_DDRAM_ADDR_CMD(ADD)             (0x80u | (ADD & 0x7Fu))

#define PACK_DATA_4BIT_INTERFACE(RS, E, DATA)   (0x00u | \
                                                ((RS | ((E & 0x01u) << 1u) | ((DATA & 0x0Fu) << 2u))))
void LCD_SendCommand(unsigned char Command);
unsigned char LCD_GotoXY(unsigned char x, unsigned char y);
void LCD_ClearDisplay(void);
void LCD_Init(void);
void LCD_PutChar(unsigned char Character);
void LCD_PutString(unsigned char * const Character);
#endif
