#ifndef _SHIFT_REG_

#define _SHIFT_REG_

/***********************************
*              DEFINE              *
***********************************/




/************************************
*              API                  *
************************************/

/** @brief Make falling edge (↓) on Latch pin
 * @param None
 * @return None
*/
void ShiftLatch(void);

/** @brief
 * @param Data 8-bit data to be output
 * @return None
*/
void ShiftData(unsigned int Data);

#endif
