#include "stm32f1xx_hal.h"
#include "Lcd.h"
#include "ShiftReg.h"

#define ROW_MAX_LENGTH  (0x28u)
#define COL_MAX_LENGTH  (0x02u)
typedef enum
{
  COMMAND = 0x00u,
  DATA,
}LcdInstructionType;

static void LCD_Send4Bit(unsigned int Data);
static void LCD_LInit(void);

/** @brief Init LCD (IC HD44780)
 * @param None
 * @return None
*/
void LCD_Init(void)
{
  LCD_LInit();
  /** @brief 0x02 */
  LCD_SendCommand(RETURN_HOME_CMD);
  LCD_SendCommand(ENTRY_MODE_SET_CMD(ENTRY_MODE_SET_INCREASE, \
                  ENTRY_MODE_SET_NON_DISPLAY_SHIFT));
  /** @brief 0x28 */
  LCD_SendCommand(FUNCTION_SET_CMD(FUNCTION_SET_DL_4BIT, \
                  FUNCTION_SET_N_2LINES, \
                  FUNCTION_SET_F_5X8_DOTS));

  /** @brief 0x0E */
  LCD_SendCommand(DISPLAY_CONTROL_CMD(DISPLAY_CONTROL_ENTIRE_DISPLAY_ON, \
                  DISPLAY_CONTROL_CURSOR_OFF, \
                  DISPLAY_CONTROL_BLINK_CURSOR_OFF));
}

/** @brief Internal function to Initialize
 * @param None
 * @return None
*/
static void LCD_LInit(void)
{
  /* Initialization */
  /* Send 0x03 */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              1, LCD_INITIAL_VALUE));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              0, LCD_INITIAL_VALUE));
  HAL_Delay(1);
  /* Send 0x03 */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              1, LCD_INITIAL_VALUE));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              0, LCD_INITIAL_VALUE));
  HAL_Delay(1);
  /* Send 0x03 */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              1, LCD_INITIAL_VALUE));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, \
              0, LCD_INITIAL_VALUE));
  HAL_Delay(1);
}

/** @brief Write a command to LCD
 * @param Command
 * @return None
*/
void LCD_SendCommand(unsigned char Command)
{
  /* Make a falling edge on Pin E to write 4 bit high */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 1, \
    (Command & 0xF0u) >> 4u));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 0, \
    (Command & 0xF0u) >> 4u));
  /* Make a falling edge on Pin E to write 4 bit low */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 1, \
    Command & 0x0Fu));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(COMMAND, 0, \
    Command & 0x0Fu));
}

/** @brief Goto position on screen
 * @param x Column index
 * @param y Row index
 * @return True if the position is valid
 */
unsigned char LCD_GotoXY(unsigned char x, unsigned char y)
{
  unsigned char retVal = 1;
  unsigned char address = 0;

  if ((x > (ROW_MAX_LENGTH - 1u)) || \
      (y > (COL_MAX_LENGTH - 1u)))
  {
    retVal = 0;
  }
  else
  {
    address = (0x40u * y) + x;
    LCD_SendCommand(SET_DDRAM_ADDR_CMD(address));
  }

  return retVal;
}

/** @brief Internal function to write data to 74HC595
 * @param Data Data to be written, follow bit structure:<br>
 * B7 B6 B5 B4 B3 B2 B1 B0
 * 0  0  D7 D6 D5 D4 E  RS
 * @return None
*/
static void LCD_Send4Bit(unsigned int Data)
{
  ShiftData(Data);
  ShiftLatch();
}

void LCD_PutString(unsigned char * const Character)
{
  unsigned char * TempStr = Character;

  while (*TempStr != '\0')
  {
    LCD_PutChar(*TempStr);
    TempStr++;
  }
}

/** @brief Write a character to DDRAM
 * @param Character ASCII code
 * @return None
*/
void LCD_PutChar(unsigned char Character)
{
  /* 4-bit high */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 1, \
                                    ((Character & 0xF0u) >> 4u)));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 0, \
                                    ((Character & 0xF0u) >> 4u)));
  /* 4-bit low */
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 1, \
                                    ((Character & 0x0Fu))));
  LCD_Send4Bit(PACK_DATA_4BIT_INTERFACE(DATA, 0, \
                                    ((Character & 0x0Fu))));
}

/** @brief Clear the screen 
 * @param None
 * @return None
*/
void LCD_ClearDisplay(void)
{
  LCD_SendCommand(CLEAR_DISPLAY_CMD);
	LCD_Init();
}
